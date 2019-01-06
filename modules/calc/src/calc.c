/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
/* Standard C ----------------------------------------------------------------*/
	#include <math.h>

/* libalx --------------------------------------------------------------------*/
	#include "alx_math.h"

/* Module --------------------------------------------------------------------*/
	#include "calc.h"


/******************************************************************************
 ******* variables ************************************************************
 ******************************************************************************/
	int64_t	param_i_a;
	int64_t	param_i_b;
	int64_t	param_i_c;
	int64_t	param_i_n;
	int64_t	param_i_N;
	int64_t	param_i_r;
	int64_t	param_i_x [65536];

	double	param_a;
	double	param_b;
	double	param_p;
	double	param_x_dbl [65536];
	double	param_y [65536];
	double	param_beta;
	double	param_lambda;
	double	param_mu;
	double	param_sigma2;
	double	param_X;
	double	param_Z;
#if 0
	double	result_P;
	double	result_E;
	double	result_Var;
#endif

/******************************************************************************
 ******* main *****************************************************************
 ******************************************************************************/
// distributions:
	// Binomial dist.	X -> B(n, p)
double	binomial_P	(double n, double p, double x)
{
	double ret;

	ret	= alx_bin_coef(n, x) * pow(p, x) * pow(1-p, n-x);

	return	ret;
}

double	binomial_E	(double n, double p)
{
	double ret;

	ret	= n * p;

	return	ret;
}

double	binomial_Var	(double n, double p)
{
	double ret;

	ret	= n * p * (1 - p);

	return	ret;
}


	// Poisson dist.	X -> P(l)
double	poisson_P	(double l, double x)
{
	double ret;

	ret	= exp(-l) * pow(l, x) / alx_fact(x);

	return	ret;
}

double	poisson_E	(double l)
{
	double ret;

	ret	= l;

	return	ret;
}

double	poisson_Var	(double l)
{
	double ret;

	ret	= l;

	return	ret;
}


	// Geometric dist.	X -> G(p)
double	geometric_P	(double p, double x)
{
	double ret;

	ret	= p * pow(1-p, x-1);

	return	ret;
}

double	geometric_E	(double p)
{
	double ret;

	ret	= 1 / p;

	return	ret;
}

double	geometric_Var	(double p)
{
	double ret;

	ret	= (1 - p) / (p * p);

	return	ret;
}


	// Uniform dist.	X -> U(a, b)
double	uniform_P	(double a, double b, double x1, double x2)
{
	double ret;

	ret	= (x2 - x1) / (b - a);

	return	ret;
}

double	uniform_E	(double a, double b)
{
	double ret;

	ret	= (a + b) / 2;

	return	ret;
}

double	uniform_Var	(double a, double b)
{
	double ret;

	ret	= (b - a) * (b - a) / 12;

	return	ret;
}


	// Exponential dist.	X -> exp(b)
double	exponential_P	(double b, double x1, double x2)
{
	double ret;

	ret	= exp(-b * x1) - exp(-b * x2);

	return	ret;
}

double	exponential_E	(double b)
{
	double ret;

	ret	= 1 / b;

	return	ret;
}

double	exponential_Var	(double b)
{
	double ret;

	ret	= 1 / (b * b);

	return	ret;
}


	// Normal (Gauss) dist.	X -> N(u, o2);	Z -> N(0, 1)
double	normal_o	(double o2)
{
	double ret;

	ret	= sqrt(o2);

	return	ret;
}

double	normal_A	(double o)
{
	double ret;

	ret	= 1 / o;

	return	ret;
}

double	normal_B	(double u, double o)
{
	double ret;

	ret	= -u / o;

	return	ret;
}

double	normal_Z	(double a, double b, double x)
{
	double ret;

	ret	= a * x + b;

	return	ret;
}

double	normal_X	(double a, double b, double z)
{
	double ret;

	ret	= (z - b) / a;

	return	ret;
}


// descriptive statistics:
double	descrip_Eni	(double ni)
{
	double ret;

	ret	= ni;

	return	ret;
}

double	descrip_Exi	(double ni, double xi)
{
	double ret;

	ret	= ni * xi;

	return	ret;
}

double	descrip_Exi2	(double ni, double xi)
{
	double ret;

	ret	= ni * xi * xi;

	return	ret;
}

double	descrip_Exiyi	(double xi, double yi)
{
	double ret;

	ret	= xi * yi;

	return	ret;
}


double	descrip_u	(double Exi, double Eni)
{
	double ret;

	ret	= Exi / Eni;

	return	ret;
}

double	descrip_o2	(double Exi2, double Eni, double u)
{
	double ret;

	ret	= Exi2 / Eni - u * u;

	return	ret;
}

double	descrip_o	(double o2)
{
	double ret;

	ret	= sqrt(o2);

	return	ret;
}

double	descrip_s2	(double o2, double Eni)
{
	double ret;

	ret	= o2 * Eni / (Eni - 1);

	return	ret;
}

double	descrip_s	(double s2)
{
	double ret;

	ret	= sqrt(s2);

	return	ret;
}

double	descrip_CV	(double o, double u)
{
	double ret;

	ret	= o / u;

	return	ret;
}


double	descrip_oxy	(double n, double Exiyi, double ux, double uy)
{
	double ret;

	ret	= Exiyi / n - ux * uy;

	return	ret;
}

double	descrip_a	(double ox2, double oxy)
{
	double ret;

	ret	= oxy / ox2;

	return	ret;
}

double	descrip_b	(double ux, double uy, double a)
{
	double ret;

	ret	= uy - a * ux;

	return	ret;
}

double	descrip_r	(double ox, double oy, double oxy)
{
	double ret;

	ret	= oxy / (ox * oy);

	return	ret;
}


double	descrip_Eyiy2	(double xi, double yi, double a, double b)
{
	double ret;

	ret	= pow(yi-a*xi-b, 2);

	return	ret;
}


double	descrip_Aa	(double n, double Exi, double Exi2, double Eyiy2)
{
	double ret;

	ret	= sqrt(Eyiy2 / ((n - 2) * (Exi2 - Exi * Exi / n)));

	return	ret;
}

double	descrip_Ab	(double n, double Exi2, double Aa)
{
	double ret;

	ret	= Aa * sqrt(Exi2 / n);

	return	ret;
}

double	descrip_Vr	(double n, double Eyiy2)
{
	double ret;

	ret	= Eyiy2 / n;

	return	ret;
}

double	descrip_R2	(double oy2, double Vr)
{
	double ret;

	ret	= 1 - Vr / oy2;

	return	ret;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
