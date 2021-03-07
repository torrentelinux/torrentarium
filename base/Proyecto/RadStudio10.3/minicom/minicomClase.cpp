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

#include <tchar.h>
#include <windows.h>

#include "LadrilloModular.h"
#include "minicomClase.h"

// Macro para producir un informe de errores en funciones API
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

   if(cpp.cstdlib.getenv("base"))
     var_base = cpp.cstdlib.getenv("base");  // Toma variable de entorno 'base=<contenido>'
   else
   {
     var_base = "base=c:\\base";
     cpp.cstdlib.putenv(var_base.c_str());

     *(cpp.iostream.cerr) << "ERROR: no existe var. entorno 'base'." << endl
                          << "Ajustado 'base' a " << var_base.c_str() << endl;
   }

   ncf_shells << var_base << "\\config\\shells" << ends;

   if(cpp.cstdlib.getenv("COMSPEC"))
     comspec = cpp.cstdlib.getenv("COMSPEC");  // Toma cmd.exe ~ command.com
   else
   {
     // Alternativa --> leer \base\config\shells
     comspec = "COMSPEC=c:\\windows\\system32\\cmd.exe";
     cpp.cstdlib.putenv(comspec.c_str());

     *(cpp.iostream.cerr) << "Error: no existe COMSPEC." << endl
                          << "Ajustado COMSPEC a " << comspec.c_str() << endl;
   }

   // Pone título a la ventana: dir. actual
   titular(dir_vigente());

   // Guardar el estado actual de la ventana
   guardarEstado();
}

