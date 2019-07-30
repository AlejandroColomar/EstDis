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
		dist.o							\
		main.o							\
		menus.o							\
		parse.o							\
		share.o							\
		start.o

DIST_INC	=							\
		$(INC_DIR)/estadistica/dist.h				\
		$(LIBALX_INC_DIR)/libalx/base/compiler/unused.h		\
		$(LIBALX_INC_DIR)/libalx/base/stdio/get.h		\
		$(LIBALX_INC_DIR)/libalx/base/stdio/printf/sbprintf.h	\
		$(LIBALX_INC_DIR)/libalx/extra/gsl/distributions/binomial.h \
		$(LIBALX_INC_DIR)/libalx/extra/gsl/distributions/exponential.h \
		$(LIBALX_INC_DIR)/libalx/extra/gsl/distributions/geometric.h \
		$(LIBALX_INC_DIR)/libalx/extra/gsl/distributions/normal.h \
		$(LIBALX_INC_DIR)/libalx/extra/gsl/distributions/poisson.h \
		$(LIBALX_INC_DIR)/libalx/extra/gsl/distributions/uniform.h
DIST_SRC	=							\
		$(SRC_DIR)/dist.c

MAIN_INC	=							\
		$(LIBALX_INC_DIR)/libalx/extra/ncurses/common.h		\
		$(INC_DIR)/estadistica/menus.h				\
		$(INC_DIR)/estadistica/parse.h				\
		$(INC_DIR)/estadistica/share.h
MAIN_SRC	=							\
		$(SRC_DIR)/main.c

MENUS_INC	=							\
		$(INC_DIR)/estadistica/menus.h				\
		$(LIBALX_INC_DIR)/libalx/base/compiler/size.h		\
		$(LIBALX_INC_DIR)/libalx/base/stdio/seekc.h		\
		$(LIBALX_INC_DIR)/libalx/extra/ncurses/common.h		\
		$(LIBALX_INC_DIR)/libalx/extra/ncurses/menu.h		\
		$(INC_DIR)/estadistica/share.h				\
		$(INC_DIR)/estadistica/start.h
MENUS_SRC	=							\
		$(SRC_DIR)/menus.c

PARSE_INC	=							\
		$(INC_DIR)/estadistica/parse.h				\
		$(LIBALX_INC_DIR)/libalx/base/stdio/sscan.h		\
		$(INC_DIR)/estadistica/menus.h				\
		$(INC_DIR)/estadistica/share.h				\
		$(INC_DIR)/estadistica/start.h
PARSE_SRC	=							\
		$(SRC_DIR)/parse.c

SHARE_INC	=							\
		$(INC_DIR)/estadistica/share.h				\
		$(LIBALX_INC_DIR)/libalx/base/compiler/size.h		\
		$(LIBALX_INC_DIR)/libalx/base/errno/perror.h		\
		$(LIBALX_INC_DIR)/libalx/base/stdio/printf/sbprintf.h
SHARE_SRC	=							\
		$(SRC_DIR)/share.c

START_INC	=							\
		$(INC_DIR)/estadistica/start.h				\
		$(INC_DIR)/estadistica/dist.h				\
		$(INC_DIR)/estadistica/share.h
START_SRC	=							\
		$(SRC_DIR)/start.c

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(OBJ)


dist.s: $(DIST_SRC) $(DIST_INC)
	@echo	"	CC	estadistica/tmp/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
dist.o: dist.s
	@echo	"	AS	estadistica/tmp/$@"
	$(Q)$(AS) $< -o $@

main.s: $(MAIN_SRC) $(MAIN_INC)
	@echo	"	CC	estadistica/tmp/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
main.o: main.s
	@echo	"	AS	estadistica/tmp/$@"
	$(Q)$(AS) $< -o $@

menus.s: $(MENUS_SRC) $(MENUS_INC)
	@echo	"	CC	estadistica/tmp/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
menus.o: menus.s
	@echo	"	AS	estadistica/tmp/$@"
	$(Q)$(AS) $< -o $@

parse.s: $(PARSE_SRC) $(PARSE_INC)
	@echo	"	CC	estadistica/tmp/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
parse.o: parse.s
	@echo	"	AS	estadistica/tmp/$@"
	$(Q)$(AS) $< -o $@

share.s: $(SHARE_SRC) $(SHARE_INC)
	@echo	"	CC	estadistica/tmp/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
share.o: share.s
	@echo	"	AS	estadistica/tmp/$@"
	$(Q)$(AS) $< -o $@

start.s: $(START_SRC) $(START_INC)
	@echo	"	CC	estadistica/tmp/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
start.o: start.s
	@echo	"	AS	estadistica/tmp/$@"
	$(Q)$(AS) $< -o $@


PHONY += clean
clean:
	@echo	"	RM	*.o *.s"
	$(Q)rm -f	*.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)


################################################################################
######## End of file ###########################################################
################################################################################
