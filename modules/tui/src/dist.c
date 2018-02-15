////////////////----------------------------------------////////////////
////////////////        EstDis                          ////////////////
////////////////----------------------------------------////////////////

	/*
	 * EstDis	This is a solver of statistics problems.
	 * Copyright (C) 2016 Alejandro Colomar Andrés
	 *
	 * This program is free software: you can redistribute it and/or
	 * modify it under the terms of the GNU General Public License
	 * as published by the Free Software Foundation, either version
	 * 3 of the License, or (at your option) any later version.

	 * This program is distributed in the hope that it will be
	 * useful, but WITHOUT ANY WARRANTY; without even the implied
	 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
	 * PURPOSE.  See the GNU General Public License for more
	 * details.
	 *
	 * You should have received a copy of the GNU General Public
	 * License along with this program.
	 * If not, see <http://www.gnu.org/licenses/>.
	 */

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

	#include <inttypes.h>
	#include <curses.h>
	#include <stdio.h>
	#include <tgmath.h>

	#include "alx_getnum.h"

	#include "calc.h"
	#include "dist.h"

long double		dist_binomial_P		(int64_t n, long double p, int64_t c)
{
	int64_t		x;
	int64_t		a;
	int64_t		b;
	int64_t		i;
	long double	Pi;
	long double	P = 0;

	if (c) {
		for (i = 1; i <= c; i++) {
			printf("x_%"PRIi64":\t", i);
			x =	alx_getint_mM(0, n, 0, NULL, NULL);

			Pi =	binomial_P(n, p, x);
			printf("P_%"PRIi64"\t= %Lf\n", i, Pi);
			P +=	Pi;
		}
	} else {
		a =	alx_getint_mM(0, n, 0, "a:\t", NULL);
		b =	alx_getint_mM(a+1, n, 0, "b:\t", NULL);

		for (; a <= b; a++) {
			Pi =	binomial_P(n, p, a);
			printf("P_%"PRIi64"\t= %Lf\n", a, Pi);
			P +=	Pi;
		}
	}

	return	P;
}

void			dist_binomial		(void)
{
	int64_t		n;
	int64_t		c;
	long double	p;
	long double	P = 0;
	long double	E;
	long double	Var;

	printf("\n_______________________________________________________________________________________________________________\n");
	printf("\nESTADISTICA/Distribuciones:\tDistribucion Binomial: B(n,p)\n\n");

	printf("n = numero de veces que se repite el experimento (con reemplazamiento)\n");
	printf("p = probabilidad del suceso individual\n");
	printf("x = numero de veces que interesa que ocurra el suceso\n");
	printf("c = cantidad de x que interesan (inroducir [0] para intervalo [a U b])\n\n");

	n =	alx_getint_m(1, 2, "n:\t", NULL);
	p =	alx_getdbl_mM(0, 1, 0.5, "p:\t", NULL);
	c =	alx_getint_mM(0, n+1, 1, "c:\t", NULL);

	P =	dist_binomial_P(n, p, c);
	E =	binomial_E(n, p);
	Var =	binomial_Var(n, p);

	printf("\nP{X}\t= %Lf", P);
	printf("\nE(X)\t= %Lf", E);
	printf("\nVar(X)\t= %Lf\n", Var);

	if ((n*p > 5) && (n*(1-p) > 5)) {
		printf("\nAproximacion a Distribucion Normal N(u = np, o2 = np(1-p))");
		printf("\nu\t= %Lf", E);
		printf("\no2\t= %Lf\n", Var);
	}
getchar();
}


long double		dist_poisson_P		(long double l, int64_t c)
{
	int64_t		x;
	int64_t		a;
	int64_t		b;
	int64_t		i;
	long double	Pi;
	long double	P = 0;

	if (c) {
		for	(i = 1; i <= c; i++) {
			printf("x_%"PRIi64":\t", i);
			x =	alx_getint_m(0, 1, NULL, NULL);

			Pi =	poisson_P(l, x);
			printf("P_%"PRIi64"\t= %Lf\n", i, Pi);
			P +=	Pi;
		}
	} else {
		a =	alx_getint_m(0, 1, "a:\t", NULL);
		b =	alx_getint_m(a+1, a+2, "b:\t", NULL);

		for	(; a <= b; a++) {
			Pi =	poisson_P(l, a);
			printf("P_%"PRIi64"\t= %Lf\n", a, Pi);
			P +=	Pi;
		}
	}

	return	P;
}

void			dist_poisson		(void)
{
	int64_t		c;
	long double	l;
	long double	P;
	long double	E;
	long double	Var;

	printf("\n_______________________________________________________________________________________________________________\n");
	printf("\nESTADISTICA/Distribuciones:\tDistribucion de Poisson: P(l)\n\n");

	printf("l = veces que ocurre de media/ud. de tiempo\n");
	printf("x = veces que interesa que ocurra X/ud. de tiempo\n");
	printf("c = cantidad de x que interesan (inroducir [0] para intervalo [a U b])\n\n");

	l =	alx_getdbl_m(0, 1, "l:\t", NULL);
	c =	alx_getint_m(0, 1, "c:\t", NULL);

	P =	dist_poisson_P(l, c);
	E =	poisson_E(l);
	Var =	poisson_Var(l);

	printf("\nP{X}\t= %Lf", P);
	printf("\nE(X)\t= %Lf", E);
	printf("\nVar(X)\t= %Lf\n", Var);
getchar();
}


