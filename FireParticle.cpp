#include "FireParticle.h"
#include "GlobalConstants.h"

#include "Engine.h"

FireParticle::FireParticle(const Vector &worldPosition,
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
    this->size = rng->randomReal(1.5, 2.5);
    this->texture = 0;
    this->rotation = rng->randomReal(0.0, 360.0);
    this->lifetime = 0.0;
    this->duration = 1000.0;
}

FireParticle::~FireParticle() {

}

double FireParticle::getOpacity() {
    double alpha = 1.0 - (lifetime / duration);

    return alpha;
}

Vector FireParticle::getWorldPosition() {
    return worldPosition;
}

Vector FireParticle::getPosition(double edt) {
    Vector eVel = vel.translate(acc.mult(edt));
    Vector ePos = pos.translate(vel.mult(edt));

    return ePos;
}

double FireParticle::getSize() {
    double currentSize = (1.0 - (lifetime / duration)) * size;

    return currentSize;
}

double FireParticle::getRotation() {
    return rotation;
}

int FireParticle::getTexture() {
    return texture;
}

bool FireParticle::isAlive() {
    bool alive = (lifetime < duration);

    return alive;
}

void FireParticle::update(double dt) {
    if (isAlive()) {
        vel = vel.translate(acc.mult(dt));
        pos = pos.translate(vel.mult(dt));
        rotation += (360.0 / 1000.0) * dt;

        lifetime += dt;
        if (lifetime > duration) {
            lifetime = duration;
        }
    }
}

void FireParticle::setBlendMode() {
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);    
}
