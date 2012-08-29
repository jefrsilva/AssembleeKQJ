#ifndef __acidslashanimation__
#define __acidslashanimation__

#include "Animation.h"

/**
 * \class AcidSlashAnimation
 * \author Jeferson Rodrigues da Silva
 * \date 12/20/2009
 * \file AcidSlashAnimation.h
 * \brief 
 */
class AcidSlashAnimation : public Animation {

private:
    std::list<Particle *> particles;

    double lifetime;
    double duration;
    
    double newParticleCounter;
    double interval;
    
    double newSmokeCounter;
    double smokeInterval;

public:
	AcidSlashAnimation(const Vector &position);
	~AcidSlashAnimation();

	virtual std::list<Particle*> getParticles();
	virtual bool hasFinished();
	virtual bool isBlocking();
	virtual void update(double dt);
    
};

#endif // __acidslashanimation__
