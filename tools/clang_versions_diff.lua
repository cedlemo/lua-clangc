#!/usr/bin/env lua

local truckboris = require('truckboris')
local lfs = require('lfs')

local function exec_out(cmd)
  local handle = io.popen(cmd)
  local result = string.gsub(handle:read("*a"), "\n", "")
  handle:close()
  return result
end
--
--local gcc_lib_base = '/usr/lib/gcc/' .. exec_out('llvm-config --host-target')
--
--local last = ''
--for dir in lfs.dir(gcc_lib_base) do
--  if not dir:match('^..?$') then
--    if dir > last then
--      last = dir
--    end
--  end
--end
--
--local headers_paths = {}
--headers_paths[1] = gcc_lib_base .. '/' .. last .. '/' .. 'include'
--headers_paths[2] = '/usr/include'
--
--local clangc_source_34 = 'clang-3.4/Index.h'
--local clangc_source_35 = 'clang-3.5/Index.h'
--local clangc_source_36 = 'clang-3.6/Index.h'
--local clangc_source_37 = 'clang-3.7/Index.h'
--
--
--
--local function read_sources(source_file, include_h)
--  local parser = truckboris.HeaderParser()
--  parser:add_source_file(source_file)
--  for _,h in ipairs(include_h) do
--    parser:add_search_path(h)
--  end
--
--  local has_worked = parser:parse()
--
--  if has_worked == true then
--    print('Parsing has worked for ' .. source_file)
--    return parser
--  else
--    return nil
--  end
--end
--
--headers_paths[3] = 'clang-3.4'
--local parser34 = read_sources(clangc_source_34, headers_paths)
--
--headers_paths[3] = 'clang-3.5'
--local parser35 = read_sources(clangc_source_35, headers_paths)
--
--headers_paths[3] = 'clang-3.6'
--local parser36 = read_sources(clangc_source_36, headers_paths)
--
--headers_paths[3] = 'clang-3.7'
--local parser37 = read_sources(clangc_source_37, headers_paths)
--
--
local Clangparser = {}

function Clangparser:new (version)

  if type(version) ~= "string" or version:match('^%d.%d$') == nil then
    return nil
  end

  local p = {}
  p.version = version
  p.source = 'clang-'.. p.version .. '/Index.h'
  local gcc_lib_base = '/usr/lib/gcc/' .. exec_out('llvm-config --host-target')

  local last = ''
  for dir in lfs.dir(gcc_lib_base) do
    if not dir:match('^..?$') then
      if dir > last then
        last = dir
      end
    end
  end

  p.headers_paths = {}
  p.headers_paths[1] = gcc_lib_base .. '/' .. last .. '/' .. 'include'
  p.headers_paths[2] = '/usr/include'

  setmetatable(p, self)
  self.__index = self
  print(p.version)
  print(p)
  return p
end

function Clangparser:parse()
  parser = truckboris.HeaderParser()
  parser:add_source_file(self.source)
  for _,h in ipairs(self.headers_paths) do
    parser:add_search_path(h)
  end
  
  self.parser = parser

  return parser:parse()
end

local clang_34 = Clangparser:new("3.4")
local clang_35 = Clangparser:new("3.5")
local clang_36 = Clangparser:new("3.6")
local clang_37 = Clangparser:new("3.7")

clang_34:parse()
clang_35:parse()
clang_36:parse()
clang_37:parse()

print('Number of structures')
print('3.4.0 => ' .. clang_34.parser:structures_num())
print('3.5.0 => ' .. clang_35.parser:structures_num())
print('3.6.0 => ' .. clang_36.parser:structures_num())
print('3.7.0 => ' .. clang_37.parser:structures_num())

print('Number of Enums')
print('3.4.0 => ' .. clang_34.parser:enums_num())
print('3.5.0 => ' .. clang_35.parser:enums_num())
print('3.6.0 => ' .. clang_36.parser:enums_num())
print('3.7.0 => ' .. clang_37.parser:enums_num())

print('Number of functions')
print('3.4.0 => ' .. clang_34.parser:functions_num())
print('3.5.0 => ' .. clang_35.parser:functions_num())
print('3.6.0 => ' .. clang_36.parser:functions_num())
print('3.7.0 => ' .. clang_37.parser:functions_num())

