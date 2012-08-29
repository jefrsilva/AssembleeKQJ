#ifndef __monsterattackevent__
#define __monsterattackevent__

#include "Event.h"

class GameController;
class UserInterface;
class Monster;
class Player;

/**
 * \class MonsterAttackEvent
 * \author Jeferson Rodrigues da Silva
 * \date 12/18/2009
 * \file MonsterAttackEvent.h
 * \brief 
 */
class MonsterAttackEvent : public Event {

private:
    GameController *game;
    UserInterface *gui;
    Player *player;
    Monster *monster;

    bool executed;

public:
    MonsterAttackEvent(GameController *game, UserInterface *gui,
                       Player *player, Monster *monster);
    ~MonsterAttackEvent();

    virtual bool hasFinished();
    virtual bool isBlocking();
    virtual void run();
    virtual void update(double dt);
    virtual bool wasExecuted();

};

#endif // __monsterattackevent__
