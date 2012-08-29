/*
** Lua binding: Attack
** Generated automatically by tolua++-1.0.92 on Tue Dec 29 17:14:12 2009.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_Attack_open (lua_State* tolua_S);

#include "Attack.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Attack (lua_State* tolua_S)
{
 Attack* self = (Attack*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Attack");
}

/* method: new of class  Attack */
#ifndef TOLUA_DISABLE_tolua_Attack_Attack_new00
static int tolua_Attack_Attack_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Attack",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::string name = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  std::string pattern = ((std::string)  tolua_tocppstring(tolua_S,3,0));
  int damage = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   Attack* tolua_ret = (Attack*)  Mtolua_new((Attack)(name,pattern,damage));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Attack");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Attack */
#ifndef TOLUA_DISABLE_tolua_Attack_Attack_new00_local
static int tolua_Attack_Attack_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Attack",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::string name = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  std::string pattern = ((std::string)  tolua_tocppstring(tolua_S,3,0));
  int damage = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   Attack* tolua_ret = (Attack*)  Mtolua_new((Attack)(name,pattern,damage));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Attack");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Attack */
#ifndef TOLUA_DISABLE_tolua_Attack_Attack_new01
static int tolua_Attack_Attack_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Attack",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  std::string pattern = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  int damage = ((int)  tolua_tonumber(tolua_S,3,0));
  int damageBonus = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   Attack* tolua_ret = (Attack*)  Mtolua_new((Attack)(pattern,damage,damageBonus));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Attack");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Attack_Attack_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Attack */
#ifndef TOLUA_DISABLE_tolua_Attack_Attack_new01_local
static int tolua_Attack_Attack_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Attack",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  std::string pattern = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  int damage = ((int)  tolua_tonumber(tolua_S,3,0));
  int damageBonus = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   Attack* tolua_ret = (Attack*)  Mtolua_new((Attack)(pattern,damage,damageBonus));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Attack");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_Attack_Attack_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_Attack_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Attack","Attack","",tolua_collect_Attack);
  #else
  tolua_cclass(tolua_S,"Attack","Attack","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Attack");
   tolua_function(tolua_S,"new",tolua_Attack_Attack_new00);
   tolua_function(tolua_S,"new_local",tolua_Attack_Attack_new00_local);
   tolua_function(tolua_S,".call",tolua_Attack_Attack_new00_local);
   tolua_function(tolua_S,"new",tolua_Attack_Attack_new01);
   tolua_function(tolua_S,"new_local",tolua_Attack_Attack_new01_local);
   tolua_function(tolua_S,".call",tolua_Attack_Attack_new01_local);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Attack (lua_State* tolua_S) {
 return tolua_Attack_open(tolua_S);
}
#endif

