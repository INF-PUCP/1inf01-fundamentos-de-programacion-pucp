Proceso numero_ceros_factorial
	Definir n,fact como entero
	Repetir
		Escribir "Ingrese un número entero no negativo"
		Leer n
	Hasta Que n>=0
	si n<=4
		Escribir "El factorial de ",n," no termina en cero"
	Sino
		Escribir "El factorial de ",n," termina en ",trunc(n/5)," ceros"
	FinSi
FinProceso
