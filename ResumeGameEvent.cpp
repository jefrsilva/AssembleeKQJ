#include "ResumeGameEvent.h"
#include "GameController.h"

ResumeGameEvent::ResumeGameEvent(GameController *game) {
    this->game = game;
    this->executed = false;
}

ResumeGameEvent::~ResumeGameEvent() {
    
}

bool ResumeGameEvent::hasFinished() {
    return executed;
}

bool ResumeGameEvent::isBlocking() {
    return false;
}

void ResumeGameEvent::run() {
    game->setPaused(false);
    executed = true;
}

void ResumeGameEvent::update(double dt) {
    
}

bool ResumeGameEvent::wasExecuted() {
    return executed;
}
