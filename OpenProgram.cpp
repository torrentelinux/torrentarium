//---------------------------------------------------------------------------
// Programa : OpenProgram.cpp
// Autor    : Eugenio Mart�nez - torrentelinux@gmail.com - Mayo de 2016
// Prop�sito: Ejecutar una aplicaci�n, documento, URL, etc.,
//            seleccionada por el usuario mediante un cuadro de di�logo simple.
//---------------------------------------------------------------------------

#include <tchar.h>
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
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
