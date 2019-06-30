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

#include <gsl/gsl_cdf.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_statistics_double.h>

#include "libalx/base/stdio/get.h"
#include "libalx/base/stdio/printf/sbprintf.h"
#include "libalx/extra/gsl/distributions/binomial.h"
#include "libalx/extra/gsl/distributions/exponential.h"
#include "libalx/extra/gsl/distributions/geometric.h"
#include "libalx/extra/gsl/distributions/normal.h"
#include "libalx/extra/gsl/distributions/poisson.h"
#include "libalx/extra/gsl/distributions/uniform.h"


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
static	void	dist_normal_normalize	(double a, double b);
static	void	dist_normal_x2z		(double a, double b);
static	void	dist_normal_z2x		(double a, double b);
static	double	dist_binomial_P		(ptrdiff_t c, uint32_t n, double p);
static	double	dist_poisson_P		(ptrdiff_t c, double l);
static	double	dist_geometric_P	(ptrdiff_t c, double p);


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
void	desc_1var	(void)
{
	ptrdiff_t	N;
	double		u, o2, o, s2, s, CV;

	printf("\n________________________________________________________________________________\n");
	printf("mu (u)		= E(wi*xi) / w		--Media.\n");
	printf("sigma2 (o2)	= E(xi^2) / w - u^2	--Varianza.\n");
	printf("s2		= o2 * w / (w - 1)	--Cuasivarianza.\n");
	printf("sigma (o)	= sqrt(o2)		--Desviacion tipica.\n");
	printf("s		= sqrt(s2)		--Cuasidesviacion tipica.\n");
	printf("CV		= o / u			--Coeficiente de variacion.\n");
	printf("\n");

	N = alx_get_pdif(1, 2, PTRDIFF_MAX, "N:", NULL, 3);

	double	x[N];
	double	w[N];

	for (ptrdiff_t i = 0; i < N; i++) {
		printf("x_%ti:", i);
		x[i]	= alx_get_dbl(-INFINITY, 0, INFINITY, NULL, NULL, 3);
		printf("w_%ti:", i);
		w[i]	= alx_get_dbl(-INFINITY, 1, INFINITY, NULL, NULL, 3);
		printf("\n");
	}

	u	= gsl_stats_wmean(w, 1, x, 1, N);
	o2	= gsl_stats_wvariance_with_fixed_mean(w, 1, x, 1, N, u);
	o	= sqrt(o2);
	s2	= gsl_stats_wvariance_m(w, 1, x, 1, N, u);
	s	= sqrt(s2);
	CV	= o / u;

	printf("\n");
	printf("u	= %e\n", u);
	printf("o2	= %e\n", o2);
	printf("o	= %e\n", o);
	printf("s2	= %e\n", s2);
	printf("s	= %e\n", s);
	printf("CV	= %e\n", CV);
	printf("\n");
}

void	desc_2var	(void)
{
	ptrdiff_t	N;
	double		ux, sx2, sx, a, b;
	double		uy, sy2, sy, c, d;
	double		sxy, r;

	printf("\n");
	printf("________________________________________________________________________________\n");
	printf("mu (u)	= E(xi) / n			--Media.\n");
	printf("s2	= E(xi^2) / n - u^2		--Cuasiarianza.\n");
	printf("s	= sqrt(o2)			--Cuasidesviacion tipica.\n");
	printf("sxy	= E(xi*yi) / n - ux * uy	--Covarianza.\n");
	printf("\n");
	printf("a	= sxy / sx2		--Pendiente.\n");
	printf("b	= uy - a * ux		--Sesgo.\n");
	printf("r	= sxy / (sx * sy)	--Coeficiente de correlacion lineal.\n");
	printf("\n");
	printf("n	=			--Numero de puntos.\n");
	printf("\n");

	N = alx_get_pdif(1, 2, PTRDIFF_MAX, "n:", NULL, 3);

	double	x[N];
	double	y[N];

	for (ptrdiff_t i = 0; i < N; i++) {
		printf("x_%ti:", i);
		x[i] = alx_get_dbl(-INFINITY, 0.0, INFINITY, NULL, NULL, 3);
		printf("y_%ti:", i);
		y[i] = alx_get_dbl(-INFINITY, 0.0, INFINITY, NULL, NULL, 3);
		printf("\n");
	}

	ux	= gsl_stats_mean(x, 1, N);
	sx2	= gsl_stats_variance_m(x, 1, N, ux);
	sx	= sqrt(sx2);
	uy	= gsl_stats_mean(y, 1, N);
	sy2	= gsl_stats_variance_m(y, 1, N, uy);
	sy	= sqrt(sy2);
	sxy	= gsl_stats_covariance_m(x, 1, y, 1, N, ux, uy);
	a	= sxy / sx2;
	b	= uy - a * ux;
	c	= sxy / sy2;
	d	= ux - c * uy;
	r	= gsl_stats_correlation(x, 1, y, 1, N);

	printf("\n");
	printf("ux	= %e\n", ux);
	printf("sx2	= %e\n", sx2);
	printf("sx	= %e\n", sx);
	printf("uy	= %e\n", uy);
	printf("sy2	= %e\n", sy2);
	printf("sy	= %e\n", sy);
	printf("sxy	= %e\n", sxy);
	printf("a	= %e\n", a);
	printf("b	= %e\n", b);
	printf("c	= %e\n", c);
	printf("d	= %e\n", d);
	printf("r	= %e\n", r);
	printf("\n");
}

