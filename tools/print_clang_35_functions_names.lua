#!/usr/bin/env lua

local toolbox = require('toolbox')

local clang_35 = toolbox.Clangparser:new("clang-3.5")
local clang_arch = toolbox.Clangparser:new("/usr/include/clang-c")

clang_35:parse(true)
clang_arch:parse(true)

print('Number of functions')
print('3.5.0 => ' .. clang_35.parser:functions_num())
print('Arch => ' .. clang_arch.parser:functions_num())

for i = 1, clang_35.parser:functions_num(), 1 do
  print(clang_35.parser:get_nth_function(i - 1):name())
end
