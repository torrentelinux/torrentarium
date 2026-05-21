// conjunto.h
//
// Implementación básica de la clase 'Conjunto'.
// Puede almacenar hasta 3 elementos numéricos.
//
// Implementación de la subclase extendida 'xConjunto'.
// Puede almacenar hasta 1024 elementos numéricos.
//
// Licencia: Software Libre.

#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <string>

using namespace std;

static const int indefinido	= -1;
static const int ninguno	= 0;
static const string sin_nombre = "sin nombre";
static const char _si[] 	= "sí";
static const char _no[] 	= "no";

/**
 * Clase Conjunto.
 */
class Conjunto
{
    private:
	// Definición de las propiedades del conjunto.

	int _elementos;		// Cantidad de elementos numéricos que contiene el conjunto.
	int _capacidad;		// Capacidad máxima del conjunto para alojar sus elementos numéricos.
	string _nombre;		// Nombre del conjunto.

    public:
	int a1;  // Valor entero a1.
        int a2;  // Valor entero a2.
        int a3;  // Valor entero a3.

        // Constructor de la clase <b>Conjunto</b>:<br>
        Conjunto()
        {
            a1 = a2 = a3 = indefinido;	// El conjunto carece de datos válidos.
            _elementos = ninguno;	// El conjunto está vacío.
            _capacidad = 3;		// El conjunto puede alojar hasta tres elementos numéricos.
            _nombre = sin_nombre;	// El conjunto no posee nombre.
        }

        // Constructor de la clase <b>Conjunto</b>:<br>
        // Introduce uno o más datos numéricos al conjunto.
        Conjunto(int d1, int d2=-1, int d3=-1) : a1(d1), a2(d2), a3(d3)
        {
		int cuenta = 0;

            if(d1 != -1)
            {
        	cuenta++;
	    }

            if(d2 != -1)
            {
        	cuenta++;
            }

            if(d3 != -1)
            {
        	cuenta++;
            }

            _elementos = cuenta;
            _capacidad = 3;	// El conjunto puede alojar hasta tres elementos numéricos.
            _nombre = sin_nombre;
        }

        // Constructor de la clase <b>Conjunto</b>:<br>
        // Introduce al nuevo conjunto datos numéricos de otro conjunto.
        Conjunto(Conjunto &x)
        {
            a1 = x.a1;
            a2 = x.a2;
            a3 = x.a3;
            _elementos = x.elementos();		// El conjunto consta de 'x' elementos numéricos.
            _capacidad = x.capacidad();		// El conjunto puede alojar hasta 'x' elementos numéricos.
            _nombre = x.preguntaleNombre();
        }

        // Devuelve el nº de elementos numéricos que posee el <b>conjunto</b>.
        int elementos(void) { return _elementos; }

	// Devuelve el nº máximo de elementos numéricos que el <b>conjunto</b> puede alojar.
	int capacidad(void) { return _capacidad; }

        // Le pregunta por su nombre al <b>Conjunto</b>.
        const char *preguntaleNombre() { return _nombre.c_str(); }

        // Le otorga un nuevo nombre al <b>Conjunto</b>.
        void otorgaleNombre(string n) { _nombre = n; }

        // Introduce un nuevo dato numérico al <b>Conjunto</b>.
        void introduce(int d1) { a1 = d1; }

        // Introduce dos nuevos datos numéricos al <b>Conjunto</b>.
        void introduce(int d1, int d2) { a1 = d1; a2 = d2; }

        // Introduce tres nuevos datos numéricos al <b>Conjunto</b>.
        void introduce(int d1, int d2, int d3) { a1 = d1; a2 = d2; a3 = d3; }

	// Devuelve "sí" si el elemento 'd' está contenido en el conjunto.
	// Devuelve "no" si el elemento 'd' no está contenido en el conjunto.
        const char *contiene(int d);

        // Devuelve "sí" si el conjunto es el conjunto vacío.
        // Devuelve "no" si el conjunto no es el conjunto vacío.
        const char *esVacio(void);

        // Si el conjunto es vacío devuelve "{ Ø }",
        // sino una lista de elementos numéricos "{ a1, a2, a3 }".
        const char *listeElementos(void);

        // Transforma en conjunto vacío.
        void vacie(void);
};

class xConjunto : protected Conjunto
{
    private:
        // Definición de las propiedades de xConjunto.

	int _elementos;		// Cantidad de elementos numéricos que contiene el conjunto.
	int _capacidad;		// Capacidad máxima del conjunto para alojar sus elementos numéricos.
        int _pares;             // Cantidad de elementos numéricos pares que contiene el conjunto.
        int _impares;           // Cantidad de elementos numéricos impares que contiene el conjunto.
	string _nombre;		// Nombre del conjunto.

    public:
        int a[1024];            // Los elementos numéricos son tratados en un vector de nº enteros.
        xConjunto();            // Constructor de la clase <b>xConjunto</b>.
        xConjunto(int vNum[1024], int cant);  // Constructor de la clase <b>xConjunto</b> que recibe un vector de elementos numéricos.

        // Devuelve el nº de elementos numéricos que posee el <b>conjunto</b>.
        int elementos(void) { return _elementos; }

	// Devuelve el nº máximo de elementos numéricos que el <b>conjunto</b> puede alojar.
	int capacidad(void) { return _capacidad; }

        // Le pregunta por su nombre al <b>Conjunto</b>.
        const char *preguntaleNombre() { return _nombre.c_str(); }

        // Le otorga un nuevo nombre al <b>Conjunto</b>.
        void otorgaleNombre(string n) { _nombre = n; }

        // Devuelve "sí" si el conjunto es el conjunto vacío.
        // Devuelve "no" si el conjunto no es el conjunto vacío.
        const char *esVacio(void);

        // Introduce en el conjunto los elementos numéricos pares positivos del conjunto 'e'.
        void introducePares(xConjunto e);

        // Devuelve el nº de elementos numéricos pares que posee el <b>conjunto</b>.
        int pares(void);

        // Introduce en el conjunto los elementos numéricos impares positivos del conjunto 'e'.
        void introduceImpares(xConjunto e);

        // Devuelve el nº de elementos numéricos impares que posee el <b>conjunto</b>.
        int impares(void);

        // Ordena los elementos numéricos del conjunto de menor a mayor (0, 1, 2, 3, ...).
        void ordenamM();

        // Ordena los elementos numéricos del conjunto de mayor a menor (..., 3, 2, 1, 0).
        void ordenaMm();

        // Si el conjunto es vacío devuelve "{ Ø }",
        // sino una lista de elementos numéricos "{ 1, 2, 3, ... }".
        const char *listeElementos(void);

        /* Otros casos a implementar
         * leePositivos(), leeNegativos(), leePrimos()
         */
};

#endif		// CONJUNTO_H
