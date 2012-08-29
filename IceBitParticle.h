#ifndef __icebitparticle__
#define __icebitparticle__

#include "Particle.h"

/**
 * \class IceBitParticle
 * \author Jeferson Rodrigues da Silva
 * \date 12/19/2009
 * \file IceBitParticle.h
 * \brief 
 */
class IceBitParticle : public Particle {

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
    IceBitParticle(const Vector &worldPosition, const Vector &position);
    ~IceBitParticle();

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

#endif // __icebitparticle__
