// Proyecto: Ejemplo1.cbproj
// Módulo  : frmPrincipal.cpp
// Autor   : Octulio Biletán * Octubre de 2025.
// Descrip.: Implementar la clase 'TfrmCentral'. Es la ventana principal de la aplicación.
// Ambiente: Windows, modo gráfico, 64 bits.
// Licencia: Software libre.

//---------------------------------------------------------------------------
#include <vcl.h>
#include <strstream>
#pragma hdrstop

#include "frmPrincipal.h"
#include "hojaDeDibujo.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.dfm"

using namespace std;
TfrmCentral *frmCentral;

// Definida en Ejemplo1.cpp
extern int codigo_salida;
static bool condicion_salida;

//---------------------------------------------------------------------------
__fastcall TfrmCentral::TfrmCentral(TComponent* Owner) : TForm(Owner)
{
   rtfEdit->Font->Name = "Lucida Console";
   rtfEdit->Font->Size = 18;

   sbBarraEstado->Panels->Items[0]->Text = "Entorno de trabajo listo.";
   condicion_salida = false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCentral::FormClick(TObject *Sender)
{
   if(condicion_salida == true)
   {
     Application->Terminate();
     return;
   }
   
   // Despliega la hoja de dibujo en la pantalla principal
   miHojaDeDibujo();
}
//---------------------------------------------------------------------------
void __fastcall TfrmCentral::FormKeyPress(TObject *Sender, System::WideChar &Key)
{
   if(condicion_salida == true)
   {
     Application->Terminate();
     return;
   }

   if(Key > 0)
   {
     // Despliega la hoja de dibujo en la pantalla principal
     miHojaDeDibujo();
     Key = 0;
   }
}
//---------------------------------------------------------------------------
// Procede a visualizar en pantalla la hoja de dibujo y la tortuga.
// Se ejecuta una única vez esta función miembro.
void TfrmCentral::miHojaDeDibujo(void)
{
   lblAviso->Visible = false;

   // Ejecuta nuestro programa Logo y devuelve el código
   // que será entregado al S.O.
   int estado = HojaDeDibujo.visualizar(frmCentral, this);
   codigo_salida = estado;

   lblAviso->Left = 4;
   lblAviso->Top  = 704;
   lblAviso->Caption = "Presione una tecla cualquiera del teclado/ratón para salir.";
   lblAviso->Visible = true;

   sbBarraEstado->Panels->Items[0]->Text = "Estado: " + String(codigo_salida);
   sbBarraEstado->Panels->Items[2]->Text = "Terminado.";

   condicion_salida = true;  // autoriza la salida a la aplicación
}

char *TfrmCentral::versionEmbarcadero(void)
{
	ostrstream salida;

   salida << std::hex
	  << ((__CODEGEARC_VERSION__ & 0xFF000000) >> 24) << '.'
	  << ((__CODEGEARC_VERSION__ & 0x00FF0000) >> 16) << '.'
	  << std::dec
	  << ((__CODEGEARC_VERSION__ & 0x0000FFFF))
	  << ends;

   return salida.str();
}
void __fastcall TfrmCentral::opcSalirClick(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmCentral::opcAcercaDeClick(TObject *Sender)
{
	ostrstream salida;

   salida << "JLogo versión 1.0" << endl
	  << "Copyright (c) 2025 Eugenio Martínez." << endl
	  << "Fecha: " << __DATE__ << endl;

   salida << "Construído con Embarcadero C++ " << versionEmbarcadero()
	  << " for " << ((_WIN64) ? "Win64." : "Win32.") << ends;

   Application->MessageBox(String(salida.str()).c_str(), L"Acerca De...", MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------
