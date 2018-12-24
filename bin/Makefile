# -*- MakeFile -*-

# directories

LIBALX_LIB_DIR	= $(LIBALX_DIR)/lib/

MODULES_TMP_DIR	= $(MODULES_DIR)/tmp/

TMP_DIR	= $(MAIN_DIR)/tmp/

# dependencies
_ALL	= $(BIN_NAME) $(BIN_NAME).exe

ALL	= $(BIN_NAME)

MAIN_OBJ_MODULES	= modules.o
MAIN_OBJS	= $(TMP_DIR)/main.o \
			$(patsubst %,$(MODULES_TMP_DIR)/%,$(MAIN_OBJ_MODULES))

# static libs
STATIC_LIB_LIBALX	= -L $(LIBALX_LIB_DIR) \
				-l alx-curses \
				-l alx-io \
				-l alx-base

STATIC_LIBS	= $(STATIC_LIB_LIBALX)


# target: dependencies
#	action

all: $(ALL)


ifeq ($(OS), linux)
$(BIN_NAME): $(MAIN_OBJS)
	@echo	"	CC	$@"
	$(Q)$(CC) $^ -o $@ $(STATIC_LIBS) $(LIBS)
else ifeq ($(OS), win)
$(BIN_NAME).exe: $(MAIN_OBJS)
	@echo	"	CC	$@"
	$(Q)$(CC) $^ -o $@ $(STATIC_LIBS) $(LIBS)
endif


clean:
	@echo  "	RM	$(_ALL)"
	$(Q)rm -f $(_ALL)
