# -*- MakeFile -*-

# MACRO = substitute with this

# export

export	OS = linux
export	TST = false
export	DBG = false

 ifeq ($(OS), linux)
export	CC = gcc
export	CFLAGS = -std=c11 -O3 -march=native
export	LIBS = -l ncurses -l pthread -l m

 else
  ifeq ($(OS), win)
CFLAGS_NCURSESW6 = -D_XOPEN_SOURCE=500 -I/mingw/include/ncursesw -I/mingw/include
LIBS_NCURSESW6 = -L/mingw/lib -lncursesw -lpsapi
export	CC = gcc.exe
export	CFLAGS = -std=c11 -O3 $(CFLAGS_NCURSESW6)
export	LIBS = -static -l m $(LIBS_NCURSESW6)
  endif
 endif

# directories

ESTDIS_DIR = ./

LIBALX_DIR = $(ESTDIS_DIR)/libalx/
MODULES_DIR = $(ESTDIS_DIR)/modules/
OBJ_DIR = $(ESTDIS_DIR)/obj/
BIN_DIR = $(ESTDIS_DIR)/bin/
WIN_DIR = $(ESTDIS_DIR)/win/
TST_DIR = $(ESTDIS_DIR)/tst/


# target: dependencies
#	action

all:
	cd $(LIBALX_DIR) && $(MAKE) && cd ..
	cd $(MODULES_DIR) && $(MAKE) && cd ..
	cd $(OBJ_DIR) && $(MAKE) && cd ..

 ifeq ($(OS), linux)
	cd $(BIN_DIR) && $(MAKE) && cd ..
 else
  ifeq ($(OS), win)
	cd $(WIN_DIR) && $(MAKE) && cd ..
  endif
 endif

 ifeq ($(TST), true)
	cd $(TST_DIR) && $(MAKE) && cd ..
 endif

del: clean
	cd $(WIN_DIR) && $(MAKE) clean && cd ..
	cd $(BIN_DIR) && $(MAKE) clean && cd ..

clean:
	cd $(LIBALX_DIR) && $(MAKE) clean && cd ..
	cd $(MODULES_DIR) && $(MAKE) clean && cd ..
	cd $(OBJ_DIR) && $(MAKE) clean && cd ..
	cd $(TST_DIR) && $(MAKE) clean && cd ..
