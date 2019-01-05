/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
/* Standard C ----------------------------------------------------------------*/
	#include <getopt.h>
		/* int64_t & SCNi64 */
	#include <inttypes.h>
		/* INFINITY */
	#include <math.h>
		/* printf() */
	#include <stdio.h>
		/* exit? */
	#include <stdlib.h>

/* libalx --------------------------------------------------------------------*/
	#include "alx_input.h"

/* Project -------------------------------------------------------------------*/
		/* print functions */
	#include "about.h"
		/* statistics variables */
	#include "calc.h"
		/* flag_verbose */
	#include "menus.h"
		/* start_mode */
	#include "start.h"

/* Module --------------------------------------------------------------------*/
	#include "parse.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
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
 ******* enums ****************************************************************
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


/******************************************************************************
 ******* static functions *****************************************************
 ******************************************************************************/
static	void	error_handle	(int err, const char *optstr, double m, double M);


/******************************************************************************
 ******* functions ************************************************************
 ******************************************************************************/
void	parser	(int argc, char *argv[])
{
	int	opt =		0;
	int	opt_index =	0;

	struct option long_options[] = {
		{PARSE_L_HELP,		no_argument,		0, PARSE_S_HELP},
		{PARSE_L_LICENSE,	no_argument,		0, PARSE_S_LICENSE},
		{PARSE_L_START,		required_argument,	0, PARSE_S_START},
		{PARSE_L_VERBOSE,	required_argument,	0, PARSE_S_VERBOSE},
		{PARSE_L_VERSION,	no_argument,		0, PARSE_S_VERSION},
		{PARSE_L_EXIT,		no_argument,		0, PARSE_S_EXIT},

		{PARSE_L_CPRIGHT,	no_argument,		0, PARSE_S_CPRIGHT},
		{PARSE_L_WARRANTY,	no_argument,		0, PARSE_S_WARRANTY},

		{PARSE_L_PARAM_c,	required_argument,	0, PARSE_S_PARAM_c},
		{PARSE_L_PARAM_n,	required_argument,	0, PARSE_S_PARAM_n},
		{PARSE_L_PARAM_N,	required_argument,	0, PARSE_S_PARAM_N},
		{PARSE_L_PARAM_r,	required_argument,	0, PARSE_S_PARAM_r},

		{PARSE_L_PARAM_a,	required_argument,	0, PARSE_S_PARAM_a},
		{PARSE_L_PARAM_b,	required_argument,	0, PARSE_S_PARAM_b},
		{PARSE_L_PARAM_p,	required_argument,	0, PARSE_S_PARAM_p},
		{PARSE_L_PARAM_x0,	required_argument,	0, PARSE_S_PARAM_x0},
		{PARSE_L_PARAM_x1,	required_argument,	0, PARSE_S_PARAM_x1},
		{PARSE_L_PARAM_x2,	required_argument,	0, PARSE_S_PARAM_x2},
		{PARSE_L_PARAM_beta,	required_argument,	0, PARSE_S_PARAM_beta},
		{PARSE_L_PARAM_lambda,	required_argument,	0, PARSE_S_PARAM_lambda},
		{0,			0,			0, 0}
	};

	int	err;

	while ((opt = getopt_long(argc, argv, OPT_LIST, long_options,
						&opt_index )) != -1) {
		switch (opt) {
		case PARSE_S_HELP:
			print_share_file(SHARE_HELP);
			exit(EXIT_SUCCESS);

		case PARSE_S_LICENSE:
			print_share_file(SHARE_LICENSE);
			exit(EXIT_SUCCESS);

		case PARSE_S_START:
			err	= alx_sscan_int(&start_mode, START_FOO, 0,
							START_NORMAL, optarg);
			error_handle(err, PARSE_L_START, START_FOO, START_NORMAL);
			break;

		case PARSE_S_VERBOSE:
			err	= alx_sscan_int(&flag_verbose, VERBOSE_0, 0,
							VERBOSE_MAX, optarg);
			error_handle(err, PARSE_L_VERBOSE, VERBOSE_0,
							VERBOSE_MAX);
			break;

		case PARSE_S_VERSION:
			print_version();
			exit(EXIT_SUCCESS);

		case PARSE_S_EXIT:
			flag_exit	= true;
			break;


		case PARSE_S_CPRIGHT:
			print_share_file(SHARE_COPYRIGHT);
			exit(EXIT_SUCCESS);

		case PARSE_S_WARRANTY:
			print_share_file(SHARE_DISCLAIMER);
			exit(EXIT_SUCCESS);


		case PARSE_S_PARAM_c:
			err	= alx_sscan_i64(&param_i_c, 0, 0, 3, optarg);
			error_handle(err, PARSE_L_PARAM_c, 0, 3);
			break;

		case PARSE_S_PARAM_n:
			err	= alx_sscan_i64(&param_i_n, 0, 0, INFINITY,
							optarg);
			error_handle(err, PARSE_L_PARAM_n, 0, INFINITY);
			break;

		case PARSE_S_PARAM_N:
			err	= alx_sscan_i64(&param_i_N, 0, 0, INFINITY,
							optarg);
			error_handle(err, PARSE_L_PARAM_N, 0, INFINITY);
			break;

		case PARSE_S_PARAM_r:
			err	= alx_sscan_i64(&param_i_r, 0, 0, INFINITY,
							optarg);
			error_handle(err, PARSE_L_PARAM_r, 0, INFINITY);
			break;


		case PARSE_S_PARAM_a:
			err	= alx_sscan_dbl(&param_a, -INFINITY, 0,
							INFINITY, optarg);
			error_handle(err, PARSE_L_PARAM_a, -INFINITY, INFINITY);
			break;

		case PARSE_S_PARAM_b:
			err	= alx_sscan_dbl(&param_b, param_a, 0, INFINITY,
							optarg);
			error_handle(err, PARSE_L_PARAM_b, param_a, INFINITY);
			break;

		case PARSE_S_PARAM_p:
			err	= alx_sscan_dbl(&param_p, 0, 0, 1, optarg);
			error_handle(err, PARSE_L_PARAM_p, 0, 1);
			break;

		case PARSE_S_PARAM_x0:
			err	= alx_sscan_dbl(&param_x_dbl[0], -INFINITY, 0,
							INFINITY, optarg);
			error_handle(err, PARSE_L_PARAM_x0, -INFINITY, INFINITY);
			break;

		case PARSE_S_PARAM_x1:
			err	= alx_sscan_dbl(&param_x_dbl[1], -INFINITY, 0,
							INFINITY, optarg);
			error_handle(err, PARSE_L_PARAM_x1, -INFINITY, INFINITY);
			break;

		case PARSE_S_PARAM_x2:
			err	= alx_sscan_dbl(&param_x_dbl[2], param_x_dbl[1],
							0, INFINITY, optarg);
			error_handle(err, PARSE_L_PARAM_x2, param_x_dbl[1],
							INFINITY);
			break;

		case PARSE_S_PARAM_beta:
			err	= alx_sscan_dbl(&param_beta, 0, 0, INFINITY,
							optarg);
			error_handle(err, PARSE_L_PARAM_beta, 0, INFINITY);
			break;

		case PARSE_S_PARAM_lambda:
			err	= alx_sscan_dbl(&param_lambda, 0, 0, INFINITY,
							optarg);
			error_handle(err, PARSE_L_PARAM_lambda, 0, INFINITY);
			break;

		case '?':
			/* getopt_long already printed an error message. */

		default:
			print_share_file(SHARE_USAGE);
			exit(EXIT_FAILURE);
		}
	}
}


/******************************************************************************
 ******* static functions *****************************************************
 ******************************************************************************/
static	void	error_handle	(int err, const char *optstr, double m, double M)
{
	if (err) {
		printf("%s argument not valid\n", optstr);

		switch (err) {
		case ERR_RANGE:
			printf("It must be in the range [%lf U %lf]\n", m, M);
			break;
		case ERR_SSCANF:
			puts("NaN");
			break;
		}

		exit(EXIT_FAILURE);
	}
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
