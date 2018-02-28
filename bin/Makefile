# -*- MakeFile -*-

# MACRO = substitute with this

# directories

ESTDIS_DIR = ../

LIBALX_DIR = $(ESTDIS_DIR)/libalx/
LIBALX_OBJ_DIR = $(LIBALX_DIR)/obj/

MODULES_DIR = $(ESTDIS_DIR)/modules/

ABOUT_DIR = $(MODULES_DIR)/about/
ABOUT_OBJ_DIR = $(ABOUT_DIR)/obj/

CALC_DIR = $(MODULES_DIR)/calc/
CALC_OBJ_DIR = $(CALC_DIR)/obj/

CTRL_DIR = $(MODULES_DIR)/ctrl/
CTRL_OBJ_DIR = $(CTRL_DIR)/obj/

DATA_DIR = $(MODULES_DIR)/data/
DATA_OBJ_DIR = $(DATA_DIR)/obj/

PARSE_DIR = $(MODULES_DIR)/parse/
PARSE_OBJ_DIR = $(PARSE_DIR)/obj/

TUI_DIR = $(MODULES_DIR)/tui/
TUI_OBJ_DIR = $(TUI_DIR)/obj/

OBJ_DIR = $(ESTDIS_DIR)/obj/

# dependencies

ALL = estdis

ESTDIS_OBJ_LIBALX = alx_file.o alx_getnum.o alx_math.o alx_ncur.o
ESTDIS_OBJ_ABOUT = about.o
ESTDIS_OBJ_CALC = calc.o
ESTDIS_OBJ_CTRL = start.o
ESTDIS_OBJ_DATA = data.o
ESTDIS_OBJ_PARSE = parse.o
ESTDIS_OBJ_TUI = dist.o menus.o
ESTDIS_OBJS = $(OBJ_DIR)/main.o \
			$(patsubst %,$(LIBALX_OBJ_DIR)/%,$(ESTDIS_OBJ_LIBALX)) \
			$(patsubst %,$(ABOUT_OBJ_DIR)/%,$(ESTDIS_OBJ_ABOUT)) \
			$(patsubst %,$(CALC_OBJ_DIR)/%,$(ESTDIS_OBJ_CALC)) \
			$(patsubst %,$(CTRL_OBJ_DIR)/%,$(ESTDIS_OBJ_CTRL)) \
			$(patsubst %,$(DATA_OBJ_DIR)/%,$(ESTDIS_OBJ_DATA)) \
			$(patsubst %,$(PARSE_OBJ_DIR)/%,$(ESTDIS_OBJ_PARSE)) \
			$(patsubst %,$(TUI_OBJ_DIR)/%,$(ESTDIS_OBJ_TUI))


# target: dependencies
#	action

all: $(ALL)


estdis: $(ESTDIS_OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)


clean:
	rm -f $(ALL)
