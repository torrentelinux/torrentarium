// LadrilloModular.h
// Octulio Biletán - Agosto de 2020
// Declarar la clase LadrilloConCalce
// Esta clase reúne en un único lugar la biblioteca de funciones y clases de C/C++.

#ifndef _LADRILLO_H
#define _LADRILLO_H

#include "bbteca.c.cpp.h"

class LadrilloConCalce
{
   public:
        _cstdio   C;
        _conio    consola;
        _cstring  cstring;
        _cstdlib  cstdlib;
        _cctype   cctype;
        _cmath    cmath;
        _ctime    ctime;
        _mem      mem;
        _cprocess cprocess;
        _cdir     cdir;
        _clocale  clocale;
        _iostream iostream;

        LadrilloConCalce();
        ~LadrilloConCalce();
};

#endif

