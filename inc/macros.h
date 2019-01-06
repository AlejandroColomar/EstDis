/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 ******************************************************************************/

# ifndef			MACROS
	# define		MACROS

	# define		DBG	true
	# define		DBG_th	thr_num
	# if (DBG)
	# 	define		DBG_PRINT(x, y, z)	print_verbose(x, y, z)
	# else
	# 	define		DBG_PRINT(x, y, z)	do {} while (0)
	# endif

# endif				/* macros.h */
