// Encabezamiento: minicomClase.h
// Autor         : Eugenio Martínez
// Propósito     : Declarar la clase MiniCom.
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

#include <string>

using namespace std;

class MiniCom
{
   private:
	bool es_informativo;
	string comspec;

   public:
	MiniCom();
	~MiniCom();

	// Informa qué lengua local está usando minicom.
	void lengua(void);

	// Activa/desactiva mensajes informátivos en pantalla.
	void informativo(bool dato);

	// Muestra una ayuda breve sobre los comandos admitidos.
	void ayuda(void);

	// Sale del programa minicom.
	void salir(void);

	// Ejecuta comandos externos a minicom.
	void cmd(char *cmd);

	// Muestra en pantalla el indicador de petición de comandos.
	void indicador(const char *ipc);

	// Borra la pantalla
	void borrar(void);

	// Amplía la ventana de minicom
	void ampliar(void);

	// Minimiza la ventana consola
	void contraer(void);

	// Restaura la ventana de minicom
	void restaurar(void);
};
