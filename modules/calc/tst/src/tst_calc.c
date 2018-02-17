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

	#include <curses.h>
	#include <stdbool.h>
	#include <stdint.h>
	#include <stdio.h>

	#include "alx_ncur.h"

	#include "calc.h"


	enum	Tst_Functions {
		TST_END = 0,

		TST_BINOMIAL_P,
		TST_BINOMIAL_E,
		TST_BINOMIAL_Var,

		TST_POISSON_P,
		TST_POISSON_E,
		TST_POISSON_Var,

		TST_GEOMETRIC_P,
		TST_GEOMETRIC_E,
		TST_GEOMETRIC_Var,

		TST_UNIFORM_P,
		TST_UNIFORM_E,
		TST_UNIFORM_Var,

		TST_EXPONENTIAL_P,
		TST_EXPONENTIAL_E,
		TST_EXPONENTIAL_Var,

		TST_NORMAL_O,
		TST_NORMAL_A,
		TST_NORMAL_B,
		TST_NORMAL_Z,
		TST_NORMAL_X,

		TST_DESCRIP_U,
		TST_DESCRIP_O2,
		TST_DESCRIP_O,
		TST_DESCRIP_S2,
		TST_DESCRIP_S,
		TST_DESCRIP_CV,

		TST_DESCRIP_OXY,
		TST_DESCRIP_A,
		TST_DESCRIP_B,
		TST_DESCRIP_R,
		TST_DESCRIP_EIYI2,

		TST_DESCRIP_AA,
		TST_DESCRIP_AB,
		TST_DESCRIP_VR,
		TST_DESCRIP_R2,

		TST_FUNCTIONS
	};


