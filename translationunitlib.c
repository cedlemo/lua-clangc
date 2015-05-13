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
#include "translationunitlib.h"
#include <stdio.h>
int
_alloc_translationunit(lua_State * L)
{
  CXTranslationUnit *t;
  t = (CXTranslationUnit *) lua_newuserdata(L, sizeof(CXTranslationUnit *));
  luaL_getmetatable(L, "Clangc.TranslationUnit_mt");
  lua_setmetatable(L, -2);

  return 1;
}
int
translationunit__gc(lua_State * L)
{
  CXTranslationUnit tu = *(CXTranslationUnit *) lua_touserdata(L, 1);
  if(tu)
  {
    clang_disposeTranslationUnit(tu);
  }
  return 0;
}
int
