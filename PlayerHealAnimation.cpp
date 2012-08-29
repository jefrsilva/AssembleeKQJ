#include "PlayerHealAnimation.h"
#include "GlobalConstants.h"

#include "Particle.h"
#include "PlayerHealParticle.h"

#include "Engine.h"

PlayerHealAnimation::PlayerHealAnimation(const Vector &position) {
    this->worldPosition = position;
    
    this->lifetime = 0.0;
    this->duration = 250.0;
    
    this->newParticleCounter = 0.0;
    this->interval = 25.0;
}

PlayerHealAnimation::~PlayerHealAnimation() {
    std::list<Particle *>::iterator it;
    
    for (it = particles.begin(); it != particles.end(); it++) {
        Particle *particle = (*it);
        delete particle;
    }
}

std::list<Particle*> PlayerHealAnimation::getParticles() {
    std::list<Particle *> emptyList;
    
    if (lifetime > 0.0) {
        return particles;
    }
    
    return emptyList;
}

bool PlayerHealAnimation::hasFinished() {
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

bool PlayerHealAnimation::isBlocking() {
    return false;
}

void PlayerHealAnimation::update(double dt) {
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
        
        Particle *particle = new PlayerHealParticle(worldPosition);
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

