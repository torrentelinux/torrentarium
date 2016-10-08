//---------------------------------------------------------------------------
// Programa : OpenProgram.cpp
// Autor    : Eugenio Mart�nez - torrentelinux@gmail.com - Mayo de 2016
// Prop�sito: Ejecutar una aplicaci�n, documento, URL, etc.,
//            seleccionada por el usuario mediante un cuadro de di�logo simple.
//---------------------------------------------------------------------------

#include <tchar.h>
#include <vcl.h>
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
#pragma hdrstop

#include "OpenProgramDefs.h"
#include "OpenProgramClass.h"

//---------------------------------------------------------------------------
USEFORM("OpenProgramDialog.cpp", frmOpenProgram);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	MessageDialog dlgMessage;
	DWORD status = 0;
	int nargs;
        LPWSTR *args;

   args = CommandLineToArgvW(GetCommandLineW(), &nargs);

   if(nargs > 1)
   {
     if(wcscmp(args[1], L"/i") == 0)
     {
       wostringstream msg;

       // Responde a la opci�n /i pasada desde la l�nea de comandos
       msg << L"OpenProgram.exe version 1.10.16.10\n"
           << L"Description: Opens a program, folder, document, or internet url.\n"
           << L"Author: Octulio Bilet�n\n"
           << L"Date and time of compilation: " << __DATE__ << ", " << __TIME__
           << ends;

       status = dlgMessage.info(L"Information", msg.str().c_str());
     }
     else
       status = dlgMessage.error(L"Error", L"Invalid argument !\nTry /i to show info dialog.");
   }
   else
   {
     try
     {
       Application->Initialize();
       Application->MainFormOnTaskBar = true;
       TStyleManager::TrySetStyle("Luna");
       Application->CreateForm(__classid(TfrmOpenProgram), &frmOpenProgram);
       Application->Run();
     }

     catch (Exception &exception)
     {
	 Application->ShowException(&exception);
     }

     catch (...)
     {
       try
       {
	 throw Exception("");
       }

       catch (Exception &exception)
       {
	 Application->ShowException(&exception);
       }
     }
   }

   return status;
}
//---------------------------------------------------------------------------
