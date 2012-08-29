#ifndef __moveplayerevent__
#define __moveplayerevent__

#include "Event.h"

class GameController;
class UserInterface;
class Player;

/**
 * \class MovePlayerEvent
 * \author Jeferson Rodrigues da Silva
 * \date 12/14/2009
 * \file MovePlayerEvent.h
 * \brief
 */
class MovePlayerEvent : public Event {

private:
    GameController *game;
    UserInterface *gui;
    Player *player;
    int direction;
    bool executed;

public:
    MovePlayerEvent(GameController *game, UserInterface *gui, Player *player,
                    int direction);
    ~MovePlayerEvent();

    void run();
    void update(double dt);
    bool wasExecuted();
    bool isBlocking();
    bool hasFinished();

};

#endif // __moveplayerevent__
