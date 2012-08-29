#ifndef __smokeparticle__
#define __smokeparticle__

#include "Particle.h"

/**
 * \class SmokeParticle
 * \author Jeferson Rodrigues da Silva
 * \date 12/20/2009
 * \file SmokeParticle.h
 * \brief 
 */
class SmokeParticle : public Particle {
    
private:
    int texture;

    Vector worldPosition;

    Vector pos;
    Vector vel;
    Vector acc;
    
    double size;
    double rotation;
    
    double lifetime;
    double duration;

public:
	SmokeParticle(const Vector &worldPosition, const Vector &position);
	~SmokeParticle();

	virtual double getOpacity();
	virtual Vector getPosition(double edt);
	virtual double getRotation();
	virtual double getSize();
	virtual int getTexture();
	virtual Vector getWorldPosition();
	virtual bool isAlive();
	virtual void setBlendMode();
	virtual void update(double dt);
    
};

#endif // __smokeparticle__
