#ifndef __playerturnparticle__
#define __playerturnparticle__

#include "Particle.h"
#include "Vector.h"

/**
 * \class PlayerTurnParticle
 * \author Jeferson Rodrigues da Silva
 * \date 01/04/2010
 * \file PlayerTurnParticle.h
 * \brief 
 */
class PlayerTurnParticle : public Particle {

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
    PlayerTurnParticle(const Vector &position);
    ~PlayerTurnParticle();

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

#endif // __playerturnparticle__
