// Módulo   : minicomClase.cpp
// Autor    : Eugenio Martínez
// Propósito: Definir la clase MiniCom.
// Licencia : Copyright (C) 2020-2021 - Eugenio Martínez - torrentelinux@gmail.com
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 3
// of the License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#define STRICT
#define __USELOCALES__

#include <clocale>
#include <tchar.h>

#include <windows.h>

#include "LadrilloModular.h"
#include "minicomClase.h"

// Macro para el reporte de errores en funciones API
#define PERR(bSuccess, api) {if(!(bSuccess)) fprintf(stderr, "%s: Error %ld from %s \
    on line %d\n", __FILE__, GetLastError(), api, __LINE__);}

HWND *id_minicom = NULL;
LadrilloConCalce cpp;

MiniCom::MiniCom()
{
	BOOL bCorrecto = 0;
	COORD dim_pantalla = { 152, 42 };
	SMALL_RECT tam_ventana = { 0, 0, 151, 41};

   if(id_minicom == NULL)
     id_minicom = new HWND;

   SetConsoleTitle("MiniCom");
   *id_minicom = GetConsoleWindow();

   bCorrecto = ShowScrollBar(*id_minicom, SB_BOTH, FALSE);
   PERR(bCorrecto, "ShowScrollBar");

   bCorrecto = SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), dim_pantalla);
   PERR(bCorrecto, "SetConsoleScreenBufferSize");

   bCorrecto = SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &tam_ventana);
   PERR(bCorrecto, "SetConsoleWindowInfo");

   bCorrecto = ShowWindow(*id_minicom, SW_SHOWNORMAL);
   PERR(bCorrecto, "ShowWindow");

   // Deshabilita las opciones del menú sistema de la ventana consola:
   // Cerrar, Maximizar, Minimizar y Restaurar.
   DeleteMenu(GetSystemMenu(*id_minicom, false), SC_CLOSE, MF_BYCOMMAND);
   DeleteMenu(GetSystemMenu(*id_minicom, false), SC_MAXIMIZE, MF_BYCOMMAND);
   DeleteMenu(GetSystemMenu(*id_minicom, false), SC_MINIMIZE, MF_BYCOMMAND);
   DeleteMenu(GetSystemMenu(*id_minicom, false), SC_RESTORE, MF_BYCOMMAND);

   DrawMenuBar(*id_minicom);

   es_informativo = true;
   comspec = "";

   if(getenv("COMSPEC"))
     comspec = getenv("COMSPEC");
   else
   {
     // Alternativa --> c:\Windows\SysWOW64\cmd.exe
     comspec = "COMSPEC=c:\\windows\\system32\\cmd.exe";
     putenv(comspec.c_str());

     *(cpp.iostream.cerr) << "Error: no existe COMSPEC." << endl
                          << "Ajustado COMSPEC a " << comspec.c_str() << endl;
   }
}

MiniCom::~MiniCom()
{
   if(id_minicom)
   {
     GetSystemMenu(*id_minicom, TRUE);
     DrawMenuBar(*id_minicom);

     delete id_minicom;
     id_minicom = NULL;
   }
}

// Informa qué lengua local está usando minicom.
void MiniCom::lengua(void)
{
   *(cpp.iostream.cout) << "Lengua local:" << endl
                        << setlocale(LC_ALL, NULL) << endl
                        << "Código de página activa: " << GetConsoleOutputCP()
                        << endl;
}

void MiniCom::informativo(bool dato)
{
   es_informativo = dato;
}

