#ifndef __tile__
#define __tile__

#include "AlphaObject.h"
#include "Vector.h"

#include <vector>
#include <list>
#include <map>

class Map;
class Item;
class Monster;

/**
 * \class Tile
 * \author Jeferson Rodrigues da Silva
 * \date 12/08/2009
 * \file Tile.h
 * \brief
 */
class Tile {

protected:
    Map *map;
    Vector mapPosition;
    Vector worldPosition;
    int type;
    std::vector<Item *> items;

    std::vector<Monster *> monsters;
    std::map<Monster *, int> monsterSlots;
    
    bool visited;

public:
    virtual ~Tile() {};

    virtual void setType(int type);
    virtual int getType();

    virtual Vector getMapPosition();
    virtual Vector getWorldPosition();

    virtual void addItem(Item *item);
    virtual void removeItem(Item *item);

    virtual void addMonster(Monster *monster);
    virtual void removeMonster(Monster *monster);
    virtual std::vector<Monster *> getMonsters();

    virtual std::list<AlphaObject> getItemObjects(const Vector &playerPosition,
            double viewAngle);

    //virtual std::vector<Vector> getMonsterPositions();
    virtual Vector getMonsterSlot(int slotNumber);

    virtual int getTotalMonsterSize();
    virtual bool hasMonsters();
    virtual int getFreeSpace();
    
    virtual void update(double dt) = 0;
    virtual void render(double edt, bool selection, int modelsToRender) = 0;
    virtual void renderOrtho() = 0;
    
    virtual bool blocksLineOfSight();
    virtual bool isPassable();
    
    virtual void visit();
    virtual bool isVisited();

};

#endif // __tile__
