#include "PlayerAttackEvent.h"
#include "GameController.h"
#include "UserInterface.h"
#include "Player.h"
#include "Item.h"
#include "GlobalConstants.h"

#include "Events.h"
#include "Animations.h"

#include <sstream>

PlayerDefenseEvent::PlayerDefenseEvent(GameController *game,
                                       UserInterface *gui,
                                       Player *player,
                                       Item *item) {
    this->game = game;
    this->gui = gui;
    this->player = player;
    this->item = item;

    this->executed = false;
}

PlayerDefenseEvent::~PlayerDefenseEvent() {

}

bool PlayerDefenseEvent::hasFinished() {
    return executed;
}

bool PlayerDefenseEvent::isBlocking() {
    return true;
}

void PlayerDefenseEvent::run() {
    if (item->getDurability() > 0) {
        DefenseResult defenseResult = item->defend();

        player->setDefense(defenseResult);

        AttackAnimationEvent *animationEvent = new AttackAnimationEvent();
        Animation *animation = 0;

        std::stringstream text;
        if (defenseResult.defenseType != 'x') {
            text << "|ff8|+" << defenseResult.absorption << "|fff| ";

            unsigned char c[] = {16, 17, 18, 19, 20, 21};
            unsigned char defType = defenseResult.defenseType;
            if (defType == 'x') {
                text << "|888|" << c[0] << "|fff|";
            } else if (defType == 'W') {
                text << c[1];
            } else if (defType == 'G') {
                text << c[2];
            } else if (defType == 'R') {
                text << c[3];
            } else if (defType == 'B') {
                text << c[4];
            } else if (defType == 'Y') {
                text << c[5];
            }
        } else {
            text << "Defense failed";
        }

        Vector textPosition =
            gui->getHealthPotPosition().translate(Vector(0.0, 1.0 / 8.0, 0.0));
        animation =
            new TextAnimation(textPosition,
                              text.str(),
                              ALIGN_CENTER,
                              false);
        animationEvent->addAnimation(animation);
        gui->attachAnimation(animation);

        Event *event = new SetTooltipVisibilityEvent(gui, true, true);
        game->queueFrontEvent(event);

        game->queueFrontEvent(animationEvent);

        event = new SetTooltipVisibilityEvent(gui, false, true);
        game->queueFrontEvent(event);

        event = new ItemDelayEvent(item);
        game->queueFrontEvent(event);

        game->nextTurn();

        AttackAnimationEvent *defenseEvent = new AttackAnimationEvent();
        Vector position = gui->getHealthPotPosition();
        position = position.translate(Vector(0.0, 0.045, 0.0));
        animation =
            new PlayerDefenseAnimation(position, defenseResult.defenseType);

        defenseEvent->addAnimation(animation);
        gui->attachAnimation(animation);

        game->queueAsyncEvent(defenseEvent);
    }

    executed = true;
}

void PlayerDefenseEvent::update(double dt) {

}

bool PlayerDefenseEvent::wasExecuted() {
    return executed;
}
