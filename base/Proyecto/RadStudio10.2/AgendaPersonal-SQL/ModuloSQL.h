//------------------------------------------------------------------------------
/* Agenda Personal * SQL						      */
// Leer docu/AgendaPersonalSQL.txt para más información acerca de este proyecto
//------------------------------------------------------------------------------

#ifndef ModuloSQLH
#define ModuloSQLH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.PG.hpp>
#include <FireDAC.Phys.PGDef.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.UI.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Login.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.VCLUI.Script.hpp>
#include <FireDAC.Comp.BatchMove.DataSet.hpp>
#include <FireDAC.Comp.BatchMove.hpp>
#include <FireDAC.Comp.BatchMove.SQL.hpp>
#include <Datasnap.Provider.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TModuloDatos : public TDataModule
{
__published:	// IDE-managed Components
	TFDPhysPgDriverLink *FDPhysPgDriverLink1;
	TFDConnection *FDConnection1;
	TFDGUIxLoginDialog *FDVCLLoginDialog1;
	TFDQuery *FDQuery1;
	TDataSetProvider *DataSetProvider1;
	TDataSource *DataSource1;
	TIntegerField *FDQuery1codigo;
	TWideStringField *FDQuery1nombre;
	TWideStringField *FDQuery1apellido;
	TWideStringField *FDQuery1correoe;
	TWideStringField *FDQuery1sitio1;
	TWideStringField *FDQuery1sitio2;
	TWideStringField *FDQuery1alias;
	TWideStringField *FDQuery1telefono;
	TWideStringField *FDQuery1Telegrammsj;
	TWideStringField *FDQuery1Xmsj;
	TOpenDialog *OpenDialog1;
private:	// User declarations
public:		// User declarations
	__fastcall TModuloDatos(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TModuloDatos *ModuloDatos;
//---------------------------------------------------------------------------
#endif
