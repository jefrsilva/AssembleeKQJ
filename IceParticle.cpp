#include "IceParticle.h"
#include "GlobalConstants.h"

#include "Engine.h"

IceParticle::IceParticle(const Vector &worldPosition,
                         const Vector &position) {
    Engine::RandomNumberGenerator *rng =
        Engine::Core::getInstance()->getRandomNumberGenerator();

    this->worldPosition = worldPosition;
    this->pos = position;
    pos.x += cos(rng->randomReal() * (2.0 * M_PI)) * TILE_SIZE / 16.0;
    pos.y += sin(rng->randomReal() * (2.0 * M_PI)) * TILE_SIZE / 16.0;
    pos.z += rng->randomReal(-0.005, 0.005);    

    this->vel = Vector(0.0, 0.0, 0.0);
    this->acc = Vector(0.0, 0.0, 0.0);
    this->size = rng->randomReal(1.5, 2.5);
    this->texture = 4;
    this->rotation = rng->randomReal(0.0, 360.0);
    this->lifetime = 0.0;
    this->duration = rng->randomReal(750.0, 1000.0);
}

IceParticle::~IceParticle() {

}

double IceParticle::getOpacity() {
    double alpha = 1.0;

    return alpha;
}

Vector IceParticle::getWorldPosition() {
    return worldPosition;
}

Vector IceParticle::getPosition(double edt) {
    Vector eVel = vel.translate(acc.mult(edt));
    Vector ePos = pos.translate(vel.mult(edt));

    return ePos;
}

double IceParticle::getSize() {
    double currentSize = size;

    return currentSize;
}

double IceParticle::getRotation() {
    return rotation;
}

int IceParticle::getTexture() {
    return texture;
}

bool IceParticle::isAlive() {
    bool alive = (lifetime < duration);

    return alive;
}

void IceParticle::update(double dt) {
    if (isAlive()) {
        lifetime += dt;
        if (lifetime > duration) {
            lifetime = duration;
        }
    }
}

void IceParticle::setBlendMode() {
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
}
