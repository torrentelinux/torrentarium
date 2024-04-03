//---------------------------------------------------------------------------
// Proyecto : SQLite_Ejemplo.cbproj
// Módulo   : mdlControles.cpp
// Autor    : Octulio Biletán * Marzo de 2024
// Propósito: Gestionar controles de conexión a la base de datos 'ejemploSQLite.sdb'
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
}
//---------------------------------------------------------------------------
void __fastcall TfrmControl::SQLConexionAfterConnect(TObject *Sender)
{
   estado_conexion = frmControl->SQLConexion->Connected;
}
//---------------------------------------------------------------------------
const bool TfrmControl::estadoConexion(void)
{
   return estado_conexion;
}
