/* LEALINEA.C */
/* Eugenio Mart¡nez -- Enero de 2022 */
/* Define la funci¢n lealinea(), backspace() y tab() */

#include <conio.h>
#include <stdio.h>

int lealinea(char *entrada, int max_linea);
void backspace(void);
void tab(void);

/*
   Lee una secuencia de caracteres hasta 'max_linea' desde el teclado
   y guarda los mismos en 'entrada'.
   En caso de ‚xito devuelve 0 sino 1.
   Termina la entrada de datos cuando se presiona la tecla [Intro]
*/
int lealinea(char *entrada, int max_linea)
{
	int caracter = 0, n = 0;
	int tope = 0;

   if(max_linea < 1)
     return 1;	/* error en 'max_linea' */

   if(entrada == NULL)
     return 1;  /* error porque 'entrada' contiene un puntero nulo */

   while(1)	/* inicia ciclo while() */
   {
     caracter = getch();   /* lee tecla */
     if(caracter == '\r')  /* tecla [Intro] presionada */
       break;		   /* sale del ciclo while() */

     if(caracter == 8 && tope == 1)	/* en el tope alcanzado */
     {
       tope = 0;
       backspace();			/* retrocede un lugar */

       n--;
       entrada[n] = '\0';               /* elimina el £ltimo caracterer */

       continue;                        /* contin£a leyendo el teclado */
     }

     if(n < max_linea)
     {
       if(caracter > 31)		/* acepta caracteres imprimibles */
       {
	 putch(caracter);
	 entrada[n] = caracter;
	 n++;
       }
       else				/* analiza caracteres especiales */
	 if(caracter == 8)		/* tecla [Retroceso] presionada */
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
   }	/* finaliza ciclo while() */

   entrada[n] = '\0';		/* da por finalizado la entrada de datos */
   return 0;			/* entrada de datos con ‚xito */
}

/* Retrocede el cursor horizontalmente un espacio sobre la pantalla */
void backspace(void)
{
   gotoxy(wherex()-1, wherey());
   putch(' ');
   gotoxy(wherex()-1, wherey());
}

/* Avanza el cursor horizontalmente ocho espacios sobre la pantalla */
void tab(void)
{
   gotoxy(wherex()+8, wherey());
}

void main(void)
{
	int edad = 0;
	int estado = 0;
	char sin_dato[] = "<sin datos>";
	char nombre_apellido[96] = { "" };
	char numero[3] = { "" };

   directvideo = 0;
   clrscr();

   cputs("<< Ejercicio de programaci¢n C >>");
   gotoxy(1, wherey() + 1); cputs("Uso de las funciones de conio.h");

   gotoxy(1, wherey() + 2); cprintf("Ingrese nombre y apellido: ");
   estado = lealinea(nombre_apellido, 20);

   if(estado == 1)
     cprintf("\n\rError en el ingreso de datos: %s\n\r", nombre_apellido);

   cprintf("\n\rIngrese la edad          : ");
   estado = lealinea(numero, 2);

   sscanf(numero, "%d", &edad);

   clrscr();
   cputs("Los datos ingresados fueron los siguientes\n\r");

   if(nombre_apellido[0] != '\0')
   {
     cputs("Nombre y apellido:"); tab(); cprintf("%s\n\r", nombre_apellido);
   }
   else
   {
     cputs("Nombre y apellido:"); tab(); cprintf("%s\n\r", sin_dato);
   }

   if(edad > 0)
   {
     cputs("Edad             :"); tab(); cprintf("%d\n\r", edad);
   }
   else
   {
     cputs("Edad             :"); tab(); cprintf("%s\n\r", sin_dato);
   }

   getch();
}
