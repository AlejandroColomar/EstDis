////////////////----------------------------------------////////////////
////////////////        EstDis                          ////////////////
////////////////----------------------------------------////////////////

	/*
	 * EstDis	This is a solver of statistics problems.
	 * Copyright (C) 2016 Alejandro Colomar Andrés
	 *
	 * This program is free software: you can redistribute it and/or
	 * modify it under the terms of the GNU General Public License
	 * as published by the Free Software Foundation, either version
	 * 3 of the License, or (at your option) any later version.

	 * This program is distributed in the hope that it will be
	 * useful, but WITHOUT ANY WARRANTY; without even the implied
	 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
	 * PURPOSE.  See the GNU General Public License for more
	 * details.
	 *
	 * You should have received a copy of the GNU General Public
	 * License along with this program.
	 * If not, see <http://www.gnu.org/licenses/>.
	 */

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

//	#include <getopt.h>
	#include <inttypes.h>
	#include <curses.h>
//	#include <pthread.h>
//	#include <stdarg.h>
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

//	#include "alx_file.h"
//	#include "alx_getnum.h"
//	#include "alx_math.h"
	#include "alx_ncur.h"
//	#include "alx_seed.h"

	#include "about.h"
//	#include "desc.h"
//	#include "dist.h"
//	#include "menu.h"
	#include "start.h"

	#include "global_ext.h"
	#include "macros.h"

	/*
	 * + Menu:
	 *	+ Continue:
	 *		+ Descriptiva:
	 *			- 1 Variable
	 *			- 2 Variables
	 *			- ..
	 *		+ Distribuciones:
	 *			- Binomial
	 *			- help
	 *			- Poisson
	 *			- help
	 *			- Geometrica
	 *			- help
	 *			- Hipergeometrica
	 *			- help
	 *			- Uniforme
	 *			- help
	 *			- Exponencial
	 *			- help
	 *			- Gauss(Normal)
	 *			- help
	 *			- ..
	 *		- ..
	 *	- Disclaimer
	 *	- License
	 *	- Exit program
	 */
/*----------------------------------------------------------------------------*/

static	void	menu_continue	(void);
static	void	menu_select	(void);
static	void	menu_verbose	(void);



//------------------------------------------------------------------------------
//--| menu |--------------------------------------------------------------------
//------------------------------------------------------------------------------

void	menu_main		(void)
{
	int64_t	sw;
	bool	wh;
	WINDOW		*win;
	const int64_t	h =	10;
	const int64_t	w =	34;
	const int64_t	r =	1;
	const int64_t	c =	(80 - w) / 2;

	const int64_t		len = 4;
	const struct alx_option	mnu[4] =	{{7, 4, "[0]	Exit program"},
						{2, 4, "[1]	Continue"},
						{4, 4, "[2]	Disclaimer of warranty"},
						{5, 4, "[3]	Terms and conditions"}};

	wh = true;
	while (wh) {
		win =	newwin(h, w, r, c);
		keypad(win, true);

		alx_w_title(win, "MENU:");
		mvwaddstr(win, mnu[1].r, mnu[1].c, mnu[1].t);
		mvwaddstr(win, mnu[2].r, mnu[2].c, mnu[2].t);
		mvwaddstr(win, mnu[3].r, mnu[3].c, mnu[3].t);
		mvwaddstr(win, mnu[0].r, mnu[0].c, mnu[0].t);
		wrefresh(win);

		sw =	alx_menu(len, mnu, win);

		wclear(win);
		wrefresh(win);
		delwin(win);

		switch (sw) {
		case 0:
			wh = false;
			break;

		case 1:
			menu_continue();
			break;

		case 2:
			w_print_disclaim();
			break;

		case 3:
			w_print_license();
			break;
		}
	}
}



//------------------------------------------------------------------------------
//--| submenus |----------------------------------------------------------------
//------------------------------------------------------------------------------

