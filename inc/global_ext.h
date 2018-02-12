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

# ifndef		GLOBAL_EXT_H
	# define	GLOBAL_EXT_H

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


	extern	int16_t		flag_s;
	extern	int16_t		flag_r;
	extern	int16_t		flag_V;
	extern	bool		flag_x;

	enum	Start_Switch {
		START_FOO = 0,
		START_DESC_1VAR,
		START_DESC_2VAR,
		START_BINOMIAL,
		START_POISSON,
		START_GEOMETRIC,
		START_HYPERGEOMETRIC,
		START_UNIFORM,
		START_EXPONENTIAL,
		START_NORMAL
	};

	enum	Help_Switch {
		HELP_GENERIC = 0,
		HELP_DESC_1VAR,
		HELP_DESC_2VAR,
		HELP_BINOMIAL,
		HELP_POISSON,
		HELP_GEOMETRIC,
		HELP_HYPERGEOMETRIC,
		HELP_UNIFORM,
		HELP_EXPONENTIAL,
		HELP_NORMAL
	};

	extern	char		file_path [FILENAME_MAX];

# endif			/* global_ext.h */
