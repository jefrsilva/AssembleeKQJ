#include "FadeInEvent.h"
#include "UserInterface.h"

FadeInEvent::FadeInEvent(UserInterface *gui, double duration) {
    this->gui = gui;
    this->duration = duration;
    this->executed = false;
}

FadeInEvent::~FadeInEvent() {
    
}

bool FadeInEvent::hasFinished() {
    return executed && gui->finishedFading();
}

bool FadeInEvent::isBlocking() {
    return true;
}

void FadeInEvent::run() {
    gui->fadeIn(duration);
    this->executed = true;
}

void FadeInEvent::update(double dt) {
    
}

bool FadeInEvent::wasExecuted() {
    return executed;
}
