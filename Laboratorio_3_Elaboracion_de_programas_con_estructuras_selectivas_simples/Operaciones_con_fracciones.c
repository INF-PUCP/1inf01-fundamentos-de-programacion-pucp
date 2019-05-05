#include <stdio.h>

int main() {
	int numerador1, denominador1, numerador2, denominador2;
	scanf("%d %d %d %d", &numerador1, &denominador1, &numerador2, &denominador2);
	char operacion;
	scanf("%*c%c", &operacion);
	
	/* La division entre cero no esta definida en los numeros reales*/
	int valido = 1;
	if (denominador1 == 0 || denominador2 == 0) {
		valido = 0;
	}
	if (operacion == '/' && numerador2 == 0) {
		valido = 0;
	}
	
	if (valido) {
		int numerador, denominador;
		if (operacion == '+') {
			numerador = numerador1 * denominador2 + numerador2 * denominador1;
			denominador = denominador1 * denominador2;
		}
		if (operacion == '-') {
			numerador = numerador1 * denominador2 - numerador2 * denominador1;
			denominador = denominador1 * denominador2;
		}
		if (operacion == '*') {
			numerador = numerador1 * numerador2;
			denominador = denominador1 * denominador2;
		}
		if (operacion == '/') {
			numerador = numerador1 * denominador2;
			denominador = denominador1 * numerador2;
		}
		if (numerador == 0 || denominador == 1) {
			printf("%d/%d %c %d/%d = %d\n", numerador1, denominador1, operacion, numerador2, denominador2, numerador);
		} else {
			printf("%d/%d %c %d/%d = %d/%d\n", numerador1, denominador1, operacion, numerador2, denominador2, numerador, denominador);
		}
	} else {
		printf("Error. Division entre cero.\n");
	}
	return 0;
}
