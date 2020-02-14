SubProceso Simplificar ( num Por Referencia,den Por Referencia)
	//Var
	Definir a,b,r Como Entero
	
	//inicio
	a<-num
	b<-den
	Repetir
		r<- a mod b
		a<-b
		b<-r
	Hasta Que r=0
	num<-num/a
	den<-den/a
	Si den<0 Entonces
		num<-num*(-1)
		den<-den*(-1)
	FinSi
Fin SubProceso

SubProceso Convertir_reales ( num Por Referencia,den Por Referencia )
	//Está función hará que los numeradores y denominadores que sean reales, los convertimos a enteros(amplificamos la fracción)
	
	//Var
	Definir m,n,i,pot1,pot2,pot Como Entero
	Definir tnumer,tdenom Como Caracter
	
	//inicio
	tnumer<-ConvertirATexto(num)
	m<-Longitud(tnumer)
	i<-1
	Mientras i<=m y SubCadena(tnumer,i,i)<>'.' Hacer
		i<-i+1
	Fin Mientras
	pot1<-1
	i<-i+1
	Mientras (i<=m) Hacer
		pot1<-10*pot1
		i<-i+1
	FinMientras
	tdenom<-ConvertirATexto(den)
	n<-Longitud(tdenom)
	i<-1
	Mientras i<=n y SubCadena(tdenom,i,i)<>'.' Hacer
		i<-i+1
	Fin Mientras
	pot2<-1
	i<-i+1
	Mientras (i<=n) Hacer
		pot2<-10*pot2
		i<-i+1
	FinMientras
	Si (pot1>=pot2) entonces
		pot<-pot1
	Sino
		pot<-pot2
	FinSi
	den<-den*pot
	num<-num*pot
Fin SubProceso

SubProceso Lectura(sigue Por Referencia, text Por Referencia)
	//Var
	Definir den,num Como Real
	Definir i,ind,ind2,cont,l,numer,denom Como Entero
	Definir deci como logico
	Definir frac Como Caracter
	
	//inicio
	Leer text
	i<-1
	l<-Longitud(text)
	ind<-l
	sigue<-Verdadero
	deci<-Falso
	cont<-0
	//verificamos la entrada de datos
	Mientras i<=l y sigue Hacer
		Segun SubCadena(text,i,i) Hacer
			'1','2','3','4','5','6','7','8','9','0','/','-','.':
				//bien
			De Otro Modo:
				sigue<-Falso
				Escribir "ERROR.La entrada de datos no es correcta"
		Fin Segun
		Si deci Entonces
			Segun SubCadena(text,i,i) Hacer
				'1','2','3','4','5','6','7','8','9','0':
					//bien
				'/': 
					Si i=ind2+1 Entonces
						sigue<-Falso
					Sino
						deci<-Falso
					FinSi
				De Otro Modo:
					sigue<-Falso
					Escribir "ERROR.La entrada de datos no es correcta"
			Fin Segun
		FinSi
		Si Subcadena(text,i,i)= '.' Entonces
			deci<-Verdadero
			ind2<-i
		FinSi
		Si SubCadena(text,i,i)='/' Entonces
			cont<-cont+1
			ind<-i
		Fin Si
		Si sigue y (SubCadena(text,i,i)='/' o SubCadena(text,i,i)='.')  y (i=l o i=1) Entonces
			sigue<-Falso
			Escribir "ERROR.La entrada de datos no es correcta"
		Fin Si
		Si sigue y Subcadena(text,i,i)='-' y i=l Entonces
			sigue <-Falso
			Escribir "ERROR.La entrada de datos no es correcta"
		FinSi
		i<-i+1
	Fin Mientras
	Si sigue Entonces
		Si cont>1 Entonces
			Escribir "ERROR. La entrada de datos no es correcta"
			sigue<-Falso
		Fin Si
	Fin Si
	Si sigue Entonces
		Para i<-1 Hasta l Con Paso 1 Hacer
			Si SubCadena(text,i,i)='-' Y i<>1 y i<>ind+1 Entonces
				Escribir "ERROR.La entrada de datos no es correcta"
				sigue<-Falso
			Fin Si
		Fin Para
	Fin Si
	Si sigue Entonces
		Si cont=1 Entonces
			den<-ConvertirANumero(SubCadena(text,ind+1,l))
			Si den=0 Entonces
				sigue<-Falso
				Escribir "ERROR.No está definida la división entre cero"
			FinSi
		FinSi
	FinSi
	//separamos numerador y denominador
	Si sigue Entonces
		Si cont=1 Entonces
			den<-ConvertirANumero(SubCadena(text,ind+1,l))
			num<-ConvertirANumero(SubCadena(text,1,ind-1))
		Sino
			den<-1
			num<-ConvertirANumero(text)
		Fin Si
		Convertir_reales(num,den)
		numer<-ConvertirANumero(ConvertirATexto(num))
		denom<-ConvertirANumero(ConvertirATexto(den))
		Simplificar(numer,denom)
		Si denom=1 Entonces
			frac<- ConvertirATexto(numer)
		Sino
			frac<-ConvertirATexto(numer)+"/"+convertiratexto(denom)
		FinSi
		text<-frac
	Fin Si
