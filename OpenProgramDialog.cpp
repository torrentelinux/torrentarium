//---------------------------------------------------------------------------
// Módulo   : OpenProgramDialog.cpp
// Autor    : Eugenio Martínez - torrentelinux@gmail.com - Mayo de 2016
// Propósito: Ejecutar una aplicación seleccionada por el usuario mediante un cuadro de diálogo simple.
//            Ejemplos de comandos aceptados:
//              * cmd /k dir&pause&exit
//              * cmd /k echo help|diskpart&pause&exit
//              * cmd /k CSCRIPT %systemroot%\system32\SCREGEDIT.WSF&pause&exit
//              * cmd /k powershell /?&pause&exit
//              * powershell
//              * cmd /c runas /user:Administrador notepad&pause&exit
//            Ejemplos de nombres de carpetas aceptadas:
//              * .
//              * ..
//              * c:\\
//            Ejemplos de recursos tipo URL aceptados:
//              * www.google.com
//              * www.bing.com
//              * www.bing.com/?q=cuando+sale+windows+server+2016
//              * www.duckduckgo.com/?q=cuando+sale+windows+server+2016
//              * file:///C:/
//              * http://127.0.0.1
//              * http://localhost
//              * ftp://ftp.sitio.org
//            Ejemplos de nombres de documentos aceptados:
//              * C:\Windows\Help\mui\0C0A\mmc.CHM
//---------------------------------------------------------------------------

#include <tchar.h>
#include <vcl.h>
#include <shellapi.h>
#include <shlwapi.h>
#pragma hdrstop

#include "OpenProgramDialog.h"
#include "OpenProgramDefs.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

wstring begin_log = L"----------------------< begin log >------------------------------------";
wstring end_log   = L"----------------------< end log >--------------------------------------";

_TCHAR drv[MAXDRIVE] = { L"" },
       dir[MAXDIR] = { L"" },
       nm[MAXFILE] = { L"" },
       ext[MAXEXT] = { L"" };

_TCHAR *prog = NULL;
TfrmOpenProgram *frmOpenProgram;

