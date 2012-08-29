#ifndef __enemyturnparticle__
#define __enemyturnparticle__

#include "Particle.h"

/**
 * \class EnemyTurnParticle
 * \author Jeferson Rodrigues da Silva
 * \date 01/04/2010
 * \file EnemyTurnParticle.h
 * \brief 
 */
class EnemyTurnParticle : public Particle {

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
    EnemyTurnParticle(const Vector &position);
    ~EnemyTurnParticle();

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

#endif // __enemyturnparticle__
