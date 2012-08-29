#include "TextAnimation.h"
#include "TextParticle.h"

#include "Engine.h"

#include <iostream>

TextAnimation::TextAnimation(const Vector &position, std::string text,
                             int alignment, bool convertToOrtho) {
    Vector realPosition = position;
    this->convertToOrtho = convertToOrtho;

    if (convertToOrtho) {
        Engine::VideoSystem *videoSystem =
            Engine::Core::getInstance()->getVideoSystem();

        double width = videoSystem->getWindowWidth();
        double height = videoSystem->getWindowHeight();

        double orthoHeight = 1.0;
        double orthoWidth = (width / height) * orthoHeight;

        Vector ortho = Vector();
        videoSystem->project(position.x, position.y, position.z,
                             &ortho.x, &ortho.y, &ortho.z);

        realPosition =
            Vector(((ortho.x / width) * orthoWidth) - orthoWidth / 2.0,
                   ((ortho.y / height) * orthoHeight) - orthoHeight / 2.0,
                   0.0);
    }

    textParticle = new TextParticle(realPosition, text, alignment);
}

TextAnimation::~TextAnimation() {
    delete textParticle;
}

std::list<Particle*> TextAnimation::getParticles() {
    std::list<Particle *> particles;
    particles.push_back(textParticle);

    return particles;
}

bool TextAnimation::hasFinished() {
    bool finished = !textParticle->isAlive();

    return finished;
}

bool TextAnimation::isBlocking() {
    return true;
}

void TextAnimation::update(double dt) {
    textParticle->update(dt);
}
