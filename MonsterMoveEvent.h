#ifndef __monstermoveevent__
#define __monstermoveevent__

#include "Event.h"

class Map;
class Monster;
class Tile;

class MonsterMoveEvent : public Event {
    
private:
    Map *map;
    Monster *monster;
    Tile *destination;

    bool executed;

public:
    MonsterMoveEvent(Map *map, Monster *monster, Tile *destination);
    ~MonsterMoveEvent();

    virtual bool hasFinished();
    virtual bool isBlocking();
    virtual void run();
    virtual void update(double dt);
    virtual bool wasExecuted();

};

#endif // __monstermoveevent__
