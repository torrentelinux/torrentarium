// tipoDato1024bits.cpp
// octulio biletán * Junio de 2024
// Crear un espacio de 1024 bits para almacenamiento de datos.
// Para uso en gral.
//
// Calculadora online para hacer cálculos matemático-científico
// https://www.wolframalpha.com
//

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <iostream>
#include <climits>
#include <mem.h>

using namespace std;

struct unsigned_int128
{
    unsigned __int64 pA;  // parte Alta
    unsigned __int64 pB;  // parte Baja
};

struct unsigned_int256
{
   unsigned_int128 pA;
   unsigned_int128 pB;
};

struct unsigned_int512
{
    unsigned_int256 pA;  // parte Alta
    unsigned_int256 pB;  // parte Baja
};

// valor min=0
// valor max=(2^1024)-1  ··> son 256 'F'
// valor max=0xffffffffffffffff'ffffffffffffffff'ffffffffffffffff'ffffffffffffffff'ffffffffffffffff'ffffffffffffffff'ffffffffffffffff
//             ffffffffffffffff'ffffffffffffffff'ffffffffffffffff'ffffffffffffffff'ffffffffffffffff'ffffffffffffffff'ffffffffffffffff
//             ffffffffffffffff'ffffffffffffffff
// son 309 dígitos decimales
// valor max=179769313486231590772930519078902473361797697894230657273430081157732675805500963132708477322407536021120113879871393357
//           658789768814416622492847430639474124377767893424865485276302219601246094119453082952085005768838150682342462881473913110
//           540827237163350510684586298239947245938479716304835356329624224137215

struct unsigned_int1024
{
   unsigned_int512 pA;  // parte Alta
   unsigned_int512 pB;  // parte Baja
};

// El espacio de almacenamiento de 1024 bits.
union unsigned_extra_long_int
{
   struct unsigned_int1024 ui;
   unsigned __int64 n[16];
   unsigned char c[128];
};

size_t nbits(size_t type_name)
{
   return (type_name * 8);
}

 int _tmain(int argc, _TCHAR* argv[])
{
	unsigned_int128  dato  = { 0 };
	unsigned_int256  dato2 = { 0 };
	unsigned_int512  dato3 = { 0 };
	unsigned_int1024 dato4 = { 0 };
	unsigned_extra_long_int nro16 = { 0 };  // número de 16 bytes

   cout << "Trabajo de investigaci¢n sobre el almacenamiento de datos en un espacio de 1024 bits (128 bytes)." << endl;
   cout << __TIME__ << ", jueves 20 de junio de 2024." << endl << endl;

   dato.pB = 0xeffffffffffffffd;
   dato.pA = ULLONG_MAX;

   /*
   cout << "Tama¤o de dato: " << nbits(sizeof(dato)) << " bits." << endl;
   cout << "Contenido de dato: 0x" << hex << dato.pA << dato.pB << endl;
   cout << "                   " << dec << dato.pA << dato.pB << endl;

   cout << "---" << endl;
   */

   // 256 bits
   dato2.pB.pB = dato.pB;
   dato2.pB.pA = dato.pA;
   dato2.pA.pB = dato.pB;
   dato2.pA.pA = dato.pA;

   /*
   cout << "Tama¤o de dato2: " << nbits(sizeof(dato2)) << " bits." << endl;
   cout << "Contenido de dato2: 0x" << hex << dato2.pA.pA << dato2.pA.pB
					   << dato2.pB.pA << dato2.pB.pB << endl;
   cout << "                    " << dec << dato2.pA.pA << dato2.pA.pB
					   << dato2.pB.pA << dato2.pB.pB << endl;

   cout << "---" << endl;
   */

   // 1024 bits
   dato4.pA.pA.pA.pB = dato.pB;
   dato4.pA.pA.pA.pA = dato.pA;
   dato4.pA.pA.pB.pB = dato.pB;
   dato4.pA.pA.pB.pA = dato.pA;
   dato4.pA.pB.pA.pB = dato.pB;
   dato4.pA.pB.pA.pA = dato.pA;
   dato4.pA.pB.pB.pB = dato.pB;
   dato4.pA.pB.pB.pA = dato.pA;

   dato4.pB.pA.pA.pB = dato.pB;
   dato4.pB.pA.pA.pA = dato.pA;
   dato4.pB.pA.pB.pB = dato.pB;
   dato4.pB.pA.pB.pA = dato.pA;
   dato4.pB.pB.pA.pB = dato.pB;
   dato4.pB.pB.pA.pA = dato.pA;
   dato4.pB.pB.pB.pB = dato.pB;
   dato4.pB.pB.pB.pA = dato.pA;

   /*
   cout << "Tama¤o de dato4: " << nbits(sizeof(dato4)) << " bits." << endl;
   cout << "Contenido de dato4: 0x" << hex << dato4.pA.pA.pA.pA << dato4.pA.pA.pA.pB
					   << dato4.pA.pA.pB.pA << dato4.pA.pA.pB.pB
					   << dato4.pA.pB.pA.pA << dato4.pA.pB.pA.pB
					   << dato4.pA.pB.pB.pA << dato4.pA.pB.pB.pB
					   << dato4.pB.pA.pA.pB << dato4.pB.pA.pA.pA
					   << dato4.pB.pA.pB.pB << dato4.pB.pA.pB.pA
					   << dato4.pB.pB.pA.pB << dato4.pB.pB.pA.pA
					   << dato4.pB.pB.pB.pB << dato4.pB.pB.pB.pA
					   << endl;
   cout << "                    " << dec << dato4.pA.pA.pA.pA << dato4.pA.pA.pA.pB
					   << dato4.pA.pA.pB.pA << dato4.pA.pA.pB.pB
					   << dato4.pA.pB.pA.pA << dato4.pA.pB.pA.pB
					   << dato4.pA.pB.pB.pA << dato4.pA.pB.pB.pB
					   << dato4.pB.pA.pA.pB << dato4.pB.pA.pA.pA
					   << dato4.pB.pA.pB.pB << dato4.pB.pA.pB.pA
					   << dato4.pB.pB.pA.pB << dato4.pB.pB.pA.pA
					   << dato4.pB.pB.pB.pB << dato4.pB.pB.pB.pA
					   << endl;

   cout << "---" << endl;
   */

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

   /*
   nro16.c[120] = 0xfb;  // parte baja
   nro16.c[127] = 0xff;  // parte alta
   */

   cout << "Contenido de nro16 como n£mero hexadecimal:" << endl << "0x";
   for(int i = 0; i < 16; i++)
     cout << hex << nro16.n[i];

   cout << dec << endl;

   // Presionar tecla 'Intro' para terminar...
   cin.get();
   return 0;
}

