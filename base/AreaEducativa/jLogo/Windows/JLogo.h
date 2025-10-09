// Proyecto: Ejemplo1
// Encabez.: JLogo.h
// Librería: JLogo.cpp
// Versión : 1.0
// Depende.: Embarcadero Studio/VCL ver. 22.0, Alexandria, 64 bits.
// Autor   : Octulio Biletán * Octubre de 2025.
// Descrip.: Declarar la clase JLogo.
// Ambiente: Windows modo gráfico, 64 bits.
// Licencia: Software libre.

#ifndef jlogo_JLogo
#  define jlogo_JLogo

#  include <vcl.h>
#  include <tchar.h>

#  include "frmPrincipal.h"

#  define MAX_LINEAS	80
#  define MAX_COLS	1024

class JLogo
{
   private:
	bool error_ptr;         // Indicador de error en punteros.
	bool jlogo_operable;    // True: está operativo; False: está inoperativo.

	int columnas;   // eje Y
	int lineas;     // eje X
	int col_actual;
	int linea_actual;

	String direccion;		// norte, sur, este, oeste
	String tortuga_version;
	String tortuga_fproduc;
	String tortuga_copyright;
	wchar_t tortuga_traza;
	wchar_t tortuga_figura;
	wchar_t piso_figura;
	wchar_t _pantalla[MAX_LINEAS][MAX_COLS];  // aquí se efectúa el dibujo de la tortuga

	TLabel *linea;
	Vcl::Controls::TWinControl *frmBase;
	TfrmCentral *apli;

   public:
	JLogo(TfrmCentral *frm, Vcl::Controls::TWinControl *AOwner);
	JLogo();
	~JLogo();

//	void borrapantalla();
	void iniciar(TfrmCentral *frm, Vcl::Controls::TWinControl *AOwner);
        void terminar(void);
	int mostrar(void);
	int producto(void);
	int avance(int pasos);
	void centropantalla(void);
	void detente(int lapso);
	void limpiar(void);
	void subir(void);
	void bajar(void);
	void izquierda(void);
	void derecha(void);
};

#endif
