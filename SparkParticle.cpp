#include "SparkParticle.h"
#include "GlobalConstants.h"

#include "Engine.h"

SparkParticle::SparkParticle(const Vector &worldPosition,
                             const Vector &position) {
    Engine::RandomNumberGenerator *rng =
        Engine::Core::getInstance()->getRandomNumberGenerator();

    this->worldPosition = worldPosition;
    this->pos = position;
    //pos.x += cos(rng->randomReal() * (2.0 * M_PI)) * TILE_SIZE / 16.0;
    //pos.y += sin(rng->randomReal() * (2.0 * M_PI)) * TILE_SIZE / 16.0;
    pos.z += rng->randomReal(-0.005, 0.005);    

    this->vel = Vector();
    vel.x = rng->randomReal(-2.0 / 1000.0, 2.0 / 1000.0);
    vel.y = rng->randomReal(0.0, 6.0 / 1000.0);
    
    this->acc = Vector(0.0, -0.01 / 1000.0, 0.0);
    this->size = 2.0;
    this->texture = 2;
    this->rotation = rng->randomReal(-180.0, 180.0);
    this->lifetime = 0.0;
    this->duration = 750.0;
}

SparkParticle::~SparkParticle() {

}

double SparkParticle::getOpacity() {
    double alpha = 1.0 - (lifetime / duration);

    return alpha;
}

Vector SparkParticle::getWorldPosition() {
    return worldPosition;
}

Vector SparkParticle::getPosition(double edt) {
    Vector eVel = vel.translate(acc.mult(edt));
    Vector ePos = pos.translate(vel.mult(edt));

    return ePos;
}

double SparkParticle::getSize() {
    double currentSize = (1.0 - (lifetime / duration)) * size;

    return currentSize;
}

double SparkParticle::getRotation() {
    return rotation;
}

int SparkParticle::getTexture() {
    return texture;
}

bool SparkParticle::isAlive() {
    bool alive = (lifetime < duration);

    return alive;
}

void SparkParticle::update(double dt) {
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

void SparkParticle::setBlendMode() {
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
}
