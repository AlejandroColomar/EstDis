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

	#include <curses.h>
//	#include <getopt.h>
	#include <inttypes.h>
	#include <math.h>
	#include <stdarg.h>
	#include <stdbool.h>
//	#include <stdint.h>
	#include <stdio.h>
//	#include <stdlib.h>
	#include <string.h>
//	#include <sys/types.h>
//	#include <time.h>
//	#include <unistd.h>
	#include <wchar.h>

	#include "alx_ncur.h"

	# define	BUFF_SIZE	1024


void	alx_start_curses	(void)
{
	initscr();
	nonl();
	cbreak();
	noecho();
	keypad(stdscr, true);
//	start_color();
//	mousemask(BUTTON4_PRESSED | BUTTON2_PRESSED, NULL);
}


void	alx_pause_curses	(void)
{
	def_prog_mode();
	endwin();
}


void	alx_resume_curses	(void)
{
	fflush(stdout);
	getchar();
	reset_prog_mode();
}


void	alx_end_curses	(void)
{
	endwin();
}


int64_t	alx_menu		(const int64_t len,
				const struct alx_option mnu[len],
				WINDOW *win)
{
	bool	wh;
	wchar_t	ch;
	int64_t	i;

	noecho();

	i =	1;
	wmove(win, mnu[i].r, mnu[i].c + 1);
	wh = true;
	while (wh) {
		ch = wgetch(win);

		if ((ch >= '0') && (ch < len + '0')) {
			i = ch - '0';
			wmove(win, mnu[i].r, mnu[i].c + 1);
		} else if (ch == KEY_UP) {
			if (i != 0) {
				i--;
			} else {
				i = len - 1;
			}
			wmove(win, mnu[i].r, mnu[i].c + 1);
		} else if (ch == KEY_DOWN) {
			if (i != len - 1) {
				i++;
			} else {
				i = 0;
			}
			wmove(win, mnu[i].r, mnu[i].c + 1);
		} else if (ch == '\r') {
			wh = false;
		}
	}

	return	i;
}


void	alx_w_title		(WINDOW *win, const char *str)
{
	int64_t	h;
	int64_t	w;
	int64_t len;

	getmaxyx(win, h, w);
	len =	strlen(str);

	box(win, 0, 0);
	mvwaddch(win, 0, (w - len)/2 - 1, ACS_RTEE);
	wprintw(win, " %s ", str);
	waddch(win, ACS_LTEE);
	wrefresh(win);
}


float_t	alx_w_getdbl_mM		(float_t m, float_t M, float_t def,
				WINDOW *win_i, WINDOW *win_o,
				const char *format, ...)
{
	va_list	args;
	va_start(args, format);

	int64_t	i;
	int64_t	wh;
	char	buff [BUFF_SIZE];
	int64_t	x;
	float_t	R;
	int64_t	ri;
	int64_t	ci;
	int64_t	ro;
	int64_t	co;

	getbegyx(win_i, ri, ci);
	getbegyx(win_o, ro, co);
	wmove(win_o, ri-ro +2, ci-co +1);
	if (format == NULL) {
		wprintw(win_o, "Introduce a real number [%f U %f]", m, M);
	} else {
		vw_printw(win_o, format, args);
	}
	wrefresh(win_o);

	wh = 1;
	for (i = 0; i < 2 && wh; i++) {
		echo();
		x =	mvwgetstr(win_i, 0, 0, buff);
		noecho();

		wclear(win_i);
		wrefresh(win_i);

		if (x) {
			if (1 == sscanf(buff, "%f", &R)) {
				if (R < m || R > M) {
					wh = 1;
				} else {
					wh = 0;
				}
			} else {
				wh = 2;
			}
		} else {
			wh = 3;
		}

		if (wh) {
			switch (wh) {
			case 1:
				mvwaddstr(win_i, 0, 0, "Not valid");
					break;
			case 2:
				mvwaddstr(win_i, 0, 0, "Not valid!");
					break;
			case 3:
				mvwaddstr(win_i, 0, 0, "Not valid!!!");
					break;
			}
			wrefresh(win_i);
			wgetch(win_i);
			wclear(win_i);
			wrefresh(win_i);
			R =	def;
		}
	}

	va_end(args);
	return	R;
}


int64_t	alx_w_getint		(int64_t def,
				WINDOW *win_i, WINDOW *win_o,
				const char *format, ...)
{
	va_list	args;
	va_start(args, format);

	int64_t	i;
	int64_t	wh;
	char	buff [BUFF_SIZE];
	int64_t	x;
	int64_t	Z;
	int64_t	ri;
	int64_t	ci;
	int64_t	ro;
	int64_t	co;

	getbegyx(win_i, ri, ci);
	getbegyx(win_o, ro, co);
	wmove(win_o, ri-ro +2, ci-co +1);
	if (format == NULL) {
		waddstr(win_o, "Introduce an integer number");
	} else {
		vw_printw(win_o, format, args);
	}
	wrefresh(win_o);

	wh = 1;
	for (i = 0; i < 2 && wh; i++) {
		echo();
		x =	mvwgetstr(win_i, 0, 0, buff);
		noecho();

		wclear(win_i);
		wrefresh(win_i);

		if (x) {
			if (1 == sscanf(buff, "%"SCNi64"", &Z)) {
				wh = 0;
			} else {
				wh = 2;
			}
		} else {
			wh = 3;
		}

		if (wh) {
			switch (wh) {
			case 2:
				mvwaddstr(win_i, 0, 0, "Not valid!");
					break;
			case 3:
				mvwaddstr(win_i, 0, 0, "Not valid!!!");
					break;
			}
			wrefresh(win_i);
			wgetch(win_i);
			wclear(win_i);
			wrefresh(win_i);
			Z =	def;
		}
	}

	wclear(win_i);
	wrefresh(win_i);
	delwin(win_i);

	va_end(args);
	return	Z;
}


