#ifndef __animation__
#define __animation__

#include "Vector.h"

#include <list>

class Particle;

/**
 * \class Animation
 * \author Jeferson Rodrigues da Silva
 * \date 12/15/2009
 * \file Animation.h
 * \brief 
 */
class Animation {
    
protected:
    Vector worldPosition;

public:
    virtual ~Animation() {};
    
    virtual void update(double dt) = 0;
    virtual bool hasFinished() = 0;
    virtual bool isBlocking() = 0;
    virtual std::list<Particle *> getParticles() = 0;
    
    virtual void setWorldPosition(const Vector &worldPosition);

};

#endif // __animation__
