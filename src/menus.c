/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	GPL-2.0-only			      *
 ******************************************************************************/
/*
 * + Menu:
 *	+ Continue:
 *		- Run
 *		- Help
 *		+ Select:
 *			- 1 Var
 *			- 2 Var
 *			- Binomial
 *			- Poisson
 *			- Geometrica
 *			- Hipergeometrica
 *			- Uniforme
 *			- Exponencial
 *			- Gauss(Normal)
 *			- ..
 *		+ Verbose: Not yet
 *			- ..
 *		- ..
 *	- Disclaimer
 *	- Terms & conditions
 *	- Exit program
 */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "estadistica/menus.h"

#include <stdbool.h>
#include <stdint.h>

#include <ncurses.h>

#include "libalx/base/compiler/size.h"
#include "libalx/base/stdio/seekc.h"
#include "libalx/extra/ncurses/common.h"
#include "libalx/extra/ncurses/menu.h"

#include "estadistica/share.h"
#include "estadistica/start.h"


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
bool	flag_exit;
int	flag_verbose;
int	menu_iface_mode;


/******************************************************************************
 ******* static functions (prototypes) ****************************************
 ******************************************************************************/
static	void	menu_continue	(void);
static	void	menu_select	(void);
static	void	menu_verbose	(void);


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
void	menu_main		(void)
{
	int_fast8_t	h, w;
	bool		wh;
	int_fast8_t	sw;

	h	= 23;
	w	= 80;

	const struct Alx_Ncurses_Menu	mnu[]	= {
		{8, 4, "[0]	Exit program"},
		{2, 4, "[1]	Continue"},
		{4, 4, "[2]	Disclaimer of warranty"},
		{5, 4, "[3]	Terms & conditions"}
	};

	wh	= true;
	while (wh) {
		sw	= alx_ncurses_menu(h, w, ARRAY_SIZE(mnu), mnu, "MENU:");

		switch (sw) {
		case 0:
			wh = false;
			break;
		case 1:
			menu_continue();
			break;
		case 2:
			alx_ncurses_pause();
			print_share_file(SHARE_DISCLAIMER);
			alx_ncurses_resume();
			break;
		case 3:
			alx_ncurses_pause();
			print_share_file(SHARE_LICENSE);
			alx_ncurses_resume();
			break;
		}
	}
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/
static	void	menu_continue	(void)
{
	int_fast8_t	h, w;
	bool		wh;
	int_fast8_t	sw;

	h	= 23;
	w	= 80;

	const struct Alx_Ncurses_Menu	mnu[]	= {
		{7, 4, "[0]	Back"},
		{2, 4, "[1]	Run"},
		{3, 4, "[2]	Help"},
		{4, 4, "[3]	Select problem type"},
		{5, 4, "[4]	Change verbose"}
	};

	wh	= true;
	while (wh) {
		sw = alx_ncurses_menu(h, w, ARRAY_SIZE(mnu), mnu, "CONTINUE:");

		switch (sw) {
		case 0:
			wh = false;
			break;

		case 1:
			alx_ncurses_pause();
			start_switch();
			printf("Press ENTER to continue");
			alx_wait4enter();
			alx_ncurses_resume();
			break;

		case 2:
			alx_ncurses_pause();
			help_switch();
			printf("Press ENTER to continue");
			alx_wait4enter();
			alx_ncurses_resume();
			break;

		case 3:
			menu_select();
			break;

		case 4:
			menu_verbose();
			break;
		}
	}
}

static	void	menu_select	(void)
{
	int_fast8_t	h, w;
	int_fast8_t	opt;

	h	= 23;
	w	= 80;

	const struct Alx_Ncurses_Menu	mnu[]	= {
		{13, 4, "[0]	Back"},
		{2, 4, "[1]	1 Variable"},
		{3, 4, "[2]	2 Variables"},
		{5, 4, "[3]	Binomial"},
		{6, 4, "[4]	Poisson"},
		{7, 4, "[5]	Geometrica"},
		{8, 4, "[6]	Hipergeometrica"},
		{9, 4, "[7]	Uniforme"},
		{10, 4, "[8]	Exponencial"},
		{11, 4, "[9]	Gauss(Normal)"}
	};

	opt	= alx_ncurses_menu(h, w, ARRAY_SIZE(mnu), mnu, "SELECT:");
	if (opt)
		start_mode	= opt;
}

static	void	menu_verbose	(void)
{
	int_fast8_t	h, w;

	h	= 23;
	w	= 80;

	const struct Alx_Ncurses_Menu	mnu[]	= {
		{7, 4, "[0]	Show NOTHING"},
		{2, 4, "[1]	Show only solution"},
		{3, 4, "[2]	Show short help"},
		{4, 4, "[3]	Show help"},
# if (DBG)
		{5, 4, "[4]	Show everything  (DBG)"}
# else
		{5, 4, "[4]	DBG (Not active)"}
# endif
	};

	flag_verbose = alx_ncurses_menu(h, w, ARRAY_SIZE(mnu), mnu, "VERBOSE:");
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
