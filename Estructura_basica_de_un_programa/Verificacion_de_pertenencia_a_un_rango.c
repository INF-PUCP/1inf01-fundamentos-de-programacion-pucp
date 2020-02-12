#include <stdio.h>

int main() {
    int n = 7;
    int a = 3;
    int b = 10;
    /* Suponiendo que el rango es válido, el número n pertenece a [a, b]
    si a <= n <= b */
    int pertenece_a_rango = a <= n && n <= b;
    printf("%d pertenece al rango [%d, %d]? %d\n", n, a, b, pertenece_a_rango);
    return 0;
}
