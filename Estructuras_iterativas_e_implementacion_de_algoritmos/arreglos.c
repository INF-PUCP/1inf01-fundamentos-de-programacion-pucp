#include<stdio.h>
#include<time.h>

/* No hay en el C estandar una funcion equivalente a "esperar", pero puede programarse. */
void esperar(double t);

/* Para las variables que no se pudo determinar el tipo se utiliza la constante
   SIN_TIPO. El usuario debe reemplazar sus ocurrencias por el tipo adecuado
   (usualmente int,float,bool, o char[]). */
#define SIN_TIPO int

/* Para leer variables de texto se utiliza scanf, que lee solo una palabra. 
   Para leer una linea completa (es decir, incluyendo los espacios en blanco)
   se debe utilzar ges (ej, reemplazar scanf("%s",x) por gets(x)) pero 
   obliga a agregar un getchar() antes del gets si antes del mismo se leyó
   otra variable con scanf. */

int main() {
	SIN_TIPO arr[3][3];
	int i;
	int j;
	printf("Inserte 9 números enteros\n");
	for (i=1;i<=3;i+=1) {
		for (j=1;j<=3;j+=1) {
			printf("Elemento (%i %i)\n",i,j);
			scanf("%s",arr[i-1][j-1]);
		}
	}
	printf("Los números son:\n");
	esperar(1*1000);
	for (i=1;i<=3;i+=1) {
		for (j=1;j<=3;j+=1) {
			printf("Elemento (%i %i)\n",i,j);
			printf("%s\n",arr[i-1][j-1]);
		}
	}
	return 0;
}


void esperar(double t) {
	clock_t t0 = clock();
	double e = 0;
	do {
		e = 1000*double(clock()-t0)/CLOCKS_PER_SEC;
	} while (e<t);
}
