#include <stdio.h>

int main() {
	int numero;
	scanf("%d", &numero);
	if (100 <= numero && numero <= 999) {
		int u, d, c;
		int original = numero;
		u = numero % 10;
		numero /= 10;
		d = numero % 10;
		numero /= 10;
		c = numero;
		int suma = u * u * u + d * d * d + c * c * c;
		if (suma == original) {
			printf("%d es numero Armstrong.\n", original);
		} else {
			printf("%d no es numero Armstrong.\n", original);
		}
	} else {
		printf("El numero no tiene 3 cifras.\n");
	}
	return 0;
}
