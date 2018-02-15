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

//	#include <getopt.h>
	#include <inttypes.h>
	#include <curses.h>
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


uint8_t	alx_menu		(const uint8_t len,
				const struct alx_option mnu[len],
				WINDOW *win)
{
	bool	wh;
	wchar_t	ch;
	uint8_t	i;

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
	uint8_t	h;
	uint8_t	w;
	uint8_t len;

	getmaxyx(win, h, w);
	len =	strlen(str);

	box(win, 0, 0);
	mvwaddch(win, 0, (w - len)/2 - 1, ACS_RTEE);
	wprintw(win, " %s ", str);
	waddch(win, ACS_LTEE);
	wrefresh(win);
}


double	alx_w_getdbl_mM		(int16_t m, int16_t M, double def,
				WINDOW *win_i, WINDOW *win_o,
				const char *format, ...)
{
	va_list	args;
	va_start(args, format);

	int8_t	i;
	double	R;
	bool	wh;
	uint8_t	ri;
	uint8_t	ci;
	uint8_t	ro;
	uint8_t	co;

	getbegyx(win_i, ri, ci);
	getbegyx(win_o, ro, co);
	wmove(win_o, ri-ro +2, ci-co +1);
	if (format == NULL) {
		wprintw(win_o, "Introduce a real number [%i U %i]", m, M);
	} else {
		vw_printw(win_o, format, args);
	}
	wrefresh(win_o);

	wh = true;
	for (i = 0; i < 3 && wh; i++) {
		echo();
		fflush(stdin);
		mvwscanw(win_i, 0, 0, " %lf", &R);
		noecho();

		wclear(win_i);
		wrefresh(win_i);

		if (R < m || R > M) {
			mvwaddstr(win_i, 0, 0, "Not valid!!!");
			wrefresh(win_i);
			wgetch(win_i);
			wclear(win_i);
			wrefresh(win_i);
			R =	def;

		} else {
			wh = false;
		}
	}

	va_end(args);
	return	R;
}


int16_t	alx_w_getint		(int16_t def,
				WINDOW *win_i, WINDOW *win_o,
				const char *format, ...)
{
	va_list	args;
	va_start(args, format);

	double	sf;
	int8_t	i;
	int16_t	Z;
	bool	wh;
	uint8_t	ri;
	uint8_t	ci;
	uint8_t	ro;
	uint8_t	co;

	getbegyx(win_i, ri, ci);
	getbegyx(win_o, ro, co);
	wmove(win_o, ri-ro +2, ci-co +1);
	if (format == NULL) {
		waddstr(win_o, "Introduce an integer number");
	} else {
		vw_printw(win_o, format, args);
	}
	wrefresh(win_o);

	wh = true;
	for (i = 0; i < 3 && wh; i++) {
		echo();
		fflush(stdin);
		mvwscanw(win_i, 0, 0, " %lf", &sf);
		noecho();

		wclear(win_i);
		wrefresh(win_i);
		Z =	sf;

		if (sf != Z) {
			mvwaddstr(win_i, 0, 0, "Not valid!!!");
			wrefresh(win_i);
			wgetch(win_i);
			wclear(win_i);
			wrefresh(win_i);
			Z =	def;

		} else {
			wh = false;
		}
	}

	wclear(win_i);
	wrefresh(win_i);
	delwin(win_i);

	va_end(args);
	return	Z;
}


int16_t	alx_w_getint_mM		(int16_t m, int16_t M, int16_t def,
				WINDOW *win_i, WINDOW *win_o,
				const char *format, ...)
{
	va_list	args;
	va_start(args, format);

	double	sf;
	int8_t	i;
	int16_t	Z;
	bool	wh;
	uint8_t	ri;
	uint8_t	ci;
	uint8_t	ro;
	uint8_t	co;

	getbegyx(win_i, ri, ci);
	getbegyx(win_o, ro, co);
	wmove(win_o, ri-ro +2, ci-co +1);
	if (format == NULL) {
		wprintw(win_o, "Introduce an integer number [%i U %i]", m, M);
	} else {
		vw_printw(win_o, format, args);
	}
	wrefresh(win_o);

	wh = true;
	for (i = 0; i < 3 && wh; i++) {
		echo();
		fflush(stdin);
		mvwscanw(win_i, 0, 0, " %lf", &sf);
		noecho();

		wclear(win_i);
		wrefresh(win_i);
		Z =	sf;

		if (sf < m || sf != Z || sf > M) {
			mvwaddstr(win_i, 0, 0, "Not valid!!!");
			wrefresh(win_i);
			wgetch(win_i);
			wclear(win_i);
			wrefresh(win_i);
			Z =	def;

		} else {
			wh = false;
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

	int	sf;
	int8_t	i;
	bool	wh;
	uint8_t	ri;
	uint8_t	ci;
	uint8_t	ro;
	uint8_t	co;

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
	for (i = 0; i < 3 && wh; i++) {
		echo();
		fflush(stdin);
		sf = mvwscanw(win_i, 0, 0, " %s", str);
		noecho();

		wclear(win_i);
		wrefresh(win_i);

		if (sf == ERR) {
			mvwaddstr(win_i, 0, 0, "Not valid!!!");
			wrefresh(win_i);
			wgetch(win_i);
			wclear(win_i);
			wrefresh(win_i);
			strcpy(str, def);
		} else {
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

	int	sf;
	int8_t	i;
	bool	wh;
	FILE	*fp;
	uint8_t	ri;
	uint8_t	ci;
	uint8_t	ro;
	uint8_t	co;

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
	for (i = 0; i < 3 && wh; i++) {
		echo();
		fflush(stdin);
		sf = mvwscanw(win_i, 0, 0, " %s", fpath);
		noecho();

		wclear(win_i);
		wrefresh(win_i);
		fp =	fopen(fpath, "r");

		if (fp == NULL || sf == ERR) {
			mvwaddstr(win_i, 0, 0, "Not valid!!!");
			wrefresh(win_i);
			wgetch(win_i);
			wclear(win_i);
			wrefresh(win_i);
			strcpy(fpath, def);
		} else {
			fclose(fp);
			wh = false;
		}
	}

	va_end(args);
}
