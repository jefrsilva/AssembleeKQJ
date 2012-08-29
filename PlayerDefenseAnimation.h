#ifndef __playerdefenseanimation__
#define __playerdefenseanimation__

#include "Animation.h"

/**
 * \class PlayerDefenseAnimation
 * \author Jeferson Rodrigues da Silva
 * \date 01/08/2010
 * \file PlayerDefenseAnimation.h
 * \brief 
 */
class PlayerDefenseAnimation : public Animation {
    
private:
    std::list<Particle *> particles;

    double lifetime;
    double duration;
    
    double newParticleCounter;
    double interval;
    
    unsigned char defenseType;

public:
	PlayerDefenseAnimation(const Vector &position, unsigned char defenseType);
	~PlayerDefenseAnimation();

	virtual std::list<Particle*> getParticles();
	virtual bool hasFinished();
	virtual bool isBlocking();
	virtual void update(double dt);
    
};

#endif // __playerdefenseanimation__
