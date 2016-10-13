//---------------------------------------------------------------------------
// Encabezamiento : OpenProgramDialog.h
// Autor    : Eugenio Martínez - torrentelinux@gmail.com - Mayo de 2016
// Propósito: Ejecutar una aplicación, documento, URL, etc.,
//            seleccionada por el usuario mediante un cuadro de diálogo simple.
//---------------------------------------------------------------------------

#ifndef OpenProgramDialogH
#define OpenProgramDialogH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Outline.hpp>
#include <Vcl.Samples.DirOutln.hpp>
#include <Vcl.FileCtrl.hpp>
#include <Vcl.AppEvnts.hpp>

#include "OpenProgramClass.h"
#include "OpenProgramDefs.h"

//---------------------------------------------------------------------------
class TfrmOpenProgram : public TForm
{
__published:	// IDE-managed Components
	TBevel *bvlBevel;
	TButton *OKBtn;
	TButton *CancelBtn;
	TButton *btnSelDir;
	TButton *btnBrowse;
	TBitBtn *btnDown;
	TBitBtn *btnUp;
	TComboBox *cbxOpen;
	TComboBox *cbxParameters;
	TComboBox *cbxDirectory;
	TComboBox *cftRun;
	TComboBox *cftOperation;
	TComboBox *cbxDelayTime;
	TComboBox *cbxPriority;
	TComboBox *cbxAffinity;
	TCheckBox *chkboxActivateDTime;
	TStaticText *txtOpen;
	TStaticText *txtParameters;
	TStaticText *txtDirectory;
	TStaticText *txtRun;
	TStaticText *txtErrorMsg;
	TStaticText *txtOperation;
	TStaticText *txtTrick;
	TStaticText *txtPriority;
	TStaticText *txtAffinity;
	TStaticText *txtDelayTime;
	TStaticText *txtText2;
	TStaticText *txtText3;
	TShape *shpCircle;
	TOpenDialog *dlgFileOpen;
	TImage *imgEscudo;
	TImage *imgMinimize;
	TImage *imgHelp;
	TImage *imgViewLog;
	void __fastcall CancelBtnClick(TObject *Sender);
	void __fastcall OKBtnClick(TObject *Sender);
	void __fastcall cbxOpenChange(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall btnBrowseClick(TObject *Sender);
	void __fastcall btnDownClick(TObject *Sender);
	void __fastcall btnUpClick(TObject *Sender);
	void __fastcall btnSelDirClick(TObject *Sender);
	void __fastcall btnDownMouseEnter(TObject *Sender);
	void __fastcall btnUpMouseEnter(TObject *Sender);
	void __fastcall txtTrickClick(TObject *Sender);
	void __fastcall txtTrickMouseEnter(TObject *Sender);
	void __fastcall imgMinimizeClick(TObject *Sender);
	void __fastcall imgHelpClick(TObject *Sender);
	void __fastcall imgMinimizeMouseEnter(TObject *Sender);
	void __fastcall imgHelpMouseEnter(TObject *Sender);
	void __fastcall imgViewLogClick(TObject *Sender);
	void __fastcall imgViewLogMouseEnter(TObject *Sender);
	void __fastcall chkboxActivateDTimeClick(TObject *Sender);

private:	// User declarations
protected:
	DirectoryDialog dlgDirOpen;
	File_Exec feInfo;

	void __fastcall WMQueryEndSession(TWMQueryEndSession &Message);

public:		// User declarations
	__fastcall TfrmOpenProgram(TComponent* Owner);

	BEGIN_MESSAGE_MAP
	    VCL_MESSAGE_HANDLER(WM_QUERYENDSESSION, TWMQueryEndSession, WMQueryEndSession)
	END_MESSAGE_MAP(TForm)

};
//---------------------------------------------------------------------------
extern PACKAGE TfrmOpenProgram *frmOpenProgram;
//---------------------------------------------------------------------------
#endif
