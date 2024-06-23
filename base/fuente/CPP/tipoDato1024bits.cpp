// tipoDato1024bits.cpp
// octulio biletán * Junio de 2024
// Crear un espacio de 1024 bits para el almacenamiento de datos.
// Para uso en gral.: cálculos matemáticos, físicos, químicos, procesamiento de textos, etc.
// Software Libre.

#include <cstdio>
#include <climits>

#include "tipoDato1024bits.h"

espacioMem128Bytes tiempo_compilacion(void)
{
	espacioMem128Bytes tiempo;
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
	espacioMem nro128;  // número de 128 bytes

   cout << "Trabajo de investigaci¢n sobre el almacenamiento de datos en un espacio de 1024 bits (128 bytes)." << endl;
   cout << "Tiempo de compilaci¢n de la aplicaci¢n: " << tiempo_compilacion().c << endl << endl;

   /*  EN FASE DE DESARROLLO...
   for(int i = 0; i < 16; i++)
       nro128.n[i] = ULLONG_MAX;
   */

   char tmp[144] = "Para crear un programa y que la computadora lo interprete y ejecute,"
		   " las instrucciones deben escribirse en un lenguaje de programación";

   nro128 = tmp;
   nro128[nro128.nbytes()-2] = '.';
   nro128[nro128.nbytes()-1] = 0x00;

   cout << "Tama¤o de nro128: " << nro128.nbits() << " bits; "
	<< nro128.nbytes() << " bytes." << endl;

   cout << "Contenido de nro128 como bytes: " << endl;
   cout << nro128 << endl << endl;

   cout << "Contenido de nro128 como n£mero hexadecimal:" << endl << "0x";
   for(unsigned int i = 0; i < nro128.nelems(); i++)
     cout << hex << nro128.numero(i);

   cout << dec << endl;
   return teclaIntro();
}

