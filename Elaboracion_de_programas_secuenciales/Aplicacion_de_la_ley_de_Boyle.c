#include <stdio.h>

int main() {
  // Ley de boyle
  // P1 * V1 = P2 * V2
  double p1, v1, p2, v2;
  printf("Ingrese el volumen V1 en cm^3 :\n");
  scanf("%lf", &v1);
  printf("Ingrese la presion P1 en mmHg :\n");
  scanf("%lf", &p1);
  printf("Ingrese la presion P2 en atm :\n");
  scanf("%lf", &p2);
  // Primero todos deben estar en las mismas unidades para ser operados
  // Sabemos que 1 atm = 760 mmHg
  p1 = p1 / 760.0;
  v2 = p1 * v1 / p2;
  printf("El volumen V2 que ocupara a una presion %lf atm es de %lf cm^3\n", p2, v2);
  return 0;
}