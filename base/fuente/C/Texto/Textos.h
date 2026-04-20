/*
    Encabezamiento: Textos.h
    Autor         : Edmund Muslok - Marzo~Abril de 2026.
    Descripción   : Gestión de líneas de caracteres mediante las funcs:
                    crearTexto(), eliminarTexto(), inicializarTexto(), copiarTexto()
                    y la estructura de datos _stTexto{}.
    Observaciones : En _stTexto{} se registra la capacidad máxima de almacenamiento
                    y el tamaño vigente de la línea de textos.
                    Es compatible con el compilador de Embarcadero C++ Builder y
                    con G++/CygWin.
*/

#if !defined(__TEXTOS_H)
#define __TEXTOS_H

#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

#if defined(__BORLANDC__)
#  include <mem.h>
#  include <conio.h>
#endif // __BORLANDC__

struct _stTexto
{
    size_t tam;		/* tamaño vigente de la línea de caracteres */
    size_t cap;		/* capacidad máxima de almacenamiento en la línea de caracteres */
    char *linea;	/* línea de caracteres */
};

/* Tipo de dato 'Texto'
   Por ej.: Texto txt;
*/
typedef struct _stTexto Texto;

#ifdef __cplusplus
extern "C" {
#endif

/* La función de prueba */
void pruebaTextos1(void);

/* Conjunto de funciones para el tratamiento simple de 'Texto' (una secuencia de caracteres) */
void inicializarTexto(Texto *t, char *txtlinea, size_t ncaracts);
void crearTexto(Texto *nuevo, size_t cap_nuevo);
char *eliminarTexto(Texto *dst);
Texto *copiarTexto(Texto *dst, Texto *org);
/*___________________________________________________________*/

#if defined(__CYGWIN__)
    int getch(void);

#include <termios.h>
#include <unistd.h>

/*
Func. para leer un único caracter desde teclado y sin emitir eco en la pantalla.
Devuelve -1 en caso de error.
Ejemplo:
    int c = getch();
    if(c != -1)
    {
        printf("\nHa presionado: '%c' (ASCII %d)\n", c, c);
    }
*/
int getch(void)
{
    int ch;
    struct termios oldt, newt;

    // Obtiene el estado actual de la terminal consola
    if(tcgetattr(STDIN_FILENO, &oldt) != 0) 
    {
        perror("::Error:: tcgetattr");
        return -1;
    }

    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);	//   Deshabilita el modo canónico y el modo eco
    if(tcsetattr(STDIN_FILENO, TCSANOW, &newt) != 0) 
    {
        perror("::Error:: tcsetattr");
        return -1;
    }

    // Lee desde teclado un único caracter
    ch = getchar();

    // Restablece los valores anteriores
    if(tcsetattr(STDIN_FILENO, TCSANOW, &oldt) != 0) 
    {
        perror("::Error:: tcsetattr");
        return -1;
    }

    return ch; // Devuelve el caracter ingresado desde teclado
}
#endif  // fin __CYGWIN__

void crearTexto(Texto *nuevo, size_t cap_nuevo)
{
   errno = 0;

   nuevo->linea = (char *)calloc(cap_nuevo, sizeof(char));
   nuevo->cap = cap_nuevo;
   nuevo->tam = 0;
}

char *eliminarTexto(Texto *dst)
{
   errno = 0;

   if(dst == NULL || dst->linea == NULL)
    {
      errno = EINVAL;  /* argumento inválido */
      return NULL;
    }

#if defined(__CYGWIN__)
   memset(dst->linea, '\0', dst->tam);
#else
   setmem(dst->linea, dst->tam, '\0');
#endif // __CYGWIN__

   dst->cap = 0;
   dst->tam = 0;

   free(dst->linea);
   dst->linea = NULL;
   return NULL;
}

Texto *copiarTexto(Texto *dst, Texto *org)
{
	char *tmp = NULL;

    errno = 0;

    tmp = strncpy(dst->linea, org->linea, dst->cap);
    if(tmp == NULL)
    {
      errno = EINVAL;  /* argumento inválido */
      return NULL;
    }

    dst->tam = strlen(dst->linea);

    return dst;
}

void inicializarTexto(Texto *t, char *txtlinea, size_t ncaracts)
{
   t->linea = txtlinea;
   t->cap = ncaracts;
   t->tam = 0;
}

/* Prueba las capacidades de uso de 'Texto' y sus funcs. */
void pruebaTextos1(void)
{
        Texto t1 = { 0 };
        Texto t2 = { 0 };
        char linea[80] = { 0 };

   puts("Prueba nº 1 de 'Texto'\n");

   sprintf(linea, "Hoy es un dia nublado.\n");
   crearTexto(&t1, 80);

   /* Inicializa 't2' */
   inicializarTexto(&t2, linea, sizeof(linea));

   copiarTexto(&t1, &t2);

   printf("Contenido de t1: %s", t1.linea);
   printf("Contenido de t2: %s\n", t2.linea);

   eliminarTexto(&t1);

   puts("Presione cualquier tecla para terminar...");
   getch();
}

#ifdef __cplusplus
}
#endif

#endif  /* __TEXTOS_H */
