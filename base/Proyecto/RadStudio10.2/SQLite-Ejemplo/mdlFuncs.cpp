//---------------------------------------------------------------------------
// Proyecto : SQLite_Ejemplo.cbproj
// Módulo   : mdlFuncs.cpp
// Autor    : Octulio Biletán * Marzo de 2024
// Propósito: Realizar una consulta a la base de datos 'ejemploSQLite.sdb'
//            Definición de variables constantes externas.
// Obs.     : El lenguaje de consulta utilizado es SQLite v3.
// Refs.    : https://www.sqlite.org/fileformat.html
//---------------------------------------------------------------------------

#include "mdlGestorDatos.h"
#include "mdlFuncs.h"

#include <io.h>
#include <fcntl.h>
#include <errno.h>

const int FBIEN = 0;
const int FTAMCERO = 2000;
const int FERRORCAB = 2001;

// Cabecera de 16 bytes de un fichero sqlite.
struct cabecera_sqlite3
{
	unsigned char secuencia[16];
};

cabecera_sqlite3 cab16bytes = { 0x53, 0x51, 0x4c, 0x69, 0x74, 0x65, 0x20, 0x66, 0x6f, 0x72, 0x6d, 0x61, 0x74, 0x20, 0x33, 0x00 };

// Verifica la integridad de una base de datos (archivo) en SQLite
const int TfrmGestorDatos::verificarSQL(String &fsql)
{
	int codigo_error = FBIEN;
	int id_fichero = 0;
	int leidos = 0;
	long tam_fichero = 0;
	cabecera_sqlite3 datos16bytes = { 0 };

   id_fichero = _wopen(fsql.c_str(), O_RDONLY|O_BINARY);
   if(id_fichero == -1)
     codigo_error = errno;  // No se pudo abrir el fichero
   else
   {
     tam_fichero = filelength(id_fichero);
     if(tam_fichero == -1)
       codigo_error = errno;  // No se pudo determinar el tamaño del fichero
     else
     {
       if(tam_fichero == 0)
	 codigo_error = FTAMCERO;  // Se rechaza por fichero sin datos
       else
       {
	 errno = 0;
	 leidos = read(id_fichero, &datos16bytes.secuencia, 16);
	 if(leidos < 1)
	 {
	   codigo_error = errno;  // No se pudo leer la cabecera del fichero
	 }
	 else
	 {
	   // Compara los datos leídos para verificar si es un archivo sqlite
	   for(unsigned short int i = 0; i < 16; i++)
	     if(cab16bytes.secuencia[i] != datos16bytes.secuencia[i])
	     {
	       codigo_error = FERRORCAB;  // La cabecera es incorrecta
	       break;
	     }
	 }
       }
     }
     close(id_fichero);
   }

   return codigo_error;
}
