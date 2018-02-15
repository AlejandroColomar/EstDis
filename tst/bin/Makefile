# -*- MakeFile -*-

# MACRO = substitute with this

OS = linux

CC = gcc
CFLAGS = -std=c11 -O3 -march=native
LIBS = -l ncurses -l pthread -l m


ROOT_DIR = ../../

LIBALX_DIR = $(ROOT_DIR)/libalx/
LIBALX_OBJ_DIR = $(LIBALX_DIR)/obj/

MODULES_DIR = $(ROOT_DIR)/modules/
ABOUT_DIR = $(MODULES_DIR)/about/
ABOUT_OBJ_DIR = $(ABOUT_DIR)/obj/

TST_ABOUT_DIR = $(ABOUT_DIR)/tst/
TST_ABOUT_OBJ_DIR = $(TST_ABOUT_DIR)/obj/

# dependencies

ALL = tst_about

TST_ABOUT_OBJ_LIBALX = alx_file.o alx_ncur.o
TST_ABOUT_OBJ_ABOUT = about.o
TST_ABOUT_OBJS = $(TST_ABOUT_OBJ_DIR)/tst_about.o \
			$(patsubst %,$(LIBALX_OBJ_DIR)/%,$(TST_ABOUT_OBJ_LIBALX)) \
			$(patsubst %,$(ABOUT_OBJ_DIR)/%,$(TST_ABOUT_OBJ_ABOUT))

# target: dependencies
#	action

all: $(ALL)


tst_about: $(TST_ABOUT_OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)


clean:
	rm -f $(ALL)
