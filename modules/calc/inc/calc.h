/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 ******************************************************************************/

# ifndef		CALC_H
	# define	CALC_H

	#include <math.h>


// distributions:
	// Binomial dist.	X -> B(n, p)
double	binomial_P	(double n, double p, double x);
double	binomial_E	(double n, double p);
double	binomial_Var	(double n, double p);

	// Poisson dist.	X -> P(l)
double	poisson_P	(double l, double x);
double	poisson_E	(double l);
double	poisson_Var	(double l);

	// Geometric dist.	X -> G(p)
double	geometric_P	(double p, double x);
double	geometric_E	(double p);
double	geometric_Var	(double p);

	// Uniform dist.	X -> U(a, b)
double	uniform_P	(double a, double b, double x1, double x2);
double	uniform_E	(double a, double b);
double	uniform_Var	(double a, double b);

	// Exponential dist.	X -> exp(b)
double	exponential_P	(double b, double x1, double x2);
double	exponential_E	(double b);
double	exponential_Var	(double b);

	// Normal (Gauss) dist.	X -> N(u, o2);	Z -> N(0, 1)
double	normal_o	(double o2);
double	normal_A	(double o);
double	normal_B	(double u, double o);
double	normal_Z	(double a, double b, double x);
double	normal_X	(double a, double b, double z);

// descriptive statistics:
double	descrip_Eni	(double ni);
double	descrip_Exi	(double ni, double xi);
double	descrip_Exi2	(double ni, double xi);
double	descrip_Exiyi	(double xi, double yi);

double	descrip_u	(double Exi, double Eni);
double	descrip_o2	(double Exi2, double Eni, double u);
double	descrip_o	(double o2);
double	descrip_s2	(double o2, double Eni);
double	descrip_s	(double s2);
double	descrip_CV	(double o, double u);

double	descrip_oxy	(double n, double Exiyi, double ux, double uy);
double	descrip_a	(double ox2, double oxy);
double	descrip_b	(double ux, double uy, double a);
double	descrip_r	(double ox, double oy, double oxy);
double	descrip_Eyiy2	(double xi, double yi, double a, double b);

double	descrip_Aa	(double n, double Exi, double Exi2, double Eyiy2);
double	descrip_Ab	(double n, double Exi2, double Aa);
double	descrip_Vr	(double n, double Eyiy2);
double	descrip_R2	(double oy2, double Vr);

# endif			/* calc.h */
