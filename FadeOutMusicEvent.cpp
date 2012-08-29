#include "FadeOutMusicEvent.h"
#include "Engine.h"

FadeOutMusicEvent::FadeOutMusicEvent(int duration) {
    this->duration = duration;
    this->executed = false;
}

FadeOutMusicEvent::~FadeOutMusicEvent() {
    
}

bool FadeOutMusicEvent::hasFinished() {
    return executed;
}

bool FadeOutMusicEvent::isBlocking() {
    return false;
}

void FadeOutMusicEvent::run() {
    Engine::AudioSystem *audioSystem =
        Engine::Core::getInstance()->getAudioSystem();
        
    audioSystem->fadeOutMusic(duration);
    
    executed = true;
}

void FadeOutMusicEvent::update(double dt) {
    
}

bool FadeOutMusicEvent::wasExecuted() {
    return executed;
}
