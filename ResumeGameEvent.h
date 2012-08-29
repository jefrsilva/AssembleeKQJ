#ifndef __resumegameevent__
#define __resumegameevent__

#include "Event.h"

class GameController;

/**
 * \class ResumeGameEvent
 * \author Jeferson Rodrigues da Silva
 * \date 01/05/2010
 * \file ResumeGameEvent.h
 * \brief
 */
class ResumeGameEvent : public Event {

private:
    GameController *game;
    bool executed;

public:
    ResumeGameEvent(GameController *game);
    ~ResumeGameEvent();

    virtual bool hasFinished();
    virtual bool isBlocking();
    virtual void run();
    virtual void update(double dt);
    virtual bool wasExecuted();

};

#endif // __resumegameevent__
