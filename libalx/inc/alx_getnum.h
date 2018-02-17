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

# ifndef		ALX_GETNUM_H
	# define	ALX_GETNUM_H

//	#include <curses.h>
	#include <math.h>
//	#include <stdbool.h>
	#include <stdarg.h>
	#include <stdint.h>

	/*
	 * Examples:
	 *	a =	alx_getdbl_mM(m, M, d, "a:\t", NULL);
	 *	a =	alx_getdbl_m(m, d, "a:\t", NULL);
	 *	a =	alx_getdbl("a:\t", NULL);
	 *	a =	alx_getint_mM(m, M, d, "a:\t", NULL);
	 *	a =	alx_getint_m(m, d, "a:\t", NULL);
	 */


	float_t	alx_getdbl_mM	(float_t	m,
				float_t		M,
				float_t		def,
				const char	*formatA,
				const char	*formatB,
						...);

	float_t	alx_getdbl_m	(float_t	m,
				float_t		def,
				const char	*formatA,
				const char	*formatB,
						...);

	float_t	alx_getdbl	(float_t	def,
				const char	*formatA,
				const char	*formatB,
						...);

	int64_t	alx_getint_mM	(int64_t	m,
				int64_t		M,
				int64_t		def,
				const char	*formatA,
				const char	*formatB,
						...);

	int64_t	alx_getint_m	(int64_t	m,
				int64_t		def,
				const char	*formatA,
				const char	*formatB,
						...);

# endif			/* alx_getnum.h */
