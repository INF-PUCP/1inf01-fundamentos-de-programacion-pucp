#include <stdio.h>

int main() {
	/* Ecuacion de la recta y = mx + b */
	double m, b;
	scanf("%lf %lf", &m, &b);
	/* Punto P(x, y) */
	double x, y;
	scanf("%lf %lf", &x, &y);
	if (y == (m * x + b)) {
		printf("El punto (%lf, %lf) pertenece a la recta y = %lfx+%lf.\n", x, y, m, b);
	} else {
		printf("El punto (%lf, %lf) no pertenece a la recta y = %lfx+%lf.\n", x, y, m, b);
	}
	return 0;
}
