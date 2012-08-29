#ifndef __slashanimation__
#define __slashanimation__

#include "Animation.h"

/**
 * \class SlashAnimation
 * \author Jeferson Rodrigues da Silva
 * \date 12/15/2009
 * \file SlashAnimation.h
 * \brief 
 */
class SlashAnimation : public Animation {
    
private:
    std::list<Particle *> particles;
    
    double lifetime;
    double duration;
    
    double newParticleCounter;
    double interval;

public:
	SlashAnimation(const Vector &position);
	~SlashAnimation();

	virtual std::list<Particle*> getParticles();
	virtual bool hasFinished();
	virtual bool isBlocking();
	virtual void update(double dt);
    
};

#endif // __slashanimation__
