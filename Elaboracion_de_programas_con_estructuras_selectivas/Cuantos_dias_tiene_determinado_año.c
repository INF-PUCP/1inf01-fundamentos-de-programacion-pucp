#include <stdio.h>
#include <math.h>

int main() {
    // Este programa calcula la cantidad de d�as que tiene un a�o
    // Para eso debemos saber si dicho a�o es bisiesto
    // Un a�o es bisiesto si es al terminar en -00 tiene que ser divisible entre 400
    // si no termina en -00, debe ser divisible entre 4
    int anio;
    scanf("%d", &anio);
    int dias = 365;
    if ((anio % 400 == 0) || (anio % 4 == 0 && anio % 100 != 0)) dias++;
    printf("El anio %d tiene %d dias.\n", anio, dias);
    return 0;
}