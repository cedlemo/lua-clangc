MAINTAINERCLEANFILES = \
Makefile.in aclocal.m4 config.h.in configure \
depcomp install-sh missing compile config.sub \
config.guess ltmain.sh

lib_LTLIBRARIES = src/clangc.la
src_clangc_la_SOURCES = src/clangc.c src/indexlib.c src/translationunit.c
src_clangc_la_LDFLAGS = -module -avoid-version -shared
