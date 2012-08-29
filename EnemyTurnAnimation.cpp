#include "EnemyTurnAnimation.h"
#include "GlobalConstants.h"

#include "Particle.h"
#include "EnemyTurnParticle.h"

#include "Engine.h"

EnemyTurnAnimation::EnemyTurnAnimation(const Vector &position) {
    this->worldPosition = position;
    
    this->lifetime = 0.0;
    this->duration = 100.0;
    
    this->newParticleCounter = 0.0;
    this->interval = 3.5;
}

EnemyTurnAnimation::~EnemyTurnAnimation() {
    std::list<Particle *>::iterator it;
    
    for (it = particles.begin(); it != particles.end(); it++) {
        Particle *particle = (*it);
        delete particle;
    }
}

std::list<Particle*> EnemyTurnAnimation::getParticles() {
    std::list<Particle *> emptyList;
    
    if (lifetime > 0.0) {
        return particles;
    }
    
    return emptyList;
}

bool EnemyTurnAnimation::hasFinished() {
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

bool EnemyTurnAnimation::isBlocking() {
    return false;
}

void EnemyTurnAnimation::update(double dt) {
    if (lifetime == 0.0) {
        Engine::AudioSystem *audioSystem = 
            Engine::Core::getInstance()->getAudioSystem();
            
        audioSystem->playSound("EnemyTurn", 0);
    }
    
    lifetime += dt;
    if (lifetime < duration) {
        newParticleCounter += dt;
    }
    
    while (newParticleCounter > interval) {
        newParticleCounter -= interval;
        
        Particle *particle = new EnemyTurnParticle(worldPosition);
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

