#include <stdio.h>

int main() {
    int u = 1, d = 7, c = 3;
    /* En este caso particular, nos dar�n un n�mero de 3 d�gitos
    en base 10, as� que primero lo formar�*/
    int original = c * 100 + d * 10 + u;
    /* Para calcular un n�mero al cubo, como no existe el operador de
    exponenciaci�n, lo multiplicamos por s� mismo 3 veces */
    int suma = c * c * c + d * d * d + u * u * u;
    int es_Armstrong = original == suma;
    printf("Es Armstrong? %d\n", es_Armstrong);
    return 0;
}
