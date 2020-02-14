#include <stdio.h>
#include <math.h>

void conjetura_collatz(int n) {
	int actual = n;
	printf("Para n = %d obtenemos los siguientes numeros de la conjetura de Collatz: ", n);
	int primera_vez = 1;
	while (actual != 1) {
		if (primera_vez) primera_vez = 0;
		else printf(", ");
		printf("%d", actual);
		if (actual % 2 == 0) actual /= 2;
		else actual = 3 * actual + 1;
	}
	printf(", 1\n");
}

void sucesion_de_fibonacci(int n) {
	int f[n];
	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i < n; i++) f[i] = f[i - 1] + f[i - 2];
	printf("%d primeros numeros de la sucesion de Fibonacci: ", n);
	for (int i = 0; i < n; i++) {
		if (i > 0) printf(", ");
		printf("%d", f[i]);
	}
	printf("\n");
}

int main() {
	printf("Ingrese el numero de elementos de las sucesiones n = ");
	int n;
	scanf("%d", &n);
	conjetura_collatz(n);
	sucesion_de_fibonacci(n);
	return 0;
}