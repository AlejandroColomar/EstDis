/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	GPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "estadistica/start.h"

#include "estadistica/about.h"
#include "estadistica/dist.h"


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
int	start_mode;


/******************************************************************************
 ******* static functions (prototypes) ****************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
void	start_switch	(void)
{

	switch (start_mode) {
	case START_FOO:
		break;
	case START_DESC_1VAR:
		desc_1var();
		break;
	case START_DESC_2VAR:
		desc_2var();
		break;
	case START_BINOMIAL:
		dist_binomial();
		break;
	case START_POISSON:
		dist_poisson();
		break;
	case START_GEOMETRIC:
		dist_geometric();
		break;
	case START_HYPERGEOMETRIC:
		break;
	case START_UNIFORM:
		dist_uniform();
		break;
	case START_EXPONENTIAL:
		dist_exponential();
		break;
	case START_NORMAL:
		dist_normal();
		break;
	}
}

void	help_switch	(void)
{

	switch (start_mode) {
	case START_FOO:
		break;
	case START_DESC_1VAR:
		break;
	case START_DESC_2VAR:
		break;
	case START_BINOMIAL:
		print_share_file(SHARE_DIST_BINOMIAL);
		break;
	case START_POISSON:
		print_share_file(SHARE_DIST_POISSON);
		break;
	case START_GEOMETRIC:
		print_share_file(SHARE_DIST_GEOMETRIC);
		break;
	case START_HYPERGEOMETRIC:
		print_share_file(SHARE_DIST_HYPERGEOMETRIC);
		break;
	case START_UNIFORM:
		print_share_file(SHARE_DIST_UNIFORM);
		break;
	case START_EXPONENTIAL:
		print_share_file(SHARE_DIST_EXPONENTIAL);
		break;
	case START_NORMAL:
		break;
	}
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
