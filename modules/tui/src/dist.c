
/******************************************************************************
 * This program is free software; you can redistribute it and/or modify	      *
 * it under the terms of the GNU General Public License as published by	      *
 * the Free Software Foundation; either version 2 of the License, or          *
 * (at your option) any later version.					      *
 *									      *
 * This program is distributed in the hope that it will be useful,	      *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of	      *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the	      *
 * GNU General Public License for more details.				      *
 *									      *
 * You should have received a copy of the GNU General Public License	      *
 * along with this program; if not, see the file COPYING, or write	      *
 * to the Free Software Foundation, Inc.				      *
 ******************************************************************************/

		/* need: int64_t & INT64_MIN & INT64_MAX  & PRNi64 */
	#include <inttypes.h>
		/* need: INFINITY */
	#include <math.h>
		/* need: printf() */
	#include <stdio.h>

		/* need: alx_getint() & alx_getdbl() */
	#include "alx_getnum.h"

		/* do calculations */
	#include "calc.h"



//------------------------------------------------------------------------------
//--| suboptions |--------------------------------------------------------------
//------------------------------------------------------------------------------

	static	void	dist_normal_m		(double a, double b);
	static	void	dist_normal_m_1		(double a, double b);
	static	void	dist_normal_m_2		(double a, double b);
	static	double	dist_binomial_P		(int64_t n, double p, int64_t c);
	static	double	dist_poisson_P		(double l, int64_t c);
	static	double	dist_geometric_P	(double p);



//------------------------------------------------------------------------------
//--| descriptive statistics |--------------------------------------------------
//------------------------------------------------------------------------------

void		desc_1var		(void)
{
	int64_t		N;
	int64_t		i;
	double	xi;
	double	ni;
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

	N =	alx_getint_mM(1, INT64_MAX, 2, "N:\t", NULL);

	for (i = 1; i <= N; i++) {
		printf("x_%"PRIi64":\t", i);
		xi =	alx_getdbl_mM(-INFINITY, INFINITY, 1, NULL, NULL);
		printf("n_%"PRIi64":\t", i);
		ni =	alx_getdbl_mM(0, INFINITY, 1, NULL, NULL);

		Exi +=	descrip_Exi(ni, xi);
		Exi2 +=	descrip_Exi2(ni, xi);
		Eni +=	descrip_Eni(ni);
	}

	u =	descrip_u(Exi, Eni);
	o2 =	descrip_o2(Exi2, Eni, u);
	o =	descrip_o(o2);
	s2 =	descrip_s2(o2, Eni);
	s =	descrip_s(s2);
	CV =	descrip_CV(o, u);

	printf("\nu\t= %lf", u);
	printf("\no2\t= %lf", o2);
	printf("\no\t= %lf", o);
	printf("\ns2\t= %lf", s2);
	printf("\ns\t= %lf", s);
	printf("\nCV\t= %lf\n", CV);
}

