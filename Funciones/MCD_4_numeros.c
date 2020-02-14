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

int main() {
	// Creo un arreglo con cuatro numeros enteros
	int a[4];
	
	// Leo los 4 numeros, recordar que estan indexados desde 0 hasta 3
	for (int i = 0; i < 4; i++) {
		printf("Ingrese el %d° numero entero no negativo: ", i + 1);
		scanf("%d", &a[i]);
	}
	// Sabemos que el MCD(a1,a2,...,an) = MCD(a1,MCD(a2,MCD(...MCD(a(n-1),an)))...)
	// Por lo tanto, fijamos el primero como la respuesta y luego lo modificamos
	int mcd = a[0];
	for (int i = 1; i < 4; i++) {
		int mayor, menor;
		if (mcd > a[i]) {
			mayor = mcd;
			menor = a[i];
		} else {
			mayor = a[i];
			menor = mcd;
		}
		mcd = MCD(mayor, menor);
	}
	printf("El maximo comun divisor de los 4 numeros es %d.\n", mcd);
	return 0;
}
