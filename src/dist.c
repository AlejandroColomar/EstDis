/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	GPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "estadistica/dist.h"

#include <inttypes.h>
#include <math.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#include "libalx/base/math/descriptive_statistics_1var.h"
#include "libalx/base/math/descriptive_statistics_2var.h"
#include "libalx/base/math/distribution_binomial.h"
#include "libalx/base/math/distribution_exponential.h"
#include "libalx/base/math/distribution_geometric.h"
#include "libalx/base/math/distribution_normal.h"
#include "libalx/base/math/distribution_poisson.h"
#include "libalx/base/math/distribution_uniform.h"
#include "libalx/base/math/fast.h"
#include "libalx/base/stdio/get.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enums ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* structs / unions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* variables ************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static functions (prototypes) ****************************************
 ******************************************************************************/
static	void		dist_normal_normalize	(double_t a, double_t b);
static	void		dist_normal_x2z		(double_t a, double_t b);
static	void		dist_normal_z2x		(double_t a, double_t b);
static	double_t	dist_binomial_P		(ptrdiff_t c,
						int_fast16_t n, double_t p);
static	double_t	dist_poisson_P		(ptrdiff_t c, double_t l);
static	double_t	dist_geometric_P	(ptrdiff_t c,
						double_t p);


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
void	desc_1var	(void)
{
	ptrdiff_t	N;
	struct Alx_Descriptive_Statistics_1var	stats;

	printf("\n________________________________________________________________________________\n");
	printf("mu (u)		= E(ni*xi) / n		--Media.\n");
	printf("sigma2 (o2)	= E(xi^2) / n - u^2	--Varianza.\n");
	printf("s2		= o2 * n / (n - 1)	--Cuasivarianza.\n");
	printf("sigma (o)	= sqrt(o2)		--Desviacion tipica.\n");
	printf("s		= sqrt(s2)		--Cuasidesviacion tipica.\n");
	printf("CV		= o / u			--Coeficiente de variacion.\n");
	printf("\n");

	N = alx_get_ptrdiff(ALX_DS1V_N_MIN, 2, PTRDIFF_MAX, "N:", NULL, 3);

	double	x[N];
	double	n[N];

	for (ptrdiff_t i = 0; i < N; i++) {
		printf("x_%ti:", i);
		x[i]	= alx_get_dbl(-INFINITY, 0, INFINITY, NULL, NULL, 3);
		printf("n_%ti:", i);
		n[i]	= alx_get_dbl(-INFINITY, 1, INFINITY, NULL, NULL, 3);
		printf("\n");
	}

	stats	= alx_descriptive_statistics_1var(N, x, n);

	printf("\n");
	printf("u	= %lf\n", stats.u);
	printf("o2	= %lf\n", stats.o2);
	printf("o	= %lf\n", stats.o);
	printf("s2	= %lf\n", stats.s2);
	printf("s	= %lf\n", stats.s);
	printf("CV	= %lf\n", stats.CV);
	printf("\n");
}

void	desc_2var	(void)
{
	ptrdiff_t	N;
	struct Alx_Descriptive_Statistics_2var	stats;

	printf("\n");
	printf("________________________________________________________________________________\n");
	printf("mu (u)		= E(xi) / n			--Media.\n");
	printf("sigma2 (o2)	= E(xi^2) / n - u^2		--Varianza.\n");
	printf("sigma (o)	= sqrt(o2)			--Desviacion tipica.\n");
	printf("sigmaxy (oxy)	= E(xi*yi) / n - ux * uy	--Covarianza.\n");
	printf("\n");
	printf("a	= oxy / ox2		--Pendiente.\n");
	printf("b	= uy - a * ux		--Sesgo.\n");
	printf("r	= oxy / (ox * oy)	--Coeficiente de correlacion lineal.\n");
	printf("\n");
	printf("n	=			--Numero de puntos.\n");
	printf("\n");

	N = alx_get_ptrdiff(ALX_DS1V_N_MIN, 2, PTRDIFF_MAX, "n:", NULL, 3);

	double	x[N];
	double	y[N];

	for (ptrdiff_t i = 0; i < N; i++) {
		printf("x_%ti:", i);
		x[i] = alx_get_dbl(-INFINITY, 0, INFINITY, NULL, NULL, 3);
		printf("y_%ti:", i);
		y[i] = alx_get_dbl(-INFINITY, 0, INFINITY, NULL, NULL, 3);
		printf("\n");
	}

	stats	= alx_descriptive_statistics_2var(N, x, y);

	printf("\n");
	printf("ux	= %lf\n", stats.ux);
	printf("ox2	= %lf\n", stats.ox2);
	printf("ox	= %lf\n", stats.ox);
	printf("uy	= %lf\n", stats.uy);
	printf("oy2	= %lf\n", stats.oy2);
	printf("oy	= %lf\n", stats.oy);
	printf("oxy	= %lf\n", stats.oxy);
	printf("a	= %lf\n", stats.a);
	printf("Aa	= %lf\n", stats.Aa);
	printf("b	= %lf\n", stats.b);
	printf("Ab	= %lf\n", stats.Ab);
	printf("c	= %lf\n", stats.c);
	printf("Ac	= %lf\n", stats.Ac);
	printf("d	= %lf\n", stats.d);
	printf("Ad	= %lf\n", stats.Ad);
	printf("r	= %lf\n", stats.r);
	printf("Vr	= %lf\n", stats.Vr);
	printf("R2	= %lf\n", stats.R2);
	printf("\n");
}

