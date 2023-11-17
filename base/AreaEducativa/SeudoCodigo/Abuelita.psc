// Abuelita.psc
// Octulio Biletán * Nov. 2023
// Ejecutar desde la consola de textos:
// pseint --nouser Abuelita.psc

Proceso Abuelita
	Definir tecla Como Cadena;
	Definir sueldo Como Real;
	Definir pabu, phijo, pnieto Como Real;
	Definir monto1, monto2, monto3 Como Real;
	Definir hijos, nietos Como Entero;
	
	hijos <- 2;
	nietos <- 3;
	
	// 14 %  para la abuelita
	pabu <- 0.14;
	
	// 19 %  para cada hijo (2)
	phijo <- 0.19;
	
	// 16 %  para cada nieto (3)
	pnieto <- 0.16;
	
	Escribir 'Ejemplo 01';
	Escribir 'Ingrese el sueldo de la abuelita $: ';
	Leer sueldo;
	
	monto1 <- sueldo * pabu;
	monto2 <- sueldo * phijo;
	monto3 <- sueldo * pnieto;
	
	Escribir '--Reparto del sueldo de la abuelita con sus familiares--';
	Escribir 'Abuelita: ', pabu * 100, '%';
	Escribir 'Monto a percibir: $', monto1;
	Escribir 'Hijos: ', hijos;
	Escribir 'Le corresponde a cada hijo: ', phijo * 100, '%';
	Escribir 'Monto a percibir: $', monto2;
	Escribir 'Nietos: ', nietos;
	Escribir 'Le corresponde a cada nieto: ', pnieto * 100, '%';
	Escribir 'Monto a percibir: $', monto3;
	Escribir '';
	Escribir '**Detalle**';
	Escribir '$', sueldo, ' = ', monto1, ' + ', monto2 * hijos, ' + ', monto3 * nietos;
	
	Escribir 'Presione tecla Intro...';
	Leer tecla;
FinProceso
