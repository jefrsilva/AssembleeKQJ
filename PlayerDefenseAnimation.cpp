#include "PlayerDefenseAnimation.h"
#include "GlobalConstants.h"

#include "Particle.h"
#include "PlayerDefenseParticle.h"

#include "Engine.h"

PlayerDefenseAnimation::PlayerDefenseAnimation(const Vector &position,
        unsigned char defenseType) {
    this->worldPosition = position;

    this->lifetime = 0.0;
    this->duration = 250.0;

    this->newParticleCounter = 0.0;
    this->interval = 10.0;

    this->defenseType = defenseType;
}

PlayerDefenseAnimation::~PlayerDefenseAnimation() {
    std::list<Particle *>::iterator it;

    for (it = particles.begin(); it != particles.end(); it++) {
        Particle *particle = (*it);
        delete particle;
    }
}

std::list<Particle*> PlayerDefenseAnimation::getParticles() {
    std::list<Particle *> emptyList;

    if (lifetime > 0.0) {
        return particles;
    }

    return emptyList;
}

bool PlayerDefenseAnimation::hasFinished() {
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

bool PlayerDefenseAnimation::isBlocking() {
    return false;
}

void PlayerDefenseAnimation::update(double dt) {
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

        Vector color = Vector();
        if (defenseType == 'W') {
            color.x = 1.0;
            color.y = 1.0;
            color.z = 1.0;
        } else if (defenseType == 'R') {
            color.x = 1.0;
            color.y = 0.0;
            color.z = 0.0;
        } else if (defenseType == 'G') {
            color.x = 0.0;
            color.y = 1.0;
            color.z = 0.0;
        } else if (defenseType == 'B') {
            color.x = 0.0;
            color.y = 0.0;
            color.z = 1.0;
        } else if (defenseType == 'Y') {
            color.x = 1.0;
            color.y = 1.0;
            color.z = 0.0;
        }

        Particle *particle =
            new PlayerDefenseParticle(color.x,
                                      color.y,
                                      color.z,
                                      worldPosition);
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
