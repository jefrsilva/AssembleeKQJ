#include <iostream>

#include "Engine.h"
#include "MainMenuState.h"
#include "DungeonCrawlingState.h"
#include "GameOverState.h"

int main(int argc, char **argv) {
    int err = 0;
    
    Engine::GameFramework framework;
    
    Engine::GameState *mainMenuState = new MainMenuState();
    Engine::GameState *dungeonCrawlingState = new DungeonCrawlingState();
    Engine::GameState *gameOverState = new GameOverState();    
    
    framework.setVideoMode(1024, 768, 32, false);
    //framework.setVideoMode(1280, 800, 32, true);        
    framework.addState(mainMenuState);
    framework.addState(dungeonCrawlingState);
    framework.addState(gameOverState);

    if (framework.run(0) != 0) {
        err = -1;
        std::cout << "Failed to run the game framework." << std::endl;
    }

    return err;
}
