# -*- MakeFile -*-

# MACRO = substitute with this

OS = linux
TST = false
DBG = false

# directories

ROOT_DIR = ../../

MODULES_DIR = $(ROOT_DIR)/modules/
ABOUT_DIR = $(MODULES_DIR)/about/
OBJ_DIR = $(ABOUT_DIR)/obj/
TST_DIR = $(ABOUT_DIR)/tst/

# target: dependencies
#	action

all:
	cd $(OBJ_DIR) && $(MAKE) OS=$(OS) && cd ..

clean:
	cd $(OBJ_DIR) && $(MAKE) clean && cd ..
