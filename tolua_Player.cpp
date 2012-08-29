/*
** Lua binding: Player
** Generated automatically by tolua++-1.0.92 on Fri Jan  8 21:09:57 2010.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_Player_open (lua_State* tolua_S);

#include "Player.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Item");
 tolua_usertype(tolua_S,"Player");
}

/* method: addItem of class  Player */
#ifndef TOLUA_DISABLE_tolua_Player_Player_addItem00
static int tolua_Player_Player_addItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Player",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Item",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Player* self = (Player*)  tolua_tousertype(tolua_S,1,0);
  Item* item = ((Item*)  tolua_tousertype(tolua_S,2,0));
  int slot = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addItem'", NULL);
#endif
  {
   self->addItem(item,slot);
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

/* method: setHealth of class  Player */
#ifndef TOLUA_DISABLE_tolua_Player_Player_setHealth00
static int tolua_Player_Player_setHealth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Player",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Player* self = (Player*)  tolua_tousertype(tolua_S,1,0);
  int health = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setHealth'", NULL);
#endif
  {
   self->setHealth(health);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setHealth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getHealth of class  Player */
#ifndef TOLUA_DISABLE_tolua_Player_Player_getHealth00
static int tolua_Player_Player_getHealth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Player",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Player* self = (Player*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHealth'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getHealth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHealth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMaxHealth of class  Player */
#ifndef TOLUA_DISABLE_tolua_Player_Player_setMaxHealth00
static int tolua_Player_Player_setMaxHealth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Player",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Player* self = (Player*)  tolua_tousertype(tolua_S,1,0);
  int maxHealth = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMaxHealth'", NULL);
#endif
  {
   self->setMaxHealth(maxHealth);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMaxHealth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMaxHealth of class  Player */
#ifndef TOLUA_DISABLE_tolua_Player_Player_getMaxHealth00
static int tolua_Player_Player_getMaxHealth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Player",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Player* self = (Player*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMaxHealth'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getMaxHealth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMaxHealth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFactionStance of class  Player */
#ifndef TOLUA_DISABLE_tolua_Player_Player_setFactionStance00
static int tolua_Player_Player_setFactionStance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Player",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Player* self = (Player*)  tolua_tousertype(tolua_S,1,0);
  std::string faction = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  int stance = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFactionStance'", NULL);
#endif
  {
   self->setFactionStance(faction,stance);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFactionStance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFactionStance of class  Player */
#ifndef TOLUA_DISABLE_tolua_Player_Player_getFactionStance00
static int tolua_Player_Player_getFactionStance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Player",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Player* self = (Player*)  tolua_tousertype(tolua_S,1,0);
  std::string faction = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFactionStance'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getFactionStance(faction);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFactionStance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_Player_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"Player","Player","",NULL);
  tolua_beginmodule(tolua_S,"Player");
   tolua_function(tolua_S,"addItem",tolua_Player_Player_addItem00);
   tolua_function(tolua_S,"setHealth",tolua_Player_Player_setHealth00);
   tolua_function(tolua_S,"getHealth",tolua_Player_Player_getHealth00);
   tolua_function(tolua_S,"setMaxHealth",tolua_Player_Player_setMaxHealth00);
   tolua_function(tolua_S,"getMaxHealth",tolua_Player_Player_getMaxHealth00);
   tolua_function(tolua_S,"setFactionStance",tolua_Player_Player_setFactionStance00);
   tolua_function(tolua_S,"getFactionStance",tolua_Player_Player_getFactionStance00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Player (lua_State* tolua_S) {
 return tolua_Player_open(tolua_S);
}
#endif

