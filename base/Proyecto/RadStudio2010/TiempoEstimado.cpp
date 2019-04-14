// TiempoEstimado.cpp
// Octulio Biletán - torrentelinux@gmail.com - 04|2019
// Realiza la cuenta desde 0 hasta 2^N - 1
// Comenzando con 2^18 hasta 2^36 incluído.
// Calcular y contar hasta 2^40 demandaría un tiempo aprox. de 1 hora.
// Proyecto ContarHasta.cbproj para Embarcadero RAD Studio 10.2/RAD Studio 2010

#include "ContarHasta.h"

class TiempoEstimado
{
   private:
	double frec;
	double tope;
	double tparcial;
	double ttotal;

	LARGE_INTEGER t2;
	LARGE_INTEGER t1;
	LARGE_INTEGER f;

   public:
	TiempoEstimado()
	{
            tparcial = ttotal = 0;
	    QueryPerformanceFrequency(&f);
	    frec = f.QuadPart;
	}

	// Realiza la operación de 2^N y cuenta desde 0 hasta 2^N - 1.
	// Devuelve el tiempo, en segs., consumido en la operación realizada.
	double calculos(int n)
	{
            // Calcula la potencia 2^N
            tope = pow(2, n);

            // Toma el tiempo de partida
            QueryPerformanceCounter(&t1);

            // Comienza a contar desde 0 hasta 2^N - 1
            for(double cuenta = 0; cuenta < tope; cuenta++)
              ;

            // Toma el tiempo de finalización.
            QueryPerformanceCounter(&t2);

            // Calcula el tiempo empleado en el ciclo for()
            tparcial = ((t2.QuadPart - t1.QuadPart) / frec);

            // Va sumando cada tiempo empleado
            ttotal += tparcial;

            // Devuelve el tiempo empleado en el ciclo for() en precisión simple.
            return tparcial;
	}

	// Devuelve el tiempo total, en segundos.
	double total_tiempos(void)
	{
            return ttotal;
	}
};

int _tmain(void)
{
        int simbolo = 0xDB;
        int demora = 249;
        double segs, mins;
        TiempoEstimado potenciaEstimada;
        ostringstream salida;

   cerr << "Calculando los tiempos para la cuenta\ndesde 2^18 hasta 2^36, aguarde unos minutos..." << endl;

   salida << "Contar hasta - Tiempo (segs.)" << endl;
   salida.setf(ios_base::fixed, ios_base::floatfield);
   salida.precision(3);

   // Toma los tiempos de cálculos desde 2^18 hasta 2^36 incluído.
   for(int n = 18; n < 37; n++)
   {
     salida << "2^" << n << "\t\t";
     salida << potenciaEstimada.calculos(n) << endl;

     cerr.put(simbolo); simbolo ^= 0xDC;
     Sleep(demora); demora ^= 2;
   }

   segs = potenciaEstimada.total_tiempos();
   mins = segs / 60.0;

   salida << endl << "Totales: " << segs << " segs. (" << mins << " mins.)" << endl << ends;
   cerr << endl;
   cout << salida.str().c_str();

   cerr << "Presione cualquier tecla para terminar...";
   cerr.put(simbolo);
   getch();

   cerr << endl;
   return 0;
}