/* distributions -------------------------------------------------------------*/
void	dist_binomial	(void)
{
	uint32_t	n;
	double		p;
	ptrdiff_t	c;
	double		P, E, Var;

	printf("\n");
	printf("________________________________________________________________________________\n");
	printf("ESTADISTICA/Distribuciones:	Distribucion Binomial: B(n,p)\n");
	printf("\n");
	printf("n	= numero de veces que se repite el experimento (con reemplazamiento)\n");
	printf("p	= probabilidad del suceso individual\n");
	printf("x	= numero de veces que interesa que ocurra el suceso\n");
	printf("c	= cantidad de x que interesan (inroducir [0] para intervalo [a U b])\n");
	printf("\n");

	n	= alx_get_u32(1, 1, UINT32_MAX, "n:", NULL, 3);
	p	= alx_get_dbl(0.0, 0.5, 1.0, "p:", NULL, 3);

	E	= alx_gsl_dist_binomial_E(n, p);
	Var	= alx_gsl_dist_binomial_Var(n, p);

	if (((n * p) > 5)  &&  ((n * (1 - p)) > 5)) {
		printf("\n");
		printf("Aproximacion a Distribucion Normal N(u = np, o2 = np(1-p))\n");
		printf("u	= %e\n", E);
		printf("o2	= %e\n", Var);
		printf("\n");
	}

	c	= alx_get_pdif(0, 1, n + 1, "c:", NULL, 3);
	P	= dist_binomial_P(c, n, p);

	printf("\n");
	printf("P{X}	= %e\n", P);
	printf("E(X)	= %e\n", E);
	printf("Var(X)	= %e\n", Var);
	printf("\n");
}

void	dist_poisson	(void)
{
	double		l;
	ptrdiff_t	c;
	double		P, E, Var;

	printf("\n");
	printf("________________________________________________________________________________\n");
	printf("ESTADISTICA/Distribuciones:	Distribucion de Poisson: P(lambda)\n");
	printf("\n");
	printf("lambda (l)	= veces que ocurre de media/ud. de tiempo\n");
	printf("x	= veces que interesa que ocurra X/ud. de tiempo\n");
	printf("c	= cantidad de x que interesan (inroducir [0] para intervalo [a U b])\n");
	printf("\n");

	l	= alx_get_dbl(0.0, 1.0, INFINITY, "l:", NULL, 3);
	c	= alx_get_pdif(0, 1, UINT32_MAX, "c:", NULL, 3);

	P	= dist_poisson_P(c, l);
	E	= alx_gsl_dist_poisson_E(l);
	Var	= alx_gsl_dist_poisson_Var(l);

	printf("\n");
	printf("P{X}	= %e\n", P);
	printf("E(X)	= %e\n", E);
	printf("Var(X)	= %e\n", Var);
	printf("\n");
}

