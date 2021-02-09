// LadrilloModular.cpp
// Octulio Biletán - Agosto de 2020
// El "ladrillo" como objeto modular en la estructura de un programa C++.
// Compatible con Embarcadero RAD Studio 10.2 y versiones posteriores.

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
   C.getchar = getchar;

   // Grupo de e/s para ficheros
   C.fclose = fclose;
   C.fopen = fopen;
   C.getc = getc;
   C.fgetchar = _fgetchar;
   C.fgetc = fgetc;
   C.fgets = fgets;
   C.ungetc = ungetc;
   C.putc = putc;
   C.fputchar = _fputchar;
   C.fputc = fputc;
   C.fputs = fputs;
   C.fcloseall = fcloseall;
   C.feof = feof;
   C.ferror = ferror;
   C.fflush = fflush;
   C.flushall = flushall;
   C.fileno = fileno;
   C.fprintf = fprintf;
   C.fscanf = fscanf;
   C.fread = fread;
   C.fwrite =fwrite;
   C.fseek = fseek;
   C.fsetpos = fsetpos;
   C.ftell = ftell;
   C.fseeki64 = _fseeki64;
   C.ftelli64 = _ftelli64;
   C.rewind = rewind;
   C.clearerr = clearerr;

   // Grupo de funciones de mem.h
   mem.memset = memset;

   // Grupo de funciones de cstring
   cstring.strcmp = strcmp;

   // Grupo de funciones de cstdlib
   cstdlib.exit = exit;

   // Grupo de funciones de cmath
   cmath.pow = pow;

   // Grupo de funciones de cprocess
   cprocess.system = system;
   cprocess.spawnl = spawnl;
   cprocess.spawnle = spawnle;
   cprocess.spawnlp = spawnlp;
   cprocess.spawnlpe = spawnlpe;
   cprocess.spawnv = spawnv;
   cprocess.spawnve = spawnve;
   cprocess.spawnvp = spawnvp;
   cprocess.spawnvpe = spawnvpe;
   cprocess.cwait = cwait;
   cprocess.execl = execl;
   cprocess.execle = execle;
   cprocess.execlp = execlp;
   cprocess.execlpe = execlpe;
   cprocess.execv = execv;
   cprocess.execve = execve;
   cprocess.execvp = execvp;
   cprocess.execvpe = execvpe;

   // Objeto C++ de la salida estándar con error del sistema
   iostream.cerr = &cerr;

   // Objetos C++ de la entrada/salida estándar del sistema
   iostream.cout = &cout;
   iostream.cin = &cin;

   // Grupo de funciones de conio.h
   consola.getch = getch;
   consola.clrscr = clrscr;
}

// Elimina todos los punteros
LadrilloConCalce::~LadrilloConCalce()
{
   // Grupo de funciones de cstdio
   memset(&C,0,sizeof(C));

   // Grupo de funciones de mem.h
   memset(&mem, 0, sizeof(mem));

   // Grupo de funciones de cstring
   memset(&cstring, 0, sizeof(cstring));

   // Grupo de funciones de cstdlib
   memset(&cstdlib, 0, sizeof(cstdlib));

   // Grupo de funciones de cmath
   memset(&cmath, 0, sizeof(cmath));

   // Grupo de funciones de cprocess
   memset(&cprocess, 0, sizeof(cprocess));

   // Objeto C++ de la entrada/salida estándar del sistema
   memset(&iostream, 0, sizeof(iostream));

   // Grupo de funciones de conio.h
   memset(&consola, 0, sizeof(consola));
}

