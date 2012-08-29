#ifndef __playeracidhitanimation__
#define __playeracidhitanimation__

#include "Animation.h"

class Player;
class Particle;

/**
 * \class PlayerAcidHitAnimation
 * \author Jeferson Rodrigues da Silva
 * \date 12/20/2009
 * \file PlayerAcidHitAnimation.h
 * \brief 
 */
class PlayerAcidHitAnimation : public Animation {

private:
    std::list<Particle *> particles;
    Player *player;
    
    double lifetime;
    double duration;
    
    double newParticleCounter;
    double interval;
    
    double newSmokeCounter;
    double smokeInterval;

public:
	PlayerAcidHitAnimation(Player *player);
	~PlayerAcidHitAnimation();

	virtual std::list<Particle*> getParticles();
	virtual bool hasFinished();
	virtual bool isBlocking();
	virtual void update(double dt);
    
};

#endif // __playeracidhitanimation__
