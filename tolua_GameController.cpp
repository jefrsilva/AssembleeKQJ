/*
** Lua binding: GameController
** Generated automatically by tolua++-1.0.92 on Sat Jan  9 23:55:16 2010.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_GameController_open (lua_State* tolua_S);

#include "GameController.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Map");
 tolua_usertype(tolua_S,"Player");
 tolua_usertype(tolua_S,"Item");
 tolua_usertype(tolua_S,"Monster");
 tolua_usertype(tolua_S,"GameController");
}

/* method: getPlayer of class  GameController */
#ifndef TOLUA_DISABLE_tolua_GameController_GameController_getPlayer00
static int tolua_GameController_GameController_getPlayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameController",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameController* self = (GameController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPlayer'", NULL);
#endif
  {
   Player* tolua_ret = (Player*)  self->getPlayer();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Player");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPlayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMap of class  GameController */
#ifndef TOLUA_DISABLE_tolua_GameController_GameController_getMap00
static int tolua_GameController_GameController_getMap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameController",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameController* self = (GameController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMap'", NULL);
#endif
  {
   Map* tolua_ret = (Map*)  self->getMap();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Map");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setGlobalVar of class  GameController */
#ifndef TOLUA_DISABLE_tolua_GameController_GameController_setGlobalVar00
static int tolua_GameController_GameController_setGlobalVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameController",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameController* self = (GameController*)  tolua_tousertype(tolua_S,1,0);
  std::string varName = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  int varValue = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setGlobalVar'", NULL);
#endif
  {
   self->setGlobalVar(varName,varValue);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setGlobalVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getGlobalVar of class  GameController */
#ifndef TOLUA_DISABLE_tolua_GameController_GameController_getGlobalVar00
static int tolua_GameController_GameController_getGlobalVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameController",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameController* self = (GameController*)  tolua_tousertype(tolua_S,1,0);
  std::string varName = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getGlobalVar'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getGlobalVar(varName);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getGlobalVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pause of class  GameController */
#ifndef TOLUA_DISABLE_tolua_GameController_GameController_pause00
static int tolua_GameController_GameController_pause00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameController",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameController* self = (GameController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pause'", NULL);
#endif
  {
   self->pause();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pause'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resume of class  GameController */
#ifndef TOLUA_DISABLE_tolua_GameController_GameController_resume00
static int tolua_GameController_GameController_resume00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameController",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameController* self = (GameController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resume'", NULL);
#endif
  {
   self->resume();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resume'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: returnToMenu of class  GameController */
#ifndef TOLUA_DISABLE_tolua_GameController_GameController_returnToMenu00
static int tolua_GameController_GameController_returnToMenu00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameController",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameController* self = (GameController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'returnToMenu'", NULL);
#endif
  {
   self->returnToMenu();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'returnToMenu'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fadeInMapMusic of class  GameController */
#ifndef TOLUA_DISABLE_tolua_GameController_GameController_fadeInMapMusic00
static int tolua_GameController_GameController_fadeInMapMusic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameController",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameController* self = (GameController*)  tolua_tousertype(tolua_S,1,0);
  std::string mapID = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  int duration = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fadeInMapMusic'", NULL);
#endif
  {
   self->fadeInMapMusic(mapID,duration);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fadeInMapMusic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fadeOutMusic of class  GameController */
#ifndef TOLUA_DISABLE_tolua_GameController_GameController_fadeOutMusic00
static int tolua_GameController_GameController_fadeOutMusic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameController",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameController* self = (GameController*)  tolua_tousertype(tolua_S,1,0);
  int duration = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fadeOutMusic'", NULL);
#endif
  {
   self->fadeOutMusic(duration);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fadeOutMusic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFadeColor of class  GameController */
#ifndef TOLUA_DISABLE_tolua_GameController_GameController_setFadeColor00
static int tolua_GameController_GameController_setFadeColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameController",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameController* self = (GameController*)  tolua_tousertype(tolua_S,1,0);
  double r = ((double)  tolua_tonumber(tolua_S,2,0));
  double g = ((double)  tolua_tonumber(tolua_S,3,0));
  double b = ((double)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFadeColor'", NULL);
#endif
  {
   self->setFadeColor(r,g,b);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFadeColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fadeIn of class  GameController */
#ifndef TOLUA_DISABLE_tolua_GameController_GameController_fadeIn00
static int tolua_GameController_GameController_fadeIn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameController",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameController* self = (GameController*)  tolua_tousertype(tolua_S,1,0);
  double duration = ((double)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fadeIn'", NULL);
#endif
  {
   self->fadeIn(duration);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fadeIn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fadeOut of class  GameController */
#ifndef TOLUA_DISABLE_tolua_GameController_GameController_fadeOut00
static int tolua_GameController_GameController_fadeOut00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameController",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameController* self = (GameController*)  tolua_tousertype(tolua_S,1,0);
  double duration = ((double)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fadeOut'", NULL);
#endif
  {
   self->fadeOut(duration);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fadeOut'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: playerGiveItem of class  GameController */
#ifndef TOLUA_DISABLE_tolua_GameController_GameController_playerGiveItem00
static int tolua_GameController_GameController_playerGiveItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameController",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Item",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameController* self = (GameController*)  tolua_tousertype(tolua_S,1,0);
  Item* item = ((Item*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'playerGiveItem'", NULL);
#endif
  {
   self->playerGiveItem(item);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'playerGiveItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: playerHasItem of class  GameController */
#ifndef TOLUA_DISABLE_tolua_GameController_GameController_playerHasItem00
static int tolua_GameController_GameController_playerHasItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameController",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameController* self = (GameController*)  tolua_tousertype(tolua_S,1,0);
  std::string itemID = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'playerHasItem'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->playerHasItem(itemID);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'playerHasItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: healPlayer of class  GameController */
#ifndef TOLUA_DISABLE_tolua_GameController_GameController_healPlayer00
static int tolua_GameController_GameController_healPlayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameController",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameController* self = (GameController*)  tolua_tousertype(tolua_S,1,0);
  int amount = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'healPlayer'", NULL);
#endif
  {
   self->healPlayer(amount);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'healPlayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: increaseMaxHealth of class  GameController */
#ifndef TOLUA_DISABLE_tolua_GameController_GameController_increaseMaxHealth00
static int tolua_GameController_GameController_increaseMaxHealth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameController",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameController* self = (GameController*)  tolua_tousertype(tolua_S,1,0);
  int amount = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'increaseMaxHealth'", NULL);
#endif
  {
   self->increaseMaxHealth(amount);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'increaseMaxHealth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPlayerDirection of class  GameController */
#ifndef TOLUA_DISABLE_tolua_GameController_GameController_setPlayerDirection00
static int tolua_GameController_GameController_setPlayerDirection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameController",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameController* self = (GameController*)  tolua_tousertype(tolua_S,1,0);
  int direction = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPlayerDirection'", NULL);
#endif
  {
   self->setPlayerDirection(direction);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPlayerDirection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPlayerLocation of class  GameController */
#ifndef TOLUA_DISABLE_tolua_GameController_GameController_setPlayerLocation00
static int tolua_GameController_GameController_setPlayerLocation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameController",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameController* self = (GameController*)  tolua_tousertype(tolua_S,1,0);
  std::string mapName = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  int row = ((int)  tolua_tonumber(tolua_S,3,0));
  int col = ((int)  tolua_tonumber(tolua_S,4,0));
  int direction = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPlayerLocation'", NULL);
#endif
  {
   self->setPlayerLocation(mapName,row,col,direction);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPlayerLocation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadMap of class  GameController */
#ifndef TOLUA_DISABLE_tolua_GameController_GameController_loadMap00
static int tolua_GameController_GameController_loadMap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameController",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameController* self = (GameController*)  tolua_tousertype(tolua_S,1,0);
  std::string mapID = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadMap'", NULL);
#endif
  {
   self->loadMap(mapID);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadMap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: playMusic of class  GameController */
#ifndef TOLUA_DISABLE_tolua_GameController_GameController_playMusic00
static int tolua_GameController_GameController_playMusic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameController",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameController* self = (GameController*)  tolua_tousertype(tolua_S,1,0);
  std::string musicID = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'playMusic'", NULL);
#endif
  {
   self->playMusic(musicID);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'playMusic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: playSound of class  GameController */
#ifndef TOLUA_DISABLE_tolua_GameController_GameController_playSound00
static int tolua_GameController_GameController_playSound00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameController",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameController* self = (GameController*)  tolua_tousertype(tolua_S,1,0);
  std::string soundID = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'playSound'", NULL);
#endif
  {
   self->playSound(soundID);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'playSound'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: newMonster of class  GameController */
#ifndef TOLUA_DISABLE_tolua_GameController_GameController_newMonster00
static int tolua_GameController_GameController_newMonster00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameController",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameController* self = (GameController*)  tolua_tousertype(tolua_S,1,0);
  std::string monsterID = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  std::string instanceID = ((std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'newMonster'", NULL);
#endif
  {
   Monster* tolua_ret = (Monster*)  self->newMonster(monsterID,instanceID);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Monster");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'newMonster'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: newItem of class  GameController */
#ifndef TOLUA_DISABLE_tolua_GameController_GameController_newItem00
static int tolua_GameController_GameController_newItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameController",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameController* self = (GameController*)  tolua_tousertype(tolua_S,1,0);
  std::string itemID = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'newItem'", NULL);
#endif
  {
   Item* tolua_ret = (Item*)  self->newItem(itemID);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Item");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'newItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createTextWindow of class  GameController */
#ifndef TOLUA_DISABLE_tolua_GameController_GameController_createTextWindow00
static int tolua_GameController_GameController_createTextWindow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameController",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameController* self = (GameController*)  tolua_tousertype(tolua_S,1,0);
  double x = ((double)  tolua_tonumber(tolua_S,2,0));
  double y = ((double)  tolua_tonumber(tolua_S,3,0));
  std::string text = ((std::string)  tolua_tocppstring(tolua_S,4,0));
  int width = ((int)  tolua_tonumber(tolua_S,5,0));
  bool blocking = ((bool)  tolua_toboolean(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createTextWindow'", NULL);
#endif
  {
   self->createTextWindow(x,y,text,width,blocking);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createTextWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createTextWindow of class  GameController */
#ifndef TOLUA_DISABLE_tolua_GameController_GameController_createTextWindow01
static int tolua_GameController_GameController_createTextWindow01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameController",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Monster",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GameController* self = (GameController*)  tolua_tousertype(tolua_S,1,0);
  Monster* monster = ((Monster*)  tolua_tousertype(tolua_S,2,0));
  std::string text = ((std::string)  tolua_tocppstring(tolua_S,3,0));
  int width = ((int)  tolua_tonumber(tolua_S,4,0));
  bool blocking = ((bool)  tolua_toboolean(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createTextWindow'", NULL);
#endif
  {
   self->createTextWindow(monster,text,width,blocking);
  }
 }
 return 0;
tolua_lerror:
 return tolua_GameController_GameController_createTextWindow00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: createTutorialWindow of class  GameController */
#ifndef TOLUA_DISABLE_tolua_GameController_GameController_createTutorialWindow00
static int tolua_GameController_GameController_createTutorialWindow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameController",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameController* self = (GameController*)  tolua_tousertype(tolua_S,1,0);
  std::string text = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createTutorialWindow'", NULL);
#endif
  {
   self->createTutorialWindow(text);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createTutorialWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearTutorialWindow of class  GameController */
#ifndef TOLUA_DISABLE_tolua_GameController_GameController_clearTutorialWindow00
static int tolua_GameController_GameController_clearTutorialWindow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameController",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameController* self = (GameController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearTutorialWindow'", NULL);
#endif
  {
   self->clearTutorialWindow();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearTutorialWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_GameController_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"GameController","GameController","",NULL);
  tolua_beginmodule(tolua_S,"GameController");
   tolua_function(tolua_S,"getPlayer",tolua_GameController_GameController_getPlayer00);
   tolua_function(tolua_S,"getMap",tolua_GameController_GameController_getMap00);
   tolua_function(tolua_S,"setGlobalVar",tolua_GameController_GameController_setGlobalVar00);
   tolua_function(tolua_S,"getGlobalVar",tolua_GameController_GameController_getGlobalVar00);
   tolua_function(tolua_S,"pause",tolua_GameController_GameController_pause00);
   tolua_function(tolua_S,"resume",tolua_GameController_GameController_resume00);
   tolua_function(tolua_S,"returnToMenu",tolua_GameController_GameController_returnToMenu00);
   tolua_function(tolua_S,"fadeInMapMusic",tolua_GameController_GameController_fadeInMapMusic00);
   tolua_function(tolua_S,"fadeOutMusic",tolua_GameController_GameController_fadeOutMusic00);
   tolua_function(tolua_S,"setFadeColor",tolua_GameController_GameController_setFadeColor00);
   tolua_function(tolua_S,"fadeIn",tolua_GameController_GameController_fadeIn00);
   tolua_function(tolua_S,"fadeOut",tolua_GameController_GameController_fadeOut00);
   tolua_function(tolua_S,"playerGiveItem",tolua_GameController_GameController_playerGiveItem00);
   tolua_function(tolua_S,"playerHasItem",tolua_GameController_GameController_playerHasItem00);
   tolua_function(tolua_S,"healPlayer",tolua_GameController_GameController_healPlayer00);
   tolua_function(tolua_S,"increaseMaxHealth",tolua_GameController_GameController_increaseMaxHealth00);
   tolua_function(tolua_S,"setPlayerDirection",tolua_GameController_GameController_setPlayerDirection00);
   tolua_function(tolua_S,"setPlayerLocation",tolua_GameController_GameController_setPlayerLocation00);
   tolua_function(tolua_S,"loadMap",tolua_GameController_GameController_loadMap00);
   tolua_function(tolua_S,"playMusic",tolua_GameController_GameController_playMusic00);
   tolua_function(tolua_S,"playSound",tolua_GameController_GameController_playSound00);
   tolua_function(tolua_S,"newMonster",tolua_GameController_GameController_newMonster00);
   tolua_function(tolua_S,"newItem",tolua_GameController_GameController_newItem00);
   tolua_function(tolua_S,"createTextWindow",tolua_GameController_GameController_createTextWindow00);
   tolua_function(tolua_S,"createTextWindow",tolua_GameController_GameController_createTextWindow01);
   tolua_function(tolua_S,"createTutorialWindow",tolua_GameController_GameController_createTutorialWindow00);
   tolua_function(tolua_S,"clearTutorialWindow",tolua_GameController_GameController_clearTutorialWindow00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_GameController (lua_State* tolua_S) {
 return tolua_GameController_open(tolua_S);
}
#endif

