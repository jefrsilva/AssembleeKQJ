#include "GameController.h"
#include "GlobalConstants.h"

#include "Player.h"
#include "Map.h"
#include "Tile.h"
#include "DoorTile.h"
#include "PressurePlateTile.h"
#include "UserInterface.h"
#include "InventoryBar.h"
#include "Vector.h"
#include "Item.h"
#include "Monster.h"
#include "TextWindow.h"

#include "Events.h"
#include "Animations.h"

#include "Engine.h"

#include <string>
#include <iostream>

GameController::GameController() {
    currentTurn = TURN_FREE;

    player = new Player();

    map = 0;

    gui = new UserInterface(player);

    eventManager = new EventManager(this);

    movingForward = false;
    movingBackwards = false;
    strafingLeft = false;
    strafingRight = false;
    turningLeft = false;
    turningRight = false;

    endTurn = false;
    endGame = false;
    paused = false;
    nextState = 0;
}

GameController::~GameController() {
    if (this->player) {
        delete this->player;
        this->player = 0;
    }

    std::map<std::string, Map *>::iterator it;
    for (it = maps.begin(); it != maps.end(); it++) {
        Map *map = (*it).second;

        delete map;
    }
    maps.clear();
    if (this->map) {
        this->map = 0;
    }

    if (this->gui) {
        delete this->gui;
        this->gui = 0;
    }

    if (this->eventManager) {
        delete this->eventManager;
        this->eventManager = 0;
    }
}

void GameController::newGame() {
    currentTurn = TURN_FREE;

    if (this->player) {
        delete this->player;
        this->player = 0;
    }

    std::map<std::string, Map *>::iterator it;
    for (it = maps.begin(); it != maps.end(); it++) {
        Map *oldMap = (*it).second;

        delete oldMap;
    }
    maps.clear();
    if (this->map) {
        this->map = 0;
    }

    if (this->gui) {
        delete this->gui;
        this->gui = 0;
    }

    if (this->eventManager) {
        delete this->eventManager;
        this->eventManager = 0;
    }

    globalVars.clear();

    player = new Player();
    map = 0;
    gui = new UserInterface(player);

    delete eventManager;
    eventManager = new EventManager(this);

    movingForward = false;
    movingBackwards = false;
    strafingLeft = false;
    strafingRight = false;
    turningLeft = false;
    turningRight = false;

    endTurn = false;
    endGame = false;
    paused = false;
    nextState = 0;
}

void GameController::setupView() {
    if (map) {
        map->setupBackgroundColor();
    } else {
        glClearColor(0.0, 0.0, 0.0, 0.0);
    }

    glClearDepth(200.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
}

void GameController::handleSelection() {
    if (!paused) {

        Engine::VideoSystem *videoSystem =
            Engine::Core::getInstance()->getVideoSystem();

        glDisable(GL_FOG);
        glDisable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);

        setupView();
        map->render(0.0, true);
        gui->render(0.0, true);

        glEnable(GL_FOG);
        glEnable(GL_LIGHTING);
        glEnable(GL_TEXTURE_2D);

        Vector cursor = gui->getCursorPosition();
        selection =
            videoSystem->getSelectionObject(cursor.x,
                                            cursor.y);

        if (selection.getType() == SEL_OBJ_ITEM) {
            Item *item = (Item *)selection.getData();

            Tooltip *tooltip = item->getTooltip();
            gui->setWorldTooltip(tooltip);
        } else if (selection.getType() == SEL_OBJ_MONSTER) {
            Monster *monster = (Monster *)selection.getData();

            Tooltip *tooltip = monster->getTooltip();
            gui->setWorldTooltip(tooltip);
        } else if (selection.getType() == SEL_OBJ_DOOR) {
            DoorTile *door = (DoorTile *)selection.getData();

            Tooltip *tooltip = door->getTooltip();
            gui->setWorldTooltip(tooltip);
        } else {
            gui->setWorldTooltip(0);
        }

    }
}

