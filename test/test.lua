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
local luaunit = require("luaunit")

TestClangcModule = {}
  function TestClangcModule:testHaveIndex()
    luaunit.assertNotNil(clangc.Index)
  end
  function TestClangcModule:testIndexIsTable()
    luaunit.assertIsTable(clangc.Index)
  end

TestIndexCreation = {}
  function TestIndexCreation:setUp()
    self.idx = clangc.Index.new(true, true)
  end

  function TestIndexCreation:testIsuserdata()
    luaunit.assertEquals( type(self.idx), 'userdata')
  end

TestIndexGlobalOptions = {}
  function TestIndexGlobalOptions:setUp()
    self.idx = clangc.Index.new(true, true)
  end
  function TestIndexGlobalOptions:testSetNoOptionsFlag()
    flags = clangc.IndexOptFlags.None
    self.idx:set_global_options(flags)
    luaunit.assertEquals(flags, self.idx:get_global_options())
  end
TestIndexTranslationUnit = {}
  function TestIndexTranslationUnit:setUp()
    self.idx = clangc.Index.new(false, false)
  end
  function TestIndexTranslationUnit:testCreateTUFromSourceFileNoCmdFail()
  end
  function TestIndexTranslationUnit:testCreateTUFromSourceFileNoCmd()
  end
  function TestIndexTranslationUnit:testCreateTUFromSourceFileCmdFail()
  end
  function TestIndexTranslationUnit:testCreateTUFromSourceFileCmd()
  end
os.exit(luaunit.LuaUnit.run())
