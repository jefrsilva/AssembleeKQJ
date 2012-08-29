#include "FadeInMusicEvent.h"
#include "Engine.h"

#include <iostream>

FadeInMusicEvent::FadeInMusicEvent(std::string musicID, int duration) {
    this->musicID = musicID;
    this->duration = duration;
    this->executed = false;
}

FadeInMusicEvent::~FadeInMusicEvent() {

}

bool FadeInMusicEvent::hasFinished() {
    return executed;
}

bool FadeInMusicEvent::isBlocking() {
    return false;
}

void FadeInMusicEvent::run() {
    Engine::AudioSystem *audioSystem =
        Engine::Core::getInstance()->getAudioSystem();
        
    audioSystem->fadeInMusic(musicID, -1, duration);
    
    executed = true;
}

void FadeInMusicEvent::update(double dt) {

}

bool FadeInMusicEvent::wasExecuted() {
    return executed;
}