void GameController::freeTurnUpdate(double dt) {
    if (!endTurn) {
        if (turningLeft) {
            turnPlayer(DIR_CCLOCKWISE);
        } else if (turningRight) {
            turnPlayer(DIR_CLOCKWISE);
        } else if (strafingLeft) {
            movePlayer(DIR_STRAFE_LEFT);
        } else if (strafingRight) {
            movePlayer(DIR_STRAFE_RIGHT);
        } else if (movingForward) {
            movePlayer(DIR_FORWARD);
        } else if (movingBackwards) {
            movePlayer(DIR_BACKWARDS);
        }

        activateHostileMonsters();
    }

    if (endTurn && !eventManager->hasPendingEvents()) {
        player->resetTurn();

        changeTurn(TURN_PLAYER);

        turningLeft = false;
        turningRight = false;
        strafingLeft = false;
        strafingRight = false;
        movingForward = false;
        movingBackwards = false;

        std::list<Monster *> monsters = map->getMonsters();
        std::list<Monster *>::iterator it;
        for (it = monsters.begin(); it != monsters.end(); it++) {
            Monster *monster = (*it);
            if (monster->isActivated()) {
                monster->resetTurn();
            }
        }
    }
}

void GameController::playerTurnUpdate(double dt) {
    if (!endTurn) {
        if (turningLeft) {
            turnPlayer(DIR_CCLOCKWISE);
        } else if (turningRight) {
            turnPlayer(DIR_CLOCKWISE);
        } else if (strafingLeft) {
            movePlayer(DIR_STRAFE_LEFT);
        } else if (strafingRight) {
            movePlayer(DIR_STRAFE_RIGHT);
        } else if (movingForward) {
            movePlayer(DIR_FORWARD);
        } else if (movingBackwards) {
            movePlayer(DIR_BACKWARDS);
        }

        turningLeft = false;
        turningRight = false;
        strafingLeft = false;
        strafingRight = false;
        movingForward = false;
        movingBackwards = false;

        int activeMonsters = 0;
        std::list<Monster *> monsters = map->getMonsters();
        std::list<Monster *>::iterator it;
        for (it = monsters.begin(); it != monsters.end(); it++) {
            Monster *monster = (*it);

            Vector pMonster = monster->getMapPosition();
            Vector pPlayer = player->getMapPosition();

            double distance = Vector(pMonster, pPlayer).length();

            if (monster->getHealth() > 0 &&
                    map->hasLineOfSight(pMonster, pPlayer)) {
                std::string monsterFaction = monster->getFaction();
                int factionStance =
                    player->getFactionStance(monsterFaction);
                if (factionStance == FACTION_HOSTILE) {
                    if (monster->isActivated()) {
                        activeMonsters++;
                    } else {
                        if (distance <= monster->getActivationRange()) {
                            monster->activate();
                            activeMonsters++;
                        }
                    }
                }
            } else {
                monster->deactivate();
            }
        }

        if (activeMonsters == 0) {
            changeTurn(TURN_FREE);

            player->resetInventoryDelay();
            player->resetTurn();
        }
    } else {
        if (!eventManager->hasPendingEvents()) {
            changeTurn(TURN_ENEMY);

            std::list<Monster *> monsters = map->getMonsters();
            std::list<Monster *>::iterator it;
            for (it = monsters.begin(); it != monsters.end(); it++) {
                Monster *monster = (*it);
                if (monster->isActivated()) {
                    monster->resetTurn();
                }
            }
        }
    }
}

void GameController::enemyTurnUpdate(double dt) {
    endTurn = true;

    std::list<Monster *> monsters = map->getMonsters();
    std::list<Monster *>::iterator it;
    for (it = monsters.begin(); it != monsters.end(); it++) {
        Monster *monster = (*it);

        if (monster->isActivated()) {
            if (!monster->hasEndedTurn()) {
                if (!monster->isStunned()) {
                    Vector monsterPosition = monster->getMapPosition();
                    Vector playerPosition = player->getMapPosition();

                    double distance =
                        Vector(playerPosition, monsterPosition).length();

                    std::vector<Tile *> path;
                    if (monster->isRangedAttacker()) {
                        path = map->findRangedPath(monsterPosition,
                                                   playerPosition);

                        if (path.size() >= 1) {
                            Tile *destination = path[0];

                            Event *event =
                                new MonsterMoveEvent(map, monster,
                                                     destination);

                            eventManager->queueEvent(event);
                        } else {
                            path = map->findPath(monsterPosition,
                                                 playerPosition);

                            if (distance <= 1.0 || path.size() >= 1) {
                                Event *event =
                                    new MonsterAttackEvent(this, gui, player,
                                                           monster);

                                eventManager->queueEvent(event);
                            } else {
                                monster->deactivate();
                            }
                        }
                    } else {
                        if (distance > 1.0) {
                            path = map->findPath(monsterPosition,
                                                 playerPosition);

                            if (path.size() >= 1) {
                                Tile *destination = path[0];

                                Event *event =
                                    new MonsterMoveEvent(map, monster,
                                                         destination);

                                eventManager->queueEvent(event);
                            } else {
                                monster->deactivate();
                            }
                        } else {
                            Event *event =
                                new MonsterAttackEvent(this, gui, player,
                                                       monster);

                            eventManager->queueEvent(event);
                        }
                    }
                }
                monster->endTurn();
                endTurn = false;
            } else {
                if (monster->isMoving()) {
                    endTurn = false;
                }
            }
        }
    }

    if (endTurn && !eventManager->hasPendingEvents()) {
        player->tickInventoryDelay();
        player->resetTurn();

        changeTurn(TURN_PLAYER);

        std::list<Monster *> monsters = map->getMonsters();
        std::list<Monster *>::iterator it;
        for (it = monsters.begin(); it != monsters.end(); it++) {
            Monster *monster = (*it);
            if (monster->isActivated()) {
                monster->resetTurn();
                monster->tickStunCounter();
            }
        }
    }
}

