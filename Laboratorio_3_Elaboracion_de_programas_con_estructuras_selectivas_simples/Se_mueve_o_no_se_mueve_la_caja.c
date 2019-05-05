#include <stdio.h>

int main() {
	double peso, coeficiente, fuerza;
	scanf("%lf %lf %lf", &peso, &coeficiente, &fuerza);
	double max_fuerza_rozamiento = coeficiente * peso;
	if (fuerza > max_fuerza_rozamiento) {
		printf("Si se mueve la caja.\n");
	} else {
		printf("No se mueve la caja.\n");
	}
	return 0;
}
