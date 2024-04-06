//---------------------------------------------------------------------------
// Proyecto : SQLite_Ejemplo.cbproj
// M�dulo   : mdlControles.cpp
// Autor    : Octulio Bilet�n * Marzo de 2024
// Prop�sito: Gestionar controles de conexi�n a la base de datos 'ejemploSQLite.sdb'
// Obs.     : El lenguaje de consulta utilizado es SQLite v3.
//---------------------------------------------------------------------------

#include <vcl.h>
#include "mdlControles.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TfrmControl *frmControl;
//---------------------------------------------------------------------------
__fastcall TfrmControl::TfrmControl(TComponent* Owner) : TFrame(Owner)
{
   conexion.estado = false;
   conexion.tamBaseDatos = 0;
   conexion.verControlador = "";
   conexion.nombreControlador = "";
   conexion.funcionControlador = "";
   conexion.nombreBiblioteca = "";
   conexion.proveedorBiblioteca = "";
}
//---------------------------------------------------------------------------
void __fastcall TfrmControl::SQLConexionAfterConnect(TObject *Sender)
{
   conexion.estado              = frmControl->SQLConexion->Connected;

   conexion.nombreControlador   = frmControl->SQLConexion->DriverName;
   conexion.nombreBiblioteca    = frmControl->SQLConexion->Params->ValueFromIndex[0];
   conexion.proveedorBiblioteca = frmControl->SQLConexion->Params->ValueFromIndex[1];
   conexion.funcionControlador  = frmControl->SQLConexion->Params->ValueFromIndex[2];

   conexion.verControlador = leerVersionBaseDatos();
   conexion.tamBaseDatos = leerLongBaseDatos();
}
//---------------------------------------------------------------------------
void __fastcall TfrmControl::SQLConexionAfterDisconnect(TObject *Sender)
{
   conexion.estado = false;
   conexion.tamBaseDatos = 0;

   conexion.nombreControlador   = "";
   conexion.verControlador      = "";
   conexion.nombreBiblioteca    = "";
   conexion.proveedorBiblioteca = "";
   conexion.funcionControlador  = "";
}
//---------------------------------------------------------------------------
void TfrmControl::estadoConexionSQL(DatosConexionSQL &dcsql)
{
   dcsql.estado = conexion.estado;
   dcsql.tamBaseDatos = conexion.tamBaseDatos;

   dcsql.verControlador = conexion.verControlador;
   dcsql.nombreControlador = conexion.nombreControlador;
   dcsql.nombreBiblioteca = conexion.nombreBiblioteca;
   dcsql.proveedorBiblioteca = conexion.proveedorBiblioteca;
   dcsql.funcionControlador = conexion.funcionControlador;
}
//---------------------------------------------------------------------------
// Averigua el n� de versi�n de sqlite
wchar_t *TfrmControl::leerVersionBaseDatos(void)
{
	String tmp;

   tmp = "";

   SQLConsulta->CommandText = "select sqlite_version();";
   SQLConsulta->Prepared = true;
   SQLConsulta->Open();

   SQLConsulta->First();
   tmp = SQLConsulta->Fields->Fields[0]->AsString;
   SQLConsulta->Close();

   return tmp.c_str();
}
//---------------------------------------------------------------------------
// Averigua la longitud de la base de datos.
// Devuelve el n� de bytes que ocupa la bdd. en el dispositivo de almacenamiento.
int TfrmControl::leerLongBaseDatos(void)
{
	static int tmp;

   tmp = 0;

   SQLConsulta->CommandText = "select page_size * page_count from pragma_page_count(), pragma_page_size();";
   SQLConsulta->Prepared = true;
   SQLConsulta->Open();

   SQLConsulta->First();
   tmp = SQLConsulta->Fields->Fields[0]->AsInteger;
   SQLConsulta->Close();

   return tmp;
}
//---------------------------------------------------------------------------

