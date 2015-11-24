#!/usr/bin/env lua

local toolbox = require('toolbox')

local clang_34 = toolbox.Clangparser:new("clang-3.4")
local clang_35 = toolbox.Clangparser:new("clang-3.5")
local clang_36 = toolbox.Clangparser:new("clang-3.6")
local clang_37 = toolbox.Clangparser:new("clang-3.7")
local clang_arch = toolbox.Clangparser:new("/usr/include/clang-c")

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
