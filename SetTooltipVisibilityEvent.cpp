#include "SetTooltipVisibilityEvent.h"

#include "GlobalConstants.h"

#include "UserInterface.h"

SetTooltipVisibilityEvent::SetTooltipVisibilityEvent(UserInterface *gui,
        bool visibility, bool worldVisibility) {
    this->executed = false;
    this->gui = gui;
    this->visibility = visibility;
    this->worldVisibility = worldVisibility;
}

SetTooltipVisibilityEvent::~SetTooltipVisibilityEvent() {

}

void SetTooltipVisibilityEvent::run() {
    gui->setTooltipVisibility(visibility);
    gui->setWorldTooltipVisibility(worldVisibility);

    executed = true;
}

void SetTooltipVisibilityEvent::update(double dt) {

}

bool SetTooltipVisibilityEvent::wasExecuted() {
    return executed;
}

bool SetTooltipVisibilityEvent::isBlocking() {
    return false;
}

bool SetTooltipVisibilityEvent::hasFinished() {
    return executed;
}
