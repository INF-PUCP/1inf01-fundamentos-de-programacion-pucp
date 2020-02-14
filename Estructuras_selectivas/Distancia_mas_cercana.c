#include <stdio.h>

int main() {
	int Ax, Ay;
	scanf("%d %d", &Ax, &Ay);
	int Bx, By;
	scanf("%d %d", &Bx, &By);
	int Cx, Cy;
	scanf("%d %d", &Cx, &Cy);
	int X, Y;
	scanf("%d %d", &X, &Y);
	int menor_distancia_cuadrado;
	int distancia_A_cuadrado = (Ax - X) * (Ax - X) + (Ay - Y) * (Ay - Y);
	int distancia_B_cuadrado = (Bx - X) * (Bx - X) + (By - Y) * (By - Y);
	int distancia_C_cuadrado = (Cx - X) * (Cx - X) + (Cy - Y) * (Cy - Y);
	menor_distancia_cuadrado = distancia_A_cuadrado;
	if (distancia_B_cuadrado < menor_distancia_cuadrado) {
		menor_distancia_cuadrado = distancia_B_cuadrado;
	}
	if (distancia_C_cuadrado < menor_distancia_cuadrado) {
		menor_distancia_cuadrado = distancia_C_cuadrado;
	}
	if (distancia_A_cuadrado == menor_distancia_cuadrado) {
		printf("El punto mas cercano es A.\n");
	} else {
		if (distancia_B_cuadrado == menor_distancia_cuadrado) {
			printf("El punto mas cercano es B.\n");
		} else {
			printf("El punto mas cercano es C.\n");
		}
	}
	return 0;
}
