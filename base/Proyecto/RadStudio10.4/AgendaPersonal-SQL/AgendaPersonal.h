//------------------------------------------------------------------------------
/* Agenda Personal * SQL						      */
// Leer docu/AgendaPersonalSQL.txt para más información acerca de este proyecto
//------------------------------------------------------------------------------

#ifndef AgendaPersonalH
#define AgendaPersonalH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ToolWin.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <Vcl.WinXCtrls.hpp>
#include <Vcl.Samples.Spin.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TfrmPrincipal : public TForm
{
__published:	// IDE-managed Components
	TMemo *mmMensajes;
	TStatusBar *sbMensajes;
	TToolBar *ToolBar1;
	TToolButton *tbtnConectar;
	TToolButton *tbtnDesconectar;
	TToolButton *tbtnSalir;
	TDBGrid *DBAgenda;
	TToolButton *tbtnGrilla;
	TDBNavigator *DBNavegador;
	TSpinButton *SpinButton1;
	TSpeedButton *sbtnGrilla;
	TToolButton *tbtnEditar;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall tbtnConectarClick(TObject *Sender);
	void __fastcall tbtnSalirClick(TObject *Sender);
	void __fastcall tbtnDesconectarClick(TObject *Sender);
	void __fastcall tbtnGrillaClick(TObject *Sender);
	void __fastcall DBNavegadorClick(TObject *Sender, TNavigateBtn Button);
	void __fastcall SpinButton1UpClick(TObject *Sender);
	void __fastcall SpinButton1DownClick(TObject *Sender);
	void __fastcall FormClick(TObject *Sender);
	void __fastcall sbtnGrillaClick(TObject *Sender);
	void __fastcall tbtnEditarClick(TObject *Sender);

private:	// User declarations
	int constY;
	bool conectado;

	String tiempoActual(void);
	void guardarRegistroActividades(void);

public:		// User declarations
	__fastcall TfrmPrincipal(TComponent* Owner);
	bool conectarSQL(void);
	bool desconectarSQL(void);
	bool estadoSQL(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmPrincipal *frmPrincipal;
//---------------------------------------------------------------------------
#endif
