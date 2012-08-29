/*
** Lua binding: Item
** Generated automatically by tolua++-1.0.92 on Fri Jan  8 21:07:16 2010.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_Item_open (lua_State* tolua_S);

#include "Item.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Defense");
 tolua_usertype(tolua_S,"Item");
 tolua_usertype(tolua_S,"Attack");
}

/* method: setName of class  Item */
#ifndef TOLUA_DISABLE_tolua_Item_Item_setName00
static int tolua_Item_Item_setName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Item",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Item* self = (Item*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setTexture of class  Item */
#ifndef TOLUA_DISABLE_tolua_Item_Item_setTexture00
static int tolua_Item_Item_setTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Item",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Item* self = (Item*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setType of class  Item */
#ifndef TOLUA_DISABLE_tolua_Item_Item_setType00
static int tolua_Item_Item_setType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Item",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Item* self = (Item*)  tolua_tousertype(tolua_S,1,0);
  int type = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setType'", NULL);
#endif
  {
   self->setType(type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addAttack of class  Item */
#ifndef TOLUA_DISABLE_tolua_Item_Item_addAttack00
static int tolua_Item_Item_addAttack00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Item",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Attack",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Item* self = (Item*)  tolua_tousertype(tolua_S,1,0);
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

/* method: addDefense of class  Item */
#ifndef TOLUA_DISABLE_tolua_Item_Item_addDefense00
static int tolua_Item_Item_addDefense00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Item",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Defense",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Item* self = (Item*)  tolua_tousertype(tolua_S,1,0);
  const Defense* defense = ((const Defense*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addDefense'", NULL);
#endif
  {
   self->addDefense(*defense);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addDefense'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setToughness of class  Item */
#ifndef TOLUA_DISABLE_tolua_Item_Item_setToughness00
static int tolua_Item_Item_setToughness00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Item",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Item* self = (Item*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setDurability of class  Item */
#ifndef TOLUA_DISABLE_tolua_Item_Item_setDurability00
static int tolua_Item_Item_setDurability00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Item",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Item* self = (Item*)  tolua_tousertype(tolua_S,1,0);
  int durability = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDurability'", NULL);
#endif
  {
   self->setDurability(durability);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDurability'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDelay of class  Item */
#ifndef TOLUA_DISABLE_tolua_Item_Item_setDelay00
static int tolua_Item_Item_setDelay00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Item",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Item* self = (Item*)  tolua_tousertype(tolua_S,1,0);
  int delay = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDelay'", NULL);
#endif
  {
   self->setDelay(delay);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDelay'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setWeight of class  Item */
#ifndef TOLUA_DISABLE_tolua_Item_Item_setWeight00
static int tolua_Item_Item_setWeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Item",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Item* self = (Item*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setDescription of class  Item */
#ifndef TOLUA_DISABLE_tolua_Item_Item_setDescription00
static int tolua_Item_Item_setDescription00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Item",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Item* self = (Item*)  tolua_tousertype(tolua_S,1,0);
  std::string description = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDescription'", NULL);
#endif
  {
   self->setDescription(description);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDescription'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setConsumed of class  Item */
#ifndef TOLUA_DISABLE_tolua_Item_Item_setConsumed00
static int tolua_Item_Item_setConsumed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Item",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Item* self = (Item*)  tolua_tousertype(tolua_S,1,0);
  bool consumed = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setConsumed'", NULL);
#endif
  {
   self->setConsumed(consumed);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setConsumed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_Item_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"Item","Item","",NULL);
  tolua_beginmodule(tolua_S,"Item");
   tolua_function(tolua_S,"setName",tolua_Item_Item_setName00);
   tolua_function(tolua_S,"setTexture",tolua_Item_Item_setTexture00);
   tolua_function(tolua_S,"setType",tolua_Item_Item_setType00);
   tolua_function(tolua_S,"addAttack",tolua_Item_Item_addAttack00);
   tolua_function(tolua_S,"addDefense",tolua_Item_Item_addDefense00);
   tolua_function(tolua_S,"setToughness",tolua_Item_Item_setToughness00);
   tolua_function(tolua_S,"setDurability",tolua_Item_Item_setDurability00);
   tolua_function(tolua_S,"setDelay",tolua_Item_Item_setDelay00);
   tolua_function(tolua_S,"setWeight",tolua_Item_Item_setWeight00);
   tolua_function(tolua_S,"setDescription",tolua_Item_Item_setDescription00);
   tolua_function(tolua_S,"setConsumed",tolua_Item_Item_setConsumed00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Item (lua_State* tolua_S) {
 return tolua_Item_open(tolua_S);
}
#endif

