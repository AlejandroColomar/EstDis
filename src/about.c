/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	GPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "estadistica/about.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "libalx/base/stddef/size.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enums ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* structs / unions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* variables ************************************************************
 ******************************************************************************/
char	share_path[FILENAME_MAX];


/******************************************************************************
 ******* static functions (prototypes) ****************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
void	about_init		(void)
{

	if (snprintf(share_path, sizeof(share_path), "%s/estadistica/",
				INSTALL_SHARE_DIR)  >=  SSIZEOF(share_path)) {
		goto err;
	}
	return;
err:
	printf("Path is too large and has been truncated\n");
	exit(EXIT_FAILURE);
}

void	print_share_file	(int file)
{
	char	fname[FILENAME_MAX];
	char	cmd[_POSIX_ARG_MAX];

	switch (file) {
	case SHARE_COPYRIGHT:
		if (snprintf(fname, sizeof(fname), "%s/%s",
				share_path,
				"COPYRIGHT.txt")  >=  SSIZEOF(fname)) {
			goto err;
		}
		break;
	case SHARE_DISCLAIMER:
		if (snprintf(fname, sizeof(fname), "%s/%s",
				share_path,
				"DISCLAIMER.txt")  >=  SSIZEOF(fname)) {
			goto err;
		}
		break;
	case SHARE_HELP:
		if (snprintf(fname, sizeof(fname), "%s/%s",
				share_path,
				"HELP.txt")  >=  SSIZEOF(fname)) {
			goto err;
		}
		break;
	case SHARE_LICENSE:
		if (snprintf(fname, sizeof(fname), "%s/%s",
				share_path,
				"LICENSE.txt")  >=  SSIZEOF(fname)) {
			goto err;
		}
		break;
	case SHARE_USAGE:
		if (snprintf(fname, sizeof(fname), "%s/%s",
				share_path,
				"USAGE.txt")  >=  SSIZEOF(fname)) {
			goto err;
		}
		break;

	case SHARE_DIST_BINOMIAL:
		if (snprintf(fname, sizeof(fname), "%s/%s",
				share_path,
				"dist/binomial.txt")  >=  SSIZEOF(fname)) {
			goto err;
		}
		break;
	case SHARE_DIST_POISSON:
		if (snprintf(fname, sizeof(fname), "%s/%s",
				share_path,
				"dist/poisson.txt")  >=  SSIZEOF(fname)) {
			goto err;
		}
		break;
	case SHARE_DIST_GEOMETRIC:
		if (snprintf(fname, sizeof(fname), "%s/%s",
				share_path,
				"dist/geometric.txt")  >=  SSIZEOF(fname)) {
			goto err;
		}
		break;
	case SHARE_DIST_HYPERGEOMETRIC:
		if (snprintf(fname, sizeof(fname), "%s/%s",
				share_path,
				"dist/hypergeometric.txt")  >=  SSIZEOF(fname)) {
			goto err;
		}
		break;
	case SHARE_DIST_UNIFORM:
		if (snprintf(fname, sizeof(fname), "%s/%s",
				share_path,
				"dist/uniform.txt")  >=  SSIZEOF(fname)) {
			goto err;
		}
		break;
	case SHARE_DIST_EXPONENTIAL:
		if (snprintf(fname, sizeof(fname), "%s/%s",
				share_path,
				"dist/exponential.txt")  >=  SSIZEOF(fname)) {
			goto err;
		}
		break;
	}

	if (snprintf(cmd, sizeof(cmd), "less %s", fname)  >=  SSIZEOF(cmd))
		goto err;
	system(cmd);

	return;
err:
	printf("Path is too large and has been truncated\n");
	printf("File could not be shown!\n");
}

void	print_version		(void)
{

	printf(""PROG_NAME" "PROG_VERSION"\n\n");
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
