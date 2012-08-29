#ifndef __walltile__
#define __walltile__

#include "Tile.h"

/**
 * \class WallTile
 * \author Jeferson Rodrigues da Silva
 * \date 12/20/2009
 * \file WallTile.h
 * \brief 
 */
class WallTile : public Tile {

public:
	WallTile(Map *map, const Vector &worldPosition);
	~WallTile();

	virtual void render(double edt, bool selection, int modelsToRender);
	virtual void update(double dt);
    virtual void renderOrtho();    
    
    bool blocksLineOfSight();
    bool isPassable();
    
};

#endif // __walltile__
