/* LEALINEA.C */
/* Eugenio Mart¡nez -- Enero de 2022 */
/* Define las funciones
	pause,
	delay_ms,
        getkey(),
	lealinea(),
	direct_video(),
	backspace(),
        newline y
	tab()
*/
/*
 * Licencia   : Copyright ©Eugenio Mart¡nez, 2022
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#include <conio.h>
#include <stdio.h>

#ifdef __WIN32__
#  include <windows.h>
#else
#  include <dos.h>
#endif

/* Ciclo do...until
   Usar: do
	 {
	   cuerpo;
	 } until(cond);
*/
#define until(cond) while(!(cond))

#define loop()  while(1)

int lealinea(char *entrada, int max_linea);
void delay_ms(unsigned int ms);
void pause(unsigned int sec);
unsigned int getkey(void);
void direct_video(int v);
void backspace(void);
void newline(void);
void tab(void);

/*
   lee el teclado y devuelve su c¢digo, intercepta las teclas extendidas
   reconoce c¢digos de teclas de 2 bytes o m s
   similar a getch() de <conio.h>
*/
unsigned int getkey(void)
{
	register unsigned char codigo_extendido = 0;
	unsigned int tecla = 0;
        int status = 0;

#ifdef __WIN32__
   __flush_win95_keyup_events();  /* libera la memoria intermedia del teclado */
#endif

   status = ungetch(0);  /* inserta cero en la memoria intermedia del teclado */
   if(status == EOF)
     fprintf(stderr, "[EOF]");

   do
   {
     codigo_extendido = ~codigo_extendido;	/* convierte 0 -> 1 y 1 -> 0 */
     tecla = getch();				/* invoca a getch */

   } until(tecla != 0);

   if(codigo_extendido == 0)
     tecla += 256;      /* teclas F1~F12, Alt+F1~Alt+F12, etc. */

   return tecla;
}

/*
   Lee una secuencia de caracteres hasta 'max_linea' desde el teclado
   y guarda los mismos en 'entrada'.
   En caso de ‚xito devuelve 0 sino 1.
   Termina la entrada de datos cuando se presiona la tecla [Intro].
   Reconoce la tecla [Retroceso] para borrar el caracter anterior.
   Hace sonar el altavoz de la PC cuando se alcanza el l¡mite permitido
   de caracteres a leer.
   similar a cgets() de <conio.h>
*/
int lealinea(char *entrada, int max_linea)
{
	unsigned int caracter = 0;
	int n = 0;
	int tope = 0;

   if(max_linea < 1)
     return 1;	/* error en 'max_linea' */

   if(entrada == NULL)
     return 1;  /* error porque 'entrada' contiene un puntero nulo */

   loop()	/* inicia ciclo repetitivo */
   {
     caracter = getkey();  /* lee tecla */

     if(caracter == 269)  /* tecla [Intro] presionada */
       break;		   /* sale del ciclo repetitivo */

     if(caracter == 264 && tope == 1)	/* en el tope alcanzado */
     {
       tope = 0;
       backspace();			/* retrocede un lugar */

       n--;
       entrada[n] = '\0';               /* elimina el £ltimo caracterer */

       continue;                        /* contin£a leyendo el teclado */
     }

     if(n < max_linea)
     {
       if((unsigned char)caracter > 31 && (unsigned char)caracter <= 255)   /* acepta caracteres imprimibles */
       {
	 putch(caracter);
	 entrada[n] = (unsigned char)caracter;
	 n++;
       }
       else				/* analiza caracteres especiales */
	 if(caracter == 264)		/* tecla [Retroceso] presionada */
	 {
	   if(n == 0)			/* sin caracteres recibidos */
	     putchar('\a');		/* suena el altavoz interno */
	   else
	   {
	     backspace();		/* retrocede un lugar */
	     n--;
	     entrada[n] = '\0';		/* elimina el £ltimo caracterer */
	   }
	 }
	 else
	   putchar('\a');		/* suena el altavoz interno */
     }
     else
     {
       putchar('\a');			/* suena el altavoz interno */
       tope = 1;			/* tope alcanzado */
     }
   }	/* finaliza ciclo repetitivo */

   entrada[n] = '\0';		/* da por finalizada la entrada de datos */
   return 0;			/* entrada exitosa de datos */
}

