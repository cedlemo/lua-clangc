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
#include "indexlib.h"
#include <stdio.h>
int
index_new(lua_State * L)
{
  int e, d;
  e = lua_toboolean(L, 1);
  d = lua_toboolean(L, 2);
  CXIndex *i;
  i = (CXIndex *) lua_newuserdata(L, sizeof(CXIndex *));
  luaL_getmetatable(L, "Clangc.Index_mt");
  lua_setmetatable(L, -2);

  *i = clang_createIndex(e, d);

  return 1;
}
int
index__gc(lua_State * L)
{
  CXIndex idx = *(CXIndex *) lua_touserdata(L, 1);
  if(idx)
  {
    clang_disposeIndex(idx);
  }
  return 0;
}
int
index_get_globaloptions(lua_State * L)
{
  CXIndex idx = *(CXIndex *) lua_touserdata(L, 1);
  unsigned int o;
  o = clang_CXIndex_getGlobalOptions(idx);
  lua_pushinteger(L, o);
  return 1;
}
int
index_set_globaloptions(lua_State * L)
{
  CXIndex idx = *(CXIndex *) lua_touserdata(L, 1);
  unsigned int o;
  o = luaL_checkunsigned(L, 2);
  clang_CXIndex_setGlobalOptions(idx, o);
  return 0;
}
int
index_create_translationunit_fromsourcefile(lua_State *L)
{
  CXIndex idx = *(CXIndex *) lua_touserdata(L, 1);
  const char * source_file = NULL;
  //First parameter is a string
  source_file = L_2_CSTRING(L, 2);  
  //second parameter is a table/array of string
  if(lua_istable(L, 3))
  {
    int len = luaL_len(L, 3);
    char * carray[len];
    len = L_2_CSTRINGARRAY(L, 3, len, carray);
  }
  CXTranslationUnit tu;
  tu = clang_createTranslationUnitFromSourceFile( idx,
                                                  source_file,
                                                  len, carray, 0, 0); // TODO manage unsaved files
   
  return 1;
}
