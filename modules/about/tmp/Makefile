#!/usr/bin/make -f


LIBALX_INC_DIR = $(LIBALX_DIR)/inc/

GLOBAL_INC_DIR = $(MAIN_DIR)/inc/

INC_DIR = $(ABOUT_DIR)/inc/
SRC_DIR = $(ABOUT_DIR)/src/

# dependencies

_ALL	= about.o
ALL	= $(_ALL) about_mod.o

ABOU_INC_LIBALX	= alx_file.h
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
	$(Q)$(LD) -r $^ -o $@
	@echo  "	LD	$@"
	@echo  ""
	

about.s: $(ABOU_DEPS)
	$(Q)$(CC) $(CFLAGS) $(ABOU_INC_DIRS) -S $< -o $@ $(LIBS)
	@echo  "	CC	$@"
about.o: about.s
	$(Q)$(AS) $< -o $@
	@echo  "	AS	$@"


################################################################################
######## End of file ###########################################################
################################################################################
