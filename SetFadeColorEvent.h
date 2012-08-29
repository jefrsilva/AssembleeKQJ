#ifndef __setfadecolorevent__
#define __setfadecolorevent__

#include "Event.h"
#include "Vector.h"

class UserInterface;

/**
 * \class SetFadeColorEvent
 * \author Jeferson Rodrigues da Silva
 * \date 01/03/2010
 * \file SetFadeColorEvent.h
 * \brief 
 */
class SetFadeColorEvent : public Event {
    
private:
    UserInterface *gui;
    Vector color;
    bool executed;

public:
	SetFadeColorEvent(UserInterface *gui, const Vector &color);
	~SetFadeColorEvent();

	virtual bool hasFinished();
	virtual bool isBlocking();
	virtual void run();
	virtual void update(double dt);
	virtual bool wasExecuted();
    
};

#endif // __setfadecolorevent__
