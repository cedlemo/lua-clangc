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
#ifndef INDEXLIB_H
#define INDEXLIB_H
#include "lua.h"
#include "lauxlib.h"
#include "clang-c/Index.h"
#include "macros.h"
int index_new(lua_State *);
int index__gc(lua_State *);
int index_get_globaloptions(lua_State *);
int index_set_globaloptions(lua_State *);
int index_create_translationunit_fromsourcefile(lua_State *);
#endif
