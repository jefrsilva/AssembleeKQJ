#include "AudioSystem.h"
#include "Engine.h"

#include <iostream>

using namespace Engine;

AudioSystem::AudioSystem() {
    std::cout << "Audio system constructor." << std::endl;
    
    currentMusic = "";
}

AudioSystem::~AudioSystem() {
    std::map<std::string, Mix_Chunk *>::iterator itS;

    for (itS = sounds.begin(); itS != sounds.end(); itS++) {
        std::pair<std::string, Mix_Chunk *> soundPair = (*itS);

        Mix_FreeChunk(soundPair.second);
    }

    std::map<std::string, Mix_Music *>::iterator itM;

    for (itM = musics.begin(); itM != musics.end(); itM++) {
        std::pair<std::string, Mix_Music *> musicPair = (*itM);

        Mix_FreeMusic(musicPair.second);
    }

    std::cout << "Audio system destructor." << std::endl;
}

int AudioSystem::init() {
    int err = 0;

    if (Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 1024) != 0) {
        std::cout << "Error initializing SDL_mixer: " << Mix_GetError()
        << std::endl;
        err = -1;
    }

    return err;
}

void AudioSystem::shutdown() {
    Mix_CloseAudio();
}

void AudioSystem::update() {

}

int AudioSystem::loadMusic(std::string filename, std::string musicID) {
    int err = 0;
    Mix_Music *music = Mix_LoadMUS(filename.c_str());

    if (!music) {
        std::cout << "Error on loading music: " << Mix_GetError() << std::endl;
        err = -1;
    } else {
        musics[musicID] = music;
    }

    return err;
}

void AudioSystem::setGlobalMusicVolume(int volume) {
    Mix_VolumeMusic(volume);
}

void AudioSystem::playMusic(std::string musicID, int loops) {
    currentMusic = musicID;
    Mix_PlayMusic(musics[musicID], loops);
}

void AudioSystem::fadeInMusic(std::string musicID, int loops, int duration) {
    currentMusic = musicID;    
    Mix_FadeInMusic(musics[musicID], loops, duration);
}

void AudioSystem::fadeOutMusic(int duration) {
    currentMusic = "";    
    Mix_FadeOutMusic(duration);
}

void AudioSystem::stopMusic() {
    currentMusic = "";    
    Mix_HaltMusic();
}

std::string AudioSystem::getCurrentMusicID() {
    return currentMusic;
}

int AudioSystem::loadSound(std::string filename, std::string soundID) {
    int err = 0;
    Mix_Chunk *sound = Mix_LoadWAV(filename.c_str());

    if (!sound) {
        std::cout << "Error on loading sound: " << Mix_GetError() << std::endl;
        err = -1;
    } else {
        sounds[soundID] = sound;
    }

    return err;
}

void AudioSystem::setGlobalSoundVolume(int volume) {
    Mix_Volume(-1, volume);
}

void AudioSystem::setSoundVolume(std::string soundID, int volume) {
    Mix_VolumeChunk(sounds[soundID], volume);
}

void AudioSystem::playSound(std::string soundID, int loops) {
    Mix_PlayChannel(-1, sounds[soundID], loops);
}
