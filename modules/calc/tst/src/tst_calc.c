/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 ******************************************************************************/

	#include <curses.h>
	#include <stdbool.h>
	#include <stdint.h>
	#include <stdio.h>

	#include "alx_ncur.h"

	#include "calc.h"


	# define	XXX_n		1
	# define	XXX_p		0.5
	# define	XXX_x		1
	# define	XXX_l		1
	# define	XXX_a		0
	# define	XXX_b		1
	# define	XXX_x1		0.25
	# define	XXX_x2		0.75
	# define	XXX_o2		1
	# define	XXX_o		1
	# define	XXX_u		1
	# define	XXX_z		1
	# define	XXX_ni		1
	# define	XXX_xi		1
	# define	XXX_yi		1
	# define	XXX_Exi		1
	# define	XXX_Eni		1
	# define	XXX_Exi2	1
	# define	XXX_s2		1
	# define	XXX_Exiyi	1
	# define	XXX_ux		1
	# define	XXX_uy		1
	# define	XXX_ox2		1
	# define	XXX_oxy		1
	# define	XXX_ox		1
	# define	XXX_oy		1
	# define	XXX_Eyiy2	1
	# define	XXX_Aa		1
	# define	XXX_oy2		1
	# define	XXX_Vr		1


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

		TST_DESCRIP_Eni,
		TST_DESCRIP_Exi,
		TST_DESCRIP_Exi2,
		TST_DESCRIP_Exiyi,

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
	int64_t	h =	35;
	int64_t	w =	34;
	int64_t	r =	1;
	int64_t	c =	(80 - w) / 2;

	int64_t		N = TST_FUNCTIONS;
	struct alx_optn	mnu[TST_FUNCTIONS] =	{
		{32, 4, "[0]  END TEST"},

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
		{40, 4, "[39] descrip_R2"}
	};

	wh = true;
	while (wh) {
		sw =	alx_menu(h, w, N, mnu, "TEST:");

		switch (sw) {
		case TST_END:
			wh = false;
			break;

		case TST_BINOMIAL_P:
			alx_pause_curses();
			binomial_P(XXX_n, XXX_p, XXX_x);
			alx_resume_curses();
			break;
		case TST_BINOMIAL_E:
			alx_pause_curses();
			binomial_E(XXX_n, XXX_p);
			alx_resume_curses();
			break;
		case TST_BINOMIAL_Var:
			alx_pause_curses();
			binomial_Var(XXX_n, XXX_p);
			alx_resume_curses();
			break;

		case TST_POISSON_P:
			alx_pause_curses();
			poisson_P(XXX_l, XXX_x);
			alx_resume_curses();
			break;
		case TST_POISSON_E:
			alx_pause_curses();
			poisson_E(XXX_l);
			alx_resume_curses();
			break;
		case TST_POISSON_Var:
			alx_pause_curses();
			poisson_Var(XXX_l);
			alx_resume_curses();
			break;

		case TST_GEOMETRIC_P:
			alx_pause_curses();
			geometric_P(XXX_p, XXX_x);
			alx_resume_curses();
			break;
		case TST_GEOMETRIC_E:
			alx_pause_curses();
			geometric_E(XXX_p);
			alx_resume_curses();
			break;
		case TST_GEOMETRIC_Var:
			alx_pause_curses();
			geometric_Var(XXX_p);
			alx_resume_curses();
			break;

		case TST_UNIFORM_P:
			alx_pause_curses();
			uniform_P(XXX_a, XXX_b, XXX_x1, XXX_x2);
			alx_resume_curses();
			break;
		case TST_UNIFORM_E:
			alx_pause_curses();
			uniform_E(XXX_a, XXX_b);
			alx_resume_curses();
			break;
		case TST_UNIFORM_Var:
			alx_pause_curses();
			uniform_Var(XXX_a, XXX_b);
			alx_resume_curses();
			break;

		case TST_EXPONENTIAL_P:
			alx_pause_curses();
			exponential_P(XXX_b, XXX_x1, XXX_x2);
			alx_resume_curses();
			break;
		case TST_EXPONENTIAL_E:
			alx_pause_curses();
			exponential_E(XXX_b);
			alx_resume_curses();
			break;
		case TST_EXPONENTIAL_Var:
			alx_pause_curses();
			exponential_Var(XXX_b);
			alx_resume_curses();
			break;

		case TST_NORMAL_O:
			alx_pause_curses();
			normal_o(XXX_o2);
			alx_resume_curses();
			break;
		case TST_NORMAL_A:
			alx_pause_curses();
			normal_A(XXX_o);
			alx_resume_curses();
			break;
		case TST_NORMAL_B:
			alx_pause_curses();
			normal_B(XXX_u, XXX_o);
			alx_resume_curses();
			break;
		case TST_NORMAL_Z:
			alx_pause_curses();
			normal_Z(XXX_a, XXX_b, XXX_x);
			alx_resume_curses();
			break;
		case TST_NORMAL_X:
			alx_pause_curses();
			normal_X(XXX_a, XXX_b, XXX_z);
			alx_resume_curses();
			break;

		case TST_DESCRIP_Eni:
			alx_pause_curses();
			descrip_Eni(XXX_ni);
			alx_resume_curses();
			break;
		case TST_DESCRIP_Exi:
			alx_pause_curses();
			descrip_Exi(XXX_ni, XXX_xi);
			alx_resume_curses();
			break;
		case TST_DESCRIP_Exi2:
			alx_pause_curses();
			descrip_Exi2(XXX_ni, XXX_xi);
			alx_resume_curses();
			break;
		case TST_DESCRIP_Exiyi:
			alx_pause_curses();
			descrip_Exiyi(XXX_xi, XXX_yi);
			alx_resume_curses();
			break;

		case TST_DESCRIP_U:
			alx_pause_curses();
			descrip_u(XXX_Exi, XXX_Eni);
			alx_resume_curses();
			break;
		case TST_DESCRIP_O2:
			alx_pause_curses();
			descrip_o2(XXX_Exi2, XXX_Eni, XXX_u);
			alx_resume_curses();
			break;
		case TST_DESCRIP_O:
			alx_pause_curses();
			descrip_o(XXX_o2);
			alx_resume_curses();
			break;
		case TST_DESCRIP_S2:
			alx_pause_curses();
			descrip_s2(XXX_o2, XXX_Eni);
			alx_resume_curses();
			break;
		case TST_DESCRIP_S:
			alx_pause_curses();
			descrip_s(XXX_s2);
			alx_resume_curses();
			break;
		case TST_DESCRIP_CV:
			alx_pause_curses();
			descrip_CV(XXX_o, XXX_u);
			alx_resume_curses();
			break;

		case TST_DESCRIP_OXY:
			alx_pause_curses();
			descrip_oxy(XXX_n, XXX_Exiyi, XXX_ux, XXX_uy);
			alx_resume_curses();
			break;
		case TST_DESCRIP_A:
			alx_pause_curses();
			descrip_a(XXX_ox2, XXX_oxy);
			alx_resume_curses();
			break;
		case TST_DESCRIP_B:
			alx_pause_curses();
			descrip_b(XXX_ux, XXX_uy, XXX_a);
			alx_resume_curses();
			break;
		case TST_DESCRIP_R:
			alx_pause_curses();
			descrip_r(XXX_ox, XXX_oy, XXX_oxy);
			alx_resume_curses();
			break;
		case TST_DESCRIP_EIYI2:
			alx_pause_curses();
			descrip_Eyiy2(XXX_xi, XXX_yi, XXX_a, XXX_b);
			alx_resume_curses();
			break;

		case TST_DESCRIP_AA:
			alx_pause_curses();
			descrip_Aa(XXX_n, XXX_Exi, XXX_Exi2, XXX_Eyiy2);
			alx_resume_curses();
			break;
		case TST_DESCRIP_AB:
			alx_pause_curses();
			descrip_Ab(XXX_n, XXX_Exi2, XXX_Aa);
			alx_resume_curses();
			break;
		case TST_DESCRIP_VR:
			alx_pause_curses();
			descrip_Vr(XXX_n, XXX_Eyiy2);
			alx_resume_curses();
			break;
		case TST_DESCRIP_R2:
			alx_pause_curses();
			descrip_R2(XXX_oy2, XXX_Vr);
			alx_resume_curses();
			break;
		}
	}
	alx_end_curses();

	return	0;
}
