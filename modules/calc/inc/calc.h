/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
# ifndef		CALC_H
	# define	CALC_H


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
/* Standard C ----------------------------------------------------------------*/
		/* INFINITY */
	#include <math.h>


/******************************************************************************
 ******* variables ************************************************************
 ******************************************************************************/
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
#if 0
extern	double		result_P;
extern	double		result_E;
extern	double		result_Var;
#endif

/******************************************************************************
 ******* functions ************************************************************
 ******************************************************************************/
// distributions:
	// Binomial dist.	X -> B(n, p)
double	binomial_P	(double n, double p, double x);
double	binomial_E	(double n, double p);
double	binomial_Var	(double n, double p);

	// Poisson dist.	X -> P(l)
double	poisson_P	(double l, double x);
double	poisson_E	(double l);
double	poisson_Var	(double l);

	// Geometric dist.	X -> G(p)
double	geometric_P	(double p, double x);
double	geometric_E	(double p);
double	geometric_Var	(double p);

	// Uniform dist.	X -> U(a, b)
double	uniform_P	(double a, double b, double x1, double x2);
double	uniform_E	(double a, double b);
double	uniform_Var	(double a, double b);

	// Exponential dist.	X -> exp(b)
double	exponential_P	(double b, double x1, double x2);
double	exponential_E	(double b);
double	exponential_Var	(double b);

	// Normal (Gauss) dist.	X -> N(u, o2);	Z -> N(0, 1)
double	normal_o	(double o2);
double	normal_A	(double o);
double	normal_B	(double u, double o);
double	normal_Z	(double a, double b, double x);
double	normal_X	(double a, double b, double z);

// descriptive statistics:
double	descrip_Eni	(double ni);
double	descrip_Exi	(double ni, double xi);
double	descrip_Exi2	(double ni, double xi);
double	descrip_Exiyi	(double xi, double yi);

double	descrip_u	(double Exi, double Eni);
double	descrip_o2	(double Exi2, double Eni, double u);
double	descrip_o	(double o2);
double	descrip_s2	(double o2, double Eni);
double	descrip_s	(double s2);
double	descrip_CV	(double o, double u);

double	descrip_oxy	(double n, double Exiyi, double ux, double uy);
double	descrip_a	(double ox2, double oxy);
double	descrip_b	(double ux, double uy, double a);
double	descrip_r	(double ox, double oy, double oxy);
double	descrip_Eyiy2	(double xi, double yi, double a, double b);

double	descrip_Aa	(double n, double Exi, double Exi2, double Eyiy2);
double	descrip_Ab	(double n, double Exi2, double Aa);
double	descrip_Vr	(double n, double Eyiy2);
double	descrip_R2	(double oy2, double Vr);


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
# endif			/* calc.h */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
