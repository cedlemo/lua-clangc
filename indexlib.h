#ifndef INDEXLIB_H
#define INDEXLIB_H
#include "lua.h"
#include "lauxlib.h"
#include "clang-c/Index.h"
int indexnew(lua_State *);
int index__gc(lua_State *);
int indexgetglobaloptions(lua_State *);
int indexsetglobaloptions(lua_State *);
#endif
