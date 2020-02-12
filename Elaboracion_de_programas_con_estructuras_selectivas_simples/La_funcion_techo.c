#include <stdio.h>
#include <math.h>

int main() {
  double x;
  scanf("%lf", &x);
  double techo = ceil(x);
  printf("El techo de %lf es %lf.\n", x, techo);
  return 0;
}