int	main	()
{
	alx_start_curses();

	int64_t	sw;
	bool	wh;
	WINDOW		*win;
	const int64_t	h =	35;
	const int64_t	w =	34;
	const int64_t	r =	1;
	const int64_t	c =	(80 - w) / 2;

	const int64_t		len = TST_FUNCTIONS;
	const struct alx_option	mnu[TST_FUNCTIONS] =	{{32, 4, "[0]  END TEST"},

						{2, 4, "[1]  binomial_P"},
						{3, 4, "[2]  binomial_E"},
						{4, 4, "[3]  binomial_Var"},

						{5, 4, "[4]  poisson_P"},
						{6, 4, "[5]  poisson_E"},
						{7, 4, "[6]  poisson_Var"},

						{8, 4, "[7]  geometric_P"},
						{9, 4, "[8]  geometric_E"},
						{10, 4, "[9]  geometric_Var"},

						{11, 4, "[10] uniform_P"},
						{12, 4, "[11] uniform_E"},
						{13, 4, "[12] uniform_Var"},

						{14, 4, "[13] exponential_P"},
						{15, 4, "[14] exponential_E"},
						{16, 4, "[15] exponential_Var"},

						{17, 4, "[16] normal_o"},
						{18, 4, "[17] normal_A"},
						{19, 4, "[18] normal_B"},
						{20, 4, "[19] normal_Z"},
						{21, 4, "[20] normal_X"},

						{22, 4, "[21] descrip_Eni"},
						{23, 4, "[22] descrip_Exi"},
						{24, 4, "[23] descrip_Exi2"},
						{25, 4, "[24] descrip_Exiyi"},

						{26, 4, "[25] descrip_u"},
						{27, 4, "[26] descrip_o2"},
						{28, 4, "[27] descrip_o"},
						{29, 4, "[28] descrip_s2"},
						{30, 4, "[29] descrip_s"},
						{31, 4, "[30] descrip_CV"},

						{32, 4, "[31] descrip_oxy"},
						{33, 4, "[32] descrip_a"},
						{34, 4, "[33] descrip_b"},
						{35, 4, "[34] descrip_r"},
						{36, 4, "[35] descrip_Eyiy2"},

						{37, 4, "[36] descrip_Aa"},
						{38, 4, "[37] descrip_Ab"},
						{39, 4, "[38] descrip_Vr"},
						{40, 4, "[39] descrip_R2"},};

	wh = true;
	while (wh) {
		win =	newwin(h, w, r, c);
		keypad(win, true);

		alx_w_title(win, "MENU:");
		mvwaddstr(win, mnu[1].r, mnu[1].c, mnu[1].t);
		mvwaddstr(win, mnu[2].r, mnu[2].c, mnu[2].t);
		mvwaddstr(win, mnu[3].r, mnu[3].c, mnu[3].t);
		mvwaddstr(win, mnu[4].r, mnu[4].c, mnu[4].t);
		mvwaddstr(win, mnu[5].r, mnu[5].c, mnu[5].t);
		mvwaddstr(win, mnu[6].r, mnu[6].c, mnu[6].t);
		mvwaddstr(win, mnu[7].r, mnu[7].c, mnu[7].t);
		mvwaddstr(win, mnu[8].r, mnu[8].c, mnu[8].t);
		mvwaddstr(win, mnu[9].r, mnu[9].c, mnu[9].t);
		mvwaddstr(win, mnu[10].r, mnu[10].c, mnu[10].t);
		mvwaddstr(win, mnu[11].r, mnu[11].c, mnu[11].t);
		mvwaddstr(win, mnu[12].r, mnu[12].c, mnu[12].t);
		mvwaddstr(win, mnu[13].r, mnu[13].c, mnu[13].t);
		mvwaddstr(win, mnu[14].r, mnu[14].c, mnu[14].t);
		mvwaddstr(win, mnu[15].r, mnu[15].c, mnu[15].t);
		mvwaddstr(win, mnu[16].r, mnu[16].c, mnu[16].t);
		mvwaddstr(win, mnu[17].r, mnu[17].c, mnu[17].t);
		mvwaddstr(win, mnu[18].r, mnu[18].c, mnu[18].t);
		mvwaddstr(win, mnu[19].r, mnu[19].c, mnu[19].t);
		mvwaddstr(win, mnu[20].r, mnu[20].c, mnu[20].t);
		mvwaddstr(win, mnu[21].r, mnu[21].c, mnu[21].t);
		mvwaddstr(win, mnu[22].r, mnu[22].c, mnu[22].t);
		mvwaddstr(win, mnu[23].r, mnu[23].c, mnu[23].t);
		mvwaddstr(win, mnu[24].r, mnu[24].c, mnu[24].t);
		mvwaddstr(win, mnu[25].r, mnu[25].c, mnu[25].t);
		mvwaddstr(win, mnu[26].r, mnu[26].c, mnu[26].t);
		mvwaddstr(win, mnu[27].r, mnu[27].c, mnu[27].t);
		mvwaddstr(win, mnu[28].r, mnu[28].c, mnu[28].t);
		mvwaddstr(win, mnu[29].r, mnu[29].c, mnu[29].t);
		mvwaddstr(win, mnu[30].r, mnu[30].c, mnu[30].t);
		mvwaddstr(win, mnu[31].r, mnu[31].c, mnu[31].t);
		mvwaddstr(win, mnu[32].r, mnu[32].c, mnu[32].t);
		mvwaddstr(win, mnu[33].r, mnu[33].c, mnu[33].t);
		mvwaddstr(win, mnu[34].r, mnu[34].c, mnu[34].t);
		mvwaddstr(win, mnu[35].r, mnu[35].c, mnu[35].t);
		mvwaddstr(win, mnu[36].r, mnu[36].c, mnu[36].t);
		mvwaddstr(win, mnu[37].r, mnu[37].c, mnu[37].t);
		mvwaddstr(win, mnu[38].r, mnu[38].c, mnu[38].t);
		mvwaddstr(win, mnu[39].r, mnu[39].c, mnu[39].t);
		mvwaddstr(win, mnu[40].r, mnu[40].c, mnu[40].t);
		mvwaddstr(win, mnu[0].r, mnu[0].c, mnu[0].t);
		wrefresh(win);

		sw =	alx_menu(len, mnu, win);

		wclear(win);
		wrefresh(win);
		delwin(win);

		switch (sw) {
		case TST_END:
			wh = false;
			break;

		case TST_BINOMIAL_P:
			alx_pause_curses();
			binomial_P();
			alx_resume_curses();
			break;
		case TST_BINOMIAL_E:
			alx_pause_curses();
			binomial_E();
			alx_resume_curses();
			break;
		case TST_BINOMIAL_Var:
			alx_pause_curses();
			binomial_Var();
			alx_resume_curses();
			break;

		case TST_POISSON_P:
			alx_pause_curses();
			poisson_P();
			alx_resume_curses();
			break;
		case TST_POISSON_E:
			alx_pause_curses();
			poisson_E();
			alx_resume_curses();
			break;
		case TST_POISSON_Var:
			alx_pause_curses();
			poisson_Var();
			alx_resume_curses();
			break;

		case TST_GEOMETRIC_P:
			alx_pause_curses();
			print_license();
			alx_resume_curses();
			break;
		case TST_GEOMETRIC_E:
			alx_pause_curses();
			dist_binomial_help();
			alx_resume_curses();
			break;
		case TST_GEOMETRIC_Var:
			alx_pause_curses();
			dist_poisson_help();
			alx_resume_curses();
			break;

		case TST_UNIFORM_P:
			alx_pause_curses();
			dist_geometric_help();
			alx_resume_curses();
			break;
		case TST_UNIFORM_E:
			alx_pause_curses();
			dist_hypergeometric_help();
			alx_resume_curses();
			break;
		case TST_UNIFORM_Var:
			alx_pause_curses();
			dist_uniform_help();
			alx_resume_curses();
			break;

		case TST_EXPONENTIAL_P:
			alx_pause_curses();
			dist_exponential_help();
			alx_resume_curses();
			break;
		case TST_EXPONENTIAL_E:
			alx_pause_curses();
			print_usage();
			alx_resume_curses();
			break;
		case TST_EXPONENTIAL_Var:
			alx_pause_curses();
			print_cpright();
			alx_resume_curses();
			break;

		case TST_NORMAL_O:
			alx_pause_curses();
			print_disclaim();
			alx_resume_curses();
			break;
		case TST_NORMAL_A:
			alx_pause_curses();
			print_license();
			alx_resume_curses();
			break;
		case TST_NORMAL_B:
			alx_pause_curses();
			dist_binomial_help();
			alx_resume_curses();
			break;
		case TST_NORMAL_Z:
			alx_pause_curses();
			dist_poisson_help();
			alx_resume_curses();
			break;
		case TST_NORMAL_X:
			alx_pause_curses();
			dist_geometric_help();
			alx_resume_curses();
			break;

		case TST_DESCRIP_U:
			alx_pause_curses();
			dist_hypergeometric_help();
			alx_resume_curses();
			break;
		case TST_DESCRIP_O2:
			alx_pause_curses();
			dist_uniform_help();
			alx_resume_curses();
			break;
		case TST_DESCRIP_O:
			alx_pause_curses();
			dist_exponential_help();
			alx_resume_curses();
			break;
		case TST_DESCRIP_S2:
			alx_pause_curses();
			print_usage();
			alx_resume_curses();
			break;
		case TST_DESCRIP_S:
			alx_pause_curses();
			print_cpright();
			alx_resume_curses();
			break;
		case TST_DESCRIP_CV:
			alx_pause_curses();
			print_disclaim();
			alx_resume_curses();
			break;

		case TST_DESCRIP_OXY:
			alx_pause_curses();
			print_license();
			alx_resume_curses();
			break;
		case TST_DESCRIP_A:
			alx_pause_curses();
			dist_binomial_help();
			alx_resume_curses();
			break;
		case TST_DESCRIP_B:
			alx_pause_curses();
			dist_poisson_help();
			alx_resume_curses();
			break;
		case TST_DESCRIP_R:
			alx_pause_curses();
			dist_geometric_help();
			alx_resume_curses();
			break;
		case TST_DESCRIP_EIYI2:
			alx_pause_curses();
			dist_hypergeometric_help();
			alx_resume_curses();
			break;

		case TST_DESCRIP_AA:
			alx_pause_curses();
			dist_uniform_help();
			alx_resume_curses();
			break;
		case TST_DESCRIP_AB:
			alx_pause_curses();
			dist_exponential_help();
			alx_resume_curses();
			break;
		case TST_DESCRIP_VR:
			alx_pause_curses();
			dist_uniform_help();
			alx_resume_curses();
			break;
		case TST_DESCRIP_R2:
			alx_pause_curses();
			dist_exponential_help();
			alx_resume_curses();
			break;
		}
	}
	endwin();

	return	0;
}
