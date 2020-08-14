// Encabezamiento: minicomClase.h
// Autor         : Eugenio Mart�nez
// Prop�sito     : Declarar la clase MiniCom.

#include <string>

using namespace std;

class MiniCom
{
   private:
   	string comspec;

   public:
	MiniCom();
	~MiniCom();

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

	// Restaura la ventana de minicom
	void restaurar(void);
};

