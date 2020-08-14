// Programa : minicom.cpp
// Autor    : Eugenio Martínez
// Propósito: Definir un mini intérprete de comandos
//            para sistemas Windows.
// Licencia : Copyright (C) 2020 - Eugenio Martínez - torrentelinux@gmail.com
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

#include "LadrilloModular.h"
#include "minicomClase.h"

LadrilloConCalce lib;

int main(int argc, char** argv)
{
	MiniCom mc;
	const int CTRL_A = 0x01;
	const int CTRL_D = 0x04;
	const int CTRL_G = 0x07;
	const int CTRL_L = 0x0C;
        const int CTRL_R = 0x12;
	char entrada[272] = { "" };

    *(lib.iostream.cout) << "Minicom 1.0" << endl;

    while(true)
    {
      mc.indicador("¯ ");
      lib.mem.memset(entrada, 0, 256);

      lib.iostream.cin->getline(entrada, 256);

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

      if(lib.cstring.strcmp(entrada, "ayuda") == 0)
      {
	mc.ayuda();
	continue;
      }

      string comando(entrada);
      int npos = comando.find("cmd");

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

      *(lib.iostream.cout) << "Comando no reconocido: " << entrada << endl;
    }  // fin while()

    *(lib.iostream.cout) << endl << "Finalizando..." << endl;
    return 0;
}

