#include <stdio.h>

int main() {
  /* Ya que este problema es trivial, calcularé la tabla de verdad sin
  si quiera reducir las expresiones para que comprueben sus respuestas
  particulares cuando reduzcan las expresiones y le den valores*/
  int p, q, r, resultado;
  printf("p -> (r v ~q)\n");
  for (int i = 0; i < 8; i++) {
    int j = i;
    r = j % 2;
    j /= 2;
    q = j % 2;
    j /= 2;
    p = j % 2;
    j /= 2;
    resultado = !p || (r || !q);
    printf("p = %d q = %d r = %d resultado = %d\n", p, q, r, resultado);
  }
  printf("\n");

  printf("~(p v q) <-> (~p ^ ~q)\n");
  for (int i = 0; i < 4; i++) {
    int j = i;
    q = j % 2;
    j /= 2;
    p = j % 2;
    j /= 2;
        resultado = ((p || q) || (!p && !q)) && (!(!p && !q) || !(p || q));
        printf("p = %d q = %d resultado = %d\n", p, q, resultado);
  }
  printf("\n");

  printf("(~p ^ (q v r)) <-> ((p v r) ^ q)\n");
  for (int i = 0; i < 8; i++) {
    int j = i;
    r = j % 2;
    j /= 2;
    q = j % 2;
    j /= 2;
    p = j % 2;
    j /= 2;
    resultado = (!(!p && (q || r)) || ((p || r) && q)) &&
                (!((p || r) && q) || (!p && (q || r)));
    printf("p = %d q = %d r = %d resultado = %d\n", p, q, r, resultado);
  }
  printf("\n");

  printf("~(~(p v (~q -> p)) v ~((p <-> ~q) -> (q ^ ~p)))\n");
  for (int i = 0; i < 4; i++) {
    int j = i;
    q = j % 2;
    j /= 2;
    p = j % 2;
    j /= 2;
    resultado = !(!(p || q) || !(!((!p || !q) && (q || p)) || (q && !p)));
    printf("p = %d q = %d resultado = %d\n", p, q, resultado);
  }
  printf("\n");
  return 0;
}