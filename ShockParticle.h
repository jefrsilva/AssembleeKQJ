#ifndef __shockparticle__
#define __shockparticle__

#include "Particle.h"

class ShockParticle : public Particle {

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
    
    double turnCounter;
    double turnInterval;

public:
	ShockParticle(const Vector &worldPosition, const Vector &position);
	~ShockParticle();

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

#endif // __shockparticle__
