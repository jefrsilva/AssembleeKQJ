#include "MonsterMoveEvent.h"

#include "Map.h"
#include "Monster.h"
#include "Tile.h"

MonsterMoveEvent::MonsterMoveEvent(Map *map,
                                   Monster *monster,
                                   Tile *destination) {
    this->map = map;
    this->monster = monster;
    this->destination = destination;
    
    this->executed = false;
}

MonsterMoveEvent::~MonsterMoveEvent() {

}

bool MonsterMoveEvent::hasFinished() {
    return executed;
}

bool MonsterMoveEvent::isBlocking() {
    return false;
}

void MonsterMoveEvent::run() {
    map->moveMonsterTo(monster, destination);    
    
    executed = true;
}

void MonsterMoveEvent::update(double dt) {

}

bool MonsterMoveEvent::wasExecuted() {
    return executed;
}
