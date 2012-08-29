/*
** Lua binding: Map
** Generated automatically by tolua++-1.0.92 on Tue Jan  5 12:37:25 2010.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_Map_open (lua_State* tolua_S);

#include "Map.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Monster");
 tolua_usertype(tolua_S,"DoorTile");
 tolua_usertype(tolua_S,"Item");
 tolua_usertype(tolua_S,"PressurePlateTile");
 tolua_usertype(tolua_S,"HoleTile");
 tolua_usertype(tolua_S,"Map");
}

/* method: setName of class  Map */
#ifndef TOLUA_DISABLE_tolua_Map_Map_setName00
static int tolua_Map_Map_setName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Map",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Map* self = (Map*)  tolua_tousertype(tolua_S,1,0);
  std::string name = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setName'", NULL);
#endif
  {
   self->setName(name);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMusic of class  Map */
#ifndef TOLUA_DISABLE_tolua_Map_Map_setMusic00
static int tolua_Map_Map_setMusic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Map",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Map* self = (Map*)  tolua_tousertype(tolua_S,1,0);
  std::string music = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMusic'", NULL);
#endif
  {
   self->setMusic(music);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMusic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTileset of class  Map */
#ifndef TOLUA_DISABLE_tolua_Map_Map_setTileset00
static int tolua_Map_Map_setTileset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Map",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Map* self = (Map*)  tolua_tousertype(tolua_S,1,0);
  int tileset = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTileset'", NULL);
#endif
  {
   self->setTileset(tileset);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTileset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setCeilingHeight of class  Map */
#ifndef TOLUA_DISABLE_tolua_Map_Map_setCeilingHeight00
static int tolua_Map_Map_setCeilingHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Map",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Map* self = (Map*)  tolua_tousertype(tolua_S,1,0);
  double height = ((double)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCeilingHeight'", NULL);
#endif
  {
   self->setCeilingHeight(height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCeilingHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFloorReflection of class  Map */
#ifndef TOLUA_DISABLE_tolua_Map_Map_setFloorReflection00
static int tolua_Map_Map_setFloorReflection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Map",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Map* self = (Map*)  tolua_tousertype(tolua_S,1,0);
  bool reflection = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFloorReflection'", NULL);
#endif
  {
   self->setFloorReflection(reflection);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFloorReflection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFog of class  Map */
#ifndef TOLUA_DISABLE_tolua_Map_Map_setFog00
static int tolua_Map_Map_setFog00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Map",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Map* self = (Map*)  tolua_tousertype(tolua_S,1,0);
  double r = ((double)  tolua_tonumber(tolua_S,2,0));
  double g = ((double)  tolua_tonumber(tolua_S,3,0));
  double b = ((double)  tolua_tonumber(tolua_S,4,0));
  double density = ((double)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFog'", NULL);
#endif
  {
   self->setFog(r,g,b,density);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFog'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAmbientLight of class  Map */
#ifndef TOLUA_DISABLE_tolua_Map_Map_setAmbientLight00
static int tolua_Map_Map_setAmbientLight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Map",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Map* self = (Map*)  tolua_tousertype(tolua_S,1,0);
  double r = ((double)  tolua_tonumber(tolua_S,2,0));
  double g = ((double)  tolua_tonumber(tolua_S,3,0));
  double b = ((double)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAmbientLight'", NULL);
#endif
  {
   self->setAmbientLight(r,g,b);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAmbientLight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDiffuseLight of class  Map */
#ifndef TOLUA_DISABLE_tolua_Map_Map_setDiffuseLight00
static int tolua_Map_Map_setDiffuseLight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Map",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Map* self = (Map*)  tolua_tousertype(tolua_S,1,0);
  double r = ((double)  tolua_tonumber(tolua_S,2,0));
  double g = ((double)  tolua_tonumber(tolua_S,3,0));
  double b = ((double)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDiffuseLight'", NULL);
#endif
  {
   self->setDiffuseLight(r,g,b);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDiffuseLight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLightParams of class  Map */
#ifndef TOLUA_DISABLE_tolua_Map_Map_setLightParams00
static int tolua_Map_Map_setLightParams00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Map",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Map* self = (Map*)  tolua_tousertype(tolua_S,1,0);
  double constant = ((double)  tolua_tonumber(tolua_S,2,0));
  double linear = ((double)  tolua_tonumber(tolua_S,3,0));
  double quadratic = ((double)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLightParams'", NULL);
#endif
  {
   self->setLightParams(constant,linear,quadratic);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLightParams'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addItem of class  Map */
#ifndef TOLUA_DISABLE_tolua_Map_Map_addItem00
static int tolua_Map_Map_addItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Map",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Item",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Map* self = (Map*)  tolua_tousertype(tolua_S,1,0);
  Item* item = ((Item*)  tolua_tousertype(tolua_S,2,0));
  int row = ((int)  tolua_tonumber(tolua_S,3,0));
  int col = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addItem'", NULL);
#endif
  {
   self->addItem(item,row,col);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addMonster of class  Map */
#ifndef TOLUA_DISABLE_tolua_Map_Map_addMonster00
static int tolua_Map_Map_addMonster00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Map",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Monster",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Map* self = (Map*)  tolua_tousertype(tolua_S,1,0);
  Monster* monster = ((Monster*)  tolua_tousertype(tolua_S,2,0));
  int row = ((int)  tolua_tonumber(tolua_S,3,0));
  int col = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addMonster'", NULL);
#endif
  {
   self->addMonster(monster,row,col);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addMonster'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMonster of class  Map */
#ifndef TOLUA_DISABLE_tolua_Map_Map_getMonster00
static int tolua_Map_Map_getMonster00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Map",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Map* self = (Map*)  tolua_tousertype(tolua_S,1,0);
  std::string instanceID = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMonster'", NULL);
#endif
  {
   Monster* tolua_ret = (Monster*)  self->getMonster(instanceID);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Monster");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMonster'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDoorAt of class  Map */
#ifndef TOLUA_DISABLE_tolua_Map_Map_getDoorAt00
static int tolua_Map_Map_getDoorAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Map",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Map* self = (Map*)  tolua_tousertype(tolua_S,1,0);
  int row = ((int)  tolua_tonumber(tolua_S,2,0));
  int col = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDoorAt'", NULL);
#endif
  {
   DoorTile* tolua_ret = (DoorTile*)  self->getDoorAt(row,col);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"DoorTile");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDoorAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPressurePlateAt of class  Map */
#ifndef TOLUA_DISABLE_tolua_Map_Map_getPressurePlateAt00
static int tolua_Map_Map_getPressurePlateAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Map",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Map* self = (Map*)  tolua_tousertype(tolua_S,1,0);
  int row = ((int)  tolua_tonumber(tolua_S,2,0));
  int col = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPressurePlateAt'", NULL);
#endif
  {
   PressurePlateTile* tolua_ret = (PressurePlateTile*)  self->getPressurePlateAt(row,col);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"PressurePlateTile");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPressurePlateAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getHoleAt of class  Map */
#ifndef TOLUA_DISABLE_tolua_Map_Map_getHoleAt00
static int tolua_Map_Map_getHoleAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Map",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Map* self = (Map*)  tolua_tousertype(tolua_S,1,0);
  int row = ((int)  tolua_tonumber(tolua_S,2,0));
  int col = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHoleAt'", NULL);
#endif
  {
   HoleTile* tolua_ret = (HoleTile*)  self->getHoleAt(row,col);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"HoleTile");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHoleAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_Map_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"Map","Map","",NULL);
  tolua_beginmodule(tolua_S,"Map");
   tolua_function(tolua_S,"setName",tolua_Map_Map_setName00);
   tolua_function(tolua_S,"setMusic",tolua_Map_Map_setMusic00);
   tolua_function(tolua_S,"setTileset",tolua_Map_Map_setTileset00);
   tolua_function(tolua_S,"setCeilingHeight",tolua_Map_Map_setCeilingHeight00);
   tolua_function(tolua_S,"setFloorReflection",tolua_Map_Map_setFloorReflection00);
   tolua_function(tolua_S,"setFog",tolua_Map_Map_setFog00);
   tolua_function(tolua_S,"setAmbientLight",tolua_Map_Map_setAmbientLight00);
   tolua_function(tolua_S,"setDiffuseLight",tolua_Map_Map_setDiffuseLight00);
   tolua_function(tolua_S,"setLightParams",tolua_Map_Map_setLightParams00);
   tolua_function(tolua_S,"addItem",tolua_Map_Map_addItem00);
   tolua_function(tolua_S,"addMonster",tolua_Map_Map_addMonster00);
   tolua_function(tolua_S,"getMonster",tolua_Map_Map_getMonster00);
   tolua_function(tolua_S,"getDoorAt",tolua_Map_Map_getDoorAt00);
   tolua_function(tolua_S,"getPressurePlateAt",tolua_Map_Map_getPressurePlateAt00);
   tolua_function(tolua_S,"getHoleAt",tolua_Map_Map_getHoleAt00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Map (lua_State* tolua_S) {
 return tolua_Map_open(tolua_S);
}
#endif

