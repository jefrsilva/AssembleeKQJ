#include "IceBitParticle.h"
#include "GlobalConstants.h"

#include "Engine.h"

IceBitParticle::IceBitParticle(const Vector &worldPosition,
                               const Vector &position) {
    Engine::RandomNumberGenerator *rng =
        Engine::Core::getInstance()->getRandomNumberGenerator();

    this->worldPosition = worldPosition;
    this->pos = position;
    pos.x += cos(rng->randomReal() * (2.0 * M_PI)) * TILE_SIZE / 16.0;
    pos.y += sin(rng->randomReal() * (2.0 * M_PI)) * TILE_SIZE / 16.0;
    pos.z += rng->randomReal(-0.005, 0.005);    

    double maxSpeed = rng->randomReal(3.0 / 1000.0, 6.0 / 1000.0);
    double direction = rng->randomReal(0.0, 2.0 * M_PI);
    this->vel = Vector(std::cos(direction) * maxSpeed,
                       std::sin(direction) * maxSpeed, 0.0);
                       
    this->acc = Vector(0.0, 0.0, 0.0);
    
    this->size = rng->randomReal(0.75, 1.25);
    this->texture = 5;
    this->rotation = rng->randomReal(-180.0, 180.0);
    this->lifetime = 0.0;
    this->duration = 500.0;
}

IceBitParticle::~IceBitParticle() {

}

double IceBitParticle::getOpacity() {
    double alpha = 1.0 - (lifetime / duration);

    return alpha;
}

Vector IceBitParticle::getWorldPosition() {
    return worldPosition;
}

Vector IceBitParticle::getPosition(double edt) {
    Vector eVel = vel.translate(acc.mult(edt));
    Vector ePos = pos.translate(vel.mult(edt));

    return ePos;
}

double IceBitParticle::getSize() {
    double currentSize = (1.0 - (lifetime / duration)) * size;

    return currentSize;
}

double IceBitParticle::getRotation() {
    return rotation;
}

int IceBitParticle::getTexture() {
    return texture;
}

bool IceBitParticle::isAlive() {
    bool alive = (lifetime < duration);

    return alive;
}

void IceBitParticle::update(double dt) {
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

void IceBitParticle::setBlendMode() {
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
}
