#include <stdio.h>
#include <math.h>

struct Intervalo {
	double l, r;
};

void leer_intervalo(Intervalo *I, char c) {
	printf("Ingrese limite inferior y superior de intervalo %c: ", c);
	scanf("%lf %lf", &I->l, &I->r);
}

int es_valido(Intervalo I) {
	if (I.l <= I.r) return 1;
	return 0;
}

double max(double a, double b) {
	if (a > b) return a;
	return b;
}

double min(double a, double b) {
	if (a < b) return a;
	return b;
}

Intervalo intersectar(Intervalo A, Intervalo B) {
	Intervalo C;
	C.l = max(A.l, B.l);
	C.r = min(A.r, B.r);
	return C;
}

void imprimir_validez(int ok, char c) {
	if (ok) printf("El intervalo %c es valido.\n", c);
	else printf("El intervalo %c no es valido.\n", c);
}

void imprimir_intervalo(Intervalo I, char c) {
	printf("Intervalo %c:\n", c);
	printf("Limite inferior: %lf\n", I.l);
	printf("Limite superior: %lf\n", I.r);
}

int main() {
	Intervalo A, B, C;
	leer_intervalo(&A, 'A');
	leer_intervalo(&B, 'B');
	int ok_A = es_valido(A);
	int ok_B = es_valido(B);
	imprimir_validez(ok_A, 'A');
	imprimir_validez(ok_B, 'B');
	if (ok_A && ok_B) {
		C = intersectar(A, B);
		printf("Los intervalos A y B se intersectan? ");
		if (es_valido(C)) {
			printf("Si.\n");
			imprimir_intervalo(C, 'C');
		} else {
			printf("No.\n");
		}
	}
	return 0;
}
