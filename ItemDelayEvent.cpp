#include "ItemDelayEvent.h"
#include "Item.h"

ItemDelayEvent::ItemDelayEvent(Item *item) {
    this->item = item;
    this->executed = false;
}

ItemDelayEvent::~ItemDelayEvent() {
    
}

bool ItemDelayEvent::hasFinished() {
    return executed;
}

bool ItemDelayEvent::isBlocking() {
    return false;
}

void ItemDelayEvent::run() {
    if (item) {
        item->enterDelay();
    }
    
    executed = true;
}

void ItemDelayEvent::update(double dt) {
    
}

bool ItemDelayEvent::wasExecuted() {
    return executed;
}
