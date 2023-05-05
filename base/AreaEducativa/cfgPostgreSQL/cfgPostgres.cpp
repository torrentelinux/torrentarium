//---------------------------------------------------------------------------
// Programa: cfgPostgres.cpp
// Autor: Octulio Biletán * Mayo de 2023
// Propósito:
// Permite hacer modificaciones sobre el archivo de configuración de PostgreSQL.
// Fichero c:\Bitnami\wappstack-x.x.xx-x\postgresql\data\postgresql.conf
// Modelo Educativo de aplicación para Windows.
// Compilador C++: Embarcadero C++ Builder 10.2 para Windows.
//---------------------------------------------------------------------------

#include <vcl.h>
#include <tchar.h>
#pragma hdrstop

//---------------------------------------------------------------------------
USEFORM("formPrincipal.cpp", frmPrincipal);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TfrmPrincipal), &frmPrincipal);
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
