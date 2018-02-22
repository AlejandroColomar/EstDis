# -*- MakeFile -*-

# MACRO = substitute with this

# directories

ESTDIS_DIR = ../

TST_DIR = $(ESTDIS_DIR)/tst/
BIN_DIR = $(TST_DIR)/bin/
WIN_DIR = $(TST_DIR)/win/


# target: dependencies
#	action

all:

 ifeq ($(OS), linux)
	cd $(BIN_DIR) && $(MAKE) && cd ..
 else
  ifeq ($(OS), win)
	cd $(WIN_DIR) && $(MAKE) && cd ..
  endif
 endif

clean:
	cd $(BIN_DIR) && $(MAKE) clean && cd ..
	cd $(WIN_DIR) && $(MAKE) clean && cd ..
