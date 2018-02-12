#include	<stdio.h>
#include	<math.h>
// Cálculos:
	// Calcula		factoriales:
			long double		fact	(unsigned n){
				return	(n==1 || !n)	?	1:	n * fact(n - 1);
			}

	// Calcula		a sobre b:				--!!!--a debe ser mayor que b--!!!--
			long double		sobre	(unsigned a, unsigned b){
				unsigned	i;
				long double	c = 1;
				i = 1;
				while	(a > b){
					c = c * a-- / i++;
				}
				return	c;
			}

// Solicitudes:
	// Solicita		Z >=m:
			int		getZm	(int m){
				long double	sf;
				unsigned	i;
				int		Z;
				char		r = 1;
				printf	("Introduce un Entero [%i U inf:...\t", m);
				for	(i = 0; i < 3 && r; i ++){
					scanf	(" %Lf", &sf);
					Z =	sf;
					if	(sf < m || sf != Z){
						printf	("No es valido...\t");
						Z =	0;
					}else
						r =	0;
				}
				return	Z;
			}

	// Solicita		M>= Z >=m:
			int		getZmM	(int m, int M){
				long double	sf;
				unsigned	i;
				int		Z;
				char		r = 1;
				printf	("Introduce un Entero [%i U %i]:...\t", m, M);
				for	(i = 0; i < 3 && r; i++){
					scanf	("%Lf", &sf);
					Z =	sf;
					if	(sf < m || sf != Z || sf > M){
						printf	("No es valido...\t");
						Z =	0;
					}else
						r =	0;
				}
				return	Z;
			}

	// Solicita		R >m:
			long double	getRm	(int m){
				unsigned	i;
				long double	R;
				char		r = 1;
				printf	("Introduce un Real (%i U inf):...\t\t", m);
				for	(i = 0; i < 3 && r; i++){
					scanf	("%Lf", &R);
					if	(R <= m){
						printf	("No es valido...\t");
						R =	0;
					}else
						r =	0;
				}
				return	R;
			}

	// Solicita		M>= R >m:
			long double	getRmM	(int m, int M){
				unsigned	i;
				long double	R;
				char		r = 1;
				printf	("Introduce un Real (%i U %i):...\t\t", m, M);
				for	(i = 0; i < 3 && r; i++){
					scanf	("%Lf", &R);
					if	(R <= m || R >= M){
						printf	("No es valido...\t");
						R =	0;
					}else
						r =	0;
				}
				return	R;
			}
