// conjunto.cpp
// Implementación básica de la clase 'Conjunto'.
// Puede almacenar hasta 3 elementos numéricos.
//
// Implementación de la subclase extendida 'xConjunto'.
// Puede almacenar hasta 1024 elementos numéricos.
//
// Licencia: Software Libre.

#include <cstring>
#include <cstdio>

#include "conjunto.h"

// Devuelve "sí" si el elemento 'd' está contenido en el conjunto.
// Devuelve "no" si el elemento 'd' no está contenido en el conjunto.
const char *Conjunto::contiene(int d)
{
            int valores[] = { a1, a2, a3 };
            static string respuesta;

    respuesta = _no;
    for(unsigned int i = 0; i < (sizeof(valores) / sizeof(int)); i++)
    {
            if(valores[i] == d)
            {
                respuesta = _si;
                break;
            }
    }

    return respuesta.c_str();
}

// Devuelve "sí" si el conjunto es el conjunto vacío.
// Devuelve "no" si el conjunto no es el conjunto vacío.
const char *Conjunto::esVacio(void)
{
            int valor[] = { a1, a2, a3 };
            int cuenta = 0;
            static string respuesta;

    respuesta = _no;
    for(unsigned int i = 0; i < (sizeof(valor) / sizeof(int)); i++)
    {
        if(valor[i] == -1)
        {
            cuenta++;
        }
    }

    if(cuenta == _capacidad)
        respuesta = _si;

    return respuesta.c_str();
}

// Si el conjunto es vacío devuelve "{ Ø }",
// sino una lista de elementos numéricos "{ a1, a2, a3 }".
const char *Conjunto::listeElementos(void)
{
            string respuesta;
            static char valores[64];

    strcpy(valores, "{ Ø }");
    respuesta = esVacio();

    if(respuesta == _no)
        sprintf(valores, "{ %d,%d,%d }", a1, a2, a3 );

    return valores;
}

// Transforma en conjunto vacío.
void Conjunto::vacie(void)
{
    a1 = a2 = a3 = indefinido;	// El conjunto carece de datos válidos.
    _elementos = ninguno;	// El conjunto está vacío.
    _capacidad = 3;		// El conjunto puede alojar hasta tres elementos numéricos.
}

// -------------------------------

xConjunto::xConjunto():Conjunto(0)
{
    _elementos = ninguno;       // El conjunto está vacío.
    _capacidad = 1024;          // El conjunto puede alojar hasta 1024 elementos numéricos.
    _pares = _impares = ninguno;
    _nombre = sin_nombre;	// El conjunto no posee nombre.

    (void)memset(&a, indefinido, sizeof(int) * _capacidad);  // Todo el vector está indefinido
}

xConjunto::xConjunto(int vNum[1024], int cant):Conjunto(0)
{
    _capacidad = 1024;          // El conjunto puede alojar hasta 1024 elementos numéricos.
    _pares = _impares = ninguno;

    if(cant > _capacidad)
        cant = _capacidad;

    _elementos = cant;
    (void)memset(&a, indefinido, sizeof(int) * _capacidad);  // Todo el vector está indefinido.

    for(int i = 0; i < cant; i++)
        a[i] = vNum[i];         // El conjunto destino contiene los valores del vector recibido
}

const char *xConjunto::esVacio(void)
{
        int cuenta = 0;
        unsigned int nelems;
        static string respuesta;

    respuesta = _no;
    nelems = sizeof(a) / sizeof(int);

    for(unsigned int i = 0; i < nelems; i++)
    {
        if(a[i] == indefinido)
        {
            cuenta++;
        }
    }

    if(cuenta == _capacidad)
        respuesta = _si;

    return respuesta.c_str();
}

void xConjunto::introducePares(xConjunto e)
{
        int tmp = 0;
        int k = 0;
        string respuesta;

    respuesta = e.esVacio();

    if(respuesta == _si)
        return;  // el conjunto está vacío.

    // recorre todo el contenido del conjunto 'e'
    for(int i = 0, k = 0; i < e.elementos(); i++)
    {
        if(e.a[i] < 1)  // ignora el 0 y los nros negativos
          continue;

        tmp = e.a[i] % 2;   // calcula el módulo
        if(tmp == 0)        // si es cero entonces es par
        {
            a[k++] = e.a[i];  // guarda el valor en el conjunto destino
            _pares++;       // cuenta los nº pares guardados en el conjunto destino
        }
    }

    if(_pares > 0)
      _elementos = _pares;  // actualiza la cantidad de elementos numéricos que posee el conjunto
}

int xConjunto::pares(void)
{
   return _pares;
}

int xConjunto::impares(void)
{
   return _impares;
}

const char *xConjunto::listeElementos(void)
{
            static string lista;
            string respuesta;
            char tmp[32];

    lista = "{ Ø }";
    respuesta = esVacio();

    if(respuesta == _no)
    {
        lista = "{ ";

        for(int i = 0; i < xConjunto::_elementos; i++)
        {
            sprintf(tmp, "%d,", a[i]);
            lista.append(tmp);
        }

        lista[lista.length()-1] = ' ';  // borra la última coma de la lista
        lista.append("}");
    }

    return lista.c_str();
}

void xConjunto::introduceImpares(xConjunto e)
{
        int tmp = 0;
        int k = 0;
        string respuesta;

    respuesta = e.esVacio();

    if(respuesta == _si)
        return;  // el conjunto está vacío.

    // recorre todo el contenido del conjunto 'e'
    for(int i = 0, k = 0; i < e.elementos(); i++)
    {
        if(e.a[i] < 1)  // ignora el 0 y los nros negativos
          continue;

        tmp = e.a[i] % 2;   // calcula el módulo
        if(tmp == 1)        // si es uno entonces es impar
        {
            a[k++] = e.a[i];  // guarda el valor en el conjunto destino
            _impares++;       // cuenta los nº impares guardados en el conjunto destino
        }
    }

    if(_impares > 0)
      _elementos = _impares;  // actualiza la cantidad de elementos numéricos que posee el conjunto
}
