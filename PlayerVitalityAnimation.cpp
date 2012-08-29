#include "PlayerVitalityAnimation.h"
#include "GlobalConstants.h"

#include "Particle.h"
#include "PlayerVitalityParticle.h"

#include "Engine.h"

PlayerVitalityAnimation::PlayerVitalityAnimation(const Vector &position) {
    this->worldPosition = position;
    
    this->lifetime = 0.0;
    this->duration = 250.0;
    
    this->newParticleCounter = 0.0;
    this->interval = 25.0;
}

PlayerVitalityAnimation::~PlayerVitalityAnimation() {
    std::list<Particle *>::iterator it;
    
    for (it = particles.begin(); it != particles.end(); it++) {
        Particle *particle = (*it);
        delete particle;
    }
}

std::list<Particle*> PlayerVitalityAnimation::getParticles() {
    std::list<Particle *> emptyList;
    
    if (lifetime > 0.0) {
        return particles;
    }
    
    return emptyList;
}

bool PlayerVitalityAnimation::hasFinished() {
    bool finished = true;
    
    std::list<Particle *>::iterator it;    
    for (it = particles.begin(); it != particles.end() && finished; it++) {
        Particle *particle  = (*it);
        
        if (particle->isAlive()) {
            finished = false;
        }
    }
    
    return (lifetime >= duration) && finished;
}

bool PlayerVitalityAnimation::isBlocking() {
    return false;
}

void PlayerVitalityAnimation::update(double dt) {
    if (lifetime == 0.0) {
        Engine::AudioSystem *audioSystem = 
            Engine::Core::getInstance()->getAudioSystem();
            
        audioSystem->playSound("PlayerTurn", 0);
    }
    
    lifetime += dt;
    if (lifetime < duration) {
        newParticleCounter += dt;
    }
    
    while (newParticleCounter > interval) {
        newParticleCounter -= interval;
        
        Particle *particle = new PlayerVitalityParticle(worldPosition);
        particles.push_back(particle);
    }
    
    if (lifetime > duration) {
        lifetime = duration;
        newParticleCounter = 0;
    }
   
    std::list<Particle *>::iterator it;
    for (it = particles.begin(); it != particles.end(); it++) {
        Particle *particle = (*it);
        
        particle->update(dt);
    }
}