// Distribuciones:
	// Dist. Binomial	B(n,p):
		// Calcula PB:
			long double		D_B_P	(unsigned int n, unsigned int c, long double p){
				unsigned	x,	a,	b,	i;
				long double	Pi,	P = 0,	pex,	penx,	snx;

				if	(c){
					for	(i = 0; i < c; i++){
						printf	("x_%u:\t", i+1);						// Solicita x.
						x =	getZmM	(0, n);

						pex =	pow	(p, x);
						penx =	pow	(1 - p, n - x);
						snx =	sobre	(n, x);

						Pi =	(snx)*pex*penx;
						printf	("P_%u\t= %Lf\n", i+1, Pi);
						P +=	Pi;
					}
				}else{
					printf	("a:\t");								// Solicita a.
					a =	getZmM	(0, n);
					printf	("b:\t");								// Solicita b.
					b =	getZmM	(a + 1, n);

					for	(; a <= b; a++){
						pex =	pow	(p, a);
						penx =	pow	(1 - p, n - a);
						snx =	sobre	(n, a);

						Pi =	(snx)*pex*penx;
						printf	("P_%u\t= %Lf\n", a, Pi);
						P +=	Pi;
				}	}
				return	P;
			}

		// Ppal:
			void			D_B	(void){
				unsigned	n,	c;
				long double	p,	P = 0,	E,	Var;

				printf	("\n_______________________________________________________________________________________________________________\n");
				printf	("\nESTADISTICA/Distribuciones:\tDistribucion Binomial: B(n,p)\n\n");

				printf	("n = numero de veces que se repite el experimento (con reemplazamiento)\n");
				printf	("p = probabilidad del suceso individual\n");
				printf	("c = cantidad de x que interesan (inroducir [0] para intervalo [a U b])\n");
				printf	("x = numero de veces que interesa que ocurra el suceso\n\n");

				printf	("n:\t");								// Solicita n.
				n =	getZm	(1);
				printf	("p:\t");								// Solicita p.
				p =	getRmM	(0, 1);
				printf	("c:\t");								// Solicita c.
				c =	getZmM	(0, n+1);

				P =	D_B_P	(n, c, p);
				E =	n * p;
				Var =	n * p * (1 - p);
				printf	("\nP{X}\t= %Lf\nE(X)\t= %Lf\nVar(X)\t= %Lf\n", P, E, Var);

				if	(n*p > 5 && n*(1-p) > 5){
					printf	("\nAproximacion a Distribucion Normal N(u = np, o2 = np(1-p))\n");
					printf	("u\t= %Lf\n", E);
					printf	("o2\t= %Lf\n", Var);
				}
			}

	// Dist. de Poisson	P(l):

		// Calcula PP:
			long double		D_P_P	(long double l, unsigned int c){
				unsigned	x,	a,	b,	i;
				long double	Pi,	P = 0,	eel,	lex,	fx;

				if	(c){
					for	(i = 0; i < c; i++){
						printf	("x_%u:\t", i+1);						// Solicita x.
						x =	getZm	(0);

						eel =	exp	(-l);
						lex =	pow	(l, x);
						fx =	fact	(x);

						Pi =	eel*lex/fx;
						printf	("P_%u\t= %Lf\n", i+1, Pi);
						P +=	Pi;
					}
				}else{
					printf	("a:\t");								// Solicita a.
					a =	getZm	(0);
					printf	("b:\t");								// Solicita b.
					b =	getZm	(a + 1);

					for	(; a <= b; a++){
						eel =	exp	(-l);
						lex =	pow	(l, a);
						fx =	fact	(a);

						Pi =	eel*lex/fx;
						printf	("P_%u\t= %Lf\n", a, Pi);
						P +=	Pi;
				}	}
				return	P;
			}

		// Ppal:
			void			D_P	(void){
				unsigned	c;
				long double	l,	P;

				printf	("\n_______________________________________________________________________________________________________________\n");
				printf	("\nESTADISTICA/Distribuciones:\tDistribucion de Poisson: P(l)\n\n");

				printf	("l = veces que ocurre de media/ud. de tiempo\n");
				printf	("x = veces que interesa que ocurra X/ud. de tiempo\n\n");

				printf	("l:\t");									// Solicita l.
				l =	getRm	(0);
				printf	("c:\t");									// Solicita c.
				c =	getZm	(0);

				P =	D_P_P	(l, c);

				printf	("\nP{X}\t= %Lf\nE(X)\t= %Lf\nVar(X)\t= %Lf\n", P, l, l);
			}

	// Dist. Geométrica	G(p):
			void			D_G	(void){
				unsigned	x;
				long double	p,	pex,	P,	E,	Var;

				printf	("\n_______________________________________________________________________________________________________________\n");
				printf	("\nESTADISTICA/Distribuciones:\tDistribucion Geometrica: G(p)\n\n");

				printf	("p = probabilidad del suceso cada repeticion\n");
				printf	("x = vez que interesa que ocurra el suceso\n\n");

				printf	("p:\t");									// Solicita p.
				p =	getRmM	(0, 1);
				printf	("x:\t");									// Solicita x.
				x =	getZm	(1);

				pex =	pow	(1-p, x-1);

				P =	p*pex;
				E =	1/p;
				Var =	(1-p)/(p*p);

				printf	("\nP{X=x}\t= %Lf\nE(X)\t= %Lf\nVar(X)\t= %Lf\n", P, E, Var);
			}

	// Dist. Uniforme	U(a,b):
			void			D_U	(void){
				long double	a,	b,	x1,	x2,	P,	E,	Var;

				printf	("\n_______________________________________________________________________________________________________________\n");
				printf	("\nESTADISTICA/Distribuciones:\tDistribucion Uniforme: U(p)\n\n");

				printf	("a = limite inferior de la distribucion.\n");
				printf	("b = limite superior de la distribucion.\n");
				printf	("x1 = limite inferior de interes.\n");
				printf	("x2 = limite superior de interes.\n\n");

				printf	("a:\tIntroduce un Real\t\t");							// Solicita a.
				scanf	("%Lf", &a);
				printf	("b:\t");									// Solicita b.
				b =	getRm	(a);
				printf	("x1:\t");									// Solicita x1.
				x1 =	getRmM	(a, b);
				printf	("x2:\t");									// Solicita x2.
				x2 =	getRmM	(x1, b);

				P =	(x2-x1)/(b-a);
				E =	(a+b)/2;
				Var =	(b-a)*(b-a)/12;

				printf	("\nP{x1<X<x2}\t= %Lf\nE(X)\t\t= %Lf\nVar(X)\t\t= %Lf\n", P, E, Var);
			}

	// Dist. Exponencial	exp(b):
			void			D_exp	(void){
				long double	x1,	x2,	b,	c,	P1,	P0,	E,	Var,	eebx1,	eebx2;

				printf	("\n_______________________________________________________________________________________________________________\n");
				printf	("\nESTADISTICA/Distribuciones:\tDistribucion Exponencial: exp(b)\n\n");

				printf	("b = coeficiente beta\n");
				printf	("x = tiempo para que ocurra el suceso\n\n");

				printf	("b:\t");									// Solicita p.
				b =	getRm	(0);
				printf	("Intervalo (x1 U x2)[0]\t\tIntervalo (0 U x)[1]\n");									// Solicita p.
				c =	getZmM	(0, 1);
				if	(c)
					printf	("x:\t");									// Solicita x.
				else
					printf	("x1:\t");
				x1 =	getRm	(0);
				if	(!c){
					printf	("x2:\t");
					x2 =	getRm	(x1);
				}
				
				eebx1 =	exp	(-b*x1);
				eebx2 =	exp	(-b*x2);

				if	(c){
					P1 =	1-eebx1;
					printf	("\nP{X<x}\t= %Lf\nP{X>x}\t= %Lf\n", P1, eebx1);
				}else{
					P0 =	eebx1-eebx2;
					printf	("\nP{x1<X<x2}\t= %Lf\n", P0);
				}

				E =	1/b;
				Var =	1/(b*b);

				printf	("\nE(X)\t= %Lf\nVar(X)\t= %Lf\n", E, Var);
			}

	// Dist. Gauss(Normal)	N(u,s2):
		// Menu			D_N_m:
			// Opcion1	D_N_m_1(a,b):
			void			D_N_m_1	(long double a, long double b){
				long double	x,	z;

				printf	("Z = aX + b\n", a, b);

				printf	("x:\tIntroduce un Real\t");					// Solicita x.
				scanf	("%Lf", &x);

				z =	a*x+b;

				printf	("\nz = %Lf\n", z);
			}
			// Opcion2	D_N_m_2(a,b):
			void			D_N_m_2	(long double a, long double b){
				long double	x,	z;

				printf	("X = (Z-b)/a\n", a, b);

				printf	("z:\tIntroduce un Real\t");					// Solicita y.
				scanf	("%Lf", &z);

				x =	(z-b)/a;

				printf	("\nx = %Lf\n", x);
			}
			// Ppal		D_N_m(a,b):
			void			D_N_m	(long double a, long double b){
				unsigned	i,	wh = 1;
				while	(wh){
					printf	("\nTipificar:\n");
					printf	("X -> Z [1]\tZ -> X [2]\tExit[0]\n");

					i =	getZmM	(0, 2);
					switch	(i){							// Menu distribuciones
						case	0:
							wh =	0;
							break;
						case	1:
							D_N_m_1	(a, b);
							break;
						case	2:
							D_N_m_2	(a, b);
							break;
			}	}	}

		// Ppal			D_N():
			void			D_N	(void){
				long double	u,	o2,	o,	a,	b;

				printf	("\n_______________________________________________________________________________________________________________\n");
				printf	("\nESTADISTICA/Distribuciones:\tDistribucion Normal (Gauss): N(u,o2)\n\n");

				printf	("X -> N(u,o2)\n");
				printf	("u\t=\t\t--Esperanza de X.\n");
				printf	("o2\t=\t\t--Varianza de X.\n\n");
				printf	("o\t=\t\t--Desviacion tipica de X.\n\n");

				printf	("Z = aX + b\n");
				printf	("Z -> N(0,1)\n");
				printf	("a\t= 1/o\n");
				printf	("b\t= -u/o\n\n");

				printf	("u:\tIntroduce un Real\t\t");						// Solicita u.
				scanf	("%Lf", &u);
				printf	("o2:\t");								// Solicita s2.
				o2 =	getRm	(0);

				o =	sqrt	(o2);
				a =	1/o;
				b =	-u/o;

				printf	("\na\t= %Lf\nb\t= %Lf\n", a, b);

				D_N_m	(a, b);
			}

	// Ppal				D():
		// Ayuda:
			//Ayuda DB	D_B_h():
			void			D_B_h	(void){
				printf	("\n________________");
				printf	("\n\t\tBinomial\tX -> B(n,p):\n");
				printf	("Supongase que un experimento aleatorio, consistente en observar si un ");
				printf	("determinado suceso ocurre o no, se realiza n veces consecutivas (obteniendose n ");
				printf	("realizaciones independientes del experimento aleatorio).\nSea p la probabilidad ");
				printf	("de que ocurra el suceso A, esto es, P(A)=p y P(!A)=1-p=q. La v.a. X definida ");
				printf	("como el numero de veces que ocurre el suceso A en las n realizaciones ");
				printf	("independientes del experimento aleatorio.\nSe dice que tiene una distribucion ");
				printf	("binomial de parametros n y p, cuya funcion de probabilidad viene dada por\n");
				printf	("\tP{X=x} =\t(n  x)*p^x*(1-p)^(n-x)\tx = 0, 1, 2, ..., n.\n");
				printf	("\tE[x] =\tn*p\n");
				printf	("\tVar[X] =\tn*p*(1-)\n");
			}

			//Ayuda DP	D_P_h():
			void			D_P_h	(void){
				printf	("\n________________");
				printf	("\n\t\tPoisson\t\tX -> P(l):\n");
				printf	("Las vv.aa. asociadas a distribuciones de Poisson suelen representar el numero de ");
				printf	("sucesos aleatorios independientes que ocurren con velocidad constante en el ");
				printf	("tiempo o en el espacio.\n");
				printf	("Sea l el promedio de ocurrencias del suceso aleatorio de interes por unidad de ");
				printf	("tiempo (espacio) y X la v.a. igual al numero de veces que ha ocurrido el suceso ");
				printf	("en un intervalo de tiempo(espacio) escogido al azar.\nSe dice que X tiene ");
				printf	("distribucion de Poisson de parametro l (con l>0) y su f.m.p. viene dada por\n");
				printf	("\tP{X=x} =\te^(-l)*l^x/x!\tx = 0, 1, 2, ...\n");
				printf	("\tE[x] =\t\tl\n");
				printf	("\tVar[X] =\tl\n");
				printf	("Criterio de aproximacion (Binomial -> Poisson):\tn >= 25,\tp <= 0.1,\tn*p <= 5;\t\tl = n*p\n");
			}

			//Ayuda DG	D_G_h():
			void			D_G_h	(void){
				printf	("\n________________");
				printf	("\n\t\tGeometrica\tX -> G(p):\n");
				printf	("Considerese un experimento aleatorio en el que se observa si ocurre o no un ");
				printf	("determinado suceso, siendo la probabilidad de exito p.\nSea: ");
				printf	("X la v.a. que cuenta el numero de veces que debe realizarse el experimento ");
				printf	("hasta que ocurre por primera vez el suceso de interes.\n");
				printf	("Entonces, se dice que X tienen una distribucion geometrica de ");
				printf	("parametro p, estando sus f.m.p. dadas por las siguientes expresiones:\n");
				printf	("\tP{X=x} =\tp*(1-p)^(x-1)\tx = 1, 2, ...\n");
				printf	("\tE[x] =\t\t1/p\n");
				printf	("\tVar[X] =\t(1-p)/p^2\n");
			}

			//Ayuda DH	D_H_h():
			void			D_H_h	(void){
				printf	("\n________________");
				printf	("\n\t\tHipereometrica\tX -> H(N,n,r):\n");
				printf	("Una v.a. se dice que tiene distribucion hipergeometrica de parametros N, n y r ");
				printf	("si su f.m.p.es\n");
				printf	("\tP{X=x} =\t(r  n)*(N-r  n-x)/(N  n)\tmax{0, n-N+r)} <= x <= min{n, r}\tN, n, r c R\n");
				printf	("Esta distribucion esta asociada al muestreo aleatorio sin reemplazamiento. ");
				printf	("Concretamente, las vv.aa. con esta distribucion\ncuentan el numero de elementos ");
				printf	("con una cierta caracteristica en un experimento consistente en elegir n elementos ");
				printf	("de una poblacion de N de los cuales solo r poseen la caracteristica deseada.\n");
				printf	("\tE[x] =\t\tr*n/N\n");
				printf	("\tVar[X] =\tn*r*(N-r)*(N-n)/[N^2*(N-1)]\n");
				printf	("Criterio de aproximacion (Hipergeometrica -> Binomial):\tn < 0.1*N;\t\tp = r/N\n");
			}

			//Ayuda DU	D_U_h():
			void			D_U_h	(void){
				printf	("\n________________");
				printf	("\n\t\tUniforme\tX -> U(a,b):\n");
				printf	("Se dice que una v.a. X tiene distribucion uniforme dentro del intervalo (a, b) si su ");
				printf	("funcion de densidad viene dada por\n");
				printf	("\t\t\t1/(b-a)\t\ta < x < b\n");
				printf	("\tf(x) = {\n");
				printf	("\t\t\t0\t\telse\n");
				printf	("Asi pues, la probabilidad de que X este en el intervalo [a, b] sera 1 y la ");
				printf	("probabilidad de que este en un subintervalo sera proporcional a su longitud.\n");
				printf	("\t\t\t0\t\tx < a\n");
				printf	("\tF(x) = {\t(x-a)/(b-a)\ta <= x <= b\n");
				printf	("\t\t\t0\t\tx > b\n");
				printf	("\tE[x] =\t\t(a+b)/2\n");
				printf	("\tVar[X] =\t(b-a)^2/12\n");
			}

			//Ayuda Dexp	D_exp_h():
			void			D_exp_h	(void){
				printf	("\n________________");
				printf	("\n\t\tExponencial\tX -> exp(b):\n");
				printf	("Se dice que una v.a. X tiene distribucion exponencial con parametro b > 0 si su ");
				printf	("funcion de densidad viene dada por\n");
				printf	("\t\t\t0\t\tx < 0\n");
				printf	("\tf(x) = {\n");
				printf	("\t\t\tb*e^(-b*x)\t\tx >= 0\n");
				printf	("Este tipo de v.a. se utiliza generlmente para modelizar tiempos de vida o medir ");
				printf	("el tiempo entre dos ocurrencias consecutivas de un suceso que ocurre b veces ");
				printf	("por unidad de tiempo.\n");
				printf	("\t\t\t0\t\tx < 0\n");
				printf	("\tF(x) = {\n");
				printf	("\t\t\t1-e^(-b*x)\t\tx >= 0\n");
				printf	("\tE[x] =\t\t1/b\n");
				printf	("\tVar[X] =\t1/b^2\n");
				printf	("\tP{X>=x+t/X>=t}\t= P{X>=x}\n");
			}

		// Menu D		D():
			char			D	(void){
				unsigned	i,	wh = 1;
				while	(wh){
					printf	("\n_______________________________________________________________________________________________________________\n");
					printf	("\nESTADISTICA:\tDistribuciones\n");

					printf	("\nBinomial[1] -h[2]\tPoisson[3] -h[4]\tGeometrica[5] -h[6]\tHipergeometrica[] -h[8]\t");
					printf	("Uniforme[9] -h[10]\tExponencial[11] -h[12]\tGauss(Normal)[13] -h[]\tExit[0]\t\t-h = help\n");

					i =	getZmM	(0, 14);
					switch	(i){									// Menu distribuciones
						case	0:
							wh =	0;
							break;
						case	1:
							D_B_h	();
							D_B	();
							break;
						case	2:
							D_B_h	();
							break;
						case	3:
							D_P_h	();
							D_P	();
							break;
						case	4:
							D_P_h	();
							break;
						case	5:
							D_G_h	();
							D_G	();
							break;
						case	6:
							D_G_h	();
							break;
						case	7:
							D_H_h	();
							break;
						case	8:
							D_H_h	();
							break;
						case	9:
							D_U_h	();
							D_U	();
							break;
						case	10:
							D_U_h	();
							break;
						case	11:
							D_exp_h	();
							D_exp	();
							break;
						case	12:
							D_exp_h	();
							break;
						case	13:
							D_N	();
							break;
						case	14:
							break;
			}	}	}

