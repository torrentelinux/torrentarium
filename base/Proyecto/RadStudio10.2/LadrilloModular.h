// LadrilloModular.h
// Octulio Biletán - Agosto de 2020
// Declarar la clase LadrilloConCalce
// Esta clase reúne en un único lugar la biblioteca de funciones y clases de C/C++.

#ifndef _LADRILLO_H
#define _LADRILLO_H

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
        _cmath    cmath;
        _cprocess cprocess;
        _iostream iostream;

        LadrilloConCalce();
        ~LadrilloConCalce();
};

#endif

