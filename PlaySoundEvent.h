#ifndef __playsoundevent__
#define __playsoundevent__

#include "Event.h"

#include <string>

/**
 * \class PlaySoundEvent
 * \author Jeferson Rodrigues da Silva
 * \date 01/03/2010
 * \file PlaySoundEvent.h
 * \brief 
 */
class PlaySoundEvent : public Event {
    
private:
    std::string soundID;
    bool executed;

public:
	PlaySoundEvent(std::string soundID);
	~PlaySoundEvent();

	virtual bool hasFinished();
	virtual bool isBlocking();
	virtual void run();
	virtual void update(double dt);
	virtual bool wasExecuted();
    
};

#endif // __playsoundevent__
