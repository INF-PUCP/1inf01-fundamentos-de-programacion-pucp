#include <stdio.h>

int main() {
    int a, b, c;
    /* Asignamos a todos el mismo valor */
    a = b = c = 5;
    /* En la guía nos proponen lo siguiente*/
    int iguales = a == b == c;
    printf("Son los numeros iguales? %d\n", iguales);
    /* A pesar de ser iguales, nos da otro resultado ya que cuando una
    comparación es 5 == 5 y al ser verdadero retorna 1, y luego compara 5 == 1
    y esto es 0. La forma correcta es la siguiente:*/
    iguales = a == b && b == c;
    printf("Son los numeros iguales? %d\n", iguales);
    /* Si le cambio el valor a alguno de ellos, debería ser falso */
    c = 69;
    iguales = a == b && b == c;
    printf("Son los numeros iguales? %d\n", iguales);
    return 0;
}
