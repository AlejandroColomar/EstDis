
/******************************************************************************
 * EstDis	Copyright (C) 2016	Alejandro Colomar Andrés	      *
 *									      *
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
