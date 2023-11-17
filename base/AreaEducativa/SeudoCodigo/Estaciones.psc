// Programa : Estaciones.psc
// Autor    : Eugenio Martínez - Mayo de 2013
// Propósito: Determinar la estación del año correspondiente a la fecha ingresada por teclado.
//            Por ej.: 25 de mayo es otoño en el hemisferio sur.

// Lee la fecha ingresada desde teclado y la convierte a la forma mmdd,
// por ej. dia:25, mes:5, fec:525.
// Devuelve la fecha como un nro. entero de la forma 'mmdd', en caso de error devuelve 0.
SubProceso fec<-LeerFechaActual ()
	DEFINIR fec COMO ENTERO;
	DEFINIR dia COMO ENTERO;
	DEFINIR mes COMO ENTERO;
	DEFINIR ldia COMO LOGICO;
	DEFINIR lmes COMO LOGICO;
	
	Escribir 'Ingrese día actual (1~31): ';
	Leer dia;
	
	Escribir 'Ingrese mes actual (1~12): ';
	Leer mes;
	
	ldia <- (dia<1 | dia>31);
	lmes <- (mes<1 | mes>12);
	
	Si ldia | lmes Entonces
		Escribir 'Día/Mes ingresado incorrecto.';
		dia <- 0;
		mes <- 0;
	FinSi
	
	fec <- mes * 100 + dia;
	
FinSubProceso

// Proceso principal
Proceso EstacionesAnuales
	DEFINIR fecha COMO ENTERO;
	
	fecha <- LeerFechaActual;
	Escribir 'Fecha actual ingresada: ',fecha;
	
	Si fecha >= 321 & fecha <= 620 Entonces
		Escribir 'La fecha corresponde a Otoño';
	Sino
		Si fecha >= 621 & fecha <= 920 Entonces
			Escribir 'La fecha corresponde a Invierno';
		Sino
			Si fecha >= 921 & fecha <= 1220 Entonces
				Escribir 'La fecha corresponde a Primavera';
			Sino
				Si fecha >= 1221 & fecha <= 1231 Entonces
					Escribir 'La fecha corresponde a Verano';
				Sino
					Si fecha >= 101 & fecha <= 320 Entonces
						Escribir 'La fecha corresponde a Verano.';
					Sino
						Escribir 'Fecha incorrecta.';
					FinSi
				FinSi
			FinSi
		FinSi
	FinSi
FinProceso
