/*
 * ejercicio nº 3 sobre conjuntos de datos numéricos.
 * Licencia: Software Libre.

 */
#include <iostream>

#include "conjunto.h"

int resolver_ejercicio_03(void)
{
        xConjunto x = { };
        xConjunto y = { };
        int vectorZ[] = { 10, 231, -768, 300, 40, 25, 1001, -4 };
        xConjunto muestra = { vectorZ, 5 };

    cout << "Ejercicio 3--" << endl << endl;

    x.otorgaleNombre("Números pares");
    y.otorgaleNombre("Números impares");

    muestra.otorgaleNombre("Muestra numérica");

    cout << muestra.capacidad() << " "
         << muestra.elementos() << " "
         << muestra.esVacio() << " "
         << muestra.preguntaleNombre()
         << endl;

    cout << muestra.listeElementos() << endl << endl;

    cout << "Introduce pares." << endl;
    x.introducePares(muestra);

    cout << "El conjunto de '" << x.preguntaleNombre() << "'" << " contiene: " << x.pares() << " números pares." << endl;

    cout << "Sus elementos son:" << endl;
    cout << x.listeElementos() << endl << endl;

    cout << "Introduce impares." << endl;
    y.introduceImpares(muestra);

    cout << "El conjunto de '" << y.preguntaleNombre() << "'" << " contiene: " << y.impares() << " números impares." << endl;

    cout << "Sus elementos son:" << endl;
    cout << y.listeElementos() << endl;

    return 0;
}
