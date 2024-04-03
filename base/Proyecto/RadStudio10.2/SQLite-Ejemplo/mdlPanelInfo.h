//---------------------------------------------------------------------------
// Proyecto : SQLite_Ejemplo.cbproj
// Encabezamiento: mdlPanelInfo.h
// Autor    : Octulio Biletán * Marzo de 2024
// Propósito: Gestionar la ventana "Panel Informativo".
// Obs.     : Simple ayuda de textos.
//----------------------------------------------------------------------------
#ifndef mdlPanelInfoH
#define mdlPanelInfoH
//----------------------------------------------------------------------------
#include <OKCANCL2.h>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Graphics.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <System.hpp>
#include <Winapi.Windows.hpp>
//----------------------------------------------------------------------------
class TdlgPanelInfo : public TOKRightDlg
{
__published:
	TMemo *mmAyuda;
private:
public:
	virtual __fastcall TdlgPanelInfo(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TdlgPanelInfo *dlgPanelInfo;
//----------------------------------------------------------------------------
#endif
