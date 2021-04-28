//---------------------------------------------------------------------------
// CentroAplicaciones.cpp
// Octulio Biletán - torrentelinux@gmail.com - Marzo de 2021.
// Centro de aplicaciones para productos Oracle.
// Dirigido para aquellos usuarios programadores y desarrolladores en
// lenguaje Java con nivel inicial a intermedio.
// Proyecto para Embarcadero RAD Studio 2010 y versiones posteriores.
// Coloque una firma digital:
// signtool.exe sign /a /fd SHA256 CentroAplicaciones.exe
// signtool.exe sign /a /t http://timestamp.digicert.com /fd SHA256 CentroAplicaciones.exe
// Referencias: https://docs.microsoft.com/es-es/dotnet/framework/tools/signtool-exe
//---------------------------------------------------------------------------
// Este programa fuente informático se acoge a la licencia GNU GPL v3
// https://www.gnu.org/licenses/gpl-3.0.en.html
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see https://www.gnu.org/licenses/
//----------------------------------------------------------------------------------

#include <vcl.h>
#include <tchar.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("caModulo.cpp", frmPrincipal);
//---------------------------------------------------------------------------
WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		TStyleManager::TrySetStyle("Glossy");
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
