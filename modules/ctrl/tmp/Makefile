#!/usr/bin/make -f

# directories

LIBALX_INC_DIR = $(LIBALX_DIR)/inc/

ABOUT_INC_DIR = $(ABOUT_DIR)/inc/
DATA_INC_DIR = $(DATA_DIR)/inc/
TUI_INC_DIR = $(TUI_DIR)/inc/

INC_DIR = $(CTRL_DIR)/inc/
SRC_DIR = $(CTRL_DIR)/src/
TST_DIR = $(CTRL_DIR)/tst/

# dependencies

_ALL	= start.o
ALL	= $(_ALL) ctrl_mod.o

STRT_INC_LIBALX	= libalx/alx_ncur.h
STRT_INC_ABOUT	= about.h
STRT_INC_TUI	= dist.h
STRT_INC	= start.h
STRT_DEPS	= $(SRC_DIR)/start.c \
			$(patsubst %,$(LIBALX_INC_DIR)/%,$(STRT_INC_LIBALX)) \
			$(patsubst %,$(ABOUT_INC_DIR)/%,$(STRT_INC_ABOUT)) \
			$(patsubst %,$(DATA_INC_DIR)/%,$(STRT_INC_DATA)) \
			$(patsubst %,$(TUI_INC_DIR)/%,$(STRT_INC_TUI)) \
			$(patsubst %,$(INC_DIR)/%,$(STRT_INC))
STRT_INC_DIRS	= -I $(LIBALX_INC_DIR) \
			-I $(ABOUT_INC_DIR) \
			-I $(DATA_INC_DIR) \
			-I $(TUI_INC_DIR) \
			-I $(INC_DIR)

# target: dependencies
#	action

all: $(ALL)


ctrl_mod.o: $(_ALL)
	@echo  "	LD	$@"
	$(Q)$(LD) -r $^ -o $@


start.s: $(STRT_DEPS)
	@echo  "	CC	$@"
	$(Q)$(CC) $(CFLAGS) $(STRT_INC_DIRS) -S $< -o $@ $(LIBS)
start.o: start.s
	@echo  "	AS	$@"
	$(Q)$(AS) $< -o $@


################################################################################
######## End of file ###########################################################
################################################################################
