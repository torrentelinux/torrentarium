// Módulo   : minicomClase.cpp
// Autor    : Eugenio Martínez
// Propósito: Definir la clase MiniCom.

#include <windows.h>
#include <process.h>

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

   comspec = "";
   if(getenv("COMSPEC"))
     comspec = getenv("COMSPEC");
   else
     *(cpp.iostream.cerr) << "Error: no existe COMSPEC" << endl;
}

MiniCom::~MiniCom()
{
   delete id_minicom;
   id_minicom = NULL;
}

// Muestra una ayuda breve sobre los comandos admitidos.
void MiniCom::ayuda(void)
{
   *(cpp.iostream.cout) << "Comandos admitidos en minicom:" << endl;
   *(cpp.iostream.cout) << "* salir: sale de minicom." << endl;
   *(cpp.iostream.cout) << "* ayuda: muestra esta ayuda en pantalla." << endl;
   *(cpp.iostream.cout) << "* cmd  : ejecuta comandos externos, por ejemplo clear." << endl;
   *(cpp.iostream.cout) << endl;
   *(cpp.iostream.cout) << "Combinaciones de teclas admitidas:" << endl;
   *(cpp.iostream.cout) << "CTRL+Inter: interrumpe la ejecuci¢n de minicom." << endl;
   *(cpp.iostream.cout) << "CTRL+A: ampl¡a la ventana de la consola." << endl;
   *(cpp.iostream.cout) << "CTRL+C: idem a CTRL+Inter." << endl;
   *(cpp.iostream.cout) << "CTRL+D: sale de minicom." << endl;
   *(cpp.iostream.cout) << "CTRL+G: emite un pitido por el altavoz de la computadora." << endl;
   *(cpp.iostream.cout) << "CTRL+L: borra la pantalla." << endl;
   *(cpp.iostream.cout) << "CTRL+R: restaura la ventana de la consola." << endl;
   *(cpp.iostream.cout) << "CTRL+Z: sale de minicom." << endl;
   *(cpp.iostream.cout) << endl;
   *(cpp.iostream.cout) << "Por ejemplo: tecla CTRL y tecla L luego tecla Intro --> borra la pantalla." << endl;
}

// Sale del programa minicom.
void MiniCom::salir(void)
{
   *(cpp.iostream.cout) << endl << "Saliendo..." << endl;

   delete id_minicom;
   id_minicom = NULL;

   cpp.cstdlib.exit(EXIT_SUCCESS);
}

// Ejecuta comandos externos a minicom.
void MiniCom::cmd(char *cmd)
{
	int status = 0;
	int pid = 0;
	//char *args[] = { "c:\\windows\\system32\\cmd.exe", "/c", cmd, NULL };
	char *args[] = { (char *const)"c:\\windows\\system32\\cmd.exe", (char *const)"/c", cmd, NULL };

   if(*cmd == '\0')
   {
	*(cpp.iostream.cerr) << "Error: no hay comando para invocar." << endl;
	return;
   }

   *(cpp.iostream.cout) << "Comando: " << cmd << endl;

   pid = cpp.process.spawnv(P_NOWAIT, comspec.c_str(), args);
   if(pid == -1)
   {
      *(cpp.iostream.cerr) << "Error en " << __FUNC__ << "(): " << cpp.C.strerror(errno) << endl;
      *(cpp.iostream.cerr) << "Args: " << args[0] << " " << args[1] << " " << args[2] << endl;
      return;
   }

   *(cpp.iostream.cout) << "Subproceso: " << pid << endl;

   if(cpp.process.cwait(&status, pid, 0) != -1)
      *(cpp.iostream.cout) << "status=" << status << endl;
   else
      cpp.C.perror("-Error en cwait()-");
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

// Restaura las dimensiones de la ventana consola
void MiniCom::restaurar(void)
{
   if(id_minicom)
   {
     ShowWindow(*id_minicom, SW_RESTORE);
     SetFocus(*id_minicom);
   }
}

