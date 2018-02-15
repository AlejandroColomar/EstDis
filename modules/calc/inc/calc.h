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
	#include <tgmath.h>

	#include "alx_math.h"



// distributions:
	// Binomial dist.	X -> B(n, p)
# define	binomial_P(n, p, x)		(alx_bin_coef(n, x) * pow(p, x) * pow(1-p, n-x))
# define	binomial_E(n, p)		(n * p)
# define	binomial_Var(n, p)		(n * p * (1 - p))

	// Poisson dist.	X -> P(l)
# define	poisson_P(l, x)			(exp(-l) * pow(l, x) / alx_fact(x))
# define	poisson_E(l)			(l)
# define	poisson_Var(l)			(l)

	// Geometric dist.	X -> G(p)
# define	geometric_P(p, x)		(p * pow(1-p, x-1))
# define	geometric_E(p)			(1 / p)
# define	geometric_Var(p)		((1 - p) / (p * p))

	// Uniform dist.	X -> U(a, b)
# define	uniform_P(a, b, x1, x2)		((x2 - x1) / (b - a))
# define	uniform_E(a, b)			((a + b) / 2)
# define	uniform_Var(a, b)		((b - a) * (b - a) / 12)

	// Exponential dist.	X -> exp(b)
# define	exponential_P(b, x1, x2)	(exp(-b * x1) - exp(-b * x2))
# define	exponential_E(b)		(1 / b)
# define	exponential_Var(b)		(1 / (b * b))

	// Normal (Gauss) dist.	X -> N(u, o2);	Z -> N(0, 1)
# define	normal_o(o2)			(sqrt(o2))
# define	normal_A(o)			(1 / o)
# define	normal_B(u, o)			(-u / o)
# define	normal_Z(a, b, x)		(a * x + b)
# define	normal_X(a, b, z)		((z - b) / a)

// descriptive statistics:
# define	descrip_Eni(ni)			(ni)
# define	descrip_Exi(ni, xi)		(ni * xi)
# define	descrip_Exi2(ni, xi)		(ni * xi * xi)
# define	descrip_Exiyi(xi, yi)		(xi * yi)

# define	descrip_u(Exi, Eni)		(Exi / Eni)
# define	descrip_o2(Exi2, Eni, u)	(Exi2 / Eni - u * u)
# define	descrip_o(o2)			(sqrt(o2))
# define	descrip_s2(o2, Eni)		(o2 * Eni / (Eni - 1))
# define	descrip_s(s2)			(sqrt(s2))
# define	descrip_CV(o, u)		(o / u)

# define	descrip_oxy(n, Exiyi, ux, uy)	(Exiyi / n - ux * uy)
# define	descrip_a(ox2, oxy)		(oxy / ox2)
# define	descrip_b(ux, uy, a)		(uy - a * ux)
# define	descrip_r(ox, oy, oxy)		(oxy / (ox * oy))

# define	descrip_Eyiy2(xi, yi, a, b)	(pow(yi-a*xi-b, 2))

# define	descrip_Aa(n, Exi, Exi2, Eyiy2)	(sqrt(Eyiy2 / ((n - 2) * (Exi2 - Exi * Exi / n))))
# define	descrip_Ab(n, Exi2, Aa)		(Aa * sqrt(Exi2 / n))
# define	descrip_Vr(n, Eyiy2)		(Eyiy2 / n)
# define	descrip_R2(oy2, Vr)		(1 - Vr / oy2)

# endif			/* calc.h */
