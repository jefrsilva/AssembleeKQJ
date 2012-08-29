#include "StateManager.h"

#include "Engine.h"

#include <iostream>

using namespace Engine;

StateManager::StateManager() {
    std::cout << "State manager constructor." << std::endl;

    this->currentState = 0;
}

StateManager::~StateManager() {
    for (unsigned int i = 0; i < states.size(); i++) {
        GameState *state = states[i];

        delete state;
    }

    std::cout << "State manager destructor." << std::endl;
}

void StateManager::setCurrentState(int stateNumber) {
    if (stateNumber == -1) {
        
        if (currentState) {
            currentState->stop();
        }
        
        currentState = 0;

    } else {

        if (currentState) {
            // currentState->stop();
        }

        currentState = states[stateNumber];
        currentState->start();

    }
}

void StateManager::pushState(GameState *state) {
    states.push_back(state);
}

GameState *StateManager::getCurrentState() {
    return this->currentState;
}
