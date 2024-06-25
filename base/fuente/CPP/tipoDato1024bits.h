// tipoDato1024bits.h
// octulio biletán * Junio de 2024
// Crear un espacio de 1024 bits para el almacenamiento de datos.
// Arquitectura de CPU Intel 64 bits, multinúcleo.
// Para uso en gral.: cálculos matemáticos, físicos, químicos, procesamiento de textos, etc.
// Software Libre.
//
// Calculadora online para hacer cálculos matemático-científico
// https://www.wolframalpha.com
//
// Observaciones: el tipo de datos '__int128' no se encuentra documentado en la página siguiente
// https://docwiki.embarcadero.com/RADStudio/Tokyo/en/Int8%2C_int16%2C_int32%2C_int64%2C_Unsigned_int64%2C_Extended_Integer_Types
// https://docwiki.embarcadero.com/RADStudio/Athens/en/Int8%2C_int16%2C_int32%2C_int64%2C_Unsigned_int64%2C_Extended_Integer_Types
// Pero sí está documentado en las siguientes páginas:
// https://docwiki.embarcadero.com/RADStudio/Athens/en/Delphi_Intrinsic_Routines
// https://docwiki.embarcadero.com/Libraries/Athens/en/System.MulDivInt64
// Sufijos aceptados para las constantes: ui128, i128
//

#ifndef __1024bits__
#define __1024bits__

#include <iostream>
#include <_stddef.h>
#include <mem.h>

using namespace std;

typedef unsigned __int64  uint64_t;
typedef unsigned __int128 uint128_t;
typedef unsigned char     uchar_t;

// Es aceptado por el compilador Embarcadero RAD Studio 10.2
struct unsigned_int128
{
    uint64_t pB; // parte Baja
    uint64_t pA; // parte Alta
};

// Espacio de memoria para la conversión de 128 bits a 64 bits
union unsigned_int64_128
{
   uint128_t       b;
   unsigned_int128 a;
};

// Es aceptado por el compilador Embarcadero RAD Studio 10.2, versión 25.0.26309.314
// y 11.3, versión 28.0.47991.2819. Edición 64 bits.
struct unsigned_int256
{
   uint128_t pB;  // parte Baja
   uint128_t pA;  // parte Alta
};

struct unsigned_int512
{
    unsigned_int256 pB;  // parte Baja
    unsigned_int256 pA;  // parte Alta
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
   unsigned_int512 pB;  // parte Baja
   unsigned_int512 pA;  // parte Alta
};

// Implementación del espacio de almacenamiento de 1024 bits.
union unsigned_extra_long_int
{
   unsigned_int1024 ui;
   uint128_t n[8];     //  8 posiciones para cada elemento
   uchar_t   c[128];  // 128 posiciones para cada elemento
};

// Definición del tipo 'espacioMem128Bytes'.
// Espacio de almacenamiento en memoria.
// Su tamaño es de 128 bytes: número entero extra largo sin signo.
typedef unsigned_extra_long_int espacioMem128Bytes;
typedef unsigned_extra_long_int ueli_t;
ostream& operator <<(ostream& pantalla, uint128_t origen);

class espacioMem
{
   private:
	bool activo = false;
	ueli_t dato = { 0 };

   public:
	espacioMem()
	{
	   activo = true;
	   //for(unsigned int i = 0; i < 8; i++)
	     //dato.n[i] = 0;
	}

	~espacioMem()
	{
	    activo = false;
	}

	espacioMem(uint128_t origen)
	{
	    activo = true;
	    dato.n[0] = origen;
	}

	espacioMem(int origen)
	{
	    activo = true;
	    dato.n[0] = origen;
	}

	espacioMem& operator =(char *origen)
	{
	   memcpy(dato.c, origen, (sizeof(uint128_t)*8));
	   return *this;
	}

	espacioMem& operator =(uint128_t origen)
	{
	    dato.n[0] = origen;
	    return *this;
	}

	uchar_t& operator[](unsigned int i)
	{
	   return dato.c[i];
	}

	friend ostream& operator <<(ostream& pantalla, espacioMem& origen);

	uint128_t numero(unsigned int indice)
	{
	   if(indice < 8)
	     return dato.n[indice];  // devuelve el valor solicitado

	   return dato.n[ 7 ];  // devuelve el último valor
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
	   return (nbytes()/sizeof(uint128_t));
	}
};

ostream& operator <<(ostream& pantalla, espacioMem& origen)
{
   pantalla << origen.dato.c;

   return pantalla;
}

ostream& operator <<(ostream& pantalla, uint128_t origen)
{
	unsigned_int64_128 temp = { 0 };

   temp.b = origen;
   pantalla << temp.a.pB << temp.a.pA;

   return pantalla;
}

#endif  //__1024bits__

