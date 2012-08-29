#ifndef __playerattackevent__
#define __playerattackevent__

#include "Event.h"

class GameController;
class UserInterface;
class Item;
class Monster;

/**
 * \class PlayerAttackEvent
 * \author Jeferson Rodrigues da Silva
 * \date 12/15/2009
 * \file PlayerAttackEvent.h
 * \brief
 */
class PlayerAttackEvent : public Event {

private:
    GameController *game;
    UserInterface *gui;
    Item *item;
    Monster *monster;

    bool executed;

public:
    PlayerAttackEvent(GameController *game, UserInterface *gui,
                      Item *item, Monster *monster);
    ~PlayerAttackEvent();

    virtual bool hasFinished();
    virtual bool isBlocking();
    virtual void run();
    virtual void update(double dt);
    virtual bool wasExecuted();

};

#endif // __playerattackevent__
