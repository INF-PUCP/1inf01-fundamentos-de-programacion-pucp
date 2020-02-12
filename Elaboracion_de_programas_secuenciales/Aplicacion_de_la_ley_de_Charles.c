#include <stdio.h>

int main() {
  // Ley de Charles
  // V1/T1 = V2/T2
  double v1, t1, v2, t2;
  printf("Ingrese el volumen V1 en cm^3 :\n");
  scanf("%lf", &v1);
  printf("Ingrese la temperatura T1 en grados C :\n");
  scanf("%lf", &t1);
  printf("Ingrese la temperatura T2 en grados C :\n");
  scanf("%lf", &t2);
  // Primero todos deben estar en las mismas unidades para ser operados
  // La proporcion se cumple cuando la temperatura esta en K (kelvin)
  // La guia de laboratorio presenta un error al comparar directamente en Celsius
  t1 = t1 + 273.0;
  t2 = t2 + 273.0;
  v2 = v1 * t2 / t1;
  printf("El volumen V2 que ocupara a una temperatura %lf grados C es de %lf cm^3\n", t2 - 273.0, v2);
  return 0;
}