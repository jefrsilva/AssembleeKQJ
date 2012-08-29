#ifndef __fadeoutmusicevent__
#define __fadeoutmusicevent__

#include "Event.h"

/**
 * \class FadeOutMusicEvent
 * \author Jeferson Rodrigues da Silva
 * \date 01/04/2010
 * \file FadeOutMusicEvent.h
 * \brief 
 */
class FadeOutMusicEvent : public Event {
    
private:
    int duration;
    bool executed;

public:
	FadeOutMusicEvent(int duration);
	~FadeOutMusicEvent();

	virtual bool hasFinished();
	virtual bool isBlocking();
	virtual void run();
	virtual void update(double dt);
	virtual bool wasExecuted();
    
};

#endif // __fadeoutmusicevent__
