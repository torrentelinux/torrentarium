// LEETECLA.CPP
// Eugenio Mart¡nez
// Lectura del teclado. Muestra los c¢digos de cada tecla presionada.
// Uso de la funci¢n getch() de la biblioteca de funciones conio.h
// que corresponde al compilador Embarcadero C++ Builder/RAD Studio.
// 1§ versi¢n: Abril de 1997.
// Ultima versi¢n actualizada: Febrero de 2022.
// __________________________________________________________________

#include <iostream.h>
#include <conio.h>
#include <windows.h>

/* Ciclo do...until
   Usar: do
	 {
	   cuerpo;
	 } until(cond);
*/
#define until(cond) while(!(cond))

using namespace std;

// Clase para la gesti¢n de la ventana de textos en Windows.
// Se apoya en las funciones de conio.h
class ConsoleWindow
{
   private:
	UINT cp_entrada;
	UINT cp_salida;
	DWORD codigo_error;
	BOOL status;
	bool traducir_codigo;
	bool statusVText;

   public:
	// Definici¢n de c¢digos de teclas que
	// ser n le¡das mediante getkey().
	enum Teclado {
			NADA   =  0,
			BS     =  8,
			TAB    =  9,
			ENTER  = 13,
			ESC    = 27,
			ESPACIO= 32,
			F1     =315, F2, F3, F4, F5, F6, F7, F8, F9, F10,
			F11    =389, F12,
			HOME   =327, F_ARRIBA, PGUP,
			F_IZQ  =331,
			F_DER  =333,
			END    =335, F_ABAJO, PGDN, INS, DEL,
			ALT_F5 =364
		     };

	static const bool on = true;
	static const bool off = false;
	Teclado cwTecla;

	ConsoleWindow()
	{
	   cp_entrada = 0;
	   cp_salida = 0;
	   codigo_error = 0;
	   status = 0;
	   traducir_codigo = false;
	   cwTecla = NADA;

	   statusVText = true;  // La ventana de textos est  operativa.
	}

	~ConsoleWindow()
	{
	   statusVText = false;  // La ventana de textos est  inoperable.
	}

	// Establecer la condici¢n de la traducci¢n de c¢digo de teclado
	// on: activada; off: desactivada
	void setConditionKBDCode(const bool state)
	{
	   if(statusVText == false)
	     return;

	    traducir_codigo = state;
	}

	// Obtener la condici¢n de la traducci¢n de c¢digo de teclado
	// true: activada; false: desactivada
	bool getConditionKBDCode(void)
	{
	   if(statusVText == false)
	     return statusVText;

	    return traducir_codigo;
	}

	// Devuelve el c¢digo de error
	DWORD error(void)
	{
	   if(statusVText == false)
	     return 0;

	   return codigo_error;
	}

	// Establece el c¢digo de p gina indicado en 'cpID'
	// para la E/S de datos.
	// En caso de ‚xito guarda un 0 sino un valor mayor a 0.
	void setio_cpmode(UINT cpID)
	{
	   if(statusVText == false)
	     return;

	   SetLastError(0);

	   status = SetConsoleCP(cpID);
	   if(status != 0)
           {
	     status = SetConsoleOutputCP(cpID);
	     if(status != 0)
             {
	       codigo_error = 0;
               return;
             }
	   }

	   codigo_error = GetLastError();
	}

	void saveio_cpmode(void)
	{
	   if(statusVText == false)
	     return;

	   SetLastError(0);

	   cp_entrada = GetConsoleCP();
	   cp_salida  = GetConsoleOutputCP();

	   codigo_error = GetLastError();
	}

	void restoreio_cpmode(void)
	{
	   if(statusVText == false)
	     return;

	   SetLastError(0);

	   status = SetConsoleOutputCP(cp_salida);
	   if(status != 0)
	     status = SetConsoleCP(cp_entrada);

	   codigo_error = GetLastError();
	}

