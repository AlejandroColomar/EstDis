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
	#include "desc.h"
	#include "dist.h"
	#include "menu.h"

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

void	menu_main		(void)
{
	int8_t	sw;
	bool	wh;
	WINDOW		*win;
	const uint8_t	h =	10;
	const uint8_t	w =	34;
	const uint8_t	r =	1;
	const uint8_t	c =	(80 - w) / 2;

	const uint8_t		len = 4;
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
	endwin();
}

void	menu_continue	(void)
{
	int8_t	sw;
	bool	wh;
	WINDOW		*win;
	const uint8_t	h =	8;
	const uint8_t	w =	30;
	const uint8_t	r =	1;
	const uint8_t	c =	(80 - w) / 2;

	const uint8_t		len = 3;
	const struct alx_option	mnu[3] =	{{5, 4, "[0]	Back"},
						{2, 4, "[1]	Descriptiva"},
						{3, 4, "[2]	Distribuciones"}};

	wh = true;
	while (wh) {
		win =	newwin(h, w, r, c);
		keypad(win, true);

		alx_w_title(win, "CONTINUE:");
		mvwaddstr(win, mnu[1].r, mnu[1].c, mnu[1].t);
		mvwaddstr(win, mnu[2].r, mnu[2].c, mnu[2].t);
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
			menu_desc();
			break;

		case 2:
			menu_dist();
			break;
		}
	}
}

void	menu_desc	(void)
{
	int8_t	sw;
	bool	wh;
	WINDOW		*win;
	const uint8_t	h =	8;
	const uint8_t	w =	30;
	const uint8_t	r =	1;
	const uint8_t	c =	(80 - w) / 2;

	const uint8_t		len = 3;
	const struct alx_option	mnu[3] =	{{5, 4, "[0]	Back"},
						{2, 4, "[1]	1 Variable"},
						{3, 4, "[2]	2 Variables"}};

	wh = true;
	while (wh) {
		win =	newwin(h, w, r, c);
		keypad(win, true);

		alx_w_title(win, "DESCRIPTIVA:");
		mvwaddstr(win, mnu[1].r, mnu[1].c, mnu[1].t);
		mvwaddstr(win, mnu[2].r, mnu[2].c, mnu[2].t);
		mvwaddstr(win, mnu[0].r, mnu[0].c, mnu[0].t);
		wrefresh(win);

		sw =	alx_menu(len, mnu, win);

		wclear(win);
		wrefresh(win);
		delwin(win);

		def_prog_mode();
		endwin();

		switch (sw) {
		case 0:
			wh = false;
			break;

		case 1:
			desc_1var();
			break;

		case 2:
			desc_2var();
			break;
		}

		getch();
		reset_prog_mode();
	}
}

void	menu_dist	(void)
{
	int8_t	sw;
	bool	wh;
	WINDOW		*win;
	const uint8_t	h =	13;
	const uint8_t	w =	50;
	const uint8_t	r =	1;
	const uint8_t	c =	(80 - w) / 2;

	const uint8_t		len = 15;
	const struct alx_option	mnu[15] =	{{10, 4, "[0]	Back"},
						{2, 4, "[1]	Binomial"},
						{2, 30, "[2]	--help"},
						{3, 4, "[3]	Poisson"},
						{3, 30, "[4]	--help"},
						{4, 4, "[5]	Geometrica"},
						{4, 30, "[6]	--help"},
						{5, 4, "[7]	Hipergeometrica"},
						{5, 30, "[8]	--help"},
						{6, 4, "[9]	Uniforme"},
						{6, 30, "[10]	--help"},
						{7, 4, "[11]	Exponencial"},
						{7, 30, "[12]	--help"},
						{8, 4, "[13]	Gauss(Normal)"},
						{8, 30, "[14]	--help"}};

	wh = true;
	while (wh) {
		win =	newwin(h, w, r, c);
		keypad(win, true);

		alx_w_title(win, "CONTINUE:");
		mvwaddstr(win, mnu[1].r, mnu[1].c, mnu[1].t);
		mvwaddstr(win, mnu[2].r, mnu[2].c, mnu[2].t);
		mvwaddstr(win, mnu[3].r, mnu[3].c, mnu[3].t);
		mvwaddstr(win, mnu[4].r, mnu[4].c, mnu[4].t);
		mvwaddstr(win, mnu[5].r, mnu[5].c, mnu[5].t);
		mvwaddstr(win, mnu[6].r, mnu[6].c, mnu[6].t);
		mvwaddstr(win, mnu[7].r, mnu[7].c, mnu[7].t);
		mvwaddstr(win, mnu[8].r, mnu[8].c, mnu[8].t);
		mvwaddstr(win, mnu[9].r, mnu[9].c, mnu[9].t);
		mvwaddstr(win, mnu[10].r, mnu[10].c, mnu[10].t);
		mvwaddstr(win, mnu[11].r, mnu[11].c, mnu[11].t);
		mvwaddstr(win, mnu[12].r, mnu[12].c, mnu[12].t);
		mvwaddstr(win, mnu[13].r, mnu[13].c, mnu[13].t);
		mvwaddstr(win, mnu[14].r, mnu[14].c, mnu[14].t);
		mvwaddstr(win, mnu[0].r, mnu[0].c, mnu[0].t);
		wrefresh(win);

		sw =	alx_menu(len, mnu, win);

		wclear(win);
		wrefresh(win);
		delwin(win);

		def_prog_mode();
		endwin();

		switch (sw) {
			wh = false;
			break;
		case 1:
			dist_binomial_help();
			dist_binomial();
			break;
		case 2:
			dist_binomial_help();
			break;
		case 3:
			dist_poisson_help();
			dist_poisson();
			break;
		case 4:
			dist_poisson_help();
			break;
		case 5:
			dist_geometric_help();
			dist_geometric();
			break;
		case 6:
			dist_geometric_help();
			break;
		case 7:
			dist_hypergeometric_help();
			break;
		case 8:
			dist_hypergeometric_help();
			break;
		case 9:
			dist_uniform_help();
			dist_uniform();
			break;
		case 10:
			dist_uniform_help();
			break;
		case 11:
			dist_exponential_help();
			dist_exponential();
			break;
		case 12:
			dist_exponential_help();
			break;
		case 13:
			dist_normal();
			break;
		case 14:
			break;
		}

		getch();
		reset_prog_mode();
	}
}
