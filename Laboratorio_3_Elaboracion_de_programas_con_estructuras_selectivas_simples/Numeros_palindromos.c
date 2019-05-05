#include <stdio.h>

int main() {
	int numero;
	scanf("%d", &numero);
	if (10 <= numero && numero <= 99) {
		int invertido = 10 * (numero % 10) + (numero / 10);
		int suma = numero + invertido;
		int es_palindromo = 0;
		
		/* Guardare las cifras de las unidades, decenas y centenas para analizar si es palindromo */
		int u, d, c;
		int copia = suma;
		u = copia % 10;
		copia /= 10;
		d = copia % 10;
		copia /= 10;
		c = copia % 10;
		
		/* La suma tiene 2 cifras o 3 cifras */
		if (suma >= 100) {
			if (u == c) {
				es_palindromo = 1;
			}
		} else {
			if (u == d) {
				es_palindromo = 1;
			}
		}
		if (es_palindromo) {
			printf("Se encontro el palindromo %d.\n", suma);
		} else {
			printf("No se encontro el palindromo.\n");
		}
	} else {
		printf("El numero ingresado no tiene 2 cifras.\n");
	}
	return 0;
}
