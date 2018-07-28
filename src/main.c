/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 ******************************************************************************/

		/* start and end curses */
	#include "alx_ncur.h"

		/* menu_main() */
	#include "menus.h"
		/* parser() */
	#include "parse.h"

int	main	(int argc, char *argv[], char *envp[])
{
	parser(argc, argv);

//	init_values();
//								print_verbose(1, w_print_cpright, NULL);
//	start_switch();
//	if (!flag_x) {
		alx_start_curses();
		menu_main();
		alx_end_curses();
//	}
	return	0;
}
