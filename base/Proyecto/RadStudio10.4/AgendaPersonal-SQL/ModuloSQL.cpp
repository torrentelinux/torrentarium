//------------------------------------------------------------------------------
/* Agenda Personal * SQL						      */
// Leer docu/AgendaPersonalSQL.txt para más información acerca de este proyecto
//------------------------------------------------------------------------------

#pragma hdrstop

#include "ModuloSQL.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma resource "*.dfm"

TModuloDatos *ModuloDatos;
//---------------------------------------------------------------------------
__fastcall TModuloDatos::TModuloDatos(TComponent* Owner) : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
