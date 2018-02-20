# -*- MakeFile -*-

# MACRO = substitute with this

# directories

ESTDIS_DIR = ../

MODULES_DIR = $(ESTDIS_DIR)/modules/

ABOUT_DIR = $(MODULES_DIR)/about/
CALC_DIR = $(MODULES_DIR)/calc/
CTRL_DIR = $(MODULES_DIR)/ctrl/
TUI_DIR = $(MODULES_DIR)/tui/

# dependencies


# target: dependencies
#	action

all:
	cd $(ABOUT_DIR) && $(MAKE) && cd ..
	cd $(CALC_DIR) && $(MAKE) && cd ..
	cd $(CTRL_DIR) && $(MAKE) && cd ..
	cd $(TUI_DIR) && $(MAKE) && cd ..


clean:
	cd $(ABOUT_DIR) && $(MAKE) clean && cd ..
	cd $(CALC_DIR) && $(MAKE) clean && cd ..
	cd $(CTRL_DIR) && $(MAKE) clean && cd ..
	cd $(TUI_DIR) && $(MAKE) clean && cd ..
