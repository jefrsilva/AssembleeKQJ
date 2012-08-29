#include "SmokeParticle.h"
#include "GlobalConstants.h"

#include "Engine.h"

SmokeParticle::SmokeParticle(const Vector &worldPosition,
                             const Vector &position) {
    Engine::RandomNumberGenerator *rng =
        Engine::Core::getInstance()->getRandomNumberGenerator();

    this->worldPosition = worldPosition;
    this->pos = position;
    pos.x += cos(rng->randomReal() * (2.0 * M_PI)) * TILE_SIZE / 16.0;
    pos.y += sin(rng->randomReal() * (2.0 * M_PI)) * TILE_SIZE / 16.0;
    pos.z += rng->randomReal(-0.005, 0.005);

    this->vel = Vector(0.0, 0.0, 0.0);
    this->acc = Vector(0.0, 0.01 / 1000.0, 0.0);
    this->size = rng->randomReal(0.9, 1.1);
    this->texture = 7;
    this->rotation = rng->randomReal(-180.0, 180.0);
    this->lifetime = 0.0;
    this->duration = rng->randomReal(500.0, 750.0);
}

SmokeParticle::~SmokeParticle() {

}

double SmokeParticle::getOpacity() {
    double alpha = 1.0 - (lifetime / duration);

    return alpha;
}

Vector SmokeParticle::getWorldPosition() {
    return worldPosition;
}

Vector SmokeParticle::getPosition(double edt) {
    Vector eVel = vel.translate(acc.mult(edt));
    Vector ePos = pos.translate(vel.mult(edt));

    return ePos;
}

double SmokeParticle::getSize() {
    double currentSize = size;

    return currentSize;
}

double SmokeParticle::getRotation() {
    return rotation;
}

int SmokeParticle::getTexture() {
    return texture;
}

bool SmokeParticle::isAlive() {
    bool alive = (lifetime < duration);

    return alive;
}

void SmokeParticle::update(double dt) {
    if (isAlive()) {
        vel = vel.translate(acc.mult(dt));
        pos = pos.translate(vel.mult(dt));
        
        if (rotation >= 0.0) {
            rotation += (360.0 / 1000.0) * dt;
        } else {
            rotation -= (360.0 / 1000.0) * dt;            
        }

        lifetime += dt;
        if (lifetime > duration) {
            lifetime = duration;
        }
    }
}

void SmokeParticle::setBlendMode() {
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
}
