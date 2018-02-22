# -*- MakeFile -*-

# MACRO = substitute with this

# directories

ESTDIS_DIR = ../../

MODULES_DIR = $(ESTDIS_DIR)/modules/
CALC_DIR = $(MODULES_DIR)/calc/
OBJ_DIR = $(CALC_DIR)/obj/
TST_DIR = $(CALC_DIR)/tst/

# target: dependencies
#	action

all:
	cd $(OBJ_DIR) && $(MAKE) && cd ..
 ifeq ($(TST), true)
	cd $(TST_DIR) && $(MAKE) && cd ..
 endif

clean:
	cd $(OBJ_DIR) && $(MAKE) clean && cd ..
	cd $(TST_DIR) && $(MAKE) clean && cd ..
