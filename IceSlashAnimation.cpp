#include "IceSlashAnimation.h"
#include "GlobalConstants.h"

#include "Particle.h"
#include "IceParticle.h"
#include "IceBitParticle.h"

#include "Engine.h"

IceSlashAnimation::IceSlashAnimation(const Vector &position) {
    this->worldPosition = position;

    this->lifetime = 0.0;
    this->duration = 250.0;

    this->newParticleCounter = 0.0;
    this->interval = 25.0;
}

IceSlashAnimation::~IceSlashAnimation() {
    std::list<Particle *>::iterator it;

    for (it = particles.begin(); it != particles.end(); it++) {
        Particle *particle = (*it);
        delete particle;
    }
}

std::list<Particle*> IceSlashAnimation::getParticles() {
    std::list<Particle *> emptyList;
    
    if (lifetime > 0.0) {
        return particles;
    }
    
    return emptyList;
}

bool IceSlashAnimation::hasFinished() {
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

bool IceSlashAnimation::isBlocking() {
    return false;
}

void IceSlashAnimation::update(double dt) {
    if (lifetime == 0.0) {
    }

    lifetime += dt;
    if (lifetime < duration) {
        newParticleCounter += dt;
    }

    Vector start = Vector(MONSTER_SIZE / 2.0, MONSTER_SIZE, 1.0);
    Vector end = Vector(-MONSTER_SIZE / 2.0, 0.0, 1.0);

    while (newParticleCounter > interval) {
        Engine::AudioSystem *audioSystem =
            Engine::Core::getInstance()->getAudioSystem();

        audioSystem->playSound("IceSlash", 0);
        
        newParticleCounter -= interval;

        double t = (lifetime - newParticleCounter) / duration;
        Vector position = start.mult(1.0 - t).translate(end.mult(t));

        Particle *particle = new IceParticle(worldPosition, position);
        particles.push_back(particle);
    }

    if (lifetime > duration) {
        lifetime = duration;
        newParticleCounter = 0;
    }

    std::list<Particle *>::iterator it = particles.begin();
    while (it != particles.end()) {
        Particle *particle = (*it);

        particle->update(dt);
        if (!particle->isAlive()) {
            if (particle->getTexture() == 4) {
                Engine::AudioSystem *audioSystem =
                    Engine::Core::getInstance()->getAudioSystem();

                audioSystem->playSound("IceBreak", 0);

                for (int i = 0; i < 6; i++) {
                    Vector position = particle->getPosition(0.0);
                    Particle *bitParticle = new IceBitParticle(worldPosition, position);
                    particles.push_back(bitParticle);
                }
            }
            it = particles.erase(it);
        } else {
            it++;
        }
    }
}
