#include "Core.h"
#include "Engine.h"

#include <iostream>

using namespace Engine;

Core *Core::instance = 0;

Core::Core() {
    std::cout << "Core constructor." << std::endl;
    
    this->videoSystem = 0;
    this->audioSystem = 0;
    this->scriptingSystem = 0;
    this->stateManager = 0;
    this->randomNumberGenerator = 0;
}

Core::~Core() {
    std::cout << "Core destructor." << std::endl;
}

void Core::destroy() {
    if (instance) {
        delete instance;
        instance = 0;
    }
}

Core *Core::getInstance() {
    if (!instance) {
        instance = new Core();
    }

    return instance;
}

int Core::init() {
    int err = 0;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0) {
        std::cout << "Failed to initialize SDL." << std::endl;
        err = -1;
    } else {
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_SWAP_CONTROL, 1);

        if (!this->videoSystem) {
            this->videoSystem = new VideoSystem();
        }
        
        if (!this->audioSystem) {
            this->audioSystem = new AudioSystem();
            if (this->audioSystem->init() != 0) {
                err = -1;
            }
        }
        
        if (!this->scriptingSystem) {
            this->scriptingSystem = new ScriptingSystem();
        }
        
        if (!this->stateManager) {
            this->stateManager = new StateManager();
        }
        
        if (!this->randomNumberGenerator) {
            this->randomNumberGenerator = new RandomNumberGenerator();
        }
    }

    return err;
}

void Core::shutdown() {
    if (this->videoSystem) {
        delete this->videoSystem;
        this->videoSystem = 0;
    }
    
    if (this->audioSystem) {
        this->audioSystem->shutdown();
        delete this->audioSystem;
        this->audioSystem = 0;
    }
    
    if (this->scriptingSystem) {
        delete this->scriptingSystem;
        this->scriptingSystem = 0;
    }
    
    if (this->stateManager) {
        delete this->stateManager;
        this->stateManager = 0;
    }
    
    if (this->randomNumberGenerator) {
        delete this->randomNumberGenerator;
        this->randomNumberGenerator = 0;
    }

    SDL_Quit();
}

VideoSystem *Core::getVideoSystem() {
    return this->videoSystem;
}

AudioSystem *Core::getAudioSystem() {
    return this->audioSystem;
}

ScriptingSystem *Core::getScriptingSystem() {
    return this->scriptingSystem;
}

StateManager *Core::getStateManager() {
    return this->stateManager;
}

RandomNumberGenerator *Core::getRandomNumberGenerator() {
    return this->randomNumberGenerator;
}
