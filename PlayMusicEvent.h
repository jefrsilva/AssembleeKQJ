#ifndef __playmusicevent__
#define __playmusicevent__

#include "Event.h"

#include <string>

/**
 * \class PlayMusicEvent
 * \author Jeferson Rodrigues da Silva
 * \date 01/03/2010
 * \file PlayMusicEvent.h
 * \brief
 */
class PlayMusicEvent : public Event {

private:
    std::string musicID;
    bool executed;

public:
    PlayMusicEvent(std::string musicID);
    ~PlayMusicEvent();

    virtual bool hasFinished();
    virtual bool isBlocking();
    virtual void run();
    virtual void update(double dt);
    virtual bool wasExecuted();

};

#endif // __playmusicevent__
