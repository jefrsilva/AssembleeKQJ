#include "SecretWallTile.h"
#include "Item.h"
#include "Map.h"
#include "GlobalConstants.h"

#include "Engine.h"

SecretWallTile::SecretWallTile(Map *map, const Vector &worldPosition) {
    this->map = map;
    this->type = TILE_SECRET_WALL;
    this->mapPosition = Vector(worldPosition.x / TILE_SIZE,
                               worldPosition.z / TILE_SIZE);
    this->worldPosition = worldPosition;

    for (int i = 0; i < 9; i++) {
        items.push_back(0);
    }

    this->visited = false;
}

SecretWallTile::~SecretWallTile() {
    for (unsigned int i = 0; i < items.size(); i++) {
        if (items[i]) {
            delete items[i];
        }
    }
}

void SecretWallTile::render(double edt, bool selection, int modelsToRender) {
    Engine::VideoSystem *videoSystem =
        Engine::Core::getInstance()->getVideoSystem();

    int row = mapPosition.y;
    int col = mapPosition.x;

    if (modelsToRender & RENDER_WALL) {
        for (int dir = 0; dir < 4; dir++) {
            Tile *tile = map->getTile(row + dy[dir],
                                      col + dx[dir]);

            if (tile->getType() == TILE_WALL) {
                glPushMatrix();

                glTranslatef(dx[dir] * HALF_TILE,
                             0.0f,
                             dy[dir] * HALF_TILE);
                glRotatef(dir * -90.0f, 0.0f, 1.0f, 0.0f);

                videoSystem->renderList("WallModel");

                glPopMatrix();
            } else if (tile->isPassable()) {
                int newDir = (dir + 2) % 4;

                glPushMatrix();

                glTranslatef(dx[dir] * HALF_TILE,
                             0.0f,
                             dy[dir] * HALF_TILE);
                glRotatef(newDir * -90.0f, 0.0f, 1.0f, 0.0f);

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

void SecretWallTile::renderOrtho() {
    int texture = 7;
    if (!visited) {
        texture = 0;
    }

    double row = texture / 12;
    double col = texture % 12;

    double pw = 1.0 / TEX_IMAGE_ITEM_WIDTH;
    double ph = 1.0 / TEX_IMAGE_ITEM_HEIGHT;

    double tileWidth = 8.0 * pw;
    double tileHeight = 8.0 * ph;

    double hOffset = (col * (tileWidth + 2.0 * pw)) + pw;
    double vOffset = 1.0 - ((row + 1.0) * tileHeight + 2.0 * ph) + ph;

    double tileSize = 1.0 / 48.0;

    glColor4f(0.5f, 0.5f, 0.5f, 1.0f);
    glBegin(GL_TRIANGLE_STRIP);
    glTexCoord2f(hOffset + tileWidth, vOffset);
    glVertex3f(tileSize / 2.0, -tileSize / 2.0, 0.0f);

    glTexCoord2f(hOffset + tileWidth, vOffset + tileHeight);
    glVertex3f(tileSize / 2.0, tileSize / 2.0, 0.0f);

    glTexCoord2f(hOffset, vOffset);
    glVertex3f(-tileSize / 2.0, -tileSize / 2.0, 0.0f);

    glTexCoord2f(hOffset, vOffset + tileHeight);
    glVertex3f(-tileSize / 2.0, tileSize / 2.0, 0.0f);
    glEnd();

}

void SecretWallTile::update(double dt) {

}

bool SecretWallTile::blocksLineOfSight() {
    return true;
}
