Proceso suma_digitos_mayor_par_menor_impar
	Definir n,suma,cont,maxpar,minimpar Como Entero
	Escribir "Ingrese un n�mero entero positivo"
	Repetir
		leer n
		si n<=0
			Escribir "Ingrese de nuevo un n�mero que sea ENTERO POSITIVO"
		FinSi
	Hasta Que n>0
	suma<-0
	cont<-0
	maxpar<- -1
	minimpar<- -1
	Mientras n<>0
		suma<-suma+(n mod 10)
		si maxpar = -1
			si (n mod 10) mod 2=0
				maxpar<-n mod 10
			FinSi
		Sino
			si (n mod 10) mod 2=0
				si n mod 10 >= maxpar
					maxpar <- n mod 10
				FinSi
			FinSi
		FinSi
		si minimpar = -1
			si (n mod 10) mod 2 <> 0
				minimpar<-n mod 10
			FinSi
		Sino
			si (n mod 10) mod 2 <> 0
				si n mod 10 <= minimpar
					minimpar <- n mod 10
				FinSi
			FinSi
		FinSi
		
		n <- trunc(n / 10)
		cont <- cont+1		
	FinMientras
	si maxpar <> -1 y minimpar <> -1
		escribir "La suma de d�gitos es ",suma
		Escribir "el m�ximo par es ",maxpar
		Escribir "el m�nimo impar es ",minimpar
	FinSi
	si maxpar= -1
		escribir "La suma de d�gitos es ",suma," y el menor impar es ",minimpar
	FinSi
	si minimpar= -1
		escribir "La suma de d�gitos es ",suma," y el m�ximo par es ",maxpar
	FinSi
	FinProceso
