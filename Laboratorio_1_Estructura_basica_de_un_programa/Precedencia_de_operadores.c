#include <stdio.h>

int main() {
    /* Simplemente nos damos cuenta que la jerarquía de los operadores
        en C es la misma a la cual estamos acostumbrados*/
    int resultado1 = 5 + 3 * 2 + 7;
    int resultado2 = (5 + 3) * (2 + 7);
    printf("El primer resultado es %d y el segundo es %d.\n", resultado1, resultado2);
    return 0;
}
