# -*- MakeFile -*-

# MACRO = substitute with this

OS = linux
TST = false
DBG = false

MAKE_ARGS = OS=$(OS) TST=$(TST) DGB=$(DBG)


LIBALX_DIR = ./

OBJ_DIR = $(LIBALX_DIR)/obj/


# target: dependencies
#	action

all:
	cd $(OBJ_DIR) && $(MAKE) $(MAKE_ARGS) && cd ..


clean:
	cd $(OBJ_DIR) && $(MAKE) clean && cd ..
