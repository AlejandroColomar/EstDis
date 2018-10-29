#!/usr/bin/make -f

# MACRO = substitute with this

# directories

ABOUT_DIR = $(MODULES_DIR)/about/
CALC_DIR = $(MODULES_DIR)/calc/
CTRL_DIR = $(MODULES_DIR)/ctrl/
PARSE_DIR = $(MODULES_DIR)/parse/
TUI_DIR = $(MODULES_DIR)/tui/

TMP_DIR = $(MODULES_DIR)/tmp/

export	ABOUT_DIR
export	CALC_DIR
export	CTRL_DIR
export	PARSE_DIR
export	TUI_DIR

# dependencies


# target: dependencies
#	action

all:
	$(Q)cd $(ABOUT_DIR) && $(MAKE) && cd ..
	$(Q)cd $(CALC_DIR) && $(MAKE) && cd ..
	$(Q)cd $(CTRL_DIR) && $(MAKE) && cd ..
	$(Q)cd $(PARSE_DIR) && $(MAKE) && cd ..
	$(Q)cd $(TUI_DIR) && $(MAKE) && cd ..
	$(Q)cd $(TMP_DIR) && $(MAKE) && cd ..


clean:
	$(Q)find . -type f -name '*.o' -exec rm '{}' '+'
	$(Q)find . -type f -name '*.s' -exec rm '{}' '+'
	@echo  "Clean modules"

################################################################################
######## End of file ###########################################################
################################################################################
