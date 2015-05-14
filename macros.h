#ifndef MACROS_H
#define MACROS_H
/*****************/
/*Debugging tools*/
/*****************/
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "lua.h"
#include "lauxlib.h" 
#define clean_errno() (errno == 0 ? "None" : strerror(errno))
#define SENTINEL(M, ...) printf("[SENTINEL] (%s:%s:%d: errno: %s) " M "\n",__FILE__, __FUNCTION__, __LINE__, clean_errno(), ##__VA_ARGS__)
#define LOG_ERR(M, ...) fprintf(stderr,  "[ERROR] (%s:%s:%d: errno: %s) " M "\n", __FILE__, __FUNCTION__, __LINE__, clean_errno(), ##__VA_ARGS__)
#define LOG_WARN(M, ...) fprintf(stderr, "[WARN]  (%s:%s:%d: errno: %s) " M "\n", __FILE__, __FUNCTION__, __LINE__, clean_errno(), ##__VA_ARGS__)
#define LOG_INFO(M, ...) fprintf(stderr, "[INFO]  (%s:%s:%d) " M "\n", __FILE__,__FUNCTION__ , __LINE__, ##__VA_ARGS__)
#define check(A, M, ...) if(!(A)) { log_err(M, ##__VA_ARGS__); errno=0; }
#define check_mem(A) check((A), "Out of memory.")
#define check_debug(A, M, ...) if(!(A)) { debug(M, ##__VA_ARGS__); errno=0; goto error; }
/*****************/
/*Common C macros*/
/*****************/
#define CARRAY_LEN(A)   (sizeof(A) / sizeof((A)[0]));

/**********************/
/*Lua Stack to C value*/
/**********************/
//Lua string to c string pointer
#define L_2_CSTRING(L, i)\
lua_isstring(L,i)? lua_tostring(L, i) : NULL
//Lua array to c array of string pointers
#define L_2_CSTRINGARRAY(L, i)\
if(lua_istable(L, i))\
{\
  int len = luaL_len(L, i);\
  SENTINEL("size %d",len);\
  if(len)\
  {\
  }\
}\
else\
  SENTINEL("Not a table");
#endif //MACROS_H
