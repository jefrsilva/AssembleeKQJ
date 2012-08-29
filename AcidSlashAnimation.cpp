#include "AcidSlashAnimation.h"
#include "GlobalConstants.h"

#include "Particle.h"
#include "AcidParticle.h"
#include "SmokeParticle.h"

#include "Engine.h"

AcidSlashAnimation::AcidSlashAnimation(const Vector &position) {
    this->worldPosition = position;

    this->lifetime = 0.0;
    this->duration = 250.0;

    this->newParticleCounter = 0.0;
    this->interval = 25.0;

    this->newSmokeCounter = 200.0;
    this->smokeInterval = 200.0;
}

AcidSlashAnimation::~AcidSlashAnimation() {
    std::list<Particle *>::iterator it;

    for (it = particles.begin(); it != particles.end(); it++) {
        Particle *particle = (*it);
        delete particle;
    }
}

std::list<Particle*> AcidSlashAnimation::getParticles() {
    std::list<Particle *> emptyList;
    
    if (lifetime > 0.0) {
        return particles;
    }
    
    return emptyList;
}

bool AcidSlashAnimation::hasFinished() {
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

bool AcidSlashAnimation::isBlocking() {
    return false;
}

void AcidSlashAnimation::update(double dt) {
    if (lifetime == 0.0) {
        Engine::AudioSystem *audioSystem =
            Engine::Core::getInstance()->getAudioSystem();

        audioSystem->playSound("Acid", 0);
    }

    lifetime += dt;
    if (lifetime < duration) {
        newParticleCounter += dt;
    }
    newSmokeCounter += dt;

    Vector start = Vector(MONSTER_SIZE / 2.0, MONSTER_SIZE, 1.0);
    Vector end = Vector(-MONSTER_SIZE / 2.0, 0.0, 1.0);

    while (newParticleCounter > interval) {
        newParticleCounter -= interval;

        double t = (lifetime - newParticleCounter) / duration;
        Vector position = start.mult(1.0 - t).translate(end.mult(t));

        Particle *particle = new AcidParticle(worldPosition, position);
        particles.push_back(particle);
    }

    if (lifetime > duration) {
        lifetime = duration;
        newParticleCounter = 0.0;
    }

    std::list<Particle *>::iterator it = particles.begin();
    while (it != particles.end()) {
        Particle *particle = (*it);

        particle->update(dt);
        if (particle->isAlive()) {
            if (particle->getTexture() == 6) {
                if (newSmokeCounter > smokeInterval) {
                    for (int i = 0; i < 1; i++) {
                        Vector position = particle->getPosition(0.0);
                        Particle *smokeParticle = new SmokeParticle(worldPosition, position);
                        particles.push_back(smokeParticle);
                    }
                }
            }
        }
        it++;
    }

    if (newSmokeCounter > smokeInterval) {
        newSmokeCounter -= smokeInterval;
    }
}
