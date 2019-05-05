#include <stdio.h>

int main() {
	/*landa = rapidez de propagacion en un determinado medio / frecuencia*/
	double landa, rapidez, frecuencia;
	char medio;
	scanf("%c", &medio);
	if (medio == 'A') {
		/*Si el medio es el agua, v = 1400 m/s*/
		rapidez = 1400.0;
	} else {
		/*Sino, asumiremos que es solo el aire, v = 340 m/s*/
		rapidez = 340.0;
	}
	/*Por convencion, la frecuencia de la nota LA es de 440 Hz*/
	frecuencia = 440.0;
	landa = rapidez / frecuencia;
	printf("La longitud de la onda en dicho medio es de %lfm.\n", landa);
	return 0;
}
