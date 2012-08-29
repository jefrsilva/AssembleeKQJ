#ifndef __playerhealanimation__
#define __playerhealanimation__

#include "Animation.h"

/**
 * \class PlayerHealAnimation
 * \author Jeferson Rodrigues da Silva
 * \date 01/08/2010
 * \file PlayerHealAnimation.h
 * \brief 
 */
class PlayerHealAnimation : public Animation {
    
private:
    std::list<Particle *> particles;

    double lifetime;
    double duration;
    
    double newParticleCounter;
    double interval;

public:
	PlayerHealAnimation(const Vector &position);
	~PlayerHealAnimation();

	virtual std::list<Particle*> getParticles();
	virtual bool hasFinished();
	virtual bool isBlocking();
	virtual void update(double dt);
    
};

#endif // __playerhealanimation__
