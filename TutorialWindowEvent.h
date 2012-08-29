#ifndef __tutorialwindowevent__
#define __tutorialwindowevent__

#include "Event.h"

class GameController;
class UserInterface;

#include <string>

/**
 * \class TutorialWindowEvent
 * \author Jeferson Rodrigues da Silva
 * \date 01/05/2010
 * \file TutorialWindowEvent.h
 * \brief
 */
class TutorialWindowEvent : public Event {
    
private:
    GameController *game;
    UserInterface *gui;
    std::string text;
    bool executed;

public:
    TutorialWindowEvent(GameController *game, UserInterface *gui,
                        std::string text);
    ~TutorialWindowEvent();

    virtual bool hasFinished();
    virtual bool isBlocking();
    virtual void run();
    virtual void update(double dt);
    virtual bool wasExecuted();

};

#endif // __tutorialwindowevent__
