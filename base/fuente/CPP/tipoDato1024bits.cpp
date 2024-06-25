// tipoDato1024bits.cpp
// octulio biletán * Junio de 2024
// Crear un espacio de 1024 bits para el almacenamiento de datos.
// Para uso en gral.: cálculos matemáticos, físicos, químicos, procesamiento de textos, etc.
// Software Libre.

#define STRICT
#define __USELOCALES__

#include <windows.h>
#include <cstdio>
#include <climits>
#include <string>
#include <locale>
#include <iomanip>

#include "tipoDato1024bits.h"

espacioMem128Bytes tiempo_compilacion(void)
{
	espacioMem128Bytes tiempo;
	char datos[128] = { 0 };

   sprintf(datos, "%s %s.", __TIME__, __DATE__);
   memcpy(tiempo.c, datos, strlen(datos));

   return tiempo;
}

// Espera la pulsación de la tecla 'Intro'
int teclaIntro(void)
{
   cout << "Presionar tecla 'Intro' para terminar..." << flush;
   return (cin.get()/10)-1;  // devuelve 0
}

int main(int argc, char *argv[])
{
	espacioMem nro128;  // número de 128 bytes

   SetConsoleCP(1252);
   SetConsoleOutputCP(1252);

   setlocale(LC_ALL, "Spanish_Argentina.1252");
   cout.imbue(locale(""));

   cout << "Trabajo de investigación sobre el almacenamiento de datos en un espacio de 1024 bits (128 bytes)." << endl;
   cout << "Tiempo de compilación de la aplicación: " << tiempo_compilacion().c << endl << endl;

   // Dato a guardar como nº de 128 bytes
   char tmp[144] = "Para crear un programa y que la computadora lo interprete y ejecute,"
		   " las instrucciones deben escribirse en un lenguaje de programación";

   nro128 = tmp;
   nro128[nro128.nbytes()-2] = '.';
   nro128[nro128.nbytes()-1] = 0x00;

   cout << "Tamaño de nro128: " << nro128.nbits() << " bits; "
	<< nro128.nbytes() << " bytes." << endl;

   cout << "Contenido de nro128 como bytes: " << endl;
   cout << nro128 << endl << endl;

   cout << "Contenido de nro128 como número hexadecimal:" << endl << "0x";
   for(unsigned int i = 0; i < nro128.nelems(); i++)
     cout << hex << nro128.numero(i);

   cout << dec << endl;
   return teclaIntro();
}
