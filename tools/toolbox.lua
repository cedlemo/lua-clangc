local truckboris = require('truckboris')
local lfs = require('lfs')
local posix = require('posix')

local function exec_out(cmd)
  local handle = io.popen(cmd)
  local result = string.gsub(handle:read("*a"), "\n", "")
  handle:close()
  return result
end

local function isdir(fn)
    return (posix.stat(fn, "type") == 'directory')
end

---Split string in different parts which are returned in a table. The delimiter of each part is a pattern given in argument.
--@param str the string to split
--@param pat the pattern delimiter
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

local function to_screaming_snake_case(a_string)
  return to_snake_case(a_string):upper()
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

return {
  isdir = isdir,
  exec_out = exec_out,
  Clangparser = Clangparser,
  split = split,
  to_snake_case = to_snake_case,
  to_screaming_snake_case = to_screaming_snake_case,
  lfs = lfs,
  posix = posix,
  truckboris =truckboris,
}
