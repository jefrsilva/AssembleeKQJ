/*
** Lua binding: DoorTile
** Generated automatically by tolua++-1.0.92 on Tue Dec 29 18:23:53 2009.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_DoorTile_open (lua_State* tolua_S);

#include "DoorTile.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Tile");
 tolua_usertype(tolua_S,"DoorTile");
}

/* method: open of class  DoorTile */
#ifndef TOLUA_DISABLE_tolua_DoorTile_DoorTile_open00
static int tolua_DoorTile_DoorTile_open00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DoorTile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DoorTile* self = (DoorTile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'open'", NULL);
#endif
  {
   self->open();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'open'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: close of class  DoorTile */
#ifndef TOLUA_DISABLE_tolua_DoorTile_DoorTile_close00
static int tolua_DoorTile_DoorTile_close00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DoorTile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DoorTile* self = (DoorTile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'close'", NULL);
#endif
  {
   self->close();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'close'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLocked of class  DoorTile */
#ifndef TOLUA_DISABLE_tolua_DoorTile_DoorTile_setLocked00
static int tolua_DoorTile_DoorTile_setLocked00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DoorTile",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DoorTile* self = (DoorTile*)  tolua_tousertype(tolua_S,1,0);
  bool locked = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLocked'", NULL);
#endif
  {
   self->setLocked(locked);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLocked'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setKey of class  DoorTile */
#ifndef TOLUA_DISABLE_tolua_DoorTile_DoorTile_setKey00
static int tolua_DoorTile_DoorTile_setKey00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DoorTile",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DoorTile* self = (DoorTile*)  tolua_tousertype(tolua_S,1,0);
  std::string itemID = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setKey'", NULL);
#endif
  {
   self->setKey(itemID);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setKey'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_DoorTile_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"DoorTile","DoorTile","Tile",NULL);
  tolua_beginmodule(tolua_S,"DoorTile");
   tolua_function(tolua_S,"open",tolua_DoorTile_DoorTile_open00);
   tolua_function(tolua_S,"close",tolua_DoorTile_DoorTile_close00);
   tolua_function(tolua_S,"setLocked",tolua_DoorTile_DoorTile_setLocked00);
   tolua_function(tolua_S,"setKey",tolua_DoorTile_DoorTile_setKey00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_DoorTile (lua_State* tolua_S) {
 return tolua_DoorTile_open(tolua_S);
}
#endif