void GameController::update(double dt) {
    if (endGame && gui->finishedFading()) {
        Engine::StateManager *stateManager =
            Engine::Core::getInstance()->getStateManager();

        stateManager->setCurrentState(nextState);
    }

    if (map) {
        if (currentTurn == TURN_FREE) {
            freeTurnUpdate(dt);
        } else if (currentTurn == TURN_PLAYER) {
            playerTurnUpdate(dt);
        } else if (currentTurn == TURN_ENEMY) {
            enemyTurnUpdate(dt);
        }

        player->update(dt);

        if (!endGame && player->getHealth() <= 0) {
            pause();
            fadeOutMusic(1000);
            gui->setFadeColor(Vector(1.0, 0.0, 0.0));
            gui->fadeOut(1500);

            nextState = 2;
            endGame = true;
        }

        map->update(dt);

        gui->setTurn(currentTurn);
        gui->update(dt);

        handleSelection();
    }

    eventManager->update(dt);
}

void GameController::render(double edt) {
    setupView();

    if (map) {
        map->render(edt, false);
        gui->render(edt, false);
    }
}

void GameController::handleLeftClick(const Vector &mousePosition) {
    if (!gui->handleMouseClick(mousePosition, MOUSE_BUTTON_LEFT) &&
            !paused) {
        if (selection.getType() == SEL_OBJ_ITEM) {
            Item *item = (Item *)selection.getData();

            gui->handleMouseClick(item, MOUSE_BUTTON_LEFT);
        } else if (selection.getType() == SEL_OBJ_MONSTER) {
            if (TURN_PLAYER && !eventManager->hasPendingEvents()) {
                // Player attack
                Monster *monster = (Monster *)selection.getData();
                Item *item = gui->getCursorItem();

                std::string faction = monster->getFaction();
                int factionStance = player->getFactionStance(faction);
                if (factionStance == FACTION_HOSTILE) {
                    if (item) {
                        if (item->getType() == ITEM_TYPE_SWORD ||
                                item->getType() == ITEM_TYPE_AXE ||
                                item->getType() == ITEM_TYPE_SPEAR ||
                                item->getType() == ITEM_TYPE_BOW) {
                            playerAttack(item, monster);
                        }
                    }
                }
            }
        } else if (selection.getType() == SEL_OBJ_DOOR) {
            DoorTile *door = (DoorTile *)selection.getData();
            Item *item = gui->getCursorItem();

            Vector tilePos = door->getMapPosition();
            Vector playerPos = player->getMapPosition();

            double distance = Vector(tilePos, playerPos).length();
            if (distance == 1.0) {
                Event *event = new ActivateDoorEvent(door, item);
                eventManager->queueEvent(event);
            }
        } else if (selection.getType() == SEL_OBJ_PRESSURE_PLATE) {
            PressurePlateTile *plate =
                (PressurePlateTile *)selection.getData();

            Vector tilePos = plate->getMapPosition();
            Vector playerPos = player->getMapPosition();

            double distance = Vector(tilePos, playerPos).length();
            if (distance <= 1.0) {
                gui->handleMouseClick(plate, MOUSE_BUTTON_LEFT);
            } else {
                gui->handleMouseClick(map->getPlayerTile(),
                                      MOUSE_BUTTON_LEFT);
            }
        } else if (selection.getType() == SEL_OBJ_NONE) {
            gui->handleMouseClick(map->getPlayerTile(), MOUSE_BUTTON_LEFT);
        }
    }
}

