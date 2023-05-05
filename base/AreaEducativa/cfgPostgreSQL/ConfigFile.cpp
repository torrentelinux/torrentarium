// ConfigFile.cpp
// Octulio Biletán * Mayo de 2023
// Modelo Educativo de aplicación para Windows.
// Define las funciones miembros de la clase TConfigFile.

#ifndef UNICODE
#define UNICODE
#endif

#include <vcl.h>
#include <stdio.h>
#include "ConfigFile.h"

TConfigFile::TConfigFile()
{
   fnombre_config = "";
}

TConfigFile::TConfigFile(String nm)
{
   fnombre_config = nm;
}

String TConfigFile::ReadString(const String value)
{
	String salida = L"";
	TCHAR dato[160] = { L"" };
	FILE *fichero = NULL;
	TCHAR *resultado = NULL;
        TCHAR *status = NULL;
	TCHAR *sign_igual = NULL;
	TCHAR *sign_com = NULL;

   fichero = _wfopen(fnombre_config.c_str(), L"rt");
   if(fichero == NULL)
     return "";

   while(!feof(fichero))
   {
     status = fgetws(dato, 160, fichero);
     if(status == NULL)
       break;

     if(*dato == '\n')
       continue;

     if(*dato == '#')
       continue;

     resultado = wcsstr(dato, value.c_str());
     if(resultado != NULL)
     {
       sign_igual = wcschr(resultado, '=');
       if(sign_igual != NULL)
       {
	 sign_com = wcschr(resultado, '#');
	 if(sign_com != NULL)
	 {
	   *sign_com = '\0';
           sign_igual++;

	   salida = sign_igual;
           salida = salida.Trim();
	   fclose(fichero);

	   return salida;
	 }
       }
     }
   }  // fin while()

   fclose(fichero);
   return "";
}