// Encabezamiento: minicomClase.h
// Autor         : Eugenio Mart�nez
// Prop�sito     : Declarar la clase MiniCom.
// Licencia : Copyright (C) 2020-2021 - Eugenio Mart�nez - torrentelinux@gmail.com
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
#include <sstream>
#include <fstream>

using namespace std;

class MiniCom
{
   private:
	bool es_informativo;
	string comspec;
        string var_base;
        ostringstream ncf_shells;  // Nombre completo de fichero shells
        ifstream if_shells;  //  Fichero de lectura 'shells'

	void listar_shells(void);
        void borrar_shell(void);
	void guardarEstado(void);
        void recuperarEstado(void);

        void cambiar_shell(string npos);
	_TCHAR *dir_vigente(void);
        BOOL titular(const _TCHAR *ti);

   public:
	MiniCom();
	~MiniCom();

        // Configura b�sicamente el int�rprete de comandos a invocar.
        void comando(_TCHAR *secuencia_comando);

	// Informa qu� lengua local est� usando minicom.
	void lengua(void);

	// Activa/desactiva mensajes inform�tivos en pantalla.
	void informativo(bool dato);

	// Muestra una ayuda breve sobre los comandos admitidos.
	void ayuda(void);

	// Sale del programa minicom.
	void salir(void);

	// Ejecuta comandos externos a minicom.
	void cmd(char *cmd);

	// Muestra en pantalla el indicador de petici�n de comandos.
	void indicador(const char *ipc);

	// Borra la pantalla
	void borrar(void);

	// Ampl�a la ventana de minicom
	void ampliar(void);

	// Minimiza la ventana consola
	void contraer(void);

	// Restaura la ventana de minicom
	void restaurar(void);
};
