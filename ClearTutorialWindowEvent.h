#ifndef __cleartutorialwindowevent__
#define __cleartutorialwindowevent__

#include "Event.h"

class UserInterface;

/**
 * \class ClearTutorialWindowEvent
 * \author Jeferson Rodrigues da Silva
 * \date 01/05/2010
 * \file ClearTutorialWindowEvent.h
 * \brief
 */
class ClearTutorialWindowEvent : public Event {

private:
    UserInterface *gui;
    bool executed;

public:
    ClearTutorialWindowEvent(UserInterface *gui);
    ~ClearTutorialWindowEvent();

    virtual bool hasFinished();
    virtual bool isBlocking();
    virtual void run();
    virtual void update(double dt);
    virtual bool wasExecuted();

};

#endif // __cleartutorialwindowevent__
