#include "SlashParticle.h"
#include "GlobalConstants.h"

#include "Engine.h"

SlashParticle::SlashParticle(const Vector &worldPosition) {
    this->worldPosition = worldPosition;
    this->start = Vector(MONSTER_SIZE / 2.0,
                         MONSTER_SIZE,
                         1.0);
    this->end = Vector(-MONSTER_SIZE / 2.0,
                       0.0,
                       1.0);

    this->texture = 1;
    this->size = 2.0;

    this->lifetime = 0.0;
    this->duration = 200.0;
}

SlashParticle::~SlashParticle() {

}

double SlashParticle::getOpacity() {
    double opacity = 1.0;
    
    if (!isAlive()) {
        opacity = 0.0;
    }
    
    return opacity;
}

Vector SlashParticle::getPosition(double edt) {
    double eLifetime = lifetime + edt;
    if (eLifetime > duration) {
        eLifetime = duration;
    }

    double t = eLifetime / duration;
    Vector position = (start.mult(1.0 - t)).translate(end.mult(t));

    return position;
}

double SlashParticle::getRotation() {
    return 0.0;
}

double SlashParticle::getSize() {
    return size;
}

int SlashParticle::getTexture() {
    return texture;
}

Vector SlashParticle::getWorldPosition() {
    return worldPosition;
}

bool SlashParticle::isAlive() {
    bool alive = (lifetime < duration);

    return alive;
}

void SlashParticle::setBlendMode() {
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
}

void SlashParticle::update(double dt) {
    if (isAlive()) {
        lifetime += dt;
        if (lifetime > duration) {
            lifetime = duration;
        }
    }
}
