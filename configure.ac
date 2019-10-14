# Process this file with autoconf to produce a configure script.
AC_INIT(pippi, 0.0.1)
AC_CONFIG_SRCDIR([libpippi/pipdebug.cpp])
AM_INIT_AUTOMAKE([subdir-objects])
AM_SILENT_RULES([yes])

AM_CONFIG_HEADER(config.h)
AC_CONFIG_MACRO_DIR([m4])
AC_PREFIX_DEFAULT(/usr)

# Checks for programs.
AC_PROG_CPP
AC_PROG_CXX
#AM_PROG_LEX
#AC_PROG_YACC
AC_PROG_RANLIB
AC_PROG_MAKE_SET
AC_CHECK_PROGS([DOXYGEN], [doxygen])

# Checks for library functions.
AC_HEADER_STDC
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_FUNC_VPRINTF
AC_CHECK_FUNCS([strdup strtol strcmp strncmp])

# Checking for dependency libraries.
AC_CHECK_HEADERS([pigpio.h],have_pigpio="yes",have_pigpio="no")
#AC_CHECK_LIB(pigpio,gpioSetMode,,AC_MSG_ERROR([Pigpio library was not found.]))
AM_CONDITIONAL(HAVE_PIGPIO, [test "$have_pigpio" = "yes"])


#
# Creating the makefiles.
#
AC_CONFIG_FILES(Makefile                          \
                libpippi/Makefile                 \
                src/Makefile                      \
                tests/Makefile                    \
                tests/ut_pipvariant/Makefile      \
                tests/ut_pipconfigparser/Makefile \
               )

AC_OUTPUT
