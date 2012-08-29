#ifndef __playergiveitemevent__
#define __playergiveitemevent__

#include "Event.h"

class Map;
class Player;
class Item;

/**
 * \class PlayerGiveItemEvent
 * \author Jeferson Rodrigues da Silva
 * \date 01/09/2010
 * \file PlayerGiveItemEvent.h
 * \brief 
 */
class PlayerGiveItemEvent : public Event {
    
private:
    Map *map;
    Player *player;
    Item *item;
    bool executed;

public:
	PlayerGiveItemEvent(Map *map, Player *player, Item *item);
	~PlayerGiveItemEvent();

	virtual bool hasFinished();
	virtual bool isBlocking();
	virtual void run();
	virtual void update(double dt);
	virtual bool wasExecuted();
    
};

#endif // __playergiveitemevent__
