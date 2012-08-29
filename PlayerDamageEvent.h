#ifndef __playerdamageevent__
#define __playerdamageevent__

#include "Event.h"

#include "AttackFeedback.h"

class GameController;
class UserInterface;
class Player;

class PlayerDamageEvent : public Event {

private:
    GameController *game;
    UserInterface *gui;
    Player *player;
    AttackFeedback feedback;
    bool executed;

public:
    PlayerDamageEvent(GameController *game, UserInterface *gui,
                      Player *player, AttackFeedback feedback);
    ~PlayerDamageEvent();

    virtual bool hasFinished();
    virtual bool isBlocking();
    virtual void run();
    virtual void update(double dt);
    virtual bool wasExecuted();

};

#endif // __playerdamageevent__
