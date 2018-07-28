/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 ******************************************************************************/


/******************************************************************************
 ******| include |*************************************************************
 ******************************************************************************/
		/* curses interface */
	#include <ncurses.h>
		/* bool */
	#include <stdbool.h>
		/* int64_t */
	#include <stdint.h>

		/* menu & curses */
	#include "alx_ncur.h"

		/* print functions */
	#include "about.h"
		/* variables */
	#include "data.h"
		/* start */
	#include "start.h"

		/* DBG */
	#include "macros.h"

	#include "menus.h"


/******************************************************************************
 ******| menu |****************************************************************
 ******************************************************************************/
	/*
	 * + Menu:
	 *	+ Continue:
	 *		- Run
	 *		- Help
	 *		+ Select:
	 *			- 1 Var
	 *			- 2 Var
	 *			- Binomial
	 *			- Poisson
	 *			- Geometrica
	 *			- Hipergeometrica
	 *			- Uniforme
	 *			- Exponencial
	 *			- Gauss(Normal)
	 *			- ..
	 *		+ Verbose: Not yet
	 *			- ..
	 *		- ..
	 *	- Copyright
	 *	- Disclaimer
	 *	- Terms & conditions
	 *	- Exit program
	 */


/******************************************************************************
 ******| submenus |************************************************************
 ******************************************************************************/
static	void	menu_continue	(void);
static	void	menu_select	(void);
static	void	menu_verbose	(void);


/******************************************************************************
 ******| main menu |***********************************************************
 ******************************************************************************/
void	menu_main		(void)
{
	int	sw;
	bool	wh;
	WINDOW	*win;
	int	h =	11;
	int	w =	34;

	int		N = 5;
	struct alx_optn	mnu[5] =	{
		{8, 4, "[0]	Exit program"},
		{2, 4, "[1]	Continue"},
		{4, 4, "[2]	Copyright"},
		{5, 4, "[3]	Disclaimer of warranty"},
		{6, 4, "[4]	Terms & conditions"}
	};

	wh = true;
	while (wh) {
		sw =	alx_menu(h, w, N, mnu, "MENU:");

		switch (sw) {
		case 0:
			wh = false;
			break;

		case 1:
			menu_continue();
			break;

		case 2:
			alx_pause_curses();
			print_cpright();
			alx_resume_curses();
			break;

		case 3:
			alx_pause_curses();
			print_disclaim();
			alx_resume_curses();
			break;

		case 4:
			alx_pause_curses();
			print_license();
			alx_resume_curses();
			break;
		}
	}
}


/******************************************************************************
 ******| submenus |************************************************************
 ******************************************************************************/
static	void	menu_continue	(void)
{
	int	sw;
	bool	wh;
	WINDOW	*win;
	int	h =	10;
	int	w =	35;

	int		N = 5;
	struct alx_optn	mnu[5] =	{
		{7, 4, "[0]	Back"},
		{2, 4, "[1]	Run"},
		{3, 4, "[2]	Help"},
		{4, 4, "[3]	Select problem type"},
		{5, 4, "[4]	Change verbose"}
	};

	wh = true;
	while (wh) {
		sw =	alx_menu(h, w, N, mnu, "CONTINUE:");

		switch (sw) {
		case 0:
			wh = false;
			break;

		case 1:
			alx_pause_curses();
			start_switch();
			alx_resume_curses();
			break;

		case 2:
			alx_pause_curses();
			help_switch();
			alx_resume_curses();
			break;

		case 3:
			menu_select();
			break;

		case 4:
			menu_verbose();
			break;
		}
	}
}

static	void	menu_select	(void)
{
	int	buff;
	WINDOW	*win;
	int	h =	16;
	int	w =	50;

	int		N = 10;
	struct alx_optn	mnu[10] =	{
		{13, 4, "[0]	Back"},
		{2, 4, "[1]	1 Variable"},
		{3, 4, "[2]	2 Variables"},
		{5, 4, "[3]	Binomial"},
		{6, 4, "[4]	Poisson"},
		{7, 4, "[5]	Geometrica"},
		{8, 4, "[6]	Hipergeometrica"},
		{9, 4, "[7]	Uniforme"},
		{10, 4, "[8]	Exponencial"},
		{11, 4, "[9]	Gauss(Normal)"}
	};

	buff =	alx_menu(h, w, N, mnu, "SELECT:");

	if (buff) {
		flag_s =	buff;
	}
}

static	void	menu_verbose	(void)
{
	int	h =	10;
	int	w =	51;

	int		N = 5;
	struct alx_optn	mnu[5] =	{
		{7, 4, "[0]	Show NOTHING"},
		{2, 4, "[1]	Show only solution"},
		{3, 4, "[2]	Show short help"},
		{4, 4, "[3]	Show help"},
# if (DBG)
		{5, 4, "[4]	Show everything  (DBG)"}
# else
		{5, 4, "[4]	DBG (Not active)"}
# endif
	};

	flag_V =	alx_menu(h, w, N, mnu, "VERBOSE:");
}
