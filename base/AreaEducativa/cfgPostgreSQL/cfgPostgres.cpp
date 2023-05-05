//---------------------------------------------------------------------------
// cfgPostgres.cpp
// Octulio Biletán * Mayo de 2023
// Modelo Educativo de aplicación para Windows.
// Permite hacer modificaciones sobre el archivo de configuración de PostgreSQL
// Fichero c:\Bitnami\wappstack-x.x.xx-x\postgresql\data\postgresql.conf
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>

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
