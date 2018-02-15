# -*- MakeFile -*-

# MACRO = substitute with this

OS = linux
TST = false
DBG = false

MAKE_ARGS = OS=$(OS) TST=$(TST) DGB=$(DBG)

# directories

ROOT_DIR = ../../

MODULES_DIR = $(ROOT_DIR)/modules/
CALC_DIR = $(MODULES_DIR)/calc/
OBJ_DIR = $(CALC_DIR)/obj/
TST_DIR = $(CALC_DIR)/tst/

# target: dependencies
#	action

all:
	cd $(OBJ_DIR) && $(MAKE) $(MAKE_ARGS) && cd ..

clean:
	cd $(OBJ_DIR) && $(MAKE) clean && cd ..
