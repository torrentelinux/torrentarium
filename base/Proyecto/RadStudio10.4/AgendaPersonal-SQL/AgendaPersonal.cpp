//------------------------------------------------------------------------------
/* Agenda Personal * SQL						      */
// Leer docu/AgendaPersonalSQL.txt para más información acerca de este proyecto
//------------------------------------------------------------------------------

#include <vcl.h>
#include <fstream>
#pragma hdrstop

#include "AgendaPersonal.h"
#include "ModuloSQL.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.dfm"

using namespace std;
TfrmPrincipal *frmPrincipal;
//---------------------------------------------------------------------------
__fastcall TfrmPrincipal::TfrmPrincipal(TComponent* Owner) : TForm(Owner)
{
   // 1ro. el constructor luego el evento crear form...
   constY = mmMensajes->Top - 4;

   // En el comienzo... SQL está desconectado.
   conectado = false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::FormCreate(TObject *Sender)
{
	bool status;

   ModuloDatos = new TModuloDatos(this);

   Left   = 8;
   Top    = 8;
   Width  = 460;
   Height = 360;

   status = conectarSQL();
   if(status)
   {
     sbMensajes->SimpleText = "Conexión exitosa.";
   }
   else
   {
     sbMensajes->SimpleText = "No se pudo establecer conexión al servidor SQL.";
   }

   WindowState = wsMaximized;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::FormResize(TObject *Sender)
{
   mmMensajes->Top = (Height / 2) + (mmMensajes->Height / 2) + constY;
   mmMensajes->Left = 8;

   mmMensajes->Width = Width - 32;
   DBGrid1->Width = Width - 32;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::tbtnConectarClick(TObject *Sender)
{
	bool status;

   if(estadoSQL() == true)
   {
     sbMensajes->SimpleText = "Ya se encuentra establecida la conexión al servidor SQL.";
     return;
   }

   status = conectarSQL();
   if(status)
     sbMensajes->SimpleText = "Conexión exitosa al servidor SQL.";
   else
     sbMensajes->SimpleText = "No se pudo establecer conexión al servidor SQL.";
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::tbtnDesconectarClick(TObject *Sender)
{
	bool status;

   if(estadoSQL() == false)
   {
     sbMensajes->SimpleText = "Ya se encuentra desconectado del servidor SQL.";
     return;
   }

   status = desconectarSQL();
   if(status)
     sbMensajes->SimpleText = "Desconexión exitosa.";
   else
     sbMensajes->SimpleText = "No se pudo desconectar del servidor SQL.";
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::tbtnSalirClick(TObject *Sender)
{
   sbMensajes->SimpleText = "Saliendo de la aplicación...";
   ModuloDatos->FDConnection1->Close();

   mmMensajes->Lines->Append(tiempoActual());
   mmMensajes->Lines->Append(sbMensajes->SimpleText);

   guardarRegistroActividades();

   Sleep(3000);
   Close();
}
//---------------------------------------------------------------------------
bool TfrmPrincipal::conectarSQL(void)
{
	bool status = false;  // false: desconectado

   try
   {
     ModuloDatos->FDVCLLoginDialog1->Caption = "Inicio de sesión";
     ModuloDatos->FDConnection1->Connected = true;
     DBGrid1->DataSource->DataSet->Active = true;

     mmMensajes->Lines->Append(tiempoActual());
     mmMensajes->Lines->Append("Aviso: Conexión establecida al servidor SQL.");

     status = true;
   }
   catch(EFDException &sqlError)
   {
     mmMensajes->Lines->Append(tiempoActual());

     mmMensajes->Lines->Append("Error de conexión.");
     mmMensajes->Lines->Append(sqlError.Message);
   }

   conectado = status;
   return status;
}
//---------------------------------------------------------------------------
bool TfrmPrincipal::desconectarSQL(void)
{
	bool status = true;  // true: conectado

   try
   {
     ModuloDatos->FDVCLLoginDialog1->Caption = "Inicio de sesión";
     ModuloDatos->FDConnection1->Connected = false;
     DBGrid1->DataSource->DataSet->Active = false;

     mmMensajes->Lines->Append(tiempoActual());
     mmMensajes->Lines->Append("Aviso: Desconexión completada al servidor SQL.");

     status = false;
   }
   catch(EFDException &sqlError)
   {
     mmMensajes->Lines->Append(tiempoActual());

     mmMensajes->Lines->Append("Error de desconexión.");
     mmMensajes->Lines->Append(sqlError.Message);
   }

   conectado = status;
   return status;
}
//---------------------------------------------------------------------------
String TfrmPrincipal::tiempoActual(void)
{
	SYSTEMTIME tl;
	String tiempo;

    GetLocalTime(&tl);
    tiempo.sprintf(L"Tiempo local: %d,%d,%d<>%02d:%02d:%02d", tl.wDay, tl.wMonth, tl.wYear, tl.wHour, tl.wMinute, tl.wSecond);
    return tiempo;
}

void TfrmPrincipal::guardarRegistroActividades(void)
{
	wofstream salida;

   salida.open(L"salida.txt", wofstream::app);

   for(int i = 0; i < mmMensajes->Lines->Count; i++)
     salida << mmMensajes->Lines->Strings[i] << endl;

   salida << "_____________________________________________________________" << endl;
   salida.close();
}
//---------------------------------------------------------------------------
// Devuelve el estado de conexión a SQL: true=conectado/false=desconectado
bool TfrmPrincipal::estadoSQL(void)
{
   return conectado;
}

