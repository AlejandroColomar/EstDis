#!/usr/bin/make -f


# directories

LIBALX_INC_DIR = $(LIBALX_DIR)/inc/

ABOUT_INC_DIR = $(ABOUT_DIR)/inc/
CALC_INC_DIR = $(CALC_DIR)/inc/
CTRL_INC_DIR = $(CTRL_DIR)/inc/
TUI_INC_DIR = $(TUI_DIR)/inc/

INC_DIR = $(PARSE_DIR)/inc/
SRC_DIR = $(PARSE_DIR)/src/

# dependencies

_ALL	= parse.o
ALL	= $(_ALL) parse_mod.o

PARSE_INC_LIBALX	= alx_input.h
PARSE_INC_ABOUT		= about.h
PARSE_INC_CALC		= calc.h
PARSE_INC_CTRL		= start.h
PARSE_INC_TUI		= menus.h
PARSE_INC		= parse.h
PARSE_DEPS	= $(SRC_DIR)/parse.c \
			$(patsubst %,$(LIBALX_INC_DIR)/%,$(PARSE_INC_LIBALX)) \
			$(patsubst %,$(ABOUT_INC_DIR)/%,$(PARSE_INC_ABOUT)) \
			$(patsubst %,$(CALC_INC_DIR)/%,$(PARSE_INC_CALC)) \
			$(patsubst %,$(CTRL_INC_DIR)/%,$(PARSE_INC_CTRL)) \
			$(patsubst %,$(TUI_INC_DIR)/%,$(PARSE_INC_TUI)) \
			$(patsubst %,$(INC_DIR)/%,$(PARSE_INC))
PARSE_INC_DIRS	= -I $(LIBALX_INC_DIR) \
			-I $(ABOUT_INC_DIR) \
			-I $(CALC_INC_DIR) \
			-I $(CTRL_INC_DIR) \
			-I $(TUI_INC_DIR) \
			-I $(INC_DIR)

# target: dependencies
#	action

all: $(ALL)


parse_mod.o: $(_ALL)
	$(Q)$(LD) -r $^ -o $@
	@echo  "	LD	$@"
	@echo  ""


parse.s: $(PARSE_DEPS)
	$(Q)$(CC) $(CFLAGS) $(PARSE_INC_DIRS) -S $< -o $@ $(LIBS)
	@echo  "	CC	$@"
parse.o: parse.s
	$(Q)$(AS) $< -o $@
	@echo  "	AS	$@"


################################################################################
######## End of file ###########################################################
################################################################################
