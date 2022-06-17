// cliente_config.cpp
// Edmund Muslok -- Junio de 2022
// Cliente de TCP que se comunica con un servidor TCP por el puerto asignado.
// Configura la dirección IPv4 y el nº de puerto asignado por el usuario.
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
   PuertoTCP = "";

   meDirIP->Clear();
   mePuerto->Clear();
}
//---------------------------------------------------------------------
void __fastcall TDlgAjustes::OKBtnClick(TObject *Sender)
{
	int valor[4] = {0};
	_TCHAR param1[16] = { L"" };
	_TCHAR param2[16] = { L"" };
	_TCHAR param3[16] = { L"" };
	_TCHAR param4[16] = { L"" };
	_TCHAR param5[16] = { L"" };
	_TCHAR param6[16] = { L"" };
	_TCHAR param7[16] = { L"" };
	wistringstream entrada(meDirIP->Text.c_str());
	String temp;

   entrada >> ws >> param1
	   >> ws >> param2
	   >> ws >> param3
	   >> ws >> param4
	   >> ws >> param5
	   >> ws >> param6
	   >> ws >> param7;

   PuertoTCP = String(mePuerto->Text).Trim();

   temp = "";
   temp = temp + param1 + param2 + param3 + param4 + param5 + param6 + param7;

   swscanf(temp.c_str(), L"%d.%d.%d.%d", &valor[0], &valor[1], &valor[2], &valor[3]);

   bool todo_bien = true;
   for(int i = 0; i < 4; i++)
   {
     if(valor[i] >= 0 && valor[i] <= 255)
       continue;
     else
       todo_bien = false;
   }

   if(todo_bien == true)
   {
     DirIP = temp;

     ModalResult = mrOk;
   }
   else
   {
     meDirIP->SetFocus();
     Application->MessageBox(L"Datos incorrectos en IP.", L"Aviso", MB_OK|MB_ICONERROR);

     ModalResult = mrNone;
   }
}
//---------------------------------------------------------------------------
void __fastcall TDlgAjustes::CancelBtnClick(TObject *Sender)
{
   ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TDlgAjustes::btnBorrarClick(TObject *Sender)
{
   meDirIP->Clear();
   mePuerto->Clear();
}
//---------------------------------------------------------------------------
