#ifndef __turnplayerevent__
#define __turnplayerevent__

#include "Event.h"

class Player;

/**
 * \class TurnPlayerEvent
 * \author Jeferson Rodrigues da Silva
 * \date 12/14/2009
 * \file TurnPlayerEvent.h
 * \brief 
 */
class TurnPlayerEvent : public Event {
    
private:
    Player *player;
    int direction;
    bool executed;

public:
	TurnPlayerEvent(Player *player, int direction);
	~TurnPlayerEvent();
    
    void run();
    void update(double dt);
    bool wasExecuted();
    bool isBlocking();
    bool hasFinished();

};

#endif // __turnplayerevent__
