#ifndef __activatedoorevent__
#define __activatedoorevent__

#include "Event.h"

class Item;
class DoorTile;

/**
 * \class ActivateDoorEvent
 * \author Jeferson Rodrigues da Silva
 * \date 12/20/2009
 * \file ActivateDoorEvent.h
 * \brief
 */
class ActivateDoorEvent : public Event {
    
private:
    Item *item;
    DoorTile *door;
    
    bool executed;

public:
    ActivateDoorEvent(DoorTile *door, Item *item);
    ~ActivateDoorEvent();

    virtual bool hasFinished();
    virtual bool isBlocking();
    virtual void run();
    virtual void update(double dt);
    virtual bool wasExecuted();

};

#endif // __activatedoorevent__