void GameController::handleRightClick(const Vector &mousePosition) {
    if (!paused) {

        if (selection.getType() == SEL_OBJ_MONSTER) {
            if (TURN_PLAYER && !eventManager->hasPendingEvents()) {
                // Player attack
                Monster *monster = (Monster *)selection.getData();
                Item *item = 0;

                std::vector<Item *> items = player->getInventory();

                bool found = false;
                for (unsigned int i = 0; i < items.size() && !found; i++) {
                    item = items[i];
                    if (item) {
                        if (item->getType() == ITEM_TYPE_SWORD ||
                                item->getType() == ITEM_TYPE_AXE ||
                                item->getType() == ITEM_TYPE_SPEAR ||
                                item->getType() == ITEM_TYPE_BOW) {
                            if (!item->onDelay() && item->getDurability() > 0) {
                                found = true;
                            }
                        }
                    }
                }

                if (found) {
                    playerAttack(item, monster);
                }
            }
        } else if (selection.getType() == SEL_OBJ_NONE) {

            InventoryBar *inventoryBar = gui->getInventoryBar();

            Item *item = inventoryBar->getItem(mousePosition);
            if (item) {
                if (item->getType() == ITEM_TYPE_SHIELD) {
                    if (currentTurn == TURN_PLAYER &&
                            !eventManager->hasPendingEvents()) {
                        playerDefense(item);
                    }
                } else if (item->getType() == ITEM_TYPE_CONSUMABLE) {
                    if (currentTurn != TURN_ENEMY) {
                        item = inventoryBar->detachItem(mousePosition);
                        item->consume();
                        item->unlock();

                        if (item->wasConsumed()) {
                            player->removeItem(item);
                            delete item;
                        }
                    }
                }
            }

        }
    }
}

void GameController::setCursorPosition(const Vector &cursorPosition) {
    gui->setCursorPosition(cursorPosition);
}

void GameController::setPlayerMotion(int direction) {
    if (!paused && gui->finishedFading()) {

        switch (direction) {
            case DIR_FORWARD:
                movingForward = true;
                break;

            case DIR_BACKWARDS:
                movingBackwards = true;
                break;

            case DIR_STRAFE_LEFT:
                strafingLeft = true;
                break;

            case DIR_STRAFE_RIGHT:
                strafingRight = true;
                break;
        }

    }
}

void GameController::setPlayerRotation(int direction) {
    if (!paused && gui->finishedFading()) {

        switch (direction) {
            case DIR_CCLOCKWISE:
                turningLeft = true;
                break;

            case DIR_CLOCKWISE:
                turningRight = true;
                break;
        }

    }
}

void GameController::stopPlayerMotion(int direction) {
    switch (direction) {
        case DIR_FORWARD:
            movingForward = false;
            break;

        case DIR_BACKWARDS:
            movingBackwards = false;
            break;

        case DIR_STRAFE_LEFT:
            strafingLeft = false;
            break;

        case DIR_STRAFE_RIGHT:
            strafingRight = false;
            break;
    }
}

void GameController::stopPlayerRotation(int direction) {
    switch (direction) {
        case DIR_CCLOCKWISE:
            turningLeft = false;
            break;

        case DIR_CLOCKWISE:
            turningRight = false;
            break;
    }
}

void GameController::movePlayer(int direction) {
    if (!player->isMoving() && gui->finishedFading()) {
        Event *event = new MovePlayerEvent(this, gui, player, direction);
        eventManager->queueEvent(event);
    }
}

void GameController::turnPlayer(int direction) {
    if (!player->isMoving()) {
        Event *event = new TurnPlayerEvent(player, direction);
        eventManager->queueEvent(event);
    }
}

void GameController::setShowMap(bool showMap) {
    gui->setShowMap(showMap);
}

void GameController::toggleMap() {
    gui->toggleMap();
}

void GameController::toggleTutorial() {
    gui->toggleTutorial();
}

Player *GameController::getPlayer() {
    return player;
}

Map *GameController::getMap() {
    return map;
}

