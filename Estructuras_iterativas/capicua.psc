Proceso sin_titulo
	definir inv Como Entero
	definir n Como Entero
	definir a Como Entero
	
	Escribir "ingrese un n�mero entero positivo"
	leer n
	a<-n
	inv<-0
	Mientras a>0
		inv <- 10*inv+ (a mod 10)
		a<-trunc(a/10)
	FinMientras
	si n=inv Entonces
		Escribir "El n�mero es capicua"
	Sino
		Escribir "El n�mero no es capicua"
	FinSi
FinProceso
