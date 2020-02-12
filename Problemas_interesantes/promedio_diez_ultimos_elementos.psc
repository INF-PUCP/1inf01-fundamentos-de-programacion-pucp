Proceso promedio_diez_ultimos
	definir i,j,lista,num como entero
	Dimension lista[10]
	definir primo Como Real
	definir terminar como logico
	terminar<-falso
	i<-1
	mientras no terminar
		Escribir "Ingrese un nùmero entero [",i,"] , si desea terminar el proceso ingrese un número negativo"
		leer num
		si num<0
			terminar<-verdadero
		Sino
			prom<-0
			si i<=10
				lista[i]<-num
				para j<-1 hasta i
					prom<-prom+lista[j]
				FinPara
				Escribir "El promedio es ",prom/i
			Sino
				si i mod 10 =0
					lista[10]<-num
				sino
					lista[i mod 10]<-num
				FinSi
				Para j<-1 hasta 10
					prom<-prom+lista[j]
				FinPara
				Escribir "El promedio de los elementos desde ",i-9," hasta ",i," es ",prom/10
			FinSi
		FinSi
		i<-i+1
	FinMientras
	Escribir "Gracias por su colaboración :)"
FinProceso
