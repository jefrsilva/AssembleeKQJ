#include "Map.h"
#include "Item.h"
#include "Monster.h"
#include "Player.h"
#include "Tile.h"
#include "WallTile.h"
#include "SecretWallTile.h"
#include "FloorTile.h"
#include "DoorTile.h"
#include "HoleTile.h"
#include "PressurePlateTile.h"
#include "MapTransitionTile.h"
#include "Particle.h"
#include "Models.h"
#include "GlobalConstants.h"

#include "Engine.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>

Map::Map(std::string mapID) {
    this->id = mapID;

    this->width = 0;
    this->height = 0;
    this->player = 0;

    this->musicID = "";
    this->tileset = 0;
    this->ceilingHeight = 1.0;
    this->floorReflection = false;

    this->fogDensity = 0.25;
    this->fogColor = Vector();
}

Map::~Map() {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            delete tiles[row][col];
        }
    }

    std::list<Monster *>::iterator it;
    for (it = monsters.begin(); it != monsters.end(); it++) {
        Monster *monster = (*it);

        delete monster;
    }
}

void Map::update(double dt) {
    std::list<Monster *>::iterator it = monsters.begin();
    while (it != monsters.end()) {
        Monster *monster = (*it);

        if (!monster->isAlive()) {
            Tile *tile = monster->getTile();
            tile->removeMonster(monster);

            monsterInstances.erase(monster->getInstanceID());
            it = monsters.erase(it);
        } else {
            monster->update(dt);
            it++;
        }
    }

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            Tile *tile = tiles[row][col];

            tile->update(dt);
        }
    }
}

std::string Map::getID() {
    return id;
}

