/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 ******************************************************************************/

# ifndef		MENU_H
	# define	MENU_H


/******************************************************************************
 ******* variables ************************************************************
 ******************************************************************************/
	extern	bool	flag_exit;
	extern	int	flag_verbose;
	extern	int	menu_iface_mode;


/******************************************************************************
 ******* enums ****************************************************************
 ******************************************************************************/
	enum	Level_Verbose {
		VERBOSE_0 = 0,
		VERBOSE_1,
		VERBOSE_2,
		VERBOSE_3,
		VERBOSE_MAX
	};

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
	 *	- Disclaimer
	 *	- Terms & conditions
	 *	- Exit program
	 */
/*----------------------------------------------------------------------------*/

void	menu_main	(void);

# endif			/* menu.h */
