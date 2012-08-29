#ifndef __holetile__
#define __holetile__

#include "Tile.h"

/**
 * \class HoleTile
 * \author Jeferson Rodrigues da Silva
 * \date 12/21/2009
 * \file HoleTile.h
 * \brief 
 */
class HoleTile : public Tile { // tolua_export
    
private:
    bool isOpen;

public:
	HoleTile(Map *map, const Vector &worldPosition);
	~HoleTile();

	virtual void render(double edt, bool selection, int modelsToRender);
	virtual void update(double dt);
    virtual void renderOrtho();    
    
    bool blocksLineOfSight();
    bool isPassable();
    
    void open(); // tolua_export
    void close(); // tolua_export
    
}; // tolua_export

#endif // __holetile__
