#include "ActivateDoorEvent.h"
#include "Item.h"
#include "DoorTile.h"
#include "GlobalConstants.h"

#include "Events.h"
#include "Animations.h"

#include "Engine.h"

#include <sstream>

ActivateDoorEvent::ActivateDoorEvent(DoorTile *door, Item *item) {
    this->item = item;
    this->door = door;

    this->executed = false;
}

ActivateDoorEvent::~ActivateDoorEvent() {

}

bool ActivateDoorEvent::hasFinished() {
    return executed;
}

bool ActivateDoorEvent::isBlocking() {
    return false;
}

void ActivateDoorEvent::run() {
    Engine::AudioSystem *audioSystem =
        Engine::Core::getInstance()->getAudioSystem();

    if (!item) {
        if (!door->isLocked()) {
            if (!door->hasMonsters()) {
                door->activate();
            }
        } else {
            audioSystem->playSound("Denied", 0);
        }
    } else {
        if (item->getID() == door->getKey()) {
            audioSystem->playSound("Unlock", 0);

            door->setLocked(false);
            door->setKey("");
        } else {
            audioSystem->playSound("Denied", 0);
        }
    }

    executed = true;
}

void ActivateDoorEvent::update(double dt) {

}

bool ActivateDoorEvent::wasExecuted() {
    return executed;
}
