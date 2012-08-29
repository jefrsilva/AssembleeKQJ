#ifndef __playericehitanimation__
#define __playericehitanimation__

#include "Animation.h"

class Player;
class Particle;

/**
 * \class PlayerIceHitAnimation
 * \author Jeferson Rodrigues da Silva
 * \date 12/20/2009
 * \file PlayerIceHitAnimation.h
 * \brief 
 */
class PlayerIceHitAnimation : public Animation {

private:
    std::list<Particle *> particles;
    Player *player;
    
    double lifetime;
    double duration;
    
    double newParticleCounter;
    double interval;

public:
	PlayerIceHitAnimation(Player *player);
	~PlayerIceHitAnimation();

	virtual std::list<Particle*> getParticles();
	virtual bool hasFinished();
	virtual bool isBlocking();
	virtual void update(double dt);
    
};

#endif // __playericehitanimation__
