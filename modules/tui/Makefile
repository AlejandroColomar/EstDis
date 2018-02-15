# -*- MakeFile -*-

# MACRO = substitute with this

OS = linux
TST = false
DBG = false

MAKE_ARGS = OS=$(OS) TST=$(TST) DGB=$(DBG)

# directories

ROOT_DIR = ../../

MODULES_DIR = $(ROOT_DIR)/modules/
TUI_DIR = $(MODULES_DIR)/tui/
OBJ_DIR = $(TUI_DIR)/obj/
TST_DIR = $(TUI_DIR)/tst/

# target: dependencies
#	action

all:
	cd $(OBJ_DIR) && $(MAKE) $(MAKE_ARGS) && cd ..

clean:
	cd $(OBJ_DIR) && $(MAKE) clean && cd ..
