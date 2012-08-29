#include "PlayerGiveItemEvent.h"
#include "Map.h"
#include "Player.h"
#include "Item.h"
#include "Tile.h"

PlayerGiveItemEvent::PlayerGiveItemEvent(Map *map, Player *player, Item *item) {
    this->map = map;
    this->player = player;
    this->item = item;
    this->executed = false;
}

PlayerGiveItemEvent::~PlayerGiveItemEvent() {
    
}

bool PlayerGiveItemEvent::hasFinished() {
    return executed;
}

bool PlayerGiveItemEvent::isBlocking() {
    return false;
}

void PlayerGiveItemEvent::run() {
    std::vector<Item *> inventory = player->getInventory();
    
    int freeSlot = -1;
    for (unsigned int i = 0; i < inventory.size(); i++) {
        Item *item = inventory[i];
        if (!item) {
            freeSlot = i;
            break;
        }
    }
    
    if (freeSlot > -1) {
        player->addItem(item, freeSlot);
    } else {
        Tile *tile = map->getPlayerTile();
        tile->addItem(item);
    }
    
    executed = true;
}

void PlayerGiveItemEvent::update(double dt) {
    
}

bool PlayerGiveItemEvent::wasExecuted() {
    return executed;
}
