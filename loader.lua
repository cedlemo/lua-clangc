#!/usr/bin/env lua
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
