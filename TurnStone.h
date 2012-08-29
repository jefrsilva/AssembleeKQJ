#ifndef __turnstone__
#define __turnstone__

#include "BoundingBox.h"
#include "Vector.h"
#include "LinearInterpolator.h"

class Tooltip;

/**
 * \class TurnStone
 * \author Jeferson Rodrigues da Silva
 * \date 12/13/2009
 * \file TurnStone.h
 * \brief 
 */
class TurnStone {
    
private:
    Tooltip *tooltip;
    Vector position;
    
    double stoneAlpha[3];
    LinearInterpolator iplStoneAlpha[3];

public:
	TurnStone();
	~TurnStone();

    void update(double dt);
    void render(double edt, bool selection);
    
    void setTooltipVisibility(bool visibility);
    BoundingBox getBoundingBox();
    
    void setTurn(int turn);
    
    Vector getPosition();

};

#endif // __turnstone__
