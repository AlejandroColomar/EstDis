/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 ******************************************************************************/

		/* int64_t & PRNi64 */
	#include <inttypes.h>
		/* printf() */
	#include <stdio.h>

		/* alx_getint() & alx_getdbl() */
	#include "alx_input.h"

		/* calculations */
	#include "calc.h"

	#include "dist.h"



//------------------------------------------------------------------------------
/*--| suboptions |------------------------------------------------------------*/
//------------------------------------------------------------------------------
static	void	dist_normal_m		(double a, double b);
static	void	dist_normal_m_1		(double a, double b);
static	void	dist_normal_m_2		(double a, double b);
static	double	dist_binomial_P		(void);
static	double	dist_poisson_P		(void);
static	double	dist_geometric_P	(void);



//------------------------------------------------------------------------------
//--| descriptive statistics |--------------------------------------------------
//------------------------------------------------------------------------------

void	desc_1var		(void)
{
	int64_t	i;
	double	Eni = 0;
	double	Exi = 0;
	double	Exi2 = 0;
	double	u;
	double	o2;
	double	o;
	double	s2;
	double	s;
	double	CV;

	printf("\n________________________________________________________________________________\n");
	printf("u\t= E(ni*xi)/n\t--Media.\n");
	printf("o2\t= E(xi^2)/n-u^2\t--Varianza.\n");
	printf("s2\t= o2*n/(n-1)\t--Cuasivarianza.\n");
	printf("o\t= sqrt(o2)\t--Desviacion tipica.\n");
	printf("s\t= sqrt(s2)\t--Cuasidesviacion tipica.\n");
	printf("CV\t= o/u\t\t--Coeficiente de variacion.\n\n");

	param_i_N	= alx_getint(PARAM_i_N_MIN, PARAM_i_N_DEF, PARAM_i_N_MAX,
							"N:\t", NULL);

	/* here param_y is used as n */
	for (i = 0; i < param_i_N; i++) {
		printf("x_%"PRIi64":\t", i);
		param_x_dbl[i]	= alx_getdbl(PARAM_x_MIN, PARAM_x_DEF, PARAM_x_MAX,
							NULL, NULL);
		printf("n_%"PRIi64":\t", i);
		param_y[i]	= alx_getdbl(PARAM_n_MIN, PARAM_n_DEF, PARAM_n_MAX,
							NULL, NULL);
		printf("\n");
	}

	/* here param_y is used as n */
	for (i = 0; i < param_i_N; i++) {
		Exi +=	descrip_Exi(param_y[i], param_x_dbl[i]);
		Exi2 +=	descrip_Exi2(param_y[i], param_x_dbl[i]);
		Eni +=	descrip_Eni(param_y[i]);
	}

	u	= descrip_u(Exi, Eni);
	o2	= descrip_o2(Exi2, Eni, u);
	o	= descrip_o(o2);
	s2	= descrip_s2(o2, Eni);
	s	= descrip_s(s2);
	CV	= descrip_CV(o, u);

	printf("\nu\t= %lf", u);
	printf("\no2\t= %lf", o2);
	printf("\no\t= %lf", o);
	printf("\ns2\t= %lf", s2);
	printf("\ns\t= %lf", s);
	printf("\nCV\t= %lf\n", CV);
}

