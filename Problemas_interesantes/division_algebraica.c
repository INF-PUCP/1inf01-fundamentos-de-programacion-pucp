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

/* Para las variables que no se pudo determinar el tipo se utiliza la constante
   SIN_TIPO. El usuario debe reemplazar sus ocurrencias por el tipo adecuado
   (usualmente int,float,bool, o char[]). */
#define SIN_TIPO float

// Declaraciones adelantadas de las funciones
char polinomio(SIN_TIPO coefinv[], float n);

/* función que coger como entrada un arreglo(coeficientes del polinomio desde el coeficiente del "x" de mayor grado */
/* hasta el término independiente) y un número (el grado del polinomio) y ,  */
/* así dar como respuesta el polinomio en forma textual */
char polinomio(SIN_TIPO coefinv[], float n) {
	char aux[MAX_STRLEN];
	char aux2[MAX_STRLEN];
	char aux3[MAX_STRLEN];
	int coef[1000];
	int i;
	int k;
	char polin[MAX_STRLEN];
	char text[MAX_STRLEN];
	/* Invertir el arreglo */
	k = n+1;
	for (i=1;i<=n+1;i+=1) {
		coef[i-1] = coefinv[k-1];
		k = k-1;
	}
	/* Formar la cadena */
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
	text = polin;
	return *text;
}

int main() {
	float a[100];
	float b[100];
	int g;
	int g2;
	int i;
	int j;
	int k;
	float m;
	float n;
	float q[100];
	/* Ingreso de datos */
	printf("Ingrese el grado del numerador (entero positvo menor que 100)\n");
	do {
		scanf("%f",&m);
		if (m<=0 || m>=100 || int(m)!=m) {
			printf("ERROR. Debe ser entero positivo menor que 100\n");
		}
	} while (!(m>0 && m<100 && int(m)==m));
	printf("Ingrese en orden los coeficientes del numerador, desde el coeficiente del x con mayor grado hasta el término independiente\n");
	for (i=1;i<=m+1;i+=1) {
		printf("Coeficiente #%i\n",i);
		if (i==1) {
			printf("Recuerde que este primer coeficiente debe ser diferente de 0\n");
			do {
				scanf("%f",&a[i-1]);
				if (a[i-1]==0) {
					printf("ERROR. El primer coeficiente debe ser diferente de 0\n");
				}
			} while (a[i-1]==0);
		} else {
			scanf("%f",&a[i-1]);
		}
	}
	printf("El numerador ingresado es%s\n",polinomio(a,m));
	printf("Ingrese el grado del denominador (entero positivo menor que 100), además el grado del denominador debe ser MENOR O IGUAL al del numerador\n");
	do {
		scanf("%f",&n);
		if (n<=0 || n>m || int(n)!=n) {
			printf("ERROR. Debe ser entero positivo menor o igual que el grado del numerador\n");
		}
	} while (!(n>0 && n<=m && int(n)==n));
	printf("Ingrese en orden los coeficientes del denominador, desde el coeficiente del x con mayor grado hasta el término independiente\n");
	for (i=1;i<=n+1;i+=1) {
		printf("Coeficiente #%i\n",i);
		if (i==1) {
			printf("Recuerde que este primer coeficiente debe ser diferente de 0\n");
			do {
				scanf("%f",&b[i-1]);
				if (b[i-1]==0) {
					printf("ERROR. El primer coeficiente debe ser diferente de 0\n");
				}
			} while (b[i-1]==0);
		} else {
			scanf("%f",&b[i-1]);
		}
	}
	printf("El denominador ingresado es %s\n",polinomio(b,n));
	/* División algebraica */
	i = 1;
	g = m-n;
	g2 = m;
	while (m>=n) {
		q[i-1] = a[i-1]/b[0];
		k = i;
		for (j=1;j<=n+1;j+=1) {
			a[k-1] = a[k-1]-b[j-1]*q[i-1];
			k = k+1;
		}
		m = m-1;
		i = i+1;
	}
	/* Eliminar los ceros del arreglo del residuo(el siguinte paso no es tan necesario, es solo para la estática) */
	i = 1;
	while (i<=g2+1) {
		if (a[i-1]==0 && i!=g2+1) {
			k = i;
			while (k<g2+1) {
				a[k-1] = a[k];
				k = k+1;
			}
			i = i-1;
			g2 = g2-1;
		} else {
			if (a[i-1]==0 && i==g2+1) {
				g2 = g2-1;
			}
		}
		i = i+1;
	}
	/* Presentación de los datos */
	printf("El cociente es %s\n",polinomio(q,g));
	if (g2+1!=0) {
		printf("El residuo es %s\n",polinomio(a,g2));
	} else {
		printf("El residuo es 0\n");
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