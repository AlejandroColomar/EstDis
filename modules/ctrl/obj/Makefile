# -*- MakeFile -*-

# MACRO = substitute with this

OS = linux
TST = false
DBG = false

ifeq ($(OS), linux)
	CC = gcc
	CFLAGS = -std=c11 -O3 -march=native
	LIBS = -l ncurses -l pthread -l m
else
 ifeq ($(OS), win)
	CC = gcc.exe
	CFLAGS = -std=c11 -O3
	LIBS = -l pdcurses -l m
 endif
endif

# directories

ROOT_DIR = ../../../

LIBALX_DIR = $(ROOT_DIR)/libalx/
LIBALX_INC_DIR = $(LIBALX_DIR)/inc/

GLOBAL_INC_DIR = $(ROOT_DIR)/inc/

MODULES_DIR = $(ROOT_DIR)/modules/

TUI_DIR = $(MODULES_DIR)/tui/
TUI_INC_DIR = $(TUI_DIR)/inc/

CTRL_DIR = $(MODULES_DIR)/ctrl/
INC_DIR = $(CTRL_DIR)/inc/
SRC_DIR = $(CTRL_DIR)/src/
TST_DIR = $(CTRL_DIR)/tst/

# dependencies

ALL = start.o

STRT_INC_LIBALX = alx_ncur.h
STRT_INC_GLOBAL = global_ext.h macros.h
STRT_INC_TUI = dist.h
STRT_INC = start.h
STRT_DEPS = $(SRC_DIR)/start.c \
			$(patsubst %,$(LIBALX_INC_DIR)/%,$(STRT_INC_LIBALX)) \
			$(patsubst %,$(GLOBAL_INC_DIR)/%,$(STRT_INC_GLOBAL)) \
			$(patsubst %,$(TUI_INC_DIR)/%,$(STRT_INC_TUI)) \
			$(patsubst %,$(INC_DIR)/%,$(STRT_INC))
STRT_INC_DIRS = -I $(LIBALX_INC_DIR) \
			-I $(GLOBAL_INC_DIR) \
			-I $(TUI_INC_DIR) \
			-I $(INC_DIR)

# target: dependencies
#	action

all: $(ALL)


start.o: $(STRT_DEPS)
	$(CC) $(CFLAGS) $(STRT_INC_DIRS) -c $< -o $@ $(LIBS)


clean:
	rm -f *.o
