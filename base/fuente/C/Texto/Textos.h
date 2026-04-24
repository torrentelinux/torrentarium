/*
    Encabezamiento: Textos.h
    Autor         : Edmund Muslok - Marzo~Abril de 2026.
    Descripción   : Gestión de líneas de caracteres mediante las funcs:
                    crearTexto(), crearTextoF(), eliminarTexto(), eliminarTextoF(), copiarTexto()
                    y la función auxiliar limpiar() y la estructura de datos _stTexto{}.
    Observaciones : En _stTexto{} se registra la capacidad máxima de almacenamiento
                    y el tamaño vigente de la línea de textos entre otras cosas.
                    Es compatible con el compilador de Embarcadero C++ Builder y
                    con GNU G++/CygWin.
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

#ifdef __cplusplus
extern "C" {
#endif

struct _stTexto
{
    size_t tam;			/* tamaño vigente de la línea de caracteres */
    size_t cap;			/* capacidad máxima de almacenamiento en la línea de caracteres */
    unsigned long int venc;	/* Tiempo de vencimiento/caducidad o "contador de accesos" de los datos guardados en 'linea' */
    unsigned short int tipo_venc;	/* 0=no definido, 1=contador de accesos, 2=tiempo de vencimiento, 3=dato no modificable */
    char *linea;		/* línea de caracteres, son los datos guardados */
};

/* Tipo de dato 'Texto'
   Por ej.: Texto txt;
*/
typedef struct _stTexto Texto;

/* Es similar a setmem() */
void limpiar(void *region, unsigned int longitud, char valor);

/* Conjunto de funciones para el tratamiento simple de 'Texto' (una secuencia de caracteres) */

/* Crear una línea de textos de longitud fija en memoria */
void crearTextoF(Texto *t, char txtlinea[], size_t ncaracts);

/* Crear una línea de textos de longitud fija y dinámicamente en memoria */
void crearTexto(Texto *nuevo, size_t cap_nuevo);

/* Eliminar de la memoria la línea de textos */
char *eliminarTexto(Texto *dst);

/* Eliminar de la memoria la línea de textos de longitud fija */
char *eliminarTextoF(Texto *dst);

/* Copiar una línea de textos 'org' en otra del mismo tipo 'dst' */
Texto *copiarTexto(Texto *dst, Texto *org);

/* Copiar una secuencia de caracteres 'org' en 'dst' del tipo 'Texto' */
Texto *copiarATexto(Texto *dst, const char *org);

/* Abre un archivo de textos para operaciones de E/S de datos */
FILE *abrirTexto(const char *fnom);

/* Cierra el archivo de textos dando por finalizada las operaciones de E/S de datos */
int cerrarTexto(FILE *f);

/* Guarda texto 'org' en un archivo de textos 'fdestino' */
int guardarTexto(FILE *fdestino, Texto *org);

/* Lee texto 'dst'  de un archivo de textos 'forig' */
int leerTexto(FILE *forig, Texto *dst);

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
    nuevo->tipo_venc = 0;
    nuevo->venc = 0;	/* Este valor puede representar una cuenta de accesos comenzando desde uno */
			/* o tiempo de vencimiento a los datos para su acceso comenzando desde uno,*/
			/* el tiempo puede ser años, meses, días, horas, minutos y segundos */
			/* Cuando es cero, significa no definido */
}

void crearTextoF(Texto *t, char txtlinea[], size_t ncaracts)
{
    t->linea = (char *)txtlinea;
    t->cap = ncaracts;
    t->tam = 0;
    t->tipo_venc = 0;
    t->venc = 0;	/* Este valor puede representar una cuenta de accesos comenzando desde uno */
			/* o tiempo de vencimiento a los datos para su acceso comenzando desde uno,*/
			/* el tiempo puede ser años, meses, días, horas, minutos y segundos */
			/* Cuando es cero, significa no definido */
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

char *eliminarTextoF(Texto *dst)
{
   errno = 0;

   if(dst->linea == NULL || dst->cap == 0)
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

Texto *copiarATexto(Texto *dst, const char *org)
{
	char *tmp = NULL;

   errno = 0;
   tmp = strncpy(dst->linea, org, dst->cap);
   if(tmp == NULL)
   {
      errno = EINVAL;  /* argumento inválido */
      return NULL;
   }

   dst->tam = strlen(dst->linea);

   return dst;
}

FILE *abrirTexto(const char *fnom)
{
        static FILE *fichero;

   errno = 0;
   fichero = fopen(fnom, "w+t");
   return fichero;
}

int cerrarTexto(FILE *f)
{
        int estado = 0;

   errno = 0;
   if(ferror(f) || feof(f))
     clearerr(f);

   estado = fclose(f);
   return estado;
}

int guardarTexto(FILE *fdestino, Texto *org)
{
        int estado = 0;

   if(fdestino == NULL || org == NULL)
   {
     errno = 2;
   }
   else
   {
     errno = 0;
     estado = fwrite(org->linea, org->tam, 1, fdestino);
     fflush(fdestino);
     return estado;
   }

   return errno;
}

int leerTexto(FILE *forig, Texto *dst)
{
        int estado = 0;

   errno = 0;
   if(feof(forig))
     clearerr(forig);

   estado = fread(dst->linea, dst->cap, 1, forig);
   dst->tam = strlen(dst->linea);

   return estado;
}

void limpiar(void *region, unsigned int longitud, char valor)
{
#if defined(__CYGWIN__)
   memset(region, valor, longitud);
#else
   setmem(region, longitud, valor);
#endif // fin __CYGWIN__
}

#ifdef __cplusplus
}
#endif

#endif  /* __TEXTOS_H */
