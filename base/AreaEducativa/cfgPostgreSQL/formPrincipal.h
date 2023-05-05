//---------------------------------------------------------------------------

#ifndef formPrincipalH
#define formPrincipalH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Tabs.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
#include <IniFiles.hpp>
//---------------------------------------------------------------------------
class TfrmPrincipal : public TForm
{
__published:	// IDE-managed Components
	TButton *btnCerrar;
	TStatusBar *stbEstado;
	TPageControl *PageControlPrincipal;
	TTabSheet *Hoja1;
	TTabSheet *Hoja2;
	TTabSheet *Hoja3;
	TTabSheet *Hoja4;
	TTabSheet *Hoja5;
	TStaticText *StaticText1;
	TStaticText *StaticText2;
	TOpenTextFileDialog *dlgAbrirConfig;
	TButton *btnSeleccionar1;
	TEdit *edtLinea1;
	TEdit *edtLinea2;
	TButton *btnSeleccionar2;
	TStaticText *StaticText3;
	TEdit *edtListenAddr;
	TLabel *Label1;
	TEdit *edtPort;
	TLabel *Label2;
	TEdit *edtMaxConn;
	TMemo *mmMensajes;
	TLabel *Label3;
	TEdit *edtShareBuff;
	TButton *btnAyuda;
	void __fastcall btnCerrarClick(TObject *Sender);
	void __fastcall btnSeleccionar1Click(TObject *Sender);
	void __fastcall btnSeleccionar2Click(TObject *Sender);
	void __fastcall btnAyudaClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmPrincipal(TComponent* Owner);
	void __fastcall opcionesGeneral(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmPrincipal *frmPrincipal;
//---------------------------------------------------------------------------
#endif