//---------------------------------------------------------------------------
__fastcall TfrmOpenProgram::TfrmOpenProgram(TComponent* Owner)
	: TForm(Owner)
{
   btnBrowse->Tag = 0;
   dlgFileOpen->FilterIndex = 0;
   dlgFileOpen->FileName = "";

   prog = new _TCHAR[512];

   // Inicia el registro de actividades del usuario
   SaveLog(begin_log);
}
//---------------------------------------------------------------------------
void __fastcall TfrmOpenProgram::FormCreate(TObject *Sender)
{
   // Establece las dimensiones normales de la ventana principal
   Left = 40;
   Top = 59;
   Width = 564;
   Height = 212;
   ClientHeight = 186;
   ClientWidth = 558;

   // Ubica el control 'TImage' en su posición normal
   imgEscudo->Left = 18;
   imgEscudo->Top = 84;

   // Oculta los controles de parámetros, directorio y modo de ejecución
   txtParameters->Visible = false;
   txtDirectory->Visible = false;
   cbxParameters->Visible = false;
   cbxDirectory->Visible = false;

   // Oculta los controles de operación
   txtOperation->Visible = false;
   cftOperation->Visible = false;

   // Oculta los controles de correr
   txtRun->Visible = false;
   cftRun->Visible = false;

   // Oculta los controles de prioridad
   txtPriority->Visible = false;
   cbxPriority->Visible = false;

   // Oculta los controles de afinidad
   txtAffinity->Visible = false;
   cbxAffinity->Visible = false;

   // Oculta los controles de tiempo de espera
   txtDelayTime->Visible = false;
   cbxDelayTime->Visible = false;

   // El control de tiempo de espera está deshabilitado
   cbxDelayTime->Enabled = false;

   // Oculta el control 'activar tiempo de espera'
   chkboxActivateDTime->Visible = false;

   // Ubica el control 'txtText3' en su posición normal
   txtText3->Left = 59;
   txtText3->Top = 84;

   // Ubica el control 'TBevel en su posición normal
   bvlBevel->Left = 0;
   bvlBevel->Top = 0;
   bvlBevel->Height = 130;
   bvlBevel->Width = 554;

   // Ubica los botones en sus posiciones normales
   OKBtn->Left = 128;
   OKBtn->Top = 137;

   CancelBtn->Left = 220;
   CancelBtn->Top = 137;

   btnBrowse->Left = 312;
   btnBrowse->Top = 137;

   btnSelDir->Visible = false;

   // Configuración del botón 'Down'
   btnDown->Left = 518;
   btnDown->Top = 137;
   btnDown->Visible = false;

   // Oculta el botón 'Up'
   btnUp->Visible = false;

   // Configuración de la línea de texto 'txtTrick'
   txtTrick->Left = 510;
   txtTrick->Top = 130;
   txtTrick->Caption = "";

   // Ubica el control 'TShape' en su posición normal
   shpCircle->Left = 32;
   shpCircle->Top = 140;

   // Oculta los botones Minimize, Help y ViewLog
   imgMinimize->Visible = false;
   imgHelp->Visible = false;
   imgViewLog->Visible = false;

   txtErrorMsg->Caption = "";
   txtErrorMsg->Visible = false;

   SYSTEM_INFO siInfo;
   GetSystemInfo(&siInfo);

   for(unsigned int i = 0; i <= siInfo.dwNumberOfProcessors; i++)
     cbxAffinity->Items->Add(UnicodeString(i));

   cbxAffinity->ItemIndex = 0;

   for(unsigned int i = 1; i <= nelemsTimeTable; i++)
     cbxDelayTime->Items->Add(UnicodeString(i));

   cbxDelayTime->ItemIndex = 5;
}
//---------------------------------------------------------------------------
void __fastcall TfrmOpenProgram::FormClose(TObject *Sender, TCloseAction &Action)
{
   // Finaliza el registro de actividades del usuario
   SaveLog(end_log);
}
//---------------------------------------------------------------------------
void __fastcall TfrmOpenProgram::FormDestroy(TObject *Sender)
{
   // Libera memoria utilizada
   delete[] prog;
   prog = NULL;

   // SetProcessWorkingSetSize: Sets the minimum and maximum working set sizes for the specified process
   // Libera la memoria utilizada por este proceso
   SetProcessWorkingSetSize(GetCurrentProcess(), -1, -1);
}
//---------------------------------------------------------------------------
void __fastcall TfrmOpenProgram::CancelBtnClick(TObject *Sender)
{
   if(cbxOpen->Text.IsEmpty())
     Close();  // Cierra el programa y sale
   else
   {
     // Limpia cada línea de texto escrita por el usuario
     cbxOpen->Text = "";
     cbxParameters->Text = "";
     cbxDirectory->Text = "";

     // Limpia la línea que corresponde al mensaje de error
     txtErrorMsg->Caption = "";

     // Inicializa el control cftRun a la opción 'Normal window'
     cftRun->ItemIndex = 1;

     // Inicializa el control cftOperation a la opción 'Open'
     cftOperation->ItemIndex = op_open;

     // Inicializa el control a la 1ra. opción
     cbxAffinity->ItemIndex = 0;

     // Inicializa el control a la 1ra. opción
     cbxPriority->ItemIndex = 0;

     // Inicializa el control a la 6ta. opción
     cbxDelayTime->ItemIndex = 5;

     // Deshabilita el control
     cbxDelayTime->Enabled = false;

     // Desmarca el control
     chkboxActivateDTime->Checked = false;

     // Botón 'OK' deshabilitado
     OKBtn->Enabled = false;

     // Inicializa el círculo a 'Ok'
     shpCircle->Brush->Color = clBlue;
     shpCircle->Hint = "Ok";
   }
}
//---------------------------------------------------------------------------
void __fastcall TfrmOpenProgram::OKBtnClick(TObject *Sender)
{
	DWORD status = 33;
        wstringstream tmp;
     	wostringstream msg, commands;
        _TCHAR current_time[42] = { L"" };
        _TCHAR current_date[42] = { L"" };
        _TCHAR *params = NULL;

   Screen->Cursor =crHourGlass;
   if(btnDown->Tag == 0)
   {
     // El modo normal está habilitado

     if(btnBrowse->Tag == 0)
     {
       // Obtiene el nombre del programa/documento
       tmp << cbxOpen->Text.c_str() << ends;
       tmp >> prog;
     }

     // Obtiene los argumentos que acompañan al programa/documento
     params = PathGetArgs(cbxOpen->Text.c_str());

     // Obtiene la fecha y hora actual
     GetDateFormat(LOCALE_SYSTEM_DEFAULT, LOCALE_NOUSEROVERRIDE, NULL, NULL, current_date, sizeof(current_date));
     GetTimeFormat(LOCALE_SYSTEM_DEFAULT, LOCALE_NOUSEROVERRIDE, NULL, NULL, current_time, sizeof(current_time));

     // Ejecuta el objeto seleccionado por el usuario mediante alguna de estas funcs.
     // ShellExecute, ShellExecuteEx, ShellExecCmdLine, WinExec, ...
     // Por ej. escribir la sig. orden:
     //              * cmd /k dir&pause&exit
     status = (DWORD)ShellExecute(Application->Handle, L"open", prog, params, NULL, SW_SHOWNORMAL);

     // Guarda cada línea de texto en 'OpenProgram.log'
     commands << current_date << L", " << current_time << L": "
              << prog         << L", " << params
              << L", Open, Normal window, "
              << status << ends;
   }
   else
   {
     // El modo extendido está habilitado

     txtErrorMsg->Caption = "";
     wcscpy(prog, cbxOpen->Text.c_str());

     // Obtiene la fecha y hora actual
     GetDateFormat(LOCALE_SYSTEM_DEFAULT, LOCALE_NOUSEROVERRIDE, NULL, NULL, current_date, sizeof(current_date));
     GetTimeFormat(LOCALE_SYSTEM_DEFAULT, LOCALE_NOUSEROVERRIDE, NULL, NULL, current_time, sizeof(current_time));

     feInfo.hwnd = Application->Handle;
     feInfo.Operation = cftOperation->Text;
     feInfo.File = cbxOpen->Text;
     feInfo.Parameters = cbxParameters->Text;
     feInfo.Directory = cbxDirectory->Text;
     feInfo.nShowCmd = cftRun->ItemIndex;
     feInfo.dwPriorityClass = IdPriority[cbxPriority->ItemIndex].dwId;
     feInfo.dwProcessAffinityMask = cbxAffinity->Text.ToInt();

     if(chkboxActivateDTime->Checked)
       feInfo.Interval = TimeTable[cbxDelayTime->ItemIndex].Interval;
     else
       feInfo.Interval = IGNORE;  // No se utiliza el tiempo de espera

     // Ejecuta el objeto seleccionado por el usuario
     status = FileExec(&feInfo);

     // Guarda cada línea de texto en 'OpenProgram.log'
     commands << current_date               << L", " << current_time << L": "
              << cbxOpen->Text.c_str()      << L", " << cbxParameters->Text.c_str() << L", "
              << cbxDirectory->Text.c_str() << L", " << cftOperation->Text.c_str()  << L", "
              << cftRun->Text.c_str()       << L", " << cbxPriority->Text.c_str()   << L", "
              << cbxAffinity->Text.c_str()  << L", " << feInfo.Interval             << L", "
              << status << ends;
   }

   Screen->Cursor = crDefault;
   if(status <= 32)
   {
     // Se prepara para mostrar un mensaje de error en una caja de diálogo
     shpCircle->Brush->Color = clRed;
     shpCircle->Hint = "Wrong !";

     if(btnDown->Tag == 1)
       ShowErrorCode(L"< Wrong >", status);

     msg << L"Windows cannot find \'" << prog << L"\'. Make sure you typed the name correctly, and then try again.";
     Application->MessageBox(msg.str().c_str(), L"Error", MB_ICONERROR);
   }
   else
   {
     // El programa/documento se abrió exitosamente
     shpCircle->Brush->Color = clGreen;
     shpCircle->Hint = "Right !";
   }

   // Guarda cada línea de texto, no vacía, escrita por el usuario
   if(!cbxOpen->Text.IsEmpty())
     cbxOpen->Items->Add(cbxOpen->Text);

   if(!cbxParameters->Text.IsEmpty())
     cbxParameters->Items->Add(cbxParameters->Text);

   if(!cbxDirectory->Text.IsEmpty())
     cbxDirectory->Items->Add(cbxDirectory->Text);

   // Registra el comando ingresado por el usuario en un fichero de texto
   SaveLog(commands.str().c_str());

   return;
}
//---------------------------------------------------------------------------
void __fastcall TfrmOpenProgram::btnBrowseClick(TObject *Sender)
{
   if(dlgFileOpen->Execute())
   {
     _wfnsplit(dlgFileOpen->FileName.c_str(), drv, dir, nm, ext);

     if(wcschr(dir, ' '))
       // Agrega comillas al fichero porque contiene espacios en blanco
       dlgFileOpen->FileName = L"\"" + dlgFileOpen->FileName + L"\"";

     wcscpy(prog, dlgFileOpen->FileName.c_str());
     cbxOpen->Text = dlgFileOpen->FileName;

     btnBrowse->Tag = 1;
     OKBtn->Enabled = true;
   }
   else
   {
     btnBrowse->Tag = 0;
     OKBtn->Enabled = false;
     shpCircle->Brush->Color = clBlue;
     shpCircle->Hint = "Ok";
   }
}
//---------------------------------------------------------------------------
void __fastcall TfrmOpenProgram::cbxOpenChange(TObject *Sender)
{
   if(cbxOpen->Text.IsEmpty())
   {
     OKBtn->Enabled = false;
     shpCircle->Brush->Color = clBlue;
   }
   else
   {
     OKBtn->Enabled = true;
     wcscpy(prog, cbxOpen->Text.c_str());
   }
}
//---------------------------------------------------------------------------
void __fastcall TfrmOpenProgram::FormActivate(TObject *Sender)
{
   cbxOpen->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TfrmOpenProgram::btnDownClick(TObject *Sender)
{
   // Se habilita el modo extendido

   // Reajusta el tamaño de la ventana principal si se ha pulsado el botón 'btnDown'
   if(btnDown->Visible == true)
   {
     btnDown->Visible = false;  // Oculta el botón 'btnDown'
     btnDown->Tag = 1;  // El botón ha sido presionado

     // Establece las nuevas dimensiones de la ventana principal
     Width = 564;
     Height = 357;
     ClientHeight = 331;
     ClientWidth = 558;

     // Ubica el control 'TImage' a su nueva posición
     imgEscudo->Left = 18;
     imgEscudo->Top = 230;

     // Muestra los controles de parámetros, directorio y modo de ejecución
     txtParameters->Visible = true;
     txtDirectory->Visible = true;
     cbxParameters->Visible = true;
     cbxDirectory->Visible = true;

     txtOperation->Visible = true;
     cftOperation->Visible = true;
     txtRun->Visible = true;
     cftRun->Visible = true;

     // Muestra los controles de prioridad
     txtPriority->Visible = true;
     cbxPriority->Visible = true;

     // Muestra los controles de afinidad
     txtAffinity->Visible = true;
     cbxAffinity->Visible = true;

     // Muestra los controles de tiempo de espera
     txtDelayTime->Visible = true;
     cbxDelayTime->Visible = true;

     // Muestra el control 'activar tiempo de espera'
     chkboxActivateDTime->Visible = true;

     // Ubica el control 'txtText3' a su nueva posición
     txtText3->Left = 59;
     txtText3->Top = 230;

     // Ubica el control 'TBevel a su nueva posición
     bvlBevel->Left = 0;
     bvlBevel->Top = 0;
     bvlBevel->Height = 274;

     // Ubica los botones en sus nuevas posiciones
     OKBtn->Left = 150;
     OKBtn->Top = 288;

     CancelBtn->Left = 238;
     CancelBtn->Top = 288;

     btnBrowse->Left = 327;
     btnBrowse->Top = 288;

     btnSelDir->Left = 414;
     btnSelDir->Top = 288;
     btnSelDir->Visible = true;

     btnUp->Left = 518;
     btnUp->Top = 288;
     btnUp->Tag = 0;
     btnUp->Visible = true;

     imgMinimize->Visible = true;
     imgHelp->Visible = true;
     imgViewLog->Visible = true;

     // Ubica el control 'TShape' en su nueva posición
     shpCircle->Left = 122;
     shpCircle->Top = 296;
     txtErrorMsg->Visible = true;

     cbxOpen->SetFocus();
   }
}
//---------------------------------------------------------------------------
void __fastcall TfrmOpenProgram::btnUpClick(TObject *Sender)
{
   // Se habilita el modo normal

   if(btnUp->Visible == true)
   {
     btnUp->Visible = false;
     btnUp->Tag = 1;  // El botón hacia arriba fue presionado

     // Establece las dimensiones normales de la ventana principal
     Width = 564;
     Height = 212;
     ClientHeight = 186;
     ClientWidth = 558;

     // Ubica el control 'TImage' en su posición normal
     imgEscudo->Left = 18;
     imgEscudo->Top = 84;

     // Oculta los controles de parámetros, directorio y modo de ejecución
     txtParameters->Visible = false;
     txtDirectory->Visible = false;
     cbxParameters->Visible = false;
     cbxDirectory->Visible = false;

     txtOperation->Visible = false;
     cftOperation->Visible = false;
     txtRun->Visible = false;
     cftRun->Visible = false;

     // Oculta los controles de prioridad
     txtPriority->Visible = false;
     cbxPriority->Visible = false;

     // Oculta los controles de afinidad
     txtAffinity->Visible = false;
     cbxAffinity->Visible = false;

     // Oculta los controles de tiempo de espera
     txtDelayTime->Visible = false;
     cbxDelayTime->Visible = false;

     // Oculta el control 'activar tiempo de espera'
     chkboxActivateDTime->Visible = false;

     // Ubica el control 'txtText3' en su posición normal
     txtText3->Left = 59;
     txtText3->Top = 84;

     // Ubica el control 'TBevel en su posición normal
     bvlBevel->Left = 0;
     bvlBevel->Top = 0;
     bvlBevel->Height = 130;

     // Ubica los botones en sus posiciones normales
     OKBtn->Left = 128;
     OKBtn->Top = 137;

     CancelBtn->Left = 220;
     CancelBtn->Top = 137;

     btnBrowse->Left = 312;
     btnBrowse->Top = 137;

     btnSelDir->Visible = false;

     btnDown->Left = 518;
     btnDown->Top = 137;
     btnDown->Tag = 0;
     btnDown->Visible = true;

     imgMinimize->Visible = false;
     imgHelp->Visible = false;
     imgViewLog->Visible = false;

     // Ubica el control 'TShape' en su posición normal
     shpCircle->Left = 32;
     shpCircle->Top = 140;

     txtErrorMsg->Visible = false;
     cbxOpen->SetFocus();
   }
}
//---------------------------------------------------------------------------
void __fastcall TfrmOpenProgram::btnSelDirClick(TObject *Sender)
{
   dlgDirOpen.Title = L"Choose a folder to open";

   if(dlgDirOpen.Execute())
   {
     if(cftOperation->ItemIndex == op_find)
     {
       cbxOpen->Text = dlgDirOpen.DirName;
       OKBtn->Enabled = true;
     }
     else
       cbxDirectory->Text = dlgDirOpen.DirName;
   }
}
//---------------------------------------------------------------------------
void __fastcall TfrmOpenProgram::imgMinimizeClick(TObject *Sender)
{
   WindowState = wsMinimized;
}
//---------------------------------------------------------------------------
void __fastcall TfrmOpenProgram::imgHelpClick(TObject *Sender)
{
   // Muestra en un cuadro de diálogo una breve descripción acerca de este programa
   ShellAbout(Application->Handle, L"OpenProgram",
              L"Opens a program, folder, document, or internet url.\n"
              "Version 1.10.16.10",
              NULL);
}
//---------------------------------------------------------------------------
void __fastcall TfrmOpenProgram::btnDownMouseEnter(TObject *Sender)
{
   // Cambia la apariencia del ratón: flecha por mano.
   btnDown->Cursor = crHandPoint;
}
//---------------------------------------------------------------------------
void __fastcall TfrmOpenProgram::btnUpMouseEnter(TObject *Sender)
{
   // Cambia la apariencia del ratón: flecha por mano.
   btnUp->Cursor = crHandPoint;
}
//---------------------------------------------------------------------------
void __fastcall TfrmOpenProgram::imgMinimizeMouseEnter(TObject *Sender)
{
   // Cambia la apariencia del ratón: flecha por mano.
   imgMinimize->Cursor = crHandPoint;
}
//---------------------------------------------------------------------------
void __fastcall TfrmOpenProgram::imgHelpMouseEnter(TObject *Sender)
{
   // Cambia la apariencia del ratón: flecha por mano.
   imgHelp->Cursor = crHandPoint;
}
//---------------------------------------------------------------------------
void __fastcall TfrmOpenProgram::txtTrickMouseEnter(TObject *Sender)
{
   // Cambia la apariencia del ratón: flecha por mano.
   txtTrick->Cursor = crHandPoint;
}
//---------------------------------------------------------------------------
void __fastcall TfrmOpenProgram::txtTrickClick(TObject *Sender)
{
   // Oculta la línea de texto fija que sirve como truco para mostrar el botón 'Down'
   txtTrick->Visible = false;

   // Hace visible el botón 'Down';
   btnDown->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmOpenProgram::imgViewLogClick(TObject *Sender)
{
	DWORD status = 33;
	MessageDialog mdlg;

   // Abre el fichero de registro para su lectura
   status = (DWORD)ShellExecute(Application->Handle, L"open", GetFileNameLog(), NULL, NULL, SW_SHOWNORMAL);

   if(status <= 32)
     mdlg.error(L"Notice", L"Error opening file log.");
}
//---------------------------------------------------------------------------
void __fastcall TfrmOpenProgram::imgViewLogMouseEnter(TObject *Sender)
{
   // Cambia la apariencia del ratón: flecha por mano.
   imgViewLog->Cursor = crHandPoint;
}
//---------------------------------------------------------------------------
void __fastcall TfrmOpenProgram::chkboxActivateDTimeClick(TObject *Sender)
{
   if(chkboxActivateDTime->Checked)
     cbxDelayTime->Enabled = true;
   else
     cbxDelayTime->Enabled = false;
}
//---------------------------------------------------------------------------
// SIN USO
// Agrega 'null' al final de la lista de items
//   cftOperation->Items->Add(op_null);