void Map::renderTile(int row, int col, int modelsToRender) {
    Engine::VideoSystem *videoSystem =
        Engine::Core::getInstance()->getVideoSystem();

    if (modelsToRender & RENDER_WALL) {
        for (int dir = 0; dir < 4; dir++) {
            Tile *tile = getTile(row + dy[dir], col + dx[dir]);
            bool renderWall = false;
            if (tile) {
                if (tile->getType() == TILE_WALL) {
                    renderWall = true;
                }
            } else {
                renderWall = true;
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

        if (getTile(row, col)->getType() == TILE_DOOR) {
            if (getTile(row - 1, col)->getType() == TILE_WALL) {
                glPushMatrix();
                glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
                videoSystem->renderList("DoorFrameModel");

                glTranslatef(0.0f, 7.0 * TILE_SIZE / 8.0, 0.0f);
                videoSystem->renderList("DoorModel");
                glTranslatef(0.0f, -7.0 * TILE_SIZE / 8.0, 0.0f);

                glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
                videoSystem->renderList("DoorFrameModel");
                glPopMatrix();
            } else {
                glPushMatrix();
                videoSystem->renderList("DoorFrameModel");

                glTranslatef(0.0f, 7.0 * TILE_SIZE / 8.0, 0.0f);
                videoSystem->renderList("DoorModel");
                glTranslatef(0.0f, -7.0 * TILE_SIZE / 8.0, 0.0f);

                glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
                videoSystem->renderList("DoorFrameModel");
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

std::list<AlphaObject> Map::getObjectsSortedByDistance(Vector playerPosition,
        double viewAngle) {
    std::list<AlphaObject> objectsToRender;

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            Tile *tile = tiles[row][col];
            std::list<AlphaObject> itemObjects =
                tile->getItemObjects(playerPosition, viewAngle);

            objectsToRender.insert(objectsToRender.begin(),
                                   itemObjects.begin(),
                                   itemObjects.end());
        }
    }

    std::list<AlphaObject> monsterObjects = getMonsterObjects();

    objectsToRender.insert(objectsToRender.begin(),
                           monsterObjects.begin(),
                           monsterObjects.end());

    std::list<AlphaObject> playerObjects = getPlayerParticleObjects();

    objectsToRender.insert(objectsToRender.begin(),
                           playerObjects.begin(),
                           playerObjects.end());

    objectsToRender.sort(sortByDistance());

    return objectsToRender;
}

void Map::render(double edt, bool selection) {
    Engine::VideoSystem *videoSystem =
        Engine::Core::getInstance()->getVideoSystem();

    Vector worldPosition = player->getWorldPosition(edt);

    double actualCameraX = worldPosition.x;
    double actualCameraZ = worldPosition.z;

    double actualAngle = player->getViewAngle(edt);

    glRotatef(actualAngle, 0.0f, 1.0f, 0.0);
    glTranslatef(-actualCameraX, 0.0, -actualCameraZ);

    double eqUp[] = {0.0, 1.0, 0.0, 0.0};
    double eqDown[] = {0.0, -1.0, 0.0, 0.0};

    if (floorReflection) {
        glClipPlane(GL_CLIP_PLANE0, eqDown);
        glEnable(GL_CLIP_PLANE0);
    }

    videoSystem->saveMatrices();

    double viewAngle = actualAngle - 360.0 * std::floor(actualAngle / 360.0);

    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    if (floorReflection && !selection) {
        glPushMatrix();
        glScalef(1.0f, -1.0f, 1.0f);
        glFrontFace(GL_CW);

        renderMap(edt, RENDER_WALL | RENDER_CEILING, false);
        renderAlphaObjects(Vector(actualCameraX, 0.0, actualCameraZ),
                           viewAngle,
                           edt,
                           false);

        glPopMatrix();
        glFrontFace(GL_CCW);
    }

    if (floorReflection) {
        glClipPlane(GL_CLIP_PLANE0, eqUp);
    }

    if (floorReflection) {
        glColor4f(1.0f, 1.0f, 1.0f, 0.75f);
        renderMap(edt, RENDER_FLOOR, selection);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        renderMap(edt, RENDER_WALL | RENDER_CEILING, selection);
    } else {
        renderMap(edt, RENDER_FLOOR | RENDER_WALL | RENDER_CEILING, selection);
    }

    renderAlphaObjects(Vector(actualCameraX, 0.0, actualCameraZ),
                       viewAngle,
                       edt,
                       selection);

    if (floorReflection) {
        glDisable(GL_CLIP_PLANE0);
    }
}

void Map::renderOrtho(int mapState) {
    glPushMatrix();

    double tileSize = 1.0 / 48.0;
    double mapBorder = tileSize / 4.0;

    double mapWidth = width * tileSize;
    double mapHeight = height * tileSize;

    glDisable(GL_TEXTURE_2D);
    
    if (mapState == MAP_STATE_TRANSPARENT) {
        glColor4f(0.75f, 0.75f, 0.75f, 0.5f);
    } else {
        glColor4f(0.75f, 0.75f, 0.75f, 1.0f);        
    }
    
    glBegin(GL_TRIANGLE_STRIP);
    glVertex3f(mapWidth / 2.0 + mapBorder, -mapHeight / 2.0 - mapBorder, 0.0f);
    glVertex3f(mapWidth / 2.0 + mapBorder, mapHeight / 2.0 + mapBorder, 0.0f);
    glVertex3f(-mapWidth / 2.0 - mapBorder, -mapHeight / 2.0 - mapBorder, 0.0f);
    glVertex3f(-mapWidth / 2.0 - mapBorder, mapHeight / 2.0 + mapBorder, 0.0f);
    glEnd();
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_TEXTURE_2D);

    glTranslatef(-width * (0.5 * tileSize) + tileSize / 2.0,
                 height * (0.5 * tileSize) - tileSize / 2.0,
                 0.0f);
                 
    Vector playerPosition = player->getMapPosition();

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            bool wasVisited = getTile(row, col)->isVisited();

            if (!wasVisited) {
                bool isKnown = false;
                for (int yOffset = -1;
                        yOffset <= 1 && !isKnown; yOffset++) {
                    for (int xOffset = -1;
                            xOffset <= 1 && !isKnown; xOffset++) {
                        Tile *tile = getTile(row + yOffset, col + xOffset);
                        if (tile) {
                            if (tile->isVisited()) {
                                isKnown = true;
                            }
                        }
                    }
                }

                Tile *tile = getTile(row, col);
                if (isKnown) {
                    tile->renderOrtho();
                } else {
                    glDisable(GL_TEXTURE_2D);
                    glColor4f(0.0f, 0.0f, 0.0f, 0.5f);
                    glBegin(GL_TRIANGLE_STRIP);
                    glVertex3f(tileSize / 2.0, -tileSize / 2.0, 0.0f);
                    glVertex3f(tileSize / 2.0, tileSize / 2.0, 0.0f);
                    glVertex3f(-tileSize / 2.0, -tileSize / 2.0, 0.0f);
                    glVertex3f(-tileSize / 2.0, tileSize / 2.0, 0.0f);
                    glEnd();
                    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
                    glEnable(GL_TEXTURE_2D);
                }
            } else {
                Tile *tile = getTile(row, col);
                tile->renderOrtho();
            }
            
            if (row == playerPosition.y &&
                col == playerPosition.x) {
                if (mapState == MAP_STATE_TRANSPARENT) {
                glColor4f(1.0f, 1.0f, 1.0f, 1.0f);                                        
                } else {
                glColor4f(0.75f, 0.0f, 0.0f, 1.0f);                    
                }
                player->renderOrtho();
            }

            glTranslatef(tileSize, 0.0f, 0.0f);
        }
        glTranslatef(-width * tileSize, -tileSize, 0.0f);
    }

    glPopMatrix();
}

void Map::renderMap(double edt, int partsToRender, bool selection) {
    Engine::VideoSystem *videoSystem =
        Engine::Core::getInstance()->getVideoSystem();

    if (!selection) {
        videoSystem->bindTexture("Dungeons");
    }

    glPushMatrix();
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            Tile *tile = tiles[row][col];

            if (tile->getType() != TILE_WALL) {
                tile->render(edt, selection, partsToRender);
                // renderTile(row, col, partsToRender);
            }
            glTranslatef(TILE_SIZE, 0.0f, 0.0f);
        }
        glTranslatef(width * -TILE_SIZE, 0.0f, TILE_SIZE);
    }
    glPopMatrix();
}

