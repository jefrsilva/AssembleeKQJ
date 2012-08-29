#ifndef __playerhealparticle__
#define __playerhealparticle__

#include "Particle.h"

/**
 * \class PlayerHealParticle
 * \author Jeferson Rodrigues da Silva
 * \date 01/08/2010
 * \file PlayerHealParticle.h
 * \brief 
 */
class PlayerHealParticle : public Particle {

private:
    Vector pos;
    Vector vel;
    Vector acc;

    double lifetime;
    double duration;
    
    double slowCounter;
    double slowInterval;
    
    double size;
    double rotation;
    int texture;

public:
    PlayerHealParticle(const Vector &position);
    ~PlayerHealParticle();

    virtual double getOpacity();
    virtual Vector getPosition(double edt);
    virtual double getRotation();
    virtual double getSize();
    virtual int getTexture();
    virtual bool isAlive();
    virtual void setBlendMode();
    virtual void update(double dt);
    virtual void render(double edt);
    virtual Vector getWorldPosition();
    
};

#endif // __playerhealparticle__
