#include <stdio.h>
#include <math.h>

int main() {
    int costo, descuento, ciclo;
    scanf("%d %d %d", &costo, &descuento, &ciclo);
    double monto = (double) costo;
    if (ciclo >= 5) monto = monto * (100.0 - descuento) / 100.0;
    printf("Debera pagar %lf soles.\n", monto);
    return 0;
}