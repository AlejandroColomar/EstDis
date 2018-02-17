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

//	#include <curses.h>
	#include <inttypes.h>
	#include <math.h>
	#include <stdarg.h>
	#include <stdbool.h>
	#include <stdio.h>
//	#include <string.h>

	# define	BUFF_SIZE	1024


	/*
	 * Ask for a double in the range [m, M] / [m, inf) / (-inf, inf).
	 *
	 * If the user enters a non valid number, it repeats to ask for
	 * the number two more times. After that, it uses the default
	 * value.
	 *

	 * There is a bug I don't know how to solve: if the user
	 * introduces a char, it does strange things forever.
	 */
double	alx_getdbl_mM	(double m, double M, double def,
			const char *formatA, const char *formatB, ...)
{
	va_list	args;
	va_start(args, formatB);

	int64_t	i;
	char	buff [BUFF_SIZE];
	double	R;
	int64_t	wh;

	if (formatA != NULL) {
		puts(formatA);
	}
	if (formatB == NULL) {
		printf("Introduce a real number [%f U %f] (default %f):...\t", m, M, def);
	} else {
		vprintf(formatB, args);
	}

	wh = 1;
	for (i = 0; i < 2 && wh; i++) {
		if (fgets(buff, BUFF_SIZE, stdin)) {
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
				puts("Not valid");
					break;
			case 2:
				puts("Not valid!");
					break;
			case 3:
				puts("Not valid!!!");
					break;
			}
			R =	def;
		}
	}

	va_end(args);
	return	R;
}

double	alx_getdbl_m	(double m, double def,
			const char *formatA, const char *formatB, ...)
{
	va_list	args;
	va_start(args, formatB);

	int64_t	i;
	char	buff [BUFF_SIZE];
	double	R;
	int64_t	wh;

	if (formatA != NULL) {
		puts(formatA);
	}
	if (formatB == NULL) {
		printf("Introduce a real number [%f U inf) (default %f):...\t", m, def);
	} else {
		vprintf(formatB, args);
	}

	wh = 1;
	for (i = 0; i < 2 && wh; i++) {
		if (fgets(buff, BUFF_SIZE, stdin)) {
			if (1 == sscanf(buff, "%f", &R)) {
				if (R < m) {
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
				puts("Not valid");
					break;
			case 2:
				puts("Not valid!");
					break;
			case 3:
				puts("Not valid!!!");
					break;
			}
			R =	def;
		}
	}

	va_end(args);
	return	R;
}

double	alx_getdbl	(double def,
			const char *formatA, const char *formatB, ...)
{
	va_list	args;
	va_start(args, formatB);

	int64_t	i;
	char	buff [BUFF_SIZE];
	double	R;
	int64_t	wh;

	if (formatA != NULL) {
		puts(formatA);
	}
	if (formatB == NULL) {
		printf("Introduce a real number (-inf U inf) (default %f):...\t", def);
	} else {
		vprintf(formatB, args);
	}

	wh = 1;
	for (i = 0; i < 2 && wh; i++) {
		if (fgets(buff, BUFF_SIZE, stdin)) {
			if (1 == sscanf(buff, "%f", &R)) {
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
				puts("Not valid!");
					break;
			case 3:
				puts("Not valid!!!");
					break;
			}
			R =	def;
		}
	}

	va_end(args);
	return	R;
}

	/*
	 * Ask for an int64_t in the range [m, M] / [m, inf) / (-inf, inf).
	 *
	 * If the user enters a non valid number, it repeats to ask for
	 * the number two more times. After that, it uses the default
	 * value.
	 *
	 * There is a bug I don't know how to solve: if the user
	 * introduces a char, it does strange things forever.
	 */
int64_t	alx_getint_mM	(int64_t m, int64_t M, int64_t def,
			const char *formatA, const char *formatB, ...)
{
	va_list	args;
	va_start(args, formatB);

	int64_t	i;
	char	buff [BUFF_SIZE];
	int64_t	Z;
	int64_t	wh;

	if (formatA != NULL) {
		puts(formatA);
	}
	if (formatB == NULL) {
		printf("Introduce an integer number [%"PRIi64" U %"PRIi64"] (default %"PRIi64"):...\t", m, M, def);
	} else {
		vprintf(formatB, args);
	}

	wh = 1;
	for (i = 0; i < 2 && wh; i++) {
		if (fgets(buff, BUFF_SIZE, stdin)) {
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
				puts("Not valid");
					break;
			case 2:
				puts("Not valid!");
					break;
			case 3:
				puts("Not valid!!!");
					break;
			}
			Z =	def;
		}
	}

	va_end(args);
	return	Z;
}

int64_t	alx_getint_m	(int64_t m, int64_t def,
			const char *formatA, const char *formatB, ...)
{
	va_list	args;
	va_start(args, formatB);

	int64_t	i;
	char	buff [BUFF_SIZE];
	int64_t	Z;
	int64_t	wh;

	if (formatA != NULL) {
		puts(formatA);
	}
	if (formatB == NULL) {
		printf("Introduce an integer number [%"PRIi64" U inf) (default %"PRIi64"):...\t", m, def);
	} else {
		vprintf(formatB, args);
	}

	wh = 1;
	for (i = 0; i < 2 && wh; i++) {
		if (fgets(buff, BUFF_SIZE, stdin)) {
			if (1 == sscanf(buff, "%"SCNi64"", &Z)) {
				if (Z < m) {
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
				puts("Not valid");
					break;
			case 2:
				puts("Not valid!");
					break;
			case 3:
				puts("Not valid!!!");
					break;
			}
			Z =	def;
		}
	}

	va_end(args);
	return	Z;
}
