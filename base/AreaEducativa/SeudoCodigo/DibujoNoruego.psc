// Muestra en pantalla un 'dibujo Noruego' con caracteres 'X'.
// Ejemplo de una matriz de caracteres.
// Seudocódigo con ciclo Mientras y Para.
//
// Habilitar perfil: Estricto

Proceso DibujoNoruego
	definir dibujo como caracter;
	definir fila, columna, columna2 como entero;
	Dimension dibujo[11,31];
	
	// inicializa 'dibujo' a blanco
	Para fila<-0 Hasta 10 Con Paso 1 Hacer
		para columna<-0 hasta 30 Con Paso 1 Hacer
			dibujo[fila,columna] <- ' ';
		FinPara
	FinPara
	
	// comienza a colocar 'X' en dibujo
	fila <- 0; columna <- 1; columna2 <- 29;
	Mientras columna < 7 Hacer
		dibujo[fila,columna] <- 'X';
		dibujo[fila,columna2] <- 'X';
		
		fila <- fila + 1;
		columna <- columna + 1;
		columna2 <- columna2 - 1;
	FinMientras
	
	columna <- columna - 2; columna2 <- columna2 + 2;
	Mientras columna > 0 Hacer
		dibujo[fila,columna] <- 'X';
		dibujo[fila,columna2] <- 'X';
		
		fila <- fila + 1;
		columna <- columna - 1;
		columna2 <- columna2 + 1;
	FinMientras
	
	// 2º parte
	fila <- 0; columna <- 5; columna2 <- 25;
	Mientras columna < 9 Hacer
		dibujo[fila,columna] <- 'X';
		dibujo[fila,columna2] <- 'X';
		
		fila <- fila + 1;
		columna <- columna + 1;
		columna2 <- columna2 - 1;
	FinMientras
	
	dibujo[0,columna-1] <- 'X';
	dibujo[0,columna2+1] <- 'X';
	
	fila <- fila - 2;
	Mientras columna < 12 Hacer
		dibujo[fila,columna] <- 'X';
		dibujo[fila,columna2] <- 'X';
		
		fila <- fila - 1;
		columna <- columna + 1;
		columna2 <- columna2 - 1;
	FinMientras
	
	// 3º parte
	fila <- 7; columna <- 8; columna2 <- 22;
	Mientras columna > 4 Hacer
		dibujo[fila,columna] <- 'X';
		dibujo[fila,columna2] <- 'X';
		
		fila <- fila + 1;
		columna <- columna - 1;
		columna2 <- columna2 - 1;
	FinMientras
	
	dibujo[fila-1,8] <- 'X';
	dibujo[fila-1,22] <- 'X';
	
	fila <- 7; columna <- 8; columna2 <- 22;
	Mientras columna < 12 Hacer
		dibujo[fila,columna] <- 'X';
		dibujo[fila,columna2] <- 'X';
		
		fila <- fila + 1;
		columna <- columna + 1;
		columna2 <- columna2 + 1;
	FinMientras
	
	// 4º parte
	fila <- 0; columna <- 15; columna2 <- 15;
	Mientras columna > 9 Hacer
		dibujo[fila,columna] <- 'X';
		dibujo[fila,columna2] <- 'X';
		
		fila <- fila + 1;
		columna <- columna - 1;
		columna2 <- columna2 + 1;
	FinMientras
	
	dibujo[fila-1,15] <- 'X';
	
	fila <- 6; columna <- 11; columna2 <- 19;
	Mientras columna < 16 Hacer
		dibujo[fila,columna] <- 'X';
		dibujo[fila,columna2] <- 'X';
		
		fila <- fila + 1;
		columna <- columna + 1;
		columna2 <- columna2 - 1;
	FinMientras
	
	Escribir "     <-- Dibujo Noruego -->";
	escribir "";
	
        // muestra el contenido de 'dibujo'
	Para fila<-0 Hasta 10 Con Paso 1 Hacer
          Para columna<-0 hasta 30 Con Paso 1 Hacer
            escribir dibujo[fila,columna] Sin Saltar;
	  FinPara
	  escribir "";
	FinPara
FinProceso
