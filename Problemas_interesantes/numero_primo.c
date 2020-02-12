#include<stdio.h>
#include<math.h>
#include<stdbool.h>

int main() {
	int i;
	int n;
	bool primo;
	int r;
	do {
		printf("Ingrese un numero entero no negativo\n");
		scanf("%i",&n);
	} while (n<0);
	primo = true;
	if (n<2) {
		printf("El numero no es entero\n");
	} else {
		if (n>2 && n%2==0) {
			primo = false;
		}
		r = int(sqrtf(n));
		i = 3;
		while (i<=r && primo) {
			if (n%i==0) {
				primo = false;
			} else {
				i = i+2;
			}
		}
	}
	if (primo) {
		printf("%i es primo\n",n);
	} else {
		printf("%i no es  primo\n",n);
	}
	return 0;
}