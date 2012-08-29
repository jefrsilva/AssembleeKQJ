#ifndef __itemdelayevent__
#define __itemdelayevent__

#include "Event.h"

class Item;

/**
 * \class ItemDelayEvent
 * \author Jeferson Rodrigues da Silva
 * \date 12/24/2009
 * \file ItemDelayEvent.h
 * \brief 
 */
class ItemDelayEvent : public Event {
    
private:
    Item *item;
    bool executed;

public:
	ItemDelayEvent(Item *item);
	~ItemDelayEvent();

	virtual bool hasFinished();
	virtual bool isBlocking();
	virtual void run();
	virtual void update(double dt);
	virtual bool wasExecuted();
    
};

#endif // __itemdelayevent__
