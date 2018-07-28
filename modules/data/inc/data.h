/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 ******************************************************************************/

# ifndef		DATA_H
	# define	DATA_H

	#include <stdint.h>
	#include <stdbool.h>


	extern	int64_t		flag_s;
	extern	int64_t		flag_r;
	extern	int64_t		flag_V;
	extern	bool		flag_x;


	extern	int64_t		param_i_a;
	# define		PARAM_i_a_MIN		(0)
	# define		PARAM_i_a_DEF		(0)
	# define		PARAM_i_a_MAX		(param_i_N)
	extern	int64_t		param_i_b;
	# define		PARAM_i_b_MIN		(param_i_a)
	# define		PARAM_i_b_DEF		(param_i_N)
	# define		PARAM_i_b_MAX		(param_i_N)
	extern	int64_t		param_i_c;
	# define		PARAM_i_c_MIN		(0)
	# define		PARAM_i_c_DEF		(1)
	# define		PARAM_i_c_MAX		(65536)
	extern	int64_t		param_i_n;
	# define		PARAM_i_n_MIN		(1)
	# define		PARAM_i_n_DEF		(1)
	# define		PARAM_i_n_MAX		(65536)
	extern	int64_t		param_i_N;
	# define		PARAM_i_N_MIN		(1)
	# define		PARAM_i_N_DEF		(2)
	# define		PARAM_i_N_MAX		(65536)
	extern	int64_t		param_i_r;
	extern	int64_t		param_i_x [65536];
	# define		PARAM_i_x_MIN		(0)
	# define		PARAM_i_x_DEF		(1)
	# define		PARAM_i_x_MAX		(param_i_N)

	extern	double		param_a;
	# define		PARAM_a_MIN		(-INFINITY)
	# define		PARAM_a_DEF		(0)
	# define		PARAM_a_MAX		(INFINITY)
	extern	double		param_b;
	# define		PARAM_b_MIN		(param_a)
	# define		PARAM_b_DEF		(param_a + 1)
	# define		PARAM_b_MAX		(INFINITY)
	extern	double		param_p;
	# define		PARAM_p_MIN		(0)
	# define		PARAM_p_DEF		(0.5)
	# define		PARAM_p_MAX		(1)
	extern	double		param_x_dbl [65536];
	# define		PARAM_x_MIN		(-INFINITY)
	# define		PARAM_x_DEF		(1)
	# define		PARAM_x_MAX		(INFINITY)
				/* param_y also used as n (when n is dbl) */
	extern	double		param_y [65536];
	# define		PARAM_n_MIN		(0)
	# define		PARAM_n_DEF		(1)
	# define		PARAM_n_MAX		(INFINITY)
	# define		PARAM_y_MIN		(-INFINITY)
	# define		PARAM_y_DEF		(1)
	# define		PARAM_y_MAX		(INFINITY)
	extern	double		param_beta;
	# define		PARAM_beta_MIN		(0)
	# define		PARAM_beta_DEF		(1)
	# define		PARAM_beta_MAX		(INFINITY)
	extern	double		param_lambda;
	# define		PARAM_lambda_MIN	(0)
	# define		PARAM_lambda_DEF	(1)
	# define		PARAM_lambda_MAX	(INFINITY)
	extern	double		param_mu;
	# define		PARAM_mu_MIN		(-INFINITY)
	# define		PARAM_mu_DEF		(0)
	# define		PARAM_mu_MAX		(INFINITY)
	extern	double		param_sigma2;
	# define		PARAM_sigma2_MIN	(0)
	# define		PARAM_sigma2_DEF	(1)
	# define		PARAM_sigma2_MAX	(INFINITY)
	extern	double		param_X;
	# define		PARAM_X_MIN		(-INFINITY)
	# define		PARAM_X_DEF		(0)
	# define		PARAM_X_MAX		(INFINITY)
	extern	double		param_Z;
	# define		PARAM_Z_MIN		(-INFINITY)
	# define		PARAM_Z_DEF		(0)
	# define		PARAM_Z_MAX		(INFINITY)

	extern	double		result_P;
	extern	double		result_E;
	extern	double		result_Var;

	enum	Level_Verbose {
		VERBOSE_0 = 0,
		VERBOSE_1,
		VERBOSE_2,
		VERBOSE_3,
		VERBOSE_MAX
	};

	enum	Start_Switch {
		START_FOO = 0,
		START_DESC_1VAR,
		START_DESC_2VAR,
		START_BINOMIAL,
		START_POISSON,
		START_GEOMETRIC,
		START_HYPERGEOMETRIC,
		START_UNIFORM,
		START_EXPONENTIAL,
		START_NORMAL,
		START_COUNT
	};

	enum	Help_Switch {
		HELP_GENERIC = 0,
		HELP_DESC_1VAR,
		HELP_DESC_2VAR,
		HELP_BINOMIAL,
		HELP_POISSON,
		HELP_GEOMETRIC,
		HELP_HYPERGEOMETRIC,
		HELP_UNIFORM,
		HELP_EXPONENTIAL,
		HELP_NORMAL,
		HELP_MAX
	};

# endif			/* data.h */
