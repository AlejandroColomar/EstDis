
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


	int64_t	flag_s;
	int64_t	flag_r;
	int64_t	flag_V;
	bool	flag_x;


	double	param_i_a;
	double	param_i_b;
	int64_t	param_i_c;
	int64_t	param_i_n;
	int64_t	param_i_N;
	int64_t	param_i_r;
	double	param_i_x [65536];

	double	param_a;
	double	param_b;
	double	param_p;
	double	param_x_dbl [65536];
	double	param_y [65536];
	double	param_beta;
	double	param_lambda;
	double	param_mu;
	double	param_sigma2;
	double	param_X;
	double	param_Z;

	double	result_P;
	double	result_E;
	double	result_Var;

	char	file_path [FILENAME_MAX];

# endif			/* global.h */
