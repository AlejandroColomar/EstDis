
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

	#include <getopt.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	#include "about.h"
	#include "parse.h"

	#include "global_ext.h"
	#include "macros.h"


static	int64_t	parse_int	(const char *optstr, const char *optarg,
				int64_t *param, int64_t m, int64_t M);

static	int64_t	parse_dbl	(const char *optstr, const char *optarg,
				double *param, double m, double M);


void	parser	(int argc, char *argv[])
{
	int	opt =		0;
	int	opt_index =	0;

	struct option long_options[] = {
		{PARSE_L_HELP,		no_argument,		0,	PARSE_S_HELP},
		{PARSE_L_LICENSE,	no_argument,		0,	PARSE_S_LICENSE},
		{PARSE_L_START,		required_argument,	0,	PARSE_S_START},
		{PARSE_L_VERBOSE,	required_argument,	0,	PARSE_S_VERBOSE},
		{PARSE_L_VERSION,	no_argument,		0,	PARSE_S_VERSION},
		{PARSE_L_EXIT,		no_argument,		0,	PARSE_S_EXIT},

		{PARSE_L_CPRIGHT,	no_argument,		0,	PARSE_S_CPRIGHT},
		{PARSE_L_WARRANTY,	no_argument,		0,	PARSE_S_WARRANTY},

		{PARSE_L_PARAM_c,	required_argument,	0,	PARSE_S_PARAM_c},
		{PARSE_L_PARAM_n,	required_argument,	0,	PARSE_S_PARAM_n},
		{PARSE_L_PARAM_N,	required_argument,	0,	PARSE_S_PARAM_N},
		{PARSE_L_PARAM_r,	required_argument,	0,	PARSE_S_PARAM_r},

		{PARSE_L_PARAM_a,	required_argument,	0,	PARSE_S_PARAM_a},
		{PARSE_L_PARAM_b,	required_argument,	0,	PARSE_S_PARAM_b},
		{PARSE_L_PARAM_p,	required_argument,	0,	PARSE_S_PARAM_p},
		{PARSE_L_PARAM_x0,	required_argument,	0,	PARSE_S_PARAM_x0},
		{PARSE_L_PARAM_x1,	required_argument,	0,	PARSE_S_PARAM_x1},
		{PARSE_L_PARAM_x2,	required_argument,	0,	PARSE_S_PARAM_x2},
		{PARSE_L_PARAM_beta,	required_argument,	0,	PARSE_S_PARAM_beta},
		{PARSE_L_PARAM_lambda,	required_argument,	0,	PARSE_S_PARAM_lambda},
		{0,			0,			0,	0}
	};

	while ((opt = getopt_long(argc, argv, OPT_LIST, long_options,
						&opt_index )) != -1) {
		switch (opt) {
		case PARSE_S_HELP:
			print_help();
			exit(EXIT_SUCCESS);

		case PARSE_S_LICENSE:
			print_license();
			exit(EXIT_SUCCESS);

		case PARSE_S_START:
			if (parse_int(PARSE_L_START, optarg, &flag_s,
						START_FOO, START_COUNT)) {
				exit(EXIT_FAILURE);
			}
			break;

		case PARSE_S_VERBOSE:
			if (parse_int(PARSE_L_VERBOSE, optarg, &flag_V,
						VERBOSE_Q, VERBOSE_MAX)) {
				exit(EXIT_FAILURE);
			}
			break;

		case PARSE_S_VERSION:
			print_version();
			exit(EXIT_SUCCESS);

		case PARSE_S_EXIT:
			flag_x =	true;
			break;


		case PARSE_S_CPRIGHT:
			print_cpright();
			exit(EXIT_SUCCESS);

		case PARSE_S_WARRANTY:
			print_disclaim();
			exit(EXIT_SUCCESS);


		case PARSE_S_PARAM_c:
			if (parse_int(PARSE_L_PARAM_c, optarg,
						&param_c, 0, 3)) {
				exit(EXIT_FAILURE);
			}
			break;

		case PARSE_S_PARAM_n:
			if (parse_int(PARSE_L_PARAM_n, optarg,
						&param_n, 0, INT64_MAX)) {
				exit(EXIT_FAILURE);
			}
			break;

		case PARSE_S_PARAM_N:
			if (parse_int(PARSE_L_PARAM_N, optarg,
						&param_N, 0, INT64_MAX)) {
				exit(EXIT_FAILURE);
			}
			break;

		case PARSE_S_PARAM_r:
			if (parse_int(PARSE_L_PARAM_r, optarg,
						&param_r, 0, INT64_MAX)) {
				exit(EXIT_FAILURE);
			}
			break;


		case PARSE_S_PARAM_a:
			if (parse_dbl(PARSE_L_PARAM_a, optarg,
						&param_a, -DBL_MAX, DBL_MAX)) {
				exit(EXIT_FAILURE);
			}
			break;

		case PARSE_S_PARAM_b:
			if (parse_dbl(PARSE_L_PARAM_b, optarg,
						&param_b, param_a, DBL_MAX)) {
				exit(EXIT_FAILURE);
			}
			break;

		case PARSE_S_PARAM_p:
			if (parse_dbl(PARSE_L_PARAM_p, optarg,
						&param_p, 0, 1)) {
				exit(EXIT_FAILURE);
			}
			break;

		case PARSE_S_PARAM_x0:
			if (parse_dbl(PARSE_L_PARAM_x0, optarg,
						&param_x0,
						-DBL_MAX, DBL_MAX)) {
				exit(EXIT_FAILURE);
			}
			break;

		case PARSE_S_PARAM_x1:
			if (parse_dbl(PARSE_L_PARAM_x1, optarg,
						&param_x1, -DBL_MAX, DBL_MAX)) {
				exit(EXIT_FAILURE);
			}
			break;

		case PARSE_S_PARAM_x2:
			if (parse_dbl(PARSE_L_PARAM_x2, optarg,
						&param_x2, param_x1, DBL_MAX)) {
				exit(EXIT_FAILURE);
			}
			break;

		case PARSE_S_PARAM_beta:
			if (parse_dbl(PARSE_L_PARAM_beta, optarg,
						&param_beta, 0, DBL_MAX)) {
				exit(EXIT_FAILURE);
			}
			break;

		case PARSE_S_PARAM_lambda:
			if (parse_dbl(PARSE_L_PARAM_lambda, optarg,
						&param_lambda, 0, DBL_MAX)) {
				exit(EXIT_FAILURE);
			}
			break;

		case '?':
			/* getopt_long already printed an error message. */

		default:
			print_usage();
			exit(EXIT_FAILURE);
		}
	}
}


static	int64_t	parse_int	(const char *optstr, const char *optarg,
				int64_t *param, int64_t m, int64_t M)
{
	/* Error */
	int64_t	E = 0;

	if (1 == sscanf(optarg, " %"SCNi64"", param)) {
		if (param < m || param > M) {
			printf("%s argument not valid\n", optstr);
			printf("It must be greater an integer [%"PRIi64" U %"PRIi64"]\n", m, M);
			E = 1;
		}
	} else {
		printf("%s argument not valid\n", optstr);
		printf("NaN\n");
		E = 2;
	}
}


static	int64_t	parse_dbl	(const char *optstr, const char *optarg,
				double *param, double m, double M)
{
	/* Error */
	int64_t	E = 0;

	if (1 == sscanf(optarg, " %lf", param)) {
		if (param < m || param > M) {
			printf("%s argument not valid\n", optstr);
			printf("It must be greater an integer [%lf U %lf]\n", m, M);
			E = 1;
		}
	} else {
		printf("%s argument not valid\n", optstr);
		printf("NaN\n");
		E = 2;
	}
}
