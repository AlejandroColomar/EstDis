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

# ifndef		DIST_H
	# define	DIST_H

	#include <inttypes.h>

long double	dist_binomial_P		(int64_t n, long double p, int64_t c);
void		dist_binomial		(void);
long double	dist_poisson_P		(long double l, int64_t c);
void		dist_poisson		(void);
long double	dist_geometric_P	(long double p, int64_t c);
void		dist_geometric		(void);
void		dist_uniform		(void);
void		dist_exponential	(void);
void		dist_normal_m_1		(long double a, long double b);
void		dist_normal_m_2		(long double a, long double b);
void		dist_normal_m		(long double a, long double b);
void		dist_normal		(void);

# endif			/* dist.h */
