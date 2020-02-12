#include<stdio.h>
#include<math.h>

int main() {
	float s;
	float x1;
	float x2;
	float x3;
	float y1;
	float y2;
	float y3;
	float z1;
	float z2;
	float z3;
	printf("Ingrese las coordenadas del punto A=(x1,y1,z1) //Pulse enter luego de ingresar una coordenada\n");
	scanf("%f",&x1);
	scanf("%f",&y1);
	scanf("%f",&z1);
	printf("Ingrese las coordenadas del punto B=(x2,y2,z2) //Pulse enter luego de ingresar una coordenada\n");
	scanf("%f",&x2);
	scanf("%f",&y2);
	scanf("%f",&z2);
	printf("Ingrese las coordenadas del punto C=(x3,y3,z3) //Pulse enter luego de ingresar una coordenada\n");
	scanf("%f",&x3);
	scanf("%f",&y3);
	scanf("%f",&z3);
	s = (sqrtf(((y2-y1)*(z3-z1)-(z2-z1)*(y3-y1))*((y2-y1)*(z3-z1)-(z2-z1)*(y3-y1))+((x2-x1)*(z3-z1)-(z2-z1)*(x3-x1))*((x2-x1)*(z3-z1)-(z2-z1)*(x3-x1))+((x2-x1)*(y3-y1)-(y2-y1)*(x3-x1))*((x2-x1)*(y3-y1)-(y2-y1)*(x3-x1))))/2;
	if (s==0) {
		if (x1==x2 && x2==x3 && y1==y2 && y2==y3 && z1==z2 && z2==z3) {
			printf("Las 3 vértices representan un solo punto por lo que el área sería 0 u\n");
		} else {
			printf("Los 3 puntos son colineales y por lo tanto el área es 0 u\n");
		}
	} else {
		printf("El área del triángulo es %f u\n",s);
	}
	return 0;
}
