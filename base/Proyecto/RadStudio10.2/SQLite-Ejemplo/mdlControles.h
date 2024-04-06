//---------------------------------------------------------------------------
// Proyecto : SQLite_Ejemplo.cbproj
// Encabezamiento: mdlControles.h
// Autor    : Octulio Bilet�n * Marzo de 2024
// Prop�sito: Gestionar controles de conexi�n a la base de datos 'ejemploSQLite.sdb'
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
   int tamBaseDatos;		// n� de bytes que contiene la bdd.
   String verControlador;       // n� de ver. del controlador de la bdd.
   String nombreControlador;    // nombre del controlador de la bdd.
   String funcionControlador;   // nombre funci�n
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
