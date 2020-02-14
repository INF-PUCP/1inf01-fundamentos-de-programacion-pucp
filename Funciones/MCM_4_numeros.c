#include <stdio.h>
#include <math.h>

// Esta es la implementacion recursiva del algoritmo de Euclides
// La demostracion la pueden realizar listando un numero finito de veces el algoritmo de la division
// Luego utilizan el teorema de que MCD(a, b) = MCD(b, a % b)
// Complejidad en tiempo: O(lg(min(a, b))
int MCD(int a, int b) {
	if (b == 0) return a;
	return MCD(b, a % b); 
}

// Teorema: a * b = MCM(a, b) * MCD(a, b)
// Despejando, MCM(a, b) = a * b / MCD(a, b)
// Primero dividire y luego multiplicare para prevenir overflow
// Compejidad en tiempo: O(lg(min, a, b))
int MCM(int a, int b) {
	return a / MCD(a, b) * b;
}

int main() {
	// Creo un arreglo con cuatro numeros enteros
	int a[4];
	
	// Leo los 4 numeros, recordar que estan indexados desde 0 hasta 3
	for (int i = 0; i < 4; i++) {
		printf("Ingrese el %d° numero entero no negativo: ", i + 1);
		scanf("%d", &a[i]);
	}
	// Sabemos que el MCM(a1,a2,...,an) = MCM(a1,MCM(a2,MCM(...MCM(a(n-1),an)))...)
	// Por lo tanto, fijamos el primero como la respuesta y luego lo modificamos
	int mcm = a[0];
	for (int i = 1; i < 4; i++) {
		int mayor, menor;
		if (mcm > a[i]) {
			mayor = mcm;
			menor = a[i];
		} else {
			mayor = a[i];
			menor = mcm;
		}
		mcm = MCM(mayor, menor);
	}
	printf("El minimo comun multiplo de los 4 numeros es %d.\n", mcm);
	return 0;
}
