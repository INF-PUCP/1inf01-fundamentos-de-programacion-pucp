#include <stdio.h>
#include <math.h>

int main() {
    // El valor exacto de PI es arcos(-1)
    double PI = acos(-1);
    printf("El valor de pi es %.10lf.\n", PI);
    double Ramanujan_PI = 9801.0 / 4412.0 * sqrt(2.0);
    printf("El valor aproximado de pi con la formula de Ramanujan es %.10lf.\n", Ramanujan_PI);
    double diferencia = fabs(PI - Ramanujan_PI);
    printf("El error es %.10lf.\n", diferencia);
    return 0;
}