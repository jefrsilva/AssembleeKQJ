/*
** Lua binding: HoleTile
** Generated automatically by tolua++-1.0.92 on Tue Dec 29 18:14:27 2009.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_HoleTile_open (lua_State* tolua_S);

#include "HoleTile.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Tile");
 tolua_usertype(tolua_S,"HoleTile");
}

/* method: open of class  HoleTile */
#ifndef TOLUA_DISABLE_tolua_HoleTile_HoleTile_open00
static int tolua_HoleTile_HoleTile_open00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HoleTile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HoleTile* self = (HoleTile*)  tolua_tousertype(tolua_S,1,0);
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

/* method: close of class  HoleTile */
#ifndef TOLUA_DISABLE_tolua_HoleTile_HoleTile_close00
static int tolua_HoleTile_HoleTile_close00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HoleTile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HoleTile* self = (HoleTile*)  tolua_tousertype(tolua_S,1,0);
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

/* Open function */
TOLUA_API int tolua_HoleTile_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"HoleTile","HoleTile","Tile",NULL);
  tolua_beginmodule(tolua_S,"HoleTile");
   tolua_function(tolua_S,"open",tolua_HoleTile_HoleTile_open00);
   tolua_function(tolua_S,"close",tolua_HoleTile_HoleTile_close00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_HoleTile (lua_State* tolua_S) {
 return tolua_HoleTile_open(tolua_S);
}
#endif

