#include <stdio.h>

int main() {
    int dolor_abdominal = 0;
    int sensibilidad_al_tacto = 1;
    int hinchazon = 1;
    int pesadez = 0;
    int fiebre = 1;
    int nauseas = 1;
    int vomitos = 1;
    int peritonitis = (dolor_abdominal || sensibilidad_al_tacto) && (hinchazon || pesadez) && fiebre && nauseas && vomitos;
    printf("El paciente padece peritonitis? %d\n", peritonitis);
    return 0;
}
