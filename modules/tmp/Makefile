#!/usr/bin/make -f

# MACRO = substitute with this

# directories

ABOUT_TMP_DIR	= $(ABOUT_DIR)/tmp/
CALC_TMP_DIR	= $(CALC_DIR)/tmp/
CTRL_TMP_DIR	= $(CTRL_DIR)/tmp/
PARSE_TMP_DIR	= $(PARSE_DIR)/tmp/
TUI_TMP_DIR	= $(TUI_DIR)/tmp/

# dependencies

ALL = modules.o

MODS_OBJ_ABOUT	= about_mod.o
MODS_OBJ_CALC	= calc_mod.o
MODS_OBJ_CTRL	= ctrl_mod.o
MODS_OBJ_PARSE	= parse_mod.o
MODS_OBJ_TUI	= tui_mod.o
MODS_OBJS	= $(patsubst %,$(ABOUT_TMP_DIR)/%,$(MODS_OBJ_ABOUT)) \
			$(patsubst %,$(CALC_TMP_DIR)/%,$(MODS_OBJ_CALC)) \
			$(patsubst %,$(CTRL_TMP_DIR)/%,$(MODS_OBJ_CTRL)) \
			$(patsubst %,$(PARSE_TMP_DIR)/%,$(MODS_OBJ_PARSE)) \
			$(patsubst %,$(TUI_TMP_DIR)/%,$(MODS_OBJ_TUI))

# target: dependencies
#	action

all: $(ALL)


modules.o: $(MODS_OBJS)
	@echo  "	LD	$@"
	$(Q)$(LD) -r $^ -o $@


clean:
	$(Q)rm -f *.o
