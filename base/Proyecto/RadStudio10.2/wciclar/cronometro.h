//---------------------------------------------------------------------------
// Encabezamiento: cronometro.h
// Autor         : eugenio martínez - octubre de 2006
// Descripción   : declara la clase Cronometro
//                 optimizado para CPU Intel Pentium, aplicación para Windows
// Licencia      : Copyright (C) 2006-2020 - Eugenio Martinez - torrentelinux@gmail.com
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//---------------------------------------------------------------------------

#ifndef _Cronometro_
#  define _Cronometro_

#  define STRICT
#  include <windows.h>

class Cronometro
{
   private:
	LARGE_INTEGER frecuencia_reloj;
   	LARGE_INTEGER instante[2];

   public:
   	Cronometro();
        ~Cronometro();

        void iniciar();
        void detener();
        LONGLONG lapso_transcurrido();

	// Obtiene la frecuencia del reloj del sistema operativo
        LONGLONG frecuencia();
};
#endif
