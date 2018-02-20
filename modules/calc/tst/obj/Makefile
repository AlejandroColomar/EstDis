# -*- MakeFile -*-

# MACRO = substitute with this

# directories

ESTDIS_DIR = ../../../../

LIBALX_DIR = $(ESTDIS_DIR)/libalx/
LIBALX_INC_DIR = $(LIBALX_DIR)/inc/

GLOBAL_INC_DIR = $(ESTDIS_DIR)/inc/

MODULES_DIR = $(ESTDIS_DIR)/modules/
ABOUT_DIR = $(MODULES_DIR)/about/
ABOUT_INC_DIR = $(ABOUT_DIR)/inc/

TST_DIR = $(ABOUT_DIR)/tst/
SRC_DIR = $(TST_DIR)/src/


# dependencies

ALL = tst_about.o

TST_INC_LIBALX = alx_file.h alx_ncur.h
TST_INC_GLOBAL = macros.h
TST_INC_ABOUT = about.h
TST_DEPS = $(SRC_DIR)/tst_about.c \
			$(patsubst %,$(LIBALX_INC_DIR)/%,$(TST_INC_LIBALX)) \
			$(patsubst %,$(GLOBAL_INC_DIR)/%,$(TST_INC_GLOBAL)) \
			$(patsubst %,$(ABOUT_INC_DIR)/%,$(TST_INC_ABOUT))
ABOU_INC_DIRS = -I $(LIBALX_INC_DIR) \
			-I $(GLOBAL_INC_DIR) \
			-I $(ABOUT_INC_DIR)

# target: dependencies
#	action

all: $(ALL)
	

tst_about.o: $(TST_DEPS)
	$(CC) $(CFLAGS) $(ABOU_INC_DIRS) -c $< -o $@ $(LIBS)


clean:
	rm -f *.o
