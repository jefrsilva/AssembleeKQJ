#include "DungeonCrawlingState.h"
#include "GameController.h"
#include "Font.h"

#include "Engine.h"

#include "toluaBindings.h"

#include <iostream>

DungeonCrawlingState::DungeonCrawlingState() {
    started = false;
    
    game = new GameController();
}

DungeonCrawlingState::~DungeonCrawlingState() {
    if (this->game) {
        delete this->game;
        this->game = 0;
    }
}

void DungeonCrawlingState::start() {
    game->newGame();
    
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glEnable(GL_LIGHTING);
    glShadeModel(GL_SMOOTH);

    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_SPECULAR);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    glEnable(GL_TEXTURE_2D);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    Engine::VideoSystem *videoSystem =
        Engine::Core::getInstance()->getVideoSystem();

    double width = videoSystem->getWindowWidth();
    double height = videoSystem->getWindowHeight();

    gluPerspective(45.0f, (double)width / (double)height,
                   3.0 * TILE_SIZE / 4.0, 200.0f);

    gluLookAt(0.0, HALF_TILE, TILE_SIZE,
              0.0, HALF_TILE, -TILE_SIZE,
              0.0, 1.0, 0.0);

    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
   
    
    Engine::ScriptingSystem *scriptingSystem =
        Engine::Core::getInstance()->getScriptingSystem();
        
    scriptingSystem->resetLuaState();
    lua_State *luaState = scriptingSystem->getLuaState();
    
    tolua_Attack_open(luaState);
    tolua_Defense_open(luaState);
    tolua_DoorTile_open(luaState);
    tolua_HoleTile_open(luaState);
    tolua_Item_open(luaState);
    tolua_Map_open(luaState);
    tolua_Monster_open(luaState);
    tolua_Player_open(luaState);
    tolua_PressurePlateTile_open(luaState);
    tolua_GameController_open(luaState);
    
    tolua_pushusertype(luaState, (void *)game, "GameController");
    lua_setglobal(luaState, "game");
    
    scriptingSystem->runScript("Resources/Scripts/NewGame.lua");

    started = true;
}

void DungeonCrawlingState::stop() {
    started = false;
}

