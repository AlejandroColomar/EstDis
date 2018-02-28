# -*- MakeFile -*-

# MACRO = substitute with this

# directories

ESTDIS_DIR = ../../../

LIBALX_DIR = $(ESTDIS_DIR)/libalx/
LIBALX_INC_DIR = $(LIBALX_DIR)/inc/

MODULES_DIR = $(ESTDIS_DIR)/modules/

ABOUT_DIR = $(MODULES_DIR)/about/
ABOUT_INC_DIR = $(ABOUT_DIR)/inc/

DATA_DIR = $(MODULES_DIR)/data/
DATA_INC_DIR = $(DATA_DIR)/inc/

TUI_DIR = $(MODULES_DIR)/tui/
TUI_INC_DIR = $(TUI_DIR)/inc/

CTRL_DIR = $(MODULES_DIR)/ctrl/
INC_DIR = $(CTRL_DIR)/inc/
SRC_DIR = $(CTRL_DIR)/src/
TST_DIR = $(CTRL_DIR)/tst/

# dependencies

ALL = start.o

STRT_INC_LIBALX = alx_ncur.h
STRT_INC_ABOUT = about.h
STRT_INC_DATA = data.h
STRT_INC_TUI = dist.h
STRT_INC = start.h
STRT_DEPS = $(SRC_DIR)/start.c \
			$(patsubst %,$(LIBALX_INC_DIR)/%,$(STRT_INC_LIBALX)) \
			$(patsubst %,$(ABOUT_INC_DIR)/%,$(STRT_INC_ABOUT)) \
			$(patsubst %,$(DATA_INC_DIR)/%,$(STRT_INC_DATA)) \
			$(patsubst %,$(TUI_INC_DIR)/%,$(STRT_INC_TUI)) \
			$(patsubst %,$(INC_DIR)/%,$(STRT_INC))
STRT_INC_DIRS = -I $(LIBALX_INC_DIR) \
			-I $(ABOUT_INC_DIR) \
			-I $(DATA_INC_DIR) \
			-I $(TUI_INC_DIR) \
			-I $(INC_DIR)

# target: dependencies
#	action

all: $(ALL)


start.o: $(STRT_DEPS)
	$(CC) $(CFLAGS) $(STRT_INC_DIRS) -c $< -o $@ $(LIBS)


clean:
	rm -f *.o
