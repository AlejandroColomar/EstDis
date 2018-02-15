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
WIN_DIR = $(ROOT_DIR)/win/

LIBALX_DIR = $(ROOT_DIR)/libalx/


# target: dependencies
#	action

all:
	cd $(LIBALX_DIR) && $(MAKE) OS=$(OS) && cd ..
	cd $(OBJ_DIR) && $(MAKE) OS=$(OS) && cd ..

 ifeq ($(OS), linux)
	cd $(BIN_DIR) && $(MAKE) OS=$(OS) && cd ..
 else
  ifeq ($(OS), win)
	cd $(WIN_DIR) && $(MAKE) OS=$(OS) && cd ..
  endif
 endif

del:
	cd $(LIBALX_DIR) && $(MAKE) clean && cd ..
	cd $(OBJ_DIR) && $(MAKE) clean && cd ..
	cd $(WIN_DIR) && $(MAKE) clean && cd ..
	cd $(BIN_DIR) && $(MAKE) clean && cd ..

clean:
	cd $(LIBALX_DIR) && $(MAKE) clean && cd ..
	cd $(OBJ_DIR) && $(MAKE) clean && cd ..
