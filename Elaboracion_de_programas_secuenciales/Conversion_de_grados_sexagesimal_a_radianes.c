#include <stdio.h>
#include <math.h>
const double PI = acos(-1);

int main() {
    double grados, minutos, segundos;
    printf("Ingrese un angulo sexagesimal expresado en grados, minutos y segundos :\n");
    scanf("%lf %lf %lf", &grados, &minutos, &segundos);
    double sexagesimales = grados + minutos / 60.0 + segundos / 3600.0;
    double radianes = sexagesimales * PI / 180.0;
    printf("La conversion en radianes es %lf.\n", radianes);
    return 0;
}