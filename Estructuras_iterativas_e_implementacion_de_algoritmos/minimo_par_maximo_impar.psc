// Desarrolle un programa que reciba n (n <= 10) n�meros enteros positivos y
// determine un nuevo n[umero entero formado por el m�nimo d�gito par del primero, luego el m�ximo digito impar del segundo
// n�mero, luego el m�nimo d�gito par deltercero y as� sucesivamente.
// Asuma que el d�gito 0 es par.
// Ejemplo: Si n = 4 y los n�meros ingresados son 1234 5036 361 y 12793, el resultado ser� 2569
Proceso ejercicio_2
	//si el n�mero no tiene el d�gito mencionado se considerar� como 0//
	Definir nuevo,num,n,minpar,maximpar,i Como Entero
	Escribir "Ingrese la cantidad (<10) de n�meros enteros positivos que ingresar�"
	Repetir
		leer n
		si n>=10
			Escribir "La cantidad debe ser menor que 10"
		FinSi
	Hasta Que 0<n y n<10
	nuevo<-0
	para i<-1 hasta n
		Escribir "Ingrese un n�mero entero positivo"
		Repetir
			leer num
		Hasta Que 0<num
		si i mod 2 <> 0
			minpar <- -1
			Mientras num <> 0
				si((num mod 10) mod 2) = 0 
					si minpar=-1
						minpar <- num mod 10
					Sino
						si num mod 10 < minpar
							minpar <- num mod 10
						FinSi
					FinSi
				FinSi
				num <- trunc(num/10)
			FinMientras
			si minpar=-1
				nuevo<-10*nuevo
			Sino
				nuevo<-10*nuevo+minpar
			FinSi
			minpar <- -1
		Sino
			maximpar <- -1
			Mientras num <> 0
				si((num mod 10) mod 2) <> 0 
					si maximpar=-1
						maximpar <- num mod 10
					Sino
						si num mod 10 > maximpar
							maximpar <- num mod 10
						FinSi
					FinSi
				FinSi
				num <- trunc(num/10)
			FinMientras
			si maximpar=-1
				nuevo<-10*nuevo
			Sino
				nuevo<-10*nuevo+maximpar
			FinSi
			maximpar <- -1
		FinSi
	FinPara
	Escribir "El n�mero entero formado es ",nuevo
FinProceso
