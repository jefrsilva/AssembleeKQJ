#ifndef __slashparticle__
#define __slashparticle__

#include "Particle.h"

#include "Vector.h"

class SlashParticle : public Particle {
    
private:
    Vector worldPosition;
    Vector start;
    Vector end;
    
    int texture;
    double size;
    
    double lifetime;
    double duration;

public:
	SlashParticle(const Vector &worldPosition);
	~SlashParticle();

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

#endif // __slashparticle__
