# -*- MakeFile -*-

# MACRO = substitute with this

CC = gcc.exe
CFLAGS = -std=c11 -O3
LIBS = -l pdcurses


ROOT_DIR = ../
BIN_DIR = $(ROOT_DIR)/bin/
INC_DIR = $(ROOT_DIR)/inc/
OBJ_DIR = $(ROOT_DIR)/obj/
SRC_DIR = $(ROOT_DIR)/src/

LIBALX_DIR = $(ROOT_DIR)/libalx/
LIBALX_OBJ_DIR = $(LIBALX_DIR)/obj/

ALL = estdis.exe

# dependencies

OBJ_OBJ = main.o about.o desc.o dist.o menu.o start.o
LIBALX_OBJ = alx_file.o alx_getnum.o alx_math.o alx_ncur.o
OBJ = $(patsubst %,$(OBJ_DIR)/%,$(OBJ_OBJ)) $(patsubst %,$(LIBALX_OBJ_DIR)/%,$(LIBALX_OBJ))


# target: dependencies
#	action

all: $(ALL)


estdis.exe: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)


clean:
	rm -f $(ALL)
