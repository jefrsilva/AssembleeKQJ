#ifndef __shockslashanimation__
#define __shockslashanimation__

#include "Animation.h"

/**
 * \class ShockSlashAnimation
 * \author Jeferson Rodrigues da Silva
 * \date 12/15/2009
 * \file ShockSlashAnimation.h
 * \brief 
 */
class ShockSlashAnimation : public Animation {

private:
    std::list<Particle *> particles;
    
    double lifetime;
    double duration;
    
    double newParticleCounter;
    double interval;

public:
	ShockSlashAnimation(const Vector &position);
	~ShockSlashAnimation();

	virtual std::list<Particle*> getParticles();
	virtual bool hasFinished();
	virtual bool isBlocking();
	virtual void update(double dt);
    
};

#endif // __shockslashanimation__
