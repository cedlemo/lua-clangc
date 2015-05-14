#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([lua-clangc], [0.0.1], [cedlemo@gmx.com])
AC_CONFIG_SRCDIR([configure.ac])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC(clang gcc)

# Checks for libraries.
PKG_CHECK_MODULES([DEPS], [lclang lua])
# Checks for header files.
AC_CHECK_HEADERS([string.h stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AM_INIT_AUTOMAKE(1.13 dist-bzip2 foreign subdir-objects)
LT_PREREQ(2.4)
LT_INIT
AX_CXX_TYPE_UNIQUE_PTR
AC_CONFIG_FILES([
  Makefile
])
AC_OUTPUT
