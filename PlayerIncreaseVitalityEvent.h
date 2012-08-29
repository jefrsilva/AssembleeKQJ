#ifndef __playerincreasevitalityevent__
#define __playerincreasevitalityevent__

#include "Event.h"

class GameController;
class UserInterface;

/**
 * \class PlayerIncreaseVitalityEvent
 * \author Jeferson Rodrigues da Silva
 * \date 01/09/2010
 * \file PlayerIncreaseVitalityEvent.h
 * \brief
 */
class PlayerIncreaseVitalityEvent : public Event {

private:
    GameController *game;
    UserInterface *gui;
    int maxHealthIncrease;
    bool executed;

public:
    PlayerIncreaseVitalityEvent(GameController *game, UserInterface *gui,
                                int maxHealthIncrease);
    ~PlayerIncreaseVitalityEvent();

    virtual bool hasFinished();
    virtual bool isBlocking();
    virtual void run();
    virtual void update(double dt);
    virtual bool wasExecuted();

};

#endif // __playerincreasevitalityevent__
