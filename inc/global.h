////////////////----------------------------------------////////////////
////////////////        PNP-Solver      v0.31           ////////////////
////////////////----------------------------------------////////////////

	/*
	 * PNP-Solver	This is a solver of the INDEPENDENT SET PROBLEM.
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
	 *
	 * Remember to acknowledge the original author of the algorithm,
	 * which is Alejandro Colomar, if you do any version or fork it. 
	 *
	 * Contact:
	 *	e-mail:	1903716@gmail.com
	 *
	 *	mail:	Alejandro Colomar Andrés
	 *		c/Mayor, 45 - 5, 46960, Aldaia, VALENCIA, SPAIN
	 *
	 * The contact information above may change without any notice.
	 */

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

# ifndef		GLOBAL_H
	# define	GLOBAL_H

//	#include <getopt.h>
//	#include <inttypes.h>
//	#include <ncurses.h>
	#include <pthread.h>
//	#include <stdarg.h>
	#include <stdbool.h>
	#include <stdint.h>
	#include <stdio.h>
//	#include <stdlib.h>
//	#include <string.h>
//	#include <sys/types.h>
	#include <time.h>
//	#include <unistd.h>

	#include "macros.h"


	int16_t		flag_s;
	int16_t		flag_r;
	int16_t		flag_V;
	bool		flag_x;

	char		file_path [FILENAME_MAX];

# endif			/* global.h */