// Muestra una ayuda breve sobre los comandos admitidos.
void MiniCom::ayuda(void)
{
   *(cpp.iostream.cout) << "Mini intérprete de comandos para Windows.\n" << endl
			<< "Comandos admitidos en Minicom:" << endl
			<< "* salir : sale de minicom." << endl
			<< "* lengua: informa qué lengua y código de página local está activa." << endl
			<< "* ayuda : muestra esta ayuda en pantalla." << endl
			<< "* cmd   : ejecuta comandos externos, por ejemplo clear." << endl
			<< endl
			<< "Combinaciones de teclas admitidas:" << endl
			<< "CTRL+Inter: interrumpe la ejecución de minicom." << endl
			<< "CTRL+A: amplía la ventana de la consola (maximiza)." << endl
			<< "CTRL+C: idem a CTRL+Inter." << endl
			<< "CTRL+D: sale de minicom." << endl
			<< "CTRL+G: emite un pitido por el altavoz de la computadora." << endl
			<< "CTRL+L: borra la pantalla." << endl
                        << "CTRL+O: contrae la ventana de la consola (minimiza)." << endl
			<< "CTRL+R: restaura la ventana de la consola." << endl
			<< "CTRL+Z: finaliza la ejecución de minicom." << endl
			<< endl
			<< "Por ejemplo: tecla CTRL y tecla L luego tecla Intro --> borra la pantalla." << endl;
}

// Sale del programa minicom.
void MiniCom::salir(void)
{
   *(cpp.iostream.cout) << endl << "Saliendo..." << endl;

   if(id_minicom)
   {
     GetSystemMenu(*id_minicom, TRUE);
     DrawMenuBar(*id_minicom);

     delete id_minicom;
     id_minicom = NULL;
   }

   cpp.cstdlib.exit(EXIT_SUCCESS);
}

// Ejecuta comandos externos a minicom.
void MiniCom::cmd(char *cmd)
{
	int status = 0;
	int pid = 0;
   	const char *shell = comspec.c_str();
	char *args[] = { (char *const)shell, (char *const)"/c", cmd, NULL };

   if(*cmd == '\0')
   {
	*(cpp.iostream.cerr) << "Error: no hay comando para invocar." << endl;
	return;
   }

   SetConsoleOutputCP(850);
   SetConsoleCP(850);

   if(es_informativo)
     *(cpp.iostream.cout) << "Comando: " << cmd << endl;

   // Ejecuta el proceso
   pid = cpp.cprocess.spawnv(P_NOWAIT, shell, args);
   if(pid == -1)
   {
      *(cpp.iostream.cerr) << "Error en " << __FUNC__ << "(): " << cpp.C.strerror(errno) << endl
			   << "Args: " << args[0] << " " << args[1] << " " << args[2] << endl;
      return;
   }

   if(es_informativo)
     *(cpp.iostream.cout) << "Subproceso: " << pid << endl;

   if(cpp.cprocess.cwait(&status, pid, 0) != -1)
   {
     if(es_informativo)
       *(cpp.iostream.cout) << "status=" << status << endl;
   }
   else
      cpp.C.perror("-Error en cwait()-");

   SetConsoleOutputCP(1252);
   SetConsoleCP(1252);
}

// Muestra en pantalla el indicador de petición de comandos.
void MiniCom::indicador(const char *ipc)
{
   *(cpp.iostream.cout) << ipc << flush;
}

// Borra toda la pantalla
void MiniCom::borrar(void)
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

// Maximiza la ventana consola
void MiniCom::ampliar(void)
{
   if(id_minicom)
   {
     ShowWindow(*id_minicom, SW_MAXIMIZE);
     SetFocus(*id_minicom);
   }
}

// Minimiza la ventana consola
void MiniCom::contraer(void)
{
   if(id_minicom)
   {
     ShowWindow(*id_minicom, SW_MINIMIZE);
   }
}

// Restaura las dimensiones de la ventana consola
void MiniCom::restaurar(void)
{
   if(id_minicom)
   {
     ShowWindow(*id_minicom, SW_RESTORE);
     SetFocus(*id_minicom);
   }
}

/*
	//char *args[] = { "c:\\windows\\system32\\cmd.exe", "/c", cmd, NULL };
	//char *args[] = { (char *const)"c:\\windows\\system32\\cmd.exe", (char *const)"/c", cmd, NULL };
*/
