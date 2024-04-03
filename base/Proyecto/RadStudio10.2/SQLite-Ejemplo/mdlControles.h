//---------------------------------------------------------------------------
// Proyecto : SQLite_Ejemplo.cbproj
// Encabezamiento: mdlControles.h
// Autor    : Octulio Biletán * Marzo de 2024
// Propósito: Gestionar controles de conexión a la base de datos 'ejemploSQLite.sdb'
// Obs.     : El lenguaje de consulta utilizado es SQLite v3.
//---------------------------------------------------------------------------

#ifndef mdlControlesH
#define mdlControlesH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.DbxSqlite.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TfrmControl : public TFrame
{
__published:	// IDE-managed Components
	TSQLQuery *SQLConsulta;
	TSQLConnection *SQLConexion;
	TFileOpenDialog *dlgAbrirSQLite;
	void __fastcall SQLConexionAfterConnect(TObject *Sender);

private:	// User declarations
	bool estado_conexion;

public:		// User declarations
	__fastcall TfrmControl(TComponent* Owner);
	const bool estadoConexion(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmControl *frmControl;
//---------------------------------------------------------------------------
#endif
