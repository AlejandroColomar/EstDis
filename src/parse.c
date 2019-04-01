/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	GPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "estadistica/parse.h"

#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <getopt.h>

#include "libalx/base/stdio/sscan.h"

#include "estadistica/about.h"
#include "estadistica/menus.h"
#include "estadistica/start.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define OPT_LIST		"hlV:v"

#define PARSE_L_HELP		"help"
#define PARSE_L_LICENSE		"license"
#define PARSE_L_VERBOSE		"Verbose"
#define PARSE_L_VERSION		"version"

#define PARSE_L_CPRIGHT		"copyright"
#define PARSE_L_WARRANTY	"warranty"


/******************************************************************************
 ******* enums ****************************************************************
 ******************************************************************************/
enum	Parse_Short_Option {
	PARSE_S_HELP =		'h',
	PARSE_S_LICENSE =	'l',
	PARSE_S_VERBOSE =	'V',
	PARSE_S_VERSION =	'v',

	PARSE_S_CPRIGHT =	10000,	/* No short option */
	PARSE_S_WARRANTY		/* No short option */
};


/******************************************************************************
 ******* structs / unions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* variables ************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static functions (prototypes) ****************************************
 ******************************************************************************/
static	void	error_handle	(const char *optstr, double m, double M);


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
void	parser	(int argc, char *argv[])
{
	int	opt =		0;
	int	opt_index =	0;

	const struct option long_options[] = {
		{PARSE_L_HELP,		no_argument,		0, PARSE_S_HELP},
		{PARSE_L_LICENSE,	no_argument,		0, PARSE_S_LICENSE},
		{PARSE_L_VERBOSE,	required_argument,	0, PARSE_S_VERBOSE},
		{PARSE_L_VERSION,	no_argument,		0, PARSE_S_VERSION},

		{PARSE_L_CPRIGHT,	no_argument,		0, PARSE_S_CPRIGHT},
		{PARSE_L_WARRANTY,	no_argument,		0, PARSE_S_WARRANTY},
		{0,			0,			0, 0}
	};

	while ((opt = getopt_long(argc, argv, OPT_LIST, long_options,
							&opt_index)) != -1) {
		switch (opt) {
		case PARSE_S_HELP:
			print_share_file(SHARE_HELP);
			exit(EXIT_SUCCESS);
		case PARSE_S_LICENSE:
			print_share_file(SHARE_LICENSE);
			exit(EXIT_SUCCESS);
		case PARSE_S_VERBOSE:
			if (alx_sscan_int(&flag_verbose, VERBOSE_0, 0,
							VERBOSE_MAX, optarg)) {
				error_handle(PARSE_L_VERBOSE, VERBOSE_0,
								VERBOSE_MAX);
			}
			break;
		case PARSE_S_VERSION:
			print_version();
			exit(EXIT_SUCCESS);
		case PARSE_S_CPRIGHT:
			print_share_file(SHARE_COPYRIGHT);
			exit(EXIT_SUCCESS);
		case PARSE_S_WARRANTY:
			print_share_file(SHARE_DISCLAIMER);
			exit(EXIT_SUCCESS);

		case '?':
			/* getopt_long already printed an error message. */
		default:
			print_share_file(SHARE_USAGE);
			exit(EXIT_FAILURE);
		}
	}
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/
static	void	error_handle	(const char *optstr, double m, double M)
{

	printf("%s argument not valid\n", optstr);
	printf("It must be in the range [%lf U %lf]\n", m, M);

	exit(EXIT_FAILURE);
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
