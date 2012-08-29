#ifndef __iceslashanimation__
#define __iceslashanimation__

#include "Animation.h"
#include "Vector.h"

#include <list>

class Particle;

/**
 * \class IceSlashAnimation
 * \author Jeferson Rodrigues da Silva
 * \date 12/19/2009
 * \file IceSlashAnimation.h
 * \brief 
 */
class IceSlashAnimation : public Animation {
    
private:
    std::list<Particle *> particles;

    double lifetime;
    double duration;
    
    double newParticleCounter;
    double interval;

public:
	IceSlashAnimation(const Vector &position);
	~IceSlashAnimation();

	virtual std::list<Particle*> getParticles();
	virtual bool hasFinished();
	virtual bool isBlocking();
	virtual void update(double dt);
    
};

#endif // __iceslashanimation__