void Map::renderAlphaObjects(Vector cameraPosition, double viewAngle,
                             double edt, bool selection) {
    Engine::VideoSystem *videoSystem =
        Engine::Core::getInstance()->getVideoSystem();

    std::list<AlphaObject> objectsToRender =
        getObjectsSortedByDistance(Vector(cameraPosition.x,
                                          cameraPosition.y,
                                          cameraPosition.z),
                                   viewAngle);

    std::list<AlphaObject>::iterator it;
    for (it = objectsToRender.begin(); it != objectsToRender.end(); it++) {
        AlphaObject obj = (*it);

        if (obj.objectType == ALPHAOBJECT_TYPE_ITEM) {
            Item *item = (Item *)obj.objectPtr;

            if (!selection) {
                videoSystem->bindTexture("Items");
            }

            glPushMatrix();
            glTranslatef(obj.position.x, obj.position.y, obj.position.z);
            glRotatef(obj.rot, 0.0, 1.0, 0.0);
            item->render(edt, selection);
            glPopMatrix();
        } else if (obj.objectType == ALPHAOBJECT_TYPE_MONSTER) {
            Monster *monster = (Monster *)obj.objectPtr;

            if (!selection) {
                videoSystem->bindTexture("Monsters");
            }

            glPushMatrix();
            glTranslatef(obj.position.x, obj.position.y, obj.position.z);
            glRotatef(obj.rot, 0.0, 1.0, 0.0);
            monster->render(edt, selection);
            glPopMatrix();
        } else if (obj.objectType == ALPHAOBJECT_TYPE_PARTICLE) {
            Particle *particle = (Particle *)obj.objectPtr;

            if (!selection) {
                glDisable(GL_LIGHTING);
                particle->setBlendMode();
                videoSystem->bindTexture("Particles");

                glPushMatrix();
                Vector position = particle->getPosition(edt);

                glTranslatef(obj.position.x, obj.position.y, obj.position.z);
                glRotatef(obj.rot, 0.0, 1.0, 0.0);
                particle->render(edt);

                glPopMatrix();
                glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                glEnable(GL_LIGHTING);
            }
        }
    }
}

void Map::setPlayer(Player *player) {
    this->player = player;
}

Player *Map::getPlayer() {
    return this->player;
}

void Map::setName(std::string name) {
    this->name = name;
}

std::string Map::getName() {
    return this->name;
}

std::string Map::getMusicID() {
    return this->musicID;
}

double Map::getCeilingHeight() {
    return this->ceilingHeight;
}

void Map::setMusic(std::string music) {
    this->musicID = music;
}

void Map::setTileset(int tileset) {
    this->tileset = tileset;
}

void Map::setCeilingHeight(double height) {
    this->ceilingHeight = height;
}

void Map::setFloorReflection(bool reflection) {
    this->floorReflection = reflection;
}

