#include <stdio.h>
#include <math.h>

int main() {
  double x;
  scanf("%lf", &x);
  double piso = floor(x);
  printf("El piso de %lf es %lf.\n", x, piso);
  return 0;
}