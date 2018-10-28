#!/usr/bin/make -f


# directories

LIBALX_INC_DIR = $(LIBALX_DIR)/inc/

INC_DIR = $(DATA_DIR)/inc/
SRC_DIR = $(DATA_DIR)/src/

# dependencies

_ALL	= data.o
ALL	= $(_ALL) data_mod.o

DATA_INC	= data.h
DATA_DEPS	= $(SRC_DIR)/data.c \
			$(patsubst %,$(INC_DIR)/%,$(DATA_INC))
DATA_INC_DIRS	= -I $(INC_DIR)

# target: dependencies
#	action

all: $(ALL)


data_mod.o: $(_ALL)
	$(Q)$(LD) -r $^ -o $@
	@echo  "	LD	$@"
	@echo  ""


data.s: $(DATA_DEPS)
	$(Q)$(CC) $(CFLAGS) $(DATA_INC_DIRS) -S $< -o $@ $(LIBS)
	@echo  "	CC	$@"
data.o: data.s
	$(Q)$(AS) $< -o $@
	@echo  "	AS	$@"


################################################################################
######## End of file ###########################################################
################################################################################
