Algoritmo KNN
	Definir _x, _y como Real
	Escribir "Ingrese el punto a clasificar (x, y):"
	Leer _x
	Leer _y
	
	Definir listo como Logico
	listo <- Falso
	
	Definir x_auxiliar, y_auxiliar como Real
	Definir distancia_auxiliar, distancia_1, distancia_2, distancia_3 como Real
	Definir clase_auxiliar, clase_1, clase_2, clase_3 como Caracter
	Definir cantidad como Entero
	cantidad <- 0
	distancia_1 <- 1000000000
	distancia_2 <- 1000000000
	distancia_3 <- 1000000000
	
	Mientras (!listo) hacer
		Escribir "Ingrese los datos del punto (x, y, clase):"
		Leer x_auxiliar
		Leer y_auxiliar
		Leer clase_auxiliar
		Si (x_auxiliar = 0 y y_auxiliar = 0) Entonces
			listo <- Verdadero
		SiNo
			Si (clase_auxiliar = 'A' o clase_auxiliar = 'B') Entonces
				distancia_auxiliar <- Raiz((_x - x_auxiliar) * (_x - x_auxiliar) + (_y - y_auxiliar) * (_y - y_auxiliar))
				Si (distancia_auxiliar < distancia_1) Entonces
					distancia_3 <- distancia_2
					clase_3 <- clase_2
					distancia_2 <- distancia_1
					clase_2 <- clase_1
					distancia_1 <- distancia_auxiliar
					clase_1 <- clase_auxiliar
				SiNo
					Si (distancia_auxiliar < distancia_2) Entonces
						distancia_3 <- distancia_2
						clase_3 <- clase_2
						distancia_2 <- distancia_auxiliar
						clase_2 <- clase_auxiliar
					SiNo
						Si (distancia_auxiliar < distancia_3) Entonces
							distancia_3 <- distancia_auxiliar
							clase_3 <- clase_auxiliar
						FinSi
					FinSi
				FinSi
				cantidad <- cantidad + 1
			SiNo
				Escribir "La clase es invalida, no se considerara este punto."
			FinSi
		FinSi
	FinMientras
	
	Definir cantidad_a, cantidad_b como Entero
	cantidad_a <- 0
	cantidad_b <- 0
	Si (cantidad >= 3) Entonces
		Si (clase_1 = 'A') Entonces
			cantidad_a <- cantidad_a + 1
		SiNo
			cantidad_b <- cantidad_b + 1
		FinSi
		Si (clase_2 = 'A') Entonces
			cantidad_a <- cantidad_a + 1
		SiNo
			cantidad_b <- cantidad_b + 1
		FinSi
		Si (clase_3 = 'A') Entonces
			cantidad_a <- cantidad_a + 1
		SiNo
			cantidad_b <- cantidad_b + 1
		FinSi
		
		Si (cantidad_a >= 2) Entonces
			Escribir "El punto ingresado corresponde a la clase A"
		SiNo
			Escribir "El punto ingresado corresponde a la clase B"
		FinSi
	SiNo
		Escribir "No se ingresaron datos suficientes para resolver el problema"
	FinSi
FinAlgoritmo
