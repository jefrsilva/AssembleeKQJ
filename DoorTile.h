#ifndef __doortile__
#define __doortile__

#include "Tile.h"
#include "LinearInterpolator.h"

#include <string>

class Tooltip;

/**
 * \class DoorTile
 * \author Jeferson Rodrigues da Silva
 * \date 12/20/2009
 * \file DoorTile.h
 * \brief 
 */
class DoorTile : public Tile { // tolua_export
    
private:
    double doorPosition;
    LinearInterpolator iplDoorPosition;
    
    bool isVertical;
    
    Tooltip *tooltip;
    bool isOpening;
    bool closeSound;
    
    bool locked;
    std::string key;

public:
	DoorTile(Map *map, const Vector &worldPosition, bool isVertical);
	~DoorTile();

	virtual void render(double edt, bool selection, int modelsToRender);
	virtual void update(double dt);
    virtual void renderOrtho();
    
    Tooltip *getTooltip();
    bool isOpen();
    void activate();
    
    bool blocksLineOfSight();
    bool isPassable();
    
    bool isLocked();
    std::string getKey();
    
    void open(); // tolua_export
    void close(); // tolua_export
    
    void setLocked(bool locked); // tolua_export
    void setKey(std::string itemID); // tolua_export
    
}; // tolua_export

#endif // __doortile__
