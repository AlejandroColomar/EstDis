# -*- MakeFile -*-

# MACRO = substitute with this

OS = linux
TST = false
DBG = false

MAKE_ARGS = OS=$(OS) TST=$(TST) DGB=$(DBG)

# directories

ROOT_DIR = ./

LIBALX_DIR = $(ROOT_DIR)/libalx/
MODULES_DIR = $(ROOT_DIR)/modules/
OBJ_DIR = $(ROOT_DIR)/obj/
BIN_DIR = $(ROOT_DIR)/bin/
WIN_DIR = $(ROOT_DIR)/win/
TST_DIR = $(ROOT_DIR)/tst/


# target: dependencies
#	action

all:
	cd $(LIBALX_DIR) && $(MAKE) $(MAKE_ARGS) && cd ..
	cd $(MODULES_DIR) && $(MAKE) $(MAKE_ARGS) && cd ..
	cd $(OBJ_DIR) && $(MAKE) $(MAKE_ARGS) && cd ..

 ifeq ($(OS), linux)
	cd $(BIN_DIR) && $(MAKE) $(MAKE_ARGS) && cd ..
 else
  ifeq ($(OS), win)
	cd $(WIN_DIR) && $(MAKE) $(MAKE_ARGS) && cd ..
  endif
 endif

 ifeq ($(TST), true)
	cd $(TST_DIR) && $(MAKE) $(MAKE_ARGS) && cd ..
 endif

del: clean
	cd $(WIN_DIR) && $(MAKE) clean && cd ..
	cd $(BIN_DIR) && $(MAKE) clean && cd ..

clean:
	cd $(LIBALX_DIR) && $(MAKE) clean && cd ..
	cd $(MODULES_DIR) && $(MAKE) clean && cd ..
	cd $(OBJ_DIR) && $(MAKE) clean && cd ..
	cd $(TST_DIR) && $(MAKE) clean && cd ..
