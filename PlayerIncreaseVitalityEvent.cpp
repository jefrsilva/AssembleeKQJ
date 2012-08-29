#include "PlayerIncreaseVitalityEvent.h"
#include "GameController.h"
#include "UserInterface.h"
#include "Player.h"
#include "GlobalConstants.h"

#include "Events.h"
#include "Animations.h"

#include <sstream>

PlayerIncreaseVitalityEvent::PlayerIncreaseVitalityEvent(GameController *game,
        UserInterface *gui,
        int maxHealthIncrease) {
    this->game = game;
    this->gui = gui;
    this->maxHealthIncrease = maxHealthIncrease;
    this->executed = false;
}

PlayerIncreaseVitalityEvent::~PlayerIncreaseVitalityEvent() {

}

bool PlayerIncreaseVitalityEvent::hasFinished() {
    return executed;
}

bool PlayerIncreaseVitalityEvent::isBlocking() {
    return false;
}

void PlayerIncreaseVitalityEvent::run() {
    Player *player = game->getPlayer();
    double maxHealth = player->getMaxHealth();
    player->setMaxHealth(maxHealth + maxHealthIncrease);

    AttackAnimationEvent *animationEvent =
        new AttackAnimationEvent();

    std::stringstream result;
    result << "|ff8|+" << maxHealthIncrease;

    Vector position = gui->getHealthPotPosition();
    position = position.translate(Vector(0.0, 0.045, 0.0));
    Animation *animation =
        new PlayerVitalityAnimation(position);

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

void PlayerIncreaseVitalityEvent::update(double dt) {

}

bool PlayerIncreaseVitalityEvent::wasExecuted() {
    return executed;
}