void	desc_2var		(void)
{
	int64_t	i;
	double	Exi = 0;
	double	Exi2 = 0;
	double	ux;
	double	ox2;
	double	ox;
	double	a;
	double	Aa;
	double	b;
	double	Ab;
	double	Eyi = 0;
	double	Eyi2 = 0;
	double	uy;
	double	oy2;
	double	oy;
	double	c;
	double	Ac;
	double	d;
	double	Ad;
	double	Exiyi = 0;
	double	oxy;
	double	r;
	double	Eyiy2 = 0;
	double	Exix2 = 0;
	double	Vr;
	double	R2;

	printf("\n________________________________________________________________________________\n");
	printf("u\t= E(xi)/n\t\t--Media.\n");
	printf("o2\t= E(xi^2)/n-u^2\t\t--Varianza.\n");
	printf("o\t= sqrt(o2)\t\t--Desviacion tipica.\n");
	printf("oxy\t= E(xi*yi)/n-ux*uy\t--Covarianza.\n\n");

	printf("a\t= oxy/ox2\t\t--Pendiente.\n");
	printf("b\t= uy-a*ux\t\t--Sesgo.\n");
	printf("r\t= oxy/(ox*oy)\t\t--Coeficiente de correlacion lineal.\n\n");

	printf("n\t=\t\t\t--Numero de puntos.\n\n");

	param_i_N	= alx_getint(PARAM_i_N_MIN, PARAM_i_N_DEF, PARAM_i_N_MAX,
							"n:\t", NULL);

	for (i = 0; i < param_i_N; i++) {
		printf("x_%"PRIi64":\t", i);
		param_x_dbl[i]	= alx_getdbl(PARAM_x_MIN, PARAM_x_DEF, PARAM_x_MAX,
							NULL, NULL);
		printf("y_%"PRIi64":\t", i);
		param_y[i]	= alx_getdbl(PARAM_y_MIN, PARAM_y_DEF, PARAM_y_MAX,
							NULL, NULL);
		printf("\n");
	}

	for (i = 0; i < param_i_N; i++) {
		Exi	+= descrip_Exi(1, param_x_dbl[i]);
		Exi2	+= descrip_Exi2(1, param_x_dbl[i]);
		Eyi	+= descrip_Exi(1, param_y[i]);
		Eyi2	+= descrip_Exi2(1, param_y[i]);
		Exiyi	+= descrip_Exiyi(param_x_dbl[i], param_y[i]);
	}

	ux	= descrip_u(Exi, param_i_N);
	ox2	= descrip_o2(Exi2, param_i_N, ux);
	ox	= descrip_o(ox2);

	uy	= descrip_u(Eyi, param_i_N);
	oy2	= descrip_o2(Eyi2, param_i_N, uy);
	oy	= descrip_o(oy2);

	oxy	= descrip_oxy(Exiyi, param_i_N, ux, uy);
	a	= descrip_a(oxy, ox2);
	b	= descrip_b(ux, uy, a);
	c	= descrip_a(oxy, oy2);
	d	= descrip_b(uy, ux, c);
	r	= descrip_r(oxy, ox, oy);

	for (i = 0; i < param_i_N; i++) {
		Eyiy2	+= descrip_Eyiy2(param_x_dbl[i], param_y[i], a, b);
		Exix2	+= descrip_Eyiy2(param_y[i], param_x_dbl[i], c, d);
	}

	Aa	= descrip_Aa(param_i_N, Exi, Exi2, Eyiy2);
	Ab	= descrip_Ab(param_i_N, Exi2, Aa);
	Ac	= descrip_Aa(param_i_N, Eyi, Eyi2, Exix2);
	Ad	= descrip_Ab(param_i_N, Eyi2, Ac);

	Vr	= descrip_Vr(param_i_N, Eyiy2);
	R2	= descrip_R2(oy2, Vr);

	printf("\nux\t= %lf", ux);
	printf("\nox2\t= %lf", ox2);
	printf("\nox\t= %lf\n", ox);
	printf("\nuy\t= %lf", uy);
	printf("\noy2\t= %lf", oy2);
	printf("\noy\t= %lf\n", oy);
	printf("\noxy\t= %lf", oxy);
	printf("\na\t= %lf", a);
	printf("\nAa\t= %lf", Aa);
	printf("\nb\t= %lf", b);
	printf("\nAb\t= %lf", Ab);
	printf("\nc\t= %lf", c);
	printf("\nAc\t= %lf", Ac);
	printf("\nd\t= %lf", d);
	printf("\nAd\t= %lf", Ad);
	printf("\nr\t= %lf", r);
	printf("\nVr\t= %lf", Vr);
	printf("\nR2\t= %lf\n", R2);
}



//------------------------------------------------------------------------------
//--| distributions |-----------------------------------------------------------
//------------------------------------------------------------------------------