int64_t	alx_w_getint_mM		(int64_t m, int64_t M, int64_t def,
				WINDOW *win_i, WINDOW *win_o,
				const char *format, ...)
{
	va_list	args;
	va_start(args, format);

	int64_t	i;
	int64_t	wh;
	char	buff [BUFF_SIZE];
	int64_t	x;
	int64_t	Z;
	int64_t	ri;
	int64_t	ci;
	int64_t	ro;
	int64_t	co;

	getbegyx(win_i, ri, ci);
	getbegyx(win_o, ro, co);
	wmove(win_o, ri-ro +2, ci-co +1);
	if (format == NULL) {
		wprintw(win_o, "Introduce an integer number [%"SCNi64" U %"SCNi64"]", m, M);
	} else {
		vw_printw(win_o, format, args);
	}
	wrefresh(win_o);

	wh = 1;
	for (i = 0; i < 2 && wh; i++) {
		echo();
		x =	mvwgetstr(win_i, 0, 0, buff);
		noecho();

		wclear(win_i);
		wrefresh(win_i);

		if (x) {
			if (1 == sscanf(buff, "%"SCNi64"", &Z)) {
				if (Z < m || Z > M) {
					wh = 1;
				} else {
					wh = 0;
				}
			} else {
				wh = 2;
			}
		} else {
			wh = 3;
		}

		if (wh) {
			switch (wh) {
			case 1:
				mvwaddstr(win_i, 0, 0, "Not valid");
					break;
			case 2:
				mvwaddstr(win_i, 0, 0, "Not valid!");
					break;
			case 3:
				mvwaddstr(win_i, 0, 0, "Not valid!!!");
					break;
			}
			wrefresh(win_i);
			wgetch(win_i);
			wclear(win_i);
			wrefresh(win_i);
			Z =	def;
		}
	}

	va_end(args);
	return	Z;
}


void	alx_w_getstr		(char *str, const char *def,
				WINDOW *win_i, WINDOW *win_o,
				const char *format, ...)
{
	va_list	args;
	va_start(args, format);

	int64_t	i;
	bool	wh;
	char	buff [BUFF_SIZE];
	int64_t	x;
	int64_t	ri;
	int64_t	ci;
	int64_t	ro;
	int64_t	co;

	getbegyx(win_i, ri, ci);
	getbegyx(win_o, ro, co);
	wmove(win_o, ri-ro +2, ci-co +1);
	if (format == NULL) {
		waddstr(win_o, "Introduce a string");
	} else {
		vw_printw(win_o, format, args);
	}
	wrefresh(win_o);

	wh = true;
	for (i = 0; i < 2 && wh; i++) {
		echo();
		x =	mvwgetstr(win_i, 0, 0, buff);
		noecho();

		wclear(win_i);
		wrefresh(win_i);

		if (x == ERR) {
			mvwaddstr(win_i, 0, 0, "Not valid!!!");
			wrefresh(win_i);
			wgetch(win_i);
			wclear(win_i);
			wrefresh(win_i);
			strcpy(str, def);
		} else {
			strcpy(str, buff);
			wh = false;
		}
	}

	va_end(args);
}


void	alx_w_getfpath		(char *fpath, const char *def,
				WINDOW *win_i, WINDOW *win_o,
				const char *format, ...)
{
	va_list	args;
	va_start(args, format);

	int64_t	i;
	bool	wh;
	char	buff [BUFF_SIZE];
	int64_t	x;
	FILE	*fp;
	int64_t	ri;
	int64_t	ci;
	int64_t	ro;
	int64_t	co;

	getbegyx(win_i, ri, ci);
	getbegyx(win_o, ro, co);
	wmove(win_o, ri-ro +2, ci-co +1);
	if (format == NULL) {
		waddstr(win_o, "Introduce a file path");
	} else {
		vw_printw(win_o, format, args);
	}
	wrefresh(win_o);

	wh = true;
	for (i = 0; i < 2 && wh; i++) {
		echo();
		x =	mvwgetstr(win_i, 0, 0, buff);
		noecho();

		wclear(win_i);
		wrefresh(win_i);
		fp =	fopen(buff, "r");

		if (fp == NULL || x == ERR) {
			mvwaddstr(win_i, 0, 0, "Not valid!!!");
			wrefresh(win_i);
			wgetch(win_i);
			wclear(win_i);
			wrefresh(win_i);
			strcpy(fpath, def);
		} else {
			fclose(fp);
			strcpy(fpath, buff);
			wh = false;
		}
	}

	va_end(args);
}
