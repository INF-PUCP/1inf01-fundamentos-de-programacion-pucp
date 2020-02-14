SubProceso num <- Comb ( m,n )
	Definir num Como real
	num<-1
	Mientras n>=1 Hacer
		num<-num*m/n
		m<-m-1
		n<-n-1
	Fin Mientras
Fin SubProceso

Proceso Binomio_de_Newton
	Definir a,g,mult Como real
	Definir i,k como entero
	Definir aux,aux2,aux3,polin como caracter
	Dimension coefinv[1000]
	Dimension coef[1000]
	Escribir "La potencia de binomio que vamos a evaluar tiene esta forma: (x+a)^n"
	Escribir "Ingrese el valor de ´a´"
	Leer a
	Escribir "Ingrese el valor del grado(n), debe ser un entero positivo menor que 1000"
	Repetir
		Leer g
		Si g<=0 o g>=1000 o trunc(g)<>g Entonces
			Escribir "ERROR. Vuelva a ingresar el grado, debe ser entero positivo menor que 1000"
		Fin Si
	Hasta Que g>0 Y trunc(g)=g Y g<1000
	k<-0
	i<-1
	mult<-1
	Mientras k<=g Hacer
		coefinv[i]<-mult*comb(g,k)
		k<-k+1
		mult<-a*mult
		i<-i+1
	Fin Mientras
	k<-g+1
	Para i<-1 Hasta g+1 Con Paso 1 Hacer
		coef[k]<-coefinv[i]
		k<-k-1
	Fin Para
	polin<-""
	Para i<-g+1 Hasta 1 Con Paso -1 Hacer
		Segun coef[i] Hacer
			1:
				Si i<>g+1 Entonces
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
				Si coef[i]>0 Y i<>g+1 Entonces
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
	Escribir "El polinomio desarrollado es" polin
FinProceso

