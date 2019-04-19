#include <stdio.h>
#include <math.h>

int main() {
  double l, a;
  printf("Ingrese el valor de l y a en metros :\n");
  scanf("%lf %lf", &l, &a);
  /*
  Datos:
  1 litro pinta 10 m^2
  1 litro equivale a 0.2641720512415584
  */
  double area = l * a;
  int galon = ceil(area / 10.0 * 0.2641720512415584);
  printf("Necesitamos comprar %d galones para pintar %lf m^2.\n", galon, area);
  return 0;
}