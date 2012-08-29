#ifndef __fadeinevent__
#define __fadeinevent__

#include "Event.h"

class UserInterface;

/**
 * \class FadeInEvent
 * \author Jeferson Rodrigues da Silva
 * \date 01/03/2010
 * \file FadeInEvent.h
 * \brief 
 */
class FadeInEvent : public Event {

private:
    UserInterface *gui;
    double duration;
    bool executed;

public:
	FadeInEvent(UserInterface *gui, double duration);
	~FadeInEvent();

	virtual bool hasFinished();
	virtual bool isBlocking();
	virtual void run();
	virtual void update(double dt);
	virtual bool wasExecuted();
    
};

#endif // __fadeinevent__