	// Lee el teclado y devuelve su c¢digo, intercepta las teclas extendidas.
        // Captura las combinaciones de teclas Ctrl+<tecla>, Alt+<tecla>, AltGr+<tecla> y Ctrl+Alt+<tecla>
	// Similar a getch() de conio.h
	int getKey(void)
	{
		register unsigned char codigo_extendido = 0;
		int tecla = 0;

	   if(statusVText == false)
	     return 0;

	   SetLastError(0);

	   do
	   {
	     codigo_extendido = ~codigo_extendido;	// convierte 0 -> 1 y 1 -> 0
	     tecla = ::getch();				// declarada en conio.h

	   } until(tecla != NADA);

	   if(codigo_extendido == 0)
	   {
	     if(traducir_codigo == true)
	     {
	       if(GetConsoleCP() == GetOEMCP())
	       {
		 switch(tecla)
		 {
		   // Obtiene las vocales acentuadas mediante una traducci¢n de c¢digo
		   // Modo OEM CP
		   case 20:  tecla = 160;  //    AltGr + t
			     break;

		   case 21:  tecla = 130;  // ‚  AltGr + y
			     break;

		   case 22:  tecla = 163;  // £  AltGr + u
			     break;

		   case 23:  tecla = 161;  // ¡  AltGr + i
			     break;

		   case 24:  tecla = 162;  // ¢  AltGr + o
			     break;

		   default:  tecla += 256;
		 }  // fin de switch()
	       }
	       else
		 if(GetConsoleCP() == GetACP())
		 {
		   switch(tecla)
		   {
		     // Obtiene las vocales acentuadas mediante una traducci¢n de c¢digo
		     // Modo Ansi CP
		     case 20:  tecla = 225;  // á AltGr + t
			       break;

		     case 21:  tecla = 233;  // é AltGr + y
			       break;

		     case 22:  tecla = 250;  // ú AltGr + u
			       break;

		     case 23:  tecla = 237;  // í AltGr + i
			       break;

		     case 24:  tecla = 243;  // ó AltGr + o
			       break;

		     default:  tecla += 256;
		   }  // fin de switch()
		 }
		 else
		   tecla += 256;  // traducci¢n sencilla

	     }  // fin de traducci¢n de c¢digo
	     else
	       tecla += 256;
	   }  // fin de c¢digo extendido

	   return tecla;
	}

	// Limpia la ventana de textos
	void clearScreen(void)
	{
	   // No hace nada si la ventana de textos est  inoperable.
	   if(statusVText == false)
	     return;

	   ::clrscr();
	}
};

main()
{
	int codigo = 0;
	DWORD estado = 0;
	ConsoleWindow vtext;

   vtext.clearScreen();
   vtext.saveio_cpmode();

   vtext.setio_cpmode(GetOEMCP());
   estado = vtext.error();
   if(estado != 0)
   {
     cerr << "C¢digo de error: " << estado << endl;
     ::MessageBox(NULL, "Terminando aplicación.", "Error", MB_OK | MB_ICONEXCLAMATION);
     return 1;
   }

   vtext.setConditionKBDCode(ConsoleWindow::on);

   cout << "Ansi CP=" << GetACP()
	<< " | OEM CP=" << GetOEMCP()
	<< " | CP Activo E/S=" << GetConsoleCP() << "/" << GetConsoleOutputCP()
	<< " | Remapeo de teclas=" << vtext.getConditionKBDCode()
	<< endl;
   cout << "_________________________________________________________________________" << endl;

   cout << "Muestra el c¢digo de tecla pulsada." << endl
	<< "Para terminar presione la tecla F12" << endl;

   do
   {
     codigo = vtext.getKey();

     cout << "C¢digo de tecla pulsada: " << (unsigned int)codigo
	  << " [" << (char)codigo << "]" << endl;
   } until(codigo == vtext.F12);

   vtext.setConditionKBDCode(ConsoleWindow::off);
   cout << "\nTerminado." << endl;
   getch();

   vtext.restoreio_cpmode();
   return 0;
}
