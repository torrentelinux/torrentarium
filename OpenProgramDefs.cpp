//---------------------------------------------------------------------------
// Módulo   : OpenProgramDefs.cpp
// Autor    : Eugenio Martínez - torrentelinux@gmail.com - Mayo de 2016
// Propósito: Definir las funciones auxiliares para OpenProgram
//---------------------------------------------------------------------------
#include "OpenProgramDefs.h"
#include "OpenProgramDialog.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

// Contiene el nombre completo del fichero registro: OpenProgram.log
static _TCHAR fi_log[256] = { '\0' };

// Operaciones admitidas por ShellExecute()/ShellExecuteEx()
const unsigned short int op_edit       = 0;  // "edit"
const unsigned short int op_explore    = 1;  // "explore"
const unsigned short int op_find       = 2;  // "find"
const unsigned short int op_open       = 3;  // "open"
const unsigned short int op_print      = 4;  // "print"
const unsigned short int op_properties = 5;  // "properties"
const unsigned short int op_null       = 6;

// Valores admitidos para la prioridad del proceso
idPriorityClass IdPriority[] = { NORMAL_PRIORITY_CLASS, L"Normal",
                                 IDLE_PRIORITY_CLASS, L"Idle",
                                 HIGH_PRIORITY_CLASS, L"High",
                                 REALTIME_PRIORITY_CLASS, L"Realtime",
                                 BELOW_NORMAL_PRIORITY_CLASS, L"Below normal",
                                 ABOVE_NORMAL_PRIORITY_CLASS, L"Above normal"
                               };

// Tabla de intervalos de tiempos (milisegs.) para Sleep()
idTimeInterval TimeTable[] = {  125,
                                250,
                                375,
                                500,
                                625,
                                750,
                                875,
                                1000
                             };

// Cantidad de elementos que posee la tabla de tiempos
unsigned int nelemsTimeTable = sizeof(TimeTable) / sizeof(TimeTable[0]);

// Inglés/Usa
#define FormatMessage_USA 0x0409
#define Text_Usa TEXT(" %s failed with error code %d: %s")

// Español/Argentina
#define FormatMessage_Arg 0x2c0a
#define Text_Arg TEXT(" %s ha fallado con código de error %d: %s")

void ShowErrorCode(LPWSTR lpszMessage, DWORD dwECode)
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

// Devuelve el nombre completo del fichero de registro
_TCHAR *GetFileNameLog(void)
{
   return fi_log;
}

// Guarda una línea de texto de tipo 'wstring' en OpenProgram.log
void SaveLog(wstring &line_text)
{
   SaveLog(line_text.c_str());
}

// Guarda una línea de texto de tipo '_TCHAR *', si es posible, en %localappdata%\Registro\OpenProgram.log
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

   // Guarda el nombre completo del fichero registro en 'fi_log'
   wcscpy(fi_log, ofn.str().c_str());

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

// Ejecuta el objeto seleccionado por el usuario mediante ShellExecuteEx()
// y no cambia la prioridad/afinidad del proceso convocado.
DWORD FileExec(__in_opt HWND hwnd, __in_opt LPCWSTR lpOperation, __in LPCWSTR lpFile, __in_opt LPCWSTR lpParameters, __in_opt LPCWSTR lpDirectory, __in INT nShowCmd)
{
	DWORD status = 0;
	SHELLEXECUTEINFO seInfo = { 0 };

   seInfo.cbSize = sizeof(SHELLEXECUTEINFO);

// --- Flags ---
// SEE_MASK_FLAG_NO_UI:
// Do not display an error message box if an error occurs.
// SEE_MASK_INVOKEIDLIST:
// This flag allows applications to use ShellExecuteEx to invoke verbs from
// shortcut menu extensions instead of the static verbs listed in the registry.
// SEE_MASK_NOCLOSEPROCESS:
// Use to indicate that the 'hProcess' member receives the process handle.
// This handle is typically used to allow an application to find out when a
// process created with ShellExecuteEx terminates.
// ------
   seInfo.fMask = SEE_MASK_NOCLOSEPROCESS | SEE_MASK_INVOKEIDLIST | SEE_MASK_FLAG_NO_UI;

   seInfo.hwnd = hwnd;
   seInfo.lpVerb = lpOperation;
   seInfo.lpFile = lpFile;
   seInfo.lpParameters = lpParameters;
   seInfo.lpDirectory = lpDirectory;
   seInfo.nShow = nShowCmd;

   ShellExecuteEx(&seInfo);
   status = (DWORD)seInfo.hInstApp;

   return status;
}

