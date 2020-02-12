#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>

/* No hay en el C estandar una funcion equivalente a "convertiratexto", pero puede programarse. */
char *convertiratexto(float f);

/* Función auxiliar para el manejo de cstrings temporales, ver detalles más abajo. */
char *get_aux_buffer(double t);
/* En C no hay variables para guardar cadenas de texto, sino que debe construirse
   un arreglo de caracteres (tipo char). El tamaño del arreglo determina la longitud
   máxima que puede tener la cadena que guarda (tamaño-1, por el caracter de terminación).
   La constante MAX_STRLEN define el tamaño máximo que se utiliza en este programa para
   cualquier cadena. */
#define MAX_STRLEN 256

int main() {
	char aux[MAX_STRLEN];
	char aux2[MAX_STRLEN];
	char aux3[MAX_STRLEN];
	int coef[101];
	int i;
	float max;
	float n;
	float num;
	char polin[MAX_STRLEN];
	float pot;
	bool sigue;
	float x;
	printf("Ingrese el grado del polinomio (entero positivo menor que 100)\n");
	sigue = true;
	do {
		scanf("%f",&n);
		if (n<=0 || int(n)!=n) {
			printf("ERROR. Debe ser positivo y entero. Vuelva a escribir el grado\n");
		}
	} while (!(n>0 && int(n)==n));
	printf("Ingrese los coeficientes en forma ordenada, desde el término independiente hasta el de la variable con mayor grado\n");
	for (i=1;i<=n+1;i+=1) {
		printf("Escribir el coeficiente # %i\n",i);
		if (i==n+1) {
			printf("Recuerde que este último coeficiente debe ser diferente de 0\n");
		}
		scanf("%i",&coef[i-1]);
		if (i==n+1 && coef[i-1]==0) {
			printf("ERROR. El último coeficiente debe ser diferente de 0. Reinicie el programa\n");
			sigue = false;
		}
		if (i==1) {
			max = coef[i-1];
		} else {
			if (coef[i-1]>max) {
				max = coef[i-1];
			}
		}
	}
	if (sigue) {
		printf("El coeficiente máximo es %f\n",max);
		polin = "";
		for (i=n+1;i>=1;i-=1) {
			switch (coef[i-1]) {
			case 1:
				if (i!=n+1) {
					aux = "+";
				} else {
					aux = "";
				}
				aux2 = strcat(strcpy(get_aux_buffer(),"x^"),convertiratexto(i-1));
				aux3 = "x";
				break;
			case -1:
				aux = "-";
				aux2 = strcat(strcpy(get_aux_buffer(),"x^"),convertiratexto(i-1));
				aux3 = "x";
				break;
			case 0:
				aux = "";
				aux2 = "";
				aux3 = "";
				break;
			default:
				if (coef[i-1]>0 && i!=n+1) {
					aux = strcat(strcpy(get_aux_buffer(),"+"),convertiratexto(coef[i-1]));
					aux2 = strcat(strcpy(get_aux_buffer(),"x^"),convertiratexto(i-1));
					aux3 = "x";
				} else {
					aux = convertiratexto(coef[i-1]);
					aux2 = strcat(strcpy(get_aux_buffer(),"x^"),convertiratexto(i-1));
					aux3 = "x";
				}
			}
			if (i!=1 && i!=2) {
				polin = strcat(strcpy(get_aux_buffer(),strcat(strcpy(get_aux_buffer(),strcat(strcpy(get_aux_buffer(),polin)," ")),aux)),aux2);
			} else {
				if (i==2) {
					polin = strcat(strcpy(get_aux_buffer(),strcat(strcpy(get_aux_buffer(),strcat(strcpy(get_aux_buffer(),polin)," ")),aux)),aux3);
				} else {
					if (coef[i-1]>0) {
						polin = strcat(strcpy(get_aux_buffer(),strcat(strcpy(get_aux_buffer(),strcat(strcpy(get_aux_buffer(),polin)," ")),"+")),convertiratexto(coef[i-1]));
					} else {
						if (coef[i-1]<0) {
							polin = strcat(strcpy(get_aux_buffer(),strcat(strcpy(get_aux_buffer(),polin)," ")),convertiratexto(coef[i-1]));
						}
					}
				}
			}
		}
		printf("El polinimio es %s\n",polin);
		printf("Ingrese el número en el que desea evaluar el polinomio\n");
		scanf("%f",&x);
		num = 0;
		pot = 1;
		for (i=1;i<=n+1;i+=1) {
			num = coef[i-1]*pot+num;
			pot = x*pot;
		}
		printf("El polinomio evaluado en %f es igual a %f\n",x,num);
		polin = "";
		for (i=n+1;i>=2;i-=1) {
			switch (coef[i-1]*(i-1)) {
			case 1:
				if (i!=n+1) {
					aux = "+";
				} else {
					aux = "";
				}
				aux2 = strcat(strcpy(get_aux_buffer(),"x^"),convertiratexto(i-2));
				aux3 = "x";
				break;
			case -1:
				aux = "-";
				aux2 = strcat(strcpy(get_aux_buffer(),"x^"),convertiratexto(i-2));
				aux3 = "x";
				break;
			case 0:
				aux = "";
				aux2 = "";
				aux3 = "";
				break;
			default:
				if (coef[i-1]>0 && i!=n+1) {
					aux = strcat(strcpy(get_aux_buffer(),"+"),convertiratexto(coef[i-1]*(i-1)));
					aux2 = strcat(strcpy(get_aux_buffer(),"x^"),convertiratexto(i-2));
					aux3 = "x";
				} else {
					aux = convertiratexto(coef[i-1]*(i-1));
					aux2 = strcat(strcpy(get_aux_buffer(),"x^"),convertiratexto(i-2));
					aux3 = "x";
				}
			}
			if (i!=2 && i!=3) {
				polin = strcat(strcpy(get_aux_buffer(),strcat(strcpy(get_aux_buffer(),strcat(strcpy(get_aux_buffer(),polin)," ")),aux)),aux2);
			} else {
				if (i==3) {
					polin = strcat(strcpy(get_aux_buffer(),strcat(strcpy(get_aux_buffer(),strcat(strcpy(get_aux_buffer(),polin)," ")),aux)),aux3);
				} else {
					if (coef[i-1]>0) {
						polin = strcat(strcpy(get_aux_buffer(),strcat(strcpy(get_aux_buffer(),strcat(strcpy(get_aux_buffer(),polin)," ")),"+")),convertiratexto(coef[i-1]*(i-1)));
					} else {
						if (coef[i-1]<0) {
							polin = strcat(strcpy(get_aux_buffer(),strcat(strcpy(get_aux_buffer(),polin)," ")),convertiratexto(coef[i-1]*(i-1)));
						}
					}
				}
			}
		}
		printf("La derivada es %s\n",polin);
		num = 0;
		pot = 1;
		for (i=2;i<=n+1;i+=1) {
			num = coef[i-1]*(i-1)*pot+num;
			pot = x*pot;
		}
		printf("La derivada evaluada en %f es igual a %f\n",x,num);
	}
	return 0;
}


