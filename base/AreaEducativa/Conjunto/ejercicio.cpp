/*
 * Programa que ilustra el uso de la clase 'Conjunto' y 'xConjunto'.
 * Licencia: Software Libre.
 */

/*
 * File:   ejercicio.cpp
 * Author: Octulio Biletán
 * Created on 16 de mayo de 2026, 13:23
 */

#include <iostream>
#include <typeinfo>
#include <conio.h>

#include "conjunto.h"

char resolver_ejercicio_01(Conjunto &datos);
char resolver_ejercicio_02(Conjunto datos);
int resolver_ejercicio_03(void);

/*
 * Función de entrada a programa principal.
 */
int main(int argc, char** argv)
{
	Conjunto A = { 11, 3, 1 };

    system("chcp 1252 > nul");

    cout << resolver_ejercicio_01(A);
    cout << resolver_ejercicio_02(A);
    int estado = resolver_ejercicio_03();

    system("chcp 850 > nul");

    cout.put('>'); getch();
    return estado;
}

char resolver_ejercicio_01(Conjunto &datos)
{
    datos.otorgaleNombre("A");

    cout << "Ejercicio 1--" << endl << endl;

    cout << "Propiedades del conjunto " << datos.preguntaleNombre() << ":" << endl;
    cout << "\tTipo de dato: " << (char *)&typeid(datos).name()[1] << "." << endl;
    cout << "\tTamaño: " << (sizeof(datos)) << " bytes." << endl;
    cout << "\tTamaño de cada elemento numérico: " << sizeof(datos.a1) << " bytes." << endl;
    cout << "\tTipo de dato del elemento numérico: " << typeid(datos.a1).name()[1] << endl;
    cout << "\tCantidad de elementos que posee: " << datos.elementos() << endl;

    cout << "Elementos del conjunto " << datos.preguntaleNombre() << ":" << endl;
    cout << "\tDato 1: " << datos.a1 << endl;
    cout << "\tDato 2: " << datos.a2 << endl;
    cout << "\tDato 3: " << datos.a3 << endl;

    return '\n';
}
