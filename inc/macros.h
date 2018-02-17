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

# ifndef			MACROS
	# define		MACROS

	# define		DBG	true
	# define		DBG_th	thr_num
	# if (DBG)
	# 	define		DBG_PRINT(x, y, z)	print_verbose(x, y, z)
	# else
	# 	define		DBG_PRINT(x, y, z)	do {} while (0)
	# endif

	# define		PROG_NAME	"EstDis"
	# define		PROG_YEAR	"2015"
	# define		PROG_VERS	"2.A"
	# define		OPT_LIST	"a:b:c:f:hi:j:k:lo:p:r:s:V:vx"

	# define		ESTDIS_PATH	"./"
	# define		LICENSE_RPATH	"./LICENSE.txt"

	# define		CORES_MAX	1
	# define		THREADS_MAX	(2 * CORES_MAX - 1)

# endif				/* macros.h */
