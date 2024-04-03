// Proyecto : SQLite_Ejemplo.cbproj
// Programa : SQLite_Ejemplo.cpp
// Autor    : Octulio Biletán * Marzo de 2024
// Propósito: Realizar una consulta a la base de datos 'ejemploSQLite.sdb'
// Obs.     : El lenguaje de consulta utilizado es SQLite v3.
// Refs.    : https://docwiki.embarcadero.com/RADStudio/Athens/en/Tutorial:_Connecting_to_a_SQLite_Database_from_a_VCL_Application
//---------------------------------------------------------------------------
#include <vcl.h>
#include <tchar.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("mdlPanelInfo.cpp", dlgPanelInfo);
USEFORM("mdlControles.cpp", frmControl); /* TFrame: File Type */
USEFORM("mdlGestorDatos.cpp", frmGestorDatos);
USEFORM("c:\program files (x86)\embarcadero\studio\19.0\ObjRepos\EN\Cpp\okcancl2.CPP", OKRightDlg);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TfrmGestorDatos), &frmGestorDatos);
		Application->CreateForm(__classid(TdlgPanelInfo), &dlgPanelInfo);
		Application->Run();
	}
	catch(Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch(...)
	{
		try
		{
			throw Exception("");
		}
		catch(Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
