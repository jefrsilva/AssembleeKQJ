#include "SetPlayerLocationEvent.h"
#include "GameController.h"
#include "Player.h"
#include "Map.h"
#include "Tile.h"

SetPlayerLocationEvent::SetPlayerLocationEvent(GameController *game,
        Map *map, int row, int col, int direction) {
    this->game = game;
    this->map = map;
    this->row = row;
    this->col = col;
    this->direction = direction;
    this->executed = false;
}

SetPlayerLocationEvent::~SetPlayerLocationEvent() {

}

bool SetPlayerLocationEvent::hasFinished() {
    return executed;
}

bool SetPlayerLocationEvent::isBlocking() {
    return false;
}

void SetPlayerLocationEvent::run() {
    Player *player = game->getPlayer();
    
    Tile *tile = map->getTile(row, col);
    tile->visit();
    
    player->setMapPosition(Vector(col, row), direction * 90.0);
    game->setPlayerMap(map);
    
    executed = true;
}

void SetPlayerLocationEvent::update(double dt) {

}

bool SetPlayerLocationEvent::wasExecuted() {
    return executed;
}
