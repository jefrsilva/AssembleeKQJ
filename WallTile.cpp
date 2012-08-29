#include "WallTile.h"
#include "GlobalConstants.h"

#include "Engine.h"

WallTile::WallTile(Map *map, const Vector &worldPosition) {
    this->map = map;
    this->type = TILE_WALL;
    this->mapPosition = Vector(worldPosition.x / TILE_SIZE,
                               worldPosition.z / TILE_SIZE);
    this->worldPosition = worldPosition;
    
    this->visited = false;    
}

WallTile::~WallTile() {
    
}

void WallTile::render(double edt, bool selection, int partsToRender) {
    
}

void WallTile::renderOrtho() {
    int texture = 0;
    
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

void WallTile::update(double dt) {
    
}

bool WallTile::blocksLineOfSight() {
    return true;
}

bool WallTile::isPassable() {
    return false;
}
