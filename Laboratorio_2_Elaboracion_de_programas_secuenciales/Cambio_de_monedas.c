#include <stdio.h>

int main() {
  int cantidad, cinco, dos, uno;
  printf("Ingrese la cantidad de dinero en soles : \n");
  scanf("%d", &cantidad);
  int original = cantidad;
  cinco = cantidad / 5;
  cantidad = cantidad % 5;
  dos = cantidad / 2;
  cantidad = cantidad % 2;
  uno = cantidad;
  printf("Si la cantidad de dinero fuese %d, se debera dispensar %d moneda(s) de 5 soles, %d moneda(s) de 2 soles y %d moneda(s) de 1 sol\n", original, cinco, dos, uno);
  // Finalmente, este problema se puede generalizar y nos puede introducir a una tecnica bastante popular y util
  // llamada Dynamic Programming (DP) en la cual este problema es conocido como Coin Change
  return 0;
}