void Map::setFog(double r, double g, double b, double density) {
    fogDensity = density;
    fogColor = Vector(r, g, b);
}

void Map::setAmbientLight(double r, double g, double b) {
    ambientLight = Vector(r, g, b);
}

void Map::setDiffuseLight(double r, double g, double b) {
    diffuseLight = Vector(r, g, b);
}

void Map::setLightParams(double constant, double linear, double quadratic) {
    lightConstant = constant;
    lightLinear = linear;
    lightQuadratic = quadratic;
}

void Map::setupBackgroundColor() {
    glClearColor(fogColor.x, fogColor.y, fogColor.z, 1.0f);
}

void Map::setupFogAndLighting() {
    GLfloat globalAmbient[] = {0.0f, 0.0f, 0.0f, 1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbient);

    GLfloat ambient[] = {ambientLight.x, ambientLight.y, ambientLight.z, 1.0f};
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    GLfloat diffuse[] = {diffuseLight.x, diffuseLight.y, diffuseLight.z, 1.0f};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);

    GLfloat specular[] = {0.0f, 0.0f, 0.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

    GLfloat position[] = {0.0f, HALF_TILE / 2.0, 0.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, position);

    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, lightConstant);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, lightLinear);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, lightQuadratic);

    GLfloat fog[] = {fogColor.x, fogColor.y, fogColor.z, 1.0f};
    glEnable (GL_FOG);
    glFogi (GL_FOG_MODE, GL_EXP);
    glFogfv (GL_FOG_COLOR, fog);
    glFogf (GL_FOG_DENSITY, fogDensity);
    glHint (GL_FOG_HINT, GL_NICEST);
    glFogf(GL_FOG_START, 0.0f);
    glFogf(GL_FOG_END, 20.0f);    
}

void Map::addItem(Item *item, int row, int col) {
    getTile(row, col)->addItem(item);
    items.push_back(item);
}

void Map::addMonster(Monster *monster, int row, int col) {
    monsters.push_back(monster);
    monsterInstances[monster->getInstanceID()] = monster;

    monster->setMapPosition(Vector(col, row));

    Tile *tile = getTile(row, col);

    monster->setWorldPosition(tile->getWorldPosition());
    tile->addMonster(monster);
}

Monster *Map::getMonster(std::string instanceID) {
    Monster *monster = 0;

    std::map<std::string, Monster *>::iterator it =
        monsterInstances.find(instanceID);

    if (it != monsterInstances.end()) {
        monster = (*it).second;
    }

    return monster;
}

DoorTile *Map::getDoorAt(int row, int col) {
    DoorTile *tile = (DoorTile *)tiles[row][col];

    return tile;
}

PressurePlateTile *Map::getPressurePlateAt(int row, int col) {
    PressurePlateTile *tile = (PressurePlateTile *)tiles[row][col];

    return tile;
}

HoleTile *Map::getHoleAt(int row, int col) {
    HoleTile *tile = (HoleTile *)tiles[row][col];

    return tile;
}

std::vector<Item *> Map::getItems() {
    return items;
}

std::list<Monster *> Map::getMonsters() {
    return monsters;
}

std::list<AlphaObject> Map::getMonsterObjects() {
    std::list<AlphaObject> alphaObjects;

    double viewAngle = player->getViewAngle();

    Vector viewDirection =
        Vector(std::cos(M_PI / 2.0 - (viewAngle / 180.0) * M_PI),
               0.0,
               -std::sin(M_PI / 2.0 - (viewAngle / 180.0) * M_PI));

    std::list<Monster *>::iterator it;
    for (it = monsters.begin(); it != monsters.end(); it++) {
        Monster *monster = (*it);

        std::list<AlphaObject> particleObjects = getParticleObjects(monster);
        alphaObjects.insert(alphaObjects.begin(),
                            particleObjects.begin(),
                            particleObjects.end());

        Vector objPosition = monster->getWorldPosition(0.0);
        Vector playerPosition = player->getWorldPosition();

        Vector playerToObj = Vector(playerPosition, objPosition);

        double distance = viewDirection.dot(playerToObj);
        if (distance > HALF_TILE / 2.0) {
            AlphaObject obj = AlphaObject(objPosition,
                                          -viewAngle,
                                          distance,
                                          ALPHAOBJECT_TYPE_MONSTER,
                                          monster);
            alphaObjects.push_back(obj);
        }
    }

    return alphaObjects;
}

