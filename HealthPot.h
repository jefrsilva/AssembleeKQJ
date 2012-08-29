#ifndef __healthpot__
#define __healthpot__

#include "BoundingBox.h"
#include "Vector.h"

class Tooltip;
class Player;

/**
 * \class HealthPot
 * \author Jeferson Rodrigues da Silva
 * \date 12/08/2009
 * \file HealthPot.h
 * \brief 
 */
class HealthPot {
    
private:
    Player *player;
    Tooltip *tooltip;
    Vector position;

public:
    HealthPot(Player *player);
    ~HealthPot();
    
    void update(double dt);
    void render(double edt, bool selection);
    
    Vector getPosition();
    void setTooltipVisibility(bool visibility);
    BoundingBox getBoundingBox();

};

#endif // __healthpot__
