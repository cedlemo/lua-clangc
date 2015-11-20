/*
 * lua-clangc lua bindings for the C interface of Clang
 * Copyright (C) 2015  cedlemo <cedlemo@gmx.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "lua.h"
#include "lauxlib.h"
#include "macros.h"
#include "clangc_module_functions.h"
#include "indexlib.h"
#include "translationunitlib.h"

static const struct luaL_Reg indexlib_classes_functions[] = {
  {"new", index_new},
  {NULL, NULL}
};
static const struct luaL_Reg indexlib_instances_methods[] = {
  {"get_global_options", index_get_globaloptions},
  {"set_global_options", index_set_globaloptions},
  {"create_translationunit_from_source_file", index_create_translationunit_fromsourcefile},
  {NULL, NULL}
};
int luaopen_clangc_core(lua_State *L) {
/*
* TranslationUnit class
*/
  /*Create the metatable for TranslationUnit object*/
  luaL_newmetatable(L, "Clangc.TranslationUnit_mt");
  /*set metatable __gc field*/
  lua_pushcfunction(L, translationunit__gc);
  lua_setfield(L, -2, "__gc");
  /* When TranslationUnit methods will have to be created*/
  lua_pushvalue(L, -1); //duplicate the metatable
  lua_setfield(L, -2, "__index"); //store the duplicate in the __index field
  //luaL_setfuncs(L, translationunit_instances_methods, 0); //store the fns in the metatable
 
  lua_newtable(L);

/*
* Index Class
*/
  luaL_newmetatable(L, "Clangc.Index_mt");
  lua_pushcfunction(L, index__gc);
  lua_setfield(L, -2, "__gc");
  lua_pushvalue(L, -1);
  lua_setfield(L, -2, "__index");
  luaL_setfuncs(L, indexlib_instances_methods, 0); 
  luaL_newlib(L, indexlib_classes_functions);
  lua_setfield(L, -2, "Index");

 

/*
* Create Clangc module functions
*/
  lua_pushcfunction(L, clangc_get_version);
  lua_setfield(L, -2, "version");
  lua_pushcfunction(L, clangc_get_default_diagnostic_display_options);
  lua_setfield(L, -2, "default_diagnostic_display_options");

  return 1;
}
