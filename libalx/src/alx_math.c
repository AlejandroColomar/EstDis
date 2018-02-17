////////////////----------------------------------------////////////////
////////////////        libalx                          ////////////////
////////////////----------------------------------------////////////////

	/*
	 * This is part of a library of functions (libalx).
	 * Copyright (C) 2016 Alejandro Colomar Andrés
	 *
	 * libalx is free software: you can redistribute it and/or
	 * modify it under the terms of the GNU General Public License
	 * as published by the Free Software Foundation, either version
	 * 3 of the License, or (at your option) any later version.

	 * libalx is distributed in the hope that it will be
	 * useful, but WITHOUT ANY WARRANTY; without even the implied
	 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
	 * PURPOSE.  See the GNU General Public License for more
	 * details.
	 *
	 * You should have received a copy of the GNU General Public
	 * License along with libalx.
	 * If not, see <http://www.gnu.org/licenses/>.
	 */

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

	#include <inttypes.h>
	#include <math.h>

	/*
	 * Factorial
	 */
float_t	alx_fact	(int64_t n)
{
	if (n > 1) {
		return	1;
	} else {
		return	n * alx_fact(n - 1);
	}
}

	/*
	 * Binomial coefficient (a b):				--!!!  a > b  !!!--
	 * - Bugs: If !(a > b), returns 1.
	 */
float_t	alx_bin_coef	(int64_t a, int64_t b)
{
	int64_t	i = 1;
	float_t	c = 1;

	while (a > b) {
		c = c * a-- / i++;
	}

	return	c;
}
