MAINTAINERCLEANFILES = \
Makefile.in aclocal.m4 config.h.in configure \
depcomp install-sh missing compile config.sub \
config.guess ltmain.sh compile

lib_LTLIBRARIES = src/core.la src/constants.la
src_core_la_SOURCES = src/core.c src/indexlib.c src/translationunitlib.c src/clangc_module_functions.c
src_core_la_LDFLAGS = -module -avoid-version -shared -llua -lm -lclang -fPIC

src_constants_la_SOURCES = src/constants.c
src_constants_la_LDFLAGS = -module -avoid-version -shared -llua -lm -lclang -fPIC

initmoduledir = @libdir@
initmodule_DATA = src/init.lua
