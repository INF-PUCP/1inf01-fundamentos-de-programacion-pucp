#include<stdio.h>
#include<math.h>

int main() {
	int n;
	do {
		printf("Ingrese un numero entero no negativo: ");
		scanf("%d",&n);
	} while (n < 0);
	int primo = 1;
	if (n < 2) primo =  0; // 0 y 1 no son primos
	// Supongamos que n = a * b es un numero compuesto y al menos a o b son distintos de 1 y n
	// Luego, alguno de ellos es menor o igual que la raiz de n
	// Por lo tanto, si es que encuentras algun numero que divida a n antes de pasar su raiz
	// n necesariamente es un numero compuesto, en otro caso, es primo
	// Complejidad en tiempo: O(sqrt(n))
	for (int i = 2; i * i <= n; i++) if (n % i == 0) primo = 0;
	if (primo) printf("%d es primo.\n",n);
	else printf("%d no es  primo.\n",n);
	return 0;
}