//---------------------------------------------------------------------------
// Programa : OpenProgram.cpp
// Autor    : Eugenio Martínez - torrentelinux@gmail.com - Agosto de 2016
// Propósito: Ejecutar una aplicación, documento, URL, etc.,
//            seleccionada por el usuario mediante un cuadro de diálogo simple.
// Observac.: Para compilar desde la consola de texto debe ejecutar los siguientes pasos
//            1) Start Menu/Programs/Embarcadero RAD Studio 10.1 Berlin/RAD Studio Command Prompt
//            2) cd \RadStudio10.1\Projects
//            3) msbuild OpenProgram.cbproj /t:Build /p:Config=Release
//            4) Win32\Release\OpenProgram.exe
//
//            Ejecutar msbuild /h para conocer sus diferentes opciones
//---------------------------------------------------------------------------

#include <tchar.h>
#include <vcl.h>
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
#pragma hdrstop

//---------------------------------------------------------------------------
USEFORM("OpenProgramDialog.cpp", frmOpenProgram);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
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
	return 0;
}
//---------------------------------------------------------------------------
