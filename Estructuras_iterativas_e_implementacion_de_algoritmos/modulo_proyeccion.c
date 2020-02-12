#include<stdio.h>
#include<math.h>

int main() {
	float m;
	float n;
	float r;
	float s;
	printf("Ingrese las componentes del vector u (m,n) //Pulse enter luego de ingresar una coordenada\n");
	scanf("%f",&m);
	scanf("%f",&n);
	printf("Ingrese las componentes del vector v (r,s) //Pulse enter luego de ingresar una coordenada\n");
	scanf("%f",&r);
	scanf("%f",&s);
	if (r==0 && s==0) {
		printf("No se puede proyectar el vector u sobre el vector nulo\n");
	} else {
		if ((m*r+n*s)<0) {
			printf("El módulo del vector proyección de u sobre v es %f\n",(-1)*(m*r+n*s)/(sqrtf(r*r+s*s)));
		} else {
			printf("El módulo del vector proyección de u sobre v es %f\n",(m*r+n*s)/(sqrtf(r*r+s*s)));
		}
	}
	return 0;
}

