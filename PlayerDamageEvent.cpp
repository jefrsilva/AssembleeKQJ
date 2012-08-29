#include "PlayerDamageEvent.h"
#include "Events.h"
#include "Animations.h"
#include "GameController.h"
#include "UserInterface.h"
#include "GlobalConstants.h"

#include "Player.h"

#include <sstream>

PlayerDamageEvent::PlayerDamageEvent(GameController *game, UserInterface *gui,
                                     Player *player, AttackFeedback feedback) {
    this->game = game;
    this->gui = gui;
    this->player = player;
    this->feedback = feedback;

    this->executed = false;
}

PlayerDamageEvent::~PlayerDamageEvent() {

}

bool PlayerDamageEvent::hasFinished() {
    return executed;
}

bool PlayerDamageEvent::isBlocking() {
    return true;
}

void PlayerDamageEvent::run() {
    DefenseFeedback defenseFeedback = player->takeDamage(feedback);

    std::stringstream textPlayer;
    if (feedback.result.attackType != 'x') {
        if (defenseFeedback.totalDamage == 0) {
            textPlayer << "-0";
        } else {
            textPlayer << "-" << defenseFeedback.totalDamage;
        }
    } else {
        textPlayer << "Miss!";
    }

    if (!feedback.result.noDamageAttack) {
        AttackAnimationEvent *resultEvent = new AttackAnimationEvent();
        Animation *animation = 0;

        if (feedback.result.attackType != 'x') {
            if (feedback.result.attackType == 'W') {
                animation = new PlayerNormalHitAnimation(player);
            } else if (feedback.result.attackType == 'R') {
                animation = new PlayerFireHitAnimation(player);
            } else if (feedback.result.attackType == 'B') {
                animation = new PlayerIceHitAnimation(player);
            } else if (feedback.result.attackType == 'G') {
                animation = new PlayerAcidHitAnimation(player);
            } else if (feedback.result.attackType == 'Y') {
                animation = new PlayerShockHitAnimation(player);
            }
            resultEvent->addAnimation(animation);
            player->attachAnimation(animation);
        }

        Vector textPosition =
            gui->getHealthPotPosition().translate(Vector(0.0, 1.0 / 8.0, 0.0));
        animation =
            new TextAnimation(textPosition,
                              textPlayer.str(),
                              ALIGN_CENTER,
                              false);
        resultEvent->addAnimation(animation);
        gui->attachAnimation(animation);

        game->queueFrontEvent(resultEvent);

        if (feedback.result.attackType != 'x' ||
                defenseFeedback.totalDamage > 0) {
            AttackAnimationEvent *hurtEvent = new AttackAnimationEvent();
            Vector position = gui->getHealthPotPosition();
            position = position.translate(Vector(0.0, 0.045, 0.0));
            animation =
                new PlayerHurtAnimation(position);

            hurtEvent->addAnimation(animation);
            gui->attachAnimation(animation);

            game->queueAsyncEvent(hurtEvent);
        }
    }

    executed = true;
}

void PlayerDamageEvent::update(double dt) {

}

bool PlayerDamageEvent::wasExecuted() {
    return executed;
}
