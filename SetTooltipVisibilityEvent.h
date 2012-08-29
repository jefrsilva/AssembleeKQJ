#ifndef __settooltipvisibilityevent__
#define __settooltipvisibilityevent__

#include "Event.h"

class UserInterface;

/**
 * \class SetTooltipVisibilityEvent
 * \author Jeferson Rodrigues da Silva
 * \date 12/18/2009
 * \file SetTooltipVisibilityEvent.h
 * \brief
 */
class SetTooltipVisibilityEvent : public Event {

private:
    UserInterface *gui;
    bool visibility;
    bool worldVisibility;
    
    bool executed;

public:
    SetTooltipVisibilityEvent(UserInterface *gui,
                              bool visibility, bool worldVisibility);
    ~SetTooltipVisibilityEvent();

    virtual void run();
    virtual void update(double dt);
    virtual bool wasExecuted();
    virtual bool isBlocking();
    virtual bool hasFinished();

};

#endif // __settooltipvisibilityevent__
