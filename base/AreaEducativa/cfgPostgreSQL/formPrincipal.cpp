//---------------------------------------------------------------------------
// formPrincipal.cpp
// Octulio Biletán * Mayo de 2023
// Modelo Educativo de aplicación para Windows.
// Lee fichero postgresql.conf y muestra sus opciones en un formulario.
// Compilador C++ utilizado en Windows: Embarcadero C++ Builder 10.2.


#include <vcl.h>
#pragma hdrstop

#include "formPrincipal.h"
#include "ConfigFile.h"

// Funciones de cfgPG.dll
__declspec(dllimport) String ayudaGeneral(void);

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmPrincipal *frmPrincipal;
//---------------------------------------------------------------------------
__fastcall TfrmPrincipal::TfrmPrincipal(TComponent* Owner)
	: TForm(Owner)
{
   PageControlPrincipal->ActivePage = Hoja1;
   dlgAbrirConfig->FileName = "";
   dlgAbrirConfig->InitialDir = "%USERPROFILE%";
   dlgAbrirConfig->Filter = "Fichero config (*.conf)|*.CONF|Todos (*.*)|*.*";
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::btnCerrarClick(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::btnSeleccionar1Click(TObject *Sender)
{
   dlgAbrirConfig->Title = "Abrir postgresql.conf";

   if(dlgAbrirConfig->Execute())
   {
     stbEstado->SimpleText = "Fichero seleccionado correctamente.";
     edtLinea1->Text = dlgAbrirConfig->FileName;

     //------------------------------------------------------------
     // Lee las opciones del fichero 'postgresql.conf'
     // y los visualiza en la pestaña 'General'
     opcionesGeneral();
     //------------------------------------------------------------
   }
   else
     stbEstado->SimpleText = "Operación cancelada.";
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::btnSeleccionar2Click(TObject *Sender)
{
   dlgAbrirConfig->Title = "Abrir pg_hba.conf";

   if(dlgAbrirConfig->Execute())
   {
     stbEstado->SimpleText = "Fichero seleccionado correctamente.";
     edtLinea2->Text = dlgAbrirConfig->FileName;
   }
   else
     stbEstado->SimpleText = "Operación cancelada.";
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::opcionesGeneral(void)
{
	int npos;
	String lineaActual;
	String dato;

     TConfigFile *postgres = new TConfigFile(edtLinea1->Text);
     dato = postgres->ReadString("listen_addresses");
     lineaActual = "listen_addresses: ";

     if(dato.IsEmpty())
       lineaActual += "Dato no leído.";
     else
     {
       lineaActual += "Dato leído.";
       edtListenAddr->Text = dato;
     }
     mmMensajes->Lines->Append(lineaActual);

     dato = postgres->ReadString("port");
     lineaActual = "port: ";
     if(dato.IsEmpty())
       lineaActual += "Dato no leído.";
     else
     {
       lineaActual += "Dato leído.";
       edtPort->Text = dato;
     }
     mmMensajes->Lines->Append(lineaActual);

     dato = postgres->ReadString("max_connections");
     lineaActual = "max_connections: ";
     if(dato.IsEmpty())
       lineaActual += "Dato no leído.";
     else
     {
       lineaActual += "Dato leído.";
       edtMaxConn->Text = dato;
     }
     mmMensajes->Lines->Append(lineaActual);

     dato = postgres->ReadString("shared_buffers");
     lineaActual = "shared_buffers: ";
     if(dato.IsEmpty())
       lineaActual += "Dato no leído.";
     else
     {
       lineaActual += "Dato leído.";
       edtShareBuff->Text = dato;
     }
     mmMensajes->Lines->Append(lineaActual);
}
void __fastcall TfrmPrincipal::btnAyudaClick(TObject *Sender)
{
   if(PageControlPrincipal->ActivePageIndex == 0)
     ShowMessage(ayudaGeneral());

}
//---------------------------------------------------------------------------

