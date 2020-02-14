Proceso busca_palabra_en_oracion
	Definir palabra,oracion Como Caracter
	Definir cont,i,j como entero
	Escribir "Ingrese una oracion"
	leer oracion
	Escribir "Ingrese la palabra a buscar"
	leer palabra
	cont<-0
	para i<-0 hasta Longitud(oracion)-1
		si i=0 y Subcadena(oracion,i,i)<>' '
			j<-i
			Mientras j<=Longitud(oracion)-1 y Subcadena(oracion,j,j)<>' '
				si j=Longitud(oracion)-1 y Subcadena(oracion,j,j)<>' '
					si j-i+1=longitud(palabra)
						si Subcadena(oracion,i,j)=palabra
							cont<-cont+1
						FinSi
					FinSi
				Sino
					si subcadena(oracion,j,j)<>' ' y subcadena(oracion,j+1,j+1)=' '
						si j-i+1=longitud(palabra)
							si Subcadena(oracion,i,j)=palabra
								cont<-cont+1
							FinSi
						FinSi
					FinSi
				FinSi
				j<-j+1
			FinMientras
		Sino
			si Subcadena(oracion,i,i)<>' ' y subcadena(oracion,i-1,i-1)=' '
				j<-i
				Mientras j<=Longitud(oracion)-1 y Subcadena(oracion,j,j)<>' '
					si j=Longitud(oracion)-1 y Subcadena(oracion,j,j)<>' '
						si j-i+1=longitud(palabra)
							si Subcadena(oracion,i,j)=palabra
								cont<-cont+1
							FinSi
						FinSi
					Sino
						si subcadena(oracion,j,j)<>' ' y subcadena(oracion,j+1,j+1)=' '
							si j-i+1=longitud(palabra)
								si Subcadena(oracion,i,j)=palabra
									cont<-cont+1
								FinSi
							FinSi
						FinSi
					FinSi
					j<-j+1
				FinMientras
			FinSi
		FinSi
	FinPara
	si cont=0
		Escribir "La palabra *",palabra,"* no aparece en la oracion *",oracion,"*."
	Sino
		si cont=1
			Escribir "La palabra *",palabra,"* aparece 1 vez en la oracion *",oracion,"*."
		Sino
			Escribir "La palabra *",palabra,"* aparece ",cont," veces en la oracion *",oracion,"*."
		FinSi
	FinSi
FinProceso