void	dist_geometric	(void)
{
	double		p;
	ptrdiff_t	c;
	double		P, E, Var;

	printf("\n");
	printf("________________________________________________________________________________\n");
	printf("ESTADISTICA/Distribuciones:	Distribucion Geometrica: G(p)\n");
	printf("\n");
	printf("p	= probabilidad del suceso en cada repeticion\n");
	printf("x	= vez que interesa que ocurra el suceso\n");
	printf("c	= cantidad de x que interesan (inroducir [0] para intervalo [a U b])\n");
	printf("\n");

	p	= alx_get_dbl(0.0, 0.5, 1.0, "p:", NULL, 3);
	c	= alx_get_pdif(0, 1, UINT32_MAX, "c:", NULL, 3);

	P	= dist_geometric_P(c, p);
	E	= alx_gsl_dist_geometric_E(p);
	Var	= alx_gsl_dist_geometric_Var(p);

	printf("\n");
	printf("P{X=x}	= %e\n", P);
	printf("E(X)	= %e\n", E);
	printf("Var(X)	= %e\n", Var);
	printf("\n");
}


void	dist_uniform	(void)
{
	double	a, b;
	double	x1, x2;
	double	P, E, Var;

	printf("\n");
	printf("________________________________________________________________________________\n");
	printf("ESTADISTICA/Distribuciones:	Distribucion Uniforme: U(a, b)\n");
	printf("\n");
	printf("a	= limite inferior de la distribucion.\n");
	printf("b	= limite superior de la distribucion.\n");
	printf("x1	= limite inferior de interes.\n");
	printf("x2	= limite superior de interes.\n");
	printf("\n");

	a	= alx_get_dbl(-INFINITY, 0.0, INFINITY, "a:", NULL, 3);
	b	= alx_get_dbl(a, a, INFINITY, "b:", NULL, 3);
	x1	= alx_get_dbl(a, a, b, "x1:", NULL, 3);
	x2	= alx_get_dbl(x1, x1, b, "x2:", NULL, 3);

	P	= gsl_cdf_flat_P(x2, a, b) - gsl_cdf_flat_P(x1, a, b);
	E	= alx_gsl_dist_uniform_E(a, b);
	Var	= alx_gsl_dist_uniform_Var(a, b);

	printf("\n");
	printf("P{x1<X<x2}	= %e\n", P);
	printf("E(X)		= %e\n", E);
	printf("Var(X)		= %e\n", Var);
	printf("\n");
}


void	dist_exponential(void)
{
	double	b, mu;
	double	x1, x2;
	double	P, E, Var;

	printf("\n");
	printf("________________________________________________________________________________\n");
	printf("ESTADISTICA/Distribuciones:	Distribucion Exponencial: exp(beta)\n");
	printf("\n");
	printf("beta (b)	= coeficiente beta\n");
	printf("x		= tiempo para que ocurra el suceso\n");
	printf("x1		= limite inferior de interes.\n");
	printf("x2		= limite superior de interes.\n");
	printf("\n");

	b	= alx_get_dbl(0.0, 1.0, INFINITY, "b:", NULL, 3);
	x1	= alx_get_dbl(0.0, 1.0, INFINITY, "x1:", NULL, 3);
	x2	= alx_get_dbl(x1, x1 + 1.0, INFINITY, "x2:", NULL, 3);

	mu	= 1.0 / b;
	P	= gsl_cdf_exponential_P(x2, mu) - gsl_cdf_exponential_P(x1, mu);
	E	= alx_gsl_dist_exponential_E(b);
	Var	= alx_gsl_dist_exponential_Var(b);

	printf("\n");
	printf("P{x1<X<x2}	= %e\n", P);
	printf("E(X)		= %e\n", E);
	printf("Var(X)		= %e\n", Var);
	printf("\n");
}