/* Retrocede el cursor horizontalmente un espacio sobre la pantalla */
void backspace(void)
{
   gotoxy(wherex()-1, wherey());
   putch(32);
   gotoxy(wherex()-1, wherey());
}

/* Avanza el cursor horizontalmente ocho espacios sobre la pantalla */
void tab(void)
{
   gotoxy(wherex() + 8, wherey());
}

/* Realiza un avance de l¡nea, mueve el cursor a la siguiente l¡nea */
void newline(void)
{
   putch(10); putch(13);
}

/*
   Efect£a una pausa en la ejecuci¢n del programa
   hasta que se presiona cualquier tecla.
   Cuando 'sec' es igual a 0, espera por cualquier tecla que se va a presionar.
   Cuando 'sec' es mayor a 0, deja transcurrir un tiempo de espera (en segundos)
   y no lee el teclado.
*/
void pause(unsigned int sec)
{
   if(sec == 0)
   {
     while(!kbhit())
       ;
   }
   else
     delay_ms(sec * 1000);
}

/* Activa la salida por pantalla de manera directa o no
   v = 0 desactivado
   v = 1 activado
 */
void direct_video(int v)
{
#ifdef __WIN32__
   _directvideo = v;  /* para compilador de 32 bits Borland C++ */
#else
   directvideo = v;  /* para compilador de 16 bits Borland C++ */
#endif
}

// Efect£a una demora (milisegundos) en la ejecuci¢n del programa
void delay_ms(unsigned int ms)
{
#ifdef __WIN32__
   Sleep(ms);	/* para aplicaciones que corren en Windows/32 bits */
#else
   delay(ms);   /* para aplicaciones que corren en MS-DOS/16 bits */
#endif
}

void main(void)
{
	int edad = 0;
	int estado = 0;
	char sin_dato[] = "<sin datos>";
	char nombre_apellido[96] = { "" };
	char domicilio_particular[96] = { "" };
	char numero[3] = { "" };

   direct_video(0);
   clrscr();

   /* Visualiza los títulos */
   cputs("<< Ejercicio de programaci¢n C >>");
   gotoxy(1, wherey() + 1); cputs("Uso de las funciones de conio.h");
   gotoxy(1, wherey() + 2); cputs("Ficha personal");

   /* Solicita la entrada de datos */
   gotoxy(1, wherey() + 1); cprintf("Ingrese su nombre y apellido   : ");
   estado = lealinea(nombre_apellido, 20);

   if(estado == 1)
     cprintf("\n\rError en el ingreso de datos: %s\n\r", nombre_apellido);

   newline();

   cprintf("Ingrese su edad                : ");
   estado = lealinea(numero, 2);
   sscanf(numero, "%d", &edad);

   newline();

   cputs("Ingrese su domicilio particular: ");
   domicilio_particular[0] = 80;
   cgets(domicilio_particular);

   clrscr();

   /* Visualiza los datos ingresados */
   cputs("Los datos ingresados fueron los siguientes");
   newline();

   if(nombre_apellido[0] != '\0')
     cprintf("Nombre y apellido   : %s", nombre_apellido);
   else
     cprintf("Nombre y apellido   : %s", sin_dato);

   newline();

   if(edad > 0)
     cprintf("Edad                : %d", edad);
   else
     cprintf("Edad                : %s", sin_dato);

   newline();

   if(domicilio_particular[1] > 0)
     cprintf("Domicilio particular: %s", &domicilio_particular[2]);
   else
     cprintf("Domicilio particular: %s", sin_dato);

   newline(); newline();
   cputs("Ficha personal lista para ser guardada en la base de datos.");

   pause(5);
}
