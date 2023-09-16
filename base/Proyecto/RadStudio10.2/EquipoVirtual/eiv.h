// eiv.h

#include <string>

using namespace std;

class MaquinaVirtual
{
   private:
	string fijado() { return "Metatron"; }
	int cp_fijado() { return 850; }
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
	string pedir_nombre();
	int condicion(const int status);  // condición de salida: apagar, encender, reiniciar, hibernar, suspender
};

class SistemaOperativo
{
   private:
	string fijado() { return "eoX"; }
	string so_completo() { return "entorno de objetos X"; }
	string so_ver() { return "1.9.23"; }
        string so_derechos() { return "Copyright (c)2023 Eugenio Martínez, todos los derechos reservados."; }
	int cp_fijado() { return 1250; }

   public:
   	SistemaOperativo();
        ~SistemaOperativo();

        void pausa(int t);
    	int encender(int status);
        int iniciar(int status);
        string conocer_nombre(string nombre);
};

class Sesion
{
    public:
    	Sesion();
        ~Sesion();

        void pausa(int t);
        int iniciar(int status);
};

class Comando
{
   public:
   	Comando();
        ~Comando();

        int iniciar(int status);
        int ejecutar(int status);
        string comandos();
	string cmdAyuda() {return "ayuda"; }
	string cmdApagar() { return "apagar"; }
        string cmdCerrar() {return "cerrar"; }
	string cmdBorrarPantalla() { return "borrar"; }
	void cmdBP(void);
	void pausa(int t);
};
