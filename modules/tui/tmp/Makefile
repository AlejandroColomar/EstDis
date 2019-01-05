# -*- MakeFile -*-

# MACRO = substitute with this

# directories

LIBALX_INC_DIR = $(LIBALX_DIR)/inc/

GLOBAL_INC_DIR = $(MAIN_DIR)/inc/

ABOUT_INC_DIR = $(ABOUT_DIR)/inc/
CALC_INC_DIR = $(CALC_DIR)/inc/
CTRL_INC_DIR = $(CTRL_DIR)/inc/

INC_DIR = $(TUI_DIR)/inc/
SRC_DIR = $(TUI_DIR)/src/

# dependencies

_ALL	= dist.o menus.o
ALL	= $(_ALL) tui_mod.o

DIST_INC_LIBALX	= alx_input.h
DIST_INC_CALC	= calc.h
DIST_INC	= dist.h
DIST_DEPS	= $(SRC_DIR)/dist.c \
			$(patsubst %,$(LIBALX_INC_DIR)/%,$(DIST_INC_LIBALX)) \
			$(patsubst %,$(CALC_INC_DIR)/%,$(DIST_INC_CALC)) \
			$(patsubst %,$(INC_DIR)/%,$(DIST_INC))
DIST_INC_DIRS	= -I $(LIBALX_INC_DIR) \
			-I $(CALC_INC_DIR) \
			-I $(INC_DIR)

MENU_INC_LIBALX	= alx_ncur.h
MENU_INC_GLOBAL	= macros.h
MENU_INC_ABOUT	= about.h
MENU_INC_CTRL	= start.h
MENU_INC	= menus.h
MENU_DEPS	= $(SRC_DIR)/menus.c \
			$(patsubst %,$(LIBALX_INC_DIR)/%,$(MENU_INC_LIBALX)) \
			$(patsubst %,$(GLOBAL_INC_DIR)/%,$(MENU_INC_GLOBAL)) \
			$(patsubst %,$(ABOUT_INC_DIR)/%,$(MENU_INC_ABOUT)) \
			$(patsubst %,$(CTRL_INC_DIR)/%,$(MENU_INC_CTRL)) \
			$(patsubst %,$(INC_DIR)/%,$(MENU_INC))
MENU_INC_DIRS	= -I $(LIBALX_INC_DIR) \
			-I $(GLOBAL_INC_DIR) \
			-I $(ABOUT_INC_DIR) \
			-I $(CTRL_INC_DIR) \
			-I $(INC_DIR)

# target: dependencies
#	action

all: $(ALL)


tui_mod.o: $(_ALL)
	@echo  "	LD	$@"
	$(Q)$(LD) -r $^ -o $@


dist.s: $(DIST_DEPS)
	@echo  "	CC	$@"
	$(Q)$(CC) $(CFLAGS) $(DIST_INC_DIRS) -S $< -o $@ $(LIBS)
dist.o: dist.s
	@echo  "	AS	$@"
	$(Q)$(AS) $< -o $@

menus.s: $(MENU_DEPS)
	@echo  "	CC	$@"
	$(Q)$(CC) $(CFLAGS) $(MENU_INC_DIRS) -S $< -o $@ $(LIBS)
menus.o: menus.s
	@echo  "	AS	$@"
	$(Q)$(AS) $< -o $@


clean:
	rm -f *.o
