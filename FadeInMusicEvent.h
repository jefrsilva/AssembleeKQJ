#ifndef __fadeinmusicevent__
#define __fadeinmusicevent__

#include "Event.h"

#include <string>

/**
 * \class FadeInMusicEvent
 * \author Jeferson Rodrigues da Silva
 * \date 01/04/2010
 * \file FadeInMusicEvent.h
 * \brief 
 */
class FadeInMusicEvent : public Event {
    
private:
    std::string musicID;
    int duration;
    bool executed;

public:
	FadeInMusicEvent(std::string musicID, int duration);
	~FadeInMusicEvent();

	virtual bool hasFinished();
	virtual bool isBlocking();
	virtual void run();
	virtual void update(double dt);
	virtual bool wasExecuted();
    
};

#endif // __fadeinmusicevent__
