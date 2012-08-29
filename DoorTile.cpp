#include "DoorTile.h"
#include "GlobalConstants.h"
#include "Item.h"
#include "Map.h"
#include "Tooltip.h"

#include "Engine.h"

DoorTile::DoorTile(Map *map, const Vector &worldPosition, bool isVertical) {
    this->map = map;
    this->type = TILE_DOOR;
    this->mapPosition = Vector(worldPosition.x / TILE_SIZE,
                               worldPosition.z / TILE_SIZE);
    this->worldPosition = worldPosition;

    for (int i = 0; i < 9; i++) {
        items.push_back(0);
    }

    this->isVertical = isVertical;
    this->doorPosition = 0.0;
    this->iplDoorPosition.attach(&this->doorPosition);

    this->tooltip = new Tooltip();
    tooltip->setOrigin(Vector());

    this->isOpening = false;
    this->closeSound = true;

    this->key = "";
    this->locked = false;
    
    this->visited = false;
}

DoorTile::~DoorTile() {
    for (unsigned int i = 0; i < items.size(); i++) {
        if (items[i]) {
            delete items[i];
        }
    }

    if (tooltip) {
        delete tooltip;
        tooltip = 0;
    }
}

void DoorTile::render(double edt, bool selection, int modelsToRender) {
    Engine::VideoSystem *videoSystem =
        Engine::Core::getInstance()->getVideoSystem();

    int col = mapPosition.x;
    int row = mapPosition.y;

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

        glPushMatrix();
        if (isVertical) {
            glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
        }

        videoSystem->renderList("DoorFrameModel");

        if (selection) {
            Engine::VideoSystem *videoSystem =
                Engine::Core::getInstance()->getVideoSystem();

            unsigned int selectionID = videoSystem->getSelectionID();
            videoSystem->setSelectionObject(selectionID, SEL_OBJ_DOOR, this);

            int b = selectionID / (256 * 256);
            selectionID -= b * (256 * 256);

            int g = selectionID / 256;
            selectionID -= g * 256;

            int r = selectionID;

            glColor4f((double)r / 255.0,
                      (double)g / 255.0,
                      (double)b / 255.0, 1.0f);
        }

        glTranslatef(0.0f, doorPosition, 0.0f);
        videoSystem->renderList("DoorModel");
        glTranslatef(0.0f, -doorPosition, 0.0f);

        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

        glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
        videoSystem->renderList("DoorFrameModel");
        glPopMatrix();
    }

    if (modelsToRender & RENDER_FLOOR) {
        videoSystem->renderList("FloorModel");
    }

    if (modelsToRender & RENDER_CEILING) {
        videoSystem->renderList("CeilingModel");
    }
}

void DoorTile::renderOrtho() {
    int texture = 1;
    if (isOpen()) {
        texture = 9;
    } else if (locked) {
        texture = 2;
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
    
    if (isVertical) {
        glRotatef(90.0, 0.0, 0.0, 1.0);
    }
    
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
    
    if (isVertical) {
        glRotatef(-90.0, 0.0, 0.0, 1.0);
    }
}

void DoorTile::update(double dt) {
    this->iplDoorPosition.update(dt);

    if (doorPosition == 0.0 && !closeSound) {
        closeSound = true;

        Engine::AudioSystem *audioSystem =
            Engine::Core::getInstance()->getAudioSystem();

        audioSystem->playSound("DoorClose", 0);
    }
}

Tooltip *DoorTile::getTooltip() {
    if (locked) {
        tooltip->setText("Locked door");
    } else {
        tooltip->setText("Unlocked door");
    }

    return tooltip;
}

bool DoorTile::isOpen() {
    bool open = false;

    if (doorPosition > 0.0) {
        open = true;
    }

    return open;
}

void DoorTile::activate() {
    Engine::AudioSystem *audioSystem =
        Engine::Core::getInstance()->getAudioSystem();

    audioSystem->playSound("Door", 0);

    if (isOpening) {
        double duration =
            (doorPosition / (7.0 * TILE_SIZE / 8.0)) * 1000.0;
        iplDoorPosition.set(doorPosition, 0.0, duration);

        isOpening = false;
        closeSound = false;
    } else {
        double duration =
            (1.0 - (doorPosition / (7.0 * TILE_SIZE / 8.0))) * 1000.0;
        iplDoorPosition.set(doorPosition, 7.0 * TILE_SIZE / 8.0, duration);

        isOpening = true;
        closeSound = false;
    }
}

bool DoorTile::blocksLineOfSight() {
    bool blocks = true;

    if (doorPosition > 0.0) {
        blocks = false;
    }

    return blocks;
}

bool DoorTile::isPassable() {
    bool passable = false;

    if (doorPosition == (7.0 * TILE_SIZE / 8.0)) {
        passable = true;
    }

    return passable;
}

bool DoorTile::isLocked() {
    return locked;
}

std::string DoorTile::getKey() {
    return key;
}

void DoorTile::open() {
    if (doorPosition < 7.0 * TILE_SIZE / 8.0) {
        Engine::AudioSystem *audioSystem =
            Engine::Core::getInstance()->getAudioSystem();

        audioSystem->playSound("Door", 0);

        double duration =
            (1.0 - (doorPosition / (7.0 * TILE_SIZE / 8.0))) * 1000.0;
        iplDoorPosition.set(doorPosition, 7.0 * TILE_SIZE / 8.0, duration);

        isOpening = true;
        closeSound = false;
    }
}

void DoorTile::close() {
    Tile *playerTile = map->getPlayerTile();

    if (playerTile != this && !hasMonsters() &&
            doorPosition > 0.0) {
        Engine::AudioSystem *audioSystem =
            Engine::Core::getInstance()->getAudioSystem();

        audioSystem->playSound("Door", 0);

        double duration =
            (doorPosition / (7.0 * TILE_SIZE / 8.0)) * 1000.0;
        iplDoorPosition.set(doorPosition, 0.0, duration);

        isOpening = false;
        closeSound = false;
    }
}

void DoorTile::setLocked(bool locked) {
    this->locked = locked;
}

void DoorTile::setKey(std::string itemID) {
    this->key = itemID;
}
