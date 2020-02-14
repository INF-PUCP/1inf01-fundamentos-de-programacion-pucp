Algoritmo notas_alumnos
	Definir n,pc,aprob,desaprob,i,j Como Entero
	Escribir "Ingrese la cantidad de alumnos en el aula."
	Repetir
		leer n
		si n<4
			Escribir "Ingrese de nuevo la cantidad de alumnos que mìnimo es 4."
		FinSi
	Hasta Que n>=4
	i<-0
	mientras i<n
		aprob<-0
		desaprob<-0
		para j<-1 hasta 4 hacer
			Escribir "Ingrese la nota de la pràctica ",j," si el alumno no se presentò digite 0"
			Repetir
				leer pc
				si n<0 o n>20
					Escribir "Ingrese de nuevo la nota de la pràctica ",j
				FinSi
			Hasta Que 0<=n y n<=20
			si pc>9
				aprob<-100*aprob+pc
			Sino
				desaprob<-10*desaprob+pc
			FinSi
		FinPara
		Escribir "Nùmero aprobado: ",aprob
		Escribir "Nùmero desaprobado: ",desaprob
		i<-i+1
	FinMientras
FinAlgoritmo

