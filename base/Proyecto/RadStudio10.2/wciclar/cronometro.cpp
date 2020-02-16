//---------------------------------------------------------------------------
// Módulo        : cronometro.cpp
// Autor         : eugenio martínez - octubre de 2006
// Descripción   : define la clase Cronometro
//                 optimizado para CPU Intel Pentium, aplicación para Windows
// Licencia      : Copyright (C) 2006-2020 - Eugenio Martinez - torrentelinux@netscape.net
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

#include "cronometro.h"

Cronometro::Cronometro()
{
   memset(&instante[0], 0, sizeof(instante));

   // consulta la tasa de ciclos del microprocesador
   if(!QueryPerformanceFrequency(&frecuencia_reloj))
     memset(&frecuencia_reloj, 0, sizeof(frecuencia_reloj));
}

Cronometro::~Cronometro()
{

}

void Cronometro::iniciar()
{
   QueryPerformanceCounter(&instante[0]);
}

void Cronometro::detener()
{
   QueryPerformanceCounter(&instante[1]);
}

LONGLONG Cronometro::lapso_transcurrido()
{
   return (instante[1].QuadPart - instante[0].QuadPart);
}

// Obtiene la frecuencia del reloj del sistema operativo
LONGLONG Cronometro::frecuencia()
{
   return frecuencia_reloj.QuadPart;
}
