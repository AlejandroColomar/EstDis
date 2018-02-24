
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

# ifndef		GLOBAL_EXT_H
	# define	GLOBAL_EXT_H

//	#include <getopt.h>
//	#include <inttypes.h>
//	#include <ncurses.h>
//	#include <pthread.h>
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


	extern	int64_t		flag_s;
	extern	int64_t		flag_r;
	extern	int64_t		flag_V;
	extern	bool		flag_x;

	extern	int64_t		param_c;
	extern	int64_t		param_n;
	extern	int64_t		param_N;
	extern	int64_t		param_r;

	extern	double		param_a;
	extern	double		param_b;
	extern	double		param_p;
	extern	double		param_x0;
	extern	double		param_x1;
	extern	double		param_x2;
	extern	double		param_beta;
	extern	double		param_lambda;

	enum	Level_Verbose {
		VERBOSE_Q = 0,
		VERBOSE_1,
		VERBOSE_2,
		VERBOSE_3,
		VERBOSE_MAX
	};

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
		START_NORMAL,
		START_COUNT
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
		HELP_NORMAL,
		HELP_MAX
	};

	extern	char		file_path [FILENAME_MAX];

# endif			/* global_ext.h */
