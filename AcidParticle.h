#ifndef __acidparticle__
#define __acidparticle__

#include "Particle.h"

/**
 * \class AcidParticle
 * \author Jeferson Rodrigues da Silva
 * \date 12/20/2009
 * \file AcidParticle.h
 * \brief 
 */
class AcidParticle : public Particle {

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
	AcidParticle(const Vector &worldPosition, const Vector &position);
	~AcidParticle();

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

#endif // __acidparticle__