void GameController::setGlobalVar(std::string varName, int varValue) {
    globalVars[varName] = varValue;
}

int GameController::getGlobalVar(std::string varName) {
    int varValue = -1;

    std::map<std::string, int>::iterator it =
        globalVars.find(varName);

    if (it != globalVars.end()) {
        varValue = (*it).second;
    }

    return varValue;
}

int GameController::getCurrentTurn() {
    return currentTurn;
}

void GameController::nextTurn() {
    endTurn = true;
}

void GameController::changeTurn(int turn) {
    currentTurn = turn;
    endTurn = false;

    if (currentTurn == TURN_PLAYER) {
        callChangeTurnScript();

        AttackAnimationEvent *animationEvent =
            new AttackAnimationEvent();

        Vector position = gui->getTurnStonePosition();
        position = position.translate(Vector(0.0, 0.045, 0.0));
        Animation *animation =
            new PlayerTurnAnimation(position);

        animationEvent->addAnimation(animation);
        gui->attachAnimation(animation);

        eventManager->queueAsyncEvent(animationEvent);
    } else if (currentTurn == TURN_ENEMY) {
        AttackAnimationEvent *animationEvent =
            new AttackAnimationEvent();

        Vector position = gui->getTurnStonePosition();
        position = position.translate(Vector(0.0, 0.045, 0.0));
        Animation *animation =
            new EnemyTurnAnimation(position);

        animationEvent->addAnimation(animation);
        gui->attachAnimation(animation);

        eventManager->queueEvent(animationEvent);
    }
}

void GameController::endPlayerTurn() {
    if (currentTurn == TURN_PLAYER && !player->isMoving()) {
        endTurn = true;
    }
}

void GameController::queueAsyncEvent(Event *event) {
    eventManager->queueAsyncEvent(event);
}

void GameController::queueEvent(Event *event) {
    eventManager->queueEvent(event);
}

void GameController::queueFrontEvent(Event *event) {
    eventManager->queueFrontEvent(event);
}

void GameController::handleInventoryShortcut(int slot) {
    Vector position = gui->getSlotPosition(slot);

    gui->handleMouseClick(position, MOUSE_BUTTON_LEFT);
}

void GameController::activateHostileMonsters() {
    std::list<Monster *> monsters = map->getMonsters();
    std::list<Monster *>::iterator it;
    for (it = monsters.begin(); it != monsters.end(); it++) {
        Monster *monster = (*it);

        Vector pMonster = monster->getMapPosition();
        Vector pPlayer = player->getMapPosition();

        double distance = Vector(pPlayer, pMonster).length();

        if (map->hasLineOfSight(monster->getMapPosition(),
                                player->getMapPosition())) {
            std::string monsterFaction = monster->getFaction();
            int factionStance =
                player->getFactionStance(monsterFaction);
            if (factionStance == FACTION_HOSTILE) {
                if (distance <= monster->getActivationRange()) {
                    monster->activate();
                    endTurn = true;
                }
            } else {
                monster->endTurn();
                monster->deactivate();
            }
        }
    }
}

void GameController::playerAttack(Item *item, Monster *monster) {
    Vector monsterPos = monster->getMapPosition();
    Vector playerPos = player->getMapPosition();

    if (!item->onDelay()) {
        if (item->getType() == ITEM_TYPE_SWORD) {
            double distance = Vector(monsterPos, playerPos).length();
            if (distance <= 1.0 && item->getSlotNumber() != -1) {
                Event *event =
                    new PlayerAttackEvent(this, gui, item, monster);
                gui->detachCursorItem();
                eventManager->queueEvent(event);
            }
        } else if (item->getType() == ITEM_TYPE_AXE) {
            double distance = Vector(monsterPos, playerPos).length();
            if (distance <= 1.0 && item->getSlotNumber() != -1) {
                Event *event =
                    new PlayerAttackEvent(this, gui, item, monster);
                eventManager->queueEvent(event);

                Tile *monsterTile = monster->getTile();

                std::vector<Monster *> monsters = monsterTile->getMonsters();
                for (unsigned int i = 0; i < monsters.size(); i++) {
                    if (monsters[i] != monster) {
                        event =
                            new PlayerAttackEvent(this, gui, item, monsters[i]);
                        eventManager->queueEvent(event);
                    }
                }
                gui->detachCursorItem();
            }
        } else if (item->getType() == ITEM_TYPE_SPEAR) {
            if (playerPos.x == monsterPos.x ||
                    playerPos.y == monsterPos.y) {
                double distance = Vector(monsterPos, playerPos).length();
                if (distance <= 2.0 && item->getSlotNumber() != -1) {
                    Event *event =
                        new PlayerAttackEvent(this, gui, item, monster);
                    gui->detachCursorItem();
                    eventManager->queueEvent(event);
                }
            }
        } else if (item->getType() == ITEM_TYPE_BOW) {
            if (playerPos.x == monsterPos.x ||
                    playerPos.y == monsterPos.y) {
                if (item->getSlotNumber() != -1) {
                    Event *event =
                        new PlayerAttackEvent(this, gui, item, monster);
                    gui->detachCursorItem();
                    eventManager->queueEvent(event);
                }
            }
        }
    }
}

