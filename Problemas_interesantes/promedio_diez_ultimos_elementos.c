#include<stdio.h>
#include<stdbool.h>

int main() {
	int i;
	int j;
	int lista[10];
	int num;
	float primo;
	float prom;
	bool terminar;
	terminar = false;
	i = 1;
	while (!terminar) {
		printf("Ingrese un número entero [%i] , si desea terminar el proceso ingrese un número negativo\n",i);
		scanf("%i",&num);
		if (num<0) {
			terminar = true;
		} else {
			prom = 0;
			if (i<=10) {
				lista[i-1] = num;
				for (j=1;j<=i;j+=1) {
					prom = prom+lista[j-1];
				}
				printf("El promedio es %f\n",prom/i);
			} else {
				if (i%10==0) {
					lista[9] = num;
				} else {
					lista[i%10-1] = num;
				}
				for (j=1;j<=10;j+=1) {
					prom = prom+lista[j-1];
				}
				printf("El promedio de los elementos desde %f hasta %i es %f\n",i-9,i,prom/10);
			}
		}
		i = i+1;
	}
	printf("Gracias por su colaboración :)\n");
	return 0;
}