std::list<AlphaObject> Map::getParticleObjects(Monster *monster) {
    std::list<AlphaObject> alphaObjects;

    std::list<Particle *> particles = monster->getParticles();

    double viewAngle = player->getViewAngle();

    Vector viewDirection =
        Vector(std::cos(M_PI / 2.0 - (viewAngle / 180.0) * M_PI),
               0.0,
               -std::sin(M_PI / 2.0 - (viewAngle / 180.0) * M_PI));

    std::list<Particle *>::iterator it;
    for (it = particles.begin(); it != particles.end(); it++) {
        Particle *particle = (*it);

        Vector objPosition = particle->getWorldPosition();

        Vector objOffset = particle->getPosition(0.0);
        objOffset =
            Vector(std::cos((viewAngle / 180.0) * M_PI) * objOffset.x -
                   std::sin((viewAngle / 180.0) * M_PI) * objOffset.z,
                   objOffset.y,
                   std::sin((viewAngle / 180.0) * M_PI) * objOffset.x +
                   std::cos((viewAngle / 180.0) * M_PI) * objOffset.z);

        objPosition = objPosition.translate(objOffset);

        Vector playerPosition = player->getWorldPosition();
        Vector playerToObj = Vector(playerPosition, objPosition);

        double distance = viewDirection.dot(playerToObj);
        if (distance > HALF_TILE / 2.0) {
            AlphaObject obj = AlphaObject(objPosition,
                                          -viewAngle,
                                          distance,
                                          ALPHAOBJECT_TYPE_PARTICLE,
                                          particle);
            alphaObjects.push_back(obj);
        }
    }

    return alphaObjects;
}

std::list<AlphaObject> Map::getPlayerParticleObjects() {
    std::list<AlphaObject> alphaObjects;

    std::list<Particle *> particles = player->getParticles();

    double viewAngle = player->getViewAngle();

    Vector viewDirection =
        Vector(std::cos(M_PI / 2.0 - (viewAngle / 180.0) * M_PI),
               0.0,
               -std::sin(M_PI / 2.0 - (viewAngle / 180.0) * M_PI));

    std::list<Particle *>::iterator it;
    for (it = particles.begin(); it != particles.end(); it++) {
        Particle *particle = (*it);

        Vector objPosition = particle->getWorldPosition();

        Vector objOffset = particle->getPosition(0.0);
        objOffset =
            Vector(std::cos((viewAngle / 180.0) * M_PI) * objOffset.x -
                   std::sin((viewAngle / 180.0) * M_PI) * objOffset.z,
                   objOffset.y,
                   std::sin((viewAngle / 180.0) * M_PI) * objOffset.x +
                   std::cos((viewAngle / 180.0) * M_PI) * objOffset.z);

        objPosition = objPosition.translate(objOffset);

        Vector playerPosition = player->getWorldPosition();
        Vector playerToObj = Vector(playerPosition, objPosition);

        double distance = viewDirection.dot(playerToObj);
        if (distance > -HALF_TILE) {
            AlphaObject obj = AlphaObject(objPosition,
                                          -viewAngle,
                                          distance,
                                          ALPHAOBJECT_TYPE_PARTICLE,
                                          particle);
            alphaObjects.push_back(obj);
        }
    }

    return alphaObjects;
}

Tile *Map::getPlayerTile() {
    Vector mapPosition = player->getMapPosition();

    Tile *tile = getTile((int)mapPosition.y, (int)mapPosition.x);

    return tile;
}

