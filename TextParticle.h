#ifndef __textparticle__
#define __textparticle__

#include "Particle.h"
#include "TextRenderer.h"

#include "Vector.h"

#include <string>

class TextParticle : public Particle {

private:
    TextRenderer *textRenderer;
    std::string text;
    int alignment;
    
    Vector pos;
    Vector vel;
    Vector acc;

    double lifetime;
    double duration;
    
    double slowCounter;
    double slowInterval;

public:
    TextParticle(const Vector &position, std::string text, int alignment);
    ~TextParticle();

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

#endif // __textparticle__
