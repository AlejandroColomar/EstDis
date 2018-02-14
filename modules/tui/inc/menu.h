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

# ifndef		MENU_H
	# define	MENU_H

	/*
	 * + Menu:
	 *	+ Continue:
	 *		+ Descriptiva:
	 *			- 1 Variable
	 *			- 2 Variables
	 *			- ..
	 *		+ Distribuciones:
	 *			- Binomial
	 *			- help
	 *			- Poisson
	 *			- help
	 *			- Geometrica
	 *			- help
	 *			- Hipergeometrica
	 *			- help
	 *			- Uniforme
	 *			- help
	 *			- Exponencial
	 *			- help
	 *			- Gauss(Normal)
	 *			- help
	 *			- ..
	 *		- ..
	 *	- Disclaimer
	 *	- License
	 *	- Exit program
	 */
/*----------------------------------------------------------------------------*/

void	menu_main	(void);
void	menu_continue	(void);
//void	menu_select	(void);
void	menu_verbose	(void);

# endif			/* menu.h */
