// Proyecto: Ejemplo1.cbproj
// Encabez.: frmPrincipal.h
// Autor   : Octulio Biletán * Octubre de 2025.
// Descrip.: Declarar la clase 'TfrmCentral'.
// Ambiente: Windows modo gráfico, 64 bits.
// Licencia: Software libre.
//---------------------------------------------------------------------------

#ifndef frmPrincipalH
#define frmPrincipalH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TfrmCentral : public TForm
{
__published:	// IDE-managed Components
	TLabel *lblAviso;
	TRichEdit *rtfEdit;
	TStatusBar *sbBarraEstado;
	TPopupMenu *mnuEmergente;
	TMenuItem *opcAcercaDe;
	TMenuItem *opcSalir;
	void __fastcall FormClick(TObject *Sender);
	void __fastcall FormKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall opcSalirClick(TObject *Sender);
	void __fastcall opcAcercaDeClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmCentral(TComponent* Owner);

	void miHojaDeDibujo(void);
	char *versionEmbarcadero(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmCentral *frmCentral;
//---------------------------------------------------------------------------
#endif
