#include "GameFramework.h"

#include "Engine.h"

using namespace Engine;

#include <iostream>

GameFramework::GameFramework() {
    paused = false;
    logicFrameDuration = 16.0;
    windowWidth = 1024;
    windowHeight = 768;
    windowDepth = 32;
    fullscreen = false;
}

GameFramework::~GameFramework() {

}

void GameFramework::setVideoMode(unsigned int width, unsigned int height,
                                 unsigned int depth, bool fullscreen) {
    this->windowWidth = width;
    this->windowHeight = height;
    this->windowDepth = depth;
    this->fullscreen = fullscreen;
}

void GameFramework::setLogicFrameDuration(double duration) {
    this->logicFrameDuration = duration;
}

int GameFramework::run(int stateNumber) {
    int err = 0;

    VideoSystem *videoSystem = 0;
    AudioSystem *audioSystem = 0;

    Core *core = Core::getInstance();
    if (core->init() != 0) {
        err = -1;
    } else {
        audioSystem = core->getAudioSystem();
        videoSystem = core->getVideoSystem();
        if (videoSystem->setVideoMode(windowWidth, windowHeight,
                                      windowDepth, fullscreen) != 0) {
            err = -1;
        } else {
            bool finished = false;

            double elapsedTime = 0.0;
            double currentTime = 0.0;
            double lastTime = SDL_GetTicks();

            StateManager *stateManager = core->getStateManager();
            for (unsigned int i = 0; i < states.size(); i++) {
                GameState *state = states[i];
                stateManager->pushState(state);                
            }
            stateManager->setCurrentState(stateNumber);

            while (!finished) {
                GameState *state = stateManager->getCurrentState();
                if (!state) {
                    finished = true;
                    continue;
                }

                SDL_Event event;
                while (SDL_PollEvent(&event)) {
                    switch (event.type) {
                        case SDL_USEREVENT:
                            break;

                        case SDL_MOUSEMOTION:
                        case SDL_MOUSEBUTTONUP:
                        case SDL_MOUSEBUTTONDOWN:
                            state->handleMouseEvents(&event);
                            break;

                        case SDL_KEYUP:
                        case SDL_KEYDOWN:
                            if (event.key.keysym.sym == SDLK_ESCAPE) {
                                finished = true;
                            } else {
                                state->handleKeyboardEvents(&event);
                            }
                            break;

                        case SDL_QUIT:
                            finished = true;
                            continue;
                    }
                }

                currentTime = SDL_GetTicks();
                if (!paused) {
                    elapsedTime += currentTime - lastTime;
                }
                lastTime = currentTime;

                while (elapsedTime >= logicFrameDuration) {
                    elapsedTime -= logicFrameDuration;

                    state->update(logicFrameDuration);
                }

                state->render(elapsedTime);

                videoSystem->swapBuffers();
            }
        }
    }

    core->shutdown();
    Core::destroy();

    return err;
}

void GameFramework::addState(GameState *state) {
    states.push_back(state);
}
