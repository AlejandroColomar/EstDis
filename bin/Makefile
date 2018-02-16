# -*- MakeFile -*-

# MACRO = substitute with this

CC = gcc
CFLAGS = -std=c11 -O3 -march=native
LIBS = -l ncurses -l pthread -l m


ROOT_DIR = ../

LIBALX_DIR = $(ROOT_DIR)/libalx/
LIBALX_OBJ_DIR = $(LIBALX_DIR)/obj/

MODULES_DIR = $(ROOT_DIR)/modules/

ABOUT_DIR = $(MODULES_DIR)/about/
ABOUT_OBJ_DIR = $(ABOUT_DIR)/obj/

CALC_DIR = $(MODULES_DIR)/calc/
CALC_OBJ_DIR = $(CALC_DIR)/obj/

CTRL_DIR = $(MODULES_DIR)/ctrl/
CTRL_OBJ_DIR = $(CTRL_DIR)/obj/

TUI_DIR = $(MODULES_DIR)/tui/
TUI_OBJ_DIR = $(TUI_DIR)/obj/

OBJ_DIR = $(ROOT_DIR)/obj/

# dependencies

ALL = estdis

ESTDIS_OBJ_LIBALX = alx_file.o alx_getnum.o alx_math.o alx_ncur.o
ESTDIS_OBJ_ABOUT = about.o
ESTDIS_OBJ_CALC = calc.o
ESTDIS_OBJ_CTRL = start.o
ESTDIS_OBJ_TUI = dist.o menu.o
ESTDIS_OBJS = $(OBJ_DIR)/main.o \
			$(patsubst %,$(LIBALX_OBJ_DIR)/%,$(ESTDIS_OBJ_LIBALX)) \
			$(patsubst %,$(ABOUT_OBJ_DIR)/%,$(ESTDIS_OBJ_ABOUT)) \
			$(patsubst %,$(CALC_OBJ_DIR)/%,$(ESTDIS_OBJ_CALC)) \
			$(patsubst %,$(CTRL_OBJ_DIR)/%,$(ESTDIS_OBJ_CTRL)) \
			$(patsubst %,$(TUI_OBJ_DIR)/%,$(ESTDIS_OBJ_TUI))


# target: dependencies
#	action

all: $(ALL)


estdis: $(ESTDIS_OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)


clean:
	rm -f $(ALL)
