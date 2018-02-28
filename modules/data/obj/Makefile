# -*- MakeFile -*-

# MACRO = substitute with this

# directories

ESTDIS_DIR = ../../../

LIBALX_DIR = $(ESTDIS_DIR)/libalx/
LIBALX_INC_DIR = $(LIBALX_DIR)/inc/

MODULES_DIR = $(ESTDIS_DIR)/modules/

DATA_DIR = $(MODULES_DIR)/data/
INC_DIR = $(DATA_DIR)/inc/
SRC_DIR = $(DATA_DIR)/src/
TST_DIR = $(DATA_DIR)/tst/

# dependencies

ALL = data.o

DATA_DEPS = $(SRC_DIR)/data.c
DATA_INC_DIRS =

# target: dependencies
#	action

all: $(ALL)


data.o: $(DATA_DEPS)
	$(CC) $(CFLAGS) $(DATA_INC_DIRS) -c $< -o $@ $(LIBS)


clean:
	rm -f *.o
