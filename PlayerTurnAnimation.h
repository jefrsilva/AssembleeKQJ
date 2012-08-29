#ifndef __playerturnanimation__
#define __playerturnanimation__

#include "Animation.h"

/**
 * \class PlayerTurnAnimation
 * \author Jeferson Rodrigues da Silva
 * \date 01/04/2010
 * \file PlayerTurnAnimation.h
 * \brief 
 */
class PlayerTurnAnimation : public Animation {
    
private:
    std::list<Particle *> particles;

    double lifetime;
    double duration;
    
    double newParticleCounter;
    double interval;

public:
	PlayerTurnAnimation(const Vector &position);
	~PlayerTurnAnimation();

	virtual std::list<Particle*> getParticles();
	virtual bool hasFinished();
	virtual bool isBlocking();
	virtual void update(double dt);
    
};

#endif // __playerturnanimation__
