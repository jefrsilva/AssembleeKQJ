#include "EventManager.h"
#include "GameController.h"

#include "Event.h"

#include <iostream>

EventManager::EventManager(GameController *game) {
    this->game = game;
}

EventManager::~EventManager() {
    std::list<Event *>::iterator it;
    
    for (it = asyncEvents.begin(); it != asyncEvents.end(); it++) {
        Event *event = (*it);
        delete event;
    }

    for (it = events.begin(); it != events.end(); it++) {
        Event *event = (*it);
        delete event;
    }
}

void EventManager::update(double dt) {
    bool endUpdate = false;

    std::list<Event *>::iterator it = events.begin();
    while (it != events.end() && !endUpdate) {
        Event *event = (*it);

        if (!event->wasExecuted()) {
            event->run();
        }

        if (event->isBlocking()) {
            endUpdate = true;
        }

        if (!event->hasFinished()) {
            event->update(dt);
            it++;
        } else {
            delete event;
            it = events.erase(it);
        }
    }

    it = asyncEvents.begin();
    while (it != asyncEvents.end()) {
        Event *event = (*it);

        if (!event->wasExecuted()) {
            event->run();
        }

        if (!event->hasFinished()) {
            event->update(dt);
            it++;
        } else {
            delete event;
            it = asyncEvents.erase(it);
        }
    }
}

void EventManager::queueAsyncEvent(Event *event) {
    asyncEvents.push_back(event);
}

void EventManager::queueEvent(Event *event) {
    events.push_back(event);
}

void EventManager::queueFrontEvent(Event *event) {
    events.push_front(event);
}

bool EventManager::hasPendingEvents() {
    bool pendingEvents = (events.size() > 0);

    return pendingEvents;
}
