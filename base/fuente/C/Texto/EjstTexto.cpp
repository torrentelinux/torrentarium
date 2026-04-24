// _______________________________________________________________________________________________•
// Programa      : EjstTextos.cpp
// Autor         : Edmund Muslok - Marzo~Abril de 2026.
// Descripción   : Gestión de líneas de caracteres mediante las funcs:
//                 crearTexto(), crearTextoF(), eliminarTexto(), eliminarTextoF(), copiarTexto()
//                 y la función auxiliar limpiar() y la estructura de datos _stTexto{}.
// Observaciones : En _stTexto{} se registra la capacidad máxima de almacenamiento
//                 y el tamaño vigente de la línea de textos entre otras cosas.
//                 Es compatible con el compilador de Embarcadero C++ Builder y
//                 con GNU G++/CygWin.
// _______________________________________________________________________________________________•

#include <iostream>
#include <tchar.h>

#include "Textos.h"

/* La función de pruebas 1 y 2 */
void pruebaTextos1(void);
void pruebaTextos2(void);

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
   pruebaTextos1();
   puts("Presione cualquier tecla para terminar...");
   getch();

   pruebaTextos2();
   puts("Presione cualquier tecla para terminar...");
   getch();

   return 0;
}

/* Prueba de uso de 'Texto' y sus funcs. */
void pruebaTextos1(void)
{
        Texto t1 = { 0 };
        Texto t2 = { 0 };
        char linea[80] = { 0 };

   puts("Prueba n§ 1 de 'Texto'\n");

   sprintf(linea, "== Hoy es un d¡a nublado ==\n");
   crearTexto(&t1, 80);  /* Se crea 't1' dinámicamente en memoria */

   /* Se crea 't2' estáticamente en memoria con una longitud fija de datos del tipo char[] */
   crearTextoF(&t2, linea, sizeof(linea));

   copiarTexto(&t1, &t2);

   printf("Contenido de 'linea[]': %s", linea);
   printf("Contenido de t1: %s", t1.linea);
   printf("Contenido de t2: %s\n", t2.linea);

   eliminarTexto(&t1);		/* Se elimina 't1' dinámicamente de la memoria */
   eliminarTextoF(&t2);         /* Se elimina el contenido de 't2' de la memoria */
   limpiar(linea, 80, '\0');    /* Se elimina el contenido de 'linea' de la memoria */
   printf("Contenido de 'linea[]' despu‚s de la eliminaci¢n de 't1' y 't2':\n%s\n", (linea[0] == '\0' ? "<nul>" : linea));
}

void pruebaTextos2(void)
{
        int estado = 0;
        Texto tabla_sql = { 0 };
        Texto t1 = { 0 };
        Texto sql = { 0 };
        FILE *salida = NULL;

   cout << "<comienzo de pruebaTextos2>" << endl;

   crearTexto(&tabla_sql, 80);
   crearTexto(&t1, 160);
   crearTexto(&sql, 160);

   copiarATexto(&tabla_sql, "tabla.sql");
   copiarATexto(&t1, "create table tbl_personas(id integer not null check (id > 0),"
   		     "nombre varchar(50) not null, primary key (id))\n");

   salida = abrirTexto(tabla_sql.linea);
   if(salida == NULL)
   {
     cout << "Error: no se pudo abrir el archivo '" << tabla_sql.linea << "'." << endl;
     return;
   }

   guardarTexto(salida, &t1);
   rewind(salida);

   estado = leerTexto(salida, &sql);
   cout << "[Lectura] estado=" << estado << endl;

   estado = cerrarTexto(salida);
   cout << "[Cierre] estado=" << estado << endl;

   cout << "contenido le¡do de '" << tabla_sql.linea << "'." << endl;
   cout << sql.linea << endl;

   cout << "<fin de pruebaTextos2>" << endl;
}
