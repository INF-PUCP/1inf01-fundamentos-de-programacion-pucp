#include <stdio.h>
#include <math.h>

int main() {
    int lapiceros, capacidad;
    scanf("%d %d", &lapiceros, &capacidad);
    int paquetes = ceil((double) lapiceros / capacidad);
    printf("Se deberan utilizar %d paquete(s) de capacidad %d para guardar %d lapiceros.\n", paquetes, capacidad, lapiceros);
    return 0;
}