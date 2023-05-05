//---------------------------------------------------------------------------
// Encabezamiento: formPrincipal.h
// Autor: Octulio Biletán * Mayo de 2023
// Propósito:
// Permite hacer modificaciones sobre el archivo de configuración de PostgreSQL.
// Declaración de la clase TfrmPrincipal.
// Fichero c:\Bitnami\wappstack-x.x.xx-x\postgresql\data\postgresql.conf.
// Modelo Educativo de aplicación para Windows.
// Forma parte del proyecto cfgPostgres.cbproj.
// Compilador C++: Embarcadero C++ Builder 10.2 para Windows.
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
	TButton *btnSeleccionar1;
	TButton *btnSeleccionar2;
	TButton *btnAyuda;
	TStatusBar *stbEstado;
	TPageControl *PageControlPrincipal;
	TTabSheet *Hoja1;
	TTabSheet *Hoja2;
	TTabSheet *Hoja3;
	TTabSheet *Hoja4;
	TTabSheet *Hoja5;
	TStaticText *StaticText1;
	TStaticText *StaticText2;
	TStaticText *StaticText3;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TOpenTextFileDialog *dlgAbrirConfig;
	TEdit *edtLinea1;
	TEdit *edtLinea2;
	TEdit *edtListenAddr;
	TEdit *edtPort;
	TEdit *edtMaxConn;
	TEdit *edtShareBuff;
	TMemo *mmMensajes;
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
