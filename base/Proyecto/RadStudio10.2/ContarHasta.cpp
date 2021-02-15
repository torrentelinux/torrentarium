// ContarHasta.cpp
// Octulio Biletán - torrentelinux@gmail.com - 04|2019
// Realiza la cuenta desde 0 hasta 2^N - 1
// Comenzando con 2^18 hasta 'limite'.
// Proyecto ContarHasta.cbproj para Embarcadero RAD Studio 10.2/RAD Studio 2010.
// Compatible con versiones posteriores.
// Uso: ContarHasta
//      ContarHasta 36


#include "ContarHasta.h"

LadrilloConCalce *lib = NULL;
char hora[16];

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
		double cuenta = -1;

            // Toma el tiempo de partida
            QueryPerformanceCounter(&t1);

            // Cuenta desde 0 hasta tope-1 inclusive
	    do
	    {
	      cuenta++;
	      if(cuenta == tope)
		break;
	    } while(1);

            // Toma el tiempo de finalización.
            QueryPerformanceCounter(&t2);
        }

        void sumar_hasta(double tope)
        {
	    	double cuenta = -1;
                double sumador = 1;

            // Toma el tiempo de partida
            QueryPerformanceCounter(&t1);

            // Suma desde 0 hasta tope-1 inclusive
	    do
	    {
              sumador += cuenta;
	      cuenta++;
	      if(cuenta == tope)
		break;
	    } while(1);

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
            //sumar_hasta(lib->cmath.pow(2, n));
            contar_hasta(potencia(2, n));

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

        // Calcula x^n y devuelve el resultado como int64 sin signo.
        unsigned __int64 potencia(unsigned long int x, unsigned long int n)
        {
                unsigned long int i = 0;
                unsigned __int64 resultado = 1;

                ciclar:if(i < n)
                {
                  resultado *= x;
                  i++;
                  goto ciclar;
                }

                return resultado;
        }

        int ayuda(void)
        {
                unsigned __int64 max_val;

           max_val = potencia(2, sizeof(unsigned short int)*8);

           lib->C.puts("Ayuda:\n");
           lib->C.printf("Realiza la cuenta desde 0 hasta 2^N - 1 comenzando con 2^18 hasta N=%Lu\n", max_val);
           lib->C.puts("Uso sin argumentos: ContarHasta.exe");
           lib->C.puts("Uso con argumentos: ContarHasta.exe nn");
           lib->C.printf("donde 'nn' es un valor numérico válido desde 19 hasta %Lu\n", max_val);

           lib->consola.getch();
           return 1;
        }
};

void Exit(void)
{
   // Cambia el juego de caracteres para la entrada/salida estándar
   SetConsoleOutputCP(850);
   SetConsoleCP(850);

   // Libera de la memoria las vars. dinámicas
   if(lib)
   {
     delete lib;
     lib = NULL;
   }
}

void Entry(void)
{
   // Cambia el juego de caracteres para la entrada/salida estándar
   SetConsoleOutputCP(1252);
   SetConsoleCP(1252);

   // Inicializa la biblioteca estándar de funciones de C/C++
   if(lib == NULL)
   {
     lib = new LadrilloConCalce();
     *(lib->iostream.cerr) << "Hora actual: " << lib->ctime.strtime(hora) << endl;
   }
}

int _tmain(int argc, _TCHAR **argv)
{
        int simbolo = 0xDB;
        int demora = 211;  // Ajuste de velocidad: 211~249
        int tecla = 0;
        unsigned short int limite = 37;  // Potencia límite: 2^limite
        TiemposContarHasta tch;
        ostringstream salida;

   // Valores posibles para usar un único núcleo: 2, 4, 8, 16, ...
   SetProcessAffinityMask(GetCurrentProcess(), 2);
   SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS);
   SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_HIGHEST);

   *(lib->iostream.cerr) << "-- ContarHasta --" << endl;

   // Averigua por el valor límite ingresado por el usuario
   if(argc > 1)
   {
     if(lib->cctype.isdigit(argv[1][0]))
     {
       lib->C.sscanf(argv[1], "%hu", &limite);

       if(limite < 19)
         limite = 19;  // Valor mínimo utilizado para hacer cálculos
     }
     else
     {
       return tch.ayuda();
     }
   }

   *(lib->iostream.cerr) << "Calculando los tiempos para la cuenta\ndesde 2^18 hasta 2^"
                         << (limite-1) << ", aguarde unos minutos..."
                         << endl
                         << "<ESC> Cancela el cálculo."
                         << endl;

   salida << "Contar hasta - Tiempo (segs.)" << endl;
   salida.setf(ios_base::fixed, ios_base::floatfield);
   salida.precision(3);

   // Toma los tiempos de cálculos desde 2^18 hasta 2^'limite'.
   for(unsigned short int n = 18; n < limite; n++)
   {
     salida << "2^" << n << "\t\t" << tch.calculos(n) << endl;

     lib->iostream.cerr->put(simbolo);
     simbolo ^= 0xDC;

     Sleep(demora);
     demora ^= 2;

     if(kbhit())
     {
       tecla = getch();
       if(tecla == 27)
         break;
     }
   }

   salida << endl << "Totales: "
          << tch.total_tiempos() << " segs. ("
          << tch.a_minutos(tch.total_tiempos()) << " mins.)"
          << endl << ends;

   *(lib->iostream.cerr) << endl;

   // Muestra los resultados obtenidos.
   *(lib->iostream.cout) << salida.str().c_str();

   SetPriorityClass(GetCurrentProcess(), NORMAL_PRIORITY_CLASS);
   SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_NORMAL);

   *(lib->iostream.cerr) << "Hora actual: " << lib->ctime.strtime(hora)
                         << "\nPresione cualquier tecla para terminar...";
   lib->consola.getch();
   *(lib->iostream.cerr) << endl;

   return 0;
}
