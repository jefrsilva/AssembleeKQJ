#include "TextWindowEvent.h"

#include "GameController.h"
#include "UserInterface.h"
#include "Player.h"
#include "Monster.h"
#include "TextWindow.h"

#include "Engine.h"
#include "GlobalConstants.h"

TextWindowEvent::TextWindowEvent(GameController *game, UserInterface *gui,
                                 Monster *monster, std::string text,
                                 int width, bool blocking) {
    this->game = game;
    this->gui = gui;
    this->monster = monster;
    this->position = Vector();
    this->text = text;
    this->width = width;

    this->blocking = blocking;
    this->executed = false;
}

TextWindowEvent::TextWindowEvent(GameController *game, UserInterface *gui,
                                 const Vector &position, std::string text, 
                                 int width, bool blocking) {
    this->game = game;
    this->gui = gui;
    this->monster = 0;
    this->position = position;
    this->text = text;
    this->width = width;

    this->blocking = blocking;
    this->executed = false;
}

TextWindowEvent::~TextWindowEvent() {

}

bool TextWindowEvent::hasFinished() {
    bool finished = (executed && !gui->getTextWindow());

    return finished;
}

bool TextWindowEvent::isBlocking() {
    return blocking;
}

void TextWindowEvent::run() {
    Player *player = game->getPlayer();
    if (!player->isMoving() && !executed) {
        if (monster) {
            TextWindow *textWindow = new TextWindow();
            Vector position = monster->getWorldPosition(0.0);
            double size = monster->getSize();
            position = position.translate(Vector(0.0,
                                                 1.15 * size * MONSTER_SIZE,
                                                 0.0));

            Engine::VideoSystem *videoSystem =
                Engine::Core::getInstance()->getVideoSystem();

            double windowWidth = videoSystem->getWindowWidth();
            double windowHeight = videoSystem->getWindowHeight();

            double orthoHeight = 1.0;
            double orthoWidth = (windowWidth / windowHeight) * orthoHeight;

            Vector ortho = Vector();
            videoSystem->project(position.x, position.y, position.z,
                                 &ortho.x, &ortho.y, &ortho.z);

            Vector realPosition =
                Vector(((ortho.x / windowWidth) * orthoWidth) - orthoWidth / 2.0,
                       ((ortho.y / windowHeight) * orthoHeight) - orthoHeight / 2.0,
                       0.0);

            textWindow->setOrigin(realPosition);
            textWindow->setText(text);
            textWindow->setWidth(width);

            gui->setTextWindow(textWindow);
        } else {
            TextWindow *textWindow = new TextWindow();
            
            textWindow->setOrigin(position);
            textWindow->setText(text);
            textWindow->setWidth(width);
            
            gui->setTextWindow(textWindow);
        }

        executed = true;
    }
}

void TextWindowEvent::update(double dt) {

}

bool TextWindowEvent::wasExecuted() {
    return executed;
}