void GameController::playerDefense(Item *item) {
    if (!item->onDelay()) {
        if (item->getSlotNumber() != -1) {
            Event *event =
                new PlayerDefenseEvent(this, gui, player, item);
            eventManager->queueEvent(event);
        }
    }
}

void GameController::dropItems(Monster *monster) {
    std::vector<std::string> drops = monster->getItemDrops();
    Tile *monsterTile = monster->getTile();

    for (unsigned int i = 0; i < drops.size(); i++) {
        Item *item = newItem(drops[i]);
        monsterTile->addItem(item);
    }
}

void GameController::setPlayerMap(Map *newMap) {
    if (map) {
        map->destroyModels();
    }

    newMap->buildModels();
    newMap->setupFogAndLighting();

    newMap->setPlayer(player);
    gui->setMap(newMap);

    this->map = newMap;
}

void GameController::callEnterTileScript(const Vector &mapPosition) {
    Engine::ScriptingSystem *scriptingSystem =
        Engine::Core::getInstance()->getScriptingSystem();

    lua_State *luaState = scriptingSystem->getLuaState();

    std::string mapID = map->getID();
    lua_getglobal(luaState, mapID.c_str());
    lua_pushstring(luaState, "onEnterTile");
    lua_gettable(luaState, -2);
    tolua_pushusertype(luaState, (void *)map, "Map");
    lua_pushnumber(luaState, mapPosition.y);
    lua_pushnumber(luaState, mapPosition.x);
    lua_call(luaState, 3, 0);
    lua_pop(luaState, 1);
}

void GameController::callChangeTurnScript() {
    Engine::ScriptingSystem *scriptingSystem =
        Engine::Core::getInstance()->getScriptingSystem();

    lua_State *luaState = scriptingSystem->getLuaState();

    std::string mapID = map->getID();
    lua_getglobal(luaState, mapID.c_str());
    lua_pushstring(luaState, "onChangeTurn");
    lua_gettable(luaState, -2);
    tolua_pushusertype(luaState, (void *)map, "Map");
    lua_call(luaState, 1, 0);
    lua_pop(luaState, 1);
}

void GameController::setPaused(bool paused) {
    this->paused = paused;
}

void GameController::pause() {
    Event *event = new PauseGameEvent(this);
    eventManager->queueEvent(event);
}

void GameController::resume() {
    Event *event = new ResumeGameEvent(this);
    eventManager->queueEvent(event);
}

void GameController::returnToMenu() {
    Event *event = new ReturnToMenuEvent(this);
    eventManager->queueEvent(event);
}

void GameController::changeState() {
    fadeOutMusic(2000);
    gui->setFadeColor(Vector(0.0, 0.0, 0.0));
    gui->fadeOut(2500);

    nextState = 0;
    endGame = true;
}

void GameController::fadeInMapMusic(std::string mapID, int duration) {
    std::string musicID = maps[mapID]->getMusicID();

    Event *event = new FadeInMusicEvent(musicID, duration);
    eventManager->queueEvent(event);
}

void GameController::fadeOutMusic(int duration) {
    Event *event = new FadeOutMusicEvent(duration);
    eventManager->queueEvent(event);
}

void GameController::setFadeColor(double r, double g, double b) {
    Vector color = Vector(r, g, b);
    Event *event = new SetFadeColorEvent(gui, color);
    eventManager->queueEvent(event);
}

void GameController::fadeIn(double duration) {
    Event *event = new FadeInEvent(gui, duration);
    eventManager->queueEvent(event);
}

