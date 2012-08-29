#include "FloorTile.h"
#include "Item.h"
#include "Map.h"
#include "GlobalConstants.h"

#include "Engine.h"

FloorTile::FloorTile(Map *map, const Vector &worldPosition) {
    this->map = map;
    this->type = TILE_FLOOR;
    this->mapPosition = Vector(worldPosition.x / TILE_SIZE,
                               worldPosition.z / TILE_SIZE);
    this->worldPosition = worldPosition;

    for (int i = 0; i < 9; i++) {
        items.push_back(0);
    }
    
    this->visited = false;    
}

FloorTile::~FloorTile() {
    for (unsigned int i = 0; i < items.size(); i++) {
        if (items[i]) {
            delete items[i];
        }
    }
}

void FloorTile::render(double edt, bool selection, int modelsToRender) {
    Engine::VideoSystem *videoSystem =
        Engine::Core::getInstance()->getVideoSystem();

    int row = mapPosition.y;
    int col = mapPosition.x;

    if (modelsToRender & RENDER_WALL) {
        for (int dir = 0; dir < 4; dir++) {
            Tile *tile = map->getTile(row + dy[dir], col + dx[dir]);
            
            bool renderWall = false;
            if (!tile) {
                renderWall = true;
            } else {
                if (tile->getType() == TILE_WALL) {
                    renderWall = true;
                }
            }
            
            if (renderWall) {
                glPushMatrix();

                glTranslatef(dx[dir] * HALF_TILE,
                             0.0f,
                             dy[dir] * HALF_TILE);
                glRotatef(dir * -90.0f, 0.0f, 1.0f, 0.0f);

                videoSystem->renderList("WallModel");

                glPopMatrix();
            }
        }
    }

    if (modelsToRender & RENDER_FLOOR) {
        videoSystem->renderList("FloorModel");
    }

    if (modelsToRender & RENDER_CEILING) {
        videoSystem->renderList("CeilingModel");
    }
}

void FloorTile::renderOrtho() {

}

void FloorTile::update(double dt) {

}
