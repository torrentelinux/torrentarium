//------------------------------------------------------------------------------
/* Agenda Personal * SQL						       */
// Leer docu/AgendaPersonalSQL.txt para más información acerca de este proyecto
//------------------------------------------------------------------------------
// Añadir...
// SELECT * FROM "pg_config" WHERE ("name" = 'VERSION')
//

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
   constY = mmMensajes->Height;

   // En el comienzo... SQL está desconectado.
   conectado = false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::FormClick(TObject *Sender)
{
   sbMensajes->SimpleText = "";
   mmMensajes->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::FormCreate(TObject *Sender)
{
	bool status;

   ModuloDatos = new TModuloDatos(this);

   // Dimensiones iniciales de la ventana principal
   Left   = 8;
   Top    = 8;
   Width  = 460;
   Height = 360;
   // ----------------------\/---------------------

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
   // Ubica la caja de mensajes al pie de la ventana principal
   mmMensajes->Left = 8;  // eje X
   mmMensajes->Top  = (Height - 64) - constY;  // eje Y

   // Ajusta los anchos de la caja de mensajes y la grilla de celdas
   mmMensajes->Width = Width - 32;
   DBAgenda->Width   = Width - 32;
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
void __fastcall TfrmPrincipal::tbtnGrillaClick(TObject *Sender)
{
   if(DBAgenda->Visible)
   {
     DBAgenda->Visible    = false;
     DBNavegador->Visible = false;
     SpinButton1->Visible = false;
     sbtnGrilla->Visible  = false;

     sbMensajes->SimpleText = "Planilla oculta.";
     mmMensajes->SetFocus();
   }
   else
   {
     DBAgenda->Visible    = true;
     DBNavegador->Visible = true;
     SpinButton1->Visible = true;
     sbtnGrilla->Visible  = true;

     sbMensajes->SimpleText = "Planilla visible.";
     DBAgenda->SetFocus();
   }
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::tbtnEditarClick(TObject *Sender)
{
     // Deshabilitado
     //ModuloDatos->FDConnection1->ConnectionString = L"DriverID=PG;Port=5432;Server=localhost;Database=agenda;User_Name=postgres";
   /*ModuloDatos->FDConnection1->Params->Strings[1] = "";
   ModuloDatos->FDConnection1->Params->Strings[2] = "";
   ModuloDatos->FDConnection1->Params->Strings[3] = "";
   ModuloDatos->FDConnection1->Params->Strings[4] = "";
   ModuloDatos->FDConnection1->Params->Strings[5] = "";*/

   ModuloDatos->FDConnection1->Params->Clear();
   ModuloDatos->FDConnection1->DriverName = "PG";
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
void __fastcall TfrmPrincipal::DBNavegadorClick(TObject *Sender, TNavigateBtn Button)
{
   if(Button == nbApplyUpdates)
   {
     mmMensajes->Lines->Append(tiempoActual());
     mmMensajes->Lines->Append("Actualización ejecutada. ");
   }
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::SpinButton1UpClick(TObject *Sender)
{
   if(DBAgenda->Height == 64)
   {
     sbMensajes->SimpleText = "Se alcanzó el tope superior.";
     return;
   }

   DBAgenda->Height -= 4;
   sbMensajes->SimpleText = "Reduciendo tamaño...";
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::SpinButton1DownClick(TObject *Sender)
{
   int Y = DBAgenda->Top + DBAgenda->Height;

   if(Y == mmMensajes->Top)
   {
     sbMensajes->SimpleText = "Se alcanzó el tope inferior.";
     return;
   }

   DBAgenda->Height += 4;
   sbMensajes->SimpleText = "Aumentando tamaño...";
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::sbtnGrillaClick(TObject *Sender)
{
   if(DBAgenda->Visible)
   {
     DBAgenda->Visible    = false;
     sbtnGrilla->Caption = L"□";
     sbtnGrilla->Hint = L"Mostrar planilla.";

     sbMensajes->SimpleText = L"Planilla oculta.";
     mmMensajes->SetFocus();
   }
   else
   {
     DBAgenda->Visible    = true;
     sbtnGrilla->Caption = L"X";
     sbtnGrilla->Hint = L"Ocultar planilla";

     sbMensajes->SimpleText = "Planilla visible.";
     DBAgenda->SetFocus();
   }
}
//---------------------------------------------------------------------------
bool TfrmPrincipal::conectarSQL(void)
{
	bool status = false;  // false: desconectado

   try
   {
     ModuloDatos->FDVCLLoginDialog1->Caption = "Inicio de sesión";
     ModuloDatos->FDConnection1->Connected = true;
     DBAgenda->DataSource->DataSet->Active = true;

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
     DBAgenda->DataSource->DataSet->Active = false;

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
//---------------------------------------------------------------------------

