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

#include "clangc_module_functions.h"
int
clangc_get_version(lua_State * L)
{
  CXString str = clang_getClangVersion();
  lua_pushstring(L, clang_getCString(str));
  return 1;
}
int
clangc_get_default_diagnostic_display_options(lua_State * L)
{
  unsigned int o;
  o = clang_defaultDiagnosticDisplayOptions();
  lua_pushinteger(L, o); 
  return 1;
}
