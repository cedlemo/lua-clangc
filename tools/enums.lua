#!/usr/bin/env lua

local truckboris = require('truckboris')
local lfs = require('lfs')

local function split(str, pat)
  local t = {}  -- NOTE: use {n = 0} in Lua-5.0
  local fpat = "(.-)" .. pat
  local last_end = 1
  local s, e, cap = string.find(str,fpat, 1)
  while s do
    if s ~= 1 or cap ~= "" then
      table.insert(t,cap)
    end
    last_end = e+1
    s, e, cap = string.find(str,fpat, last_end)
  end
  if last_end <= #str then
    cap = string.sub(str,last_end)
    table.insert(t, cap)
  end
  return t
end

local function exec_out(cmd)
  local handle = io.popen(cmd)
  local result = string.gsub(handle:read("*a"), "\n", "")
  handle:close()
  return result
end

local gcc_lib_base = '/usr/lib/gcc/' .. exec_out('llvm-config --host-target')

local last = ''
for dir in lfs.dir(gcc_lib_base) do
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

local parser = truckboris.HeaderParser()
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

local function to_snake_case(a_string)
  if not a_string:match("[A-Z]") or not a_string:match("[a-z]") then
    return a_string
  else
    s = a_string:gsub("([a-z]+)([A-Z][a-z]%a*)","%1_%2")
    s = a_string:gsub("([A-Z]+)([A-Z][a-z]%a*)","%1_%2")
    s = s:gsub("([a-z]+)([A-Z]+)","%1_%2")
    return s
  end
end

local function rename_module_table(enum)
  local name = enum:name() == "" and enum:typedef_name() or enum:name()
  return name:gsub('^CX_?','') 
end

local function rename_enum_constant(constant_name)
  local name = constant_name:gsub("^([^_]+_)(.*)$","%2")
  name = to_snake_case(name)
  return name:upper()
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
