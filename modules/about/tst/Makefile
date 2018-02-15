# -*- MakeFile -*-

# MACRO = substitute with this

OS = linux
TST = false
DBG = false

MAKE_ARGS = OS=$(OS) TST=$(TST) DGB=$(DBG)

# directories

ROOT_DIR = ../../../

MODULES_DIR = $(ROOT_DIR)/modules/
ABOUT_DIR = $(MODULES_DIR)/about/
TST_DIR = $(ABOUT_DIR)/tst/
OBJ_DIR = $(TST_DIR)/obj/

# target: dependencies
#	action

all:
	cd $(OBJ_DIR) && $(MAKE) $(MAKE_ARGS) && cd ..

clean:
	cd $(OBJ_DIR) && $(MAKE) clean && cd ..
