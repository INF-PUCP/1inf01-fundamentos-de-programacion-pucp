Proceso modulo_proyeccion
	Definir m,n,r,s Como Real
	Escribir "Ingrese las componentes del vector u (m,n) //Pulse enter luego de ingresar una coordenada"
	leer m,n
	Escribir "Ingrese las componentes del vector v (r,s) //Pulse enter luego de ingresar una coordenada"
	leer r,s
	si r=0 y s=0
		Escribir "No se puede proyectar el vector u sobre el vector nulo"
	Sino
		si (m*r+n*s)<0
			Escribir "El módulo del vector proyección de u sobre v es ",(-1)*(m*r+n*s)/(raiz(r*r+s*s))
		Sino
			Escribir "El módulo del vector proyección de u sobre v es ",(m*r+n*s)/(raiz(r*r+s*s))
		FinSi
	FinSi
FinProceso