MiniCom::~MiniCom()
{
   if(id_minicom)
   {
     // Restablece las opciones del menú sistema de la ventana consola
     GetSystemMenu(*id_minicom, TRUE);

     // Restaura el estado inicial de la ventana consola
     recuperarEstado();

     DrawMenuBar(*id_minicom);

     delete id_minicom;
     id_minicom = NULL;
   }
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

void MiniCom::guardarEstado(void)
{
   cout << "1-Falta terminar..." << endl;
}

void MiniCom::recuperarEstado(void)
{
   cout << "2-Falta terminar..." << endl;
}

_TCHAR *MiniCom::dir_vigente(void)
{
        int status = 0;
        static _TCHAR dirActual[MAXDIR+16] = { "" };

   cpp.mem.memset(dirActual, 0, MAXDIR);
   status =  cpp.cdir.getcurdir(0, dirActual);

   if(status == -1)
     *dirActual = '\0';  // No se pudo leer el nombre del directorio actual

   return dirActual;
}

BOOL MiniCom::titular(const _TCHAR *ti)
{
   return SetConsoleTitle(ti);
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

// Ejecuta comandos externos a mic.
void MiniCom::cmd(char *cmd)
{
	int status = 0;
	int pid = 0;
   	const char *shell = comspec.c_str();
	char *args[] = { (char *const)shell, (char *const)"/c", cmd, NULL };
        const char *ext = NULL;
        char *ext_exe = NULL;

   if(*cmd == '\0')
   {
	*(cpp.iostream.cerr) << "Error: no hay comando para invocar." << endl;
	return;
   }

   if(comspec.empty())
   {
	*(cpp.iostream.cerr) << "Error: no hay intérprete de comandos para invocar." << endl
                             << "Se recomienda ejecutar 'com listar' para conocer la lista de intérpretes de comandos disponibles en el Sistema." << endl;
	return;
   }

   ext = cpp.cstring.strchr(shell, '.');
   if(ext == NULL)
   {
     *(cpp.iostream.cerr) << "Aviso: no posee extensión .exe el intérprete de comandos vigente." << endl
                          << "Se recomienda cambiar por otro que posea la extensión faltante." << endl;
     return;
   }

   ext_exe = cpp.cstring.strlwr((char *)ext);
   if(cpp.cstring.strcmp(ext_exe, ".exe") != 0)
   {
     *(cpp.iostream.cerr) << "Aviso: el intérprete de comandos vigente posee una extensión no aceptada." << endl
                          << "Se recomienda cambiar por otro que posea la extensión '.exe'." << endl;
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
      *(cpp.iostream.cerr) << "Error en " << __FUNC__ << "(): " << cpp.C.strerror(errno)
			   << "Args: " << args[0] << " " << args[1] << " " << args[2] << endl;

   }
   else
   {
     if(es_informativo)
       *(cpp.iostream.cout) << "Subproceso: " << pid << endl;

     if(cpp.cprocess.cwait(&status, pid, 0) != -1)
     {
       if(es_informativo)
         *(cpp.iostream.cout) << "status=" << status << endl;
     }
     else
        cpp.C.perror("-Error en cwait()-");
   }

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

void MiniCom::comando(_TCHAR *secuencia_comando)
{
        istringstream lectura(secuencia_comando);
        string parte1 = "", parte2 = "", parte3 = "";

   lectura >> parte1 >> parte2 >> parte3;
   if(parte1 == "com")
   {
     if(parte2.empty())
       *(cpp.iostream.cout) << "Intérprete de comandos activo: " << comspec << endl;
     else
       if(parte2 == "listar")
         listar_shells();
       else
         if(parte2 == "borrar")
           borrar_shell();
         else
           if(parte2 == "cambiar")
             cambiar_shell(parte3);
           else
             cerr << "Error: parámetro no reconocido." << endl;
   }
   else
     cerr << "Error: comando no reconocido." << endl;
}

void MiniCom::listar_shells(void)
{
        int nro = 0;
        _TCHAR linea_shell[272] = { _TEXT("") };

   // Abre %base%\config\shells
   if_shells.open(ncf_shells.str().c_str());

   if(if_shells.is_open())
   {
     *(cpp.iostream.cout) << "Lista de shells disponibles:" << endl;

     if_shells.seekg(0, ios::beg);

   // leer %base%\config\shells
     while(!if_shells.eof())
     {
       if_shells.getline(linea_shell, 256);
       *(cpp.iostream.cout) << "<(" << ++nro << ")>" << linea_shell << endl;

       cpp.mem.memset(linea_shell, 0, 256);
     }

     if_shells.close();
   }
   else
   {
     *(cpp.iostream.cerr) << "ERROR: no se pudo abrir fichero " << ncf_shells.str().c_str() << endl;
   }
}

void MiniCom::borrar_shell(void)
{
   *(cpp.iostream.cout) << "Borrando shell actual: " << comspec << endl;
   comspec.clear();
}

void MiniCom::cambiar_shell(string npos)
{
        int xpos = -1;
        int nro = 0;
        istringstream a_entero(npos);
        _TCHAR linea_shell[272] = { _TEXT("") };

   a_entero >> xpos;
   if(xpos < 1)
   {
     *(cpp.iostream.cerr) << "ERROR: valor no permitido." << endl;
     return;
   }

   // Lee fichero %base%\config\shells
   if_shells.open(ncf_shells.str().c_str());

   if(if_shells.is_open())
   {
     if_shells.seekg(0, ios::beg);

     while(!if_shells.eof())
     {
       nro++;
       if_shells.getline(linea_shell, 256);

       if(xpos == nro)
       {
         comspec = linea_shell;
         *(cpp.iostream.cout) << "Estableciendo nuevo shell actual: " << comspec << endl;

         break;
       }
       else
         cpp.mem.memset(linea_shell, 0, 256);
     }

     if(xpos != nro)
       *(cpp.iostream.cout) << "Aviso: no hubo cambios." << endl;

     if_shells.close();
   }
   else
   {
     *(cpp.iostream.cerr) << "ERROR: no se pudo abrir fichero " << ncf_shells.str().c_str() << endl;
   }
}

// Muestra una ayuda breve sobre los comandos admitidos.
void MiniCom::ayuda(void)
{
   *(cpp.iostream.cout) << "Mini intérprete de comandos (mic) para Windows.\n" << endl
			<< "Comandos admitidos en Minicom:" << endl
			<< "* salir : sale de minicom." << endl
			<< "* lengua: informa qué lengua y código de página local está activa." << endl
			<< "* com [listar|borrar|cambiar] : configura básicamente el intérprete de comandos a invocar." << endl
                        << "      Al ejecutar 'com' sin argumentos se visualiza la shell en curso." << endl
                        << "      listar: Muestra una lista enumerada de shells disponibles en el sistema." << endl
                        << "      borrar: Borra la shell actual en curso." << endl
                        << "      cambiar <nº>: Cambia la shell actual por otra. Use 'com listar' para conocer el nº de orden." << endl
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

