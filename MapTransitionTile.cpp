#include "MapTransitionTile.h"
#include "Item.h"
#include "Map.h"
#include "GlobalConstants.h"

#include "Engine.h"

MapTransitionTile::MapTransitionTile(Map *map, const Vector &worldPosition,
                                     int direction) {
    this->map = map;
    this->direction = direction;
    this->type = TILE_TRANSITION;
    this->mapPosition = Vector(worldPosition.x / TILE_SIZE,
                               worldPosition.z / TILE_SIZE);
    this->worldPosition = worldPosition;

    for (int i = 0; i < 9; i++) {
        items.push_back(0);
    }
    
    this->visited = false;    
}

MapTransitionTile::~MapTransitionTile() {
    for (unsigned int i = 0; i < items.size(); i++) {
        if (items[i]) {
            delete items[i];
        }
    }
}

void MapTransitionTile::render(double edt, bool selection, int modelsToRender) {
    Engine::VideoSystem *videoSystem =
        Engine::Core::getInstance()->getVideoSystem();

    int row = mapPosition.y;
    int col = mapPosition.x;

    double offset = TILE_SIZE / 1024.0;

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

        if (!selection) {
            double ceilingHeight = map->getCeilingHeight();

            glPushMatrix();
            glRotatef(direction * -90.0f, 0.0f, 1.0f, 0.0f);

            glDisable(GL_LIGHTING);
            glDisable(GL_TEXTURE_2D);

            glBegin(GL_TRIANGLE_STRIP);
            glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
            glVertex3f(-HALF_TILE + offset, 0.0, -HALF_TILE);

            glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
            glVertex3f(-HALF_TILE + offset,
                       ceilingHeight * TILE_SIZE,
                       -HALF_TILE);

            glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
            glVertex3f(-HALF_TILE + offset, 0.0, HALF_TILE);

            glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
            glVertex3f(-HALF_TILE + offset,
                       ceilingHeight * TILE_SIZE,
                       HALF_TILE);
            glEnd();

            glBegin(GL_TRIANGLE_STRIP);
            glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
            glVertex3f(HALF_TILE - offset, 0.0, HALF_TILE);

            glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
            glVertex3f(HALF_TILE - offset,
                       ceilingHeight * TILE_SIZE,
                       HALF_TILE);

            glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
            glVertex3f(HALF_TILE - offset, 0.0, -HALF_TILE);

            glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
            glVertex3f(HALF_TILE - offset,
                       ceilingHeight * TILE_SIZE,
                       -HALF_TILE);
            glEnd();

            glBegin(GL_TRIANGLE_STRIP);
            glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
            glVertex3f(HALF_TILE, 0.0, -HALF_TILE + offset);

            glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
            glVertex3f(HALF_TILE,
                       ceilingHeight * TILE_SIZE,
                       -HALF_TILE + offset);

            glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
            glVertex3f(-HALF_TILE, 0.0, -HALF_TILE + offset);

            glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
            glVertex3f(-HALF_TILE,
                       ceilingHeight * TILE_SIZE,
                       -HALF_TILE + offset);
            glEnd();

            glEnable(GL_TEXTURE_2D);
            glEnable(GL_LIGHTING);

            glPopMatrix();

            glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        }
    }

    if (modelsToRender & RENDER_FLOOR) {
        videoSystem->renderList("FloorModel");

        if (!selection) {
            glPushMatrix();
            glRotatef(direction * -90.0f, 0.0f, 1.0f, 0.0f);

            glDisable(GL_LIGHTING);
            glDisable(GL_TEXTURE_2D);

            glBegin(GL_TRIANGLE_STRIP);
            glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
            glVertex3f(HALF_TILE, offset, HALF_TILE);

            glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
            glVertex3f(HALF_TILE, offset, -HALF_TILE);

            glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
            glVertex3f(-HALF_TILE, offset, HALF_TILE);

            glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
            glVertex3f(-HALF_TILE, offset, -HALF_TILE);
            glEnd();

            glEnable(GL_TEXTURE_2D);
            glEnable(GL_LIGHTING);

            glPopMatrix();

            glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        }
    }

    if (modelsToRender & RENDER_CEILING) {
        videoSystem->renderList("CeilingModel");

        if (!selection) {
            double ceilingHeight = map->getCeilingHeight();

            glPushMatrix();
            glRotatef(direction * -90.0f, 0.0f, 1.0f, 0.0f);

            glDisable(GL_LIGHTING);
            glDisable(GL_TEXTURE_2D);

            glBegin(GL_TRIANGLE_STRIP);
            glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
            glVertex3f(HALF_TILE,
                       ceilingHeight * TILE_SIZE - offset,
                       -HALF_TILE);

            glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
            glVertex3f(HALF_TILE,
                       ceilingHeight * TILE_SIZE - offset,
                       HALF_TILE);

            glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
            glVertex3f(-HALF_TILE,
                       ceilingHeight * TILE_SIZE - offset,
                       -HALF_TILE);

            glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
            glVertex3f(-HALF_TILE,
                       ceilingHeight * TILE_SIZE - offset,
                       HALF_TILE);
            glEnd();

            glEnable(GL_TEXTURE_2D);
            glEnable(GL_LIGHTING);

            glPopMatrix();

            glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        }
    }
}

void MapTransitionTile::renderOrtho() {
    int texture = 5;
    
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

void MapTransitionTile::update(double dt) {

}
