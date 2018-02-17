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


// distributions:
	// Binomial dist.	X -> B(n, p)
float_t	binomial_P	(float_t n, float_t p, float_t x);
float_t	binomial_E	(float_t n, float_t p);
float_t	binomial_Var	(float_t n, float_t p);

	// Poisson dist.	X -> P(l)
float_t	poisson_P	(float_t l, float_t x);
float_t	poisson_E	(float_t l);
float_t	poisson_Var	(float_t l);

	// Geometric dist.	X -> G(p)
float_t	geometric_P	(float_t p, float_t x);
float_t	geometric_E	(float_t p);
float_t	geometric_Var	(float_t p);

	// Uniform dist.	X -> U(a, b)
float_t	uniform_P	(float_t a, float_t b, float_t x1, float_t x2);
float_t	uniform_E	(float_t a, float_t b);
float_t	uniform_Var	(float_t a, float_t b);

	// Exponential dist.	X -> exp(b)
float_t	exponential_P	(float_t b, float_t x1, float_t x2);
float_t	exponential_E	(float_t b);
float_t	exponential_Var	(float_t b);

	// Normal (Gauss) dist.	X -> N(u, o2);	Z -> N(0, 1)
float_t	normal_o	(float_t o2);
float_t	normal_A	(float_t o);
float_t	normal_B	(float_t u, float_t o);
float_t	normal_Z	(float_t a, float_t b, float_t x);
float_t	normal_X	(float_t a, float_t b, float_t z);

// descriptive statistics:
float_t	descrip_Eni	(float_t ni);
float_t	descrip_Exi	(float_t ni, float_t xi);
float_t	descrip_Exi2	(float_t ni, float_t xi);
float_t	descrip_Exiyi	(float_t xi, float_t yi);

float_t	descrip_u	(float_t Exi, float_t Eni);
float_t	descrip_o2	(float_t Exi2, float_t Eni, float_t u);
float_t	descrip_o	(float_t o2);
float_t	descrip_s2	(float_t o2, float_t Eni);
float_t	descrip_s	(float_t s2);
float_t	descrip_CV	(float_t o, float_t u);

float_t	descrip_oxy	(float_t n, float_t Exiyi, float_t ux, float_t uy);
float_t	descrip_a	(float_t ox2, float_t oxy);
float_t	descrip_b	(float_t ux, float_t uy, float_t a);
float_t	descrip_r	(float_t ox, float_t oy, float_t oxy);
float_t	descrip_Eyiy2	(float_t xi, float_t yi, float_t a, float_t b);

float_t	descrip_Aa	(float_t n, float_t Exi, float_t Exi2, float_t Eyiy2);
float_t	descrip_Ab	(float_t n, float_t Exi2, float_t Aa);
float_t	descrip_Vr	(float_t n, float_t Eyiy2);
float_t	descrip_R2	(float_t oy2, float_t Vr);

# endif			/* calc.h */
