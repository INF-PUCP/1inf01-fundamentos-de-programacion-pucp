#include <stdio.h>
#include <math.h>

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
		double lado_igual, lado_diferente;
		int es_isosceles = 0;
		if (lado1 == lado2) {
			lado_igual = lado1;
			lado_diferente = lado3;
			es_isosceles = 1;
		}
		if (lado1 == lado3) {
			lado_igual = lado1;
			lado_diferente = lado2;
			es_isosceles = 1;
		}
		if (lado2 == lado3) {
			lado_igual = lado2;
			lado_diferente = lado1;
			es_isosceles = 1;
		}
		if (es_isosceles) {
			double area = lado_diferente / 4.0 * sqrt(4 * lado_igual * lado_igual - lado_diferente * lado_diferente);
			printf("El area deebe ser %lf.\n", area);
		} else {
			printf("El triangulo no es isosceles.\n");
		}
	} else {
		printf("Los lados ingresados no forman un triangulo.\n");
	}
	return 0;
}
