#
# Copyright (C) pipas@gamma.ttk.pte.hu
#
bin_PROGRAMS = pippi

pippi_CPPFLAGS = \
	-Wall -Werror -fno-strict-aliasing \
	-Wno-deprecated-declarations \
	-std=c++11 \
	-I../ -I../libpippi/ -pipe 

pippi_LDADD = \
	-L../libpippi -lpippi

pippi_LDFLAGS = \
	-Wl,-rpath,. -Wl,-rpath,../libpippi -Wl,-rpath,./libpippi

pippi_SOURCES =            \
	main.cpp


