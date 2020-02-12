Proceso Derivadas
	Dimension coef[101]
	Definir x,n como real
	Definir i Como Entero
	Definir polin,aux,aux2,aux3 como caracter
	Definir max,num,pot como real
	Definir sigue como logico
	Escribir "Ingrese el grado del polinomio (entero positivo menor que 100)"
	sigue<-Verdadero
	Repetir
		Leer n
		Si n<=0 O trunc(n)<>n Entonces
			Escribir "ERROR. Debe ser positivo y entero. Vuelva a escribir el grado"
		Fin Si
	Hasta Que n>0 Y trunc(n)=n
	Escribir "Ingrese los coeficientes en forma ordenada, desde el término independiente hasta el de la variable con mayor grado"
	Para i<-1 Hasta n+1 Con Paso 1 Hacer
		Escribir "Escribir el coeficiente # " i
		Si i=n+1 Entonces
			Escribir "Recuerde que este último coeficiente debe ser diferente de 0"
		Fin Si
		Leer coef[i]
		Si i=n+1 y coef[i]=0 Entonces
			Escribir "ERROR. El último coeficiente debe ser diferente de 0. Reinicie el programa"
			sigue<-Falso
		Fin Si
		Si i=1 Entonces
			max<-coef[i]
		Sino
			Si coef[i]>max Entonces
				max<-coef[i]
			Fin Si
		Fin Si
	Fin Para
	Si sigue Entonces
		Escribir "El coeficiente máximo es " max
		polin<-""
		Para i<-n+1 Hasta 1 Con Paso -1 Hacer
			Segun coef[i] Hacer
				1:
					Si i<>n+1 Entonces
						aux<-"+"
					Sino
						aux<-""
					Fin Si
					aux2<-"x^"+ConvertirATexto(i-1)
					aux3<-"x"
				-1:
					aux<-"-"
					aux2<-"x^"+ConvertirATexto(i-1)
					aux3<-"x"
				0:
					aux<-""
					aux2<-""
					aux3<-""
				De Otro Modo:
					Si coef[i]>0 Y i<>n+1 Entonces
						aux<-"+"+ConvertirATexto(coef[i])
						aux2<-"x^"+ConvertirATexto(i-1)
						aux3<-"x"
					Sino
						aux<-ConvertirATexto(coef[i])
						aux2<-"x^"+ConvertirATexto(i-1)
						aux3<-"x"
					Fin Si
			Fin Segun
			Si i<>1 Y i<>2 Entonces
				polin<-polin+" "+aux+aux2
			Sino
				Si i=2 Entonces
					polin<-polin+" "+aux+aux3
				Sino
					Si coef[i]>0 Entonces
						polin<-polin+" "+"+"+ConvertirATexto(coef[i])
					Sino
						Si coef[i]<0 Entonces
							polin<-polin+" "+ConvertirATexto(coef[i])
						Fin Si
					Fin Si
				Fin Si
			Fin Si
		Fin Para
		Escribir "El polinimio es " polin
		Escribir "Ingrese el número en el que desea evaluar el polinomio"
		Leer x
		num<-0
		pot<-1
		Para i<-1 Hasta n+1 Con Paso 1 Hacer
			num<-coef[i]*pot+num
			pot<-x*pot
		Fin Para
		Escribir "El polinomio evaluado en " x " es igual a " num
		polin<-""
		Para i<-n+1 Hasta 2 Con Paso -1 Hacer
			Segun coef[i]*(i-1) Hacer
				1:
					Si i<>n+1 Entonces
						aux<-"+"
					Sino
						aux<-""
					Fin Si
					aux2<-"x^"+ConvertirATexto(i-2)
					aux3<-"x"
				-1:
					aux<-"-"
					aux2<-"x^"+ConvertirATexto(i-2)
					aux3<-"x"
				0:
					aux<-""
					aux2<-""
					aux3<-""
				De Otro Modo:
					Si coef[i]>0 Y i<>n+1 Entonces
						aux<-"+"+ConvertirATexto(coef[i]*(i-1))
						aux2<-"x^"+ConvertirATexto(i-2)
						aux3<-"x"
					Sino
						aux<-ConvertirATexto(coef[i]*(i-1))
						aux2<-"x^"+ConvertirATexto(i-2)
						aux3<-"x"
					Fin Si
			Fin Segun
			Si i<>2 Y i<>3 Entonces
				polin<-polin+" "+aux+aux2
			Sino
				Si i=3 Entonces
					polin<-polin+" "+aux+aux3
				Sino
					Si coef[i]>0 Entonces
						polin<-polin+" "+"+"+ConvertirATexto(coef[i]*(i-1))
					Sino
						Si coef[i]<0 Entonces
							polin<-polin+" "+ConvertirATexto(coef[i]*(i-1))
						Fin Si
					Fin Si
				Fin Si
			Fin Si
		Fin Para
		Escribir "La derivada es " polin
		num<-0
		pot<-1
		Para i<-2 Hasta n+1 Con Paso 1 Hacer
			num<-coef[i]*(i-1)*pot+num
			pot<-x*pot
		Fin Para
		Escribir "La derivada evaluada en " x " es igual a " num
	Fin Si
FinProceso
