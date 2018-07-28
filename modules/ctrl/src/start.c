/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 ******************************************************************************/

//	#include "alx_file.h"
//	#include "alx_getnum.h"
//	#include "alx_math.h"
	#include "alx_ncur.h"
//	#include "alx_seed.h"

	#include "about.h"
	#include "data.h"
	#include "dist.h"

	#include "start.h"


void	start_switch	(void)
{
	switch (flag_s) {
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


void	help_switch			(void)
{
	switch (flag_s) {
	case START_FOO:
		break;

	case START_DESC_1VAR:
		break;

	case START_DESC_2VAR:
		break;

	case START_BINOMIAL:
		dist_binomial_help();
		break;

	case START_POISSON:
		dist_poisson_help();
		break;

	case START_GEOMETRIC:
		dist_geometric_help();
		break;

	case START_HYPERGEOMETRIC:
		dist_hypergeometric_help();
		break;

	case START_UNIFORM:
		dist_uniform_help();
		break;

	case START_EXPONENTIAL:
		dist_exponential_help();
		break;

	case START_NORMAL:
		break;
	}
}
