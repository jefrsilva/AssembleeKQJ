#ifndef __gameoverstate__
#define __gameoverstate__

#include "Engine.h"
#include "GlobalConstants.h"

class GameOverScreen;

/**
 * \class GameOverState
 * \author Jeferson Rodrigues da Silva
 * \date 01/09/2010
 * \file GameOverState.h
 * \brief
 */
class GameOverState : public Engine::GameState {

private:
    GameOverScreen *gameover;
    bool started;
    
    bool returnToMenu;
    
public:
    GameOverState();
    ~GameOverState();

    virtual void start();
    virtual void stop();
    virtual void handleKeyboardEvents(SDL_Event *event);
    virtual void handleMouseEvents(SDL_Event *event);
    virtual void render(double edt);
    virtual void update(double dt);

};

#endif // __gameoverstate__
