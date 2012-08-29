#include "ReturnToMenuEvent.h"
#include "GameController.h"

ReturnToMenuEvent::ReturnToMenuEvent(GameController *game) {
    this->game = game;
    this->executed = false;
}

ReturnToMenuEvent::~ReturnToMenuEvent() {
    
}

bool ReturnToMenuEvent::hasFinished() {
    return executed;
}

bool ReturnToMenuEvent::isBlocking() {
    return false;
}

void ReturnToMenuEvent::run() {
    game->changeState();
    
    executed = true;
}

void ReturnToMenuEvent::update(double dt) {
    
}

bool ReturnToMenuEvent::wasExecuted() {
    return executed;
}
