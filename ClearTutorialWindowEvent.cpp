#include "ClearTutorialWindowEvent.h"
#include "UserInterface.h"

ClearTutorialWindowEvent::ClearTutorialWindowEvent(UserInterface *gui) {
    this->gui = gui;
    this->executed = false;
}

ClearTutorialWindowEvent::~ClearTutorialWindowEvent() {
    
}

bool ClearTutorialWindowEvent::hasFinished() {
    return executed;
}

bool ClearTutorialWindowEvent::isBlocking() {
    return false;
}

void ClearTutorialWindowEvent::run() {
    gui->clearTutorialWindow();
    executed = true;
}

void ClearTutorialWindowEvent::update(double dt) {
    
}

bool ClearTutorialWindowEvent::wasExecuted() {
    return executed;
}
