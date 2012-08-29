#ifndef __playervitalityanimation__
#define __playervitalityanimation__

#include "Animation.h"

/**
 * \class PlayerVitalityAnimation
 * \author Jeferson Rodrigues da Silva
 * \date 01/09/2010
 * \file PlayerVitalityAnimation.h
 * \brief 
 */
class PlayerVitalityAnimation : public Animation {

    
private:
    std::list<Particle *> particles;

    double lifetime;
    double duration;
    
    double newParticleCounter;
    double interval;

public:
	PlayerVitalityAnimation(const Vector &position);
	~PlayerVitalityAnimation();

	virtual std::list<Particle*> getParticles();
	virtual bool hasFinished();
	virtual bool isBlocking();
	virtual void update(double dt);
    
};

#endif // __playervitalityanimation__
