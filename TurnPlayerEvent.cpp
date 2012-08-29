#include "TurnPlayerEvent.h"

#include "GlobalConstants.h"

#include "Player.h"

TurnPlayerEvent::TurnPlayerEvent(Player *player, int direction) {
    this->player = player;
    this->direction = direction;
    this->executed = false;
}

TurnPlayerEvent::~TurnPlayerEvent() {

}

void TurnPlayerEvent::run() {
    double angle = 90.0;
    if (direction == DIR_CCLOCKWISE) {
        angle = -90.0;
    }

    double viewAngle = player->getViewAngle();
    player->setViewDestination(viewAngle + angle);

    executed = true;
}

void TurnPlayerEvent::update(double dt) {
    
}

bool TurnPlayerEvent::wasExecuted() {
    return executed;
}

bool TurnPlayerEvent::isBlocking() {
    return true;
}

bool TurnPlayerEvent::hasFinished() {
    bool finished = (executed && !player->isMoving());
    
    return finished;
}
