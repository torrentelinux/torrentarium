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
	DWORD status = -1;
	int nargs = 0;
	MessageDialog dlgMessage;
        _TCHAR nombre_estilo[64] = L"Sky";
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
#ifdef __WIN32__
       _TCHAR *platform = L"32-bit Windows.";
#else
#  ifdef _WIN64
       _TCHAR *platform = L"64-bit Windows.";
#  else
       _TCHAR *platform = L"unknown.";
#  endif
#endif

       // Responde a la opci�n /i pasada desde la l�nea de comandos
       msg << L"OpenProgram.exe version " __VERSION_op__ "\n"
           << L"Description: Opens a program, folder, document, or internet url.\n\n"
           << L"Argument supported: /s <style_name>\n"
           << L"Where <style_name> is: " << EstilosAdmitidos() << L".\n"
           << L"Sets the graphic style specified by the user.\n\n"
           << L"Author: Octulio Bilet�n.\n"
           << L"Platform: " << platform << "\n"
           << L"Date and time of compilation: " << __DATE__ << ", " << __TIME__
           << ends;

       // Muestra informaci�n acerca de esta aplicaci�n y termina su ejecuci�n
       status = dlgMessage.info(L"Information", msg.str().c_str());
     }
     else
       // Comprueba si se ha recibido la opci�n '/s'
       if(wcscmp(args[1], L"/s") == 0)
       {
         status = ValidarEstilo(args[2]);
         if(status == WRONG_STYLE)
         {
           wostringstream msg;
           msg << "Incorrect: " << args[2] << "\nSupported styles: " << EstilosAdmitidos() << L"." << ends;

           status = dlgMessage.error(L"Error", msg.str().c_str());
         }
         else
           wcscpy(nombre_estilo, args[2]);
       }
       else
         // Muestra un mensaje de error por opci�n incorrecta recibida y sale de la aplicaci�n
         status = dlgMessage.error(L"Error", L"Invalid argument !\nTry /i to show info dialog.");
   }

   // Prosigue con la ejecuci�n de esta aplicaci�n
   if(status == OK_STYLE)
   {
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		TStyleManager::TrySetStyle(nombre_estilo);
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
