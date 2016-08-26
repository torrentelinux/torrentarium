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
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <dir.h>

using namespace std;

// Operaciones admitidas por ShellExecute()
extern const unsigned short int op_edit   ;  // "edit"
extern const unsigned short int op_explore;  // "explore"
extern const unsigned short int op_find   ;  // "find"
extern const unsigned short int op_open   ;  // "open"
extern const unsigned short int op_print  ;  // "print"
extern const unsigned short int op_null   ;

void ShowErrorCode(LPTSTR lpszMessage, DWORD dwECode);
void SaveLog(const _TCHAR *line_text);
void SaveLog(wstring &line_text);

#endif
