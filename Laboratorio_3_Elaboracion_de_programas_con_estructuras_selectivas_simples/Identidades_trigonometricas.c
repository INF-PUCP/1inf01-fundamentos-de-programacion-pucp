#include <stdio.h>
#include <math.h>

int main() {
	double angulo;
	scanf("%lf", &angulo);
	double senx = sin(angulo);
	double cosx = cos(angulo);
	double sen2x = sin(2 * angulo);
	double cos2x = cos(2 * angulo);
	if (sen2x == (2 * senx * cosx)) {
		printf("Se cumple la identidad sen2x = 2senxcosx\n");
	}
	if (cos2x == (cosx * cosx - senx * senx)) {
		printf("Se cumple la identidad cos2x = (cosx)^2 - (senx)^2\n");
	}
	if (cos2x == (1.0 - 2 * senx * senx)) {
		printf("Se cumple la identidad cos2x = 1 - 2(senx)^2\n");
	}
	/*A pesar de que las identidadesse cumplen, no siempre funcionara ya que
	al utilizar double, tenemos una capacidad limitada de memoria para representarla parte decimal del numero
	y se arrastra el error al multiplicar, lo correcto seria comparar con un diferencial de error*/
	return 0;
}