FinSubProceso

SubProceso Recorrido(mat,p,q,m,n)
	//Var
	Definir i,j,l,k,esp1,esp2 Como Entero
	Definir aux Como Caracter
	
	//inicio
	Para i<-p Hasta m Con Paso 1 Hacer
		aux<-""
		Para j<-q Hasta n Con Paso 1 Hacer
			l<-Longitud(mat[i,j])
			aux<-aux+"("
			Si ((9-l) mod 2 =0) Entonces
				esp1<-(9-l)/2
				esp2<-esp1
			Sino
				esp1<-(10-l)/2
				esp2<-esp1-1
			Fin Si
			Para k<-1 Hasta esp1 Con Paso 1 Hacer
				aux<-aux+" "
			Fin Para
			aux<-aux+ mat[i,j]
			Para k<-1 Hasta esp2 Con Paso 1 Hacer
				aux<-aux+" "
			Fin Para
			aux<-aux+") "
		Fin Para
		Escribir aux
	Fin Para
FinSubProceso

SubProceso Separar(frac,num Por Referencia,den Por Referencia)
	//Este proceso separa el numerador y denominador
	//var
	Definir i,l Como Entero
	//inicio
	l<-longitud(frac) 
	i<-1
	mientras i<=l y Subcadena(frac,i,i)<>'/' Hacer
		i<-i+1
	FinMientras
	num<-ConvertirANumero(SubCadena(frac,1,i-1))
	Si subcadena(frac,i,i)='/' Entonces
		den<-ConvertirANumero(Subcadena(frac,i+1,l))
	Sino
		den<-1
	FinSi
FinSubProceso

Subproceso s<-Sum(a,b)
	//var
	Definir s Como Caracter
	Definir num_a,num_b,den_a,den_b,num_c,den_c Como Entero
	
	//inicio
	//separamos numerador y denominador de "a"
	Separar(a,num_a,den_a)
	//separamos numerador y denominador de "b"
	Separar(b,num_b,den_b)
	//Calculamos la suma
	num_c<-(num_a*den_b)+(num_b*den_a)
	den_c<- den_a*den_b
	Simplificar(num_c,den_c)
	Si(den_c<>1) Entonces
		s<-ConvertirATexto(num_c)+'/'+ConvertirATexto(den_c)
	Sino
		s<-ConvertirATexto(num_c)
	FinSi
FinSubProceso

SubProceso s<-Prod(a,b)
	//var
	Definir s Como Caracter
	Definir num_a,num_b,den_a,den_b,num_c,den_c Como Entero
	
	//inicio
	//separamos numerador y denominador de "a"
	Separar(a,num_a,den_a)
	//separamos numerador y denominador de "b"
	Separar(b,num_b,den_b)
	//Calculamos el producto
	num_c<-num_a*num_b
	den_c<-den_a*den_b
	Simplificar(num_c,den_c)
	Si(den_c<>1) Entonces
		s<-ConvertirATexto(num_c)+'/'+ConvertirATexto(den_c)
	Sino
		s<-ConvertirATexto(num_c)
	FinSi
FinSubProceso

SubProceso s<-Restar(a,b)
	//var
	Definir s Como Caracter
	//inicio
	s<-Sum(a,Prod(b,"-1"))
FinSubProceso

