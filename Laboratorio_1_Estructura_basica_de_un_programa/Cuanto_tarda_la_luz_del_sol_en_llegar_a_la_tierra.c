#include <stdio.h>

int main() {
    /* v = d / t */
    double distancia = 150000000000.0;
    double rapidez = 299792458.0;
    double segundos = distancia / rapidez;
    double minutos = segundos / 60.0;
    printf("La luz demora en llegar desde el sol %lf segundos\n", segundos);
    printf("La luz demora en llegar desde el sol %lf minutos\n", minutos);
    return 0;
}