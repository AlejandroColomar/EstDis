/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 ******************************************************************************/

	#include <curses.h>
	#include <stdbool.h>
	#include <stdio.h>

	#include "alx_ncur.h"

	#include "about.h"


	enum	Tst_Functions {
		TST_END = 0,

		TST_PRINT_HELP,
		TST_PRINT_VERSION,
		TST_PRINT_USAGE,

		TST_PRINT_CPRIGHT,
		TST_PRINT_DISCLAIM,

		TST_PRINT_LICENSE,

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

	int	sw;
	bool	wh;
	WINDOW		*win;
	int	h =	30;
	int	w =	34;
	int	r =	1;
	int	c =	(80 - w) / 2;

	int		N = TST_FUNCTIONS;
	struct alx_optn	mnu[TST_FUNCTIONS] =	{
		{19, 4, "[0]  END TEST"},
		{3, 4, "[ ]  print_help"},
		{4, 4, "[ ]  print_version"},
		{5, 4, "[ ]  print_usage"},
		{6, 4, "[ ]  print_cpright"},
		{7, 4, "[ ]  print_disclaim"},
		{10, 4, "[ ]  print_license"},
		{12, 4, "[ ] dist_binomial_help"},
		{13, 4, "[ ] dist_poisson_help"},
		{14, 4, "[ ] dist_geometric_help"},
		{15, 4, "[ ] dist_hypergeometric_help"},
		{16, 4, "[ ] dist_uniform_help"},
		{17, 4, "[ ] dist_exponential_help"}
	};

	wh = true;
	while (wh) {
		sw =	alx_menu(h, w, N, mnu, "TEST:");

		switch (sw) {
		case TST_END:
			wh = false;
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

		case TST_PRINT_LICENSE:
			alx_pause_curses();
			print_license();
			alx_resume_curses();
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
	alx_end_curses();

	return	0;
}
