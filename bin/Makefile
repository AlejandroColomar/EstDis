#! /usr/bin/make -f

# MACRO = substitute with this

# dependencies

OBJS		=							\
		$(TMP_DIR)/about.o					\
		$(TMP_DIR)/dist.o					\
		$(TMP_DIR)/main.o					\
		$(TMP_DIR)/menus.o					\
		$(TMP_DIR)/parse.o					\
		$(TMP_DIR)/start.o
DEPS_LIBS	= 							\
		$(LIBALX_LIB_DIR)/libalx-ncurses.a			\
		$(LIBALX_LIB_DIR)/libalx-stdio.a			\
		$(LIBALX_LIB_DIR)/libalx-math.a				\
		$(LIBALX_LIB_DIR)/libalx-stdlib.a

ALL	= $(BIN_NAME)

# static libs

STATIC_LIBS	= -L $(LIBALX_LIB_DIR)					\
		-l alx-ncurses						\
		-l alx-stdio						\
		-l alx-math						\
		-l alx-stdlib


# target: dependencies
#	action

PHONY := all
all: $(ALL)


$(BIN_NAME): $(OBJS) $(DEPS_LIBS)
	@echo	"	CC	$@"
	$(Q)$(CC) $(OBJS) -o $@ $(STATIC_LIBS) $(LIBS)


clean:
	@echo	"	RM	$(ALL)"
	$(Q)rm -f	$(ALL)

################################################################################
######## End of file ###########################################################
################################################################################
