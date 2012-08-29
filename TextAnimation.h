#ifndef __textanimation__
#define __textanimation__

#include "Animation.h"

#include "Vector.h"

#include <string>

/**
 * \class TextAnimation
 * \author Jeferson Rodrigues da Silva
 * \date 12/15/2009
 * \file TextAnimation.h
 * \brief 
 */
class TextAnimation : public Animation {

private:
    Particle *textParticle;
    bool convertToOrtho;

public:
    TextAnimation(const Vector &position, std::string text, int alignment,
                  bool absolutePosition);
    ~TextAnimation();

    virtual std::list<Particle*> getParticles();
    virtual bool hasFinished();
    virtual bool isBlocking();
    virtual void update(double dt);
    
};

#endif // __textanimation__
