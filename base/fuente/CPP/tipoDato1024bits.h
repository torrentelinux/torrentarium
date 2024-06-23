// tipoDato1024bits.h
// octulio bilet�n * Junio de 2024
// Crear un espacio de 1024 bits para el almacenamiento de datos.
// Para uso en gral.: c�lculos matem�ticos, f�sicos, qu�micos, procesamiento de textos, etc.
// Software Libre.
//
// Calculadora online para hacer c�lculos matem�tico-cient�fico
// https://www.wolframalpha.com
//

#ifndef __1024bits__
#define __1024bits__

#include <iostream>
#include <_stddef.h>
#include <mem.h>

using namespace std;

typedef unsigned __int64 uint64_t;
typedef unsigned char   uchar_t;

struct unsigned_int128
{
    uint64_t pB; // parte Baja
    uint64_t pA; // parte Alta
};

struct unsigned_int256
{
   unsigned_int128 pB;  // parte Baja
   unsigned_int128 pA;  // parte Alta
};

struct unsigned_int512
{
    unsigned_int256 pB;  // parte Baja
    unsigned_int256 pA;  // parte Alta
};

// valor min=0
// valor max=(2^1024)-1  ��> son 256 'F'
// valor max=0xffffffffffffffff'ffffffffffffffff'ffffffffffffffff'ffffffffffffffff'ffffffffffffffff'ffffffffffffffff'ffffffffffffffff
//             ffffffffffffffff'ffffffffffffffff'ffffffffffffffff'ffffffffffffffff'ffffffffffffffff'ffffffffffffffff'ffffffffffffffff
//             ffffffffffffffff'ffffffffffffffff
// son 309 d�gitos decimales
// valor max=179769313486231590772930519078902473361797697894230657273430081157732675805500963132708477322407536021120113879871393357
//           658789768814416622492847430639474124377767893424865485276302219601246094119453082952085005768838150682342462881473913110
//           540827237163350510684586298239947245938479716304835356329624224137215

struct unsigned_int1024
{
   unsigned_int512 pB;  // parte Baja
   unsigned_int512 pA;  // parte Alta
};

// Implementaci�n del espacio de almacenamiento de 1024 bits.
union unsigned_extra_long_int
{
   unsigned_int1024 ui;
   uint64_t n[sizeof(uint64_t)*2];     //  16 elementos
   uchar_t  c[1024/sizeof(uint64_t)];  // 128 elementos
};

// Definici�n del tipo 'espacioMem128Bytes'.
// Espacio de almacenamiento en memoria.
// Su tama�o es de 128 bytes.
typedef unsigned_extra_long_int espacioMem128Bytes;
typedef unsigned_extra_long_int ueli_t;

class espacioMem
{
   private:
	ueli_t dato;

   public:
	espacioMem()
	{
	   for(unsigned int i = 0; i < sizeof(uint64_t)*2; i++)
	     dato.n[i] = 0;
	}

	espacioMem& operator =(char *origen)
	{
	   memcpy(dato.c, origen, (1024/sizeof(uint64_t)));
	   return *this;
	}

	uchar_t& operator[](unsigned int i)
	{
	   return dato.c[i];
	}

	friend ostream& operator <<(ostream& pantalla, espacioMem& origen);

	uint64_t numero(unsigned int indice)
	{
	   if(indice < sizeof(uint64_t)*2)
	     return dato.n[indice];  // devuelve el valor solicitado

	   return dato.n[ (sizeof(uint64_t)*2) - 1 ];  // devuelve el �ltimo valor
	}

	size_t nbits()
	{
	   return (sizeof(dato) * 8);
	}

	size_t nbytes()
	{
	   return sizeof(dato);
	}

	unsigned int nelems()
	{
	   return (nbytes()/sizeof(uint64_t));
	}
};

ostream& operator <<(ostream& pantalla, espacioMem& origen)
{
   pantalla << origen.dato.c;

   return pantalla;
}

#endif  //__1024bits__

