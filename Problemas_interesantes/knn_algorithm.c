#include <stdio.h>
#include <float.h>
#include <math.h>

int main() {
	/* Tenemos un punto (x, y) que analizaremos*/
	double x, y;
	printf("Ingrese el punto (x,y) a analizar: ");
	scanf("%lf %lf", &x, &y);
	
	/* Cantidad me va a guardar la cantidad de puntos validos ingresados, es decir, solo los puntos A o B */
	int cantidad = 0;
	/* Las distancias representan las 3 menores distancias de los puntos validos a (x, y) */
	/* distancia_1 < distancia_2 < distancia_3 */
	/* Las clases indican el tipo de clase que pertenece el i-esimo menor punto */
	double distancia_auxiliar, distancia_1, distancia_2, distancia_3;
	char clase_1, clase_2, clase_3;
	distancia_1 = distancia_2 = distancia_3 = DBL_MAX;
	
	double x_auxiliar, y_auxiliar;
	char clase_auxiliar;
	while (1) {
		printf("Ingrese los datos del punto (x, y, clase): ");
		scanf("%lf %lf %c", &x_auxiliar, &y_auxiliar, &clase_auxiliar);
		if (x_auxiliar == 0 && y_auxiliar == 0) break;
		if (clase_auxiliar == 'A' || clase_auxiliar == 'B') {
			/* Los voy a analizar*/
			distancia_auxiliar = sqrt((x - x_auxiliar) * (x - x_auxiliar) + (y - y_auxiliar) * (y - y_auxiliar));
			if (distancia_auxiliar < distancia_1) {
				distancia_3 = distancia_2;
				clase_3 = clase_2;
				distancia_2 = distancia_1;
				clase_2 = clase_1;
				distancia_1 = distancia_auxiliar;
				clase_1 = clase_auxiliar;
			} else {
				if (distancia_auxiliar < distancia_2) {
					distancia_3 = distancia_2;
					clase_3 = clase_2;
					distancia_2 = distancia_auxiliar;
					clase_2 = clase_auxiliar;
				} else {
					if (distancia_auxiliar < distancia_3) {
						distancia_3 = distancia_auxiliar;
						clase_3 = clase_auxiliar;	
					}
				}
			}
			cantidad++;
		} else {
			printf("La clase es invalida, no se considerara este punto.\n");
		}
	}
	
	if (cantidad >= 3) {
		int cantidad_a = 0;
		if (clase_1 == 'A') cantidad_a++;
		if (clase_2 == 'A') cantidad_a++;
		if (clase_3 == 'A') cantidad_a++;
		if (cantidad_a >= 2) {
			printf("El punto ingresado corresponde a la clase A.\n");
		} else {
			printf("El punto ingresado corresponde a la clase B.\n");
		}
	} else {
		printf("No se ingresaron al menos 3 puntos validos.\n");
	}
	return 0;
}
