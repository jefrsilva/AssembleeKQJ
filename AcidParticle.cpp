#include "AcidParticle.h"
#include "GlobalConstants.h"

#include "Engine.h"

AcidParticle::AcidParticle(const Vector &worldPosition,
                           const Vector &position) {
    Engine::RandomNumberGenerator *rng =
        Engine::Core::getInstance()->getRandomNumberGenerator();

    this->worldPosition = worldPosition;
    this->pos = position;
    pos.x += cos(rng->randomReal() * (2.0 * M_PI)) * TILE_SIZE / 16.0;
    pos.y += sin(rng->randomReal() * (2.0 * M_PI)) * TILE_SIZE / 16.0;
    pos.z += rng->randomReal(-0.005, 0.005);

    this->vel = Vector(0.0, 0.0, 0.0);
    this->acc = Vector(0.0, -0.0035 / 1000.0, 0.0);
    this->size = rng->randomReal(1.25, 1.5);
    this->texture = 6;
    this->rotation = rng->randomReal(0.0, 360.0);
    this->lifetime = 0.0;
    this->duration = 1000.0;
}

AcidParticle::~AcidParticle() {

}

double AcidParticle::getOpacity() {
    double alpha = 1.0 - (lifetime / duration);

    return alpha;
}

Vector AcidParticle::getWorldPosition() {
    return worldPosition;
}

Vector AcidParticle::getPosition(double edt) {
    Vector eVel = vel.translate(acc.mult(edt));
    Vector ePos = pos.translate(vel.mult(edt));

    return ePos;
}

double AcidParticle::getSize() {
    double currentSize = size * (1.0 + 0.5 * (lifetime / duration));

    return currentSize;
}

double AcidParticle::getRotation() {
    return rotation;
}

int AcidParticle::getTexture() {
    return texture;
}

bool AcidParticle::isAlive() {
    bool alive = (lifetime < duration);

    return alive;
}

void AcidParticle::update(double dt) {
    if (isAlive()) {
        vel = vel.translate(acc.mult(dt));
        pos = pos.translate(vel.mult(dt));
        
        lifetime += dt;
        if (lifetime > duration) {
            lifetime = duration;
        }
    }
}

void AcidParticle::setBlendMode() {
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
}
