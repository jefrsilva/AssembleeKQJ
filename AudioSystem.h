#ifndef __audiosystem__
#define __audiosystem__

#include <SDL/SDL_mixer.h>

#include <map>
#include <string>

namespace Engine {

    /**
     * \class AudioSystem
     * \author Jeferson Rodrigues da Silva
     * \date 11/27/2009
     * \file AudioSystem.h
     * \brief 
     */
    class AudioSystem {

    private:
        std::map<std::string, Mix_Music *> musics;
        std::map<std::string, Mix_Chunk *> sounds;
        
        std::string currentMusic;

    public:
        AudioSystem();
        ~AudioSystem();

        /*!
         * \brief Initialises the audio system.
         * \return 0 on success, -1 otherwise
         */
        int init();
        
        /*!
         * \brief Shutdown the audio system.
         */
        void shutdown();
        
        /*!
         * \brief Updates the audio system.
         */
        void update();

        /*! 
         * \brief Loads a music file and associates it with a music ID.
         * \param filename Path to the music file
         * \parem musicID The music ID
         * \return 0 on success, -1 otherwise
         */
        int loadMusic(std::string filename, std::string musicID);
        
        /*!
         * \brief Sets the global music volume.
         * \param volume The volume (0-128)
         */
        void setGlobalMusicVolume(int volume);
        
        /*!
         * \brief Plays the specified music.
         * \param musicID The music ID
         * \param loops The number of times to play (-1 infinite)
         */
        void playMusic(std::string musicID, int loops);
        
        /*! \brief Plays the specified music with a fade in.
         *  \param musicID The music ID
         *  \param loops The number of times to play (-1 infinite)
         *  \param duration The fade in duration in ms
         */
        void fadeInMusic(std::string musicID, int loops, int duration);
        
        /*! \brief Stops the current playing music with a fade out.
         *  \param duration The fade out duration in ms
         */
        void fadeOutMusic(int duration);
        
        /*!
         * \brief Stops the current playing music.
         */
        void stopMusic();
        
        /*!
         * \brief Gets the current playing music ID.
         * \return The current music ID
         */
        std::string getCurrentMusicID();
        
        /*!
         * \brief Loads a sound file and associates it with a sound ID.
         * \param filename Path to the sound file
         * \param soundID The sound ID
         * \return 0 on success, -1 otherwise
         */
        int loadSound(std::string filename, std::string soundID);
        
        /*!
         * \brief Sets the global sound volume.
         * \param volume The volume (0-128)
         */
        void setGlobalSoundVolume(int volume);

        /*!
         * \brief Sets the volume of the specified sound.
         * \param soundID The sound ID
         * \param volume The volume (0-128)
         */
        void setSoundVolume(std::string soundID, int volume);
        
        /*!
         * \brief Plays the specified sound.
         * \param soundID The sound ID
         * \param loops The number of loops (-1 infinite)
         */
        void playSound(std::string soundID, int loops);
    };

}

#endif // __audiosystem__
