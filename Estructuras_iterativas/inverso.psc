Algoritmo inverso
	Definir num,inv,aux como entero
	Escribir "Ingrese un nùmero entero positivo"
	Repetir
		leer num
		si num<=0
			Escribir "Ingrese de nuevo un nùmero que sea ENTERO POSITIVO"
		FinSi
	Hasta Que num>0
	inv <- 0
	aux <- num
	mientras num<>0
		inv <- num mod 10 + 10*inv
		num <- trunc(num/10)
	FinMientras
	Escribir "El inverso del nùmero ",aux," es ",inv
FinAlgoritmo
