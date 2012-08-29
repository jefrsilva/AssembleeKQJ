#ifndef __globalconstants__
#define __globalconstants__

#include <cmath>

// const double M_PI = 3.141592653589793238462643;

const int RENDER_FLOOR = 1;
const int RENDER_WALL = 2;
const int RENDER_CEILING = 4;

const double TILE_SIZE = 8.0;
const double HALF_TILE = 4.0;

const double ITEM_SIZE = 1.0;

const int ITEM_TYPE_OTHER      = 0;
const int ITEM_TYPE_SWORD      = 1;
const int ITEM_TYPE_SPEAR      = 2;
const int ITEM_TYPE_AXE        = 3;
const int ITEM_TYPE_BOW        = 4;
const int ITEM_TYPE_SHIELD     = 5;
const int ITEM_TYPE_CONSUMABLE = 6;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

const int DIR_FORWARD      = 0;
const int DIR_STRAFE_RIGHT = 1;
const int DIR_BACKWARDS    = 2;
const int DIR_STRAFE_LEFT  = 3;
const int DIR_CCLOCKWISE   = -1;
const int DIR_CLOCKWISE    = 1;

const double WALK_SPEED = 250.0;

const int MAX_INVENTORY_SLOTS = 20;

const double INVENTORY_SLOT_SIZE = 1.0 / 24.0;

const int ALIGN_LEFT   = 0;
const int ALIGN_CENTER = 1;
const int ALIGN_RIGHT  = 2;

const int FONT_OFFSETS[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                             1, 3, 1, 0, 1, 1, 1, 3, 2, 2, 3, 2, 3, 2, 3, 1,
                             1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 0, 3, 3, 2,
                             1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                             1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1, 0,
                             3, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 3, 1, 1, 1,
                             1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 3, 2, 2
                           };

const int FONT_WIDTHS[] = { 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
                            6, 6, 6, 6, 6, 6, 7, 7, 8, 7, 7, 7, 8, 8, 8, 8,
                            6, 2, 5, 7, 6, 6, 6, 2, 4, 4, 3, 4, 2, 4, 2, 6,
                            6, 4, 6, 6, 6, 6, 6, 6, 6, 6, 2, 2, 7, 4, 4, 6,
                            6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
                            6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 4, 6, 4, 5, 8,
                            3, 6, 6, 6, 6, 6, 6, 6, 6, 2, 6, 6, 2, 6, 6, 6,
                            6, 7, 6, 6, 6, 6, 6, 6, 6, 6, 6, 4, 1, 4, 4
                          };

const double TOOLTIP_BORDER = 1.0 / 48.0;

const int TILE_WALL           = 0;
const int TILE_FLOOR          = 1;
const int TILE_DOOR           = 2;
const int TILE_SECRET_WALL    = 3;
const int TILE_HOLE           = 4;
const int TILE_PRESSURE_PLATE = 5;
const int TILE_TRANSITION     = 6;

const int SEL_OBJ_NONE           = -1;
const int SEL_OBJ_ITEM           =  0;
const int SEL_OBJ_MONSTER        =  1;
const int SEL_OBJ_DOOR           =  2;
const int SEL_OBJ_PRESSURE_PLATE =  3;

const double CURSOR_SIZE = 1.0 / 24.0;

const unsigned int MOUSE_BUTTON_LEFT = 0;
const unsigned int MOUSE_BUTTON_RIGHT = 1;

const double MONSTER_SIZE = 4.0;

const int ALPHAOBJECT_TYPE_NONE = -1;
const int ALPHAOBJECT_TYPE_ITEM = 0;
const int ALPHAOBJECT_TYPE_MONSTER = 1;
const int ALPHAOBJECT_TYPE_PARTICLE = 2;

const int TURN_FREE = 0;
const int TURN_PLAYER = 1;
const int TURN_ENEMY = 2;

const int FACTION_HOSTILE  = -1;
const int FACTION_NEUTRAL  =  0;
const int FACTION_FRIENDLY =  1;

const int MAP_STATE_HIDDEN      = 0;
const int MAP_STATE_TRANSPARENT = 1;
const int MAP_STATE_OPAQUE      = 2;

const double SHAKE_SPEED = (24.0 * M_PI) / 1000.0;


// TEXTURE RELATED CONSTANTS
// ---------------------------------------------------------------------------
const double TEX_IMAGE_TILE_WIDTH  = 128.0;
const double TEX_IMAGE_TILE_HEIGHT = 256.0;

const double TEX_IMAGE_MAP_WIDTH  = 128.0;
const double TEX_IMAGE_MAP_HEIGHT = 128.0;

const double TEX_TILE_WIDTH  = 16.0;
const double TEX_TILE_HEIGHT = 16.0;

const double TEX_IMAGE_ITEM_WIDTH = 128.0;
const double TEX_IMAGE_ITEM_HEIGHT = 128.0;

const double TEX_IMAGE_UI_WIDTH = 64.0;
const double TEX_IMAGE_UI_HEIGHT = 64.0;

const double TEX_CURSOR_WIDTH = 16.0;
const double TEX_CURSOR_HEIGHT = 16.0;

const double TEX_IMAGE_MONSTERS_WIDTH = 128.0;
const double TEX_IMAGE_MONSTERS_HEIGHT = 256.0;

const double TEX_MONSTERS_WIDTH = 8.0;
const double TEX_MONSTERS_HEIGHT = 8.0;

const double TEX_IMAGE_FONT_WIDTH  = 128.0;
const double TEX_IMAGE_FONT_HEIGHT = 256.0;

const double TEX_FONT_WIDTH  = 8.0;
const double TEX_FONT_HEIGHT = 8.0;

const double TEX_IMAGE_PARTICLE_WIDTH = 128.0;
const double TEX_IMAGE_PARTICLE_HEIGHT = 128.0;

const double TEX_PARTICLE_WIDTH = 8.0;
const double TEX_PARTICLE_HEIGHT = 8.0;

#endif // __globalconstants__
