// cfgPGSQL.cpp
// Octulio Bilet�n * Mayo de 2023
// Definiciones de las funciones: ayudaGeneral().
// Modelo Educativo de aplicaci�n para Windows.
// Forma parte del proyecto cfgPG.cbproj

#include <vcl.h>
#include <tchar.h>
#include <windows.h>

#pragma hdrstop
#pragma argsused

int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
	return 1;
}

// Devuelve el texto de ayuda correspondiente a la pesta�a General de la aplicaci�n cfgPostgres.exe
__declspec(dllexport) String ayudaGeneral(void)
{
   return "Pesta�a General";
}
