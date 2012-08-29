#ifndef __playervitalityparticle__
#define __playervitalityparticle__

#include "Particle.h"

/**
 * \class PlayerVitalityParticle
 * \author Jeferson Rodrigues da Silva
 * \date 01/09/2010
 * \file PlayerVitalityParticle.h
 * \brief 
 */
class PlayerVitalityParticle : public Particle {


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
    PlayerVitalityParticle(const Vector &position);
    ~PlayerVitalityParticle();

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

#endif // __playervitalityparticle__
