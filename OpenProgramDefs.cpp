//---------------------------------------------------------------------------
// Módulo   : OpenProgramDefs.cpp
// Autor    : Eugenio Martínez - torrentelinux@gmail.com - Mayo de 2016
// Propósito: Definir las funciones auxiliares para OpenProgram
//---------------------------------------------------------------------------
#include <windows.h>
#pragma hdrstop

#include "OpenProgramDefs.h"
#include "OpenProgramDialog.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

// Operaciones admitidas por ShellExecute()
const unsigned short int op_edit    = 0;  // "edit"
const unsigned short int op_explore = 1;  // "explore"
const unsigned short int op_find    = 2;  // "find"
const unsigned short int op_open    = 3;  // "open"
const unsigned short int op_print   = 4;  // "print"
const unsigned short int op_null    = 5;

// Inglés/Usa
#define FormatMessage_USA 0x0409
#define Text_Usa TEXT(" %s failed with error code %d: %s")

// Español/Argentina
#define FormatMessage_Arg 0x2c0a
#define Text_Arg TEXT(" %s ha fallado con código de error %d: %s")

void ShowErrorCode(LPTSTR lpszMessage, DWORD dwECode)
{
    	LPVOID lpMsgBuf = NULL;
    	LPVOID lpDisplayBuf = NULL;

   FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
                 NULL, dwECode, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                 (LPTSTR) &lpMsgBuf, 0, NULL);

   lpDisplayBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT,
                                     (lstrlen((LPCTSTR)lpMsgBuf) +
                                     lstrlen((LPCTSTR)lpszMessage) + 80) *
                                     sizeof(TCHAR));

   LANGID liCode = GetSystemDefaultLangID();
   if(liCode == FormatMessage_Arg)
     wsprintf((LPTSTR)lpDisplayBuf, Text_Arg, lpszMessage, dwECode, lpMsgBuf);
   else
     wsprintf((LPTSTR)lpDisplayBuf, Text_Usa, lpszMessage, dwECode, lpMsgBuf);

   frmOpenProgram->txtErrorMsg->Caption = (LPCTSTR)lpDisplayBuf;

   LocalFree(lpMsgBuf);
   LocalFree(lpDisplayBuf);
}

void SaveLog(wstring &line_text)
{
   SaveLog(line_text.c_str());
}
// Guarda una línea de texto, si es posible, en %localappdata%\Registro\OpenProgram.log
// sino en el directorio actual .\OpenProgram.log
void SaveLog(const _TCHAR *line_text)
{
	int status = 0;
	int flag = 0;
	MessageDialog mdbox;
   	wofstream salida;
     	wostringstream newdir, ofn;
        wstring filename = L"OpenProgram.log";
        _TCHAR data[256] = { L"" };

   status = GetEnvironmentVariable(L"LOCALAPPDATA", data, 256);

   if(status == 0)  // Si la variable no existe ...
     flag = 1;      // La variable no existe
   else
   {
     newdir << data << L"\\Registro" << ends;  // Se prepara para crear el directorio 'Registro'

     if(DirectoryExists(newdir.str().c_str()))  // ¿ El directorio existe ?
       flag = 2;  // La variable existe
     else
     {
       status = _wmkdir(newdir.str().c_str());  // Crea el directorio 'Registro'
       if(status == 0)  // Si se creó exitosamente ...
         flag = 2;
       else
         flag = 1;
     }
   }

   if(flag == 1)
     ofn << filename.c_str() << ends;  // Se prepara para abrir OpenProgram.log en el directorio vigente
   else
     ofn << newdir.str().c_str() << L"\\" << filename.c_str() << ends;  // Construye la trayectoria completa a OpenProgram.log

   // Abre el fichero
   salida.open(ofn.str().c_str(), ios_base::app);
   if(!salida)
     // Se ha producido un error en la apertura del fichero
     mdbox.error(ofn.str().c_str(), L"ERROR: The file was not opened.");
   else
   {
     // Guarda la línea de texto en el fichero
     salida << line_text << endl;

     if(!salida)
       // Se ha producido un error en la actualización del fichero
       mdbox.error(ofn.str().c_str(), L"ERROR: The file was not updated.");
   }

   // Cierra el fichero
   salida.close();
}

