#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([lua-clangc], [0.0.1], [cedlemo@gmx.com])
AC_CONFIG_SRCDIR([configure.ac])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC(clang gcc)

# Checks for libraries.
PKG_CHECK_MODULES([DEPS], [lua])
LUA_VERSION=$(pkg-config --modversion lua | awk -F "." '{print $1"."$2}')
AC_SUBST([LUA_VERSION])

libdir=$prefix/lib/lua/$LUA_VERSION/clangc
# Checks for header files.
AC_CHECK_HEADERS([string.h stdlib.h clang-c/Index.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AM_INIT_AUTOMAKE(1.13 dist-bzip2 foreign subdir-objects)
LT_PREREQ(2.4)
LT_INIT
AC_CONFIG_FILES([
  Makefile
  src/init.lua
])
AC_OUTPUT
