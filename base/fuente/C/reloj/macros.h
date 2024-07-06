/* MACROS.H  --- Eugenio Mart¡nez  --- Tucum n    */
/* 		 Definiciones de macros m s usuales */

#if !defined(__MACEOX__)
#   define __MACEOX__	   /* constante de MACROS.H */

/* Mejor en espa¤ol */
#define Principio  main

/* Ciclo do...loop
   Usar: do
	 {

	    cuerpo;

	 }loop;
*/
#define loop        while(1)

/* Ciclo do...until
   Usar: do
	 {
	   cuerpo;
	 } until(cond);
*/
#define until(cond) while(!(cond))

/* Ciclo repeat(n)
   Usar: repeat(n)
	 {
	   cuerpo;
	 }

   V lido £nicamente para C++
*/
#define repeat(n)  for(unsigned int a = 0; a < n; a++)

/* Comprobar si 'exp1' y 'exp2' es verdadera(1) o falsa(0) */
#define test(exp1, exp2)	exp1 && exp2 ? 1 : 0

/* Compruebe si 'exp1' y 'exp2' es cierta ... de lo contrario ...
   Sintaxis:
	 variable = iftest(exp1, exp2) istrue expverdad otherwise expfalsa
*/
#define iftest(exp1, exp2)	exp1 && exp2
#define istrue			?
#define otherwise		:

/* Si la 'expresion' es cierta ... */
#define iftrue(expresion)	if(expresion)

/* Si la 'expresion' es falsa ... */
#define iffalse(expresion)	if(!expresion)

#ifndef __linux__
/* Comparar si ambas expresiones, 'exp1' y 'exp2', son iguales entonces es
   cierto(1) o falso(0)
*/
#define comparexp(exp1, exp2)	exp1 == exp2 ? 1 : 0

#endif

/* Comparar si ambas expresiones, 'exp1' y 'exp2', son iguales
   Sintaxis:
	 variable = ifcompare(exp1, exp2) istrue expverdad otherwise expfalsa
*/
#define ifcompare(exp1, exp2)	exp1 == exp2

/* if(expresion) then sentenciasA else sentenciasB */
#define then

/* Selecci¢n m£ltiple 'multichoice optfor else leave'.
   Es similar a 'switch case default break'.
   Sintaxis general:
	multichoice(expresion-constante)
	{
	  optfor(expresionA)
	  {
	    sentenciasA
	    leave;
	  }
	[ else
	  {
	    sentenciasAA
	    leave;
	  }
	]
	  optfor(expresionB)
	  {
	    sentenciasB
	    leave;
	  }
	[ else
	  {
	    sentenciasBB
	    leave;
	  }
	]
	  ...
	}

Las l¡neas que se hallan encerradas entre corchetes, [ y ], son opcionales
*/
/* multiselecci¢n o multiescogida */
#define multichoice(var)	while(var)

/* optar por u opte por */
#define optfor(expresion)	if(expresion)

/* salga o salir */
#define leave			break

/* escoger o escoga */
#define choose(var, min, max)	while(var >= min && var <= max)

/* Ejecute la 'rutina' si la 'expresion' es cierta
   Sintaxis:
	execute(expresion, rutina)
*/
#define execute(expresion, rutina)	if(expresion) rutina

/* Construcción PERFORM UNTIL
   Es similar a la de COBOL
   Sintáxis:

	PERFORM(procedimiento) UNTIL(condición);

   Se utiliza para llamar a un "procedimiento" hasta que la "condición"
   sea cierta.
*/
#define PERFORM(f)	do { f(); }
#define UNTIL(c)	until(c)

#ifndef __linux__
#  ifndef __WATCOMC__

/* Operador lógico AND */
#    define and		&&

/* Operador lógico OR */
#    define or		||

/* Operador lógico de negación NOT */
#    define not		!

/* Operador AND sobre bits */
#    define bitand	&

/* Operador OR sobre bits */
#    define bitor	|
#  endif

/* Operador XOR sobre bits */
#define bitxor		^

#endif

/* Para Declaración y Definición de funciones */
#define Decl
#define Def

/* Para las funciones Terminar() y exit() y sentencia return */
#define OK	  		0
#define MAL	  		1
#define APLICACION_OK		OK
#define APLICACION_ERROR	MAL
#define Terminar  		exit

/* Uso de la operaci¢n 'cast' o 'molde'
   Por ejemplo:
	variable = cast(float, var1/2);
   Se fuerza a que el resultado de la divisi¢n sea un valor flotante
*/
#define cast(tipo, dato)	(tipo)dato

/* Caracter nulo */
#define NULO	  '\0'

/* Cadena nula */
#define NULSTR    ""

#ifndef __linux__
  /* Puntero gen‚rico far nulo */
  #define FARNULL   (void far *)0L

  /* Puntero far a caracter nulo */
  #define CHARFARNULL	(char far *)0L

  /* Puntero far sin signo a caracter nulo */
  #define UCHARFARNULL	(unsigned char far *)0UL

  /* Puntero gen‚rico near nulo */
  #define NEARNULL  (void near *)0
#endif

/* Puntero sin signo a caracter nulo, independiente del modelo de memoria */
#define UCHARNULL	(unsigned char *)0

/* Caracter nueva l¡nea */
#define NEWLINE	  '\n'

/* Caracter retorno de carro */
#define CR	  '\r'

/* Caracter de tabulaci¢n */
#define TB	  '\t'

/* Caracter retroceder un espacio en blanco */
#define BACKSPACE	'\b'

/* Caracter campanilla, hace sonar el altavoz interno de la PC */
#define BELL		'\a'

/* Caracter ESCAPE */
#define ESCAPE		'\x1B'

/* Caracter espacio blanco */
#define SPACE		' '

/* Interfaz entre funciones C y CPP
   Usar: Language(C)
	 ...funciones C...
	 EndLanguage
*/
#define Language(x)  extern #x {
#define EndLanguage  }

/* Macros Booleanas más usuales */

#define CIERTO		1
#define FALSO		0
#define SI		CIERTO
#define NO		FALSO

#if defined __MSDOS__ && !defined _Windows

/* Elimina definiciones anteriores de macros en Inglés */
#  undef TRUE
#  undef FALSE
#  undef ON
#  undef OFF

#  define TRUE		CIERTO
#  define FALSE		FALSO
#  define ON 		TRUE
#  define OFF 		FALSE
#endif

#endif  /* __MACEOX__ */
