# -*- MakeFile -*-

# MACRO = substitute with this

OS = linux

CC = gcc
CFLAGS = -std=c11 -O3 -march=native
LIBS = -l ncurses -l pthread -l m


ROOT_DIR = ../
BIN_DIR = $(ROOT_DIR)/bin/
INC_DIR = $(ROOT_DIR)/inc/
OBJ_DIR = $(ROOT_DIR)/obj/
SRC_DIR = $(ROOT_DIR)/src/

LIBALX_DIR = $(ROOT_DIR)/libalx/
LIBALX_OBJ_DIR = $(LIBALX_DIR)/obj/

ALL = estdis

# dependencies

OBJ_OBJ = main.o about.o desc.o dist.o menu.o start.o
LIBALX_OBJ = alx_file.o alx_getnum.o alx_math.o alx_ncur.o
OBJ = $(patsubst %,$(OBJ_DIR)/%,$(OBJ_OBJ)) $(patsubst %,$(LIBALX_OBJ_DIR)/%,$(LIBALX_OBJ))


# target: dependencies
#	action

all: $(ALL)


estdis: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)


clean:
	rm -f $(ALL)
