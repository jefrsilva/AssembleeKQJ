#include "TutorialWindowEvent.h"
#include "UserInterface.h"
#include "TextWindow.h"

TutorialWindowEvent::TutorialWindowEvent(GameController *game,
        UserInterface *gui, std::string text) {
    this->game = game;
    this->gui = gui;
    this->text = text;
    this->executed = false;
}

TutorialWindowEvent::~TutorialWindowEvent() {

}

bool TutorialWindowEvent::hasFinished() {
    return executed;
}

bool TutorialWindowEvent::isBlocking() {
    return false;
}

void TutorialWindowEvent::run() {
    TextWindow *textWindow = new TextWindow();

    textWindow->setOrigin(Vector(1.0, 0.5));
    textWindow->setText(text);
    textWindow->setWidth(25);
    textWindow->setPointer(false);

    gui->setTutorialWindow(textWindow);

    executed = true;
}

void TutorialWindowEvent::update(double dt) {

}

bool TutorialWindowEvent::wasExecuted() {
    return executed;
}