void		desc_2var		(void){
	int64_t		n;
	int64_t		i;
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
	double	yiy2;
	double	xix2;
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

	n =	alx_getint_mM(1, INT64_MAX, 2, "n:\t", NULL);

	double	x[n + 1];
	double	y[n + 1];

	for (i = 1; i <= n; i++) {
		printf("x_%"PRIi64":\t", i);
		x[i] =		alx_getdbl_mM(-INFINITY, INFINITY, 1, NULL, NULL);
		Exi +=		descrip_Exi(1, x[i]);
		Exi2 +=		descrip_Exi2(1, x[i]);

		printf("y_%"PRIi64":\t", i);
		y[i] =		alx_getdbl_mM(-INFINITY, INFINITY, 1, NULL, NULL);
		Eyi +=		descrip_Exi(1, y[i]);
		Eyi2 +=		descrip_Exi2(1, y[i]);

		Exiyi +=	descrip_Exiyi(x[i], y[i]);
	}

	ux =	descrip_u(Exi, n);
	ox2 =	descrip_o2(Exi2, n, ux);
	ox =	descrip_o(ox2);

	uy =	descrip_u(Eyi, n);
	oy2 =	descrip_o2(Eyi2, n, uy);
	oy =	descrip_o(oy2);

	oxy =	descrip_oxy(Exiyi, n, ux, uy);
	a =	descrip_a(oxy, ox2);
	b =	descrip_b(ux, uy, a);
	c =	descrip_a(oxy, oy2);
	d =	descrip_b(uy, ux, c);
	r =	descrip_r(oxy, ox, oy);

	for (i = 1; i <= n; i++) {
		Eyiy2 +=	descrip_Eyiy2(x[i], y[i], a, b);
		Exix2 +=	descrip_Eyiy2(y[i], x[i], c, d);;
	}

	Aa =	descrip_Aa(n, Exi, Exi2, Eyiy2);
	Ab =	descrip_Ab(n, Exi2, Aa);
	Ac =	descrip_Aa(n, Eyi, Eyi2, Exix2);
	Ad =	descrip_Ab(n, Eyi2, Ac);

	Vr =	descrip_Vr(n, Eyiy2);
	R2 =	descrip_R2(oy2, Vr);

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

void		dist_binomial		(void)
{
	int64_t		n;
	int64_t		c;
	double	p;
	double	P = 0;
	double	E;
	double	Var;

	printf("\n________________________________________________________________________________\n");
	printf("\nESTADISTICA/Distribuciones:\tDistribucion Binomial: B(n,p)\n\n");

	printf("n = numero de veces que se repite el experimento (con reemplazamiento)\n");
	printf("p = probabilidad del suceso individual\n");
	printf("x = numero de veces que interesa que ocurra el suceso\n");
	printf("c = cantidad de x que interesan (inroducir [0] para intervalo [a U b])\n\n");

	n =	alx_getint_mM(1, INT64_MAX, 2, "n:\t", NULL);
	p =	alx_getdbl_mM(0, 1, 0.5, "p:\t", NULL);
	c =	alx_getint_mM(0, n+1, 1, "c:\t", NULL);

	P =	dist_binomial_P(n, p, c);
	E =	binomial_E(n, p);
	Var =	binomial_Var(n, p);

	printf("\nP{X}\t= %lf", P);
	printf("\nE(X)\t= %lf", E);
	printf("\nVar(X)\t= %lf\n", Var);

	if ((n*p > 5) && (n*(1-p) > 5)) {
		printf("\nAproximacion a Distribucion Normal N(u = np, o2 = np(1-p))");
		printf("\nu\t= %lf", E);
		printf("\no2\t= %lf\n", Var);
	}
}

void		dist_poisson		(void)
{
	int64_t		c;
	double	l;
	double	P;
	double	E;
	double	Var;

	printf("\n________________________________________________________________________________\n");
	printf("\nESTADISTICA/Distribuciones:\tDistribucion de Poisson: P(l)\n\n");

	printf("l = veces que ocurre de media/ud. de tiempo\n");
	printf("x = veces que interesa que ocurra X/ud. de tiempo\n");
	printf("c = cantidad de x que interesan (inroducir [0] para intervalo [a U b])\n\n");

	l =	alx_getdbl_mM(0, INFINITY, 1, "l:\t", NULL);
	c =	alx_getint_mM(0, INT64_MAX, 1, "c:\t", NULL);

	P =	dist_poisson_P(l, c);
	E =	poisson_E(l);
	Var =	poisson_Var(l);

	printf("\nP{X}\t= %lf", P);
	printf("\nE(X)\t= %lf", E);
	printf("\nVar(X)\t= %lf\n", Var);
}

void		dist_geometric		(void)
{
	int64_t		x;
	double	p;
	double	P;
	double	E;
	double	Var;

	printf("\n________________________________________________________________________________\n");
	printf("\nESTADISTICA/Distribuciones:\tDistribucion Geometrica: G(p)\n\n");

	printf("p = probabilidad del suceso en cada repeticion\n");
	printf("x = vez que interesa que ocurra el suceso\n\n");

	p =	alx_getdbl_mM(0, 1, 0.5, "p:\t", NULL);

	P =	dist_geometric_P(p);
	E =	geometric_E(p);
	Var =	geometric_Var(p);

	printf("\nP{X=x}\t= %lf", P);
	printf("\nE(X)\t= %lf", E);
	printf("\nVar(X)\t= %lf\n", Var);
}


void		dist_uniform		(void)
{
	double	a;
	double	b;
	double	x1;
	double	x2;
	double	P;
	double	E;
	double	Var;

	printf("\n________________________________________________________________________________\n");
	printf("\nESTADISTICA/Distribuciones:\tDistribucion Uniforme: U(a, b)\n\n");

	printf("a = limite inferior de la distribucion.\n");
	printf("b = limite superior de la distribucion.\n");
	printf("x1 = limite inferior de interes.\n");
	printf("x2 = limite superior de interes.\n\n");

	a =	alx_getdbl_mM(-INFINITY, INFINITY, 0, "a:\t", NULL);
	b =	alx_getdbl_mM(a, INFINITY, a+1, "b:\t", NULL);
	x1 =	alx_getdbl_mM(a, b, a, "x1:\t", NULL);
	x2 =	alx_getdbl_mM(x1, b, b, "x2:\t", NULL);

	P =	uniform_P(a, b, x1, x2);
	E =	uniform_E(a, b);
	Var =	uniform_Var(a, b);

	printf("\nP{x1<X<x2}\t= %lf", P);
	printf("\nE(X)\t\t= %lf", E);
	printf("\nVar(X)\t\t= %lf\n", Var);
}


void		dist_exponential	(void)
{
	double	b;
	double	x1;
	double	x2;
	double	P;
	double	E;
	double	Var;

	printf("\n________________________________________________________________________________\n");
	printf("\nESTADISTICA/Distribuciones:\tDistribucion Exponencial: exp(b)\n\n");

	printf("b = coeficiente beta\n");
	printf("x = tiempo para que ocurra el suceso\n");
	printf("x1 = limite inferior de interes.\n");
	printf("x2 = limite superior de interes.\n\n");

	b =	alx_getdbl_mM(0, INFINITY, 1, "b:\t", NULL);
	x1 =	alx_getdbl_mM(0, INFINITY, 1, "x1:\t", NULL);
	x2 =	alx_getdbl_mM(x1, INFINITY, x1+1, "x2:\t", NULL);

	P =	exponential_P(b, x1, x2);
	E =	exponential_E(b);
	Var =	exponential_Var(b);

	printf("\nP{x1<X<x2}\t= %lf\n", P);
	printf("\nE(X)\t= %lf", E);
	printf("\nVar(X)\t= %lf\n", Var);
}

void		dist_normal		(void)
{
	double	u;
	double	o2;
	double	o;
	double	a;
	double	b;

	printf("\n________________________________________________________________________________\n");
	printf("\nESTADISTICA/Distribuciones:\tDistribucion Normal (Gauss): N(u,o2)\n\n");

	printf("X -> N(u,o2)\n");
	printf("u\t=\t\t--Esperanza de X.\n");
	printf("o2\t=\t\t--Varianza de X.\n\n");
	printf("o\t=\t\t--Desviacion tipica de X.\n\n");

	printf("Z = aX + b\n");
	printf("Z -> N(0,1)\n");
	printf("a\t= 1/o\n");
	printf("b\t= -u/o\n\n");

	u =	alx_getdbl_mM(-INFINITY, INFINITY, 0, "u:\t", NULL);
	o2 =	alx_getdbl_mM(0, INFINITY, 1, "o2:\t", NULL);

	o =	normal_o(o2);
	a =	normal_A(o);
	b =	normal_B(u, o);

	printf	("\na\t= %lf\nb\t= %lf\n", a, b);

	dist_normal_m	(a, b);
}



//------------------------------------------------------------------------------
//--| suboptions |--------------------------------------------------------------
//------------------------------------------------------------------------------

static	void	dist_normal_m		(double a, double b)
{
	int64_t		i;
	int64_t		wh = 1;

	while (wh) {
		printf	("\nTipificar:\n");
		printf	("X -> Z [1]\tZ -> X [2]\tExit[0]\n");

		i =	alx_getint_mM(0, 2, 1, NULL, NULL);
		switch (i){
		case 0:
			wh =	0;
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
	double	x;
	double	z;

	printf("Z = %lf * X + %lf\n", a, b);

	x =	alx_getdbl_mM(-INFINITY, INFINITY, 0, "x:\t", NULL);

	z =	normal_Z(a, b, x);

	printf("\nz = %lf\n", z);
}

static	void	dist_normal_m_2		(double a, double b)
{
	double	x;
	double	z;

	printf("X = (Z - %lf) / %lf\n", b, a);

	z =	alx_getdbl_mM(-INFINITY, INFINITY, 0, "z:\t", NULL);

	x =	normal_X(a, b, z);

	printf("\nx = %lf\n", x);
}

static	double	dist_binomial_P		(int64_t n, double p, int64_t c)
{
	int64_t		x;
	int64_t		a;
	int64_t		b;
	int64_t		i;
	double	Pi;
	double	P = 0;

	if (c) {
		for (i = 1; i <= c; i++) {
			printf("x_%"PRIi64":\t", i);
			x =	alx_getint_mM(0, n, 0, NULL, NULL);

			Pi =	binomial_P(n, p, x);
			printf("P_%"PRIi64"\t= %lf\n", i, Pi);
			P +=	Pi;
		}
	} else {
		a =	alx_getint_mM(0, n, 0, "a:\t", NULL);
		b =	alx_getint_mM(a+1, n, 0, "b:\t", NULL);

		for (; a <= b; a++) {
			Pi =	binomial_P(n, p, a);
			printf("P_%"PRIi64"\t= %lf\n", a, Pi);
			P +=	Pi;
		}
	}

	return	P;
}


static	double	dist_poisson_P		(double l, int64_t c)
{
	int64_t		x;
	int64_t		a;
	int64_t		b;
	int64_t		i;
	double	Pi;
	double	P = 0;

	if (c) {
		for	(i = 1; i <= c; i++) {
			printf("x_%"PRIi64":\t", i);
			x =	alx_getint_mM(0, INT64_MAX, 1, NULL, NULL);

			Pi =	poisson_P(l, x);
			printf("P_%"PRIi64"\t= %lf\n", i, Pi);
			P +=	Pi;
		}
	} else {
		a =	alx_getint_mM(0, INT64_MAX, 1, "a:\t", NULL);
		b =	alx_getint_mM(a+1, INT64_MAX, a+2, "b:\t", NULL);

		for	(; a <= b; a++) {
			Pi =	poisson_P(l, a);
			printf("P_%"PRIi64"\t= %lf\n", a, Pi);
			P +=	Pi;
		}
	}

	return	P;
}

static	double	dist_geometric_P	(double p)
{
	int64_t		x;
	int64_t		a;
	int64_t		b;
	double	P = 0;

		printf("x:\t");
		x =	alx_getint_mM(0, INT64_MAX, 1, NULL, NULL);

		P =	geometric_P(p, x);
		printf("P\t= %lf\n", P);

	return	P;
}
