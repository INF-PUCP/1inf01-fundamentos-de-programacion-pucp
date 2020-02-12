#include<stdio.h>
#include<math.h>

int main() {
	int fact;
	int n;
	do {
		printf("Ingrese un número entero no negativo\n");
		scanf("%i",&n);
	} while (n<0);
	if (n<=4) {
		printf("El factorial de %i no termina en cero\n",n);
	} else {
		printf("El factorial de %i termina en %i ceros\n",n,int(n/5));
	}
	return 0;
}

