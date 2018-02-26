
/******************************************************************************
 * This program is free software; you can redistribute it and/or modify	      *
 * it under the terms of the GNU General Public License as published by	      *
 * the Free Software Foundation; either version 2 of the License, or          *
 * (at your option) any later version.					      *
 *									      *
 * This program is distributed in the hope that it will be useful,	      *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of	      *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the	      *
 * GNU General Public License for more details.				      *
 *									      *
 * You should have received a copy of the GNU General Public License	      *
 * along with this program; if not, see the file COPYING, or write	      *
 * to the Free Software Foundation, Inc.				      *
 ******************************************************************************/

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


	double	alx_getdbl	(double	m,
				double		def,
				double		M,
				const char	*formatA,
				const char	*formatB,
						...);

	int64_t	alx_getint	(int64_t	m,
				int64_t		def,
				int64_t		M,
				const char	*formatA,
				const char	*formatB,
						...);

# endif			/* alx_getnum.h */