void Map::buildModels() {
    Engine::VideoSystem *videoSystem =
        Engine::Core::getInstance()->getVideoSystem();

    Model *wallModel = new WallModel(tileset, 0, 0.0,
                                     ceilingHeight * TILE_SIZE);
    videoSystem->newDisplayList("WallModel");
    wallModel->render();
    videoSystem->endDisplayList();
    delete wallModel;

    Model *floorModel = new FloorModel(tileset, 1, 0.0);
    videoSystem->newDisplayList("FloorModel");
    floorModel->render();
    videoSystem->endDisplayList();
    delete floorModel;

    Model *ceilingModel = new CeilingModel(tileset, 2,
                                           ceilingHeight * TILE_SIZE);
    videoSystem->newDisplayList("CeilingModel");
    ceilingModel->render();
    videoSystem->endDisplayList();
    delete ceilingModel;

    Model *doorFrameModel = new DoorFrameModel(tileset, 0, 0.0, TILE_SIZE);
    videoSystem->newDisplayList("DoorFrameModel");
    doorFrameModel->render();
    videoSystem->endDisplayList();
    delete doorFrameModel;

    Model *doorModel = new DoorModel(tileset, 3, 0.0, TILE_SIZE);
    videoSystem->newDisplayList("DoorModel");
    doorModel->render();
    videoSystem->endDisplayList();
    delete doorModel;

    Model *holeModel = new HoleModel(tileset, 0, 0.0);
    videoSystem->newDisplayList("HoleModel");
    holeModel->render();
    videoSystem->endDisplayList();
    delete holeModel;

    Model *pressurePlateModel = new PressurePlateModel(tileset, 1, 0.0);
    videoSystem->newDisplayList("PressurePlateModel");
    pressurePlateModel->render();
    videoSystem->endDisplayList();
    delete pressurePlateModel;
}

void Map::destroyModels() {
    Engine::VideoSystem *videoSystem =
        Engine::Core::getInstance()->getVideoSystem();

    videoSystem->destroyDisplayList("WallModel");
    videoSystem->destroyDisplayList("FloorModel");
    videoSystem->destroyDisplayList("CeilingModel");
    videoSystem->destroyDisplayList("DoorFrameModel");
    videoSystem->destroyDisplayList("DoorModel");
    videoSystem->destroyDisplayList("HoleModel");
    videoSystem->destroyDisplayList("PressurePlateModel");
}

void Map::load(std::string filename) {
    std::ifstream mapFile;
    mapFile.open(filename.c_str(), std::ios::in | std::ios::binary);

    if (mapFile.is_open()) {
        std::vector<std::string> charMap;

        unsigned char mRows = 0;
        unsigned char mCols = 0;
        unsigned char mTile = 0;

        mapFile.read((char *)(&mRows), sizeof(unsigned char));
        mapFile.read((char *)(&mCols), sizeof(unsigned char));

        width = mCols;
        height = mRows;

        charMap.clear();
        for (int row = 0; row < mRows; row++) {
            std::stringstream charRow;
            for (int col = 0; col < mCols; col++) {
                mapFile.read((char *)(&mTile), sizeof(unsigned char));

                charRow << mTile;
            }
            charMap.push_back(charRow.str());
        }

        mapFile.close();

        tiles.clear();
        for (int row = 0; row < mRows; row++) {
            std::vector<Tile *> tileRow;
            for (int col = 0; col < mCols; col++) {
                mTile = charMap[row][col];

                if (mTile == TILE_FLOOR) {
                    Tile *tile =
                        new FloorTile(this,
                                      Vector(col * TILE_SIZE,
                                             0.0,
                                             row * TILE_SIZE));
                    tileRow.push_back(tile);
                } else if (mTile == TILE_WALL) {
                    Tile *tile =
                        new WallTile(this,
                                     Vector(col * TILE_SIZE,
                                            0.0,
                                            row * TILE_SIZE));
                    tileRow.push_back(tile);
                } else if (mTile == TILE_DOOR) {
                    unsigned char lastTile = charMap[row][col - 1];

                    bool isVertical = (lastTile != TILE_WALL);
                    Tile *tile =
                        new DoorTile(this,
                                     Vector(col * TILE_SIZE,
                                            0.0,
                                            row * TILE_SIZE),
                                     isVertical);
                    tileRow.push_back(tile);
                } else if (mTile == TILE_SECRET_WALL) {
                    Tile *tile =
                        new SecretWallTile(this,
                                           Vector(col * TILE_SIZE,
                                                  0.0,
                                                  row * TILE_SIZE));
                    tileRow.push_back(tile);
                } else if (mTile == TILE_PRESSURE_PLATE) {
                    Tile *tile =
                        new PressurePlateTile(this,
                                              Vector(col * TILE_SIZE,
                                                     0.0,
                                                     row * TILE_SIZE));
                    tileRow.push_back(tile);
                } else if (mTile == TILE_HOLE) {
                    Tile *tile =
                        new HoleTile(this,
                                     Vector(col * TILE_SIZE,
                                            0.0,
                                            row * TILE_SIZE));
                    tileRow.push_back(tile);
                } else if (mTile == TILE_TRANSITION) {
                    int tileDirection = 0;
                    for (unsigned int dir = 0; dir < 4; dir++) {
                        unsigned char otherTile =
                            charMap[row + dy[dir]][col + dx[dir]];

                        if (otherTile == TILE_FLOOR) {
                            tileDirection = (dir + 2) % 4;
                        }
                    }

                    Tile *tile =
                        new MapTransitionTile(this,
                                              Vector(col * TILE_SIZE,
                                                     0.0,
                                                     row * TILE_SIZE),
                                              tileDirection);
                    tileRow.push_back(tile);
                }
            }
            tiles.push_back(tileRow);
        }
    }
}

