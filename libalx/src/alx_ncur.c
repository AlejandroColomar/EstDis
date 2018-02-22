
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

static	void	alx_ncur_prn_title	(WINDOW			*win,
					const char		*str);

static	void	alx_ncur_prn_menu	(WINDOW			*win,
					const int64_t		N,
					const struct alx_option	mnu[N]);

static	int64_t	alx_ncur_usr_sel	(WINDOW			*win,
					const int64_t		N,
					const struct alx_option	mnu[N]);


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


int64_t	alx_menu		(const int64_t		h,
				const int64_t		w,
				const int64_t		N,
				const struct alx_option	mnu[N],
				const char		*str)
{

	/* Create a window of size h*w and position (r,c)
	 *	r	start at the top
	 *	c	center in terminal (80 cols)
	 */
	WINDOW		*win;
	const int64_t	r =	1;
	const int64_t	c =	(80 - w) / 2;
	win =	newwin(h, w, r, c);

	/* Activate keypad, and don't echo input */
	keypad(win, true);
	noecho();

	/* Print title and menu items */
	alx_ncur_prn_title(win, str);
	alx_ncur_prn_menu(win, N, mnu);

	/* User input */
	int64_t	i;
	i =	alx_ncur_usr_sel(win, N, mnu);

	/* Delete window */
	wclear(win);
	wrefresh(win);
	delwin(win);

	return	i;
}


double	alx_w_getdbl_mM		(double m, double M, double def,
				WINDOW *win_i, WINDOW *win_o,
				const char *format, ...)
{
	va_list	args;
	va_start(args, format);

	int64_t	i;
	int64_t	wh;
	char	buff [BUFF_SIZE];
	int64_t	x;
	double	R;
	int64_t	ri;
	int64_t	ci;
	int64_t	ro;
	int64_t	co;

	getbegyx(win_i, ri, ci);
	getbegyx(win_o, ro, co);
	wmove(win_o, ri-ro +2, ci-co +1);
	if (format == NULL) {
		wprintw(win_o, "Introduce a real number [%lf U %lf]", m, M);
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
			if (1 == sscanf(buff, "%lf", &R)) {
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

/******************************************************************************/
/******* Static functions *****************************************************/
/******************************************************************************/


static	void	alx_ncur_prn_title	(WINDOW			*win,
					const char		*str)
{
	/* Print window borders */
	box(win, 0, 0);

	/* Find size of window */
	int64_t	h;
	int64_t	w;
	getmaxyx(win, h, w);

	/* Find length of title */
	int64_t len;
	len =	strlen(str);

	/* Print title centered */
	mvwaddch(win, 0, (w - len)/2 - 1, ACS_RTEE);
	wprintw(win, " %s ", str);
	waddch(win, ACS_LTEE);

	wrefresh(win);
}


static	void	alx_ncur_prn_menu	(WINDOW			*win,
					const int64_t		N,
					const struct alx_option	mnu[N])
{
	/* Find size of window */
	int64_t	h;
	int64_t	w;
	getmaxyx(win, h, w);

	/* Print all menu items */
	int64_t	i;
	for (i = 0; i < N; i++) {
		mvwaddstr(win, mnu[i].r, mnu[i].c, mnu[i].t);
	}

	wrefresh(win);
}


static	int64_t	alx_ncur_usr_sel	(WINDOW			*win,
					const int64_t		N,
					const struct alx_option	mnu[N])
{
	/* default item */
	int64_t	i =	1;
	wmove(win, mnu[i].r, mnu[i].c + 1);

	/* Receive input until ENTER key */
	bool	wh;
	wchar_t	ch;
	wh = true;
	while (wh) {
		/* Input */
		ch = wgetch(win);

		if ((ch >= '0') && (ch < N + '0')) {
			/* Input is a number, move to that item */
			i = ch - '0';
			wmove(win, mnu[i].r, mnu[i].c + 1);

		} else if (ch == KEY_UP) {
			/* KEY_UP, move one item up */
			if (i != 0) {
				i--;
			} else {
				i = N - 1;
			}
			wmove(win, mnu[i].r, mnu[i].c + 1);

		} else if (ch == KEY_DOWN) {
			/* KEY_DOWN, move one item down */
			if (i != N - 1) {
				i++;
			} else {
				i = 0;
			}
			wmove(win, mnu[i].r, mnu[i].c + 1);

		} else if (ch == '\r') {
			/* ENTER, end menu */
			wh = false;
		}
	}

	return	i;
}
