// Proyecto: Ejemplo1.cbproj
// Programa: Ejemplo1.cpp
// Librería: JLogo.cpp
// Versión : 1.0
// Depende.: Embarcadero Studio ver. 22.0, VCL ver. 28.0.47991.2819, Alexandria, 64 bits.
// Autor   : Octulio Biletán * Octubre de 2025.
// Descrip.: Implementar la función WinMain() y dar comienzo a la lógica del 1er. ejemplo de JLogo.
// Ambiente: Windows, modo gráfico, 64 bits.
// Licencia: Software libre.

//---------------------------------------------------------------------------
#include <vcl.h>
#include <tchar.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("frmPrincipal.cpp", frmCentral);
//---------------------------------------------------------------------------
int codigo_salida;

void AvisoSalida(void)
{
   String datos = "Examinar: ";
   datos = datos + codigo_salida;

   Application->MessageBox(datos.c_str(), L"Información", MB_ICONINFORMATION);
}

int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	codigo_salida = 0;

	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->Title = "JLogo";
		Application->CreateForm(__classid(TfrmCentral), &frmCentral);
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

	return codigo_salida;
}
//---------------------------------------------------------------------------