void GameController::fadeOut(double duration) {
    Event *event = new FadeOutEvent(gui, duration);
    eventManager->queueEvent(event);
}

void GameController::playerGiveItem(Item *item) {
    Event *event = new PlayerGiveItemEvent(map, player, item);
    eventManager->queueEvent(event);
}

bool GameController::playerHasItem(std::string itemID) {
    bool hasItem = player->hasItem(itemID);

    return hasItem;
}

void GameController::healPlayer(int amount) {
    Event *event = new PlayerHealEvent(this, gui, amount);
    eventManager->queueEvent(event);
}

void GameController::increaseMaxHealth(int amount) {
    Event *event = new PlayerIncreaseVitalityEvent(this, gui, amount);
    eventManager->queueEvent(event);
}

void GameController::setPlayerDirection(int direction) {
    Event *event = new SetPlayerDirectionEvent(player, direction);
    eventManager->queueEvent(event);
}

void GameController::setPlayerLocation(std::string mapID,
                                       int row, int col, int direction) {
    Map *newMap = maps[mapID];

    Event *event = new SetPlayerLocationEvent(this, newMap, row, col, direction);
    eventManager->queueEvent(event);
}

void GameController::loadMap(std::string mapID) {
    std::string mapDataPath = "Resources/Maps/" + mapID + ".map";
    std::string mapScriptPath = "Resources/Scripts/Maps/" + mapID + ".lua";

    Map *newMap = new Map(mapID);
    newMap->load(mapDataPath);

    Engine::ScriptingSystem *scriptingSystem =
        Engine::Core::getInstance()->getScriptingSystem();

    scriptingSystem->runScript(mapScriptPath);

    lua_State *luaState = scriptingSystem->getLuaState();

    lua_getglobal(luaState, mapID.c_str());
    lua_pushstring(luaState, "setup");
    lua_gettable(luaState, -2);
    tolua_pushusertype(luaState, (void *)newMap, "Map");
    lua_call(luaState, 1, 0);
    lua_pop(luaState, 1);

    maps[mapID] = newMap;
}

void GameController::playMusic(std::string musicID) {
    Event *event = new PlayMusicEvent(musicID);
    eventManager->queueEvent(event);

}

void GameController::playSound(std::string soundID) {
    Event *event = new PlaySoundEvent(soundID);
    eventManager->queueEvent(event);
}

Monster *GameController::newMonster(std::string monsterID,
                                    std::string instanceID) {
    Engine::ScriptingSystem *scriptingSystem =
        Engine::Core::getInstance()->getScriptingSystem();

    lua_State *luaState = scriptingSystem->getLuaState();

    Monster *monster = new Monster(monsterID, instanceID);

    lua_getglobal(luaState, monsterID.c_str());
    lua_pushstring(luaState, "setup");
    lua_gettable(luaState, -2);
    tolua_pushusertype(luaState, (void *)monster, "Monster");
    lua_call(luaState, 1, 0);
    lua_pop(luaState, 1);

    return monster;
}

Item *GameController::newItem(std::string itemID) {
    Engine::ScriptingSystem *scriptingSystem =
        Engine::Core::getInstance()->getScriptingSystem();

    lua_State *luaState = scriptingSystem->getLuaState();

    Item *item = new Item(itemID);

    lua_getglobal(luaState, itemID.c_str());
    lua_pushstring(luaState, "setup");
    lua_gettable(luaState, -2);
    tolua_pushusertype(luaState, (void *)item, "Item");
    lua_call(luaState, 1, 0);
    lua_pop(luaState, 1);

    return item;
}

void GameController::createTextWindow(double x, double y,
                                      std::string text, int width,
                                      bool blocking) {
    Event *event =
        new TextWindowEvent(this, gui, Vector(x, y), text, width, blocking);
    eventManager->queueEvent(event);
}

void GameController::createTextWindow(Monster *monster, std::string text,
                                      int width, bool blocking) {
    Event *event =
        new TextWindowEvent(this, gui, monster, text, width, blocking);
    eventManager->queueEvent(event);
}

void GameController::createTutorialWindow(std::string text) {
    Event *event =
        new TutorialWindowEvent(this, gui, text);
    eventManager->queueEvent(event);
}

void GameController::clearTutorialWindow() {
    Event *event =
        new ClearTutorialWindowEvent(gui);
    eventManager->queueEvent(event);
}
