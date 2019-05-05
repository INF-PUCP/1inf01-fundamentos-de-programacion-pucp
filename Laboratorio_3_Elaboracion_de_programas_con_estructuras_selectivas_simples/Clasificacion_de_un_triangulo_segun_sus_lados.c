#include <stdio.h>

int main() {
	double lado1, lado2, lado3;
	scanf("%lf %lf %lf", &lado1, &lado2, &lado3);
	int positivos;
	/* Primero, las longitudes de los lados deben ser numeros reales positivos*/
	if (lado1 > 0 && lado2 > 0 && lado3 > 0) {
		positivos = 1;
	} else {
		positivos = 0;
	}
	
	/* Luego, se tiene que cumplir la desigualdad triangular */
	int desigualdad_triangular;
	if (lado1 < (lado2 + lado3) && lado2 < (lado1 + lado3) && lado3 < (lado1 + lado2)) {
		desigualdad_triangular = 1;
	} else {
		desigualdad_triangular = 0;
	}
	
	if (positivos && desigualdad_triangular) {
		if (lado1 == lado2 && lado2 == lado3) {
			printf("Triangulo Equilatero.\n");
		} else {
			if (lado1 == lado2 || lado2 == lado3 || lado1 == lado3) {
				printf("Triangulo Isosceles.\n");
			} else {
				printf("Triangulo Escaleno.\n");
			}
		}
	} else {
		printf("Los lados ingresados no forman un triangulo.\n");
	}
	return 0;
}
