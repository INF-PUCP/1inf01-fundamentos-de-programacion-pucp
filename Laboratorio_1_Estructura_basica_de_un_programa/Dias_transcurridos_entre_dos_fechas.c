#include <stdio.h>

int main() {
  /* La sugerencia del problema es asumir que el a�o en cuesti�n no es
  bisiesto y que todos los meses tienen 31 d�as. Adem�s la fecha 1 siempre
  ser� menor o igual que la fecha 2 */
  int dd1 = 29, mm1 = 1;
  int dd2 = 7, mm2 = 4;
  /* Como a�n no podemos utilizar la sentencia condicional if, aprovechar�
  el operador aritm�tico de comparaci�n para analizar cada caso
  Cuando son del mismo mes, simplemente cuento los d�as
  Cuando son de distintos meses, por cada mes entre ellos hay 31 d�as y
  le sumo los d�as que pertenecen al primer mes y al �ltimo mes*/
  int dias_de_diferencia =
      (mm1 == mm2) * (dd2 - dd1 + 1) +
      ((mm1 + 1) <= mm2) * (31 * (mm2 - mm1 - 1) + (31 - dd1 + 1) + dd2);
  /* La cantidad de d�as transcurridos es la cantidad de d�as total - 1*/
  dias_de_diferencia = dias_de_diferencia - 1;
  printf("Entre %d/ %d y %d/ %d transcurrieron %d dias\n", dd1, mm1, dd2, mm2, dias_de_diferencia);
  return 0;
}
