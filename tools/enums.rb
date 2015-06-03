#!/usr/bin/env ruby 
require "rtruckboris"


clang_c = "/usr/include/clang-c/Index.h"
headerPaths = []
#get gcc include if needed
gccLibBase='/usr/lib/gcc/' << `llvm-config --host-target`.chomp << "/*"
gccLib = Dir.glob(gccLibBase ).sort.last + "/include"
headerPaths << gccLib
headerPaths << "/usr/include"
headerPaths << "/usr/include/clang-c"

parser = Rtruckboris::HeaderParser.new(clang_c, headerPaths)
if(!parser.parse(true))
  puts "Whada fock??"
  exit
end
def create_table_constant(enum)
  name = enum.name == "" ? enum.typedef_name : enum.name
  enum_module_name = name.gsub(/CX/,"")
  s="lua_newtable(L);\n"
  enum.enum_constants.each do |c|
    s+="lua_pushinteger(L, #{c.value});\n"
    s+="lua_setfield(L, -2, \"#{c.name.gsub(/CX[^\_]*\_/,"").capitalize}\");\n"
  end 
  s+="lua_setfield(L, -2,\"#{enum_module_name}\");\n"
  s
end
def create_tables_constants(enums)
  s="#include \"constants.h\"\n" 
  s+="void init_clang_enums_to_constants(lua_State *L){\n"
  enums.each_with_index do |e, i|
    s+="#{create_table_constant(e)}\n"
  end
  s+="}\n"
end
enums = parser.enums
puts enums.size
class OutputFiles
  attr_reader :_c, :_h
  def initialize(name)
    @_c = File.new((name||'wrapper') + '.c', 'w')
    @_h = File.new((name||'wrapper') + '.h', 'w')
    @_c.sync= true
    @_c.sync= true
  end
  def close_all
    @_c.close
    @_h.close
  end
end 
constants = OutputFiles.new("constants")
constants._h.puts <<EOF
#include "lua.h" 
void init_clang_enums_to_constants(lua_State *L);
EOF

clang_c_errors = "/usr/include/clang-c/CXErrorCode.h"
parser = Rtruckboris::HeaderParser.new(clang_c_error, headerPaths)
parser.parse(true)

enums += parser.enums

constants._c.puts create_tables_constants(enums)
constants.close_all