/* distributions -------------------------------------------------------------*/
void	dist_binomial	(void)
{
	int_fast16_t	n;
	double_t	p;
	ptrdiff_t	c;
	double_t	P, E, Var;

	printf("\n");
	printf("________________________________________________________________________________\n");
	printf("ESTADISTICA/Distribuciones:	Distribucion Binomial: B(n,p)\n");
	printf("\n");
	printf("n	= numero de veces que se repite el experimento (con reemplazamiento)\n");
	printf("p	= probabilidad del suceso individual\n");
	printf("x	= numero de veces que interesa que ocurra el suceso\n");
	printf("c	= cantidad de x que interesan (inroducir [0] para intervalo [a U b])\n");
	printf("\n");

	n	= alx_get_s16(DIST_BINOMIAL_n_MIN, 1, INT16_MAX, "n:", NULL, 3);
	p	= alx_get_dbl(DIST_BINOMIAL_p_MIN, 0.5, DIST_BINOMIAL_p_MAX,
								"p:", NULL, 3);
	c	= alx_get_ptrdiff(0, 1, INT16_MAX, "c:", NULL, 3);

	P	= dist_binomial_P(c, n, p);
	E	= alx_distribution_binomial_E(n, p);
	Var	= alx_distribution_binomial_Var(n, p);

	printf("\n");
	printf("P{X}	= %"PRIdbl"\n", P);
	printf("E(X)	= %"PRIdbl"\n", E);
	printf("Var(X)	= %"PRIdbl"\n", Var);

	if (((n * p) > 5)  &&  ((n * (1 - p)) > 5)) {
		printf("\n");
		printf("Aproximacion a Distribucion Normal N(u = np, o2 = np(1-p))\n");
		printf("u	= %"PRIdbl"\n", E);
		printf("o2	= %"PRIdbl"\n", Var);
	}
	printf("\n");
}

void	dist_poisson	(void)
{
	double_t	l;
	ptrdiff_t	c;
	double_t	P, E, Var;

	printf("\n");
	printf("________________________________________________________________________________\n");
	printf("ESTADISTICA/Distribuciones:	Distribucion de Poisson: P(lambda)\n");
	printf("\n");
	printf("lambda (l)	= veces que ocurre de media/ud. de tiempo\n");
	printf("x	= veces que interesa que ocurra X/ud. de tiempo\n");
	printf("c	= cantidad de x que interesan (inroducir [0] para intervalo [a U b])\n");
	printf("\n");

	l	= alx_get_dbl(DIST_POISSON_l_MIN, 1, INFINITY, "l:", NULL, 3);
	c	= alx_get_ptrdiff(0, 1, INT16_MAX, "c:", NULL, 3);

	P	= dist_poisson_P(c, l);
	E	= alx_distribution_poisson_E(l);
	Var	= alx_distribution_poisson_Var(l);

	printf("\n");
	printf("P{X}	= %"PRIdbl"\n", P);
	printf("E(X)	= %"PRIdbl"\n", E);
	printf("Var(X)	= %"PRIdbl"\n", Var);
	printf("\n");
}

void	dist_geometric	(void)
{
	double_t	p;
	ptrdiff_t	c;
	double_t	P, E, Var;

	printf("\n");
	printf("________________________________________________________________________________\n");
	printf("ESTADISTICA/Distribuciones:	Distribucion Geometrica: G(p)\n");
	printf("\n");
	printf("p	= probabilidad del suceso en cada repeticion\n");
	printf("x	= vez que interesa que ocurra el suceso\n");
	printf("c	= cantidad de x que interesan (inroducir [0] para intervalo [a U b])\n");
	printf("\n");

	p	= alx_get_dbl(DIST_GEOMETRIC_p_MIN, 0.5, DIST_GEOMETRIC_p_MAX,
							"p:", NULL, 3);
	c	= alx_get_ptrdiff(0, 1, INT32_MAX, "c:", NULL, 3);

	P	= dist_geometric_P(c, p);
	E	= alx_distribution_geometric_E(p);
	Var	= alx_distribution_geometric_Var(p);

	printf("\n");
	printf("P{X=x}	= %"PRIdbl"\n", P);
	printf("E(X)	= %"PRIdbl"\n", E);
	printf("Var(X)	= %"PRIdbl"\n", Var);
	printf("\n");
}


