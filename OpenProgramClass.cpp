//---------------------------------------------------------------------------
// Módulo   : OpenProgramClass.cpp
// Autor    : Eugenio Martínez - torrentelinux@gmail.com - Junio de 2016
// Propósito: Definir la clase DirectoryDialog para el programa OpenProgram que
//            ejecuta una aplicación, documento, URL, etc., seleccionada por el
//            usuario mediante un cuadro de diálogo simple.
//---------------------------------------------------------------------------
#include "OpenProgramClass.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)

DirectoryDialog::DirectoryDialog()
{
   DirName = L"";
   Title = L"";
}

DirectoryDialog::~DirectoryDialog()
{
// sin codigo aun...
}

bool DirectoryDialog::Execute(void)
{
	BROWSEINFO datos = { 0 };
        TCHAR dirsel[MAX_PATH+16] = { '\0' };

   datos.hwndOwner = Application->Handle;
   datos.pidlRoot = NULL;
   datos.pszDisplayName = dirsel;
   datos.lpszTitle = Title.c_str();
   datos.ulFlags = BIF_RETURNONLYFSDIRS;

   PIDLIST_ABSOLUTE idDirSel = SHBrowseForFolder(&datos);
   if(idDirSel == NULL)
     return false;

   SHGetPathFromIDList(idDirSel, dirsel);
   DirName = datos.pszDisplayName;

   if(idDirSel)
   {
     CoTaskMemFree(idDirSel);
   }

   return true;
}

MessageDialog::MessageDialog()
{
// sin codigo aun...
}

MessageDialog::~MessageDialog()
{
// sin codigo aun...
}

DWORD MessageDialog::error(const TCHAR *title, const TCHAR *msg)
{
     return Application->MessageBox(msg, title, MB_ICONERROR);
}

DWORD MessageDialog::info(const TCHAR *title, const TCHAR *msg)
{
     return Application->MessageBox(msg, title, MB_ICONINFORMATION);
}

DWORD MessageDialog::warning(const TCHAR *title, const TCHAR *msg)
{
     return Application->MessageBox(msg, title, MB_ICONWARNING);
}
