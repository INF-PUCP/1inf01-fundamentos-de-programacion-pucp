#include <stdio.h>

int main() {
    double l1 = 12.5;
    double l2 = 13;
    double l3 = 12.5;
    /* Para verificar que un triángulo sea isósceles, al menos dos
    lados deben tener la misma longitud*/
    int es_isosceles = l1 == l2 || l2 == l3 || l1 == l3;
    printf("Es isosceles? %d\n", es_isosceles);
    return 0;
}
