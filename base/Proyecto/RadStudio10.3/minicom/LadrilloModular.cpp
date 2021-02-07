// LadrilloModular.cpp
// Octulio Biletán - Agosto de 2020
// El "ladrillo" como objeto modular en la estructura de un programa C++.
// Compatible con Embarcadero RAD Studio 10.2 y versiones posteriores.

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

#include <mem.h>
#include <conio.h>
#include <process.h>

#include "LadrilloModular.h"

// Inicializa todos los punteros
LadrilloConCalce::LadrilloConCalce()
{
   // Grupo de funciones de cstdio
   C.strerror = strerror;
   C.perror = perror;
   C.sprintf = sprintf;
   C.sscanf = sscanf;

   // Grupo salida estándar del sistema
   C.printf = printf;
   C.puts = puts;
   C.putchar = putchar;

   // Grupo entrada estándar del sistema
   C.scanf = scanf;
   C.gets = gets;

   // Grupo de e/s para ficheros
   C.fclose = fclose;
   C.fopen = fopen;
   C.getc = getc;
   C.fgetc = fgetc;
   C.fgets = fgets;
   C.ungetc = ungetc;
   C.putc = putc;
   C.fcloseall = fcloseall;
   C.feof = feof;
   C.ferror = ferror;
   C.fflush = fflush;
   C.flushall = flushall;
   C.fileno = fileno;
   C.fprintf = fprintf;
   C.fputc = fputc;
   C.fputs = fputs;
   C.fread = fread;
   C.fscanf = fscanf;
   C.fseek = fseek;
   C.fsetpos = fsetpos;
   C.ftell = ftell;
   C.fwrite =fwrite;
   C._fseeki64 = _fseeki64;
   C._ftelli64 = _ftelli64;
   C.rewind = rewind;
   C.clearerr = clearerr;

   // Grupo de funciones de mem.h
   mem.memset = memset;

   // Grupo de funciones de cstring
   cstring.strcmp = strcmp;

   // Grupo de funciones de cstdlib
   cstdlib.exit = exit;

   // Grupo de funciones de process.h
   process.spawnv = spawnv;
   process.cwait = cwait;

   // Objeto C++ de la salida estándar con error del sistema
   iostream.cerr = &cerr;

   // Objetos C++ de la entrada/salida estándar del sistema
   iostream.cout = &cout;
   iostream.cin = &cin;

   // Grupo de funciones de conio.h
   consola.getch = getch;
}

// Elimina todos los punteros
LadrilloConCalce::~LadrilloConCalce()
{
   // Grupo de funciones de cstdio
   C.strerror = NULL;

   // Grupo salida estándar del sistema
   C.printf = NULL;
   C.puts = NULL;
   C.putchar = NULL;

   // Grupo entrada estándar del sistema
   C.scanf = NULL;

   // Grupo de funciones de mem.h
   mem.memset = NULL;

   // Grupo de funciones de cstring
   cstring.strcmp = NULL;

   // Grupo de funciones de cstdlib
   cstdlib.exit = NULL;

   // Grupo de funciones de process
   process.spawnv = NULL;
   process.cwait = NULL;

   // Objeto C++ de la salida estándar con error del sistema
   iostream.cerr = NULL;

   // Objeto C++ de la salida estándar del sistema
   iostream.cout = NULL;

   // Objeto C++ de la entrada estándar del sistema
   iostream.cin = NULL;

   // Grupo de funciones de conio.h
   consola.getch = NULL;
}

