/*
** Lua binding: PressurePlateTile
** Generated automatically by tolua++-1.0.92 on Sat Jan  9 13:20:57 2010.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_PressurePlateTile_open (lua_State* tolua_S);

#include "PressurePlateTile.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Tile");
 tolua_usertype(tolua_S,"PressurePlateTile");
}

/* method: setState of class  PressurePlateTile */
#ifndef TOLUA_DISABLE_tolua_PressurePlateTile_PressurePlateTile_setState00
static int tolua_PressurePlateTile_PressurePlateTile_setState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"PressurePlateTile",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  PressurePlateTile* self = (PressurePlateTile*)  tolua_tousertype(tolua_S,1,0);
  bool activated = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setState'", NULL);
#endif
  {
   self->setState(activated);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isActivated of class  PressurePlateTile */
#ifndef TOLUA_DISABLE_tolua_PressurePlateTile_PressurePlateTile_isActivated00
static int tolua_PressurePlateTile_PressurePlateTile_isActivated00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"PressurePlateTile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  PressurePlateTile* self = (PressurePlateTile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isActivated'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isActivated();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isActivated'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setWeightThreshold of class  PressurePlateTile */
#ifndef TOLUA_DISABLE_tolua_PressurePlateTile_PressurePlateTile_setWeightThreshold00
static int tolua_PressurePlateTile_PressurePlateTile_setWeightThreshold00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"PressurePlateTile",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  PressurePlateTile* self = (PressurePlateTile*)  tolua_tousertype(tolua_S,1,0);
  int weightThreshold = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setWeightThreshold'", NULL);
#endif
  {
   self->setWeightThreshold(weightThreshold);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setWeightThreshold'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOnActivate of class  PressurePlateTile */
#ifndef TOLUA_DISABLE_tolua_PressurePlateTile_PressurePlateTile_setOnActivate00
static int tolua_PressurePlateTile_PressurePlateTile_setOnActivate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"PressurePlateTile",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  PressurePlateTile* self = (PressurePlateTile*)  tolua_tousertype(tolua_S,1,0);
  std::string onActivate = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOnActivate'", NULL);
#endif
  {
   self->setOnActivate(onActivate);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOnActivate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOnDeactivate of class  PressurePlateTile */
#ifndef TOLUA_DISABLE_tolua_PressurePlateTile_PressurePlateTile_setOnDeactivate00
static int tolua_PressurePlateTile_PressurePlateTile_setOnDeactivate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"PressurePlateTile",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  PressurePlateTile* self = (PressurePlateTile*)  tolua_tousertype(tolua_S,1,0);
  std::string onDeactivate = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOnDeactivate'", NULL);
#endif
  {
   self->setOnDeactivate(onDeactivate);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOnDeactivate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_PressurePlateTile_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"PressurePlateTile","PressurePlateTile","Tile",NULL);
  tolua_beginmodule(tolua_S,"PressurePlateTile");
   tolua_function(tolua_S,"setState",tolua_PressurePlateTile_PressurePlateTile_setState00);
   tolua_function(tolua_S,"isActivated",tolua_PressurePlateTile_PressurePlateTile_isActivated00);
   tolua_function(tolua_S,"setWeightThreshold",tolua_PressurePlateTile_PressurePlateTile_setWeightThreshold00);
   tolua_function(tolua_S,"setOnActivate",tolua_PressurePlateTile_PressurePlateTile_setOnActivate00);
   tolua_function(tolua_S,"setOnDeactivate",tolua_PressurePlateTile_PressurePlateTile_setOnDeactivate00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_PressurePlateTile (lua_State* tolua_S) {
 return tolua_PressurePlateTile_open(tolua_S);
}
#endif

