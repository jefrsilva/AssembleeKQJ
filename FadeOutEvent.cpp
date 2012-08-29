#include "FadeOutEvent.h"
#include "UserInterface.h"

FadeOutEvent::FadeOutEvent(UserInterface *gui, double duration) {
    this->gui = gui;
    this->duration = duration;
    this->executed = false;
}

FadeOutEvent::~FadeOutEvent() {
    
}

bool FadeOutEvent::hasFinished() {
    return executed && gui->finishedFading();
}

bool FadeOutEvent::isBlocking() {
    return true;
}

void FadeOutEvent::run() {
    gui->fadeOut(duration);
    executed = true;
}

void FadeOutEvent::update(double dt) {
    
}

bool FadeOutEvent::wasExecuted() {
    return executed;
}
