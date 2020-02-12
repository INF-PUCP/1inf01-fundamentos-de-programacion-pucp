#include <stdio.h>

int main() {
    int u = 1, d = 7, c = 3;
    /* En este caso particular, nos darán un número de 3 dígitos
    en base 10, así que primero lo formaré*/
    int original = c * 100 + d * 10 + u;
    /* Para calcular un número al cubo, como no existe el operador de
    exponenciación, lo multiplicamos por sí mismo 3 veces */
    int suma = c * c * c + d * d * d + u * u * u;
    int es_Armstrong = original == suma;
    printf("Es Armstrong? %d\n", es_Armstrong);
    return 0;
}
