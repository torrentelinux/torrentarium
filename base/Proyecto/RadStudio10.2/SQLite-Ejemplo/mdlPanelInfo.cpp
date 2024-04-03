//---------------------------------------------------------------------------
// Proyecto : SQLite_Ejemplo.cbproj
// Módulo   : mdlPanelInfo.cpp
// Autor    : Octulio Biletán * Marzo de 2024
// Propósito: Gestionar la ventana "Panel Informativo".
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
