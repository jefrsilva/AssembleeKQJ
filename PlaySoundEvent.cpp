#include "PlaySoundEvent.h"
#include "Engine.h"

PlaySoundEvent::PlaySoundEvent(std::string soundID) {
    this->soundID = soundID;
    this->executed = false;
}

PlaySoundEvent::~PlaySoundEvent() {
    
}

bool PlaySoundEvent::hasFinished() {
    return executed;
}

bool PlaySoundEvent::isBlocking() {
    return false;
}

void PlaySoundEvent::run() {
    Engine::AudioSystem *audioSystem =
        Engine::Core::getInstance()->getAudioSystem();

    audioSystem->playSound(soundID, 0);
    
    executed = true;

}

void PlaySoundEvent::update(double dt) {
    
}

bool PlaySoundEvent::wasExecuted() {
    return executed;
}
