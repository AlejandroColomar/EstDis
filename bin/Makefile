#! /usr/bin/make -f

# MACRO = substitute with this

# dependencies

OBJS		=							\
		$(TMP_DIR)/dist.o					\
		$(TMP_DIR)/main.o					\
		$(TMP_DIR)/menus.o					\
		$(TMP_DIR)/parse.o					\
		$(TMP_DIR)/share.o					\
		$(TMP_DIR)/start.o

ALL	= $(BIN_NAME) size


# target: dependencies
#	action

PHONY := all
all: $(ALL)


$(BIN_NAME): $(OBJS)
	@echo	"	CC	$@"
	$(Q)$(CC) $(OBJS) -o $@ $(STATIC_LIBS) $(LIBS)

PHONY += size
size: $(BIN_NAME)
	@echo	"	SZ	$(BIN_NAME)"
	$(Q)$(SZ) $(BIN_NAME)


clean:
	@echo	"	RM	$(ALL)"
	$(Q)rm -f	$(ALL)

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)


################################################################################
######## End of file ###########################################################
################################################################################