// Ejecuta el objeto seleccionado por el usuario mediante ShellExecuteEx()
// y cambia la prioridad/afinidad del proceso convocado.
DWORD FileExec(File_Exec *fe)
{
	DWORD status = 0;
	SHELLEXECUTEINFO seInfo = { 0 };

   // Comprueba la validez del puntero 'fe'
   if(fe == NULL)
   {
     // Error por puntero nulo
     ::SetLastError(ERROR_INVALID_HANDLE);
     return ERROR_INVALID_HANDLE;
   }
   else
     // Comprueba la validez de la máscara de afinidad
     if(fe->dwProcessAffinityMask > MAXIMUM_PROCESSORS)
     {
       // Error por afinidad
       ::SetLastError(ERROR_INVALID_DATA);
       return ERROR_INVALID_DATA;
     }
     else
       // Comprueba la validez de la prioridad
       if(fe->dwPriorityClass < NORMAL_PRIORITY_CLASS || fe->dwPriorityClass > ABOVE_NORMAL_PRIORITY_CLASS)
       {
         // Error por prioridad
         ::SetLastError(ERROR_INVALID_PRIORITY);
         return ERROR_INVALID_PRIORITY;
       }
       else
         // No hay error
         ::SetLastError(ERROR_SUCCESS);

   seInfo.cbSize = sizeof(SHELLEXECUTEINFO);

// --- Flags ---
// SEE_MASK_FLAG_NO_UI:
// Do not display an error message box if an error occurs.
// SEE_MASK_INVOKEIDLIST:
// This flag allows applications to use ShellExecuteEx to invoke verbs from
// shortcut menu extensions instead of the static verbs listed in the registry.
// SEE_MASK_NOCLOSEPROCESS:
// Use to indicate that the 'hProcess' member receives the process handle.
// This handle is typically used to allow an application to find out when a
// process created with ShellExecuteEx terminates.
// ------
   seInfo.fMask = SEE_MASK_NOCLOSEPROCESS | SEE_MASK_INVOKEIDLIST | SEE_MASK_FLAG_NO_UI;

   seInfo.hwnd = fe->hwnd;
   seInfo.lpVerb = fe->Operation.c_str();
   seInfo.lpFile = fe->File.c_str();
   seInfo.lpParameters = fe->Parameters.c_str();
   seInfo.lpDirectory = fe->Directory.c_str();
   seInfo.nShow = fe->nShowCmd;

   ShellExecuteEx(&seInfo);
   status = (DWORD)seInfo.hInstApp;
   wchar_t temp[80] = { L"" };

   if(seInfo.hProcess)
     if(wcscmp(_wcslwr(wcscpy(temp, seInfo.lpVerb)), L"open") == 0)
     {
       // Opcional: Realiza una breve pausa (entre 125 y 1000 milisegundos)
       // antes de modificar la prioridad y la afinidad del proceso recién lanzado.
       // *** Le doy tiempo al nuevo proceso para que se acomode en memoria ***
       if(fe->Interval > 0)
         Sleep(fe->Interval);

       // Modifica la prioridad del proceso recién lanzado.
       SetPriorityClass(seInfo.hProcess, fe->dwPriorityClass);

       // Modifica la asignación de CPU al proceso recién lanzado.
       SetProcessAffinityMask(seInfo.hProcess, fe->dwProcessAffinityMask);
     }

   return status;
}

