#!/usr/bin/make -f

SRCDIR = src
INSTALLDIR= ~/emu80

CC = c++
CFLAGS = -c -Wall -std=c++11 `wx-config --cflags` `sdl2-config --cflags` -DPAL_SDL -DPAL_WX
LDFLAGS = `sdl2-config --libs` `wx-config --libs`

SRC = $(SRCDIR)/*.cpp
SRCSDL = $(SRCDIR)/sdl/*.cpp
SRCLITE = $(SRCDIR)/lite/*.cpp
SRCWX = $(SRCDIR)/wx/*.cpp

SOURCES = $(shell echo $(SRC)) $(shell echo $(SRCSDL)) $(shell echo $(SRCWX))
SOURCES_LITE = $(shell echo $(SRC)) $(shell echo $(SRCSDL)) $(shell echo $(SRCLITE))

OBJECTS = $(SOURCES:.cpp=.o)
OBJECTS_LITE = $(SOURCES_LITE:.cpp=.o)

all: Emu80

Emu80: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

.cpp.o:
	$(CC) $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJECTS)
	rm -f $(OBJECTS_LITE)
	rm -f Emu80
	rm -f Emu80lite

install: Emu80
	mkdir -p $(INSTALLDIR)
	cp Emu80 $(INSTALLDIR)
	cp -r dist/* $(INSTALLDIR)
	cp COPYING.txt $(INSTALLDIR)
	cp whatsnew.txt $(INSTALLDIR)
	cp doc/* $(INSTALLDIR)
