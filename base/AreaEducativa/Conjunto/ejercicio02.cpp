/*
 * ejercicio nº 2 sobre conjuntos de datos numéricos.
 * Licencia: Software Libre.
 */

 #include <iostream>

#include "conjunto.h"

char resolver_ejercicio_02(Conjunto datos)
{
    cout << "Ejercicio 2--" << endl << endl;
    Conjunto B = { datos };

    B.a2 = -1;

    cout << "Nombre del conjunto: "                 << B.preguntaleNombre() << endl;
    cout << "¿El conjunto B contiene a 4? "         << B.contiene(4) << endl;
    cout << "¿El conjunto B es un conjunto vacío? " << B.esVacio() << endl;
    cout << "¿Cuántos elementos posee? "            << B.elementos() << endl;
    cout << "¿Cuáles son sus elementos? "           << B.listeElementos() << endl;

    cout << "Ahora B se convierte en vacío." << endl;
    B.vacie();

    cout << "¿El conjunto B es un conjunto vacío? " << B.esVacio() << endl;
    cout << "¿Cuáles son sus elementos? "           << B.listeElementos() << endl;
    cout << "¿Cuál es su capacidad? "               << B.capacidad() << endl;

   return '\n';
}

