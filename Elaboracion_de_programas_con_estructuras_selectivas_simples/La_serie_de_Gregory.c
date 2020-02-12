#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	double termino;
	termino = 1 / (2 * (double) n - 1);
	if (n % 2 == 0) {
		termino = termino * (-1);
	}
	printf("El %d-esimo termino de la serie de Gregory es %lf.\n", n, termino);
	return 0;
}
