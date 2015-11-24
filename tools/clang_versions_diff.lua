#!/usr/bin/env lua

local truckboris = require('truckboris')
local lfs = require('lfs')

local function exec_out(cmd)
  local handle = io.popen(cmd)
  local result = string.gsub(handle:read("*a"), "\n", "")
  handle:close()
  return result
end

local posix = require('posix')
function isdir(fn)
    return (posix.stat(fn, "type") == 'directory')
end

local Clangparser = {}

function Clangparser:new (path)

  if not isdir(path) then
    return nil
  end

  local p = {}

  p.path = path
  p.source = p.path .. '/Index.h'
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
  p.headers_paths[3] = p.path
  setmetatable(p, self)
  self.__index = self
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

local clang_34 = Clangparser:new("clang-3.4")
local clang_35 = Clangparser:new("clang-3.5")
local clang_36 = Clangparser:new("clang-3.6")
local clang_37 = Clangparser:new("clang-3.7")
local clang_arch = Clangparser:new("/usr/include/clang-c")

clang_34:parse()
clang_35:parse()
clang_36:parse()
clang_37:parse()
clang_arch:parse()

print('Number of structures')
print('3.4.0 => ' .. clang_34.parser:structures_num())
print('3.5.0 => ' .. clang_35.parser:structures_num())
print('3.6.0 => ' .. clang_36.parser:structures_num())
print('3.7.0 => ' .. clang_37.parser:structures_num())
print('Arch  => ' .. clang_arch.parser:structures_num())

print('Number of Enums')
print('3.4.0 => ' .. clang_34.parser:enums_num())
print('3.5.0 => ' .. clang_35.parser:enums_num())
print('3.6.0 => ' .. clang_36.parser:enums_num())
print('3.7.0 => ' .. clang_37.parser:enums_num())
print('Arch => ' .. clang_arch.parser:enums_num())

print('Number of functions')
print('3.4.0 => ' .. clang_34.parser:functions_num())
print('3.5.0 => ' .. clang_35.parser:functions_num())
print('3.6.0 => ' .. clang_36.parser:functions_num())
print('3.7.0 => ' .. clang_37.parser:functions_num())
print('Arch => ' .. clang_arch.parser:functions_num())
