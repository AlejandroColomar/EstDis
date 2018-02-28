# -*- MakeFile -*-

# MACRO = substitute with this

# directories

ESTDIS_DIR = ../../../

LIBALX_DIR = $(ESTDIS_DIR)/libalx/
LIBALX_INC_DIR = $(LIBALX_DIR)/inc/

GLOBAL_INC_DIR = $(ESTDIS_DIR)/inc/

MODULES_DIR = $(ESTDIS_DIR)/modules/

ABOUT_DIR = $(MODULES_DIR)/about/
ABOUT_INC_DIR = $(ABOUT_DIR)/inc/

CALC_DIR = $(MODULES_DIR)/calc/
CALC_INC_DIR = $(CALC_DIR)/inc/

DATA_DIR = $(MODULES_DIR)/data/
DATA_INC_DIR = $(DATA_DIR)/inc/

CTRL_DIR = $(MODULES_DIR)/ctrl/
CTRL_INC_DIR = $(CTRL_DIR)/inc/

TUI_DIR = $(MODULES_DIR)/tui/
INC_DIR = $(TUI_DIR)/inc/
SRC_DIR = $(TUI_DIR)/src/
TST_DIR = $(TUI_DIR)/tst/

# dependencies

ALL = dist.o menus.o

DIST_INC_LIBALX = alx_getnum.h
DIST_INC_CALC = calc.h
DIST_INC_DATA = data.h
DIST_INC = dist.h
DIST_DEPS = $(SRC_DIR)/dist.c \
			$(patsubst %,$(LIBALX_INC_DIR)/%,$(DIST_INC_LIBALX)) \
			$(patsubst %,$(CALC_INC_DIR)/%,$(DIST_INC_CALC)) \
			$(patsubst %,$(DATA_INC_DIR)/%,$(DIST_INC_DATA)) \
			$(patsubst %,$(INC_DIR)/%,$(DIST_INC))
DIST_INC_DIRS = -I $(LIBALX_INC_DIR) \
			-I $(CALC_INC_DIR) \
			-I $(DATA_INC_DIR) \
			-I $(INC_DIR)

MENU_INC_LIBALX = alx_ncur.h
MENU_INC_GLOBAL = macros.h
MENU_INC_ABOUT = about.h
MENU_INC_DATA = data.h
MENU_INC_CTRL = start.h
MENU_INC = menus.h
MENU_DEPS = $(SRC_DIR)/menus.c \
			$(patsubst %,$(LIBALX_INC_DIR)/%,$(MENU_INC_LIBALX)) \
			$(patsubst %,$(GLOBAL_INC_DIR)/%,$(MENU_INC_GLOBAL)) \
			$(patsubst %,$(ABOUT_INC_DIR)/%,$(MENU_INC_ABOUT)) \
			$(patsubst %,$(CTRL_INC_DIR)/%,$(MENU_INC_CTRL)) \
			$(patsubst %,$(DATA_INC_DIR)/%,$(MENU_INC_DATA)) \
			$(patsubst %,$(INC_DIR)/%,$(MENU_INC))
MENU_INC_DIRS = -I $(LIBALX_INC_DIR) \
			-I $(GLOBAL_INC_DIR) \
			-I $(ABOUT_INC_DIR) \
			-I $(CTRL_INC_DIR) \
			-I $(DATA_INC_DIR) \
			-I $(INC_DIR)

# target: dependencies
#	action

all: $(ALL)


dist.o: $(DIST_DEPS)
	$(CC) $(CFLAGS) $(DIST_INC_DIRS) -c $< -o $@ $(LIBS)

menus.o: $(MENU_DEPS)
	$(CC) $(CFLAGS) $(MENU_INC_DIRS) -c $< -o $@ $(LIBS)


clean:
	rm -f *.o
