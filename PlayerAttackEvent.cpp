#include "PlayerAttackEvent.h"
#include "GameController.h"
#include "UserInterface.h"
#include "Item.h"
#include "Monster.h"
#include "Player.h"
#include "GlobalConstants.h"

#include "Events.h"
#include "Animations.h"

#include <sstream>

PlayerAttackEvent::PlayerAttackEvent(GameController *game,
                                     UserInterface *gui,
                                     Item *item, Monster *monster) {
    this->game = game;
    this->gui = gui;
    this->item = item;
    this->monster = monster;

    this->executed = false;
}

PlayerAttackEvent::~PlayerAttackEvent() {

}

bool PlayerAttackEvent::hasFinished() {
    return executed;
}

bool PlayerAttackEvent::isBlocking() {
    return true;
}

void PlayerAttackEvent::run() {
    if (item->getDurability() > 0) {
        Player *player = game->getPlayer();
        std::string faction = monster->getFaction();
        int factionStance = player->getFactionStance(faction);
        if (factionStance != FACTION_HOSTILE) {
            player->setFactionStance(faction, FACTION_HOSTILE);
        }
        
        AttackFeedback feedback = item->attack(monster);

        AttackAnimationEvent *animationEvent = new AttackAnimationEvent();

        Animation *animation = 0;
        unsigned char animationType = feedback.result.attackType;
        if (animationType == 'x') {
            animationType = feedback.result.missType;
        }

        if (animationType == 'W') {
            animation = new SlashAnimation(monster->getWorldPosition(0.0));
        } else if (animationType == 'R') {
            animation = new FireSlashAnimation(monster->getWorldPosition(0.0));
        } else if (animationType == 'B') {
            animation = new IceSlashAnimation(monster->getWorldPosition(0.0));
        } else if (animationType == 'Y') {
            animation = new ShockSlashAnimation(monster->getWorldPosition(0.0));
        } else if (animationType == 'G') {
            animation = new AcidSlashAnimation(monster->getWorldPosition(0.0));
        }

        if (animation) {
            animationEvent->addAnimation(animation);
            monster->attachAnimation(animation);
        }

        if (feedback.defeatedEnemy) {
            game->dropItems(monster);
            monster->die();
        }

        std::stringstream text;
        if (feedback.result.attackType != 'x') {
            monster->shake(350.0);

            if (feedback.wasCritical) {
                text << "-" << feedback.totalDamage << " Critical hit!";
            } else {
                text << "-" << feedback.totalDamage << " Hit!";
            }
        } else {
            text << "Miss!";
        }

        Vector textPosition =
            monster->getWorldPosition(0.0);
        textPosition =
            textPosition.translate(Vector(0.0,
                                          1.15 * MONSTER_SIZE,
                                          0.0));
        animation = new TextAnimation(textPosition,
                                      text.str(),
                                      ALIGN_CENTER,
                                      true);
        animationEvent->addAnimation(animation);
        gui->attachAnimation(animation);

        Event *event = new SetTooltipVisibilityEvent(gui, true, true);
        game->queueFrontEvent(event);

        game->queueFrontEvent(animationEvent);

        event = new SetTooltipVisibilityEvent(gui, true, false);
        game->queueFrontEvent(event);

        event = new ItemDelayEvent(item);
        game->queueFrontEvent(event);

        if (!feedback.defeatedEnemy && !feedback.wasCritical) {
            game->nextTurn();
        } else {
            AttackAnimationEvent *turnAnimationEvent =
                new AttackAnimationEvent();

            Vector position = gui->getTurnStonePosition();
            position = position.translate(Vector(0.0, 0.045, 0.0));
            animation = new PlayerTurnAnimation(position);

            turnAnimationEvent->addAnimation(animation);
            gui->attachAnimation(animation);

            Vector textPosition = gui->getTurnStonePosition();
            textPosition = textPosition.translate(Vector(0.0, 1.0 / 8.0, 0.0));
            animation =
                new TextAnimation(textPosition,
                                  "|5f5|Extend|fff|",
                                  ALIGN_CENTER,
                                  false);

            turnAnimationEvent->addAnimation(animation);
            gui->attachAnimation(animation);

            game->queueAsyncEvent(turnAnimationEvent);
        }
    }

    executed = true;
}

void PlayerAttackEvent::update(double dt) {

}

bool PlayerAttackEvent::wasExecuted() {
    return executed;
}
