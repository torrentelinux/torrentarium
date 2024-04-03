//---------------------------------------------------------------------------
// Proyecto : SQLite_Ejemplo.cbproj
// Módulo   : mdlGestorDatos.cpp
// Autor    : Octulio Biletán * Marzo de 2024
// Propósito: Realizar una consulta a la base de datos 'ejemploSQLite.sdb'
// Obs.     : El lenguaje de consulta utilizado es SQLite v3.
//---------------------------------------------------------------------------
#include <vcl.h>

#include "mdlGestorDatos.h"
#include "mdlControles.h"
#include "mdlPanelInfo.h"
#include "mdlFuncs.h"

#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmGestorDatos *frmGestorDatos;
//---------------------------------------------------------------------------
__fastcall TfrmGestorDatos::TfrmGestorDatos(TComponent* Owner) : TForm(Owner)
{
   if(frmControl == NULL)
   {
     try
     {
       frmControl = new TfrmControl(this);
     }
     catch(Exception &exception)
     {
       Application->ShowException(&exception);
     }
   }

   Application->ShowHint = true;

   // Otras herramientas: sqlite3.exe
   progSQL = "\"C:\\Program Files\\DB Browser for SQLite\\DB Browser for SQLite.exe\"";

   bddSQL = "ejemploSQLite.sdb";
}
//---------------------------------------------------------------------------
// Cierra la aplicación
void __fastcall TfrmGestorDatos::FormClose(TObject *Sender, TCloseAction &Action)
{
   Desconectar1Click(Sender);
   Sleep(750);
}
//---------------------------------------------------------------------------
// Elimina todo de la memoria antes de salir de la aplicación
void __fastcall TfrmGestorDatos::FormDestroy(TObject *Sender)
{
   Release();
}
//---------------------------------------------------------------------------
// Conecta a la base de datos
void __fastcall TfrmGestorDatos::conectarBotonClick(TObject *Sender)
{
	String baseDatos;

   if(bddSQL.IsEmpty() == true)
   {
       Application->NormalizeTopMosts();
       Application->MessageBox(L"Importante: Primero debe seleccionar una base de datos válida.", L"SQLITE *** AVISO", MB_OK|MB_ICONINFORMATION);
       Application->RestoreTopMosts();
       return;
   }

   // Prepara la cadena de conexión
   baseDatos = "Database=" + bddSQL;

   // Envía la cadena de conexión al control SQLConexion
   frmControl->SQLConexion->Params->Add(baseDatos);

   try
   {
       // Abre la base de datos.
       frmControl->SQLConexion->Open();

       ejecutarBoton->Enabled = true;
       salidaMemo->Lines->Append("Conexión establecida:" + bddSQL);
       salidaMemo->Lines->Append("_____________________");

       conectarBoton->Enabled = false;
   }
   catch(EDatabaseError &e)
   {
       salidaMemo->Text = "Excepción: " + e.Message;
       ShowMessage("Excepción: " + e.Message);
   }
   catch(TDBXError &excepcion)
   {
       if(excepcion.ErrorCode == 14)
       {
	 salidaMemo->Lines->Append("[X] Error: No se pudo abrir la base de datos: " + bddSQL);
	 salidaMemo->Lines->Append(excepcion.Message);
       }
       else
       {
	 salidaMemo->Lines->Append("[X] Falló: " + IntToStr(excepcion.ErrorCode));
	 salidaMemo->Lines->Append(excepcion.Message);
       }

       salidaMemo->Lines->Append("_____________________");
   }
}
//---------------------------------------------------------------------------
// Ejecuta la consulta sobre la 1ra. tabla de la base de datos
void __fastcall TfrmGestorDatos::ejecutarBotonClick(TObject *Sender)
{
	String query;
	TStringList *nombreTablas;

   if(frmControl->SQLConexion->ConnectionState == csStateClosed)
   {
     salidaMemo->Lines->Append("[X] Base de datos desconectada.");
     salidaMemo->Lines->Append("_____________________");
     return;
   }

   salidaMemo->Lines->Append("·····················");

   try
   {
     nombreTablas = new TStringList;
     frmControl->SQLConexion->GetTableNames(nombreTablas);

     // Consulta sobre la 1ra. tabla encontrada
     query = "SELECT * FROM " + nombreTablas->Strings[0] + ";";
   }
   catch(TDBXError &excepcion)
   {
     if(excepcion.ErrorCode == 26)
     {
       salidaMemo->Lines->Append("[X] La base de datos contiene datos incorrectos.");
       salidaMemo->Lines->Append(excepcion.Message);
     }
     else
     {
       salidaMemo->Lines->Append("[X] Falló: " + IntToStr(excepcion.ErrorCode));
       salidaMemo->Lines->Append(excepcion.Message);
     }

     salidaMemo->Lines->Append("_____________________");
     nombreTablas->Free();

     return;
   }

   try
   {
     // Assign the query to the object SQLConsulta.
     frmControl->SQLConsulta->SQL->Text = query;
     frmControl->SQLConsulta->Active = true;
   }
   catch(Exception &e)
   {
     salidaMemo->Text = "Excepción consulta: " + e.Message;
   }

   // Show the results of the query in a TMemo control.
   ShowSelectResults();
   salidaMemo->Lines->Append("_____________________");

   nombreTablas->Free();
}
//---------------------------------------------------------------------------
// Visualiza los resultados de hacer un 'select' sobre una tabla de datos
void __fastcall TfrmGestorDatos::ShowSelectResults()
{
	String currentLine;
	TStringList *names;
	TField *currentField;

   if(!frmControl->SQLConsulta->IsEmpty())
   {
       frmControl->SQLConsulta->First();
       names = new TStringList;

       __try
       {
	 frmControl->SQLConsulta->GetFieldNames(names);

	 while(!frmControl->SQLConsulta->Eof)
	 {
	   currentLine = "";

	   for(int i = 0; i < names->Count; ++i)
	   {
		currentField = frmControl->SQLConsulta->FieldByName(names->Strings[i]);
		currentLine = currentLine + "<->" + currentField->AsString;
	   }

	   salidaMemo->Lines->Append(currentLine);
	   frmControl->SQLConsulta->Next();
	 }
       }
       __finally
       {
	 names->Free();
       }
   }
   else
   {
     salidaMemo->Lines->Append("¡No hay datos!");
     salidaMemo->Lines->Append("_____________________");
   }
}
//---------------------------------------------------------------------------
void __fastcall TfrmGestorDatos::mnuEmergentePopup(TObject *Sender)
{
   salidaMemo->Lines->Append(">>Elija una opción<<");
}
//---------------------------------------------------------------------------
// Sale de la aplicación
void __fastcall TfrmGestorDatos::Finalizar1Click(TObject *Sender)
{
   salidaMemo->Lines->Append("Finalizando...");
   Sleep(750);
   Close();
}
//---------------------------------------------------------------------------
// Conecta a la base de datos
void __fastcall TfrmGestorDatos::Conectar1Click(TObject *Sender)
{
   conectarBotonClick(Sender);
}
//---------------------------------------------------------------------------
// Desconecta de la base de datos
void __fastcall TfrmGestorDatos::Desconectar1Click(TObject *Sender)
{
   if(frmControl->SQLConexion->ConnectionState != csStateClosed)
   {
     salidaMemo->Lines->Append("[+] Cerrando base de datos...");
     Sleep(750);

     frmControl->SQLConsulta->Close();
     frmControl->SQLConexion->Close();

     salidaMemo->Lines->Append("[-] Desconectada base de datos.");
     salidaMemo->Lines->Append("_____________________");

     conectarBoton->Enabled = true;
     ejecutarBoton->Enabled = false;

     bddSQL = "";  // Anula la selección y tiene que volver a elegir una nueva base de datos.
   }
   else
   {
     salidaMemo->Lines->Append("[X] No hay base de datos conectadas.");
     salidaMemo->Lines->Append("_____________________");
   }
}
//---------------------------------------------------------------------------
// Ejecuta la consulta solicitada a la base de datos
void __fastcall TfrmGestorDatos::Ejecutar1Click(TObject *Sender)
{
   ejecutarBotonClick(Sender);
}
//---------------------------------------------------------------------------
// Selecciona la base de datos SQLite desde la unidad de disco.
// Puede ser local/remoto.
void __fastcall TfrmGestorDatos::Seleccionar1Click(TObject *Sender)
{
	int estado;

   if(frmControl->dlgAbrirSQLite->Execute(Application->Handle) == true)
   {
     bddSQL = frmControl->dlgAbrirSQLite->FileName;

     estado = verificarSQL(bddSQL);
     if(estado == FTAMCERO)
     {
       salidaMemo->Lines->Append("[X] La base de datos está vacía.");
       bddSQL = "";  // Queda anulada la selección.
     }
     else
     {
       if(estado == FBIEN)
	 salidaMemo->Lines->Append("Base de datos leída: " + bddSQL);
       else
	 if(estado == FERRORCAB)
	 {
	   salidaMemo->Lines->Append("[X] La base de datos no es del tipo sqlite3.");
	   bddSQL = "";  // Queda anulada la selección.
	 }
	 else
	 {
	   salidaMemo->Lines->Append("[X] Error en base de datos seleccionada: " + bddSQL);
	   salidaMemo->Lines->Append("Código=" + IntToStr(estado));
	   bddSQL = "";  // Queda anulada la selección.
	 }
     }
   }
   else
   {
     bddSQL = "ejemploSQLite.sdb";  // selección por omisión
     salidaMemo->Lines->Append("Base de datos local: " + bddSQL);
   }

   salidaMemo->Lines->Append("_____________________");
}
//---------------------------------------------------------------------------
// Responde al clic derecho sobre la imágen mostrando una ayuda descriptiva
void __fastcall TfrmGestorDatos::Image1Click(TObject *Sender)
{
   Ayuda1Click(Sender);
}
//---------------------------------------------------------------------------
// Muestra una ventana con un texto explicativo
void __fastcall TfrmGestorDatos::Ayuda1Click(TObject *Sender)
{
   dlgPanelInfo = new TdlgPanelInfo(this);

   dlgPanelInfo->ShowModal();
   delete dlgPanelInfo;
}
//---------------------------------------------------------------------------
// Invoca la herramienta para la gestión de base de datos SQLite.
void __fastcall TfrmGestorDatos::Gestionar1Click(TObject *Sender)
{
	HINSTANCE estado;
	int vreal;

   salidaMemo->Lines->Append("Invocando herramienta externa: " + progSQL);

   estado = ShellExecute(Handle, L"open", progSQL.c_str(), L"", L"", SW_NORMAL);
   vreal = (int)estado;
   if(vreal == 42)
     vreal = 0;

   salidaMemo->Lines->Append("código=" + IntToStr(vreal));
   salidaMemo->Lines->Append("_____________________");
}
//---------------------------------------------------------------------------

