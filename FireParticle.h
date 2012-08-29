#ifndef __fireparticle__
#define __fireparticle__

#include "Particle.h"

/**
 * \class FireParticle
 * \author Jeferson Rodrigues da Silva
 * \date 12/15/2009
 * \file FireParticle.h
 * \brief 
 */
class FireParticle : public Particle {
    
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
	FireParticle(const Vector &worldPosition, const Vector &position);
	~FireParticle();

	virtual double getOpacity();
    virtual Vector getWorldPosition();
	virtual Vector getPosition(double edt);
	virtual double getSize();
    virtual double getRotation();
	virtual int getTexture();
	virtual bool isAlive();
    virtual void setBlendMode();
    
	virtual void update(double dt);
    
};

#endif // __fireparticle__
