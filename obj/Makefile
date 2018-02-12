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


ROOT_DIR = ../
BIN_DIR = $(ROOT_DIR)/bin/
INC_DIR = $(ROOT_DIR)/inc/
OBJ_DIR = $(ROOT_DIR)/obj/
SRC_DIR = $(ROOT_DIR)/src/

LIBALX_DIR = $(ROOT_DIR)/libalx/
LIBALX_HDR_DIR = $(LIBALX_DIR)/hdr/

ALL = main.o about.o desc.o dist.o menu.o

# dependencies

MAIN_INC = menu.h
MAIN_LIBALX = alx_ncur.h
MAIN_DEPS = $(SRC_DIR)/main.c $(patsubst %,$(INC_DIR)/%,$(PNPS_INC)) $(patsubst %,$(LIBALX_HDR_DIR)/%,$(MENU_LIBALX))


ABOU_INC = macros.h
ABOU_LIBALX = alx_file.h
ABOU_DEPS = $(SRC_DIR)/about.c $(patsubst %,$(INC_DIR)/%,$(ABOU_INC)) $(patsubst %,$(LIBALX_HDR_DIR)/%,$(MENU_LIBALX))

DESC_INC = calc.h desc.h
DESC_LIBALX = alx_getnum.h
DESC_DEPS = $(SRC_DIR)/desc.c $(patsubst %,$(INC_DIR)/%,$(DESC_INC)) $(patsubst %,$(LIBALX_HDR_DIR)/%,$(MENU_LIBALX))

DIST_INC = calc.h dist.h
DIST_LIBALX = alx_getnum.h
DIST_DEPS = $(SRC_DIR)/dist.c $(patsubst %,$(INC_DIR)/%,$(DIST_INC)) $(patsubst %,$(LIBALX_HDR_DIR)/%,$(MENU_LIBALX))

MENU_INC = macros.h about.h desc.h dist.h menu.h
MENU_LIBALX = alx_ncur.h
MENU_DEPS = $(SRC_DIR)/menu.c $(patsubst %,$(INC_DIR)/%,$(MENU_INC)) $(patsubst %,$(LIBALX_HDR_DIR)/%,$(MENU_LIBALX))



# target: dependencies
#	action

all: $(ALL)
	

main.o: $(MAIN_DEPS)
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBALX_HDR_DIR) -c $< -o $@ $(LIBS)

about.o: $(ABOU_DEPS)
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBALX_HDR_DIR) -c $< -o $@ $(LIBS)

desc.o: $(DESC_DEPS)
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBALX_HDR_DIR) -c $< -o $@ $(LIBS)

dist.o: $(DIST_DEPS)
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBALX_HDR_DIR) -c $< -o $@ $(LIBS)

menu.o: $(MENU_DEPS)
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBALX_HDR_DIR) -c $< -o $@ $(LIBS)


clean:
	rm -f $(ALL)