void Map::buildMap(std::vector<std::string> stringMap) {
    width = stringMap[0].size();
    height = stringMap.size();

    for (int row = 0; row < height; row++) {
        std::vector<Tile *> tileRow;
        for (int col = 0; col < width; col++) {
            if (stringMap[row][col] == '#') {
                Tile *tile =
                    new WallTile(this,
                                 Vector(col * TILE_SIZE,
                                        0.0,
                                        row * TILE_SIZE));
                tileRow.push_back(tile);
            } else if (stringMap[row][col] == ' ') {
                Tile *tile =
                    new FloorTile(this,
                                  Vector(col * TILE_SIZE,
                                         0.0,
                                         row * TILE_SIZE));
                tileRow.push_back(tile);
            } else if (stringMap[row][col] == 'd') {
                bool isHorizontal = false;
                if (stringMap[row - 1][col] == '#') {
                    isHorizontal = true;
                }
                Tile *tile =
                    new DoorTile(this,
                                 Vector(col * TILE_SIZE,
                                        0.0,
                                        row * TILE_SIZE),
                                 isHorizontal);
                tileRow.push_back(tile);
            } else if (stringMap[row][col] == 's') {
                Tile *tile =
                    new SecretWallTile(this,
                                       Vector(col * TILE_SIZE,
                                              0.0,
                                              row * TILE_SIZE));
                tileRow.push_back(tile);
            } else if (stringMap[row][col] == 'h') {
                Tile *tile =
                    new HoleTile(this,
                                 Vector(col * TILE_SIZE,
                                        0.0,
                                        row * TILE_SIZE));
                tileRow.push_back(tile);
            } else if (stringMap[row][col] == 'p') {
                Tile *tile =
                    new PressurePlateTile(this,
                                          Vector(col * TILE_SIZE,
                                                 0.0,
                                                 row * TILE_SIZE));
                tileRow.push_back(tile);
            }
        }
        tiles.push_back(tileRow);
    }
}

Tile *Map::getTile(int row, int col) {
    Tile *tile = 0;

    if (row < 0 || row >= height ||
            col < 0 || col >= width) {
        // tile->setType(TILE_WALL);
    } else {
        tile = tiles[row][col];
    }

    return tile;
}

bool Map::hasLineOfSight(const Vector &a, const Vector &b) {
    bool lineOfSight = true;

    int x0 = (int)a.x;
    int y0 = (int)a.y;
    int x1 = (int)b.x;
    int y1 = (int)b.y;

    bool steep = abs(y1 - y0) > abs(x1 - x0);
    if (steep) {
        swap(x0, y0);
        swap(x1, y1);
    }
    if (x0 > x1) {
        swap(x0, x1);
        swap(y0, y1);
    }


    int deltaX = x1 - x0;
    int deltaY = abs(y1 - y0);
    double error = 0.0;
    double deltaError = (double)deltaY / (double)deltaX;

    int y = y0;
    int yStep = 1;
    if (y0 >= y1) {
        yStep = -1;
    }

    Tile *tile = 0;
    for (int x = x0; x <= x1 && lineOfSight; x++) {
        if (steep) {
            tile = tiles[x][y];
        } else {
            tile = tiles[y][x];
        }

        if (tile->blocksLineOfSight() && x != x0) {
            lineOfSight = false;
        } else {
            error += deltaError;
            if (error >= 0.5) {
                y += yStep;
                error -= 1.0;
            }
        }
    }

    return lineOfSight;
}

void Map::swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

