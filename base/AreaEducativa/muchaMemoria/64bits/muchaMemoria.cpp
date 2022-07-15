// muchaMemoria.cpp
// Octulio Biletán - Julio de 2022.
// Hace una prueba intensiva sobre la memoria RAM asignando ceros en un rango de 8 Gbytes.
// Versión 64 bits para Windows y Linux.
// Compilar: g++ muchaMemoria.cpp -o muchaMemoria.exe (sistema Windows).
//           bcc64 muchaMemoria.cpp (sistema Windows).
//           g++ muchaMemoria.cpp -s -v -o muchaMemoria (sistema Linux).

#include <iostream>
#include <limits>
#include <new>

#if defined(__linux__)
#  include <unistd.h>
#else
#  include <windows.h>
#  include <synchapi.h>
#endif

using namespace std;

// Declara el área de memoria a trabajar con un puntero a caracter sin signo
struct RegionMemoria
{
    unsigned char *memoria;
};

// Cantidad de bancos de memoria
const int nroBancos = 8;

// Tamaño de cada banco de memoria
const unsigned long long tope = 4294967296 / 4;

// Define la región de memoria a llenar con ceros
RegionMemoria banco[nroBancos] = { NULL };

// Hace una pausa de 'x' segundos en la ejecución de la aplicación
void esperar(unsigned int x)
{
#if defined(__linux__)
    sleep(x);
#else
    Sleep(x * 1000);
#endif
}

int main()
{
	int status = 0;
	unsigned long long i = 0;

    cout << "Trabajando sobre " << nroBancos << " bancos de memoria, el tamaño de cada banco es de " << ((tope / 1024.0) / 1024.0) << " MB." << endl;
    try
    {
	for(int b = 0; b < nroBancos; b++)
	{
	  cout << "Banco nro. " << b << endl;
	
	  banco[b].memoria = new unsigned char[tope];
	  for(i = 0; i < tope; i++)
	    banco[b].memoria[i] = '0';

	  banco[b].memoria[tope] = 254;
	  cout << "Memoria: " << banco[b].memoria[tope] << endl;
	}

	for(int b = 0; b < nroBancos; b++)
	{
	  delete[] banco[b].memoria;
	  banco[b].memoria = NULL;
	}
	
	cout << "Trabajo completado." << endl;
    }
    catch(bad_alloc x)
    {
	cerr << "No hay memoria suficiente !!!" << endl;
        cerr << x.what() << endl;
	status = 1;
    }

    esperar(2);  // Hace una pausa por 2 segs.
    return status;
}
