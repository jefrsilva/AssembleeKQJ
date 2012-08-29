#ifndef __iceparticle__
#define __iceparticle__

#include "Particle.h"

/**
 * \class IceParticle
 * \author Jeferson Rodrigues da Silva
 * \date 12/19/2009
 * \file IceParticle.h
 * \brief 
 */
class IceParticle : public Particle {

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
	IceParticle(const Vector &worldPosition, const Vector &position);
	~IceParticle();

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

#endif // __iceparticle__
