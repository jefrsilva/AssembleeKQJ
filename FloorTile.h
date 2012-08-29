#ifndef __floortile__
#define __floortile__

#include "Tile.h"

/**
 * \class FloorTile
 * \author Jeferson Rodrigues da Silva
 * \date 12/20/2009
 * \file FloorTile.h
 * \brief 
 */
class FloorTile : public Tile {

public:
	FloorTile(Map *map, const Vector &worldPosition);
	~FloorTile();

	virtual void render(double edt, bool selection, int modelsToRender);
	virtual void update(double dt);
    virtual void renderOrtho();    
    
};

#endif // __floortile__
