#ifndef __pausegameevent__
#define __pausegameevent__

#include "Event.h"

class GameController;

/**
 * \class PauseGameEvent
 * \author Jeferson Rodrigues da Silva
 * \date 01/05/2010
 * \file PauseGameEvent.h
 * \brief
 */
class PauseGameEvent : public Event {

private:
    GameController *game;
    bool executed;

public:
    PauseGameEvent(GameController *game);
    ~PauseGameEvent();

    virtual bool hasFinished();
    virtual bool isBlocking();
    virtual void run();
    virtual void update(double dt);
    virtual bool wasExecuted();

};

#endif // __pausegameevent__
