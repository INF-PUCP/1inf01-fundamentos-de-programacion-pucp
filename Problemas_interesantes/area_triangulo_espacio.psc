Proceso area_triangulo_espacio
	Definir x1,y1,z1,x2,y2,z2,x3,y3,z3,S Como Real
	Escribir "Ingrese las coordenadas del punto A=(x1,y1,z1) //Pulse enter luego de ingresar una coordenada"
	Leer x1,y1,z1
	Escribir "Ingrese las coordenadas del punto B=(x2,y2,z2) //Pulse enter luego de ingresar una coordenada"
	Leer x2,y2,z2
	Escribir "Ingrese las coordenadas del punto C=(x3,y3,z3) //Pulse enter luego de ingresar una coordenada"
	Leer x3,y3,z3
	S<-(raiz(((y2-y1)*(z3-z1)-(z2-z1)*(y3-y1))*((y2-y1)*(z3-z1)-(z2-z1)*(y3-y1))+((x2-x1)*(z3-z1)-(z2-z1)*(x3-x1))*((x2-x1)*(z3-z1)-(z2-z1)*(x3-x1))+((x2-x1)*(y3-y1)-(y2-y1)*(x3-x1))*((x2-x1)*(y3-y1)-(y2-y1)*(x3-x1))))/2
	si S=0
		si x1=x2 y x2=x3 y y1=y2 y y2=y3 y z1=z2 y z2=z3
			Escribir "Las 3 vértices representan un solo punto por lo que el área sería 0 u"
		Sino
			Escribir "Los 3 puntos son colineales y por lo tanto el área es 0 u"
		FinSi
	Sino
		Escribir "El área del triángulo es ",S," u"
	FinSi
FinProceso
