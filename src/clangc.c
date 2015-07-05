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
#include "constants.h"
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
int luaopen_clangc(lua_State *L) {
//  SENTINEL("### luaopen %d ###", lua_gettop(L));
  lua_newtable(L); //create the main module table
//  SENTINEL("### newtable %d ###", lua_gettop(L));

/*
* Index Class
*/
  /*Metatable for Index class*/
  luaL_newmetatable(L, "Clangc.Index_mt");
  SENTINEL("### newtmetatable Index_mt %d ###", lua_gettop(L));
  /*set metatable __gc field*/
  lua_pushcfunction(L, index__gc);
  lua_setfield(L, -2, "__gc"); //pop the last element of the stack to the table at stack index
  SENTINEL("### set Index_mt field __gc %d ###", lua_gettop(L));
  /*set metatble __index field to metatable */
  lua_pushvalue(L, -1); //duplicate the metatable
  lua_setfield(L, -2, "__index"); //store the duplicate in the __index field
  SENTINEL("### set Index_mt field __index %d ###", lua_gettop(L));
  luaL_setfuncs(L, indexlib_instances_methods, 0); //store the fns in the metatable  
  SENTINEL("### store fns in Index_mt %d ###", lua_gettop(L));
  /*Create the Index table used as Constructor*/
  luaL_newlib(L, indexlib_classes_functions);
  SENTINEL("###Create the index table as Constructor %d ###", lua_gettop(L));
  lua_setfield(L, -2, "Index");
  SENTINEL("### Store the Index table in the main table %d ###", lua_gettop(L));
  /*Manage TranslationUnit class */
  /*Create the metatable for TranslationUnit object*/
//  luaL_newmetatable(L, "Clangc.TranslationUnit_mt");
  /*set metatable __gc field*/
//  lua_pushcfunction(L, translationunit__gc);
  /* When TranslationUnit methods will have to be created
  lua_pushvalue(L, -1); //duplicate the metatable
  lua_setfield(L, -2, "__index"); //store the duplicate in the __index field
  luaL_setfuncs(L, translationunit_instances_methods, 0); //store the fns in the metatable
*/

/*
* Create Clangc module functions
*/
  lua_pushcfunction(L, clangc_get_version);
//  SENTINEL("### Store the version fn int the stack %d ###", lua_gettop(L));
  lua_setfield(L, -2, "version");
//  SENTINEL("### Store the version fn in the main table %d ###", lua_gettop(L));
  lua_pushcfunction(L, clangc_get_default_diagnostic_display_options);
  lua_setfield(L, -2, "default_diagnostic_display_options");
/*
* Create the clangc constants
*/
  init_clang_enums_to_constants(L);
//  SENTINEL("### Store the constants table in the main table%d ###", lua_gettop(L));

  return 1; //return 1 in order to return the table
}
