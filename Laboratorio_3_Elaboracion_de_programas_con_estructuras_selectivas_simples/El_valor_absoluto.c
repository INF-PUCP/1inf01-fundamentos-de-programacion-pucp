#include <stdio.h>

int main() {
  double x;
  scanf("%lf", &x);
  double valor_absoluto = x;
  if (valor_absoluto < 0) {
    valor_absoluto = -x;
  }
  printf("El valor absoluto de %lf es %lf.\n", x, valor_absoluto);
  return 0;
}