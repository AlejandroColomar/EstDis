/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 ******************************************************************************/

	#include <stdio.h>

	#include "alx_file.h"

	#include "macros.h"

	#include "about.h"

void	print_help			(void)
{
	printf(PROG_NAME "\n\n");
}
void	print_version			(void)
{
	printf("Version:\t" PROG_VERS "\n\n");
}
void	print_usage			(void)
{
	printf("Usage: TO BE WRITTEN\n");
	printf("Help:\n");
	printf("$ ./exe --help\n");
	printf("or\n");
	printf("$ ./exe -h\n\n");
}


void	print_cpright			(void)
{
	alx_prn_file("../files/COPYRIGHT.txt");
}
void	print_disclaim			(void)
{
	alx_prn_file("../files/DISCLAIMER.txt");
}
void	print_license			(void)
{
	alx_prn_file("../files/LICENSE.txt");
}


void	dist_binomial_help		(void)
{
	alx_prn_file("../files/dist/binomial.txt");
}
void	dist_poisson_help		(void)
{
	alx_prn_file("../files/dist/poisson.txt");
}
void	dist_geometric_help		(void)
{
	alx_prn_file("../files/dist/geometric.txt");
}
void	dist_hypergeometric_help	(void)
{
	alx_prn_file("../files/dist/hypergeometric.txt");
}
void	dist_uniform_help		(void)
{
	alx_prn_file("../files/dist/uniform.txt");
}
void	dist_exponential_help		(void)
{
	alx_prn_file("../files/dist/exponential.txt");
}
