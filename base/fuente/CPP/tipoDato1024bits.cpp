// tipoDato1024bits.cpp
// octulio biletán * Junio de 2024
// Crear un espacio de 1024 bits para el almacenamiento de datos.
// Para uso en gral.: cálculos matemáticos, físicos, químicos, procesamiento de textos, etc.
// Software Libre.

#include <iostream>
#include <cstdio>
#include <climits>
#include <mem.h>

#include "tipoDato1024bits.h"

using namespace std;

espacioMem tiempo_compilacion(void)
{
	espacioMem tiempo;
	char datos[128] = { 0 };

   sprintf(datos, "%s %s", __TIME__, __DATE__);
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
	unsigned_extra_long_int nro16 = { 0 };  // número de 16 bytes

   cout << "Trabajo de investigaci¢n sobre el almacenamiento de datos en un espacio de 1024 bits (128 bytes)." << endl;
   cout << "Tiempo de compilaci¢n de la aplicaci¢n: " << tiempo_compilacion().c << endl << endl;

   for(int i = 0; i < 16; i++)
     nro16.n[i] = ULLONG_MAX;

   char tmp[144] = "Para crear un programa y que la computadora lo interprete y ejecute,"
		   " las instrucciones deben escribirse en un lenguaje de programación";

   memcpy(nro16.c, tmp, 128);
   nro16.c[126] = '.';
   nro16.c[127] = 0x00;

   cout << "Tama¤o de nro16: " << nbits(sizeof(nro16)) << " bits." << endl;
   cout << "Contenido de nro16 como bytes: " << endl;
   cout << nro16.c << endl << endl;

   cout << "Contenido de nro16 como n£mero hexadecimal:" << endl << "0x";
   for(int i = 0; i < 16; i++)
     cout << hex << nro16.n[i];

   cout << dec << endl;
   return teclaIntro();
}

