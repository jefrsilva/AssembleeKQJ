#ifndef __particle__
#define __particle__

#include "Vector.h"

/**
 * \class Particle
 * \author Jeferson Rodrigues da Silva
 * \date 12/15/2009
 * \file Particle.h
 * \brief 
 */
class Particle {
    
public:
    virtual ~Particle() {};
    
    virtual void update(double dt) = 0;
    virtual void render(double edt);
    
    virtual int getTexture() = 0;
    virtual Vector getWorldPosition() = 0;
    virtual Vector getPosition(double edt) = 0;
    virtual double getSize() = 0;
    virtual double getOpacity() = 0;
    virtual double getRotation() = 0;
    virtual bool isAlive() = 0;
    virtual void setBlendMode() = 0;

};

#endif // __particle__
