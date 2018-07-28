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

	# define		PROG_NAME	"EstDis"
	# define		PROG_YEAR	"2015"
	# define		PROG_VERS	"2.0"

	# define		ESTDIS_PATH	"./"
	# define		LICENSE_RPATH	"../COPYING.txt"

	# define		CORES_MAX	1
	# define		THREADS_MAX	(2 * CORES_MAX - 1)

# endif				/* macros.h */
