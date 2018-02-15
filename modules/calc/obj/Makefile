# -*- MakeFile -*-

# MACRO = substitute with this

OS = linux
TST = false
DBG = false

ifeq ($(OS), linux)
	CC = gcc
	CFLAGS = -std=c11 -O3 -march=native
	LIBS = -l pthread -l m
else
 ifeq ($(OS), win)
	CC = gcc.exe
	CFLAGS = -std=c11 -O3
	LIBS = -l m
 endif
endif


ROOT_DIR = ../../../

LIBALX_DIR = $(ROOT_DIR)/libalx/
LIBALX_INC_DIR = $(LIBALX_DIR)/inc/

GLOBAL_INC_DIR = $(ROOT_DIR)/inc/

MODULES_DIR = $(ROOT_DIR)/modules/

CALC_DIR = $(MODULES_DIR)/calc/
INC_DIR = $(CALC_DIR)/inc/
SRC_DIR = $(CALC_DIR)/src/
TST_DIR = $(CALC_DIR)/tst/

# dependencies

ALL =

# target: dependencies
#	action

all: $(ALL)


clean:
	rm -f *.o