SubProceso s<-Invierte(a)
	//var
	Definir s Como Caracter
	Definir num_a,den_a,num_c,den_c Como Entero
	
	//inicio
	//separamos numerador y denominador de "a"
	Separar(a,num_a,den_a)
	num_c<-den_a
	den_c<-num_a
	Simplificar(num_c,den_c)
	Si(den_c<>1) Entonces
		s<-ConvertirATexto(num_c)+'/'+ConvertirATexto(den_c)
	Sino
		s<-ConvertirATexto(num_c)
	FinSi
FinSubProceso

SubProceso Intercambio(mat Por Referencia,i,j,n)
	// "i" y "j" son las filas a intercambiar. "n" es el número de columnas de la matriz 
	//var
	Definir aux Como Caracter
	Definir k Como Entero
	
	//inicio
	Para k<-1 Hasta n Con Paso 1 Hacer
		aux<-mat[i,k]
		mat[i,k]<-mat[j,k]
		mat[j,k]<-aux
	Fin Para
	
FinSubProceso

SubProceso f<-nonull(mat Por Referencia,n,i)
	//Esta función tendrá como parámetros, la matriz, la cantidad total columnas y una fila "i" para analizar
	//Luego, en esa fila, buscará a partir de la columna 1, la primera columna "j" cuyo elemento sea diferente de 0 y nos la dará como respuesta
	//Esto nos servirá para ordenar las filas de la matriz (en orden creciente al nonull)
	
	//var
	Definir termina Como Logico
	Definir k,f como entero
	
	//inicio
	termina<-Falso
	k<-1
	mientras no termina y k<=n Hacer
		Si mat[i,k]<>"0" entonces
			f<-k
			termina<-Verdadero
		Sino
			k<-k+1
		FinSi
	FinMientras
	Si (No termina) Entonces
		f<-100
	FinSi
	
FinSubProceso

SubProceso Orden(mat por referencia,m,n,cont Por Referencia)
	//Ordena en forma creciente según nonull
	//var
	Definir i,j Como Entero
	
	//inicio
	Para i<-1 Hasta m-1 Con Paso 1 Hacer
		Para j<-i+1 Hasta m Con Paso 1 Hacer
			Si nonull(mat,n,i)>nonull(mat,n,j) Entonces
				Intercambio(mat,i,j,n)
				cont<-cont+1
			FinSi
		Fin Para
	Fin Para
	
FinSubProceso

SubProceso null<-Nulidad(mat,m,n)
	// Da la cantidad de filas nulas
	//var
	Definir i,j,cont,null como entero
	Definir todonull Como Logico
	//inicio
	cont<-0
	Para i<-1 Hasta m Con Paso 1 Hacer
		todonull<-Verdadero
		Para j<-1 Hasta n Con Paso 1 Hacer
			Si mat[i,j]<>"0" Entonces
				todonull<-Falso
			FinSi
		Fin Para
		Si (todonull) Entonces
			cont<-cont+1
		FinSi
	Fin Para
	null<-cont
FinSubProceso

Subproceso Escalonar(mat por referencia, m,n,cont Por Referencia,det Por Referencia)
	//var
	Definir cont2,i,j,nulo,k,p como entero
	Definir termina Como Logico
	Definir aux Como Caracter
	
	//inicio
	i<-1
	j<-1
	Mientras i<=m  Hacer
		cont2<-0
		Orden(mat,m,2*n,cont2)
		cont<-cont+cont2 //el cont es para saber cuantos intercambios han habido en total y luego el determinante multiplicarlo por (-1)^cont
		nulo<-Nulidad(mat,m,n)
		termina<-Falso
		mientras j<=n y no termina Hacer
			Si mat[i,j]<>"0" Entonces
				//toda la fila analizada se divide entre el primer término diferente de 0
				det<-Prod(det,mat[i,j])
				aux<-Invierte(mat[i,j])
				Para k<-j Hasta (2*n) Con Paso 1 Hacer
					mat[i,k]<-Prod(mat[i,k],aux)
				Fin Para
				//todas las filas de abajo no nulas les restamos "t" veces la la fila analizada anteriormente. 
				//Siendo "t" un número adecuado para anular todos los elementos que estén abajo del elemento "mat[i,j]" analizado
				Para k<-i+1 Hasta m-nulo Con Paso 1 Hacer
					aux<-mat[k,j]
					Para p<-j Hasta (2*n) Con Paso 1 Hacer
						mat[k,p]<-Restar(mat[k,p],Prod(aux,mat[i,p]))
					Fin Para
				Fin Para
				termina<-Verdadero
			FinSi
			j<-j+1
		FinMientras
		i<-i+1
	Fin Mientras
	
