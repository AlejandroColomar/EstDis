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
	@echo	'	MAKE	modules:	about'
	$(Q)$(MAKE) -C $(ABOUT_DIR)
	@echo	'	MAKE	modules:	calc'
	$(Q)$(MAKE) -C $(CALC_DIR)
	@echo	'	MAKE	modules:	ctrl'
	$(Q)$(MAKE) -C $(CTRL_DIR)
	@echo	'	MAKE	modules:	parse'
	$(Q)$(MAKE) -C $(PARSE_DIR)
	@echo	'	MAKE	modules:	tui'
	$(Q)$(MAKE) -C $(TUI_DIR)
	@echo	'	MAKE	modules.o'
	$(Q)$(MAKE) -C $(TMP_DIR)


clean:
	@echo	"	RM	*.o *.s"
	$(Q)find . -type f -name '*.o' -exec rm '{}' '+'
	$(Q)find . -type f -name '*.s' -exec rm '{}' '+'

################################################################################
######## End of file ###########################################################
################################################################################
