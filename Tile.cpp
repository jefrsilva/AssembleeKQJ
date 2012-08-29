#include "Tile.h"
#include "Item.h"
#include "Vector.h"
#include "Monster.h"
#include "GlobalConstants.h"

#include "Engine.h"

#include <iostream>
#include <cmath>

void Tile::setType(int type) {
    this->type = type;
}

int Tile::getType() {
    return type;
}

Vector Tile::getMapPosition() {
    return mapPosition;
}

Vector Tile::getWorldPosition() {
    return worldPosition;
}

void Tile::addItem(Item *item) {
    bool found = false;

    int freeSlot = 0;
    while (!found) {
        if (!items[freeSlot]) {
            found = true;
        } else {
            freeSlot++;
        }
    }

    if (freeSlot < 9) {
        items[freeSlot] = item;
        item->setTile(this);
    }
}

void Tile::removeItem(Item *item) {
    for (int i = 0; i < 9; i++) {
        if (items[i] == item) {
            items[i] = 0;
            item->setTile(0);
        }
    }
}

void Tile::addMonster(Monster *monster) {
    Vector position = Vector();
    if (monsters.size() == 0) {
        monsters.push_back(monster);
        monsterSlots[monster] = 0;

        Tile *monsterTile = monster->getTile();
        if (monsterTile) {
            monsterTile->removeMonster(monster);
        }
        monster->setTile(this);

        monster->setMapPosition(mapPosition);
        monster->setWorldDestination(Vector(worldPosition.x,
                                            worldPosition.y,
                                            worldPosition.z));
    } else {
        if (getTotalMonsterSize() < 2) {
            Monster *otherMonster = monsters[0];
            int occupiedSlot = monsterSlots[otherMonster];
            otherMonster->setWorldDestination(getMonsterSlot(occupiedSlot));

            int newSlot = (occupiedSlot + 3) % 4;

            Tile *monsterTile = monster->getTile();
            if (monsterTile) {
                monsterTile->removeMonster(monster);
            }
            monster->setTile(this);

            monsters.push_back(monster);
            monsterSlots[monster] = newSlot;

            monster->setMapPosition(mapPosition);
            monster->setWorldDestination(getMonsterSlot(newSlot));
        }
    }
}

void Tile::removeMonster(Monster *monster) {
    int index = 0;
    for (unsigned int i = 0; i < monsters.size(); i++) {
        if (monsters[i] == monster) {
            index = i;
        }
    }
    monsters.erase(monsters.begin() + index);
    monsterSlots.erase(monster);

    if (monsters.size() > 0) {
        Monster *otherMonster = monsters[0];
        monsterSlots[otherMonster] = 0;
        otherMonster->setWorldDestination(Vector(worldPosition.x,
                                          worldPosition.y,
                                          worldPosition.z));
    }
}

std::vector<Monster *> Tile::getMonsters() {
    return monsters;
}

Vector Tile::getMonsterSlot(int slotNumber) {
    double gap = (TILE_SIZE - 2.0 * MONSTER_SIZE) / 2.0;

    int row = (slotNumber / 2);
    int col = (slotNumber % 2);

    if (row == 0) {
        row = -1;
    }

    if (col == 0) {
        col = -1;
    }

    double xOffset = col * (gap / 2.0 + MONSTER_SIZE / 2.0);
    double zOffset = row * (gap / 2.0 + MONSTER_SIZE / 2.0);

    Vector position = Vector(worldPosition.x + xOffset,
                             worldPosition.y,
                             worldPosition.z + zOffset);

    return position;
}

std::list<AlphaObject> Tile::getItemObjects(const Vector &playerPosition,
        double viewAngle) {
    std::list<AlphaObject> alphaObjects;

    double gap = (TILE_SIZE - 3.0 * ITEM_SIZE) / 3.0;

    Vector viewDirection =
        Vector(std::cos(M_PI / 2.0 - (viewAngle / 180.0) * M_PI),
               0.0,
               -std::sin(M_PI / 2.0 - (viewAngle / 180.0) * M_PI));

    for (unsigned int itemSlot = 0; itemSlot < items.size(); itemSlot++) {
        if (items[itemSlot]) {
            int row = itemSlot / 3;
            int col = itemSlot % 3;

            double xOffset =
                (double)(col - 1) * (gap + ITEM_SIZE);
            double zOffset =
                (double)(row - 1) * (gap + ITEM_SIZE);

            Vector objPosition = Vector(worldPosition.x + xOffset,
                                        worldPosition.y,
                                        worldPosition.z + zOffset);

            Vector playerToObj = Vector(playerPosition, objPosition);

            double distance = viewDirection.dot(playerToObj);
            if (distance > HALF_TILE / 2.0) {
                AlphaObject obj = AlphaObject(objPosition,
                                              -viewAngle,
                                              distance,
                                              ALPHAOBJECT_TYPE_ITEM,
                                              items[itemSlot]);
                alphaObjects.push_back(obj);
            }
        }
    }

    return alphaObjects;
}

int Tile::getTotalMonsterSize() {
    int totalMonsterSize = 0;

    for (unsigned int i = 0; i < monsters.size(); i++) {
        Monster *monster = monsters[i];
        totalMonsterSize += monster->getSize();
    }

    return totalMonsterSize;
}

bool Tile::hasMonsters() {
    return (getTotalMonsterSize() > 0);
}

int Tile::getFreeSpace() {
    return (2 - getTotalMonsterSize());
}

bool Tile::blocksLineOfSight() {
    return false;
}

bool Tile::isPassable() {
    return true;
}

void Tile::visit() {
    visited = true;
}

bool Tile::isVisited() {
    return visited;
}
