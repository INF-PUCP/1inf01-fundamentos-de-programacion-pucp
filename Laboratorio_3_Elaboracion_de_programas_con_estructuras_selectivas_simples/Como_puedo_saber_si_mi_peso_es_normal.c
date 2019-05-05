#include <stdio.h>

int main() {
	double masa, estatura;
	scanf("%lf %lf", &masa, &estatura);
	double imc = masa / (estatura * estatura);
	if (18.50 <= imc && imc <= 24.90) {
		printf("El peso es normal.\n");
	} else {
		printf("El peso no es normal.\n");
	}
	return 0;
}
