#include <stdio.h>

char ObtenerSimbolo(int m) {
  if (m < 10) return ('0' + m);
  return ('A' + (m - 10));
}

int main(void) {
  int n;
  printf("Ingrese N: ");
  scanf("%d", &n);

  for (int fila = 0; fila < 2 * n - 1; fila++) {
    int suma = 0;
    int representante;
    if (fila < n) {
      representante = fila;
    } else {
      representante = n - 1 - (fila - (n - 1));
    }
    for (int columna = 0; columna < 2 * n - 1; columna++) {
      int numero;
      if (columna >= representante && columna <= 2 * n - 2 - representante) {
        numero = n - representante;
      } else {
        if (columna < n) {
          numero = n - columna;
        } else {
          numero = n - (2 * n - 2 - columna);
        }
      }
      suma += numero;
      printf("%c ", ObtenerSimbolo(numero));
    }
    printf("- %d\n", suma);
  }
  return 0;
}
