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

PARSE_DIR = $(MODULES_DIR)/parse/
INC_DIR = $(PARSE_DIR)/inc/
SRC_DIR = $(PARSE_DIR)/src/
TST_DIR = $(PARSE_DIR)/tst/

# dependencies

ALL = parse.o

PARSE_INC_ABOUT = about.h
PARSE_INC_DATA = data.h
PARSE_DEPS = $(SRC_DIR)/parse.c \
			$(patsubst %,$(LIBALX_INC_DIR)/%,$(PARSE_INC_LIBALX)) \
			$(patsubst %,$(ABOUT_INC_DIR)/%,$(PARSE_INC_ABOUT)) \
			$(patsubst %,$(DATA_INC_DIR)/%,$(PARSE_INC_DATA))
PARSE_INC_DIRS = -I $(LIBALX_INC_DIR) \
			-I $(ABOUT_INC_DIR) \
			-I $(DATA_INC_DIR) \

# target: dependencies
#	action

all: $(ALL)


parse.o: $(PARSE_DEPS)
	$(CC) $(CFLAGS) $(PARSE_INC_DIRS) -c $< -o $@ $(LIBS)


clean:
	rm -f *.o
