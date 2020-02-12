SubProceso   Hanoi ( n,A,B,C )
	Si (n=1) Entonces
		Escribir "Mover de ", A, " a ", B
	Sino
		Hanoi(n-1,A,C,B)
		Hanoi(1,A,B,C)
		Hanoi(n-1,C,B,A)
	FinSi
Fin SubProceso

Proceso Torres_de_Hanoi
	//Este algoritmo permite indicar los movimientos que se deben realizar en el juego de las torres de Hanoi
	//es decir, para pasar los discos desde una torre origen hasta una torre destno, utilizando una torre auxiliar
	Definir n Como Real
	Definir i,num Como Entero
	Definir A,B,C como cadena
	//Lectura
	Escribir "Inserte el número de discos. Debe ser un entero mayor que 0 y menor que 9"
	Repetir
		Leer n
		Si n<=0 o n>=9 o n<>trunc(n) Entonces
			Escribir "Incorrecto, el número de discos debe ser entero mayor que 0 y menor que 9"
		Fin Si
	Hasta Que n>0 y n<9 y n=trunc(n)
	//número mínimo de movimientos
	num<-1
	i<-n
	Escribir ""
	Mientras (i>0) Hacer
		num<-num*2
		i<-i-1
	Fin Mientras
	num<-num-1
	Escribir "El número mínimo de movimientos es ",num
	Escribir ""
	//Pasos a seguir
	A<-"ORIGEN"
	B<-"DESTINO"
	C<-"AUXILIAR"
	Escribir ""
	Escribir "Los pasos a seguir son los siguientes"
	Hanoi(n,A,B,C)
FinProceso
