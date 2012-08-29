#ifndef __fireslashanimation__
#define __fireslashanimation__

#include "Animation.h"
#include "Vector.h"

#include <list>

class Particle;

/**
 * \class FireSlashAnimation
 * \author Jeferson Rodrigues da Silva
 * \date 12/15/2009
 * \file FireSlashAnimation.h
 * \brief 
 */
class FireSlashAnimation : public Animation {
    
private:
    std::list<Particle *> particles;
    
    double lifetime;
    double duration;
    
    double newParticleCounter;
    double interval;

public:
	FireSlashAnimation(const Vector &position);
	~FireSlashAnimation();

	virtual std::list<Particle*> getParticles();
	virtual bool hasFinished();
	virtual bool isBlocking();
	virtual void update(double dt);
    
};

#endif // __fireslashanimation__
