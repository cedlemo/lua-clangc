local lfs = require('lfs')
local PATH = lfs.currentdir()
local clang_lib = '/usr/lib/clang'
local clang_include_dirs = {}
-- Build include directory arguments for compilator -I/sur/lib...
for version in lfs.dir(clang_lib) do
  if not version:match('^..?$') then
    includes = '-I' .. clang_lib .. '/' .. version .. '/include'
    table.insert(clang_include_dirs, includes)
  end
end

local utils = {
  -- Good C test file
  SOURCE_FILE = PATH .. '/source1.c',
  -- Good C test file with gnu-binary-literal option warning
  SOURCE_FILE_OPTION_WARNINGS = PATH .. '/source_option_warnings.c',
  -- C source code with one error
  SOURCE_FILE_ONE_ERROR = PATH .. '/source2.c',
  -- C source code with two error
  SOURCE_FILE_TWO_ERRORS = PATH .. '/source3.c',
  -- C source code with three error
  SOURCE_FILE_THREE_ERRORS = PATH .. '/source4.c',
  CLANG_HEADERS_PATH = clang_include_dirs
}

return utils
