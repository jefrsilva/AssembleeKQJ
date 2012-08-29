#include "TextParticle.h"
#include "GlobalConstants.h"

#include "Engine.h"

TextParticle::TextParticle(const Vector &position,
                           std::string text, int alignment) {
    this->textRenderer = new TextRenderer();
    this->text = text;
    this->alignment = alignment;
                               
    this->pos = position;
    
    this->vel = Vector(0.0, 0.10 / 1000.0, 0.0);
    this->acc = Vector(0.0, 0.0, 0.0);
    this->lifetime = 0.0;
    this->duration = 750.0;
    
    this->slowCounter = 0.0;
    this->slowInterval = 250.0;
}

TextParticle::~TextParticle() {
    if (this->textRenderer) {
        delete this->textRenderer;
        this->textRenderer = 0;
    }
}

double TextParticle::getOpacity() {
    double alpha = 1.0 - (lifetime / duration);

    return alpha;
}

Vector TextParticle::getPosition(double edt) {
    Vector eVel = vel.translate(acc.mult(edt));
    Vector ePos = pos.translate(vel.mult(edt));

    return ePos;
}

double TextParticle::getSize() {
    return 0.0;
}

double TextParticle::getRotation() {
    return 0.0;
}

int TextParticle::getTexture() {
    return 0;
}

bool TextParticle::isAlive() {
    bool alive = (lifetime < duration);

    return alive;
}

void TextParticle::update(double dt) {
    if (isAlive()) {
        slowCounter += dt;
        if (slowCounter > slowInterval) {
            slowCounter -= slowInterval;
            vel = vel.mult(0.8);
        }
        
        vel = vel.translate(acc.mult(dt));
        pos = pos.translate(vel.mult(dt));

        lifetime += dt;
        if (lifetime > duration) {
            lifetime = duration;
        }
    }
}

void TextParticle::setBlendMode() {

}

void TextParticle::render(double edt) {
    textRenderer->renderText(alignment, pos, text);
}

Vector TextParticle::getWorldPosition() {
    return pos;
}
