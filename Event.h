#ifndef __event__
#define __event__

/**
 * \class Event
 * \author Jeferson Rodrigues da Silva
 * \date 12/14/2009
 * \file Event.h
 * \brief
 */
class Event {

public:
    virtual ~Event() {};
    
    virtual void run() = 0;
    virtual void update(double dt) = 0;
    virtual bool wasExecuted() = 0;
    virtual bool isBlocking() = 0;
    virtual bool hasFinished() = 0;

};

#endif // __event__
