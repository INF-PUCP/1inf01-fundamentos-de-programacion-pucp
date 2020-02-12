#include<stdio.h>
#include<math.h>
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

// Declaraciones adelantadas de las funciones
float comb(float m, float n);

float comb(float m, float n) {
	float num;
	num = 1;
	while (n>=1) {
		num = num*m/n;
		m = m-1;
		n = n-1;
	}
	return num;
}

int main() {
	float a;
	char aux[MAX_STRLEN];
	char aux2[MAX_STRLEN];
	char aux3[MAX_STRLEN];
	int coef[1000];
	float coefinv[1000];
	float g;
	int i;
	int k;
	float mult;
	char polin[MAX_STRLEN];
	printf("La potencia de binomio que vamos a evaluar tiene esta forma: (x+a)^n\n");
	printf("Ingrese el valor de a\n");
	scanf("%f",&a);
	printf("Ingrese el valor del grado(n), debe ser un entero positivo menor que 1000\n");
	do {
		scanf("%f",&g);
		if (g<=0 || g>=1000 || int(g)!=g) {
			printf("ERROR. Vuelva a ingresar el grado, debe ser entero positivo menor que 1000\n");
		}
	} while (!(g>0 && int(g)==g && g<1000));
	k = 0;
	i = 1;
	mult = 1;
	while (k<=g) {
		coefinv[i-1] = mult*comb(g,k);
		k = k+1;
		mult = a*mult;
		i = i+1;
	}
	k = g+1;
	for (i=1;i<=g+1;i+=1) {
		coef[k-1] = coefinv[i-1];
		k = k-1;
	}
	polin = "";
	for (i=g+1;i>=1;i-=1) {
		switch (coef[i-1]) {
		case 1:
			if (i!=g+1) {
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
			if (coef[i-1]>0 && i!=g+1) {
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
	printf("El polinomio desarrollado es%s\n",polin);
	return 0;
}


/* Algunas operaciones de cadenas de texto requieren cadenas auxiliares temporales. 
   Por ejemplo, la concatenación de cadenas. Como las cadenas son en realidad arreglos
   no hay forma simple de crear estos temporales dinámicamente y destruirlos cuando ya
   no sean necesarios. Si cada función que requiere un buffer auxiliar usa su propio
   buffer estático, entonces no se puede invocar a esa función dos veces en la misma
   expresión (porque ambas invocaciones retornarán un mismo buffer como resultado
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

