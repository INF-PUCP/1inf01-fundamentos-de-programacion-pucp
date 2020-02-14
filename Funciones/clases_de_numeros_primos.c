#include <stdio.h>
#include <math.h>

// Funcion que retorna 1 si el numero es primo o 0 en otro caso
// Supongamos que n = a * b es un numero compuesto y al menos a o b son distintos de 1 y n
// Luego, alguno de ellos es menor o igual que la raiz de n
// Por lo tanto, si es que encuentras algun numero que divida a n antes de pasar su raiz
// n necesariamente es un numero compuesto, en otro caso, es primo
// Complejidad en tiempo: O(sqrt(n))
int es_primo(int n) {
	if (n < 2) return  0; // 0 y 1 no son primos
	for (int i = 2; i * i <= n; i++) if (n % i == 0) return 0;
	return 1;
}

void calcular_primos_Sophie_Germain(int n) {
	// Comenzamos a analizar desde el numero 2 ya que este es el primer primo
	int actual = 2;
	int pares = 0;
	printf("%d primeros primos de Sophie Germain: ", n);
	while (1) {
		// Cuando ya encontre todos los pares de primos que queria
		// imprimo un salto de linea para que se pueda imprimir lo que me piden luego
		if (pares == n) {
			printf("\n");
			break;
		}
		// Si se satisface la condicion de primalidad de Sophie Germain
		if (es_primo(actual) && es_primo(2 * actual + 1)) {
			// Si no es la primera vez, separo los pares con comas
			if (pares > 0) printf(", ");
			printf("(%d, %d)", actual, 2 * actual + 1);
			pares++; // Como acabo de encontrar un nuevo par, lo actualizo
		}
		actual++; // Siempre avanzo el primer elemento que analizo
	}
}

void calcular_primos_gemelos(int n) {
	int actual = 2;
	int pares = 0;
	printf("%d primeros primos gemelos: ", n);
	while (1) {
		if (pares == n) {
			printf("\n");
			break;
		}
		if (es_primo(actual) && es_primo(actual + 2)) {
			if (pares > 0) printf(", ");
			printf("(%d, %d)", actual, actual + 2);
			pares++;
		}
		actual++;
	}
}

int main() {
	printf("Ingrese el numero de pares n: ");
	int n;
	scanf("%d", &n);
	calcular_primos_Sophie_Germain(n);
	calcular_primos_gemelos(n);
	return 0;
}
