#include "PlayMusicEvent.h"
#include "Engine.h"

PlayMusicEvent::PlayMusicEvent(std::string musicID) {
    this->musicID = musicID;
    this->executed = false;
}

PlayMusicEvent::~PlayMusicEvent() {
    
}

bool PlayMusicEvent::hasFinished() {
    return executed;
}

bool PlayMusicEvent::isBlocking() {
    return false;
}

void PlayMusicEvent::run() {
    Engine::AudioSystem *audioSystem =
        Engine::Core::getInstance()->getAudioSystem();

    audioSystem->playMusic(musicID, -1);
    
    executed = true;
}

void PlayMusicEvent::update(double dt) {
    
}

bool PlayMusicEvent::wasExecuted() {
    return executed;
}
