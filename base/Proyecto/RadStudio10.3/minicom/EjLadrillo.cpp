// EjLadrillo.cpp
// Octulio Biletán - Agosto de 2020
// Uso de puntero a LadrilloConCalce.

/*
	Ejemplo de 'LadrilloConCalce' en un programa C++
*/

//---------------------------------------------------------------------------
#include <typeinfo.h>
#include "LadrilloModular.h"
//---------------------------------------------------------------------------

int main(void)
{
	LadrilloConCalce *lib = new LadrilloConCalce();

   *(lib->iostream.cout) << "Detalles de: " << typeid(LadrilloConCalce).name() << endl;
   *(lib->iostream.cout) << "Objeto lib: " << typeid(lib).name() << endl;
   *(lib->iostream.cout) << "Tama¤o lib (bytes): " << sizeof(lib) << endl;
   *(lib->iostream.cout) << "Tama¤o *lib (bytes): " << sizeof(*lib) << endl;

   lib->C.putchar('\n');
   lib->C.printf("%s\n", "Hola...");
   lib->consola.getch();

   delete lib;
   lib = NULL;

   return 0;
}

