#include <stdio.h>
#include <math.h>

int main() {
	/* (x-a)^2 + (y-b)^2 = r^2 */
	double a, b, r, x, y;
	scanf("%lf %lf", &a, &b);
	scanf("%lf", &r);
	scanf("%lf %lf", &x, &y);
	if (((x - a)*(x - a) + (y - b)*(y - b)) <= (r * r)) {
		printf("El punto (%lf, %lf) esta dentro de la circunferencia.\n", x, y);
	} else {
		printf("El punto (%lf, %lf) no esta dentro de la circunferencia.\n", x, y);
	}
	return 0;
}