long double		dist_geometric_P	(long double p, int64_t c)
{
	int64_t		x;
	int64_t		a;
	int64_t		b;
	int64_t		i;
	long double	Pi;
	long double	P = 0;

	if (c) {
		for	(i = 1; i <= c; i++) {
			printf("x_%"PRIi64":\t", i);
			x =	alx_getint_m(0, 1, NULL, NULL);

			Pi =	geometric_P(p, x);
			printf("P_%"PRIi64"\t= %Lf\n", i, Pi);
			P +=	Pi;
		}
	} else {
		a =	alx_getint_m(0, 1, "a:\t", NULL);
		b =	alx_getint_m(a+1, a+2, "b:\t", NULL);

		for	(; a <= b; a++) {
			Pi =	geometric_P(p, a);
			printf("P_%"PRIi64"\t= %Lf\n", a, Pi);
			P +=	Pi;
		}
	}

	return	P;
}

void			dist_geometric		(void)
{
	int64_t		x;
	int64_t		c;
	long double	p;
	long double	P;
	long double	E;
	long double	Var;

	printf("\n_______________________________________________________________________________________________________________\n");
	printf("\nESTADISTICA/Distribuciones:\tDistribucion Geometrica: G(p)\n\n");

	printf("p = probabilidad del suceso en cada repeticion\n");
	printf("x = vez que interesa que ocurra el suceso\n\n");
	printf("c = cantidad de x que interesan (inroducir [0] para intervalo [a U b])\n\n");

	p =	alx_getdbl_mM(0, 1, 0.5, "p:\t", NULL);
	c =	alx_getint_m(0, 1, "c:\t", NULL);

	P =	dist_geometric_P(p, c);
	E =	geometric_E(p);
	Var =	geometric_Var(p);

	printf("\nP{X=x}\t= %Lf", P);
	printf("\nE(X)\t= %Lf", E);
	printf("\nVar(X)\t= %Lf\n", Var);
getchar();
}


void			dist_uniform		(void)
{
	long double	a;
	long double	b;
	long double	x1;
	long double	x2;
	long double	P;
	long double	E;
	long double	Var;

	printf("\n_______________________________________________________________________________________________________________\n");
	printf("\nESTADISTICA/Distribuciones:\tDistribucion Uniforme: U(a, b)\n\n");

	printf("a = limite inferior de la distribucion.\n");
	printf("b = limite superior de la distribucion.\n");
	printf("x1 = limite inferior de interes.\n");
	printf("x2 = limite superior de interes.\n\n");

	a =	alx_getdbl("a:\t", NULL);
	b =	alx_getdbl_m(a, a+1, "b:\t", NULL);
	x1 =	alx_getdbl_mM(a, b, a, "x1:\t", NULL);
	x2 =	alx_getdbl_mM(x1, b, b, "x2:\t", NULL);

	P =	uniform_P(a, b, x1, x2);
	E =	uniform_E(a, b);
	Var =	uniform_Var(a, b);

	printf("\nP{x1<X<x2}\t= %Lf", P);
	printf("\nE(X)\t\t= %Lf", E);
	printf("\nVar(X)\t\t= %Lf\n", Var);
getchar();
}


void			dist_exponential	(void)
{
	long double	b;
	long double	x1;
	long double	x2;
	long double	P;
	long double	E;
	long double	Var;

	printf("\n_______________________________________________________________________________________________________________\n");
	printf("\nESTADISTICA/Distribuciones:\tDistribucion Exponencial: exp(b)\n\n");

	printf("b = coeficiente beta\n");
	printf("x = tiempo para que ocurra el suceso\n");
	printf("x1 = limite inferior de interes.\n");
	printf("x2 = limite superior de interes.\n\n");

	b =	alx_getdbl_m(0, 1, "b:\t", NULL);
	x1 =	alx_getdbl_m(0, 1, "x1:\t", NULL);
	x2 =	alx_getdbl_m(x1, x1+1, "x2:\t", NULL);

	P =	exponential_P(b, x1, x2);
	E =	exponential_E(b);
	Var =	exponential_Var(b);

	printf("\nP{x1<X<x2}\t= %Lf\n", P);
	printf("\nE(X)\t= %Lf", E);
	printf("\nVar(X)\t= %Lf\n", Var);
getchar();
}


void			dist_normal_m_1		(long double a, long double b)
{
	long double	x;
	long double	z;

	printf("Z = %Lf * X + %Lf\n", a, b);

	x =	alx_getdbl("x:\t", NULL);

	z =	normal_Z(a, b, x);

	printf("\nz = %Lf\n", z);
}

void			dist_normal_m_2		(long double a, long double b)
{
	long double	x;
	long double	z;

	printf("X = (Z - %Lf) / %Lf\n", b, a);

	z =	alx_getdbl("z:\t", NULL);

	x =	normal_X(a, b, z);

	printf("\nx = %Lf\n", x);
}

void			dist_normal_m		(long double a, long double b)
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

void			dist_normal		(void)
{
	long double	u;
	long double	o2;
	long double	o;
	long double	a;
	long double	b;

	printf("\n_______________________________________________________________________________________________________________\n");
	printf("\nESTADISTICA/Distribuciones:\tDistribucion Normal (Gauss): N(u,o2)\n\n");

	printf("X -> N(u,o2)\n");
	printf("u\t=\t\t--Esperanza de X.\n");
	printf("o2\t=\t\t--Varianza de X.\n\n");
	printf("o\t=\t\t--Desviacion tipica de X.\n\n");

	printf("Z = aX + b\n");
	printf("Z -> N(0,1)\n");
	printf("a\t= 1/o\n");
	printf("b\t= -u/o\n\n");

	u =	alx_getdbl("u:\t", NULL);
	o2 =	alx_getdbl_m(0, 1, "o2:\t", NULL);

	o =	normal_o(o2);
	a =	normal_A(o);
	b =	normal_B(u, o);

	printf	("\na\t= %Lf\nb\t= %Lf\n", a, b);

	dist_normal_m	(a, b);
getchar();
}
