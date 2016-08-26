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

#include "OpenProgramClass.h"

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
	TStaticText *txtOpen;
	TStaticText *txtText2;
	TStaticText *txtText3;
	TStaticText *txtParameters;
	TStaticText *txtDirectory;
	TStaticText *txtRun;
	TStaticText *txtErrorMsg;
	TStaticText *txtOperation;
	TStaticText *txtTrick;
	TShape *shpCircle;
	TImage *imgEscudo;
	TImage *imgMinimize;
	TImage *imgHelp;
	TOpenDialog *dlgFileOpen;
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
private:	// User declarations
protected:
	DirectoryDialog dlgDirOpen;

public:		// User declarations
	__fastcall TfrmOpenProgram(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmOpenProgram *frmOpenProgram;
//---------------------------------------------------------------------------
#endif
