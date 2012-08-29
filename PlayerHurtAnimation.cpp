#include "PlayerHurtAnimation.h"
#include "GlobalConstants.h"

#include "Particle.h"
#include "PlayerHurtParticle.h"

#include "Engine.h"

PlayerHurtAnimation::PlayerHurtAnimation(const Vector &position) {
    this->worldPosition = position;
    
    this->lifetime = 0.0;
    this->duration = 250.0;
    
    this->newParticleCounter = 0.0;
    this->interval = 25.0;
}

PlayerHurtAnimation::~PlayerHurtAnimation() {
    std::list<Particle *>::iterator it;
    
    for (it = particles.begin(); it != particles.end(); it++) {
        Particle *particle = (*it);
        delete particle;
    }
}

std::list<Particle*> PlayerHurtAnimation::getParticles() {
    std::list<Particle *> emptyList;
    
    if (lifetime > 0.0) {
        return particles;
    }
    
    return emptyList;
}

bool PlayerHurtAnimation::hasFinished() {
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

bool PlayerHurtAnimation::isBlocking() {
    return false;
}

void PlayerHurtAnimation::update(double dt) {
    lifetime += dt;
    if (lifetime < duration) {
        newParticleCounter += dt;
    }
    
    while (newParticleCounter > interval) {
        newParticleCounter -= interval;
        
        Particle *particle = new PlayerHurtParticle(worldPosition);
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

