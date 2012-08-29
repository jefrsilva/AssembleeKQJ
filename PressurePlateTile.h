#ifndef __pressureplatetile__
#define __pressureplatetile__

#include "Tile.h"
#include "LinearInterpolator.h"

#include <string>

/**
 * \class PressurePlateTile
 * \author Jeferson Rodrigues da Silva
 * \date 12/21/2009
 * \file PressurePlateTile.h
 * \brief
 */
class PressurePlateTile : public Tile { // tolua_export
    
private:
    std::string onActivate;
    std::string onDeactivate;

    double platePosition;
    LinearInterpolator iplPlatePosition;
    
    int weightThreshold;
    
    double pressedPosition;
    double releasedPosition;
    
    bool activated;

public:
    PressurePlateTile(Map *map, const Vector &worldPosition);
    ~PressurePlateTile();

    virtual void render(double edt, bool selection, int modelsToRender);
    virtual void update(double dt);
    virtual void renderOrtho();    
    
    void activate();
    void deactivate();
    
    void callActivateScript();
    void callDeactivateScript();
    
    void setState(bool activated); // tolua_export
    bool isActivated(); // tolua_export
    void setWeightThreshold(int weightThreshold); // tolua_export
    void setOnActivate(std::string onActivate); // tolua_export
    void setOnDeactivate(std::string onDeactivate); // tolua_export
    
}; // tolua_export

#endif // __pressureplatetile__
