Proceso sin_titulo
	definir inv Como Entero
	definir n Como Entero
	definir a Como Entero
	
	Escribir "ingrese un número entero positivo"
	leer n
	a<-n
	inv<-0
	Mientras a>0
		inv <- 10*inv+ (a mod 10)
		a<-trunc(a/10)
	FinMientras
	si n=inv Entonces
		Escribir "El número es capicua"
	Sino
		Escribir "El número no es capicua"
	FinSi
FinProceso
