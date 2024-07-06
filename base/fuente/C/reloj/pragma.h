/* PRAGMA.H  <> Eugenio Mart¡nez --- Tucum n --- Argentina */

/* Aqu¡ se implementa la activaci¢n/desactivaci¢n de las advertencias
   producidas por el compilador BORLAND C/C++
*/

#ifndef __linux__

#if defined(__BORLANDC__)

#if defined(__TURBO_ASSEMBLER__)

/* Avisa al compilador que ‚ste m¢dulo contiene l¡neas 'asm' */
#pragma inline

#endif

/* Activa la advertencia: Call to function 'xxx' with no prototype in function 'xxx' */
#pragma warn +prog

/* Desactiva la advertencia: Possibly incorrect assignment in function 'xxx' */
#pragma warn -pia

/* desactiva mensaje: 'ident' is assigned a value that is never used */
#pragma warn -aus

/* desactiva mensaje: Parameter 'parameter' is never used */
// opcional: #pragma option -w-par
#pragma warn -par

#if defined(__AWORD__)
#pragma option -a	/* Alineaci¢n de los datos en palabras */
#endif

#if defined(__ABYTE__)
#pragma option -a-	/* Alineaci¢n de los datos en bytes */
#endif

#if defined(__FRETURN__)
#pragma warn -rvl  /* Desactiva la advertencia: function should return a value */
#endif

#if defined(__FOBSOLETE__)
#pragma warn -obs  /* Desactiva la advertencia: 'function name' is obsolete */
#endif

#endif  /* __BORLANDC__ */

#endif  /* __linux__ */
