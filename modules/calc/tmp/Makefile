#!/usr/bin/make -f


LIBALX_INC_DIR = $(LIBALX_DIR)/inc/

INC_DIR = $(CALC_DIR)/inc/
SRC_DIR = $(CALC_DIR)/src/
TST_DIR = $(CALC_DIR)/tst/

# dependencies

_ALL	= calc.o
ALL	= $(_ALL) calc_mod.o

CALC_INC_LIBALX	= libalx/alx_math.h
CALC_INC	= calc.h
CALC_DEPS	= $(SRC_DIR)/calc.c \
			$(patsubst %,$(LIBALX_INC_DIR)/%,$(CALC_INC_LIBALX)) \
			$(patsubst %,$(INC_DIR)/%,$(CALC_INC))
CALC_INC_DIRS	= -I $(LIBALX_INC_DIR) \
			-I $(INC_DIR)

# target: dependencies
#	action

all: $(ALL)


calc_mod.o: $(_ALL)
	@echo  "	LD	$@"
	$(Q)$(LD) -r $^ -o $@


calc.s: $(CALC_DEPS)
	@echo  "	CC	$@"
	$(Q)$(CC) $(CFLAGS) $(CALC_INC_DIRS) -S $< -o $@ $(LIBS)
calc.o: calc.s
	@echo  "	AS	$@"
	$(Q)$(AS) $< -o $@


################################################################################
######## End of file ###########################################################
################################################################################
