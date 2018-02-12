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

# ifndef		LIBALX_NCUR_H
	# define	LIBALX_NCUR_H

	#include <curses.h>
//	#include <stdbool.h>
	#include <stdarg.h>
	#include <stdint.h>

	struct	alx_option {
		int8_t	r;
		int8_t	c;
		char	*t;
	};


	void	alx_start_curses(void);

	uint8_t	alx_menu	(const uint8_t		len,
				const struct alx_option	mnu[len],
				WINDOW			*win);

	void	alx_w_title	(WINDOW			*win,
				const char		*str);

	double	alx_w_getdbl_mM	(int16_t		m,
				int16_t			M,
				double			def,
				WINDOW			*win_i,
				WINDOW			*win_o,
				const char		*format,
							...);

	int16_t	alx_w_getint	(int16_t		def,
				WINDOW			*win_i,
				WINDOW			*win_o,
				const char		*format,
							...);

	int16_t	alx_w_getint_mM	(int16_t		m,
				int16_t			M,
				int16_t			def,
				WINDOW			*win_i,
				WINDOW			*win_o,
				const char		*format,
							...);

	void	alx_w_getstr	(char			*str,
				const char		*def,
				WINDOW			*win_i,
				WINDOW			*win_o,
				const char		*format,
							...);

	void	alx_w_getfpath	(char			*fpath,
				const char		*def,
				WINDOW			*win_i,
				WINDOW			*win_o,
				const char		*format,
							...);

# endif			/* alx_ncur.h */
