#ifndef __playerhurtanimation__
#define __playerhurtanimation__

#include "Animation.h"

/**
 * \class PlayerHurtAnimation
 * \author Jeferson Rodrigues da Silva
 * \date 01/08/2010
 * \file PlayerHurtAnimation.h
 * \brief 
 */
class PlayerHurtAnimation : public Animation {
    
private:
    std::list<Particle *> particles;

    double lifetime;
    double duration;
    
    double newParticleCounter;
    double interval;

public:
	PlayerHurtAnimation(const Vector &position);
	~PlayerHurtAnimation();

	virtual std::list<Particle*> getParticles();
	virtual bool hasFinished();
	virtual bool isBlocking();
	virtual void update(double dt);
    
};

#endif // __playerhurtanimation__
