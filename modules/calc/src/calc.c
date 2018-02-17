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

	#include <math.h>

	#include "alx_math.h"



// distributions:
	// Binomial dist.	X -> B(n, p)
float_t	binomial_P	(float_t n, float_t p, float_t x)
{
	return	(alx_bin_coef(n, x) * pow(p, x) * pow(1-p, n-x));
}

float_t	binomial_E	(float_t n, float_t p)
{
	return	(n * p);
}

float_t	binomial_Var	(float_t n, float_t p)
{
	return	(n * p * (1 - p));
}


	// Poisson dist.	X -> P(l)
float_t	poisson_P	(float_t l, float_t x)
{
	return	(exp(-l) * pow(l, x) / alx_fact(x));
}

float_t	poisson_E	(float_t l)
{
	return	(l);
}

float_t	poisson_Var	(float_t l)
{
	return	(l);
}


	// Geometric dist.	X -> G(p)
float_t	geometric_P	(float_t p, float_t x)
{
	return	(p * pow(1-p, x-1));
}

float_t	geometric_E	(float_t p)
{
	return	(1 / p);
}

float_t	geometric_Var	(float_t p)
{
	return	((1 - p) / (p * p));
}


	// Uniform dist.	X -> U(a, b)
float_t	uniform_P	(float_t a, float_t b, float_t x1, float_t x2)
{
	return	((x2 - x1) / (b - a));
}

float_t	uniform_E	(float_t a, float_t b)
{
	return	((a + b) / 2);
}

float_t	uniform_Var	(float_t a, float_t b)
{
	return	((b - a) * (b - a) / 12);
}


	// Exponential dist.	X -> exp(b)
float_t	exponential_P	(float_t b, float_t x1, float_t x2)
{
	return	(exp(-b * x1) - exp(-b * x2));
}

float_t	exponential_E	(float_t b)
{
	return	(1 / b);
}

float_t	exponential_Var	(float_t b)
{
	return	(1 / (b * b));
}


	// Normal (Gauss) dist.	X -> N(u, o2);	Z -> N(0, 1)
float_t	normal_o	(float_t o2)
{
	return	(sqrt(o2));
}

float_t	normal_A	(float_t o)
{
	return	(1 / o);
}

float_t	normal_B	(float_t u, float_t o)
{
	return	(-u / o);
}

float_t	normal_Z	(float_t a, float_t b, float_t x)
{
	return	(a * x + b);
}

float_t	normal_X	(float_t a, float_t b, float_t z)
{
	return	((z - b) / a);
}


// descriptive statistics:
float_t	descrip_Eni	(float_t ni)
{
	return	(ni);
}

float_t	descrip_Exi	(float_t ni, float_t xi)
{
	return	(ni * xi);
}

float_t	descrip_Exi2	(float_t ni, float_t xi)
{
	return	(ni * xi * xi);
}

float_t	descrip_Exiyi	(float_t xi, float_t yi)
{
	return	(xi * yi);
}


float_t	descrip_u	(float_t Exi, float_t Eni)
{
	return	(Exi / Eni);
}

float_t	descrip_o2	(float_t Exi2, float_t Eni, float_t u)
{
	return	(Exi2 / Eni - u * u);
}

float_t	descrip_o	(float_t o2)
{
	return	(sqrt(o2));
}

float_t	descrip_s2	(float_t o2, float_t Eni)
{
	return	(o2 * Eni / (Eni - 1));
}

float_t	descrip_s	(float_t s2)
{
	return	(sqrt(s2));
}

float_t	descrip_CV	(float_t o, float_t u)
{
	return	(o / u);
}


float_t	descrip_oxy	(float_t n, float_t Exiyi, float_t ux, float_t uy)
{
	return	(Exiyi / n - ux * uy);
}

float_t	descrip_a	(float_t ox2, float_t oxy)
{
	return	(oxy / ox2);
}

float_t	descrip_b	(float_t ux, float_t uy, float_t a)
{
	return	(uy - a * ux);
}

float_t	descrip_r	(float_t ox, float_t oy, float_t oxy)
{
	return	(oxy / (ox * oy));
}


float_t	descrip_Eyiy2	(float_t xi, float_t yi, float_t a, float_t b)
{
	return	(pow(yi-a*xi-b, 2));
}


float_t	descrip_Aa	(float_t n, float_t Exi, float_t Exi2, float_t Eyiy2)
{
	return	(sqrt(Eyiy2 / ((n - 2) * (Exi2 - Exi * Exi / n))));
}

float_t	descrip_Ab	(float_t n, float_t Exi2, float_t Aa)
{
	return	(Aa * sqrt(Exi2 / n));
}

float_t	descrip_Vr	(float_t n, float_t Eyiy2)
{
	return	(Eyiy2 / n);
}

float_t	descrip_R2	(float_t oy2, float_t Vr)
{
	return	(1 - Vr / oy2);
}


# endif			/* calc.h */
