# -*- MakeFile -*-

# MACRO = substitute with this


ESTDIS_DIR = ../../../

LIBALX_DIR = $(ESTDIS_DIR)/libalx/
LIBALX_INC_DIR = $(LIBALX_DIR)/inc/

MODULES_DIR = $(ESTDIS_DIR)/modules/

CALC_DIR = $(MODULES_DIR)/calc/
INC_DIR = $(CALC_DIR)/inc/
SRC_DIR = $(CALC_DIR)/src/
TST_DIR = $(CALC_DIR)/tst/

# dependencies

ALL = calc.o

CALC_INC_LIBALX = alx_math.h
CALC_INC = calc.h
CALC_DEPS = $(SRC_DIR)/calc.c \
			$(patsubst %,$(LIBALX_INC_DIR)/%,$(CALC_INC_LIBALX)) \
			$(patsubst %,$(INC_DIR)/%,$(CALC_INC))
CALC_INC_DIRS = -I $(LIBALX_INC_DIR) \
			-I $(INC_DIR)

# target: dependencies
#	action

all: $(ALL)
	

calc.o: $(CALC_DEPS)
	$(CC) $(CFLAGS) $(CALC_INC_DIRS) -c $< -o $@ $(LIBS)


clean:
	rm -f *.o
