#ifndef __enemyturnanimation__
#define __enemyturnanimation__

#include "Animation.h"

/**
 * \class EnemyTurnAnimation
 * \author Jeferson Rodrigues da Silva
 * \date 01/04/2010
 * \file EnemyTurnAnimation.h
 * \brief 
 */
class EnemyTurnAnimation : public Animation {

private:
    std::list<Particle *> particles;

    double lifetime;
    double duration;
    
    double newParticleCounter;
    double interval;

public:
	EnemyTurnAnimation(const Vector &position);
	~EnemyTurnAnimation();

	virtual std::list<Particle*> getParticles();
	virtual bool hasFinished();
	virtual bool isBlocking();
	virtual void update(double dt);
    
};

#endif // __enemyturnanimation__
