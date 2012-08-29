#ifndef __playershockhitanimation__
#define __playershockhitanimation__

#include "Animation.h"

class Player;

/**
 * \class PlayerShockHitAnimation
 * \author Jeferson Rodrigues da Silva
 * \date 12/20/2009
 * \file PlayerShockHitAnimation.h
 * \brief 
 */
class PlayerShockHitAnimation : public Animation {

private:
    std::list<Particle *> particles;
    Player *player;
    
    double lifetime;
    double duration;
    
    double newParticleCounter;
    double interval;

public:
	PlayerShockHitAnimation(Player *player);
	~PlayerShockHitAnimation();

	virtual std::list<Particle*> getParticles();
	virtual bool hasFinished();
	virtual bool isBlocking();
	virtual void update(double dt);
    
};

#endif // __playershockhitanimation__
