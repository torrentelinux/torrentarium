// Programa : minicom.cpp
// Autor    : Eugenio Martínez
// Propósito: Definir un mini intérprete de comandos
//            para sistemas Windows.
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

void Entry(void);
void Exit(void);
BOOL setcurrentfont(wchar_t *nfuente, SHORT tamTipoLetra);

#pragma startup Entry
#pragma exit Exit

LadrilloConCalce lib;
string indicador_linea_comando;

void Exit(void)
{
	UINT cod_pag;

   cod_pag = GetConsoleOutputCP();
   if(cod_pag != 850)
   {
     // Cambia el juego de caracteres para la entrada/salida estándar
     SetConsoleOutputCP(850);
     SetConsoleCP(850);
   }

   lib.clocale.setlocale(LC_ALL, "");
   setcurrentfont(L"Lucida Console", 14);
   indicador_linea_comando = "";
}

void Entry(void)
{
	UINT cod_pag;

   indicador_linea_comando = " ";

   cod_pag = GetConsoleOutputCP();
   if(cod_pag != 1252)
   {
     // Cambia el juego de caracteres para la entrada/salida estándar
     SetConsoleOutputCP(1252);
     SetConsoleCP(1252);
     lib.clocale.setlocale(LC_ALL, "Spanish_Argentina.1252");

     indicador_linea_comando[0] = 187;  // ANSI=187
   }
   else
   {
     SetConsoleOutputCP(850);
     SetConsoleCP(850);
     lib.clocale.setlocale(LC_ALL, "Spanish_Argentina.850");

     indicador_linea_comando[0] = 175;  // OEM=175
   }

   // Fuente de caracteres: Lucida Console, 14 pts.
   setcurrentfont(L"Lucida Console", 14);
}

// Establece una nueva fuente de caracteres para la consola de textos
// Devuelve true/false.
BOOL setcurrentfont(wchar_t *nfuente, SHORT tamTipoLetra)
{
        CONSOLE_FONT_INFOEX tipografia = { 0 };

   tipografia.cbSize = sizeof(CONSOLE_FONT_INFOEX);
   tipografia.dwFontSize.Y = tamTipoLetra;
   tipografia.FontWeight = FW_NORMAL;
   tipografia.FontFamily = FF_DONTCARE;

   lib.cstring.wcscpy(tipografia.FaceName, nfuente);

   return SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &tipografia);
}

int leeArgumentos(int argc, _TCHAR** argv)
{
	int status = 0;  // no hay opciones

   if(argc > 1)
   {
     if(lib.cstring.strcmp(argv[1], "/a") == 0)
       status = 1;  // opción solicita ver una ayuda.
     else
       status = 99;  // argumento no reconocido.
   }

   return status;
}

int _tmain(int argc, _TCHAR** argv)
{
	int opcion = 0;
	const int CTRL_A = 0x01;
	const int CTRL_D = 0x04;
	const int CTRL_G = 0x07;
	const int CTRL_L = 0x0C;
	const int CTRL_O = 0x0F;
	const int CTRL_R = 0x12;
	MiniCom mc;
	_TCHAR entrada[272] = { _TEXT("") };

   *(lib.iostream.cout) << "mic: Mini Intérprete de Comandos 1.3" << endl;

   opcion = leeArgumentos(argc, argv);
   if(opcion == 1)
   {
     mc.ayuda();
     lib.C.puts("Para conocer más sobre 'mic.exe' lea la documentación que se encuentra en %base%\\biblioteca\\docu\\minicom.docu.txt");
     lib.C.puts("Para leer la documentación, estando en la consola 'cmd.exe', use el comando 'type' o el comando 'more'.");
     return 0;
   }

   if(opcion == 99)
   {
     *(lib.iostream.cout) << "Argumento no reconocido. Ingrese '/a' para leer una breve ayuda." << endl;
     return 0;
   }

   mc.informativo(false);
   mc.cmd("ver");  // Muestra la versión del intérprete de comandos vigente en el Sistema.
   mc.informativo(true);

   // Guarda el indicador de la línea de comandos
   mc.guardar_indicador(indicador_linea_comando.c_str());

   while(true)
   {
      mc.mostrar_indicador();
      lib.mem.memset(entrada, 0, 256);

      lib.iostream.cin->getline(entrada, 256);

	// 1º responde a los comandos internos

      if(*entrada == CTRL_A)
      {
	  mc.ampliar();
          continue;
      }

      if(*entrada == CTRL_G)
      {
	  lib.iostream.cout->put('\a');
	  continue;
      }

      if(*entrada == CTRL_L)
      {
	mc.borrar();
	continue;
      }

      if(*entrada == CTRL_D or lib.cstring.strcmp(entrada, "salir") == 0)
	mc.salir();

      if(*entrada == CTRL_R)
      {
	  mc.restaurar();
          continue;
      }

      if(*entrada == CTRL_O)
      {
	 mc.contraer();
	 continue;
      }

      if(lib.cstring.strcmp(entrada, "ayuda") == 0)
      {
	mc.ayuda();  
	// añadir comando 'ayuda docu' para mostrar minicom.docu.txt
	continue;
      }

      if(lib.cstring.strcmp(entrada, "lengua") == 0)
      {
          mc.lengua();
          continue;
      }

      string comando(entrada);
      int npos = comando.find("com");
      if(npos == 0)
      {
          mc.comando(entrada);
          continue;
      }

	// 2º responde a los comandos externos

      npos = comando.find("cmd");
      if(npos == 0)
      {
	  mc.cmd(&entrada[4]);
	  continue;
      }

      // Ignora la entrada de caracteres no visibles.
      if(*entrada < 32)
      {
	// ¿ Es CTRL+Z ?
	if(lib.iostream.cin->eof())
	{
	  lib.iostream.cin->clear();
	  break;  // sale del ciclo while()
	}

	continue;
      }

      *(lib.iostream.cout) << "Comando no reconocido: " << entrada << endl
                           << "Ingrese comando >> ayuda << para conocer los comandos de Minicom."
                           << endl;

   }  // fin while()

    *(lib.iostream.cout) << endl << "Finalizando..." << endl;
    return 0;
}
