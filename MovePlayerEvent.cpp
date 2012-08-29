#include "MovePlayerEvent.h"

#include "GlobalConstants.h"

#include "GameController.h"
#include "Map.h"
#include "Player.h"
#include "Monster.h"
#include "Vector.h"
#include "Tile.h"
#include "DoorTile.h"
#include "Events.h"


MovePlayerEvent::MovePlayerEvent(GameController *game, UserInterface *gui,
                                 Player *player, int direction) {
    this->game = game;
    this->gui = gui;
    this->player = player;
    this->direction = direction;

    this->executed = false;
}

MovePlayerEvent::~MovePlayerEvent() {

}

void MovePlayerEvent::run() {
    Map *map = game->getMap();

    if (game->getCurrentTurn() == TURN_PLAYER &&
            player->hasEndedTurn()) {
        executed = true;
        return;
    }

    Vector mapPosition = player->getMapPosition();
    double viewAngle = player->getViewAngle();

    bool opportunityAttack = false;
    for (int dir = 0; dir < 4; dir++) {
        Tile *tile = map->getTile(mapPosition.y + dy[dir],
                                  mapPosition.x + dx[dir]);

        std::vector<Monster *> monsters = tile->getMonsters();
        for (unsigned int i = 0; i < monsters.size(); i++) {
            Monster *monster = monsters[i];
            if (!monster->isRangedAttacker()) {

                if (!monster->isStunned() &&
                        !monster->hasEndedTurn() &&
                        monster->getHealth() > 0) {
                    opportunityAttack = true;

                    monster->endTurn();
                    Event *event =
                        new MonsterAttackEvent(game, gui, player, monster);

                    game->queueFrontEvent(event);
                }

            }
        }
    }

    if (!opportunityAttack) {
        int dirAdjust = (int)(viewAngle / 90.0f);
        if (dirAdjust < 0) {
            dirAdjust += -((dirAdjust / 4) - 1) * 4;
        }

        direction = (direction + dirAdjust) % 4;
        Tile *playerDestination =
            map->getTile((int)mapPosition.y + dy[direction],
                         (int)mapPosition.x + dx[direction]);

        if (playerDestination->isPassable() &&
                !playerDestination->hasMonsters()) {
            playerDestination->visit();
                    
            Vector mapDestination =
                Vector((int)mapPosition.x + dx[direction],
                       (int)mapPosition.y + dy[direction]);
            player->setMapDestination(mapDestination);

            Vector worldPosition = player->getWorldPosition();
            Vector worldDestination =
                Vector(worldPosition.x + dx[direction] * TILE_SIZE,
                       0.0,
                       worldPosition.z + dy[direction] * TILE_SIZE);
            player->setWorldDestination(worldDestination);

            if (game->getCurrentTurn() != TURN_FREE) {
                game->nextTurn();
            }

            player->endTurn();

            game->callEnterTileScript(mapDestination);
        }

        executed = true;
    }
}

void MovePlayerEvent::update(double dt) {

}

bool MovePlayerEvent::wasExecuted() {
    return executed;
}

bool MovePlayerEvent::isBlocking() {
    return true;
}

bool MovePlayerEvent::hasFinished() {
    bool finished = executed && (!player->isMoving());

    return finished;
}
