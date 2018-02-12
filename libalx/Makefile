# -*- MakeFile -*-

# MACRO = substitute with this

OS = linux

ifeq ($(OS), linux)
	CC = gcc
	CFLAGS = -std=c11 -O3 -march=native
	LIBS = -l ncurses -l pthread -l m
else
 ifeq ($(OS), win)
	CC = gcc.exe
	CFLAGS = -std=c11 -O3
	LIBS = -l pdcurses -l m
 endif
endif


LIBALX_DIR = ./
INC_DIR = $(LIBALX_DIR)/inc/
OBJ_DIR = $(LIBALX_DIR)/obj/
SRC_DIR = $(LIBALX_DIR)/src/


# target: dependencies
#	action

all:
	cd $(OBJ_DIR) && $(MAKE) OS=$(OS) && cd ..


clean:
	cd $(OBJ_DIR) && $(MAKE) clean && cd ..
