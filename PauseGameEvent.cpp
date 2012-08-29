#include "PauseGameEvent.h"
#include "GameController.h"

PauseGameEvent::PauseGameEvent(GameController *game) {
    this->game = game;
    this->executed = false;
}

PauseGameEvent::~PauseGameEvent() {
    
}

bool PauseGameEvent::hasFinished() {
    return executed;
}

bool PauseGameEvent::isBlocking() {
    return false;
}

void PauseGameEvent::run() {
    game->setPaused(true);
    executed = true;
}

void PauseGameEvent::update(double dt) {
    
}

bool PauseGameEvent::wasExecuted() {
    return executed;
}