static	void	menu_continue	(void)
{
	int64_t	sw;
	bool	wh;
	WINDOW		*win;
	const int64_t	h =	10;
	const int64_t	w =	35;
	const int64_t	r =	1;
	const int64_t	c =	(80 - w) / 2;

	const int64_t		len = 5;
	const struct alx_option	mnu[5] =	{{7, 4, "[0]	Back"},
						{2, 4, "[1]	Run"},
						{3, 4, "[2]	Help"},
						{4, 4, "[3]	Select problem type"},
						{5, 4, "[4]	Change verbose"}};

	wh = true;
	while (wh) {
		win =	newwin(h, w, r, c);
		keypad(win, true);

		alx_w_title(win, "CONTINUE:");
		mvwaddstr(win, mnu[1].r, mnu[1].c, mnu[1].t);
		mvwaddstr(win, mnu[2].r, mnu[2].c, mnu[2].t);
		mvwaddstr(win, mnu[3].r, mnu[3].c, mnu[3].t);
		mvwaddstr(win, mnu[4].r, mnu[4].c, mnu[4].t);
		mvwaddstr(win, mnu[0].r, mnu[0].c, mnu[0].t);
		wrefresh(win);

		sw =	alx_menu(len, mnu, win);

		wclear(win);
		wrefresh(win);
		delwin(win);

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
			w_help_switch();
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
	const int64_t	r =	1;
	const int64_t	c =	(80 - w) / 2;

	const int64_t		len = 10;
	const struct alx_option	mnu[10] =	{{13, 4, "[0]	Back"},
						{2, 4, "[1]	1 Variable"},
						{3, 4, "[2]	2 Variables"},
						{5, 4, "[3]	Binomial"},
						{6, 4, "[4]	Poisson"},
						{7, 4, "[5]	Geometrica"},
						{8, 4, "[6]	Hipergeometrica"},
						{9, 4, "[7]	Uniforme"},
						{10, 4, "[8]	Exponencial"},
						{11, 4, "[9]	Gauss(Normal)"}};
	win =	newwin(h, w, r, c);
	keypad(win, true);

	alx_w_title(win, "SELECT:");
	mvwaddstr(win, mnu[1].r, mnu[1].c, mnu[1].t);
	mvwaddstr(win, mnu[2].r, mnu[2].c, mnu[2].t);
	mvwaddstr(win, mnu[3].r, mnu[3].c, mnu[3].t);
	mvwaddstr(win, mnu[4].r, mnu[4].c, mnu[4].t);
	mvwaddstr(win, mnu[5].r, mnu[5].c, mnu[5].t);
	mvwaddstr(win, mnu[6].r, mnu[6].c, mnu[6].t);
	mvwaddstr(win, mnu[7].r, mnu[7].c, mnu[7].t);
	mvwaddstr(win, mnu[8].r, mnu[8].c, mnu[8].t);
	mvwaddstr(win, mnu[9].r, mnu[9].c, mnu[9].t);
	mvwaddstr(win, mnu[0].r, mnu[0].c, mnu[0].t);
	wrefresh(win);

	buff =	alx_menu(len, mnu, win);

	wclear(win);
	wrefresh(win);
	delwin(win);

	if (buff) {
		flag_s =	buff;
	}
}

static	void	menu_verbose	(void)
{
	WINDOW		*win;
	const int64_t	h =	10;
	const int64_t	w =	51;
	const int64_t	r =	1;
	const int64_t	c =	(80 - w) / 2;

	const int64_t		len = 5;
	const struct alx_option	mnu[5] =	{{7, 4, "[0]	Show NOTHING"},
						{2, 4, "[1]	Show only solution"},
						{3, 4, "[2]	Show short help"},
						{4, 4, "[3]	Show help"},
						{5, 4, "[4]	Show everything  (DBG)"}};

	win =	newwin(h, w, r, c);
	keypad(win, true);

	alx_w_title(win, "VERBOSE:");
	mvwaddstr(win, mnu[1].r, mnu[1].c, mnu[1].t);
	mvwaddstr(win, mnu[2].r, mnu[2].c, mnu[2].t);
	mvwaddstr(win, mnu[3].r, mnu[3].c, mnu[3].t);
	mvwaddstr(win, mnu[4].r, mnu[4].c, mnu[4].t);
	mvwaddstr(win, mnu[4].r +1, mnu[4].c +10, DBG ? "" : "DBG not active!");
	mvwaddstr(win, mnu[0].r, mnu[0].c, mnu[0].t);
	wrefresh(win);

	flag_V =	alx_menu(len, mnu, win);

	wclear(win);
	wrefresh(win);
	delwin(win);
}
