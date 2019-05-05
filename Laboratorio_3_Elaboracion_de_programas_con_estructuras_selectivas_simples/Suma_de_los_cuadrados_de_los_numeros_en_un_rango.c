#include <stdio.h>

int main() {
	int a, b, suma;
	scanf("%d %d", &a, &b);
	if (a > 0 && b > 0 && a < b) {
		int suma_cuadrados_b = b * (b + 1) * (2 * b + 1) / 6;
		int suma_cuadrados_anterior = (a - 1) * a * (2 * a - 1) / 6; 
		suma = suma_cuadrados_b - suma_cuadrados_anterior;
		printf("La suma de cuadrados en [%d, %d] es %d.\n", a, b, suma);
	} else {
		printf("Los valores ingresados son incorrectos.\n");
	}
	return 0;
}
