#include "ShockParticle.h"
#include "GlobalConstants.h"

#include "Engine.h"

ShockParticle::ShockParticle(const Vector &worldPosition,
                             const Vector &position) {
    Engine::RandomNumberGenerator *rng =
        Engine::Core::getInstance()->getRandomNumberGenerator();

    this->worldPosition = worldPosition;
    this->pos = position;
    pos.z += rng->randomReal(-0.005, 0.005);    

    int direction = rng->randomInt(0, 7);
    this->vel =
        Vector(-std::sin(direction * M_PI / 4.0),
               std::cos(direction * M_PI / 4.0),
               0.0);
    this->vel = this->vel.mult(6.0 / 1000.0);

    this->acc = Vector(0.0, 0.0, 0.0);
    this->size = 0.0;
    this->texture = 3;
    this->rotation = 0.0;
    this->lifetime = 0.0;
    this->duration = 1000.0;

    this->turnCounter = 0.0;
    this->turnInterval = 250.0;
}

ShockParticle::~ShockParticle() {

}

double ShockParticle::getOpacity() {
    double alpha = 1.0 - (lifetime / duration);

    return alpha;
}

Vector ShockParticle::getWorldPosition() {
    return worldPosition;
}

Vector ShockParticle::getPosition(double edt) {
    Vector eVel = vel.translate(acc.mult(edt));
    Vector ePos = pos.translate(vel.mult(edt));

    return ePos;
}

double ShockParticle::getSize() {
    double currentSize = std::sin(lifetime * SHAKE_SPEED);
    if (currentSize > 0.0) {
        currentSize = 2.0;
    } else {
        currentSize = 1.0;
    }

    return currentSize;
}

double ShockParticle::getRotation() {
    return rotation;
}

int ShockParticle::getTexture() {
    return texture;
}

bool ShockParticle::isAlive() {
    bool alive = (lifetime < duration);

    return alive;
}

void ShockParticle::update(double dt) {
    if (isAlive()) {
        turnCounter += dt;
        if (turnCounter > turnInterval) {
            turnCounter -= turnInterval;

            Engine::RandomNumberGenerator *rng =
                Engine::Core::getInstance()->getRandomNumberGenerator();

            int direction = rng->randomInt(0, 1);
            if (direction == 0) {
                vel =
                    Vector(std::cos(M_PI / 4.0) * vel.x -
                           std::sin(M_PI / 4.0) * vel.y,
                           std::sin(M_PI / 4.0) * vel.x +
                           std::cos(M_PI / 4.0) * vel.y,
                           vel.z);
            } else if (direction == 1) {
                vel =
                    Vector(std::cos(-M_PI / 4.0) * vel.x -
                           std::sin(-M_PI / 4.0) * vel.y,
                           std::sin(-M_PI / 4.0) * vel.x +
                           std::cos(-M_PI / 4.0) * vel.y,
                           vel.z);
            }
            vel = vel.mult(0.5);
        }

        vel = vel.translate(acc.mult(dt));
        pos = pos.translate(vel.mult(dt));
    
        lifetime += dt;
        if (lifetime > duration) {
            lifetime = duration;
        }
    }
}

void ShockParticle::setBlendMode() {
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
}
