#
# Copyright (C) pipas@gamma.ttk.pte.hu
#
lib_LIBRARIES = libpippi.a

AM_CPPFLAGS  = \
	-Wall -Werror \
	-fno-strict-aliasing -Wno-deprecated-declarations \
	-std=c++11 \
	-fPIC -pipe

MYLIBS = -lrt 

if HAVE_PIGPIO
AM_CPPFLAGS += -DHAVE_PIGPIO
MYLIBS += -lpigpio
endif

libpippi.so: libpippi.a $(libpippi_a_OBJECTS)
	@echo "  CXXLD    $@"
	$(CXX) -shared -pthread \
		$(MYLIBS) \
		-Wl,--whole-archive \
		libpippi.a \
		-Wl,--no-whole-archive \
		-o $@ 

all-local: libpippi.so
	-@echo "Creating shared-objects."

install-exec-hook: libpippi.so
	-@echo " $(INSTALL_PROGRAM_ENV) $(INSTALL_PROGRAM) libpippi.so '$(DESTDIR)$(libdir)'"
	$(INSTALL_PROGRAM_ENV) $(INSTALL_PROGRAM) libpippi.so "$(DESTDIR)$(libdir)"

libpippi_public_h_headers =       \
	pipdebug.h                    \
	PipTypes                      \
	piptypes.h                    \
	PipMap                        \
	pipmap.h                      \
	PipVector                     \
	pipvector.h                   \
	PipVariant                    \
	pipvariant.h                  \
	PipVariantMap                 \
	pipvariantmap.h               \
	PipObject                     \
	pipobject.h                   \
	PipString                     \
	pipstring.h                   \
	PipException                  \
	pipexception.h                \
	PipConfigParser               \
	pipconfigparser.h             \
	PipRelay                      \
	piprelay.h

libpippi_a_SOURCES =              \
    $(libpippi_public_h_headers)  \
	pipdebug.cpp                  \
	pipstring.cpp                 \
	pipvariant_p.h                \
	pipvariant_p.cpp              \
	pipvariant.cpp                \
	pipvariantmap.cpp             \
	pipobject.cpp                 \
	pipexception.cpp              \
	pipconfigparser.cpp           \
	piprelay.cpp

libpippidir = $(includedir)/pippi
libpippi_HEADERS = $(libpippi_public_h_headers)
