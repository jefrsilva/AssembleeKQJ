#ifndef __playerhealevent__
#define __playerhealevent__

#include "Event.h"

class GameController;
class UserInterface;

/**
 * \class PlayerHealEvent
 * \author Jeferson Rodrigues da Silva
 * \date 01/08/2010
 * \file PlayerHealEvent.h
 * \brief 
 */
class PlayerHealEvent : public Event {
    
private:
    GameController *game;
    UserInterface *gui;
    int healPoints;
    bool executed;

public:
	PlayerHealEvent(GameController *game, UserInterface *gui, int healPoints);
	~PlayerHealEvent();

	virtual bool hasFinished();
	virtual bool isBlocking();
	virtual void run();
	virtual void update(double dt);
	virtual bool wasExecuted();
    
};

#endif // __playerhealevent__
