#ifndef __eventmanager__
#define __eventmanager__

#include <list>

class GameController;
class Event;

/**
 * \class EventManager
 * \author Jeferson Rodrigues da Silva
 * \date 12/14/2009
 * \file EventManager.h
 * \brief
 */
class EventManager {

private:
    GameController *game;
    std::list<Event *> events;
    std::list<Event *> asyncEvents;

public:
    EventManager(GameController *game);
    ~EventManager();
    
    void update(double dt);
    
    void queueAsyncEvent(Event *event);
    void queueEvent(Event *event);
    void queueFrontEvent(Event *event);
    bool hasPendingEvents();

};

#endif // __eventmanager__
