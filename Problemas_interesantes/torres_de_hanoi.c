#include<stdio.h>
#include<math.h>

/* En C no hay variables para guardar cadenas de texto, sino que debe construirse
   un arreglo de caracteres (tipo char). El tamaño del arreglo determina la longitud
   máxima que puede tener la cadena que guarda (tamaño-1, por el caracter de terminación).
   La constante MAX_STRLEN define el tamaño máximo que se utiliza en este programa para
   cualquier cadena. */
#define MAX_STRLEN 256

/* Para las variables que no se pudo determinar el tipo se utiliza la constante
   SIN_TIPO. El usuario debe reemplazar sus ocurrencias por el tipo adecuado
   (usualmente int,float,bool, o char[]). */
#define SIN_TIPO char[]

// Declaraciones adelantadas de las funciones
void hanoi(float n, SIN_TIPO a, SIN_TIPO b, SIN_TIPO c);

void hanoi(float n, SIN_TIPO a, SIN_TIPO b, SIN_TIPO c) {
	if ((n==1)) {
		printf("Mover de %s a %s\n",a,b);
	} else {
		hanoi(n-1,a,c,b);
		hanoi(1,a,b,c);
		hanoi(n-1,c,b,a);
	}
}

int main() {
	char a[MAX_STRLEN];
	char b[MAX_STRLEN];
	char c[MAX_STRLEN];
	int i;
	float n;
	int num;
	/* Este algoritmo permite indicar los movimientos que se deben realizar en el juego de las torres de Hanoi */
	/* es decir, para pasar los discos desde una torre origen hasta una torre destno, utilizando una torre auxiliar */
	/* Lectura */
	printf("Inserte el número de discos. Debe ser un entero mayor que 0 y menor que 9\n");
	do {
		scanf("%f",&n);
		if (n<=0 || n>=9 || n!=int(n)) {
			printf("Incorrecto, el número de discos debe ser entero mayor que 0 y menor que 9\n");
		}
	} while (!(n>0 && n<9 && n==int(n)));
	/* número mínimo de movimientos */
	num = 1;
	i = n;
	printf("\n");
	while ((i>0)) {
		num = num*2;
		i = i-1;
	}
	num = num-1;
	printf("El número mínimo de movimientos es %i\n",num);
	printf("\n");
	/* Pasos a seguir */
	strncpy(a, "ORIGEN", MAX_STRLEN);
	strncpy(b, "DESTINO", MAX_STRLEN);
	strncpy(c, "AUXILIAR", MAX_STRLEN);
	printf("\n");
	printf("Los pasos a seguir son los siguientes\n");
	hanoi(n,a,b,c);
	return 0;
}