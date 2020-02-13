// Escriba un programa que reciba 3 n�meros reales y determine si forman un tri�ngulo
// De ser as�, determine si el tri�ngulo es equil�tero, is�sceles o escaleno
Algoritmo ejercicio_1
	Definir a,b,c Como Real
	Definir m,n,p Como Logico
	Escribir "Ingrese 3 n�meros reales positivos"
	Repetir
		Leer a,b,c
		si a<0 o b<0 o c<0
			Escribir "Los n�meros deben ser POSITIVOS"
		FinSi
	Hasta Que  a>0 y b>0 y c>0
	m<-Verdadero
	n<-Verdadero
	p<-Verdadero
	si a-b<0
		si (-1)*(a-b)>=c
			m<-Falso
		FinSi
	Sino
		si a-b >= c
			m<-Falso
		FinSi
	FinSi
	si a-c<0
		si (-1)*(a-c)>=b
			n<-Falso
		FinSi
	Sino
		si a-c >= b
			n<-Falso
		FinSi
	FinSi
	si c-b<0
		si (-1)*(c-b)>=a
			p<-Falso
		FinSi
	Sino
		si c-b >=a
			p<-Falso
		FinSi
	FinSi
	si a+b>c y a+c>b y b+c>a y m y n y p
		si a=b y b=c
			Escribir "Con los 3 n�meros ingresados se puede formar un tri�ngulo equil�tero."
		FinSi
		si a=b y b<>c o a=c y c<>b o b=c y c<>a
			Escribir "Con los 3 n�meros ingresados se puede formar un tri�ngulo is�sceles."
		FinSi
		si a<>b y b<>c y a<>c
			Escribir "Con los 3 n�meros ingresados se puede formar un tri�ngulo escaleno."
		FinSi		
	Sino
		Escribir "Con los n�meros ingresados no se puede formar un tri�ngulo."
	FinSi
FinAlgoritmo
