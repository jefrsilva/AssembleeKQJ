#include "FireSlashAnimation.h"
#include "GlobalConstants.h"

#include "Particle.h"
#include "FireParticle.h"

#include "Engine.h"

FireSlashAnimation::FireSlashAnimation(const Vector &position) {
    this->worldPosition = position;
    
    this->lifetime = 0.0;
    this->duration = 250.0;
    
    this->newParticleCounter = 0.0;
    this->interval = 25.0;
}

FireSlashAnimation::~FireSlashAnimation() {
    std::list<Particle *>::iterator it;
    
    for (it = particles.begin(); it != particles.end(); it++) {
        Particle *particle = (*it);
        delete particle;
    }
}

std::list<Particle*> FireSlashAnimation::getParticles() {
    std::list<Particle *> emptyList;
    
    if (lifetime > 0.0) {
        return particles;
    }
    
    return emptyList;
}

bool FireSlashAnimation::hasFinished() {
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

bool FireSlashAnimation::isBlocking() {
    return false;
}

void FireSlashAnimation::update(double dt) {
    if (lifetime == 0.0) {
        Engine::AudioSystem *audioSystem = 
            Engine::Core::getInstance()->getAudioSystem();
            
        audioSystem->playSound("FireSlash", 0);
    }
    
    lifetime += dt;
    if (lifetime < duration) {
        newParticleCounter += dt;
    }
    
    Vector start = Vector(MONSTER_SIZE / 2.0, MONSTER_SIZE, 1.0);
    Vector end = Vector(-MONSTER_SIZE / 2.0, 0.0, 1.0); 
    
    while (newParticleCounter > interval) {
        newParticleCounter -= interval;
        
        double t = (lifetime - newParticleCounter) / duration;
        Vector position = start.mult(1.0 - t).translate(end.mult(t));
        
        Particle *particle = new FireParticle(worldPosition, position);
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
