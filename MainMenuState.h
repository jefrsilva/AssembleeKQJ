#ifndef __mainmenustate__
#define __mainmenustate__

#include "Engine.h"
#include "GlobalConstants.h"

class Menu;

/**
 * \class MainMenuState
 * \author Jeferson Rodrigues da Silva
 * \date 01/09/2010
 * \file MainMenuState.h
 * \brief
 */
class MainMenuState : public Engine::GameState {
    
private:
    Menu *menu;
    bool started;
    bool loadedResources;
    
    bool startNewGame;
    bool quitGame;
    
    void buildModels();
    void loadTextures();
    
public:
    MainMenuState();
    ~MainMenuState();

    virtual void start();
    virtual void stop();
    virtual void handleKeyboardEvents(SDL_Event *event);
    virtual void handleMouseEvents(SDL_Event *event);
    virtual void render(double edt);
    virtual void update(double dt);

};

#endif // __mainmenustate__
