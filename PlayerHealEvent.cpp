#include "PlayerHealEvent.h"
#include "GameController.h"
#include "UserInterface.h"
#include "Player.h"
#include "GlobalConstants.h"

#include "Events.h"
#include "Animations.h"

#include <sstream>

PlayerHealEvent::PlayerHealEvent(GameController *game, UserInterface *gui,
                                 int healPoints) {
    this->game = game;
    this->gui = gui;
    this->healPoints = healPoints;
    this->executed = false;
}

PlayerHealEvent::~PlayerHealEvent() {

}

bool PlayerHealEvent::hasFinished() {
    return executed;
}

bool PlayerHealEvent::isBlocking() {
    return false;
}

void PlayerHealEvent::run() {
    Player *player = game->getPlayer();
    player->addHealth(healPoints);

    AttackAnimationEvent *animationEvent =
        new AttackAnimationEvent();

    std::stringstream result;
    result << "|8f8|+" << healPoints;

    Vector position = gui->getHealthPotPosition();
    position = position.translate(Vector(0.0, 0.045, 0.0));
    Animation *animation =
        new PlayerHealAnimation(position);

    animationEvent->addAnimation(animation);
    gui->attachAnimation(animation);

    position =
        gui->getHealthPotPosition().translate(Vector(0.0, 1.0 / 8.0, 0.0));
    animation =
        new TextAnimation(position,
                          result.str(),
                          ALIGN_CENTER,
                          false);
    animationEvent->addAnimation(animation);
    gui->attachAnimation(animation);

    game->queueAsyncEvent(animationEvent);

    executed = true;
}

void PlayerHealEvent::update(double dt) {

}

bool PlayerHealEvent::wasExecuted() {
    return executed;
}
