#! /usr/bin/make -f

################################################################################
# Copyright (C) 2019	Alejandro Colomar Andrés
# SPDX-License-Identifier:	GPL-2.0-only
################################################################################
# *AUTHOR*
# FULL NAME	"Alejandro Colomar Andrés"
# EMAIL		"1903716@gmail.com"
################################################################################

################################################################################
# dependencies

OBJ		=							\
		about.o							\
		dist.o							\
		main.o							\
		menus.o							\
		parse.o							\
		start.o

ABOUT_INC	=							\
		$(INC_DIR)/estadistica/about.h				\
		$(LIBALX_INC_DIR)/libalx/base/stdio/sprint_file.h
ABOUT_SRC	=							\
		$(SRC_DIR)/about.c

DIST_INC	=							\
		$(INC_DIR)/estadistica/dist.h				\
		$(LIBALX_INC_DIR)/libalx/base/math/descriptive_statistics_1var.h \
		$(LIBALX_INC_DIR)/libalx/base/math/descriptive_statistics_2var.h \
		$(LIBALX_INC_DIR)/libalx/base/math/distribution_binomial.h \
		$(LIBALX_INC_DIR)/libalx/base/math/distribution_exponential.h \
		$(LIBALX_INC_DIR)/libalx/base/math/distribution_geometric.h \
		$(LIBALX_INC_DIR)/libalx/base/math/distribution_normal.h \
		$(LIBALX_INC_DIR)/libalx/base/math/distribution_poisson.h \
		$(LIBALX_INC_DIR)/libalx/base/math/distribution_uniform.h \
		$(LIBALX_INC_DIR)/libalx/base/math/fast.h		\
		$(LIBALX_INC_DIR)/libalx/base/stdio/get.h
DIST_SRC	=							\
		$(SRC_DIR)/dist.c

MAIN_INC	=							\
		$(LIBALX_INC_DIR)/libalx/extra/ncurses/common.h		\
		$(INC_DIR)/estadistica/about.h				\
		$(INC_DIR)/estadistica/menus.h				\
		$(INC_DIR)/estadistica/parse.h
MAIN_SRC	=							\
		$(SRC_DIR)/main.c

MENUS_INC	=							\
		$(INC_DIR)/estadistica/menus.h				\
		$(LIBALX_INC_DIR)/libalx/extra/ncurses/common.h		\
		$(LIBALX_INC_DIR)/libalx/extra/ncurses/menu.h		\
		$(INC_DIR)/estadistica/about.h				\
		$(INC_DIR)/estadistica/start.h
MENUS_SRC	=							\
		$(SRC_DIR)/menus.c

PARSE_INC	=							\
		$(INC_DIR)/estadistica/parse.h				\
		$(LIBALX_INC_DIR)/libalx/base/stdio/sscan.h		\
		$(INC_DIR)/estadistica/about.h				\
		$(INC_DIR)/estadistica/menus.h				\
		$(INC_DIR)/estadistica/start.h
PARSE_SRC	=							\
		$(SRC_DIR)/parse.c

START_INC	=							\
		$(INC_DIR)/estadistica/start.h				\
		$(INC_DIR)/estadistica/about.h				\
		$(INC_DIR)/estadistica/dist.h
START_SRC	=							\
		$(SRC_DIR)/start.c

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(OBJ)


about.s: $(ABOUT_SRC) $(ABOUT_INC)
	@echo	"	CC	estadistica/tmp/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBALX_INC_DIR) -S $< -o $@
about.o: about.s
	@echo	"	AS	estadistica/tmp/$@"
	$(Q)$(AS) $< -o $@

dist.s: $(DIST_SRC) $(DIST_INC)
	@echo	"	CC	estadistica/tmp/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBALX_INC_DIR) -S $< -o $@
dist.o: dist.s
	@echo	"	AS	estadistica/tmp/$@"
	$(Q)$(AS) $< -o $@

main.s: $(MAIN_SRC) $(MAIN_INC)
	@echo	"	CC	estadistica/tmp/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBALX_INC_DIR) -S $< -o $@
main.o: main.s
	@echo	"	AS	estadistica/tmp/$@"
	$(Q)$(AS) $< -o $@

menus.s: $(MENUS_SRC) $(MENUS_INC)
	@echo	"	CC	estadistica/tmp/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBALX_INC_DIR) -S $< -o $@
menus.o: menus.s
	@echo	"	AS	estadistica/tmp/$@"
	$(Q)$(AS) $< -o $@

parse.s: $(PARSE_SRC) $(PARSE_INC)
	@echo	"	CC	estadistica/tmp/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBALX_INC_DIR) -S $< -o $@
parse.o: parse.s
	@echo	"	AS	estadistica/tmp/$@"
	$(Q)$(AS) $< -o $@

start.s: $(START_SRC) $(START_INC)
	@echo	"	CC	estadistica/tmp/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBALX_INC_DIR) -S $< -o $@
start.o: start.s
	@echo	"	AS	estadistica/tmp/$@"
	$(Q)$(AS) $< -o $@


PHONY += clean
clean:
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)


################################################################################
######## End of file ###########################################################
################################################################################
