// Cabecera   : caModulo.h
// Autor      : Octulio Biletán - torrentelinux@gmail.com - Marzo de 2021.
// Descripción: Centro de aplicaciones para productos Oracle.
// Utilitario para realizar instalaciones con ficheros .zip
// Dirigido para aquellos usuarios programadores y desarrolladores en
// lenguaje Java con nivel inicial a intermedio.
//
// Referencias:
// https://docs.microsoft.com/es-es/windows-server/administration/windows-commands/rundll32
// https://www.java.com/es/download/help/path.html
//
//---------------------------------------------------------------------------
// Este programa fuente informático se acoge a la licencia GNU GPL v3
// https://www.gnu.org/licenses/gpl-3.0.en.html
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see https://www.gnu.org/licenses/
//----------------------------------------------------------------------------------

#ifndef caModuloH
#define caModuloH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ButtonGroup.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
#include <FileCtrl.hpp>
//---------------------------------------------------------------------------
class TfrmPrincipal : public TForm
{
__published:	// IDE-managed Components
	TLabel *lblAplic1;
	TStaticText *txtEncabezado;
	TLabel *lblAplic2;
	TButtonGroup *grpBotones;
	TStaticText *txtVarsEntorno;
	TLabel *lblPath;
	TFileOpenDialog *dlgAbrirFichero;
	TStatusBar *sbBarraDeEstado;
	TFileOpenDialog *dlgAbrirDir;
	TMemo *mmAyuda;
	TStaticText *StaticText1;
	TLabel *lblJava;
	TLabel *lblRevisarPath;
	TBevel *Bevel1;
	void __fastcall lblAplic1Click(TObject *Sender);
	void __fastcall lblAplic1MouseEnter(TObject *Sender);
	void __fastcall lblAplic1MouseLeave(TObject *Sender);
	void __fastcall ButtonGroup1Items1Click(TObject *Sender);
	void __fastcall ButtonGroup1Items0Click(TObject *Sender);
	void __fastcall lblAplic2Click(TObject *Sender);
	void __fastcall lblAplic2MouseEnter(TObject *Sender);
	void __fastcall lblAplic2MouseLeave(TObject *Sender);
	void __fastcall grpBotonesItems1Click(TObject *Sender);
	void __fastcall lblPathClick(TObject *Sender);
	void __fastcall lblPathMouseEnter(TObject *Sender);
	void __fastcall lblPathMouseLeave(TObject *Sender);
	void __fastcall FormDblClick(TObject *Sender);
	void __fastcall FormClick(TObject *Sender);
	void __fastcall lblJavaMouseEnter(TObject *Sender);
	void __fastcall lblJavaMouseLeave(TObject *Sender);
	void __fastcall lblJavaClick(TObject *Sender);
	void __fastcall lblRevisarPathClick(TObject *Sender);
	void __fastcall lblRevisarPathMouseEnter(TObject *Sender);
	void __fastcall lblRevisarPathMouseLeave(TObject *Sender);
private:	// User declarations
	String aplics[16];
	String instalador[16];

public:		// User declarations
	__fastcall TfrmPrincipal(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmPrincipal *frmPrincipal;
//---------------------------------------------------------------------------
#endif
