
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

# ifndef		GLOBAL_H
	# define	GLOBAL_H

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


	int64_t		flag_s;
	int64_t		flag_r;
	int64_t		flag_V;
	bool		flag_x;

	int64_t		param_c;
	int64_t		param_n;
	int64_t		param_N;
	int64_t		param_r;

	double		param_a;
	double		param_b;
	double		param_p;
	double		param_x0;
	double		param_x1;
	double		param_x2;
	double		param_beta;
	double		param_lambda;

	char		file_path [FILENAME_MAX];

# endif			/* global.h */
