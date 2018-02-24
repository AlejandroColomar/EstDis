
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

# ifndef		ARGS_H
	# define	ARGS_H

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

	enum	Parse_Long_Option {
		PARSE_L_HELP =		"help",
		PARSE_L_LICENSE =	"license",
		PARSE_L_START =		"start",
		PARSE_L_VERBOSE =	"Verbose",
		PARSE_L_VERSION =	"version",
		PARSE_L_EXIT =		"exit",

		PARSE_L_CPRIGHT =	"copyright",
		PARSE_L_WARRANTY =	"warranty",

		PARSE_L_PARAM_c =	"param-c",
		PARSE_L_PARAM_n =	"param-n",
		PARSE_L_PARAM_N =	"param-N",
		PARSE_L_PARAM_r =	"param-r",

		PARSE_L_PARAM_a =	"param-a",
		PARSE_L_PARAM_b =	"param-b",
		PARSE_L_PARAM_p =	"param-p",
		PARSE_L_PARAM_x0 =	"param-x0",
		PARSE_L_PARAM_x1 =	"param-x1",
		PARSE_L_PARAM_x2 =	"param-x2",
		PARSE_L_PARAM_beta =	"param-beta",
		PARSE_L_PARAM_lambda =	"param-lambda"
	};

	void	parser	(int argc, char *argv[]);

# endif			/* args.h */
