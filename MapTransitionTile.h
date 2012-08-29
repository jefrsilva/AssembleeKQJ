#ifndef __maptransitiontile__
#define __maptransitiontile__

#include "Tile.h"

/**
 * \class MapTransitionTile
 * \author Jeferson Rodrigues da Silva
 * \date 01/03/2010
 * \file MapTransitionTile.h
 * \brief 
 */
class MapTransitionTile : public Tile {
    
private:
    int direction;

public:
	MapTransitionTile(Map *map, const Vector &worldPosition, int direction);
	~MapTransitionTile();

	virtual void render(double edt, bool selection, int modelsToRender);
	virtual void update(double dt);
    virtual void renderOrtho();    
    
};

#endif // __maptransitiontile__