std::vector<Tile *> Map::findPath(const Vector &start, const Vector &end) {
    std::vector<Tile *> path;
    bool foundPath = false;

    if (start.x != end.x || start.y != end.y) {
        std::queue<Tile *> toSearch;
        std::map<Tile *, bool> visited;
        std::map<Tile *, Tile *> parent;

        Tile *initialTile = getTile((int)end.y, (int)end.x);
        visited[initialTile] = true;
        parent[initialTile] = 0;

        toSearch.push(initialTile);
        while (!toSearch.empty() && !foundPath) {
            Tile *curTile = toSearch.front();
            toSearch.pop();

            Vector position = curTile->getMapPosition();

            for (int dir = 0; dir < 4 && !foundPath; dir++) {
                Tile *destTile = getTile((int)position.y + dy[dir],
                                         (int)position.x + dx[dir]);

                Vector destPosition = destTile->getMapPosition();
                if (destPosition.x == start.x &&
                        destPosition.y == start.y) {
                    foundPath = true;
                    parent[destTile] = curTile;
                } else {
                    bool freeToMove = (destTile->isPassable()) &&
                                      (destTile->getFreeSpace() >= 1) &&
                                      (!visited[destTile]);
                    if (freeToMove) {
                        toSearch.push(destTile);

                        visited[destTile] = true;
                        parent[destTile] = curTile;
                    }
                }
            }
        }

        if (foundPath) {
            Tile *tile = getTile((int)start.y, (int)start.x);
            tile = parent[tile];
            while (tile) {
                if (parent[tile]) {
                    path.push_back(tile);
                }
                tile = parent[tile];
            }
        }
    }

    return path;
}

std::vector<Tile *> Map::findRangedPath(const Vector &start,
                                        const Vector &end) {
    std::vector<Tile *> path;
    bool foundPath = false;

    std::vector<Tile *> destinations;
    for (int dir = 0; dir < 4; dir++) {
        Vector position = end;

        position = position.translate(Vector(dx[dir], dy[dir]));

        bool finished = false;
        while (!finished) {
            Tile *tile = getTile(position.y, position.x);
            if (tile->isPassable()) {
                Vector tilePosition = tile->getMapPosition();
                if (start.x == tilePosition.x &&
                        start.y == tilePosition.y) {
                    foundPath = true;
                    finished = true;
                } else {
                    destinations.push_back(tile);
                }
            } else {
                finished = true;
            }

            position = position.translate(Vector(dx[dir], dy[dir]));
        }
    }

    if (!foundPath) {
        std::queue<Tile *> toSearch;
        std::map<Tile *, bool> visited;
        std::map<Tile *, Tile *> parent;

        Tile *initialTile = getTile((int)start.y, (int)start.x);
        visited[initialTile] = true;
        parent[initialTile] = 0;

        Tile *finalTile = 0;

        toSearch.push(initialTile);
        while (!toSearch.empty() && !foundPath) {
            Tile *curTile = toSearch.front();
            toSearch.pop();

            Vector position = curTile->getMapPosition();

            for (int dir = 0; dir < 4 && !foundPath; dir++) {
                Tile *destTile = getTile((int)position.y + dy[dir],
                                         (int)position.x + dx[dir]);

                for (unsigned int i = 0;
                        i < destinations.size() && !foundPath; i++) {
                    Tile *tile = destinations[i];

                    if (destTile == tile) {
                        foundPath = true;
                        parent[destTile] = curTile;
                        finalTile = destTile;
                    }
                }

                if (!foundPath) {
                    bool freeToMove = (destTile->isPassable()) &&
                                      (destTile->getFreeSpace() >= 1) &&
                                      (!visited[destTile]);
                    if (freeToMove) {
                        toSearch.push(destTile);

                        visited[destTile] = true;
                        parent[destTile] = curTile;
                    }
                }
            }
        }

        if (foundPath) {
            std::vector<Tile *> tmpPath;
            Vector startPos = finalTile->getMapPosition();
            tmpPath.push_back(finalTile);

            Tile *tile = parent[finalTile];
            while (tile) {
                if (parent[tile]) {
                    tmpPath.push_back(tile);
                }
                tile = parent[tile];
            }

            while (!tmpPath.empty()) {
                tile = tmpPath.back();
                tmpPath.pop_back();

                path.push_back(tile);
            }
        }
    }

    return path;
}

void Map::moveMonsterTo(Monster *monster, Tile *tile) {
    Vector end = tile->getMapPosition();

    if (tile->getTotalMonsterSize() < 2) {
        tile->addMonster(monster);
    }
}
