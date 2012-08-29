#ifndef __dungeoncrawlingstate__
#define __dungeoncrawlingstate__

#include "Engine.h"

#include "GlobalConstants.h"

class GameController;

/**
 * \class DungeonCrawlingState
 * \author Jeferson Rodrigues da Silva
 * \date 12/06/2009
 * \file DungeonCrawlingState.h
 * \brief State representing the main game portion: the dungeon crawling.
 */
class DungeonCrawlingState : public Engine::GameState {
    
private:
    bool started;
    GameController *game;

public:
    DungeonCrawlingState();
    ~DungeonCrawlingState();

    virtual void start();
    virtual void stop();
    virtual void handleKeyboardEvents(SDL_Event *event);
    virtual void handleMouseEvents(SDL_Event *event);
    virtual void render(double edt);
    virtual void update(double dt);

};

#endif // __dungeoncrawlingstate__
