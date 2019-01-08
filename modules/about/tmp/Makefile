#!/usr/bin/make -f


LIBALX_INC_DIR = $(LIBALX_DIR)/inc/

GLOBAL_INC_DIR = $(MAIN_DIR)/inc/

INC_DIR = $(ABOUT_DIR)/inc/
SRC_DIR = $(ABOUT_DIR)/src/

# dependencies

_ALL	= about.o
ALL	= $(_ALL) about_mod.o

ABOU_INC_LIBALX	= libalx/alx_file.h
ABOU_INC_GLOBAL	= macros.h
ABOU_INC	= about.h
ABOU_DEPS	= $(SRC_DIR)/about.c \
			$(patsubst %,$(LIBALX_INC_DIR)/%,$(ABOU_INC_LIBALX)) \
			$(patsubst %,$(GLOBAL_INC_DIR)/%,$(ABOU_INC_GLOBAL)) \
			$(patsubst %,$(INC_DIR)/%,$(ABOU_INC))
ABOU_INC_DIRS	= -I $(LIBALX_INC_DIR) \
			-I $(GLOBAL_INC_DIR) \
			-I $(INC_DIR)

# target: dependencies
#	action

all: $(ALL)


about_mod.o: $(_ALL)
	@echo  "	LD	$@"
	$(Q)$(LD) -r $^ -o $@


about.s: $(ABOU_DEPS)
	@echo  "	CC	$@"
	$(Q)$(CC) $(CFLAGS) $(ABOU_INC_DIRS) -S $< -o $@ $(LIBS)
about.o: about.s
	@echo  "	AS	$@"
	$(Q)$(AS) $< -o $@


################################################################################
######## End of file ###########################################################
################################################################################
