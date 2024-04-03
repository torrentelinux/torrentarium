//---------------------------------------------------------------------------
// Proyecto : SQLite_Ejemplo.cbproj
// Encabezamiento: mdlAgenda.h
// Autor    : Octulio Biletán * Marzo de 2024
// Propósito: Realizar una consulta a la base de datos 'ejemploSQLite.sdb'
// Obs.     : El lenguaje de consulta utilizado es SQLite v3.
//---------------------------------------------------------------------------

#ifndef mdlGestorDatosH
#define mdlGestorDatosH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.DbxSqlite.hpp>
#include <Data.SqlExpr.hpp>
#include <Data.FMTBcd.hpp>
#include <VCLTee.TeCanvas.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.DBScope.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TfrmGestorDatos : public TForm
{
__published:	// IDE-managed Components
	TMemo *salidaMemo;
	TButton *ejecutarBoton;
	TButton *conectarBoton;
	TStatusBar *stbMensaje;
	TPopupMenu *mnuEmergente;
	TMenuItem *Conectar1;
	TMenuItem *Ejecutar1;
	TMenuItem *N1;
	TMenuItem *Finalizar1;
	TMenuItem *Desconectar1;
	TMenuItem *Seleccionar1;
	TMenuItem *Ayuda1;
	TMenuItem *Gestionar1;
	TImage *Image1;

	void __fastcall conectarBotonClick(TObject *Sender);
	void __fastcall ejecutarBotonClick(TObject *Sender);
	void __fastcall ShowSelectResults();
	void __fastcall Finalizar1Click(TObject *Sender);
	void __fastcall Conectar1Click(TObject *Sender);
	void __fastcall Ejecutar1Click(TObject *Sender);
	void __fastcall Desconectar1Click(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall mnuEmergentePopup(TObject *Sender);
	void __fastcall Seleccionar1Click(TObject *Sender);
	void __fastcall Ayuda1Click(TObject *Sender);
	void __fastcall Gestionar1Click(TObject *Sender);
	void __fastcall Image1Click(TObject *Sender);

private:	// User declarations
	String bddSQL;  // nombre de la base de datos sql
        String progSQL;  // nombre de la herramienta SQLite

protected:
	const int verificarSQL(String &fsql);  // verifica la integridad de la base de datos

public:		// User declarations
	__fastcall TfrmGestorDatos(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmGestorDatos *frmGestorDatos;
//---------------------------------------------------------------------------
#endif
