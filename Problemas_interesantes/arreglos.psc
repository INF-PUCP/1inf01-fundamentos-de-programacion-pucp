Proceso Arreglos
	Dimension Arr[3,3]
	Definir i,j Como enteros
	Escribir "Inserte 9 números enteros"
	Para i<-1 Hasta 3 Con Paso 1 Hacer
		Para j<-1 Hasta 3 Con Paso 1 Hacer
			Escribir "Elemento (",i," ",j,")"
			Leer Arr[i,j]
		Fin Para
	Fin Para
	Escribir "Los números son:"
	Esperar 1 Segundos
	Para i<-1 Hasta 3 Con Paso 1 Hacer
		Para j<-1 Hasta 3 Con Paso 1 Hacer
			Escribir "Elemento (",i," ",j,")"
			Escribir Arr[i,j]
		Fin Para
	Fin Para
FinProceso
