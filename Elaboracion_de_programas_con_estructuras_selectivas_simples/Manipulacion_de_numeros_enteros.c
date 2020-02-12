#include <stdio.h>

int main() {
	/* El numero que analizaremos necesariamente debe tener 3 digitos*/
	int numero;
	printf("Ingrese el numero de 3 digitos: ");
	scanf("%d", &numero);
	
	/* Verificacion de que el numero tenga 3 cifras*/
	if ((-999 <= numero && numero <= -100) || (100 <= numero && numero <= 999)) {
		/* Voy a leer la accion a realizar A o I*/
		char manipulacion;
		printf("Ingrese opcion: ");
		scanf("%*c%c", &manipulacion);
		int tiene_signo;
		if (numero < 0) {
			tiene_signo = 1;
			numero *= (-1);
		}
		else tiene_signo = 0;
		int c, d, u;
		u = numero % 10;
		numero /= 10;
		d = numero % 10;
		numero /= 10;
		c = numero % 10;
		numero /= 10;
		if (manipulacion == 'A') {
			int suma_digitos_cubo = u * u * u + d * d * d + c * c * c;
			printf("La suma de digitos al cubo es %d.\n", suma_digitos_cubo);
		} else {
			if (manipulacion == 'I') {
				int numero_invertido = 100 * u + 10 * d + c;
				if (tiene_signo) numero_invertido *= (-1);
				printf("El numero invertido es %d.\n", numero_invertido);		
			} else {
				printf("Opcion invalida.\n");
			}
		}
	} else {
		printf("El numero ingresado no tiene 3 cifras. Por lo tanto, el programa terminara.\n");
	}
	return 0;
}
