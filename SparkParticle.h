#ifndef __sparkparticle__
#define __sparkparticle__

#include "Particle.h"

class SparkParticle : public Particle {

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
	SparkParticle(const Vector &worldPosition, const Vector &position);
	~SparkParticle();

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

#endif // __sparkparticle__