void	dist_uniform	(void)
{
	double_t	a, b;
	double_t	x1, x2;
	double_t	P, E, Var;

	printf("\n");
	printf("________________________________________________________________________________\n");
	printf("ESTADISTICA/Distribuciones:	Distribucion Uniforme: U(a, b)\n");
	printf("\n");
	printf("a	= limite inferior de la distribucion.\n");
	printf("b	= limite superior de la distribucion.\n");
	printf("x1	= limite inferior de interes.\n");
	printf("x2	= limite superior de interes.\n");
	printf("\n");

	a	= alx_get_dbl(-INFINITY, 0, INFINITY, "a:", NULL, 3);
	b	= alx_get_dbl(a, a, INFINITY, "b:", NULL, 3);
	x1	= alx_get_dbl(a, a, b, "x1:", NULL, 3);
	x2	= alx_get_dbl(x1, x1, b, "x2:", NULL, 3);

	P	= alx_distribution_uniform_P(a, b, x1, x2);
	E	= alx_distribution_uniform_E(a, b);
	Var	= alx_distribution_uniform_Var(a, b);

	printf("\n");
	printf("P{x1<X<x2}	= %"PRIdbl"\n", P);
	printf("E(X)		= %"PRIdbl"\n", E);
	printf("Var(X)		= %"PRIdbl"\n", Var);
	printf("\n");
}


void	dist_exponential(void)
{
	double_t	b;
	double_t	x1, x2;
	double_t	P, E, Var;

	printf("\n");
	printf("________________________________________________________________________________\n");
	printf("ESTADISTICA/Distribuciones:	Distribucion Exponencial: exp(beta)\n");
	printf("\n");
	printf("beta (b)	= coeficiente beta\n");
	printf("x		= tiempo para que ocurra el suceso\n");
	printf("x1		= limite inferior de interes.\n");
	printf("x2		= limite superior de interes.\n");
	printf("\n");

	b	= alx_get_dbl(DIST_BINOMIAL_b_MIN, 1, INFINITY, "b:", NULL, 3);
	x1	= alx_get_dbl(DIST_BINOMIAL_x_MIN, 1, INFINITY, "x1:", NULL, 3);
	x2	= alx_get_dbl(x1, x1 + 1, INFINITY, "x2:", NULL, 3);

	P	= alx_distribution_exponential_P(b, x1, x2);
	E	= alx_distribution_exponential_E(b);
	Var	= alx_distribution_exponential_Var(b);

	printf("\n");
	printf("P{x1<X<x2}	= %"PRIdbl"\n", P);
	printf("E(X)		= %"PRIdbl"\n", E);
	printf("Var(X)		= %"PRIdbl"\n", Var);
	printf("\n");
}

