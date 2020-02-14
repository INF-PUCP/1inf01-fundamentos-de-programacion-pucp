#include <stdio.h>
#include <math.h>

// Implementacion iterativa para hallar la sucesion de padovan
// Complejidad en Tiempo: O(n)
void sucesion_de_padovan(int n) {
	printf("Sucesion de Padovan: ");
	int a[n + 1]; // los numeros estan indexados desde 0 hasta n
	// Casos base
	a[0] = a[1] = a[2] = 1;
	// Definicion recursiva desde 3
	for (int i = 3; i <= n; i++) a[i] = a[i - 2] + a[i - 3];
	for (int i = 0; i <= n; i++) {
		if (i > 0) printf(", ");
		printf("%d", a[i]);
	}
	printf("\n");
}

void sucesion_de_perrin(int n) {
	printf("Sucesion de Perrin: ");
	int a[n + 1];
	a[0] = 3;
	a[1] = 0;
	a[2] = 2;
	for (int i = 3; i <= n; i++) a[i] = a[i - 2] + a[i - 3];
	for (int i = 0; i <= n; i++) {
		if (i > 0) printf(", ");
		printf("%d", a[i]);
	}
	printf("\n");
}

int main() {
	printf("Ingrese el numero de elementos de las sucesiones n: ");
	int n;
	scanf("%d", &n);
	sucesion_de_padovan(n);
	sucesion_de_perrin(n);
	return 0;
}
