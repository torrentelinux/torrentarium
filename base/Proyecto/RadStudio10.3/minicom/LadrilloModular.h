// LadrilloModular.h
// Octulio Bilet�n - Agosto de 2020
// Declarar la clase LadrilloConCalce
// Esta clase re�ne en un �nico lugar la biblioteca de funciones y clases de C/C++.

#include "bbteca.c.cpp.h"

using namespace std;

class LadrilloConCalce
{
   public:
        _cstdio   C;
        _conio    consola;
        _mem      mem;
        _cstring  cstring;
        _cstdlib  cstdlib;
        _process  process;
        _iostream iostream;

        LadrilloConCalce();
        ~LadrilloConCalce();
};


