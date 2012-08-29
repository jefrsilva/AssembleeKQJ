#include "SetFadeColorEvent.h"
#include "UserInterface.h"

SetFadeColorEvent::SetFadeColorEvent(UserInterface *gui, const Vector &color) {
    this->gui = gui;
    this->color = color;
    this->executed = false;
}

SetFadeColorEvent::~SetFadeColorEvent() {

}

bool SetFadeColorEvent::hasFinished() {
    return executed;
}

bool SetFadeColorEvent::isBlocking() {
    return false;
}

void SetFadeColorEvent::run() {
    gui->setFadeColor(color);
    
    executed = true;
}

void SetFadeColorEvent::update(double dt) {

}

bool SetFadeColorEvent::wasExecuted() {
    return executed;
}
