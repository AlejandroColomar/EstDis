# -*- MakeFile -*-

# MACRO = substitute with this

# directories

ESTDIS_DIR = ../../../

LIBALX_DIR = $(ESTDIS_DIR)/libalx/
LIBALX_INC_DIR = $(LIBALX_DIR)/inc/

GLOBAL_INC_DIR = $(ESTDIS_DIR)/inc/

MODULES_DIR = $(ESTDIS_DIR)/modules/

ABOUT_DIR = $(MODULES_DIR)/about/
INC_DIR = $(ABOUT_DIR)/inc/
SRC_DIR = $(ABOUT_DIR)/src/
TST_DIR = $(ABOUT_DIR)/tst/

# dependencies

ALL = about.o

ABOU_INC_LIBALX = alx_file.h
ABOU_INC_GLOBAL = macros.h
ABOU_DEPS = $(SRC_DIR)/about.c \
			$(patsubst %,$(LIBALX_INC_DIR)/%,$(ABOU_INC_LIBALX)) \
			$(patsubst %,$(GLOBAL_INC_DIR)/%,$(ABOU_INC_GLOBAL))
ABOU_INC_DIRS = -I $(LIBALX_INC_DIR) \
			-I $(GLOBAL_INC_DIR)

# target: dependencies
#	action

all: $(ALL)
	

about.o: $(ABOU_DEPS)
	$(CC) $(CFLAGS) $(ABOU_INC_DIRS) -c $< -o $@ $(LIBS)


clean:
	rm -f *.o