void	dist_normal	(void)
{
	double	u, o2;
	double	o, a, b;

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

	u	= alx_get_dbl(-INFINITY, 0.0, INFINITY, "u:", NULL, 3);
	o2	= alx_get_dbl(0.0, 1.0, INFINITY, "o2:", NULL, 3);

	o	= sqrt(o2);
	a	= alx_gsl_dist_normal_A(o);
	b	= alx_gsl_dist_normal_B(u, o);

	printf("\n");
	printf("a	= %e\n", a);
	printf("b	= %e\n", b);
	printf("\n");

	dist_normal_normalize(a, b);
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/
static	void	dist_normal_normalize	(double a, double b)
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

static	void	dist_normal_x2z		(double a, double b)
{
	double	x;
	double	z;

	printf("Z = %e * X + %e\n", a, b);
	x	= alx_get_dbl(-INFINITY, 1.0, INFINITY, "x:", NULL, 3);
	z	= alx_gsl_dist_normal_X2Z(a, b, x);
	printf("\nz = %e\n", z);
}

static	void	dist_normal_z2x		(double a, double b)
{
	double	z;
	double	x;

	printf("X = (Z - %e) / %e\n", b, a);
	z	= alx_get_dbl(-INFINITY, 1.0, INFINITY, "z:", NULL, 3);
	x	= alx_gsl_dist_normal_Z2X(a, b, z);
	printf("\nx = %e\n", x);
}

static	double	dist_binomial_P		(ptrdiff_t c, uint32_t n, double p)
{
	uint32_t	x[c];
	double		Pi, P;
	uint32_t	a, b;
	char		txt[80];

	if (c) {
		for (ptrdiff_t i = 0; i < c; i++) {
			alx_sbprintf__(txt, NULL, "x_%ti:", i);
			x[i]	= alx_get_u32(0, 0, n, txt, NULL, 3);
		}
	} else {
		a	= alx_get_u32(0, 0, n, "a:", NULL, 3);
		b	= alx_get_u32(a, n, n, "b:", NULL, 3);
	}

	P = 0;
	if (c) {
		for (ptrdiff_t i = 0; i < c; i++) {
			Pi	= gsl_ran_binomial_pdf(x[i], p, n);
			printf("P_%"PRIu32"\t= %e\n", x[i], Pi);
			P += Pi;
		}
	} else {
		for (int64_t i = b; i >= a; i--) {
			Pi	= gsl_ran_binomial_pdf(i, p, n);
			printf("P_%"PRIi64"\t= %e\n", i, Pi);
			P += Pi;
		}
	}

	return	P;
}

static	double	dist_poisson_P		(ptrdiff_t c, double l)
{
	uint32_t	x[c];
	double		Pi, P;
	uint32_t	a, b;
	char		txt[80];

	if (c) {
		for (ptrdiff_t i = 0; i < c; i++) {
			alx_sbprintf__(txt, NULL, "x_%ti:", i);
			x[i]	= alx_get_u32(0, i, UINT32_MAX, txt, NULL, 3);
		}
	} else {
		a	= alx_get_u32(0, 0, UINT32_MAX, "a:", NULL, 3);
		b	= alx_get_u32(a, UINT32_MAX, UINT32_MAX, "b:", NULL, 3);
	}

	P = 0;
	if (c) {
		for (ptrdiff_t i = 0; i < c; i++) {
			Pi	= gsl_ran_poisson_pdf(x[i], l);
			printf("P_%"PRIu32"\t= %e\n", x[i], Pi);
			P += Pi;
		}
	} else {
		for (int64_t i = b; i >= a; i--) {
			Pi	= gsl_ran_poisson_pdf(i, l);
			printf("P_%"PRIi64"\t= %e\n", i, Pi);
			P += Pi;
		}
	}

	return	P;
}

static	double	dist_geometric_P	(ptrdiff_t c, double p)
{
	uint32_t	x[c];
	double		Pi, P;
	uint32_t	a, b;
	char		txt[80];

	if (c) {
		for (ptrdiff_t i = 0; i < c; i++) {
			alx_sbprintf__(txt, NULL, "x_%ti:", i);
			x[i] = alx_get_u32(0, 0, UINT32_MAX, txt, NULL, 3);
		}
	} else {
		a	= alx_get_u32(0, 0, UINT32_MAX, "a:", NULL, 3);
		b	= alx_get_u32(a, UINT32_MAX, UINT32_MAX, "b:", NULL, 3);
	}

	P = 0;
	if (c) {
		for (ptrdiff_t i = 0; i < c; i++) {
			Pi	= gsl_ran_geometric_pdf(x[i], p);
			printf("P_%"PRIu32"\t= %e\n", x[i], Pi);
			P += Pi;
		}
	} else {
		for (int64_t i = b; i >= a; i--) {
			Pi	= gsl_ran_geometric_pdf(i, p);
			printf("P_%"PRIi64"\t= %e\n", i, Pi);
			P += Pi;
		}
	}

	return	P;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
