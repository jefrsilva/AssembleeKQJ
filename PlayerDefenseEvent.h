#ifndef __playerdefenseevent__
#define __playerdefenseevent__

#include "Event.h"

class GameController;
class UserInterface;
class Player;
class Item;

/**
 * \class PlayerDefenseEvent
 * \author Jeferson Rodrigues da Silva
 * \date 01/02/2010
 * \file PlayerDefenseEvent.h
 * \brief
 */
class PlayerDefenseEvent : public Event {

private:
    GameController *game;
    UserInterface *gui;
    Player *player;
    Item *item;

    bool executed;

public:
    PlayerDefenseEvent(GameController *game, UserInterface *gui,
                       Player *player, Item *item);
    ~PlayerDefenseEvent();

    virtual bool hasFinished();
    virtual bool isBlocking();
    virtual void run();
    virtual void update(double dt);
    virtual bool wasExecuted();

};

#endif // __playerdefenseevent__