/* Algunas operaciones de cadenas de texto requieren cadenas auxiliares temporales. 
   Por ejemplo, la concatenación de cadenas. Como las cadenas son en realidad arreglos
   no hay forma simple de crear estos temporales dinámicamente y destruirlos cuando ya
   no sean necesarios. Si cada función que requiere un buffer auxiliar usa su propio
   buffer estático, entonces no se puede invocar a esa función dos veces en la misma
   expresión (porque ambas invocaciones retornarían un mismo buffer como resultado
   aunque sus argumentos sean diferentes, y además esto genera un comportamiento 
   indefinido según el estándar de C). Para salvar este problema, esta función define
   varios buffers auxiliares y los va entregando a las demás funciones a medida que
   estas los requieren, rotando cual entrega en orden. Entonces, una expresión puede
   requerir tantos buffers como MAX_BUFFERS indique sin que se generen problemas,
   y se evita utilizar memoria dinámica. */
#define MAX_BUFFERS 10
char *get_aux_buffer(double t) {
	static char buffers[MAX_BUFFERS][MAX_STRLEN];
	static int count = -1;
	count = count+1;
	if(count==MAX_BUFFERS) count = 0;
	return buffers[count];
}


char *convertiratexto(float f) {
	char *buf = get_aux_buffer();
	sprintf(buf,"%f",f);
	return buf;
}
