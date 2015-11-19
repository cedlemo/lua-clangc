# Lua C Api classes implementation

# Lua code:

```lua
local Clangc = {}
Clangc.Index = {}

function Clangc.Index:new()
  o = o and type(o) == "table" or {}
  setmetatable(o, self)
  self.__index = self
  return o
end

function Clangc.Index:set_globaloptions(opts)
  self.opts = opts
end

function Clangc.Index:get_globaloptions()
  return self.opts
end

return Clangc 
```

# C code:

```c
int luaopen_clangc_core(lua_State *L) {
  /* Index Class */

  //create the main module table at the top of the stack
  lua_newtable(L); 

  /*Metatable for Index class*/
    //create the metatable and push it on the stack
  luaL_newmetatable(L, "Clangc.Index_mt");
    //puhs the garbage collector function on the stack
  lua_pushcfunction(L, index__gc);
  //set the metatable __gc field with the garbage collector function
    //by poping the last element of the stack to the table which is at
    //stack index -2
  lua_setfield(L, -2, "__gc");
  //set metatable __index field to self ( self.__index = self)
    //duplicate the metatable
  lua_pushvalue(L, -1); 
    //store the duplicate in the __index field
  lua_setfield(L, -2, "__index");
    //store the fns in the metatable 
  luaL_setfuncs(L, indexlib_instances_methods, 0);
  /*Create the Index table used as Constructor*/
  luaL_newlib(L, indexlib_classes_functions);
  lua_setfield(L, -2, "Index");

/* Create Clangc module functions */
    //push C function to the stack
  lua_pushcfunction(L, clangc_get_version);
    //pop the last element of the stack and set it to the table
    //at index -2 of the stack under the field "version"
  lua_setfield(L, -2, "version");
    //push C function to the stack
  lua_pushcfunction(L, clangc_get_default_diagnostic_display_options);
    //pop the last element of the stack and set it to the table
    //at index -2 of the stack under the field "default..."
  lua_setfield(L, -2, "default_diagnostic_display_options");

  return 1; //return 1 in order to return the table
}
```
