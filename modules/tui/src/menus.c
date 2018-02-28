
/******************************************************************************
 * This program is free software; you can redistribute it and/or modify	      *
 * it under the terms of the GNU General Public License as published by	      *
 * the Free Software Foundation; either version 2 of the License, or          *
 * (at your option) any later version.					      *
 *									      *
 * This program is distributed in the hope that it will be useful,	      *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of	      *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the	      *
 * GNU General Public License for more details.				      *
 *									      *
 * You should have received a copy of the GNU General Public License	      *
 * along with this program; if not, see the file COPYING, or write	      *
 * to the Free Software Foundation, Inc.				      *
 ******************************************************************************/


/******************************************************************************
 ******| include |*************************************************************
 ******************************************************************************/
		/* int64_t */
	#include <inttypes.h>
		/* curses interface */
	#include <curses.h>
//	#include <pthread.h>
//	#include <stdarg.h>
		/* bool */
	#include <stdbool.h>
//	#include <stdint.h>
	#include <stdio.h>
//	#include <stdlib.h>
//	#include <string.h>
//	#include <sys/types.h>
//	#include <threads.h>
//	#include <time.h>
//	#include <unistd.h>
//	#include <wchar.h>

		/* menu & curses */
	#include "alx_ncur.h"

		/* print functions */
	#include "about.h"
		/* variables */
	#include "data.h"
		/* start */
	#include "start.h"

		/* DBG */
	#include "macros.h"


/******************************************************************************
 ******| menu |****************************************************************
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
	 *	- Copyright
	 *	- Disclaimer
	 *	- Terms & conditions
	 *	- Exit program
	 */


/******************************************************************************
 ******| submenus |************************************************************
 ******************************************************************************/
static	void	menu_continue	(void);
static	void	menu_select	(void);
static	void	menu_verbose	(void);


/******************************************************************************
 ******| main menu |***********************************************************
 ******************************************************************************/
void	menu_main		(void)
{
	int64_t	sw;
	bool	wh;
	WINDOW		*win;
	const int64_t	h =	11;
	const int64_t	w =	34;

	const int64_t		N = 5;
	const struct alx_option	mnu[5] =	{{8, 4, "[0]	Exit program"},
						{2, 4, "[1]	Continue"},
						{4, 4, "[2]	Copyright"},
						{5, 4, "[3]	Disclaimer of warranty"},
						{6, 4, "[4]	Terms & conditions"}
				};

	wh = true;
	while (wh) {
		sw =	alx_menu(h, w, N, mnu, "MENU:");

		switch (sw) {
		case 0:
			wh = false;
			break;

		case 1:
			menu_continue();
			break;

		case 2:
			alx_pause_curses();
			print_cpright();
			alx_resume_curses();
			break;

		case 3:
			alx_pause_curses();
			print_disclaim();
			alx_resume_curses();
			break;

		case 4:
			alx_pause_curses();
			print_license();
			alx_resume_curses();
			break;
		}
	}
}


/******************************************************************************
 ******| submenus |************************************************************
 ******************************************************************************/
static	void	menu_continue	(void)
{
	int64_t	sw;
	bool	wh;
	WINDOW		*win;
	const int64_t	h =	10;
	const int64_t	w =	35;

	const int64_t		N = 5;
	const struct alx_option	mnu[5] =	{{7, 4, "[0]	Back"},
						{2, 4, "[1]	Run"},
						{3, 4, "[2]	Help"},
						{4, 4, "[3]	Select problem type"},
						{5, 4, "[4]	Change verbose"}
				};

	wh = true;
	while (wh) {
		sw =	alx_menu(h, w, N, mnu, "CONTINUE:");

		switch (sw) {
		case 0:
			wh = false;
			break;

		case 1:
			alx_pause_curses();
			start_switch();
			alx_resume_curses();
			break;

		case 2:
			alx_pause_curses();
			help_switch();
			alx_resume_curses();
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
	int64_t	buff;
	bool	wh;
	WINDOW		*win;
	const int64_t	h =	16;
	const int64_t	w =	50;

	const int64_t		N = 10;
	const struct alx_option	mnu[10] =	{{13, 4, "[0]	Back"},
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

	buff =	alx_menu(h, w, N, mnu, "SELECT:");

	if (buff) {
		flag_s =	buff;
	}
}

static	void	menu_verbose	(void)
{
	const int64_t	h =	10;
	const int64_t	w =	51;

	const int64_t		N = 5;
	const struct alx_option	mnu[5] =	{{7, 4, "[0]	Show NOTHING"},
						{2, 4, "[1]	Show only solution"},
						{3, 4, "[2]	Show short help"},
						{4, 4, "[3]	Show help"},
# if (DBG)
						{5, 4, "[4]	Show everything  (DBG)"}
# else
						{5, 4, "[4]	DBG (Not active)"}
# endif
				};

	flag_V =	alx_menu(h, w, N, mnu, "VERBOSE:");
}
