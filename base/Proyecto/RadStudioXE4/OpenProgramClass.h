//---------------------------------------------------------------------------
// Encabezamiento: OpenProgramClass.h
// Autor    : Eugenio Martínez - torrentelinux@gmail.com - Junio de 2016
// Propósito: Declarar la clase DirectoryDialog para el programa OpenProgram que
//            ejecuta una aplicación, documento, URL, etc., seleccionada por el
//            usuario mediante un cuadro de diálogo simple.
//---------------------------------------------------------------------------

#ifndef OpenProgramClassH
#define OpenProgramClassH

#include <tchar.h>
#include <vcl.h>
#include <ustring.h>
#include <shlobj.h>
#pragma hdrstop

class DirectoryDialog
{
   public:
	System::UnicodeString DirName;
	System::UnicodeString Title;

   public:
    	DirectoryDialog();
        ~DirectoryDialog();

        bool Execute(void);

};

class MessageDialog
{
   public:
   	MessageDialog();
        ~MessageDialog();

        DWORD error(const TCHAR *title = L"", const TCHAR *msg = L"");
        DWORD info(const TCHAR *title = L"", const TCHAR *msg = L"");
        DWORD warning(const TCHAR *title = L"", const TCHAR *msg = L"");
};
//---------------------------------------------------------------------------
#endif
