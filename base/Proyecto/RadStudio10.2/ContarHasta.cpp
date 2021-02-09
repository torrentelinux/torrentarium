// ContarHasta.cpp
// Octulio Biletán - torrentelinux@gmail.com - 04|2019
// Realiza la cuenta desde 0 hasta 2^N - 1
// Comenzando con 2^18 hasta 2^36 incluído.
// Calcular y contar hasta 2^40 demandaría un tiempo aprox. de 1 hora.
// Proyecto ContarHasta.cbproj para Embarcadero RAD Studio 10.2/RAD Studio 2010.
// Compatible con versiones posteriores.
// Realizar: tiempo.cronometrar(contar.hasta(elevar_a(2,n)))
//           contar desde <expresionA> hasta <expresionB> incrementando <expresionC>
//           contar desde <expresionA> hasta <expresionB> decrementando <expresionC>

#include "ContarHasta.h"

LadrilloConCalce *lib = NULL;

class TiemposContarHasta
{
   private:
	double frec;
	double tparcial;
	double ttotal;

	LARGE_INTEGER t2;
	LARGE_INTEGER t1;
	LARGE_INTEGER f;

        void contar_hasta(double tope)
        {
            // Toma el tiempo de partida
            QueryPerformanceCounter(&t1);

          // Cuenta desde 0 hasta tope-1 inclusive
          for(double cuenta = 0; cuenta < tope; cuenta++)
            ;

            // Toma el tiempo de finalización.
            QueryPerformanceCounter(&t2);
        }

   public:
	TiemposContarHasta()
	{
            tparcial = ttotal = 0;
	    QueryPerformanceFrequency(&f);
	    frec = f.QuadPart;
	}

	// Realiza la operación de 2^N y cuenta desde 0 hasta 2^N - 1.
	// Devuelve el tiempo, en segs., consumido en la operación realizada.
	double calculos(unsigned short int n)
	{
            // Calcula la potencia 2^N y cuenta hasta 2^N - 1
            contar_hasta(lib->cmath.pow(2, n));

            // Calcula el tiempo empleado en contar_hasta()
            tparcial = ((t2.QuadPart - t1.QuadPart) / frec);

            // Va sumando cada tiempo empleado
            ttotal += tparcial;

            // Devuelve el tiempo empleado en el ciclo for() en precisión doble.
            return tparcial;
	}

	// Devuelve el tiempo total, en segundos.
	double total_tiempos(void)
	{
            return ttotal;
	}

        // Convierte el tiempo en segundos a minutos
        double a_minutos(double ts)
        {
          return (ts/60.0);
        }
};

void Exit(void)
{
   // Libera de la memoria las vars. dinámicas
   if(lib)
   {
     delete lib;
     lib = NULL;
   }
}

void Entry(void)
{
   // Inicializa la biblioteca estándar de funciones de C/C++
   if(lib == NULL)
     lib = new LadrilloConCalce();
}

int _tmain(void)
{
        int simbolo = 0xDB;
        int demora = 211;
        unsigned short int limite = 37;
        TiemposContarHasta tch;
        ostringstream salida;

   // Valores posibles para usar un único núcleo: 2, 4, 8, 16, ...
   SetProcessAffinityMask(GetCurrentProcess(), 2);
   SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS);

   *(lib->iostream.cerr) << "Calculando los tiempos para la cuenta\ndesde 2^18 hasta 2^" << (limite-1) << ", aguarde unos minutos..." << endl;

   salida << "Contar hasta - Tiempo (segs.)" << endl;
   salida.setf(ios_base::fixed, ios_base::floatfield);
   salida.precision(3);

   // Toma los tiempos de cálculos desde 2^18 hasta 2^'limite'.
   for(unsigned short int n = 18; n < limite; n++)
   {
     salida << "2^" << n << "\t\t";
     salida << tch.calculos(n) << endl;

     lib->iostream.cerr->put(simbolo);
     simbolo ^= 0xDC;

     Sleep(demora);
     demora ^= 2;
   }

   salida << endl << "Totales: "
          << tch.total_tiempos() << " segs. ("
          << tch.a_minutos(tch.total_tiempos()) << " mins.)"
          << endl << ends;

   *(lib->iostream.cerr) << endl;
   *(lib->iostream.cout) << salida.str().c_str();

   *(lib->iostream.cerr) << "Presione cualquier tecla para terminar...";
   lib->iostream.cerr->put(simbolo);

   lib->consola.getch();

   *(lib->iostream.cerr) << endl;

   return 0;
}
