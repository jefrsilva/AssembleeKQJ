#ifndef __setplayerlocationevent__
#define __setplayerlocationevent__

#include "Event.h"

class GameController;
class Map;

/**
 * \class SetPlayerLocationEvent
 * \author Jeferson Rodrigues da Silva
 * \date 01/03/2010
 * \file SetPlayerLocationEvent.h
 * \brief
 */
class SetPlayerLocationEvent : public Event {

private:
    GameController *game;
    Map *map;
    int row;
    int col;
    int direction;
    bool executed;

public:
    SetPlayerLocationEvent(GameController *game, Map *map,
                           int row, int col, int direction);
    ~SetPlayerLocationEvent();

    virtual bool hasFinished();
    virtual bool isBlocking();
    virtual void run();
    virtual void update(double dt);
    virtual bool wasExecuted();

};

#endif // __setplayerlocationevent__
