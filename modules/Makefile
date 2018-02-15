# -*- MakeFile -*-

# MACRO = substitute with this

OS = linux
TST = false
DBG = false

MAKE_ARGS = OS=$(OS) TST=$(TST) DGB=$(DBG)

# directories

ROOT_DIR = ../

MODULES_DIR = $(ROOT_DIR)/modules/

ABOUT_DIR = $(MODULES_DIR)/about/
CALC_DIR = $(MODULES_DIR)/calc/
CTRL_DIR = $(MODULES_DIR)/ctrl/
TUI_DIR = $(MODULES_DIR)/tui/

# dependencies


# target: dependencies
#	action

all:
	cd $(ABOUT_DIR) && $(MAKE) $(MAKE_ARGS) && cd ..
	cd $(CALC_DIR) && $(MAKE) $(MAKE_ARGS) && cd ..
	cd $(CTRL_DIR) && $(MAKE) $(MAKE_ARGS) && cd ..
	cd $(TUI_DIR) && $(MAKE) $(MAKE_ARGS) && cd ..


clean:
	cd $(ABOUT_DIR) && $(MAKE) clean && cd ..
	cd $(CALC_DIR) && $(MAKE) clean && cd ..
	cd $(CTRL_DIR) && $(MAKE) clean && cd ..
	cd $(TUI_DIR) && $(MAKE) clean && cd ..
