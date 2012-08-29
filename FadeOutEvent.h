#ifndef __fadeoutevent__
#define __fadeoutevent__

#include "Event.h"

class UserInterface;

/**
 * \class FadeOutEvent
 * \author Jeferson Rodrigues da Silva
 * \date 01/03/2010
 * \file FadeOutEvent.h
 * \brief 
 */
class FadeOutEvent : public Event {
    
private:
    UserInterface *gui;
    double duration;
    bool executed;

public:
	FadeOutEvent(UserInterface *gui, double duration);
	~FadeOutEvent();

	virtual bool hasFinished();
	virtual bool isBlocking();
	virtual void run();
	virtual void update(double dt);
	virtual bool wasExecuted();
    
};

#endif // __fadeoutevent__
