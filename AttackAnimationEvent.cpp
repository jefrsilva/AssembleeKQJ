#include "AttackAnimationEvent.h"
#include "Animation.h"

#include <iostream>

AttackAnimationEvent::AttackAnimationEvent() {
    this->blocking = true;
    this->executed = false;
}

AttackAnimationEvent::AttackAnimationEvent(bool blocking) {
    this->blocking = blocking;
    this->executed = false;
}

AttackAnimationEvent::~AttackAnimationEvent() {
    std::list<Animation *>::iterator it;

    for (it = animations.begin(); it != animations.end(); it++) {
        Animation *animation = (*it);

        delete animation;
    }
}

void AttackAnimationEvent::run() {
    if (!executed) {
        executed = true;
    }
}

void AttackAnimationEvent::update(double dt) {
    std::list<Animation *>::iterator it = animations.begin();

    bool finished = false;
    while (it != animations.end() && !finished) {
        Animation *animation = (*it);

        if (!animation->hasFinished()) {
            animation->update(dt);
            if (animation->isBlocking()) {
                finished = true;
            } else {
                it++;
            }
        } else {
            delete animation;
            it = animations.erase(it);
        }
    }
}

bool AttackAnimationEvent::wasExecuted() {
    return executed;
}

bool AttackAnimationEvent::isBlocking() {
    return blocking;
}

bool AttackAnimationEvent::hasFinished() {
    bool finished = true;

    std::list<Animation *>::iterator it;
    for (it = animations.begin(); it != animations.end(); it++) {
        Animation *animation = (*it);

        if (!animation->hasFinished()) {
            finished = false;
            break;
        }
    }

    return (finished && executed);
}

void AttackAnimationEvent::addAnimation(Animation *animation) {
    animations.push_back(animation);
}
