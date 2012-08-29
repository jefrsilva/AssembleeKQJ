#ifndef __gameframework__
#define __gameframework__

#include <vector>

namespace Engine {

    class GameState;
    
    /**
     * \class GameFramework
     * \author Jeferson Rodrigues da Silva
     * \date 11/27/2009
     * \file GameFramework.h
     * \brief A simple framework for a game application.
     */
    class GameFramework {

    private:
        std::vector<GameState *> states;
    
        bool paused;
        double logicFrameDuration;
        unsigned int windowWidth;
        unsigned int windowHeight;
        unsigned int windowDepth;
        bool fullscreen;

    public:
        GameFramework();
        ~GameFramework();

        /*!
         * \brief Sets the desired video mode for the game application.
         * \param width The window width
         * \param height The window height
         * \param depth The window color depth
         * \param fullscreen Should open in fullscreen mode
         */
        void setVideoMode(unsigned int width, unsigned int height,
                          unsigned int depth, bool fullscreen);
                          
        /*!
         * \brief Sets the logic frame duration.
         * \param duration The logic frame duration in milliseconds.
         */
        void setLogicFrameDuration(double duration);
        
        /*!
         * \brief Runs the game framework.
         * \param stateNumber The initial state number.
         * \return 0 on success, -1 otherwise
         */
        int run(int stateNumber);
        
        /*!
         * \brief Adds a new state to the game framework.
         * \param state The state to be added.
         */
        void addState(GameState *state);

    };

}

#endif // __gameframework__
