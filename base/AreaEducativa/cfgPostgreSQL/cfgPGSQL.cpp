// cfgPGSQL.cpp
// Octulio Bilet�n * Mayo de 2023
// Modelo Educativo de aplicaci�n para Windows.

#include <vcl.h>
#include <tchar.h>
#include <windows.h>

#pragma hdrstop
#pragma argsused

int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
	return 1;
}

__declspec(dllexport) String ayudaGeneral(void)
{
   return "Pesta�a General";
}
