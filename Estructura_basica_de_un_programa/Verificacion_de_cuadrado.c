#include <stdio.h>

int main() {
    double l1 = 12.5;
    double l2 = 12.5;
    double l3 = 12.5;
    double l4 = 12.5;
    /* Para verificar que el cuadrilátero se un cuadrado, sus 4 lados
    deben ser iguales */
    int es_cuadrado = l1 == l2 && l2 == l3 && l3 == l4;
    printf("Es cuadrado? %d\n", es_cuadrado);
    return 0;
}
