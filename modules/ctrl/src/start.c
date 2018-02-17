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

//	#include "alx_file.h"
//	#include "alx_getnum.h"
//	#include "alx_math.h"
	#include "alx_ncur.h"
//	#include "alx_seed.h"

	#include "dist.h"
	#include "start.h"

	#include "global_ext.h"
	#include "macros.h"


void	start_switch	(void)
{
	switch (flag_s) {
	case START_FOO:
		break;

	case START_DESC_1VAR:
		desc_1var();
		break;

	case START_DESC_2VAR:
		desc_2var();
		break;

	case START_BINOMIAL:
		dist_binomial();
		break;

	case START_POISSON:
		dist_poisson();
		break;

	case START_GEOMETRIC:
		dist_geometric();
		break;

	case START_HYPERGEOMETRIC:
		break;

	case START_UNIFORM:
		dist_uniform();
		break;

	case START_EXPONENTIAL:
		dist_exponential();
		break;

	case START_NORMAL:
		dist_normal();
		break;
	}
}


void	w_start_switch	(void)
{
	alx_pause_curses();
	start_switch();
	alx_resume_curses();
}
