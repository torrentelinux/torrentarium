//---------------------------------------------------------------------------
// Proyecto : SQLite_Ejemplo.cbproj
// M�dulo   : mdlPanelInfo.cpp
// Autor    : Octulio Bilet�n * Marzo de 2024
// Prop�sito: Gestionar la ventana "Panel Informativo".
// Obs.     : Simple ayuda de textos.
//---------------------------------------------------------------------------
#include <vcl.h>
#include "mdlPanelInfo.h"
#pragma hdrstop

//---------------------------------------------------------------------
#pragma resource "*.dfm"
TdlgPanelInfo *dlgPanelInfo;
//--------------------------------------------------------------------- 
__fastcall TdlgPanelInfo::TdlgPanelInfo(TComponent* AOwner)
	: TOKRightDlg(AOwner)
{
}
//---------------------------------------------------------------------
