# -*- MakeFile -*-

# MACRO = substitute with this

OS = linux
TST = false
DBG = false

MAKE_ARGS = OS=$(OS) TST=$(TST) DGB=$(DBG)

# directories

ROOT_DIR = ../../

MODULES_DIR = $(ROOT_DIR)/modules/
ABOUT_DIR = $(MODULES_DIR)/about/
OBJ_DIR = $(ABOUT_DIR)/obj/
TST_DIR = $(ABOUT_DIR)/tst/

# target: dependencies
#	action

all:
	cd $(OBJ_DIR) && $(MAKE) $(MAKE_ARGS) && cd ..
 ifeq ($(TST), true)
	cd $(TST_DIR) && $(MAKE) $(MAKE_ARGS) && cd ..
 endif

clean:
	cd $(OBJ_DIR) && $(MAKE) clean && cd ..
	cd $(TST_DIR) && $(MAKE) clean && cd ..
