//función que coger como entrada un arreglo(coeficientes del polinomio desde el coeficiente del "x" de mayor grado
//hasta el término independiente) y un número (el grado del polinomio) y , 
//así dar como respuesta el polinomio en forma textual
SubProceso  text<-polinomio ( coefinv , n)
	Definir polin,aux,aux2,aux3 como caracter
	Dimension coef[1000]
	Definir i,k como entero
	//Invertir el arreglo
	k<-n+1
	Para i<-1 Hasta n+1 Con Paso 1 Hacer
		coef[i]<-coefinv[k]
		k<-k-1
	Fin Para
	//Formar la cadena
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
	text<-polin
Fin SubProceso
Proceso División_Algebraica_2
	Dimension a[100],b[100],q[100]
	Definir m,n Como Real
	Definir i,j,k,g,g2 como entero
	//Ingreso de datos
	Escribir "Ingrese el grado del numerador (entero positvo menor que 100)"
	Repetir
		Leer m
		Si m<=0 o m>=100 o trunc(m)<>m Entonces
			Escribir "ERROR. Debe ser entero positivo menor que 100"
		Fin Si
	Hasta Que m>0 Y m<100 y trunc(m)=m
	Escribir "Ingrese en orden los coeficientes del numerador, desde el coeficiente del ´x´ con mayor grado hasta el término independiente"
	Para i<-1 Hasta m+1 Con Paso 1 Hacer
		Escribir "Coeficiente #" i
		Si i=1 Entonces
			Escribir "Recuerde que este primer coeficiente debe ser diferente de 0"
			Repetir
				Leer a[i]
				Si a[i]=0 Entonces
					Escribir "ERROR. El primer coeficiente debe ser diferente de 0"
				Fin Si
			Hasta Que a[i]<>0
		Sino
			Leer a[i]
		Fin Si
	Fin Para
	Escribir "El numerador ingresado es" polinomio(a,m)
	Escribir "Ingrese el grado del denominador (entero positivo menor que 100), además el grado del denominador debe ser MENOR O IGUAL al del numerador"
	Repetir
		Leer n
		Si n<=0 o n>m o trunc(n)<>n Entonces
			Escribir "ERROR. Debe ser entero positivo menor o igual que el grado del numerador"
		Fin Si
	Hasta Que n>0 Y n<=m y trunc(n)=n
	Escribir "Ingrese en orden los coeficientes del denominador, desde el coeficiente del ´x´ con mayor grado hasta el término independiente"
	Para i<-1 Hasta n+1 Con Paso 1 Hacer
		Escribir "Coeficiente #" i
		Si i=1 Entonces
			Escribir "Recuerde que este primer coeficiente debe ser diferente de 0"
			Repetir
				Leer b[i]
				Si b[i]=0 Entonces
					Escribir "ERROR. El primer coeficiente debe ser diferente de 0"
				Fin Si
			Hasta Que b[i]<>0
		Sino
			Leer b[i]
		Fin Si
	Fin Para
	Escribir "El denominador ingresado es" polinomio(b,n)
	//División algebraica
	i<-1
	g<-m-n
	g2<-m
	Mientras m>=n Hacer
		q[i]<-a[i]/b[1]
		k<-i
		Para j<-1 Hasta n+1 Con Paso 1 Hacer
			a[k]<-a[k]-b[j]*q[i]
			k<-k+1
		Fin Para
		m<-m-1
		i<-i+1
	Fin Mientras
	//Eliminar los ceros del arreglo del residuo(el siguinte paso no es tan necesario, es solo para la estética)
	i<-1
	Mientras i<=g2+1 Hacer
		Si a[i]=0 y i<>g2+1 Entonces
			k<-i
			Mientras k<g2+1 Hacer
				a[k]<-a[k+1]
				k<-k+1
			Fin Mientras
			i<-i-1
			g2<-g2-1
		Sino
			Si a[i]=0 y i=g2+1 Entonces
				g2<-g2-1
			Fin Si
		Fin Si
		i<-i+1
	Fin Mientras
	//Presentación de los datos
	Escribir "El cociente es" polinomio(q,g)
	Si g2+1<>0 Entonces
		Escribir "El residuo es" polinomio(a,g2)
	Sino
		Escribir "El residuo es 0"
	Fin Si
FinProceso
