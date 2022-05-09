// Programa: ClienteTCP.cpp
// Autor: Edmund Muslok -- Mayo de 2022.
// Propósito: Cliente de TCP que se comunica con un servidor TCP por el puerto 337.
// Observac.: Para Embarcadero RadStudio 10.2 y versiones superiores.
//---------------------------------------------------------------------------

#include <tchar.h>
#include <vcl.h>
//---------------------------------------------------------------------------
USEFORM("cliente_tcp.cpp", frmClienteTCP);
USEFORM("cliente_config.cpp", DlgAjustes);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
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
