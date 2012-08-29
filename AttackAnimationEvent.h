#ifndef __attackanimationevent__
#define __attackanimationevent__

#include "Event.h"

#include <list>

class Animation;

/**
 * \class AttackAnimationEvent
 * \author Jeferson Rodrigues da Silva
 * \date 12/15/2009
 * \file AttackAnimationEvent.h
 * \brief 
 */
class AttackAnimationEvent : public Event {

private:
    std::list<Animation *> animations;
    bool blocking;
    bool executed;

public:
    AttackAnimationEvent();
    AttackAnimationEvent(bool blocking);
    ~AttackAnimationEvent();

    virtual void run();
    virtual void update(double dt);

    virtual void addAnimation(Animation *animation);

    virtual bool wasExecuted();
    virtual bool isBlocking();
    virtual bool hasFinished();

};

#endif // __attackanimationevent__
