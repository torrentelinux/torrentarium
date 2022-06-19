// Programa: ClienteTCP.cpp
// Autor: Edmund Muslok -- Mayo de 2022.
// Propósito: Cliente de TCP que se comunica con un servidor TCP por el puerto asignado.
//            El nº de puerto puede ser cambiado durante la ejecución de ClienteTCP.EXE
// Observac.: Para Embarcadero RAD Studio 2010, 10.2, 10.4 y versiones superiores.
//---------------------------------------------------------------------------

#include <tchar.h>
#include <vcl.h>
//---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("cliente_tcp.cpp", frmClienteTCP);
USEFORM("cliente_config.cpp", DlgAjustes);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		TStyleManager::TrySetStyle("Glossy");
		Application->CreateForm(__classid(TfrmClienteTCP), &frmClienteTCP);
		Application->CreateForm(__classid(TDlgAjustes), &DlgAjustes);
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
