#ifndef __setplayerdirectionevent__
#define __setplayerdirectionevent__

#include "Event.h"

class Player;

/**
 * \class SetPlayerDirectionEvent
 * \author Jeferson Rodrigues da Silva
 * \date 01/09/2010
 * \file SetPlayerDirectionEvent.h
 * \brief
 */
class SetPlayerDirectionEvent : public Event {

private:
    Player *player;
    int direction;
    bool executed;

public:
	SetPlayerDirectionEvent(Player *player, int direction);
	~SetPlayerDirectionEvent();

    virtual bool hasFinished();
    virtual bool isBlocking();
    virtual void run();
    virtual void update(double dt);
    virtual bool wasExecuted();

};

#endif // __setplayerdirectionevent__
