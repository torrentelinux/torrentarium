//---------------------------------------------------------------------
#include <tchar.h>
#include <vcl.h>
#include <sstream>

#include "cliente_config.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TDlgAjustes *DlgAjustes;

using namespace std;

//---------------------------------------------------------------------
__fastcall TDlgAjustes::TDlgAjustes(TComponent* AOwner)
	: TForm(AOwner)
{
   DirIP = "";
}
//---------------------------------------------------------------------
void __fastcall TDlgAjustes::OKBtnClick(TObject *Sender)
{
	String salida = "";
	wistringstream entrada(meDirIP->Text.c_str());
	_TCHAR param1[16] = { L"" };
	_TCHAR param2[16] = { L"" };
	_TCHAR param3[16] = { L"" };
	_TCHAR param4[16] = { L"" };

   entrada >> ws >> param1
	   >> ws >> param2
	   >> ws >> param3
	   >> ws >> param4;

   DirIP = salida + param1 + param2 + param3 + param4;

   ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TDlgAjustes::CancelBtnClick(TObject *Sender)
{
   DirIP = "";
   meDirIP->Clear();
   mePuerto->Clear();

   ModalResult = mrCancel;
}
//---------------------------------------------------------------------------



