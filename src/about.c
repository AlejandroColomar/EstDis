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

	#include <curses.h>
	#include <stdbool.h>
	#include <stdint.h>
	#include <stdio.h>

	#include "macros.h"


void	print_help		(void)
{
	printf(PROG_NAME "\n\n");
}

void	print_version	(void)
{
	printf("Version:\t" PROG_VERS "\n\n");
}

void	print_usage		(void)
{
	printf("Usage: TO BE WRITTEN\n");
	printf("Help:\n");
	printf("$ ./exe --help\n");
	printf("or\n");
	printf("$ ./exe -h\n\n");
}

void	print_cpright	(void)
{
	printf("\n________________________________________________________________________________");
	printf("\n");
	printf("\n\t" PROG_NAME "   \tCopyright (C) " PROG_YEAR "   \tAlejandro COLOMAR ANDRES");
	printf("\n");
	printf("\n\tThis program comes with ABSOLUTELY NO WARRANTY.");
	printf("\n\tThis is free software, and you are welcome to redistribute it");
	printf("\n\tunder certain conditions; use --license to see the full licence.");
	printf("\n________________________________________________________________________________");
	printf("\n\n");
}

void	w_print_cpright	(bool nul)
{
	WINDOW *win;

	win =	newwin(24, 80, 0, 0);

	waddstr(win, "\n________________________________________________________________________________");
	waddstr(win, "\n");
	waddstr(win, "\n\t" PROG_NAME "   \tCopyright (C) " PROG_YEAR "   \tAlejandro COLOMAR ANDRES");
	waddstr(win, "\n");
	waddstr(win, "\n\tThis program comes with ABSOLUTELY NO WARRANTY.");
	waddstr(win, "\n\tThis is free software, and you are welcome to redistribute it");
	waddstr(win, "\n\tunder certain conditions; use --license to see the full licence.");
	waddstr(win, "\n________________________________________________________________________________");
	waddstr(win, "\n\n");
	wrefresh(win);
	wgetch(win);

	wclear(win);
	wrefresh(win);
	delwin(win);
}

void	print_disclaim	(void)
{
	printf("\n________________________________________________________________________________");
	printf("\n");
	printf("\n\tDisclaimer of Warranty.");
	printf("\n");
	printf("\nTHERE IS NO WARRANTY FOR THE PROGRAM, TO THE EXTENT PERMITTED BY");
	printf("\nAPPLICABLE LAW.  EXCEPT WHEN OTHERWISE STATED IN WRITING THE COPYRIGHT");
	printf("\nHOLDERS AND/OR OTHER PARTIES PROVIDE THE PROGRAM \"AS IS\" WITHOUT WARRANTY");
	printf("\nOF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO,");
	printf("\nTHE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR");
	printf("\nPURPOSE.  THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE PROGRAM");
	printf("\nIS WITH YOU.  SHOULD THE PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF");
	printf("\nALL NECESSARY SERVICING, REPAIR OR CORRECTION.");
	printf("\n________________________________________________________________________________");
	printf("\n\n");
}

void	w_print_disclaim	(void)
{
	WINDOW *win;

	win =	newwin(24, 80, 0, 0);

	waddstr(win, "\n________________________________________________________________________________");
	waddstr(win, "\n");
	waddstr(win, "\n\tDisclaimer of Warranty.");
	waddstr(win, "\n");
	waddstr(win, "\nTHERE IS NO WARRANTY FOR THE PROGRAM, TO THE EXTENT PERMITTED BY");
	waddstr(win, "\nAPPLICABLE LAW.  EXCEPT WHEN OTHERWISE STATED IN WRITING THE COPYRIGHT");
	waddstr(win, "\nHOLDERS AND/OR OTHER PARTIES PROVIDE THE PROGRAM \"AS IS\" WITHOUT WARRANTY");
	waddstr(win, "\nOF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO,");
	waddstr(win, "\nTHE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR");
	waddstr(win, "\nPURPOSE.  THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE PROGRAM");
	waddstr(win, "\nIS WITH YOU.  SHOULD THE PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF");
	waddstr(win, "\nALL NECESSARY SERVICING, REPAIR OR CORRECTION.");
	waddstr(win, "\n________________________________________________________________________________");
	waddstr(win, "\n\n");
	wrefresh(win);
	wgetch(win);

	wclear(win);
	wrefresh(win);
	delwin(win);
}

void	dist_binomial_help		(void){
	printf("\n________________");
	printf("\n\t\tBinomial\tX -> B(n,p):\n");
	printf("Supongase que un experimento aleatorio, consistente en observar si un ");
	printf("determinado suceso ocurre o no, se realiza n veces consecutivas (obteniendose n ");
	printf("realizaciones independientes del experimento aleatorio).\nSea p la probabilidad ");
	printf("de que ocurra el suceso A, esto es, P(A)=p y P(!A)=1-p=q. La v.a. X definida ");
	printf("como el numero de veces que ocurre el suceso A en las n realizaciones ");
	printf("independientes del experimento aleatorio.\nSe dice que tiene una distribucion ");
	printf("binomial de parametros n y p, cuya funcion de probabilidad viene dada por\n");
	printf("\tP{X=x} =\t(n  x)*p^x*(1-p)^(n-x)\tx = 0, 1, 2, ..., n.\n");
	printf("\tE[x] =\tn*p\n");
	printf("\tVar[X] =\tn*p*(1-)\n");
}