void DungeonCrawlingState::handleKeyboardEvents(SDL_Event* event) {
    if (event->key.type == SDL_KEYDOWN) {
        if (event->key.keysym.sym == SDLK_w) {
            game->setPlayerMotion(DIR_FORWARD);
        } else if (event->key.keysym.sym == SDLK_a) {
            game->setPlayerMotion(DIR_STRAFE_LEFT);
        } else if (event->key.keysym.sym == SDLK_s) {
            game->setPlayerMotion(DIR_BACKWARDS);
        } else if (event->key.keysym.sym == SDLK_d) {
            game->setPlayerMotion(DIR_STRAFE_RIGHT);
        } else if (event->key.keysym.sym == SDLK_q) {
            game->setPlayerRotation(DIR_CCLOCKWISE);
        } else if (event->key.keysym.sym == SDLK_e) {
            game->setPlayerRotation(DIR_CLOCKWISE);
        } else if (event->key.keysym.sym == SDLK_SPACE) {
            game->endPlayerTurn();
        } else if (event->key.keysym.sym == SDLK_1) {
            game->handleInventoryShortcut(0);
        } else if (event->key.keysym.sym == SDLK_2) {
            game->handleInventoryShortcut(1);
        } else if (event->key.keysym.sym == SDLK_3) {
            game->handleInventoryShortcut(2);
        } else if (event->key.keysym.sym == SDLK_4) {
            game->handleInventoryShortcut(3);
        } else if (event->key.keysym.sym == SDLK_5) {
            game->handleInventoryShortcut(4);
        } else if (event->key.keysym.sym == SDLK_6) {
            game->handleInventoryShortcut(5);
        } else if (event->key.keysym.sym == SDLK_7) {
            game->handleInventoryShortcut(6);
        } else if (event->key.keysym.sym == SDLK_8) {
            game->handleInventoryShortcut(7);
        } else if (event->key.keysym.sym == SDLK_9) {
            game->handleInventoryShortcut(8);
        } else if (event->key.keysym.sym == SDLK_0) {
            game->handleInventoryShortcut(9);
        } else if (event->key.keysym.sym == SDLK_F1) {
            game->handleInventoryShortcut(10);
        } else if (event->key.keysym.sym == SDLK_F2) {
            game->handleInventoryShortcut(11);
        } else if (event->key.keysym.sym == SDLK_F3) {
            game->handleInventoryShortcut(12);
        } else if (event->key.keysym.sym == SDLK_F4) {
            game->handleInventoryShortcut(13);
        } else if (event->key.keysym.sym == SDLK_F5) {
            game->handleInventoryShortcut(14);
        } else if (event->key.keysym.sym == SDLK_F6) {
            game->handleInventoryShortcut(15);
        } else if (event->key.keysym.sym == SDLK_F7) {
            game->handleInventoryShortcut(16);
        } else if (event->key.keysym.sym == SDLK_F8) {
            game->handleInventoryShortcut(17);
        } else if (event->key.keysym.sym == SDLK_F9) {
            game->handleInventoryShortcut(18);
        } else if (event->key.keysym.sym == SDLK_F10) {
            game->handleInventoryShortcut(19);
        } else if (event->key.keysym.sym == SDLK_TAB) {
            game->setShowMap(true);
        } else if (event->key.keysym.sym == SDLK_m) {
            game->toggleMap();
        } else if (event->key.keysym.sym == SDLK_t) {
            game->toggleTutorial();
        }
    } else if (event->key.type == SDL_KEYUP) {
        if (event->key.keysym.sym == SDLK_w) {
            game->stopPlayerMotion(DIR_FORWARD);
        } else if (event->key.keysym.sym == SDLK_a) {
            game->stopPlayerMotion(DIR_STRAFE_LEFT);
        } else if (event->key.keysym.sym == SDLK_s) {
            game->stopPlayerMotion(DIR_BACKWARDS);
        } else if (event->key.keysym.sym == SDLK_d) {
            game->stopPlayerMotion(DIR_STRAFE_RIGHT);
        } else if (event->key.keysym.sym == SDLK_q) {
            game->stopPlayerRotation(DIR_CCLOCKWISE);
        } else if (event->key.keysym.sym == SDLK_e) {
            game->stopPlayerRotation(DIR_CLOCKWISE);
        } else if (event->key.keysym.sym == SDLK_TAB) {
            game->setShowMap(false);
        }
    }
}

void DungeonCrawlingState::handleMouseEvents(SDL_Event* event) {
    Engine::VideoSystem *videoSystem =
        Engine::Core::getInstance()->getVideoSystem();

    double winWidth = videoSystem->getWindowWidth();
    double winHeight = videoSystem->getWindowHeight();

    double orthoHeight = 1.0;
    double orthoWidth = (winWidth / winHeight) * orthoHeight;

    if (event->type == SDL_MOUSEBUTTONDOWN) {
        double mouseX =
            ((event->button.x / winWidth) * orthoWidth) - orthoWidth / 2.0;
        double mouseY =
            -(((event->button.y / winHeight) * orthoHeight) - orthoHeight / 2.0);

        unsigned int button = event->button.button;
        if (button == SDL_BUTTON_LEFT) {
            game->handleLeftClick(Vector(mouseX, mouseY));
        } else if (button == SDL_BUTTON_RIGHT) {
            game->handleRightClick(Vector(mouseX, mouseY));
        }
    } else if (event->type == SDL_MOUSEMOTION) {
        double mouseX =
            ((event->motion.x / winWidth) * orthoWidth) - orthoWidth / 2.0;
        double mouseY =
            -(((event->motion.y / winHeight) * orthoHeight) - orthoHeight / 2.0);

        game->setCursorPosition(Vector(mouseX, mouseY));
    }
}

void DungeonCrawlingState::render(double edt) {
    Engine::VideoSystem *videoSystem =
        Engine::Core::getInstance()->getVideoSystem();

    videoSystem->resetSelection();

    game->render(edt);
}

void DungeonCrawlingState::update(double dt) {
    game->update(dt);
}
