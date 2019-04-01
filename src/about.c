/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	GPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "estadistica/about.h"

#include <errno.h>
#include <stddef.h>
#include <stdio.h>

#include "libalx/base/stdio/sprint_file.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define BUFF_SIZE_TEXT	(0xFFFF)	/* 64 KiB */
#define BEGINNING	"\n┌──────────────────────────────────────────────────────────────────────────────┐\n"
#define ENDING		"└──────────────────────────────────────────────────────────────────────────────┘\n\n"


/******************************************************************************
 ******* enums ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* structs / unions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* variables ************************************************************
 ******************************************************************************/
char	share_path [FILENAME_MAX];


/******************************************************************************
 ******* static functions (prototypes) ****************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
void	about_init		(void)
{

	snprintf(share_path, FILENAME_MAX, "%s/estadistica/", INSTALL_SHARE_DIR);
}

void	snprint_share_file	(ptrdiff_t size, char buff[restrict size],
				int file)
{
	char	fname [FILENAME_MAX];

	switch (file) {
	case SHARE_COPYRIGHT:
		if (snprintf(fname, FILENAME_MAX, "%s/%s",
				share_path,
				"COPYRIGHT.txt")  >=  FILENAME_MAX) {
			goto err;
		}
		break;
	case SHARE_DISCLAIMER:
		if (snprintf(fname, FILENAME_MAX, "%s/%s",
				share_path,
				"DISCLAIMER.txt")  >=  FILENAME_MAX) {
			goto err;
		}
		break;
	case SHARE_HELP:
		if (snprintf(fname, FILENAME_MAX, "%s/%s",
				share_path,
				"HELP.txt")  >=  FILENAME_MAX) {
			goto err;
		}
		break;
	case SHARE_LICENSE:
		if (snprintf(fname, FILENAME_MAX, "%s/%s",
				share_path,
				"LICENSE.txt")  >=  FILENAME_MAX) {
			goto err;
		}
		break;
	case SHARE_USAGE:
		if (snprintf(fname, FILENAME_MAX, "%s/%s",
				share_path,
				"USAGE.txt")  >=  FILENAME_MAX) {
			goto err;
		}
		break;

	case SHARE_DIST_BINOMIAL:
		if (snprintf(fname, FILENAME_MAX, "%s/%s",
				share_path,
				"dist/binomial.txt")  >=  FILENAME_MAX) {
			goto err;
		}
		break;
	case SHARE_DIST_POISSON:
		if (snprintf(fname, FILENAME_MAX, "%s/%s",
				share_path,
				"dist/poisson.txt")  >=  FILENAME_MAX) {
			goto err;
		}
		break;
	case SHARE_DIST_GEOMETRIC:
		if (snprintf(fname, FILENAME_MAX, "%s/%s",
				share_path,
				"dist/geometric.txt")  >=  FILENAME_MAX) {
			goto err;
		}
		break;
	case SHARE_DIST_HYPERGEOMETRIC:
		if (snprintf(fname, FILENAME_MAX, "%s/%s",
				share_path,
				"dist/hypergeometric.txt")  >=  FILENAME_MAX) {
			goto err;
		}
		break;
	case SHARE_DIST_UNIFORM:
		if (snprintf(fname, FILENAME_MAX, "%s/%s",
				share_path,
				"dist/uniform.txt")  >=  FILENAME_MAX) {
			goto err;
		}
		break;
	case SHARE_DIST_EXPONENTIAL:
		if (snprintf(fname, FILENAME_MAX, "%s/%s",
				share_path,
				"dist/exponential.txt")  >=  FILENAME_MAX) {
			goto err;
		}
		break;
	}

	if (alx_snprint_file(size, buff, fname) < 0)
		printf("errno: %i", errno);

	return;

err:
	printf("Path is too large and has been truncated\n");
	printf("File could not be shown!\n");
}

void	print_share_file	(int file)
{
	char	str [BUFF_SIZE_TEXT];

	snprint_share_file(BUFF_SIZE_TEXT, str, file);

	printf(BEGINNING);
	printf("%s", str);
	printf(ENDING);
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
