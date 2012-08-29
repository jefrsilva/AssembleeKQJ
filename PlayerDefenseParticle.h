#ifndef __playerdefenseparticle__
#define __playerdefenseparticle__

#include "Particle.h"

/**
 * \class PlayerDefenseParticle
 * \author Jeferson Rodrigues da Silva
 * \date 01/08/2010
 * \file PlayerDefenseParticle.h
 * \brief 
 */
class PlayerDefenseParticle : public Particle {

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
    
    Vector color;

public:
    PlayerDefenseParticle(double r, double g, double b, const Vector &position);
    ~PlayerDefenseParticle();

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

#endif // __playerdefenseparticle__
