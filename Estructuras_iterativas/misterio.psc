Algoritmo misterio
	Definir  a,n,x,z,i,j,k como entero
	Definir s Como Real
	Leer a
	Leer n
	s<-0
	i<-1
	mientras i<=n
		z<-1
		j<-1
		Repetir
			z <- z*j
			j <- j+1
		Hasta Que j > i
		x <- 1
		para k <- 1 hasta n -i +1
			x <- x*a
		FinPara
		s <- s + 1.0*x/z
		i <- i + 1
	FinMientras
	Escribir "El valor de s es ",s
FinAlgoritmo
