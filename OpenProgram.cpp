//---------------------------------------------------------------------------
// Programa : OpenProgram.cpp
// Autor    : Eugenio Mart�nez - torrentelinux@gmail.com - Agosto de 2016
// Prop�sito: Ejecutar una aplicaci�n, documento, URL, etc.,
//            seleccionada por el usuario mediante un cuadro de di�logo simple.
// Observac.: Para compilar desde la consola de texto debe ejecutar los siguientes pasos
//            1) Start Menu/Programs/Embarcadero RAD Studio 10.1 Berlin/RAD Studio Command Prompt
//            2) cd \RadStudio10.1\Projects
//            3) msbuild OpenProgram.cbproj /t:Build /p:Config=Release
//            4) Win32\Release\OpenProgram.exe
//
//            Ejecutar msbuild /h para conocer sus diferentes opciones
//            --------------------------------------------------------
//            Este programa es para Windows Vista/Server 2008 y versiones posteriores
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

   // Lee todos los argumentos pasados, a esta aplicaci�n, desde la l�nea de comandos
   args = CommandLineToArgvW(GetCommandLineW(), &nargs);

   // � Hay argumentos ?
   if(nargs > 1)
   {
     // Comprueba si se ha recibido la opci�n '/i'
     if(wcscmp(args[1], L"/i") == 0)
     {
       wostringstream msg;

       // Responde a la opci�n /i pasada desde la l�nea de comandos
       msg << L"OpenProgram.exe version 1.10.16.12\n"
           << L"Description: Opens a program, folder, document, or internet url.\n"
           << L"Author: Octulio Bilet�n\n"
           << L"Date and time of compilation: " << __DATE__ << ", " << __TIME__
           << ends;

       // Muestra informaci�n acerca de esta aplicaci�n
       status = dlgMessage.info(L"Information", msg.str().c_str());
     }
     else
       // Muestra un mensaje de error por opci�n incorrecta recibida
       status = dlgMessage.error(L"Error", L"Invalid argument !\nTry /i to show info dialog.");
   }
   // No hay argumentos, prosigue con la ejecuci�n de esta aplicaci�n
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

   // Termina y retorna al S.O. con el valor de 'status'
   return status;
}
//---------------------------------------------------------------------------
