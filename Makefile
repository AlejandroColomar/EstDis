# -*- MakeFile -*-

# MACRO = substitute with this

OS = linux
TST = false
DBG = false

# directories

ROOT_DIR = ./

LIBALX_DIR = $(ROOT_DIR)/libalx/
MODULES_DIR = $(ROOT_DIR)/modules/
OBJ_DIR = $(ROOT_DIR)/obj/
BIN_DIR = $(ROOT_DIR)/bin/
WIN_DIR = $(ROOT_DIR)/win/


# target: dependencies
#	action

all:
	cd $(LIBALX_DIR) && $(MAKE) OS=$(OS) && cd ..
	cd $(MODULES_DIR) && $(MAKE) OS=$(OS) && cd ..
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
	cd $(MODULES_DIR) && $(MAKE) clean && cd ..
	cd $(OBJ_DIR) && $(MAKE) clean && cd ..
	cd $(WIN_DIR) && $(MAKE) clean && cd ..
	cd $(BIN_DIR) && $(MAKE) clean && cd ..

clean:
	cd $(LIBALX_DIR) && $(MAKE) clean && cd ..
	cd $(MODULES_DIR) && $(MAKE) clean && cd ..
	cd $(OBJ_DIR) && $(MAKE) clean && cd ..
