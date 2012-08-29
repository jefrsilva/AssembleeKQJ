#ifndef __returntomenuevent__
#define __returntomenuevent__

#include "Event.h"

class GameController;

/**
 * \class ReturnToMenuEvent
 * \author Jeferson Rodrigues da Silva
 * \date 01/09/2010
 * \file ReturnToMenuEvent.h
 * \brief 
 */
class ReturnToMenuEvent : public Event {
    
private:
    GameController *game;
    bool executed;

public:
	ReturnToMenuEvent(GameController *game);
	~ReturnToMenuEvent();

	virtual bool hasFinished();
	virtual bool isBlocking();
	virtual void run();
	virtual void update(double dt);
	virtual bool wasExecuted();
    
};

#endif // __returntomenuevent__
