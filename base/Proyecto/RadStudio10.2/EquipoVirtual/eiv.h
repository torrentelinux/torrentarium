// Proyecto: eiv.cbproj
// Encabezamiento: eiv.h
// Autor: Octulio Bilet�n
// Prop�sito: exponer los principios b�sicos de virtualizaci�n, simulaci�n y emulaci�n para ense�ar en C++.
//            El sistema inform�tico propuesto puede estar funcionando como un todo local, remoto o h�brido.
//            La plataforma de desarrollo es en: Windows 64 bits.
// Versi�n: Setiembre de 2023.
// Obs.: El proyecto eiv.cbproj permanece abierto para su desarrollo permanente...

#include <string>

using namespace std;

// Gestiona la M.V. tanto local como remota
class MaquinaVirtual
{
   private:
	int cp_fijado() { return 850; }
	string fijado() { return "Metatron"; }

    	int MVencender(int status = 1);
	string conocer_nombre(string nombre);

   public:
	static const int apagar = 0;
	static const int encender = 1;
	static const int reiniciar = 2;
	static const int suspender = 3;
	static const int hibernar = 4;
	static const int _error = -1;

	MaquinaVirtual();
	~MaquinaVirtual();

	void pausa(int t);  // realiza una pausa durante 't' segundos
	int iniciar(int status);
	int condicion(const int status);  // condici�n de salida: apagar, encender, reiniciar, hibernar, suspender
	string pedir_nombre();
};

// Gestiona el S.O. tanto local como remoto
class SistemaOperativo
{
   private:
	int cp_fijado() { return 1250; }
	string fijado() { return "eoX"; }
	string so_completo() { return "entorno de objetos X"; }
	string so_ver() { return "1.9.23"; }
        string so_derechos() { return "Copyright (c)2023 Eugenio Mart�nez, todos los derechos reservados."; }

   public:
   	SistemaOperativo();
        ~SistemaOperativo();

        void pausa(int t);
        int iniciar(int status);
    	int encender(int status);
        string conocer_nombre(string nombre);
};

// Gestiona la apertura y cierre de sesi�n interactiva/remota entre el usuario y el sistema inform�tico
class Sesion
{
    public:
    	Sesion();
        ~Sesion();

        void pausa(int t);
        int iniciar(int status);
};

// Gestiona el int�rprete de comandos local/remoto
class Comando
{
   public:
   	Comando();
        ~Comando();

        int iniciar(int status);
        int ejecutar(int status);
	void pausa(int t);
	void cmdBP(void);
        string comandos();
	string cmdAyuda() {return "ayuda"; }
	string cmdApagar() { return "apagar"; }
	string cmdBorrarPantalla() { return "borrar"; }
        string cmdCerrar() { return "cerrar"; }
};
