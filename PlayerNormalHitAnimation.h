#ifndef __playernormalhitanimation__
#define __playernormalhitanimation__

#include "Animation.h"

#include <list>

class Particle;
class Player;

/**
 * \class PlayerNormalHitAnimation
 * \author Jeferson Rodrigues da Silva
 * \date 12/19/2009
 * \file PlayerNormalHitAnimation.h
 * \brief
 */
class PlayerNormalHitAnimation : public Animation {
    
private:
    std::list<Particle *> particles;
    Player *player;
    
    double lifetime;
    double duration;
    
    double newParticleCounter;
    double interval;

public:
    PlayerNormalHitAnimation(Player *player);
    ~PlayerNormalHitAnimation();

    virtual std::list<Particle*> getParticles();
    virtual bool hasFinished();
    virtual bool isBlocking();
    virtual void update(double dt);
    
};

#endif // __playernormalhitanimation__
