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

# ifndef		ABOUT_H
	# define	ABOUT_H

	#include <stdbool.h>

//	#include "alx_about.h"
	#include "alx_file.h"
//	#include "alx_getnum.h"
//	#include "alx_math.h"
//	#include "alx_ncur.h"
//	#include "alx_seed.h"

	#include "macros.h"

	void	print_help			(void);
	void	print_version			(void);
	void	print_usage			(void);

	void	print_cpright			(void);
	void	print_disclaim			(void);

	void	w_print_cpright			(bool nul);
	void	w_print_disclaim		(void);

	# define	print_license()		alx_prn_file(LICENSE_PATH)

	# define	w_print_license()	alx_w_prn_file(LICENSE_PATH)

	void	dist_binomial_help		(void);
	void	dist_poisson_help		(void);
	void	dist_geometric_help		(void);
	void	dist_hypergeometric_help	(void);
	void	dist_uniform_help		(void);
	void	dist_exponential_help		(void);

# endif			/* about.h */
