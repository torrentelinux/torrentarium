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

struct DatosConexionSQL
{
   bool estado;
   int tamBaseDatos;		// nº de bytes que contiene la bdd.
   String verControlador;       // nº de ver. del controlador de la bdd.
   String nombreControlador;    // nombre del controlador de la bdd.
   String funcionControlador;   // nombre función
   String nombreBiblioteca;     // nombre de la biblioteca
   String proveedorBiblioteca;  // nombre del proveedor de la biblioteca

   DatosConexionSQL() : estado(false), tamBaseDatos(0) {}
};

class TfrmControl : public TFrame
{
__published:	// IDE-managed Components
	TSQLQuery *SQLConsulta;
	TSQLConnection *SQLConexion;
	TFileOpenDialog *dlgAbrirSQLite;
	void __fastcall SQLConexionAfterConnect(TObject *Sender);
	void __fastcall SQLConexionAfterDisconnect(TObject *Sender);

private:	// User declarations
	DatosConexionSQL conexion;
	int leerLongBaseDatos(void);
	wchar_t *leerVersionBaseDatos(void);

public:		// User declarations
	__fastcall TfrmControl(TComponent* Owner);
	void estadoConexionSQL(DatosConexionSQL &dcsql);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmControl *frmControl;
//---------------------------------------------------------------------------
#endif
