//---------------------------------------------------------------------------
// Encabezamiento: OpenProgramDefs.h
// Autor    : Eugenio Martínez - torrentelinux@gmail.com - Mayo de 2016
// Propósito: Definir las funciones auxiliares para OpenProgram
//---------------------------------------------------------------------------

#ifndef OpenProgramDefsH
#define OpenProgramDefsH
//---------------------------------------------------------------------------
#include <tchar.h>
#include <vcl.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <dir.h>
#pragma hdrstop

// Nro. de versión de OpenProgram.exe
#define __VERSION_op__	L"1.11.17.14"

// Estilo incorrecto
#define WRONG_STYLE     1

// Estilo correcto
#define OK_STYLE        -1

using namespace std;

// Operaciones admitidas por ShellExecute()
extern const unsigned short int op_edit      ;  // "edit"
extern const unsigned short int op_explore   ;  // "explore"
extern const unsigned short int op_find      ;  // "find"
extern const unsigned short int op_open      ;  // "open"
extern const unsigned short int op_print     ;  // "print"
extern const unsigned short int op_properties;  // "properties"
extern const unsigned short int op_null      ;

struct idPriorityClass
{
   DWORD dwId;
   UnicodeString Name;
};
extern idPriorityClass IdPriority[];

struct File_Exec
{
   HWND hwnd;
   UnicodeString Operation;
   UnicodeString File;
   UnicodeString Parameters;
   UnicodeString Directory;
   INT nShowCmd;
   DWORD dwProcessAffinityMask;
   DWORD dwPriorityClass;
   UINT Interval;
};

struct idTimeInterval
{
   unsigned int Interval;
};
extern struct idTimeInterval TimeTable[];
extern unsigned int nelemsTimeTable;

void ShowErrorCode(LPWSTR lpszMessage, DWORD dwECode);
void SaveLog(const _TCHAR *line_text);
void SaveLog(wstring &line_text);
_TCHAR *GetFileNameLog(void);
DWORD FileExec(__in_opt HWND hwnd, __in_opt LPCWSTR lpOperation, __in LPCWSTR lpFile, __in_opt LPCWSTR lpParameters, __in_opt LPCWSTR lpDirectory, __in INT nShowCmd);
DWORD FileExec(File_Exec *fe);

// Check the name of the indicated style
DWORD ValidarEstilo(_TCHAR *stl);

// Returns list of supported styles
_TCHAR *EstilosAdmitidos(void);

#endif
