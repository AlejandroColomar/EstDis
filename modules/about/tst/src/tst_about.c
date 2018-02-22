
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

	#include <curses.h>
	#include <stdbool.h>
	#include <stdint.h>
	#include <stdio.h>

	#include "alx_ncur.h"

	#include "about.h"


	enum	Tst_Functions {
		TST_END = 0,

		TST_W_HELP_SWITCH,
		TST_PRINT_HELP,
		TST_PRINT_VERSION,
		TST_PRINT_USAGE,

		TST_PRINT_CPRIGHT,
		TST_PRINT_DISCLAIM,

		TST_W_PRINT_CPRIGHT,
		TST_W_PRINT_DISCLAIM,

		TST_PRINT_LICENSE,
		TST_W_PRINT_LICENSE,

		TST_DIST_BINOMIAL_HELP,
		TST_DIST_POISSON_HELP,
		TST_DIST_GEOMETRIC_HELP,
		TST_DIST_HYPERGEOMETRIC_HELP,
		TST_DIST_UNIFORM_HELP,
		TST_DIST_EXPONENTIAL_HELP,

		TST_FUNCTIONS
	};


int	main	()
{
	alx_start_curses();

	int64_t	sw;
	bool	wh;
	WINDOW		*win;
	const int64_t	h =	30;
	const int64_t	w =	34;
	const int64_t	r =	1;
	const int64_t	c =	(80 - w) / 2;

	const int64_t		N = TST_FUNCTIONS;
	const struct alx_option	mnu[TST_FUNCTIONS] =	{{19, 4, "[0]  END TEST"},
						{2, 4, "[1]  w_help_switch"},
						{3, 4, "[2]  print_help"},
						{4, 4, "[3]  print_version"},
						{5, 4, "[4]  print_usage"},
						{6, 4, "[5]  print_cpright"},
						{7, 4, "[6]  print_disclaim"},
						{8, 4, "[7]  w_print_cpright(NULL)"},
						{9, 4, "[8]  w_print_disclaim"},
						{10, 4, "[9]  print_license"},
						{11, 4, "[10] w_print_license"},
						{12, 4, "[11] dist_binomial_help"},
						{13, 4, "[12] dist_poisson_help"},
						{14, 4, "[13] dist_geometric_help"},
						{15, 4, "[14] dist_hypergeometric_help"},
						{16, 4, "[15] dist_uniform_help"},
						{17, 4, "[16] dist_exponential_help"}};

	wh = true;
	while (wh) {
		sw =	alx_menu(h, w, N, mnu, "TEST:");

		switch (sw) {
		case TST_END:
			wh = false;
			break;

		case TST_W_HELP_SWITCH:
			w_help_switch();
			break;

		case TST_PRINT_HELP:
			alx_pause_curses();
			print_help();
			alx_resume_curses();
			break;

		case TST_PRINT_VERSION:
			alx_pause_curses();
			print_version();
			alx_resume_curses();
			break;

		case TST_PRINT_USAGE:
			alx_pause_curses();
			print_usage();
			alx_resume_curses();
			break;

		case TST_PRINT_CPRIGHT:
			alx_pause_curses();
			print_cpright();
			alx_resume_curses();
			break;

		case TST_PRINT_DISCLAIM:
			alx_pause_curses();
			print_disclaim();
			alx_resume_curses();
			break;

		case TST_W_PRINT_CPRIGHT:
			w_print_cpright(NULL);
			break;

		case TST_W_PRINT_DISCLAIM:
			w_print_disclaim();
			break;

		case TST_PRINT_LICENSE:
			alx_pause_curses();
			print_license();
			alx_resume_curses();
			break;

		case TST_W_PRINT_LICENSE:
			w_print_license();
			break;

		case TST_DIST_BINOMIAL_HELP:
			alx_pause_curses();
			dist_binomial_help();
			alx_resume_curses();
			break;

		case TST_DIST_POISSON_HELP:
			alx_pause_curses();
			dist_poisson_help();
			alx_resume_curses();
			break;

		case TST_DIST_GEOMETRIC_HELP:
			alx_pause_curses();
			dist_geometric_help();
			alx_resume_curses();
			break;

		case TST_DIST_HYPERGEOMETRIC_HELP:
			alx_pause_curses();
			dist_hypergeometric_help();
			alx_resume_curses();
			break;

		case TST_DIST_UNIFORM_HELP:
			alx_pause_curses();
			dist_uniform_help();
			alx_resume_curses();
			break;

		case TST_DIST_EXPONENTIAL_HELP:
			alx_pause_curses();
			dist_exponential_help();
			alx_resume_curses();
			break;
		}
	}
	endwin();

	return	0;
}