void	dist_binomial		(void)
{
	double	P;
	double	E;
	double	Var;

	printf("\n________________________________________________________________________________\n");
	printf("\nESTADISTICA/Distribuciones:\tDistribucion Binomial: B(n,p)\n\n");

	printf("n = numero de veces que se repite el experimento (con reemplazamiento)\n");
	printf("p = probabilidad del suceso individual\n");
	printf("x = numero de veces que interesa que ocurra el suceso\n");
	printf("c = cantidad de x que interesan (inroducir [0] para intervalo [a U b])\n\n");

	param_i_N	= alx_getint(PARAM_i_N_MIN, PARAM_i_N_DEF, PARAM_i_N_MAX,
							"n:\t", NULL);
	param_p		= alx_getdbl(PARAM_p_MIN, PARAM_p_DEF, PARAM_p_MAX,
							"p:\t", NULL);
	param_i_c	= alx_getint(PARAM_i_c_MIN, PARAM_i_c_DEF, param_i_N + 1,
							"c:\t", NULL);

	P	= dist_binomial_P();
	E	= binomial_E(param_i_N, param_p);
	Var	= binomial_Var(param_i_N, param_p);

	printf("\nP{X}\t= %lf", P);
	printf("\nE(X)\t= %lf", E);
	printf("\nVar(X)\t= %lf\n", Var);

	if ((param_i_N*param_p > 5) && (param_i_N*(1-param_p) > 5)) {
		printf("\nAproximacion a Distribucion Normal N(u = np, o2 = np(1-p))");
		printf("\nu\t= %lf", E);
		printf("\no2\t= %lf\n", Var);
	}
}

void	dist_poisson		(void)
{
	double	P;
	double	E;
	double	Var;

	printf("\n________________________________________________________________________________\n");
	printf("\nESTADISTICA/Distribuciones:\tDistribucion de Poisson: P(lambda)\n\n");

	printf("lambda = veces que ocurre de media/ud. de tiempo\n");
	printf("x = veces que interesa que ocurra X/ud. de tiempo\n");
	printf("c = cantidad de x que interesan (inroducir [0] para intervalo [a U b])\n\n");

	param_i_N	= PARAM_i_N_MAX;
	param_lambda	= alx_getdbl(PARAM_lambda_MIN, PARAM_lambda_DEF, PARAM_lambda_MAX,
							"l:\t", NULL);
	param_i_c	= alx_getint(PARAM_i_c_MIN, PARAM_i_c_DEF, PARAM_i_c_MAX,
							"c:\t", NULL);

	P	= dist_poisson_P();
	E	= poisson_E(param_lambda);
	Var	= poisson_Var(param_lambda);

	printf("\nP{X}\t= %lf", P);
	printf("\nE(X)\t= %lf", E);
	printf("\nVar(X)\t= %lf\n", Var);
}

void	dist_geometric		(void)
{
	double	P;
	double	E;
	double	Var;

	printf("\n________________________________________________________________________________\n");
	printf("\nESTADISTICA/Distribuciones:\tDistribucion Geometrica: G(p)\n\n");

	printf("p = probabilidad del suceso en cada repeticion\n");
	printf("x = vez que interesa que ocurra el suceso\n\n");

	param_p	= alx_getdbl(PARAM_p_MIN, PARAM_p_DEF, PARAM_p_MAX,
							"p:\t", NULL);

	P	= dist_geometric_P();
	E	= geometric_E(param_p);
	Var	= geometric_Var(param_p);

	printf("\nP{X=x}\t= %lf", P);
	printf("\nE(X)\t= %lf", E);
	printf("\nVar(X)\t= %lf\n", Var);
}


