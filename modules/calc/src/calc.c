////////////////----------------------------------------////////////////
////////////////        EstDis                          ////////////////
////////////////----------------------------------------////////////////

	/*
	 * EstDis	This is a solver of statistics problems.
	 * Copyright (C) 2016 Alejandro Colomar Andrés
	 *
	 * This program is free software: you can redistribute it and/or
	 * modify it under the terms of the GNU General Public License
	 * as published by the Free Software Foundation, either version
	 * 3 of the License, or (at your option) any later version.

	 * This program is distributed in the hope that it will be
	 * useful, but WITHOUT ANY WARRANTY; without even the implied
	 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
	 * PURPOSE.  See the GNU General Public License for more
	 * details.
	 *
	 * You should have received a copy of the GNU General Public
	 * License along with this program.
	 * If not, see <http://www.gnu.org/licenses/>.
	 */

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

# ifndef		CALC_H
	# define	CALC_H

	#include <inttypes.h>
	#include <math.h>

	#include "alx_math.h"



// distributions:
	// Binomial dist.	X -> B(n, p)
long double	binomial_P	(long double n, long double p, long double x)
{
	return	(alx_bin_coef(n, x) * pow(p, x) * pow(1-p, n-x));
}

long double	binomial_E	(long double n, long double p)
{
	return	(n * p);
}

long double	binomial_Var	(long double n, long double p)
{
	return	(n * p * (1 - p));
}


	// Poisson dist.	X -> P(l)
long double	poisson_P	(long double l, long double x)
{
	return	(exp(-l) * pow(l, x) / alx_fact(x));
}

long double	poisson_E	(long double l)
{
	return	(l);
}

long double	poisson_Var	(long double l)
{
	return	(l);
}


	// Geometric dist.	X -> G(p)
long double	geometric_P	(long double p, long double x)
{
	return	(p * pow(1-p, x-1));
}

long double	geometric_E	(long double p)
{
	return	(1 / p);
}

long double	geometric_Var	(long double p)
{
	return	((1 - p) / (p * p));
}


	// Uniform dist.	X -> U(a, b)
long double	uniform_P	(long double a, long double b, long double x1, long double x2)
{
	return	((x2 - x1) / (b - a));
}

long double	uniform_E	(long double a, long double b)
{
	return	((a + b) / 2);
}

long double	uniform_Var	(long double a, long double b)
{
	return	((b - a) * (b - a) / 12);
}


	// Exponential dist.	X -> exp(b)
long double	exponential_P	(long double b, long double x1, long double x2)
{
	return	(exp(-b * x1) - exp(-b * x2));
}

long double	exponential_E	(long double b)
{
	return	(1 / b);
}

long double	exponential_Var	(long double b)
{
	return	(1 / (b * b));
}


	// Normal (Gauss) dist.	X -> N(u, o2);	Z -> N(0, 1)
long double	normal_o	(long double o2)
{
	return	(sqrt(o2));
}

long double	normal_A	(long double o)
{
	return	(1 / o);
}

long double	normal_B	(long double u, long double o)
{
	return	(-u / o);
}

long double	normal_Z	(long double a, long double b, long double x)
{
	return	(a * x + b);
}

long double	normal_X	(long double a, long double b, long double z)
{
	return	((z - b) / a);
}


// descriptive statistics:
long double	descrip_Eni	(long double ni)
{
	return	(ni);
}

long double	descrip_Exi	(long double ni, long double xi)
{
	return	(ni * xi);
}

long double	descrip_Exi2	(long double ni, long double xi)
{
	return	(ni * xi * xi);
}

long double	descrip_Exiyi	(long double xi, long double yi)
{
	return	(xi * yi);
}


long double	descrip_u	(long double Exi, long double Eni)
{
	return	(Exi / Eni);
}

long double	descrip_o2	(long double Exi2, long double Eni, long double u)
{
	return	(Exi2 / Eni - u * u);
}

long double	descrip_o	(long double o2)
{
	return	(sqrt(o2));
}

long double	descrip_s2	(long double o2, long double Eni)
{
	return	(o2 * Eni / (Eni - 1));
}

long double	descrip_s	(long double s2)
{
	return	(sqrt(s2));
}

long double	descrip_CV	(long double o, long double u)
{
	return	(o / u);
}


long double	descrip_oxy	(long double n, long double Exiyi, long double ux, long double uy)
{
	return	(Exiyi / n - ux * uy);
}

long double	descrip_a	(long double ox2, long double oxy)
{
	return	(oxy / ox2);
}

long double	descrip_b	(long double ux, long double uy, long double a)
{
	return	(uy - a * ux);
}

long double	descrip_r	(long double ox, long double oy, long double oxy)
{
	return	(oxy / (ox * oy));
}


long double	descrip_Eyiy2	(long double xi, long double yi, long double a, long double b)
{
	return	(pow(yi-a*xi-b, 2));
}


long double	descrip_Aa	(long double n, long double Exi, long double Exi2, long double Eyiy2)
{
	return	(sqrt(Eyiy2 / ((n - 2) * (Exi2 - Exi * Exi / n))));
}

long double	descrip_Ab	(long double n, long double Exi2, long double Aa)
{
	return	(Aa * sqrt(Exi2 / n));
}

long double	descrip_Vr	(long double n, long double Eyiy2)
{
	return	(Eyiy2 / n);
}

long double	descrip_R2	(long double oy2, long double Vr)
{
	return	(1 - Vr / oy2);
}


# endif			/* calc.h */
