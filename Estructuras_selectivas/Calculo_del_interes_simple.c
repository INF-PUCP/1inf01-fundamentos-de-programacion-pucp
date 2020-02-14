#include <stdio.h>

int main() {
	int capital, plazo, tasa;
	double saldo_deseado, saldo_final;
	scanf("%d %d %d %lf", &capital, &plazo, &tasa, &saldo_deseado);
	saldo_final = capital * (1 + plazo * (double) tasa / 100);
	if (saldo_final >= saldo_deseado) {
		printf("Conviene depositar en el banco.\n");
	} else {
		printf("No conviene depositar en el banco.\n");
	}
	return 0;
}
