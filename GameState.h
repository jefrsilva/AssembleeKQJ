#ifndef __gamestate__
#define __gamestate__

#include <SDL/SDL.h>

namespace Engine {

    /**
     * \class GameState
     * \author Jeferson Rodrigues da Silva
     * \date 11/27/2009
     * \file GameState.h
     * \brief
     */
    class GameState {
        
    public:
        virtual ~GameState() {};
        
        virtual void start() = 0;
        virtual void stop() = 0;

        virtual void handleMouseEvents(SDL_Event *event) = 0;
        virtual void handleKeyboardEvents(SDL_Event *event) = 0;

        virtual void update(double dt) = 0;
        virtual void render(double edt) = 0;

    };

}

#endif // __gamestate__
