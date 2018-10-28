#!/usr/bin/make -f

# directories

TMP_DIR	= $(CALC_DIR)/tmp/
TST_DIR	= $(CALC_DIR)/tst/

# target: dependencies
#	action

all:
	$(Q)cd $(TMP_DIR) && $(MAKE) && cd ..
 ifeq ($(TST), true)
	$(Q)cd $(TST_DIR) && $(MAKE) && cd ..
 endif


################################################################################
######## End of file ###########################################################
################################################################################
