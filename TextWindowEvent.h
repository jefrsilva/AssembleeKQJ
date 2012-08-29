#ifndef __textwindowevent__
#define __textwindowevent__

#include "Event.h"
#include "Vector.h"

class GameController;
class UserInterface;
class Monster;

#include <string>

/**
 * \class TextWindowEvent
 * \author Jeferson Rodrigues da Silva
 * \date 01/05/2010
 * \file TextWindowEvent.h
 * \brief
 */
class TextWindowEvent : public Event {

private:
    GameController *game;
    UserInterface *gui;
    Monster *monster;
    Vector position;
    std::string text;
    int width;

    bool blocking;
    bool executed;

public:
    TextWindowEvent(GameController *game, UserInterface *gui, Monster *monster,
                    std::string text, int width, bool blocking);
    TextWindowEvent(GameController *game, UserInterface *gui,
                    const Vector &position, std::string text, int width,
                    bool blocking);
    ~TextWindowEvent();

    virtual bool hasFinished();
    virtual bool isBlocking();
    virtual void run();
    virtual void update(double dt);
    virtual bool wasExecuted();

};

#endif // __textwindowevent__
