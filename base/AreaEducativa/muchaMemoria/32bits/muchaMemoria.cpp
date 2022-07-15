// muchaMemoria.cpp
// Octulio Biletán - Julio de 2022.
// Hace una prueba intensiva sobre la memoria RAM asignando ceros en un rango de 8 Gbytes.
// Versión de 32 bits para Windows.
// Compilar: bcc32x muchaMemoria.cpp (sistema Windows).
//           g++ muchaMemoria.cpp -o muchaMemoria.exe (sistema Windows).
//           g++ muchaMemoria.cpp -s -v -o muchaMemoria (sistema Linux).

#include <iostream>
#include <new>

#if defined(__linux__)
#  include <unistd.h>
#endif

#if defined(__CYGWIN__)
#  include <unistd.h>
#endif

#if defined(__BORLANDC__)
#  include <dos.h>
#endif

#if defined(_Windows)
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
const unsigned long int tope = 2147483648 / 2;

// Define la región de memoria a llenar con ceros
RegionMemoria banco[nroBancos] = { NULL };

// Hace una pausa de 'x' segundos en la ejecución de la aplicación
void esperar(unsigned int x)
{
#if defined(_Windows)
    Sleep(x * 1000);
#else
    sleep(x);
#endif
}

int main()
{
	int status = 0;
	unsigned long int i = 0;

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
