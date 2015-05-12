#!/usr/bin/env lua
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
