#include <stdio.h>
#include "lua.h"
#include "lauxlib.h"
#include "constants.h"
#include "indexlib.h"
/*Compile with:
gcc -shared -llua -lm -fPIC -o clangc.so clangc.c
This module create a table with a value and return it
*/
static const struct luaL_Reg indexlib_classes_functions[] = {
  {"new", indexnew},
  {NULL, NULL}
};
static const struct luaL_Reg indexlib_instances_methods[] = {
  {"get_global_options", indexgetglobaloptions},
  {"set_global_options", indexsetglobaloptions},
  {NULL, NULL}
};
//TODO add OO p299 style
int luaopen_clangc(lua_State *L) {
  lua_newtable(L); //create the main module table

  luaL_newmetatable(L, "Clangc.Index_mt");
  /*set metatable __gc field*/
  lua_pushcfunction(L, index__gc);
  lua_setfield(L, -2, "__gc");
  /*set metatble __index field to metatable */
  lua_pushvalue(L, -1); //duplicate the metatable
  lua_setfield(L, -2, "__index"); //store the duplicate in the __index field
  luaL_setfuncs(L, indexlib_instances_methods, 0); //store the fns in the metatable  

  luaL_newlib(L, indexlib_classes_functions);
  lua_setfield(L, -2, "Index");
  init_clang_enums_to_constants(L);
  return 1; //return 1 in order to return the table
}
