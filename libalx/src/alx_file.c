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
//	#include <pthread.h>
//	#include <stdarg.h>
//	#include <stdbool.h>
	#include <stdio.h>
//	#include <stdlib.h>
//	#include <string.h>
//	#include <sys/types.h>
//	#include <threads.h>
//	#include <time.h>
//	#include <unistd.h>
//	#include <wchar.h>

	#include "alx_file.h"
	#include "alx_ncur.h"




void	alx_prn_file		(const char *filepath)
{

	int64_t	c;
	FILE	*fp;

	fp =	fopen(filepath, "r");
	printf("\n________________________________________________________________________________");
	printf("\n\n");
	if (fp) {
		while ((c = getc(fp)) != EOF){
			putchar(c);
		}
		fclose(fp);
	}
	printf("\n________________________________________________________________________________");
	printf("\n\n");

}

void	alx_w_prn_file	(const char *filepath)
{
	alx_pause_curses();
	alx_prn_file(filepath);
	alx_resume_curses();
}
