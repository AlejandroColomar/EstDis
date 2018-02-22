# -*- MakeFile -*-

# MACRO = substitute with this

# directories

ESTDIS_DIR = ../

LIBALX_DIR = $(ESTDIS_DIR)/libalx/
LIBALX_INC_DIR = $(LIBALX_DIR)/inc/

MODULES_DIR = $(ESTDIS_DIR)/modules/
TUI_DIR = $(MODULES_DIR)/tui/
TUI_INC_DIR = $(TUI_DIR)/inc/

INC_DIR = $(ESTDIS_DIR)/inc/
SRC_DIR = $(ESTDIS_DIR)/src/

# dependencies

ALL = main.o

MAIN_INC_LIBALX = alx_ncur.h
MAIN_INC_TUI = menus.h
MAIN_INC = global.h
MAIN_DEPS = $(SRC_DIR)/main.c \
			$(patsubst %,$(LIBALX_INC_DIR)/%,$(MAIN_INC_LIBALX)) \
			$(patsubst %,$(TUI_INC_DIR)/%,$(MAIN_INC_TUI)) \
			$(patsubst %,$(INC_DIR)/%,$(MAIN_INC))
MAIN_INC_DIRS = -I $(LIBALX_INC_DIR) \
			-I $(TUI_INC_DIR) \
			-I $(INC_DIR)

# target: dependencies
#	action

all: $(ALL)


main.o: $(MAIN_DEPS)
	$(CC) $(CFLAGS) $(MAIN_INC_DIRS) -c $< -o $@ $(LIBS)


clean:
	rm -f *.o