FinSubProceso

Subproceso Escalonar_hacia_arriba(mat Por Referencia,m,n)
	//
	
	//var
	Definir i,j,k,p como entero
	Definir aux Como Caracter
	//inicio
	i<-m
	j<-n
	Mientras i>0  Hacer
		//todas las filas de arriba no nulas les restamos "t" veces la la fila analizada anteriormente. 
		//Siendo "t" un número adecuado para anular todos los elementos que estén abajo del elemento "mat[i,j]" analizado
		Para k<-1 Hasta i-1 Con Paso 1 Hacer
			aux<-mat[k,j]
			Para p<-j Hasta (2*n) Con Paso 1 Hacer
				mat[k,p]<-Restar(mat[k,p],Prod(aux,mat[i,p]))
			Fin Para
		Fin Para
		j<-j-1
		i<-i-1
	Fin Mientras
FinSubProceso

Proceso Algoritmo
	//Var
	Definir i,j,k,l,esp1,esp2,p,rango,cont Como Entero
	Definir m,n Como Real
	Definir sigue,termina como logico
	Definir mtext,ntext,text,aux,cambio,itext,jtext,det,mat Como Caracter
	Dimension mat[20,20]
	
	//Inicio
	Escribir "Este algoritmo permite hallar el rango de la matriz. También haya el determinante y la matriz inversa en caso se pueda"
	Escribir ""
	//Lectura
	Escribir "Ingrese el número de filas de su matriz (máximo 10)"
	Repetir
		Leer mtext
		Segun mtext Hacer
			"1","2","3","4","5","6","7","8","9","10":
				m<-ConvertirANumero(mtext)
				sigue<-Verdadero
				Escribir "El número de filas ha sido ingresado correctamente"
			De Otro Modo:
				Escribir "ERROR en la entrada de datos. Vuelva a escribir el número de filas"
				sigue<-Falso
		Fin Segun
	Hasta Que sigue
	Esperar 1.5 segundos
	Escribir ""
	Escribir "Ingrese el número de columnas de su matriz (máximo 10)"
	Repetir
		Leer ntext
		Segun ntext Hacer
			"1","2","3","4","5","6","7","8","9","10":
				n<-ConvertirANumero(ntext)
				sigue<-Verdadero
				Escribir "El número de columnas ha sido ingresado correctamente"
			De Otro Modo:
				Escribir "ERROR en la entrada de datos. Vuelva a escribir el número de columnas"
				sigue<-Falso
		Fin Segun
	Hasta Que sigue
	Escribir ""
	Escribir "Presione Enter para continuar"
	Esperar Tecla
	Limpiar Pantalla
	Escribir "Su matriz es de ",m,"x",n
	Esperar 1 segundos
	Escribir ""
	Escribir "A continuación ingresará los elementos de la matriz"
	Esperar 2 segundos
	Escribir ""
	Escribir "Puede ingresar números positivos, negativos, decimales. Los decimales también los puede ingresar como fracción"
	Esperar 2 Segundos
	Escribir ""
	Escribir "En caso quiera ingresar una fracción, hágalo separando el numerador y el denominador por un entre(/). Ejemplo: 45/8"
	Esperar 2 Segundos
	Escribir ""
	Escribir "Presione Enter para continuar"
	Esperar Tecla
	Escribir ""
	sigue<-Verdadero
	Para i<-1 Hasta m Con Paso 1 Hacer
		Para j<-1 Hasta n Con Paso 1 Hacer
			Escribir "Ingrese el el elemento (",i,",",j,")"
			Repetir
				Lectura(sigue,text)
				Si (no sigue) Entonces
					Escribir "Ingrese nuevamente el elemento (",i,",",j,")"
				FinSi
			Hasta Que sigue
			mat[i,j] <-text
		Fin Para
	Fin Para
	Escribir ""
	Escribir "Se ingresaron todos los elementos." 
	Esperar 1.4 segundos
	Escribir "Presione Enter para ver la matriz en pantalla"
	Esperar Tecla
	Limpiar Pantalla
	//Se muestra la matriz
	Escribir "La matriz que usted ingresó es la siguiente"
	Recorrido(mat,1,1,m,n)
	Escribir ""
	Repetir
		Escribir "¿Desea cambiar algún elemento? Responder solo con (S) o (N) o , en su defecto, (s) o (n)"
		Repetir
			Leer cambio
			Si NO(cambio='S' o cambio='N' o cambio ='s' o cambio='n') Entonces
				Escribir "ERROR. Solo puede ser o (S) o (N) o, en su defecto, (s) o (n). VUELVA A ESCRIBIR SU RESPUESTA"
			Fin Si
		Hasta Que cambio='S' o cambio='N' o cambio ='s' o cambio='n'
		Si cambio='S' o cambio='s' Entonces
			Escribir "Inserte la fila del elemento que quiere cambiar"
			Repetir
				Leer itext
				Segun itext Hacer
					"1","2","3","4","5","6","7","8","9","10":
						i<-ConvertirANumero(itext)
						Si i>m Entonces
							sigue<-Falso
							Escribir "ERROR. Recuerde que la fila debe ser un entero entre 0 y " ,m,". VUELVA A ESCRIBIR LA FILA"
						Sino
							sigue<-Verdadero
						Fin Si
					De Otro Modo:
						Escribir "ERROR. Recuerde que la fila debe ser un entero entre 0 y " ,m,". VUELVA A ESCRIBIR LA FILA"
						sigue<-Falso
				Fin Segun
			Hasta Que sigue
			Escribir "Inserte la columna del elemento que quiere cambiar"
			Repetir
				Leer jtext
				Segun jtext Hacer
					"1","2","3","4","5","6","7","8","9","10":
						j<-ConvertirANumero(jtext)
						Si j>n Entonces
							sigue<-Falso
							Escribir "ERROR. Recuerde que la columna debe ser un entero entre 1 y " ,n,". VUELVA A ESCRIBIR LA COLUMNA"
						Sino
							sigue<-Verdadero
						FinSi
					De Otro Modo:
						Escribir "ERROR. Recuerde que la columna debe ser un entero entre 1 y " ,n,". VUELVA A ESCRIBIR LA COLUMNA"
						sigue<-Falso
				Fin Segun
			Hasta Que sigue
			Escribir ""
			Escribir "Usted quiere cambiar el elemento ","(",i,",",j,")", " que es igual a ", mat[i,j]
			Escribir ""
			Escribir "Ingrese el número que reemplazará a ese elemento de la matriz"
			Repetir
				Lectura(sigue,text)
				Si (no sigue) Entonces
					Escribir "Ingrese nuevamente el elemento (",i,",",j,")"
				FinSi
			Hasta Que sigue
			mat[i,j] <-text
			Escribir "El cambio se ha efectuado correctamente. Presione Enter para ver la nueva matriz"
			Esperar Tecla
			Limpiar Pantalla
			Escribir "La nueva matriz es la siguiente"
			Recorrido(mat,1,1,m,n)
		Fin Si
	Hasta Que cambio='N' o cambio='n'
	Escribir ""
	//Hallando el rango y determinante y la inversa
	Si m=n entonces
		Para i<-1 Hasta m Con Paso 1 Hacer
			Para j<-m+1 Hasta 2*m Con Paso 1 Hacer
				//Adjuntamos la matriz identidad al costado
				Si j-m=i Entonces
					mat[i,j]<-"1" 
				Sino
					mat[i,j]<-"0"
				FinSi
			Fin Para
		Fin Para
	FinSi
	det<-"1"
	cont<-0
	Escalonar(mat,m,n,cont,det)
	Si cont mod 2 <>0 Entonces
		det<-Prod(det,"-1")
	FinSi
	rango<-m-Nulidad(mat,m,n)
	Escribir "El rango es: ",rango
	Si m=n Entonces
		Si rango=m Entonces
			Escribir "El determinante es: ",det
			Escribir "La matriz inversa es: "
			Escalonar_hacia_arriba(mat,m,n)
			Recorrido(mat,1,n+1,m,2*n)
		Sino
			Escribir "El determinante es: ",0
			Escribir "Por lo tanto, no tiene inversa"
		FinSi
	Sino
		Escribir "La matriz no es cuadrada. Por lo tanto no tiene determinante ni inversa"
	FinSi
FinAlgoritmo