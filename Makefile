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


ROOT_DIR = ./
BIN_DIR = $(ROOT_DIR)/bin/
INC_DIR = $(ROOT_DIR)/inc/
OBJ_DIR = $(ROOT_DIR)/obj/
SRC_DIR = $(ROOT_DIR)/src/

LIBALX_DIR = $(ROOT_DIR)/libalx/


# target: dependencies
#	action

all:
	cd $(LIBALX_DIR) && $(MAKE) OS=$(OS) && cd ..
	cd $(OBJ_DIR) && $(MAKE) OS=$(OS) && cd ..
	cd $(BIN_DIR) && $(MAKE) OS=$(OS) && cd ..

clean:
	cd $(LIBALX_DIR) && $(MAKE) clean && cd ..
	cd $(OBJ_DIR) && $(MAKE) clean && cd ..
	cd $(BIN_DIR) && $(MAKE) clean && cd ..
