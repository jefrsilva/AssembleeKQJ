#include "GameOverState.h"
#include "GameOverScreen.h"
#include "Font.h"

#include "Engine.h"

GameOverState::GameOverState() {
    started = false;

    this->gameover = new GameOverScreen();

    returnToMenu = false;
}

GameOverState::~GameOverState() {
    if (this->gameover) {
        delete this->gameover;
        this->gameover = 0;
    }
}

void GameOverState::start() {
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

    gameover->setFadeColor(Vector(1.0, 0.0, 0.0));
    gameover->setFadeAlpha(1.0);
    gameover->fadeIn(0.0, 2000);

    returnToMenu = false;
    started = true;
}

void GameOverState::stop() {
    started = false;
}

void GameOverState::update(double dt) {
    gameover->update(dt);

    if (returnToMenu && gameover->finishedFading()) {
        Engine::StateManager *stateManager =
            Engine::Core::getInstance()->getStateManager();

        stateManager->setCurrentState(0);
    }
}

void GameOverState::render(double edt) {
    gameover->render(edt);
}

void GameOverState::handleKeyboardEvents(SDL_Event* event) {
    if (event->key.type == SDL_KEYDOWN) {
        if (!returnToMenu && gameover->finishedFading()) {
            returnToMenu = true;
            gameover->setFadeColor(Vector(0.0, 0.0, 0.0));
            gameover->fadeOut(1500);
        }
    } else if (event->key.type == SDL_KEYUP) {

    }
}

void GameOverState::handleMouseEvents(SDL_Event* event) {
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
            if (!returnToMenu && gameover->finishedFading()) {
                returnToMenu = true;
                gameover->setFadeColor(Vector(0.0, 0.0, 0.0));
                gameover->fadeOut(1500);
            }
        } else if (button == SDL_BUTTON_RIGHT) {

        }
    } else if (event->type == SDL_MOUSEMOTION) {
        double mouseX =
            ((event->motion.x / winWidth) * orthoWidth) - orthoWidth / 2.0;
        double mouseY =
            -(((event->motion.y / winHeight) * orthoHeight) - orthoHeight / 2.0);

        gameover->setCursorPosition(Vector(mouseX, mouseY));
    }
}
