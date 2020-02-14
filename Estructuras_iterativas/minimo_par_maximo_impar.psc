// Desarrolle un programa que reciba n (n <= 10) números enteros positivos y
// determine un nuevo n[umero entero formado por el mínimo dígito par del primero, luego el máximo digito impar del segundo
// número, luego el mínimo dígito par deltercero y así sucesivamente.
// Asuma que el dígito 0 es par.
// Ejemplo: Si n = 4 y los números ingresados son 1234 5036 361 y 12793, el resultado será 2569
Proceso ejercicio_2
	//si el número no tiene el dígito mencionado se considerará como 0//
	Definir nuevo,num,n,minpar,maximpar,i Como Entero
	Escribir "Ingrese la cantidad (<10) de números enteros positivos que ingresará"
	Repetir
		leer n
		si n>=10
			Escribir "La cantidad debe ser menor que 10"
		FinSi
	Hasta Que 0<n y n<10
	nuevo<-0
	para i<-1 hasta n
		Escribir "Ingrese un número entero positivo"
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
	Escribir "El número entero formado es ",nuevo
FinProceso
