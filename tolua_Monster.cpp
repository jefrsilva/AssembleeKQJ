/*
** Lua binding: Monster
** Generated automatically by tolua++-1.0.92 on Tue Jan  5 12:37:08 2010.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_Monster_open (lua_State* tolua_S);

#include "Monster.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Monster");
 tolua_usertype(tolua_S,"Defense");
 tolua_usertype(tolua_S,"Attack");
}

/* method: setTexture of class  Monster */
#ifndef TOLUA_DISABLE_tolua_Monster_Monster_setTexture00
static int tolua_Monster_Monster_setTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Monster",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Monster* self = (Monster*)  tolua_tousertype(tolua_S,1,0);
  int texture = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTexture'", NULL);
#endif
  {
   self->setTexture(texture);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addAttack of class  Monster */
#ifndef TOLUA_DISABLE_tolua_Monster_Monster_addAttack00
static int tolua_Monster_Monster_addAttack00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Monster",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Attack",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Monster* self = (Monster*)  tolua_tousertype(tolua_S,1,0);
  const Attack* attack = ((const Attack*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addAttack'", NULL);
#endif
  {
   self->addAttack(*attack);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addAttack'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDefense of class  Monster */
#ifndef TOLUA_DISABLE_tolua_Monster_Monster_setDefense00
static int tolua_Monster_Monster_setDefense00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Monster",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Defense",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Monster* self = (Monster*)  tolua_tousertype(tolua_S,1,0);
  const Defense* defense = ((const Defense*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDefense'", NULL);
#endif
  {
   self->setDefense(*defense);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDefense'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setName of class  Monster */
#ifndef TOLUA_DISABLE_tolua_Monster_Monster_setName00
static int tolua_Monster_Monster_setName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Monster",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Monster* self = (Monster*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setMaxHealth of class  Monster */
#ifndef TOLUA_DISABLE_tolua_Monster_Monster_setMaxHealth00
static int tolua_Monster_Monster_setMaxHealth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Monster",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Monster* self = (Monster*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setHealth of class  Monster */
#ifndef TOLUA_DISABLE_tolua_Monster_Monster_setHealth00
static int tolua_Monster_Monster_setHealth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Monster",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Monster* self = (Monster*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setToughness of class  Monster */
#ifndef TOLUA_DISABLE_tolua_Monster_Monster_setToughness00
static int tolua_Monster_Monster_setToughness00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Monster",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Monster* self = (Monster*)  tolua_tousertype(tolua_S,1,0);
  int toughness = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setToughness'", NULL);
#endif
  {
   self->setToughness(toughness);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setToughness'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSize of class  Monster */
#ifndef TOLUA_DISABLE_tolua_Monster_Monster_setSize00
static int tolua_Monster_Monster_setSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Monster",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Monster* self = (Monster*)  tolua_tousertype(tolua_S,1,0);
  int size = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSize'", NULL);
#endif
  {
   self->setSize(size);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setWeight of class  Monster */
#ifndef TOLUA_DISABLE_tolua_Monster_Monster_setWeight00
static int tolua_Monster_Monster_setWeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Monster",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Monster* self = (Monster*)  tolua_tousertype(tolua_S,1,0);
  int weight = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setWeight'", NULL);
#endif
  {
   self->setWeight(weight);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setWeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setActivationRange of class  Monster */
#ifndef TOLUA_DISABLE_tolua_Monster_Monster_setActivationRange00
static int tolua_Monster_Monster_setActivationRange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Monster",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Monster* self = (Monster*)  tolua_tousertype(tolua_S,1,0);
  int range = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setActivationRange'", NULL);
#endif
  {
   self->setActivationRange(range);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setActivationRange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRangedAttacker of class  Monster */
#ifndef TOLUA_DISABLE_tolua_Monster_Monster_setRangedAttacker00
static int tolua_Monster_Monster_setRangedAttacker00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Monster",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Monster* self = (Monster*)  tolua_tousertype(tolua_S,1,0);
  bool ranged = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRangedAttacker'", NULL);
#endif
  {
   self->setRangedAttacker(ranged);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRangedAttacker'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addItemDrop of class  Monster */
#ifndef TOLUA_DISABLE_tolua_Monster_Monster_addItemDrop00
static int tolua_Monster_Monster_addItemDrop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Monster",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Monster* self = (Monster*)  tolua_tousertype(tolua_S,1,0);
  std::string itemID = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addItemDrop'", NULL);
#endif
  {
   self->addItemDrop(itemID);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addItemDrop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFaction of class  Monster */
#ifndef TOLUA_DISABLE_tolua_Monster_Monster_setFaction00
static int tolua_Monster_Monster_setFaction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Monster",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Monster* self = (Monster*)  tolua_tousertype(tolua_S,1,0);
  std::string faction = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFaction'", NULL);
#endif
  {
   self->setFaction(faction);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFaction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_Monster_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"Monster","Monster","",NULL);
  tolua_beginmodule(tolua_S,"Monster");
   tolua_function(tolua_S,"setTexture",tolua_Monster_Monster_setTexture00);
   tolua_function(tolua_S,"addAttack",tolua_Monster_Monster_addAttack00);
   tolua_function(tolua_S,"setDefense",tolua_Monster_Monster_setDefense00);
   tolua_function(tolua_S,"setName",tolua_Monster_Monster_setName00);
   tolua_function(tolua_S,"setMaxHealth",tolua_Monster_Monster_setMaxHealth00);
   tolua_function(tolua_S,"setHealth",tolua_Monster_Monster_setHealth00);
   tolua_function(tolua_S,"setToughness",tolua_Monster_Monster_setToughness00);
   tolua_function(tolua_S,"setSize",tolua_Monster_Monster_setSize00);
   tolua_function(tolua_S,"setWeight",tolua_Monster_Monster_setWeight00);
   tolua_function(tolua_S,"setActivationRange",tolua_Monster_Monster_setActivationRange00);
   tolua_function(tolua_S,"setRangedAttacker",tolua_Monster_Monster_setRangedAttacker00);
   tolua_function(tolua_S,"addItemDrop",tolua_Monster_Monster_addItemDrop00);
   tolua_function(tolua_S,"setFaction",tolua_Monster_Monster_setFaction00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Monster (lua_State* tolua_S) {
 return tolua_Monster_open(tolua_S);
}
#endif

