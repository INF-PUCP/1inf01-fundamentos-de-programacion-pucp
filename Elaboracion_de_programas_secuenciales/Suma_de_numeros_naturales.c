#include <stdio.h>

int main() {
  // Calcular la suma de los numeros naturales en [a, b]
  int a, b;
  printf("Ingrese los extremos del rango [a, b] :\n");
  scanf("%d %d", &a, &b);
  int suma_total = b * (b + 1) / 2;
  int suma_anterior = (a - 1) * a / 2;
  int suma = suma_total - suma_anterior;
  printf("La suma de numeros naturales en [%d, %d] es %d\n", a, b, suma);
  return 0;
}