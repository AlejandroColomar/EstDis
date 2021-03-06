/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	GPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "estadistica/share.h"

#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define ALX_NO_PREFIX
#include <alx/base/compiler.h>
#include <alx/base/errno.h>
#include <alx/base/stdio.h>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define PROG_YEAR	"2015"

#define SHARE_DIR			"" INSTALL_SHARE_DIR "/estadistica/"
#define SHARE_COPYRIGHT_FILE		"" SHARE_DIR "/COPYRIGHT.txt"
#define SHARE_DISCLAIMER_FILE		"" SHARE_DIR "/DISCLAIMER.txt"
#define SHARE_HELP_FILE			"" SHARE_DIR "/HELP.txt"
#define SHARE_LICENSE_FILE		"" SHARE_DIR "/LICENSE.txt"
#define SHARE_USAGE_FILE		"" SHARE_DIR "/USAGE.txt"
#define SHARE_DIST_BINOMIAL_FILE	"" SHARE_DIR "/dist/binomial.txt"
#define SHARE_DIST_POISSON_FILE		"" SHARE_DIR "/dist/poisson.txt"
#define SHARE_DIST_GEOMETRIC_FILE	"" SHARE_DIR "/dist/geometric.txt"
#define SHARE_DIST_HYPERGEOMETRIC_FILE	"" SHARE_DIR "/dist/hypergeometric.txt"
#define SHARE_DIST_UNIFORM_FILE		"" SHARE_DIR "/dist/uniform.txt"
#define SHARE_DIST_EXPONENTIAL_FILE	"" SHARE_DIR "/dist/exponential.txt"


/******************************************************************************
 ******* enums ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* structs / unions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* variables ************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static functions (prototypes) ****************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
void	print_share_file	(int file)
{
	char	*fname;
	char	cmd[_POSIX_ARG_MAX];

	switch (file) {
	case SHARE_COPYRIGHT:
		fname	= SHARE_COPYRIGHT_FILE;
		break;
	case SHARE_DISCLAIMER:
		fname	= SHARE_DISCLAIMER_FILE;
		break;
	case SHARE_HELP:
		fname	= SHARE_HELP_FILE;
		break;
	case SHARE_LICENSE:
		fname	= SHARE_LICENSE_FILE;
		break;
	case SHARE_USAGE:
		fname	= SHARE_USAGE_FILE;
		break;
	case SHARE_DIST_BINOMIAL:
		fname	= SHARE_DIST_BINOMIAL_FILE;
		break;
	case SHARE_DIST_POISSON:
		fname	= SHARE_DIST_POISSON_FILE;
		break;
	case SHARE_DIST_GEOMETRIC:
		fname	= SHARE_DIST_GEOMETRIC_FILE;
		break;
	case SHARE_DIST_HYPERGEOMETRIC:
		fname	= SHARE_DIST_HYPERGEOMETRIC_FILE;
		break;
	case SHARE_DIST_UNIFORM:
		fname	= SHARE_DIST_UNIFORM_FILE;
		break;
	case SHARE_DIST_EXPONENTIAL:
		fname	= SHARE_DIST_EXPONENTIAL_FILE;
		break;
	}

	if (sbprintf(cmd, NULL, "less %s", fname))
		perrorx("%s", fname);
	if (system(cmd))
		perrorx("%s", cmd);

	return;
}

void	print_version		(void)
{

	printf("%s %s\n\n", program_invocation_short_name, PROG_VERSION);
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
