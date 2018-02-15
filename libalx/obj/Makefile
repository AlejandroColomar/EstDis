# -*- MakeFile -*-

# MACRO = substitute with this

OS = linux

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

LIBALX_DIR = ../

INC_DIR = $(LIBALX_DIR)/inc/
OBJ_DIR = $(LIBALX_DIR)/obj/
SRC_DIR = $(LIBALX_DIR)/src/

# dependencies

ALL = alx_file.o alx_getnum.o alx_math.o alx_ncur.o alx_seed.o

FILE_INC = alx_file.h
FILE_DEPS = $(SRC_DIR)/alx_file.c $(patsubst %,$(INC_DIR)/%,$(FILE_INC))
FILE_INC_DIRS =

GETN_INC = alx_getnum.h
GETN_DEPS = $(SRC_DIR)/alx_getnum.c $(patsubst %,$(INC_DIR)/%,$(GETN_INC))
GETN_INC_DIRS =

MATH_INC = alx_math.h
MATH_DEPS = $(SRC_DIR)/alx_math.c $(patsubst %,$(INC_DIR)/%,$(MATH_INC))
MATH_INC_DIRS =

NCUR_INC = alx_ncur.h
NCUR_DEPS = $(SRC_DIR)/alx_ncur.c $(patsubst %,$(INC_DIR)/%,$(NCUR_INC))
NCUR_INC_DIRS = -I $(INC_DIR)

SEED_INC = alx_seed.h
SEED_DEPS = $(SRC_DIR)/alx_seed.c $(patsubst %,$(INC_DIR)/%,$(SEED_INC))
SEED_INC_DIRS =

# target: dependencies
#	action

all: $(ALL)


alx_file.o: $(FILE_DEPS)
	$(CC) $(CFLAGS) $(FILE_INC_DIRS) -c $< -o $@ $(LIBS)

alx_getnum.o: $(GETN_DEPS)
	$(CC) $(CFLAGS) $(GETN_INC_DIRS) -c $< -o $@ $(LIBS)

alx_math.o: $(MATH_DEPS)
	$(CC) $(CFLAGS) $(MATH_INC_DIRS) -c $< -o $@ $(LIBS)

alx_ncur.o: $(NCUR_DEPS)
	$(CC) $(CFLAGS) $(NCUR_INC_DIRS) -c $< -o $@ $(LIBS)

alx_seed.o: $(SEED_DEPS)
	$(CC) $(CFLAGS) $(SEED_INC_DIRS) -c $< -o $@ $(LIBS)


clean:
	rm -f *.o
