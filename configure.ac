#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.67])
AC_INIT([bf], [0.0.1], [federicoculloca@gmail.com])
AM_INIT_AUTOMAKE([-Wall -Werror])
#AC_CONFIG_SRCDIR([bf_interpreter.h])
#AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_FUNC_REALLOC
AC_CHECK_FUNCS([atexit])

AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT
