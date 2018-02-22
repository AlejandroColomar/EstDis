# -*- MakeFile -*-

# MACRO = substitute with this

# directories

ESTDIS_DIR = ../../../../

LIBALX_DIR = $(ESTDIS_DIR)/libalx/
LIBALX_INC_DIR = $(LIBALX_DIR)/inc/

GLOBAL_INC_DIR = $(ESTDIS_DIR)/inc/

MODULES_DIR = $(ESTDIS_DIR)/modules/
CALC_DIR = $(MODULES_DIR)/calc/
CALC_INC_DIR = $(CALC_DIR)/inc/

TST_DIR = $(CALC_DIR)/tst/
SRC_DIR = $(TST_DIR)/src/


# dependencies

ALL = tst_about.o

TST_INC_LIBALX = alx_file.h alx_ncur.h
TST_INC_GLOBAL = macros.h
TST_INC_CALC = calc.h
TST_DEPS = $(SRC_DIR)/tst_calc.c \
			$(patsubst %,$(LIBALX_INC_DIR)/%,$(TST_INC_LIBALX)) \
			$(patsubst %,$(GLOBAL_INC_DIR)/%,$(TST_INC_GLOBAL)) \
			$(patsubst %,$(CALC_INC_DIR)/%,$(TST_INC_CALC))
CALC_INC_DIRS = -I $(LIBALX_INC_DIR) \
			-I $(GLOBAL_INC_DIR) \
			-I $(CALC_INC_DIR)

# target: dependencies
#	action

all: $(ALL)
	

tst_about.o: $(TST_DEPS)
	$(CC) $(CFLAGS) $(CALC_INC_DIRS) -c $< -o $@ $(LIBS)


clean:
	rm -f *.o
