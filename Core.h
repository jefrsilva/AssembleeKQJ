#ifndef __core__
#define __core__

namespace Engine {

    class VideoSystem;
    class AudioSystem;
    class ScriptingSystem;
    class StateManager;
    class RandomNumberGenerator;

    /**
     * \class Core
     * \author Jeferson Rodrigues da Silva
     * \date 11/26/2009
     * \file Core.h
     * \brief
     */
    class Core {

    private:
        Core();
        ~Core();

        VideoSystem *videoSystem;
        AudioSystem *audioSystem;
        ScriptingSystem *scriptingSystem;
        StateManager *stateManager;
        RandomNumberGenerator *randomNumberGenerator;

    protected:
        static Core *instance;

    public:
        /*!
         * \brief Gets a pointer to the engine core instance.
         * \return Pointer to engine core.
         */
        static Core *getInstance();

        /*!
         * \brief Destroys the engine core.
         */
        static void destroy();

        /*!
         * \brief Initialises the engine core.
         * \return 0 on success, -1 otherwise
         */
        int init();

        /*!
         * \brief Shutdown the engine core.
         */
        void shutdown();

        /*!
         * \brief Gets a pointer to the engine video system.
         * \return Pointer to video system.
         */
        VideoSystem *getVideoSystem();

        /*!
         * \brief Gets a pointer to the engine audio system.
         * \return Pointer to audio system.
         */
        AudioSystem *getAudioSystem();
        
        /*!
         * \brief Gets a pointer to the engine scripting system.
         * \return Pointer to the scripting system.
         */
        ScriptingSystem *getScriptingSystem();

        /*!
         * \brief Gets a pointer to the engine state manager.
         * \return Pointer to the state manager.
         */
        StateManager *getStateManager();
        
        /*!
         * \brief Gets a pointer to the random number generator.
         * \return Pointer to the random number generator.
         */
        RandomNumberGenerator *getRandomNumberGenerator();
    };

}

#endif // __core__
