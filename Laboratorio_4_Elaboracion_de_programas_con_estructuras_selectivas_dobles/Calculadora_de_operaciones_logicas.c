#include <stdio.h>

int main() {
	/* p y q son proposiciones (V y F) */
	/* operacion : C (conjuncion), D (disyuncion), K (condicional) y B(bicondicional)*/
	char p, q, operacion;
	printf("Ingrese el valor de verdad de la proposicion p (V o F): ");
	scanf("%c", &p);
	printf("Ingrese el valor de verdad de la proposicion q (V o F): ");
	scanf("%*c%c", &q);
	printf("Ingrese el tipo de operacion a realizar entrelas proposiciones logicas (C, D, K o B): ");
	scanf("%*c%c", &operacion);
	
	int valor_p, valor_q;
	valor_p = valor_q = 0;
	if (p == 'V') valor_p = 1;
	if (q == 'V') valor_q = 1;
	
	/* Analizaremos la variable operacion y realizaremos la accion necesario dependiendo del caso */
	int resultado_logico;
	switch (operacion) {
		case 'C' :
			resultado_logico = valor_p && valor_q;
			break;
		case 'D' :
			resultado_logico = valor_p || valor_q;
			break;
		case 'K' :
			resultado_logico = (!valor_p) || valor_q;
			break;
		case 'B' :
			resultado_logico = ((!valor_p) || valor_q) && ((!valor_q) || valor_p);
			break;
	}
	char valor_resultado;
	if (resultado_logico) valor_resultado = 'V';
	else valor_resultado = 'F';
	printf("El resultado es %c.\n", valor_resultado);
	return 0;
}
