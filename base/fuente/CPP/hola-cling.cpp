#!/usr/bin/cling

// Cling: intérprete de C++
// En Linux: ejecutar desde la línea de comandos los siguientes pasos
// paso 1: chmod +x hola-cling.cpp
// paso 2: ./hola-cling.cpp

#include <iostream>
#include <stdlib.h>

using namespace std;

int main(void)
{
   system("clear");
   cout << "¡Hola amigo/amiga!" << endl << "¿ Cómo te llamas ? " << flush;
   
   char nombre[80];
   cin.getline(nombre, 80);
   
   cout << "Hola " << nombre << "!" << endl;
   return 0; 
}