void	dist_normal	(void)
{
	double_t	u, o2;
	double_t	o, a, b;

	printf("\n");
	printf("________________________________________________________________________________\n");
	printf("ESTADISTICA/Distribuciones:	Distribucion Normal (Gauss): N(mu, sigma2)\n");
	printf("\n");
	printf("X -> N(mu,sigma2)\n");
	printf("mu (u)		= Esperanza de X.\n");
	printf("sigma2 (o2)	= Varianza de X.\n");
	printf("sigma (o)	= Desviacion tipica de X.\n");
	printf("\n");
	printf("Z = aX + b\n");
	printf("Z -> N(0,1)\n");
	printf("a	= 1/o\n");
	printf("b	= -u/o\n");
	printf("\n");

	u	= alx_get_dbl(-INFINITY, 0, INFINITY, "u:", NULL, 3);
	o2	= alx_get_dbl(DIST_NORMAL_o2_MIN, 1, INFINITY, "o2:", NULL, 3);

	o	= sqrt(o2);
	a	= alx_distribution_normal_A(o);
	b	= alx_distribution_normal_B(u, o);

	printf("\n");
	printf("a	= %"PRIdbl"\n", a);
	printf("b	= %"PRIdbl"\n", b);
	printf("\n");

	dist_normal_normalize(a, b);
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/
static	void		dist_normal_normalize	(double_t a, double_t b)
{
	int_fast8_t	sw;
	bool		wh;

	wh	= true;
	while (wh) {
		printf("\n");
		printf("Tipificar:\n");
		printf("X -> Z [1]	Z -> X [2]	Exit[0]\n");

		sw	= alx_get_s8(0, 1, 2, NULL, NULL, 3);
		switch (sw){
		case 0:
			wh	= false;
			break;
		case 1:
			dist_normal_x2z(a, b);
			break;
		case 2:
			dist_normal_z2x(a, b);
			break;
		}
	}
}

static	void		dist_normal_x2z		(double_t a, double_t b)
{
	double_t	x;
	double_t	z;

	printf("Z = %"PRIdbl" * X + %"PRIdbl"\n", a, b);
	x	= alx_get_dbl(-INFINITY, 1, INFINITY, "x:", NULL, 3);
	z	= alx_distribution_normal_X2Z(a, b, x);
	printf("\nz = %"PRIdbl"\n", z);
}

static	void		dist_normal_z2x	(double_t a, double_t b)
{
	double_t	z;
	double_t	x;

	printf("X = (Z - %"PRIdbl") / %"PRIdbl"\n", b, a);
	z	= alx_get_dbl(-INFINITY, 1, INFINITY, "z:", NULL, 3);
	x	= alx_distribution_normal_Z2X(a, b, z);
	printf("\nx = %"PRIdbl"\n", x);
}

static	double_t	dist_binomial_P		(ptrdiff_t c,
						int_fast16_t n, double_t p)
{
	int_fast16_t	x[c];
	double_t	Pi, P;
	int_fast16_t	a, b;
	char		txt[80];

	if (c) {
		for (ptrdiff_t i = 0; i < c; i++) {
			snprintf(txt, 80, "x_%ti:", i);
			x[i]	= alx_get_s16(DIST_BINOMIAL_x_MIN, 0, n,
								txt, NULL, 3);
		}
	} else {
		a	= alx_get_s16(DIST_BINOMIAL_x_MIN, 0, n, "a:", NULL, 3);
		b	= alx_get_s16(a, n, n, "b:", NULL, 3);
	}

	P = 0;
	if (c) {
		for (ptrdiff_t i = 0; i < c; i++) {
			Pi	= alx_distribution_binomial_P(n, p, x[i]);
			printf("P_%"PRIiFAST16"\t= %"PRIdbl"\n", x[i], Pi);
			P += Pi;
		}
	} else {
		for (int_fast16_t i = b; i >= a; i--) {
			Pi	= alx_distribution_binomial_P(n, p, i);
			printf("P_%"PRIiFAST16"\t= %"PRIdbl"\n", i, Pi);
			P += Pi;
		}
	}

	return	P;
}

static	double_t	dist_poisson_P		(ptrdiff_t c, double_t l)
{
	int_fast16_t	x[c];
	double_t	Pi, P;
	int_fast16_t	a, b;
	char	txt[80];

	if (c) {
		for (ptrdiff_t i = 0; i < c; i++) {
			snprintf(txt, 80, "x_%ti:", i);
			x[i]	= alx_get_s16(DIST_POISSON_x_MIN, i, INT16_MAX,
								txt, NULL, 3);
		}
	} else {
		a	= alx_get_s16(0, 0, INT16_MAX, "a:", NULL, 3);
		b	= alx_get_s16(a, INT16_MAX, INT16_MAX, "b:", NULL, 3);
	}

	P = 0;
	if (c) {
		for (ptrdiff_t i = 0; i < c; i++) {
			Pi	= alx_distribution_poisson_P(l, x[i]);
			printf("P_%"PRIiFAST16"\t= %"PRIdbl"\n", x[i], Pi);
			P += Pi;
		}
	} else {
		for (int_fast16_t i = b; i >= a; i--) {
			Pi	= alx_distribution_poisson_P(l, i);
			printf("P_%"PRIiFAST16"\t= %"PRIdbl"\n", i, Pi);
			P += Pi;
		}
	}

	return	P;
}

static	double_t	dist_geometric_P	(ptrdiff_t c,
						double_t p)
{
	int_fast32_t	x[c];
	double_t	Pi, P;
	int_fast32_t	a, b;
	char		txt[80];

	if (c) {
		for (ptrdiff_t i = 0; i < c; i++) {
			snprintf(txt, 80, "x_%ti:", i);
			x[i] = alx_get_s32(DIST_GEOMETRIC_x_MIN, 0, INT32_MAX,
								txt, NULL, 3);
		}
	} else {
		a	= alx_get_s32(DIST_GEOMETRIC_x_MIN, 0, INT32_MAX,
								"a:", NULL, 3);
		b	= alx_get_s32(a, INT32_MAX, INT32_MAX, "b:", NULL, 3);
	}

	P = 0;
	if (c) {
		for (ptrdiff_t i = 0; i < c; i++) {
			Pi	= alx_distribution_geometric_P(p, x[i]);
			printf("P_%"PRIiFAST32"\t= %"PRIdbl"\n", x[i], Pi);
			P += Pi;
		}
	} else {
		for (int_fast32_t i = b; i >= a; i--) {
			Pi	= alx_distribution_geometric_P(p, i);
			printf("P_%"PRIiFAST32"\t= %"PRIdbl"\n", i, Pi);
			P += Pi;
		}
	}

	return	P;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
