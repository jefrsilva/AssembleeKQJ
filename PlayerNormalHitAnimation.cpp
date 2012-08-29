#include "PlayerNormalHitAnimation.h"
#include "GlobalConstants.h"

#include "Particle.h"
#include "SparkParticle.h"
#include "Player.h"

#include "Engine.h"

PlayerNormalHitAnimation::PlayerNormalHitAnimation(Player *player) {
    this->worldPosition = player->getWorldPosition(0.0);
    this->player = player;
    this->lifetime = 0.0;
    this->duration = 250.0;

    this->newParticleCounter = 0.0;
    this->interval = 50.0;
}

PlayerNormalHitAnimation::~PlayerNormalHitAnimation() {
    std::list<Particle *>::iterator it;

    for (it = particles.begin(); it != particles.end(); it++) {
        Particle *particle = (*it);
        delete particle;
    }
}

std::list<Particle*> PlayerNormalHitAnimation::getParticles() {
    return particles;
}

bool PlayerNormalHitAnimation::hasFinished() {
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

bool PlayerNormalHitAnimation::isBlocking() {
    return false;
}

void PlayerNormalHitAnimation::update(double dt) {
    if (lifetime == 0.0) {
        player->shake(350.0);
        
        Engine::AudioSystem *audioSystem =
            Engine::Core::getInstance()->getAudioSystem();

        audioSystem->playSound("NormalHit", 0);
        
    }
    
    worldPosition = player->getWorldPosition(0.0);

    lifetime += dt;
    newParticleCounter += dt;

    Vector start = Vector(0.0, MONSTER_SIZE, 1.0);
    Vector end = Vector(0.0, 0.0, 1.0);

    while (newParticleCounter >= interval) {
        newParticleCounter -= interval;

        Engine::RandomNumberGenerator *rng =
            Engine::Core::getInstance()->getRandomNumberGenerator();

        Vector position =
            Vector(rng->randomReal(-0.75 * HALF_TILE,
                                   0.75 * HALF_TILE),
                   rng->randomReal(0.1 * TILE_SIZE, 0.9 * TILE_SIZE),
                   0.0);

        for (int i = 0; i < 5; i++) {
            Particle *particle =
                new SparkParticle(worldPosition, position);
            particles.push_back(particle);
        }
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