// Estadística Descriptiva:
	// 1 Variable			ED_1V():
			void			ED_1V	(void){
				unsigned	n,	i;
				long double	ni,	En = 0,	Ex = 0,	Ex2 = 0,	u,	o2,	o,	s2,	s,	CV;

				printf	("\n_______________________________________________________________________________________________________________\n");
				printf	("u\t= E(ni*xi)/n\t--Media.\n");
				printf	("o2\t= E(xi^2)/n-u^2\t--Varianza.\n");
				printf	("s2\t= o2*n/(n-1)\t--Cuasivarianza.\n");
				printf	("o\t= sqrt(o2)\t--Desviacion tipica.\n");
				printf	("s\t= sqrt(s2)\t--Cuasidesviacion tipica.\n");
				printf	("CV\t= o/u\t\t--Coeficiente de variacion.\n\n");

				printf	("n:\t");									// Solicita n.
				n =	getZm	(1);

				long double	x[n];
				for	(i = 0; i < n; i ++){
					printf	("x_%u:\tIntroduce un Real:...\t\t\t", i+1);				// Solicita xi.
					scanf	("%Lf", &x[i]);
					printf	("n_%u:\t", i+1);							// Solicita ni.
					ni =	getRm	(0);
					Ex +=	ni*x[i];
					Ex2 +=	ni*x[i]*x[i];
					En +=	ni;
				}

				u =	Ex/En;
				o2 =	Ex2/En-u*u;
				o =	sqrt	(o2);
				s2 =	o2*En/(En-1);
				s =	sqrt	(s2);
				CV =	o/u;

				printf	("\nu\t= %Lf\no2\t= %Lf\no\t= %Lf\ns2\t= %Lf\ns\t= %Lf\nCV\t= %Lf\n", u, o2, o, s2, s, CV);
			}

	// 2 Variables			ED_2V():
			void			ED_2V	(void){
				unsigned	n,	i;
				long double	Ex = 0,	Ex2 = 0,	ux,	ox2,	ox,	a,	Aa,	b,	Ab,
						Ey = 0,	Ey2 = 0,	uy,	oy2,	oy,	c,	Ac,	d,	Ad,
						Exy = 0,	oxy,	r,	yy2,	xx2,	Eyy2 = 0,	Exx2 = 0,	Vr,	R2;

				printf	("\n_______________________________________________________________________________________________________________\n");
				printf	("u\t= E(xi)/n\t\t--Media.\n");
				printf	("o2\t= E(xi^2)/n-u^2\t\t--Varianza.\n");
				printf	("o\t= sqrt(o2)\t\t--Desviacion tipica.\n");
				printf	("oxy\t= E(xi*yi)/n-ux*uy\t--Covarianza.\n\n");

				printf	("a\t= oxy/ox2\t\t--Pendiente.\n");
				printf	("b\t= uy-a*ux\t\t--Sesgo.\n");
				printf	("r\t= oxy/(ox*oy)\t\t--Coeficiente de correlacion lineal.\n\n");

				printf	("n\t=\t\t\t--Numero de puntos.\n\n");

				printf	("n:\t");									// Solicita n.
				n =	getZm	(1);

				long double	x[n],	y[n];

				for	(i = 0; i < n; i++){
					printf	("x_%u:\tIntroduce un Real\t\t", i+1);					// Solicita xi.
					scanf	("%Lf", &x[i]);
					Ex +=	x[i];
					Ex2 +=	x[i]*x[i];

					printf	("y_%u:\tIntroduce un Real\t\t", i+1);					// Solicita yi.
					scanf	("%Lf", &y[i]);
					Ey +=	y[i];
					Ey2 +=	y[i]*y[i];

					Exy +=	x[i]*y[i];
				}

				ux =	Ex/n;
				ox2 =	Ex2/n-ux*ux;
				ox =	sqrt	(ox2);

				uy =	Ey/n;
				oy2 =	Ey2/n-uy*uy;
				oy =	sqrt	(oy2);

				oxy =	Exy/n-ux*uy;
				a =	oxy/ox2;
				b =	uy-a*ux;
				c =	oxy/oy2;
				d =	ux-c*uy;
				r =	oxy/(ox*oy);

				for	(i = 0; i < n; i++){
					yy2 =	pow	(y[i]-a*x[i]-b, 2);
					Eyy2 +=	yy2;

					xx2 =	pow	(x[i]-c*y[i]-d, 2);
					Exx2 +=	xx2;
				}

				Aa =	sqrt	(Eyy2/((n-2)*(Ex2-Ex*Ex/n)));
				Ab =	Aa*sqrt	(Ex2/n);

				Ac =	sqrt	(Exx2/((n-2)*(Ey2-Ey*Ey/n)));
				Ad =	Ac*sqrt	(Ey2/n);

				Vr =	Eyy2/n;
				R2 =	1-Vr/oy2;

				printf	("\nux\t= %Lf\nox2\t= %Lf\nox\t= %Lf\n", ux, ox2, ox);
				printf	("\nuy\t= %Lf\noy2\t= %Lf\noy\t= %Lf\n", uy, oy2, oy);
				printf	("\noxy\t= %Lf\na\t= %Lf\nAa\t= %Lf\nb\t= %Lf\nAb\t= %Lf\nc\t= %Lf\nAc\t= %Lf\nd\t= %Lf\nAd\t= %Lf\nr\t= %Lf\nVr\t= %Lf\nR2\t= %Lf\n", oxy, a, Aa, b, Ab, c, Ac, d, Ad, r, Vr, R2);
			}

	// Ppal				ED():
			void			ED	(void){
				unsigned	i,	wh = 1;
				while	(wh){
					printf	("\n_______________________________________________________________________________________________________________\n");
					printf	("\nESTADISTICA:\tDescriptiva\n");
					printf	("1 Variable[1]\t2 Variables[2]\tExit[0]\n");

					i =	getZmM	(0, 2);
					switch	(i){
						case	0:
							wh =	0;
							break;
						case	1:
							ED_1V	();
							break;
						case	2:
							ED_2V	();
							break;
					}
				}
			}

// MAIN
int	main	(void){
	unsigned	i,	wh = 1;
	while	(wh){

		printf	("\n_______________________________________________________________________________________________________________\n");
		printf	("\nESTADISTICA:\n");
		printf	("Descriptiva[1]\tDistribuciones[2]\tExit[0]\n");

		i =	getZmM	(0, 2);
		switch	(i){										// Menu ppal.
			case	0:
				wh =	0;
				break;
			case	1:
				ED	();
				break;
			case	2:
				D	();
				break;
		}
	}
	return	0;
}
