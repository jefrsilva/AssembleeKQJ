#ifndef __statemanager__
#define __statemanager__

#include <vector>

namespace Engine {

    class GameState;
    
    /**
     * \class StateManager
     * \author Jeferson Rodrigues da Silva
     * \date 11/27/2009
     * \file StateManager.h
     * \brief
     */
    class StateManager {
        
    private:
        GameState *currentState;
        std::vector<GameState *> states;

    public:
        StateManager();
        ~StateManager();
        
        /*!
         * \brief Sets the current game state.
         * \param stateNumber The state number
         */
        void setCurrentState(int stateNumber);
        
        /*!
         * \brief Adds a new state to the state manager.
         * \param state The state to be added.
         */
        void pushState(GameState *state);
        
        /*!
         * \brief Gets the current game state.
         * \return Pointer to the state
         */
        GameState *getCurrentState();

    };

}

#endif // __statemanager__
