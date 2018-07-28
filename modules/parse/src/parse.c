/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 ******************************************************************************/


/******************************************************************************
 ******| include |*************************************************************
 ******************************************************************************/
	#include <getopt.h>
		/* int64_t & INT64_MIN & INT64_MAX & SCNi64 */
	#include <inttypes.h>
		/* INFINITY */
	#include <math.h>
		/* printf() */
	#include <stdio.h>
		/* exit? */
	#include <stdlib.h>

		/* print functions */
	#include "about.h"
		/* global variables */
	#include "data.h"

	#include "parse.h"


/******************************************************************************
 ******| options |*************************************************************
 ******************************************************************************/
	enum	Parse_Short_Option {
		PARSE_S_HELP =		'h',
		PARSE_S_LICENSE =	'l',
		PARSE_S_START =		's',
		PARSE_S_VERBOSE =	'V',
		PARSE_S_VERSION =	'v',
		PARSE_S_EXIT =		'x',

		PARSE_S_CPRIGHT =	10000,	/* No short option */
		PARSE_S_WARRANTY,		/* No short option */

		PARSE_S_PARAM_c,		/* No short option */
		PARSE_S_PARAM_n,		/* No short option */
		PARSE_S_PARAM_N,		/* No short option */
		PARSE_S_PARAM_r,		/* No short option */

		PARSE_S_PARAM_a,		/* No short option */
		PARSE_S_PARAM_b,		/* No short option */
		PARSE_S_PARAM_p,		/* No short option */
		PARSE_S_PARAM_x0,		/* No short option */
		PARSE_S_PARAM_x1,		/* No short option */
		PARSE_S_PARAM_x2,		/* No short option */
		PARSE_S_PARAM_beta,		/* No short option */
		PARSE_S_PARAM_lambda		/* No short option */
	};

	# define	OPT_LIST		"hls:V:vx"

	# define	PARSE_L_HELP 		"help"
	# define	PARSE_L_LICENSE 	"license"
	# define	PARSE_L_START 		"start"
	# define	PARSE_L_VERBOSE 	"Verbose"
	# define	PARSE_L_VERSION 	"version"
	# define	PARSE_L_EXIT 		"exit"

	# define	PARSE_L_CPRIGHT 	"copyright"
	# define	PARSE_L_WARRANTY 	"warranty"

	# define	PARSE_L_PARAM_c 	"param-c"
	# define	PARSE_L_PARAM_n 	"param-n"
	# define	PARSE_L_PARAM_N 	"param-N"
	# define	PARSE_L_PARAM_r 	"param-r"

	# define	PARSE_L_PARAM_a 	"param-a"
	# define	PARSE_L_PARAM_b 	"param-b"
	# define	PARSE_L_PARAM_p 	"param-p"
	# define	PARSE_L_PARAM_x0 	"param-x0"
	# define	PARSE_L_PARAM_x1 	"param-x1"
	# define	PARSE_L_PARAM_x2 	"param-x2"
	# define	PARSE_L_PARAM_beta 	"param-beta"
	# define	PARSE_L_PARAM_lambda 	"param-lambda"


/******************************************************************************
 ******| static functions |****************************************************
 ******************************************************************************/
static	int64_t	parse_int	(const char *optstr, const char *optarg,
				int64_t *param, int64_t m, int64_t M);

static	int64_t	parse_dbl	(const char *optstr, const char *optarg,
				double *param, double m, double M);


/******************************************************************************
 ******| parser |**************************************************************
 ******************************************************************************/
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
						VERBOSE_0, VERBOSE_MAX)) {
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
						&param_i_c, 0, 3)) {
				exit(EXIT_FAILURE);
			}
			break;

		case PARSE_S_PARAM_n:
			if (parse_int(PARSE_L_PARAM_n, optarg,
						&param_i_n, 0, INT64_MAX)) {
				exit(EXIT_FAILURE);
			}
			break;

		case PARSE_S_PARAM_N:
			if (parse_int(PARSE_L_PARAM_N, optarg,
						&param_i_N, 0, INT64_MAX)) {
				exit(EXIT_FAILURE);
			}
			break;

		case PARSE_S_PARAM_r:
			if (parse_int(PARSE_L_PARAM_r, optarg,
						&param_i_r, 0, INT64_MAX)) {
				exit(EXIT_FAILURE);
			}
			break;


		case PARSE_S_PARAM_a:
			if (parse_dbl(PARSE_L_PARAM_a, optarg,
						&param_a, -INFINITY, INFINITY)) {
				exit(EXIT_FAILURE);
			}
			break;

		case PARSE_S_PARAM_b:
			if (parse_dbl(PARSE_L_PARAM_b, optarg,
						&param_b, param_a, INFINITY)) {
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
						&param_x_dbl[0],
						-INFINITY, INFINITY)) {
				exit(EXIT_FAILURE);
			}
			break;

		case PARSE_S_PARAM_x1:
			if (parse_dbl(PARSE_L_PARAM_x1, optarg,
						&param_x_dbl[1], -INFINITY, INFINITY)) {
				exit(EXIT_FAILURE);
			}
			break;

		case PARSE_S_PARAM_x2:
			if (parse_dbl(PARSE_L_PARAM_x2, optarg,
						&param_x_dbl[2], param_x_dbl[1], INFINITY)) {
				exit(EXIT_FAILURE);
			}
			break;

		case PARSE_S_PARAM_beta:
			if (parse_dbl(PARSE_L_PARAM_beta, optarg,
						&param_beta, 0, INFINITY)) {
				exit(EXIT_FAILURE);
			}
			break;

		case PARSE_S_PARAM_lambda:
			if (parse_dbl(PARSE_L_PARAM_lambda, optarg,
						&param_lambda, 0, INFINITY)) {
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


/******************************************************************************
 ******| static functions |****************************************************
 ******************************************************************************/
static	int64_t	parse_int	(const char *optstr, const char *optarg,
				int64_t *param, int64_t m, int64_t M)
{
	/* Error */
	int64_t	E = 0;

	if (1 == sscanf(optarg, " %"SCNi64"", param)) {
		if (*param < m || *param > M) {
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
		if (*param < m || *param > M) {
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
