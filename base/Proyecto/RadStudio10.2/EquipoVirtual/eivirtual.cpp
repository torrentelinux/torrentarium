// eiVirtual.cpp

#include <tchar.h>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <windows.h>

#include "eiv.h"

// Macro para producir un informe de errores en funciones API
#define PERR(bSuccess, api) {if(!(bSuccess)) fprintf(stderr, "%s: Error %ld from %s \
			     on line %d\n", __FILE__, GetLastError(), api, __LINE__);}

MaquinaVirtual::MaquinaVirtual()
{
}

MaquinaVirtual::~MaquinaVirtual()
{
   cout << "." << flush;
   pausa(3);
}

// status = 0  -> apagar
// status = 1  -> encender
// status = 2  -> reiniciar
// status = 3  -> suspender
// status = 4  -> hibernar
// status = -1 -> error
int MaquinaVirtual::MVencender(int status)
{
   SetConsoleCP(cp_fijado());
   SetConsoleOutputCP(cp_fijado());

   cout << "Encendiendo..." << endl;
   return status;
}

int MaquinaVirtual::iniciar(int status)
{
   cout << "Iniciando m quina virtual " << conocer_nombre(fijado()) << endl;

   return status;
}

string MaquinaVirtual::conocer_nombre(string nombre)
{
   return nombre;
}

string MaquinaVirtual::pedir_nombre()
{
   return fijado();
}

void MaquinaVirtual::pausa(int t)
{
   Sleep(t*1000);
}

int MaquinaVirtual::condicion(const int status)
{
   if(status == apagar)
     cout << "Código de salida: " << status << endl;

   if(status == encender)
     MVencender(status);

   return status;
}
//___________________________________________________________
SistemaOperativo::SistemaOperativo()
{
}

SistemaOperativo::~SistemaOperativo()
{
   cout << "·" << flush;
   pausa(1);
}

int SistemaOperativo::encender(int status)
{
   SetConsoleCP(cp_fijado());
   SetConsoleOutputCP(cp_fijado());

   cout << "Encendiendo S.O. ..." << endl;
   return status;
}

int SistemaOperativo::iniciar(int status)
{
   cout << "Iniciando sistema operativo " << conocer_nombre(fijado()) << endl;
   cout << so_completo() << ", ver. " << so_ver() << endl;
   cout << so_derechos() << endl;

   return status;
}

string SistemaOperativo::conocer_nombre(string nombre)
{
   return nombre;
}

void SistemaOperativo::pausa(int t)
{
   Sleep(t*1000);
}
//___________________________________________________________
Sesion::Sesion()
{
}

Sesion::~Sesion()
{
   cout << "·" << flush;
   pausa(1);
}

int Sesion::iniciar(int status)
{
   cout << "Iniciando sesión..." << endl;
   return status;
}

void Sesion::pausa(int t)
{
   Sleep(t*1000);
}
//___________________________________________________________
Comando::Comando()
{
}

Comando::~Comando()
{
   cout << "." << flush;
   pausa(3);
}

void Comando::pausa(int t)
{
   Sleep(t*1000);
}

int Comando::iniciar(int status)
{
   cout << "Iniciando comando..." << endl;
   return status;
}

// Borra toda la pantalla
void Comando::cmdBP(void)
{
	BOOL bCorrecto;
	DWORD cCarsEscritos;
	DWORD dwConTam;
	HANDLE hConsola;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD coordPantalla = { 0, 0 };

    hConsola = GetStdHandle(STD_OUTPUT_HANDLE);

    bCorrecto = GetConsoleScreenBufferInfo(hConsola, &csbi);
    PERR(bCorrecto, "GetConsoleScreenBufferInfo");
    dwConTam = csbi.dwSize.X * csbi.dwSize.Y;

    bCorrecto = FillConsoleOutputCharacter(hConsola, (TCHAR)' ', dwConTam, coordPantalla, &cCarsEscritos);
    PERR(bCorrecto, "FillConsoleOutputCharacter");

    bCorrecto = GetConsoleScreenBufferInfo(hConsola, &csbi);
    PERR(bCorrecto, "ConsoleScreenBufferInfo");

    bCorrecto = FillConsoleOutputAttribute( hConsola, csbi.wAttributes, dwConTam, coordPantalla, &cCarsEscritos);
    PERR(bCorrecto, "FillConsoleOutputAttribute");

    bCorrecto = SetConsoleCursorPosition(hConsola, coordPantalla);
    PERR(bCorrecto, "SetConsoleCursorPosition");
}

string Comando::comandos()
{
	ostringstream listado;

   listado << cmdAyuda() << ", " << cmdApagar() << ", "
	   << cmdBorrarPantalla() << ", "
           << cmdCerrar()
	   << ends;

   return listado.str();
}

int Comando::ejecutar(int status)
{
	char entrada[272] = { "" };

   if(status == 1)
   {
     cout << "Escriba '" << cmdAyuda() << "' para conocer más comandos." << endl;
     do
     {
       cout << "# " << flush;
       cin.getline(entrada, 256);

       // línea vacía
       if(*entrada == '\0')
	 continue;

       // borra la pantalla
       if(*entrada == '\f')
       {
	 cmdBP();
	 continue;
       }

       if(string(entrada).compare(cmdApagar()) == 0)
       {
	 cout << "Apagando el equipo " << MaquinaVirtual().pedir_nombre() << endl;
	 status = 0;
	 break;
       }
       else
       {
	 if(string(entrada).compare(cmdAyuda()) == 0)
	 {
	   cout << "Comandos admitidos: " << comandos().c_str() << endl;
	 }
	 else
	   if(string(entrada).compare(cmdBorrarPantalla()) == 0)
	     cmdBP();
	   else
	     cout << "Ejecuta comando: " << entrada << endl;
       }

       memset(entrada, 0, 256);

     } while(true);
   }

   return status;
}