void	dist_poisson_help		(void){
	printf("\n________________");
	printf("\n\t\tPoisson\t\tX -> P(l):\n");
	printf("Las vv.aa. asociadas a distribuciones de Poisson suelen representar el numero de ");
	printf("sucesos aleatorios independientes que ocurren con velocidad constante en el ");
	printf("tiempo o en el espacio.\n");
	printf("Sea l el promedio de ocurrencias del suceso aleatorio de interes por unidad de ");
	printf("tiempo (espacio) y X la v.a. igual al numero de veces que ha ocurrido el suceso ");
	printf("en un intervalo de tiempo(espacio) escogido al azar.\nSe dice que X tiene ");
	printf("distribucion de Poisson de parametro l (con l>0) y su f.m.p. viene dada por\n");
	printf("\tP{X=x} =\te^(-l)*l^x/x!\tx = 0, 1, 2, ...\n");
	printf("\tE[x] =\t\tl\n");
	printf("\tVar[X] =\tl\n");
	printf("Criterio de aproximacion (Binomial -> Poisson):\tn >= 25,\tp <= 0.1,\tn*p <= 5;\t\tl = n*p\n");
}

void	dist_geometric_help		(void){
	printf("\n________________");
	printf("\n\t\tGeometrica\tX -> G(p):\n");
	printf("Considerese un experimento aleatorio en el que se observa si ocurre o no un ");
	printf("determinado suceso, siendo la probabilidad de exito p.\nSea: ");
	printf("X la v.a. que cuenta el numero de veces que debe realizarse el experimento ");
	printf("hasta que ocurre por primera vez el suceso de interes.\n");
	printf("Entonces, se dice que X tienen una distribucion geometrica de ");
	printf("parametro p, estando sus f.m.p. dadas por las siguientes expresiones:\n");
	printf("\tP{X=x} =\tp*(1-p)^(x-1)\tx = 1, 2, ...\n");
	printf("\tE[x] =\t\t1/p\n");
	printf("\tVar[X] =\t(1-p)/p^2\n");
}

void	dist_hypergeometric_help	(void){
	printf("\n________________");
	printf("\n\t\tHipereometrica\tX -> H(N,n,r):\n");
	printf("Una v.a. se dice que tiene distribucion hipergeometrica de parametros N, n y r ");
	printf("si su f.m.p.es\n");
	printf("\tP{X=x} =\t(r  n)*(N-r  n-x)/(N  n)\tmax{0, n-N+r)} <= x <= min{n, r}\tN, n, r c R\n");
	printf("Esta distribucion esta asociada al muestreo aleatorio sin reemplazamiento. ");
	printf("Concretamente, las vv.aa. con esta distribucion\ncuentan el numero de elementos ");
	printf("con una cierta caracteristica en un experimento consistente en elegir n elementos ");
	printf("de una poblacion de N de los cuales solo r poseen la caracteristica deseada.\n");
	printf("\tE[x] =\t\tr*n/N\n");
	printf("\tVar[X] =\tn*r*(N-r)*(N-n)/[N^2*(N-1)]\n");
	printf("Criterio de aproximacion (Hipergeometrica -> Binomial):\tn < 0.1*N;\t\tp = r/N\n");
}

void	dist_uniform_help		(void){
	printf("\n________________");
	printf("\n\t\tUniforme\tX -> U(a,b):\n");
	printf("Se dice que una v.a. X tiene distribucion uniforme dentro del intervalo (a, b) si su ");
	printf("funcion de densidad viene dada por\n");
	printf("\t\t\t1/(b-a)\t\ta < x < b\n");
	printf("\tf(x) = {\n");
	printf("\t\t\t0\t\telse\n");
	printf("Asi pues, la probabilidad de que X este en el intervalo [a, b] sera 1 y la ");
	printf("probabilidad de que este en un subintervalo sera proporcional a su longitud.\n");
	printf("\t\t\t0\t\tx < a\n");
	printf("\tF(x) = {\t(x-a)/(b-a)\ta <= x <= b\n");
	printf("\t\t\t0\t\tx > b\n");
	printf("\tE[x] =\t\t(a+b)/2\n");
	printf("\tVar[X] =\t(b-a)^2/12\n");
}

void	dist_exponential_help		(void){
	printf("\n________________");
	printf("\n\t\tExponencial\tX -> exp(b):\n");
	printf("Se dice que una v.a. X tiene distribucion exponencial con parametro b > 0 si su ");
	printf("funcion de densidad viene dada por\n");
	printf("\t\t\t0\t\tx < 0\n");
	printf("\tf(x) = {\n");
	printf("\t\t\tb*e^(-b*x)\t\tx >= 0\n");
	printf("Este tipo de v.a. se utiliza generlmente para modelizar tiempos de vida o medir ");
	printf("el tiempo entre dos ocurrencias consecutivas de un suceso que ocurre b veces ");
	printf("por unidad de tiempo.\n");
	printf("\t\t\t0\t\tx < 0\n");
	printf("\tF(x) = {\n");
	printf("\t\t\t1-e^(-b*x)\t\tx >= 0\n");
	printf("\tE[x] =\t\t1/b\n");
	printf("\tVar[X] =\t1/b^2\n");
	printf("\tP{X>=x+t/X>=t}\t= P{X>=x}\n");
}
