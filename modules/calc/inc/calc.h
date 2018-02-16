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


// distributions:
	// Binomial dist.	X -> B(n, p)
long double	binomial_P	(long double n, long double p, long double x);
long double	binomial_E	(long double n, long double p);
long double	binomial_Var	(long double n, long double p);

	// Poisson dist.	X -> P(l)
long double	poisson_P	(long double l, long double x);
long double	poisson_E	(long double l);
long double	poisson_Var	(long double l);

	// Geometric dist.	X -> G(p)
long double	geometric_P	(long double p, long double x);
long double	geometric_E	(long double p);
long double	geometric_Var	(long double p);

	// Uniform dist.	X -> U(a, b)
long double	uniform_P	(long double a, long double b, long double x1, long double x2);
long double	uniform_E	(long double a, long double b);
long double	uniform_Var	(long double a, long double b);

	// Exponential dist.	X -> exp(b)
long double	exponential_P	(long double b, long double x1, long double x2);
long double	exponential_E	(long double b);
long double	exponential_Var	(long double b);

	// Normal (Gauss) dist.	X -> N(u, o2);	Z -> N(0, 1)
long double	normal_o	(long double o2);
long double	normal_A	(long double o);
long double	normal_B	(long double u, long double o);
long double	normal_Z	(long double a, long double b, long double x);
long double	normal_X	(long double a, long double b, long double z);

// descriptive statistics:
long double	descrip_Eni	(long double ni);
long double	descrip_Exi	(long double ni, long double xi);
long double	descrip_Exi2	(long double ni, long double xi);
long double	descrip_Exiyi	(long double xi, long double yi);

long double	descrip_u	(long double Exi, long double Eni);
long double	descrip_o2	(long double Exi2, long double Eni, long double u);
long double	descrip_o	(long double o2);
long double	descrip_s2	(long double o2, long double Eni);
long double	descrip_s	(long double s2);
long double	descrip_CV	(long double o, long double u);

long double	descrip_oxy	(long double n, long double Exiyi, long double ux, long double uy);
long double	descrip_a	(long double ox2, long double oxy);
long double	descrip_b	(long double ux, long double uy, long double a);
long double	descrip_r	(long double ox, long double oy, long double oxy);
long double	descrip_Eyiy2	(long double xi, long double yi, long double a, long double b);

long double	descrip_Aa	(long double n, long double Exi, long double Exi2, long double Eyiy2);
long double	descrip_Ab	(long double n, long double Exi2, long double Aa);
long double	descrip_Vr	(long double n, long double Eyiy2);
long double	descrip_R2	(long double oy2, long double Vr);

# endif			/* calc.h */