void	dist_uniform		(void)
{
	double	P;
	double	E;
	double	Var;

	printf("\n________________________________________________________________________________\n");
	printf("\nESTADISTICA/Distribuciones:\tDistribucion Uniforme: U(a, b)\n\n");

	printf("a = limite inferior de la distribucion.\n");
	printf("b = limite superior de la distribucion.\n");
	printf("x1 = limite inferior de interes.\n");
	printf("x2 = limite superior de interes.\n\n");

	param_a		= alx_getdbl(PARAM_a_MIN, PARAM_a_DEF, PARAM_a_MAX,
							"a:\t", NULL);
	param_b		= alx_getdbl(PARAM_b_MIN, PARAM_b_DEF, PARAM_b_MAX,
							"b:\t", NULL);
	param_x_dbl[1]	= alx_getdbl(param_a, param_a, param_b,
							"x1:\t", NULL);
	param_x_dbl[2]	= alx_getdbl(param_x_dbl[1], param_b, param_b,
							"x2:\t", NULL);

	P	= uniform_P(param_a, param_b, param_x_dbl[1], param_x_dbl[2]);
	E	= uniform_E(param_a, param_b);
	Var	= uniform_Var(param_a, param_b);

	printf("\nP{x1<X<x2}\t= %lf", P);
	printf("\nE(X)\t\t= %lf", E);
	printf("\nVar(X)\t\t= %lf\n", Var);
}


void	dist_exponential	(void)
{
	double	P;
	double	E;
	double	Var;

	printf("\n________________________________________________________________________________\n");
	printf("\nESTADISTICA/Distribuciones:\tDistribucion Exponencial: exp(beta)\n\n");

	printf("beta = coeficiente beta\n");
	printf("x = tiempo para que ocurra el suceso\n");
	printf("x1 = limite inferior de interes.\n");
	printf("x2 = limite superior de interes.\n\n");

	param_beta	= alx_getdbl(PARAM_beta_MIN, PARAM_beta_DEF, PARAM_beta_MAX,
							"b:\t", NULL);
	param_x_dbl[1]	= alx_getdbl(0, 0, PARAM_x_MAX,
							"x1:\t", NULL);
	param_x_dbl[2]	= alx_getdbl(param_x_dbl[1], param_x_dbl[1] + 1, PARAM_x_MAX,
							"x2:\t", NULL);

	P	= exponential_P(param_beta, param_x_dbl[1], param_x_dbl[2]);
	E	= exponential_E(param_beta);
	Var	= exponential_Var(param_beta);

	printf("\nP{x1<X<x2}\t= %lf\n", P);
	printf("\nE(X)\t= %lf", E);
	printf("\nVar(X)\t= %lf\n", Var);
}

void	dist_normal		(void)
{
	double	o;
	double	a;
	double	b;

	printf("\n________________________________________________________________________________\n");
	printf("\nESTADISTICA/Distribuciones:\tDistribucion Normal (Gauss): N(mu, sigma2)\n\n");

	printf("X -> N(mu,sigma2)\n");
	printf("mu\t=\t\t--Esperanza de X.\n");
	printf("sigma2\t=\t\t--Varianza de X.\n\n");
	printf("sigma\t=\t\t--Desviacion tipica de X.\n\n");

	printf("Z = aX + b\n");
	printf("Z -> N(0,1)\n");
	printf("a\t= 1/o\n");
	printf("b\t= -u/o\n\n");

	param_mu	= alx_getdbl(PARAM_mu_MIN, PARAM_mu_DEF, PARAM_mu_MAX,
							"u:\t", NULL);
	param_sigma2	= alx_getdbl(PARAM_sigma2_MIN, PARAM_sigma2_DEF, PARAM_sigma2_MAX,
							"o2:\t", NULL);

	o	= normal_o(param_sigma2);
	a	= normal_A(o);
	b	= normal_B(param_mu, o);

	printf	("\na\t= %lf\nb\t= %lf\n", a, b);

	dist_normal_m	(a, b);
}



//------------------------------------------------------------------------------
//--| suboptions |--------------------------------------------------------------
//------------------------------------------------------------------------------

static	void	dist_normal_m		(double a, double b)
{
	int64_t	sw;
	int64_t	wh = 1;

	while (wh) {
		printf	("\nTipificar:\n");
		printf	("X -> Z [1]\tZ -> X [2]\tExit[0]\n");

		sw	= alx_getint(0, 1, 2, NULL, NULL);
		switch (sw){
		case 0:
			wh	= 0;
			break;
		case 1:
			dist_normal_m_1(a, b);
			break;
		case 2:
			dist_normal_m_2(a, b);
			break;
		}
	}
}

