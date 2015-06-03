MAINTAINERCLEANFILES = \
Makefile.in aclocal.m4 config.h.in configure \
depcomp install-sh missing compile config.sub \
config.guess ltmain.sh compile

lib_LTLIBRARIES = src/clangc.la
src_clangc_la_SOURCES = src/clangc.c src/indexlib.c src/translationunitlib.c src/constants.c
src_clangc_la_LDFLAGS = -module -avoid-version -shared -llua -lm -lclang -fPIC 
