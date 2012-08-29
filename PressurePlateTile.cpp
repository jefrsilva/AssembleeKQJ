#include "PressurePlateTile.h"
#include "Item.h"
#include "Monster.h"
#include "Map.h"
#include "GlobalConstants.h"
#include "HoleTile.h"

#include "Engine.h"

PressurePlateTile::PressurePlateTile(Map *map, const Vector &worldPosition) {
    this->map = map;
    this->type = TILE_PRESSURE_PLATE;
    this->mapPosition = Vector(worldPosition.x / TILE_SIZE,
                               worldPosition.z / TILE_SIZE);
    this->worldPosition = worldPosition;

    for (int i = 0; i < 9; i++) {
        items.push_back(0);
    }

    this->pressedPosition = -TILE_SIZE / 32.0;
    this->releasedPosition = -TILE_SIZE / 256.0;

    this->platePosition = releasedPosition;
    this->iplPlatePosition.attach(&this->platePosition);

    this->weightThreshold = 0;
    this->activated = false;

    this->onActivate = "";
    this->onDeactivate = "";
    
    this->visited = false;    
}

PressurePlateTile::~PressurePlateTile() {
    for (unsigned int i = 0; i < items.size(); i++) {
        if (items[i]) {
            delete items[i];
        }
    }
}

void PressurePlateTile::render(double edt, bool selection, int modelsToRender) {
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
        videoSystem->renderList("HoleModel");

        if (selection) {
            Engine::VideoSystem *videoSystem =
                Engine::Core::getInstance()->getVideoSystem();

            unsigned int selectionID = videoSystem->getSelectionID();
            videoSystem->setSelectionObject(selectionID,
                                            SEL_OBJ_PRESSURE_PLATE, this);

            int b = selectionID / (256 * 256);
            selectionID -= b * (256 * 256);

            int g = selectionID / 256;
            selectionID -= g * 256;

            int r = selectionID;

            glColor4f((double)r / 255.0,
                      (double)g / 255.0,
                      (double)b / 255.0, 1.0f);
        }

        glTranslatef(0.0f, platePosition, 0.0f);
        videoSystem->renderList("PressurePlateModel");
        glTranslatef(0.0f, -platePosition, 0.0f);

        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    }

    if (modelsToRender & RENDER_CEILING) {
        videoSystem->renderList("CeilingModel");
    }
}

void PressurePlateTile::renderOrtho() {
    int texture = 3;
    
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

void PressurePlateTile::update(double dt) {
    iplPlatePosition.update(dt);

    if (platePosition > pressedPosition) {
        activated = false;
    }

    if (!activated && platePosition == pressedPosition) {
        Engine::AudioSystem *audioSystem =
            Engine::Core::getInstance()->getAudioSystem();

        audioSystem->playSound("PlateActivate", 0);

        activated = true;

        callActivateScript();
    }

    int totalWeight = 0;
    for (unsigned int i = 0; i < items.size(); i++) {
        if (items[i]) {
            totalWeight += items[i]->getWeight();
        }
    }
    
    for (unsigned int i = 0; i < monsters.size(); i++) {
        if (monsters[i]) {
            totalWeight += monsters[i]->getWeight();
        }
    }

    Tile *playerTile = map->getPlayerTile();
    if (playerTile == this) {
        totalWeight += 50;
    }

    if (totalWeight > weightThreshold) {
        activate();
    } else {
        deactivate();
    }
}

void PressurePlateTile::activate() {
    if (platePosition > pressedPosition && iplPlatePosition.finished()) {
        Engine::AudioSystem *audioSystem =
            Engine::Core::getInstance()->getAudioSystem();

        audioSystem->playSound("PlateMoving", 0);

        iplPlatePosition.set(platePosition, pressedPosition, 100.0);
    }
}

void PressurePlateTile::deactivate() {
    if (platePosition < releasedPosition && iplPlatePosition.finished()) {
        Engine::AudioSystem *audioSystem =
            Engine::Core::getInstance()->getAudioSystem();

        audioSystem->playSound("PlateMoving", 0);

        iplPlatePosition.set(platePosition, releasedPosition, 100.0);

        activated = false;
        callDeactivateScript();
    }
}

void PressurePlateTile::callActivateScript() {
    if (onActivate.size() > 0) {
        Engine::ScriptingSystem *scriptingSystem =
            Engine::Core::getInstance()->getScriptingSystem();

        lua_State *luaState = scriptingSystem->getLuaState();

        std::string mapID = map->getID();
        lua_getglobal(luaState, mapID.c_str());
        lua_pushstring(luaState, onActivate.c_str());
        lua_gettable(luaState, -2);
        tolua_pushusertype(luaState, (void *)map, "Map");
        tolua_pushusertype(luaState, (void *)this, "PressurePlateTile");
        lua_call(luaState, 2, 0);
        lua_pop(luaState, 1);
    }
}

void PressurePlateTile::callDeactivateScript() {
    if (onDeactivate.size() > 0) {
        Engine::ScriptingSystem *scriptingSystem =
            Engine::Core::getInstance()->getScriptingSystem();

        lua_State *luaState = scriptingSystem->getLuaState();

        std::string mapID = map->getID();
        lua_getglobal(luaState, mapID.c_str());
        lua_pushstring(luaState, onDeactivate.c_str());
        lua_gettable(luaState, -2);
        tolua_pushusertype(luaState, (void *)map, "Map");
        tolua_pushusertype(luaState, (void *)this, "PressurePlateTile");
        lua_call(luaState, 2, 0);
        lua_pop(luaState, 1);
    }
}

void PressurePlateTile::setState(bool pressed) {
    if (pressed) {
        this->platePosition = pressedPosition;
        this->iplPlatePosition.attach(&this->platePosition);
        activated = true;
    } else {
        this->platePosition = releasedPosition;
        this->iplPlatePosition.attach(&this->platePosition);
        activated = false;
    }
}

bool PressurePlateTile::isActivated() {
    return activated;
}

void PressurePlateTile::setWeightThreshold(int weightThreshold) {
    this->weightThreshold = weightThreshold;
}

void PressurePlateTile::setOnActivate(std::string onActivate) {
    this->onActivate = onActivate;
}

void PressurePlateTile::setOnDeactivate(std::string onDeactivate) {
    this->onDeactivate = onDeactivate;
}