static	void	dist_normal_m_1		(double a, double b)
{
	double	z;

	printf("Z = %lf * X + %lf\n", a, b);
	param_X	= alx_getdbl(PARAM_X_MIN, PARAM_X_DEF, PARAM_X_MAX,
							"x:\t", NULL);
	z	= normal_Z(a, b, param_X);
	printf("\nz = %lf\n", z);
}

static	void	dist_normal_m_2		(double a, double b)
{
	double	x;

	printf("X = (Z - %lf) / %lf\n", b, a);
	param_Z	= alx_getdbl(PARAM_Z_MIN, PARAM_Z_DEF, PARAM_Z_MAX,
							"z:\t", NULL);
	x	= normal_X(a, b, param_Z);
	printf("\nx = %lf\n", x);
}

static	double	dist_binomial_P		(void)
{
	int64_t	i;
	double	Pi;
	double	P = 0;

	if (param_i_c) {
		for (i = 0; i < param_i_c; i++) {
			printf("x_%"PRIi64":\t", i);
			param_i_x[i]	= alx_getint(PARAM_i_x_MIN, PARAM_i_x_DEF, PARAM_i_x_MAX,
							NULL, NULL);
		}
	} else {
		param_i_a	= alx_getint(PARAM_i_a_MIN, PARAM_i_a_DEF, PARAM_i_a_MAX,
							"a:\t", NULL);
		param_i_b	= alx_getint(PARAM_i_b_MIN, PARAM_i_b_DEF, PARAM_i_b_MAX,
							"b:\t", NULL);
	}

	if (param_i_c) {
		for (i = 0; i < param_i_c; i++) {
			Pi	= binomial_P(param_i_N, param_p, param_i_x[i]);
			printf("P_%"PRIi64"\t= %lf\n", param_i_x[i], Pi);
			P +=	Pi;
		}
	} else {
		for (i = param_i_a; i < param_i_b; i++) {
			Pi	= binomial_P(param_i_N, param_p, i);
			printf("P_%"PRIi64"\t= %lf\n", i, Pi);
			P +=	Pi;
		}
		Pi	= binomial_P(param_i_N, param_p, param_i_b);
		printf("P_%"PRIi64"\t= %lf\n", param_i_b, Pi);
		P +=	Pi;
	}

	return	P;
}


static	double	dist_poisson_P		(void)
{
	int64_t	i;
	double	Pi;
	double	P = 0;

	if (param_i_c) {
		for (i = 0; i < param_i_c; i++) {
			printf("x_%"PRIi64":\t", i);
			param_i_x[i]	= alx_getint(PARAM_i_x_MIN, PARAM_i_x_DEF, PARAM_i_x_MAX,
							NULL, NULL);
		}
	} else {
		param_i_a	= alx_getint(PARAM_i_a_MIN, PARAM_i_a_DEF, PARAM_i_a_MAX,
							"a:\t", NULL);
		param_i_b	= alx_getint(PARAM_i_b_MIN, PARAM_i_b_DEF, PARAM_i_b_MAX,
							"b:\t", NULL);
	}

	if (param_i_c) {
		for (i = 0; i < param_i_c; i++) {
			Pi	= poisson_P(param_lambda, param_i_x[i]);
			printf("P_%"PRIi64"\t= %lf\n", param_i_x[i], Pi);
			P +=	Pi;
		}
	} else {
		for (i = param_i_a; i < param_i_b; i++) {
			Pi	= poisson_P(param_lambda, i);
			printf("P_%"PRIi64"\t= %lf\n", i, Pi);
			P +=	Pi;
		}
		Pi	= poisson_P(param_lambda, param_i_b);
		printf("P_%"PRIi64"\t= %lf\n", param_i_b, Pi);
		P +=	Pi;
	}

	return	P;
}

static	double	dist_geometric_P	(void)
{
	double	P = 0;

	printf("x:\t");
	param_i_x[0]	= alx_getint(PARAM_i_x_MIN, PARAM_i_x_DEF, PARAM_i_x_MAX,
						NULL, NULL);
	P	= geometric_P(param_p, param_i_x[0]);
	printf("P\t= %lf\n", P);

	return	P;
}
