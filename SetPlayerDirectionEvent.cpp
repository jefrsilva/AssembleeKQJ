#include "SetPlayerDirectionEvent.h"

#include "GlobalConstants.h"

#include "Player.h"

SetPlayerDirectionEvent::SetPlayerDirectionEvent(Player *player, int direction) {
    this->player = player;
    this->direction = direction;
    this->executed = false;
}

SetPlayerDirectionEvent::~SetPlayerDirectionEvent() {

}

void SetPlayerDirectionEvent::run() {
    double angle = 0.0;

    double actualAngle = player->getViewAngle();
    double viewAngle = actualAngle - 360.0 * std::floor(actualAngle / 360.0);    
    int curDir = (viewAngle / 90.0);
    if (direction > curDir) {
        if ((curDir + 4) - direction < direction - curDir) {
            angle = -90.0 * ((curDir + 4) - direction);
        } else {
            angle = 90.0 * (direction - curDir);
        }
    } else {
        if ((direction + 4) - curDir < curDir - direction) {
            angle = 90.0 * ((direction + 4) - curDir);
        } else {
            angle = -90.0 * (curDir - direction);
        }
    }
    
    player->setViewDestination(viewAngle + angle);

    executed = true;
}

void SetPlayerDirectionEvent::update(double dt) {
    
}

bool SetPlayerDirectionEvent::wasExecuted() {
    return executed;
}

bool SetPlayerDirectionEvent::isBlocking() {
    return true;
}

bool SetPlayerDirectionEvent::hasFinished() {
    bool finished = (executed && !player->isMoving());
    
    return finished;
}
