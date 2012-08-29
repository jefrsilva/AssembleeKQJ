#ifndef __secretwalltile__
#define __secretwalltile__

#include "Tile.h"

/**
 * \class SecretWallTile
 * \author Jeferson Rodrigues da Silva
 * \date 12/21/2009
 * \file SecretWallTile.h
 * \brief 
 */
class SecretWallTile : public Tile {

public:
	SecretWallTile(Map *map, const Vector &worldPosition);
	~SecretWallTile();

	virtual void render(double edt, bool selection, int modelsToRender);
	virtual void update(double dt);
    virtual void renderOrtho();    
    
    bool blocksLineOfSight();
    
};

#endif // __secretwalltile__
