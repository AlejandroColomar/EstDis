/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	GPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stdio.h>

#include <libalx/extra/ncurses/common.h>

#include "estadistica/share.h"
#include "estadistica/menus.h"
#include "estadistica/parse.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enums ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* structs / unions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* variables ************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static functions (prototypes) ****************************************
 ******************************************************************************/
static	void	init_all	(int argc, char *argv[]);
static	void	cleanup		(void);


/******************************************************************************
 ******* main *****************************************************************
 ******************************************************************************/
int	main	(int argc, char *argv[])
{

	init_all(argc, argv);

	print_share_file(SHARE_COPYRIGHT);

	alx_ncurses_resume();
	menu_main();
	alx_ncurses_pause();

	cleanup();

	return	0;
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/
static	void	init_all	(int argc, char *argv[])
{

	alx_ncurses_init();
	alx_ncurses_pause();

	parser(argc, argv);
}

static	void	cleanup		(void)
{

	alx_ncurses_resume();
	alx_ncurses_deinit();
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
