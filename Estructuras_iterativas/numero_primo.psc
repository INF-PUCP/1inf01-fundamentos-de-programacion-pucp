Algoritmo numero_primo
	Definir n,i,r Como Entero
	Definir primo como logico
	Repetir
		Escribir "Ingrese un numero entero no negativo"
		leer n
	Hasta Que n>=0
	primo<-Verdadero
	si n<2
		Escribir "El numero no es entero"
	Sino
		si n>2 y n mod 2 = 0
			primo<-Falso
		FinSi
		r<-trunc(raiz(n))
		i<-3
		mientras i<=r y primo
			si n mod i = 0
				primo<-Falso
			Sino
				i<-i+2
			FinSi
		FinMientras
	FinSi
	si primo
		Escribir n," es primo"
	Sino
		Escribir n," no es  primo"
	FinSi
FinAlgoritmo
