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


LIBALX_DIR = ../
HDR_DIR = $(LIBALX_DIR)/hdr/
OBJ_DIR = $(LIBALX_DIR)/obj/
SRC_DIR = $(LIBALX_DIR)/src/

ALL = alx_file.o alx_getnum.o alx_math.o alx_ncur.o alx_seed.o

FILE_INC = alx_file.h
FILE_DEPS = $(SRC_DIR)/alx_file.c $(patsubst %,$(HDR_DIR)/%,$(FILE_INC))

GETN_INC = alx_getnum.h
GETN_DEPS = $(SRC_DIR)/alx_getnum.c $(patsubst %,$(HDR_DIR)/%,$(GETN_INC))

MATH_INC = alx_math.h
MATH_DEPS = $(SRC_DIR)/alx_math.c $(patsubst %,$(HDR_DIR)/%,$(MATH_INC))

NCUR_INC = alx_ncur.h
NCUR_DEPS = $(SRC_DIR)/alx_ncur.c $(patsubst %,$(HDR_DIR)/%,$(NCUR_INC))

SEED_INC = alx_seed.h
SEED_DEPS = $(SRC_DIR)/alx_seed.c $(patsubst %,$(HDR_DIR)/%,$(SEED_INC))

# target: dependencies
#	action

all: $(ALL)


alx_file.o: $(FILE_DEPS)
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBS)

alx_getnum.o: $(GETN_DEPS)
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBS)

alx_math.o: $(MATH_DEPS)
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBS)

alx_ncur.o: $(NCUR_DEPS)
	$(CC) $(CFLAGS) -I $(HDR_DIR) -c $< -o $@ $(LIBS)

alx_seed.o: $(SEED_DEPS)
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBS)


clean:
	rm -f $(ALL)