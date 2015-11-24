#!/usr/bin/env lua

local toolbox = require('toolbox')

local gcc_lib_base = '/usr/lib/gcc/' .. toolbox.exec_out('llvm-config --host-target')

local last = ''
for dir in toolbox.lfs.dir(gcc_lib_base) do
  if not dir:match('^..?$') then
    if dir > last then
      last = dir
    end
  end
end

headers_paths = {}
headers_paths[1] = gcc_lib_base .. '/' .. last .. '/' .. 'include'
headers_paths[2] = '/usr/include'
headers_paths[3] = '/usr/include/clang-c'

clangc_source = '/usr/include/clang-c/Index.h'

local parser = toolbox.truckboris.HeaderParser()
parser:add_source_file(clangc_source)
for _,h in ipairs(headers_paths) do
  parser:add_search_path(h)
end

has_worked = parser:parse()

if has_worked == true then
  print("Parsing has worked")
end

local enums = {}

for i = 1, parser:enums_num(), 1 do
  enums[i] = parser:get_nth_enum(i - 1)
end

local function rename_module_table(enum)
  local name = enum:name() == "" and enum:typedef_name() or enum:name()
  return name:gsub('^CX_?','') 
end

local function rename_enum_constant(constant_name)
  local name = constant_name:gsub("^([^_]+_)(.*)$","%2")
  return toolbox.to_screaming_snake_case(name)
end

local function create_module_constant(enum)
  local name = rename_module_table(enum)
  print('-->' .. name)
  for i = 1, enum:constants_num(), 1 do
    local enum_constant_name = enum:get_nth_enum_constant(i - 1):name()
    print('\t-' .. rename_enum_constant(enum_constant_name) .. ' -- ' .. enum_constant_name)
  end
end

for _,e in ipairs(enums) do
  create_module_constant(e)
end
