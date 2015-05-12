#!/usr/bin/env lua
--
-- lua-clangc lua bindings for the C interface of Clang
-- Copyright (C) 2015  cedlemo <cedlemo@gmx.com>
--
-- This program is free software: you can redistribute it and/or modify
-- it under the terms of the GNU General Public License as published by
-- the Free Software Foundation, either version 3 of the License, or
-- (at your option) any later version.
-- 
-- This program is distributed in the hope that it will be useful,
-- but WITHOUT ANY WARRANTY; without even the implied warranty of
-- MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-- GNU General Public License for more details.
-- 
-- You should have received a copy of the GNU General Public License
-- along with this program.  If not, see <http://www.gnu.org/licenses/>.
--
local clangc = require("clangc")
print("clanc return a : " .. type(clangc))

print("The clangc enums are :")
for k, v in pairs(clangc) do
  print(k)
end
print("The clangc enums values are :")
for k, v in pairs(clangc) do
  print(k .. " :")
  if type(v) == "table" then
    for kk,kv in pairs(v) do
      if type(kv) == "string" then
        print("\t"..kk.."->"..kv)
      end
    end
  end
end

a= clangc.Index.new(0,0)

print(type(a))

for k, v in pairs(clangc) do
  print(k .. " : " .. type(v))
end 
