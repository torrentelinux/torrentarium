//---------------------------------------------------------------------------

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
	TDBGrid *DBGrid1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall tbtnConectarClick(TObject *Sender);
	void __fastcall tbtnSalirClick(TObject *Sender);
	void __fastcall tbtnDesconectarClick(TObject *Sender);

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
