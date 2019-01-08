# -*- MakeFile -*-

# MACRO = substitute with this

# directories

LIBALX_INC_DIR = $(LIBALX_DIR)/inc/

ABOUT_DIR = $(MODULES_DIR)/about/
ABOUT_INC_DIR = $(ABOUT_DIR)/inc/

PARSE_DIR = $(MODULES_DIR)/parse/
PARSE_INC_DIR = $(PARSE_DIR)/inc/

TUI_DIR = $(MODULES_DIR)/tui/
TUI_INC_DIR = $(TUI_DIR)/inc/

SRC_DIR	= $(MAIN_DIR)/src/

# dependencies

ALL	= main.o

MAIN_INC_LIBALX	= libalx/alx_ncur.h
MAIN_INC_ABOUT	= about.h
MAIN_INC_PARSE	= parse.h
MAIN_INC_TUI	= menus.h
MAIN_DEPS	= $(SRC_DIR)/main.c \
			$(patsubst %,$(LIBALX_INC_DIR)/%,$(MAIN_INC_LIBALX)) \
			$(patsubst %,$(ABOUT_INC_DIR)/%,$(MAIN_INC_ABOUT)) \
			$(patsubst %,$(PARSE_INC_DIR)/%,$(MAIN_INC_PARSE)) \
			$(patsubst %,$(TUI_INC_DIR)/%,$(MAIN_INC_TUI)) \
			$(patsubst %,$(INC_DIR)/%,$(MAIN_INC))
MAIN_INC_DIRS	= -I $(LIBALX_INC_DIR) \
			-I $(ABOUT_INC_DIR) \
			-I $(PARSE_INC_DIR) \
			-I $(TUI_INC_DIR)

# target: dependencies
#	action

all: $(ALL)


main.s: $(MAIN_DEPS)
	@echo	"	CC	$@"
	$(Q)$(CC) $(CFLAGS) $(MAIN_INC_DIRS) -S $< -o $@ $(LIBS)
main.o: main.s
	@echo	"	AS	$@"
	$(Q)$(AS) $< -o $@


clean:
	$(Q)rm -f *.o *.s

################################################################################
######## End of file ###########################################################
################################################################################
