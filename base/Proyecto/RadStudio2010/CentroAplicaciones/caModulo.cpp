// Módulo     : caModulo.cpp
// Autor      : Octulio Biletán - torrentelinux@gmail.com - Marzo de 2021.
// Descripción: Centro de aplicaciones para productos Oracle.
// Utilitario para realizar instalaciones con ficheros .zip
// Dirigido para aquellos usuarios programadores y desarrolladores en
// lenguaje Java con nivel inicial a intermedio.
//
// Referencias:
// Aplicación 7za.exe :: https://www.7-zip.org/
// Comando rundll32 :: https://docs.microsoft.com/es-es/windows-server/administration/windows-commands/rundll32
// Comandos para modificar PATH :: https://www.java.com/es/download/help/path.html
//
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
#include <tchar.h>
#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "caModulo.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TfrmPrincipal *frmPrincipal;

//---------------------------------------------------------------------------
__fastcall TfrmPrincipal::TfrmPrincipal(TComponent* Owner) : TForm(Owner)
{
   for(int i = 0; i < 16; i++)
   {
     instalador[i] = "";
     aplics[i] = "";
   }

   aplics[0] = lblAplic1->Caption;
   aplics[1] = lblAplic2->Caption;
   aplics[2] = lblPath->Caption;
   aplics[3] = lblJava->Caption;
   aplics[4] = lblRevisarPath->Caption;

   // Ubicación predeterminada de productos Oracle
   // -- c:\Oracle\Middleware\Oracle_Home --
   dlgAbrirDir->FileName = L"c:\\Oracle\\Middleware\\Oracle_Home";
   frmPrincipal->Height = 330;
   sbBarraDeEstado->SimpleText = L"Un click cierra la ayuda.";
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::lblAplic1Click(TObject *Sender)
{
   // Inicia la instalación de Java SDK
	HINSTANCE error_shell = 0;

   if(instalador[0].Length() > 0)
   {
     sbBarraDeEstado->SimpleText = L"Iniciando " + instalador[0];

     // Abre la aplicación que se indica en 'instalador' sin sus parámetros
     error_shell = ShellExecute(NULL, L"open", instalador[0].c_str(), NULL, NULL, SW_SHOWNORMAL);
     if((int)error_shell <= 32)
     {
	  String condicion;

       condicion = L"Error " + String((int)error_shell) + L" en:\n" + instalador[0].c_str();
       ShowMessage(condicion);

       sbBarraDeEstado->SimpleText = L"Error.";
     }
     else
     {
       Sleep(950);
       sbBarraDeEstado->SimpleText = L"Aplicación iniciada.";
     }
   }
   else
     ShowMessage(L"ERROR: Primero debe configurar ésta aplicación.");
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::lblAplic1MouseEnter(TObject *Sender)
{
   lblAplic1->Caption = L"► " + lblAplic1->Caption;

   lblAplic1->Font->Color = clBlue;
   lblAplic1->Font->Style = TFontStyles() << fsUnderline;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::lblAplic1MouseLeave(TObject *Sender)
{
   lblAplic1->Caption = aplics[0];

   lblAplic1->Font->Color = clWindowText;
   lblAplic1->Font->Style = TFontStyles();
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::ButtonGroup1Items0Click(TObject *Sender)
{
   // Configura la aplicación Java JDK
   	String var_usrprofile;

   var_usrprofile = getenv("USERPROFILE");
   dlgAbrirFichero->DefaultFolder = var_usrprofile + L"\\downloads";
   dlgAbrirFichero->FileTypeIndex = 1;

   if(dlgAbrirFichero->Execute())
   {
     instalador[0] = dlgAbrirFichero->FileName;
   }
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::grpBotonesItems1Click(TObject *Sender)
{
   // Configura la aplicación para JDeveloper
   	String var_usrprofile;

   var_usrprofile = getenv("USERPROFILE");
   dlgAbrirFichero->DefaultFolder = var_usrprofile + L"\\downloads";
   dlgAbrirFichero->FileTypeIndex = 2;

   if(dlgAbrirFichero->Execute())
   {
     instalador[1] = dlgAbrirFichero->FileName;
   }
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::ButtonGroup1Items1Click(TObject *Sender)
{
   // Sale de la aplicación
   Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::lblAplic2Click(TObject *Sender)
{
   // Inicia la instalación de JDeveloper
   	int status;
	HINSTANCE error_shell = 0;
	String parametros;

   if(instalador[1].Length() > 0)
   {
     sbBarraDeEstado->SimpleText = L"Iniciando " + instalador[1];

     // Directorio predeterminado
     dlgAbrirDir->DefaultFolder = L"c:\\";

     // Preguntar por el directorio destino...
     if(dlgAbrirDir->Execute())
       parametros = L"x -o" + dlgAbrirDir->FileName + L" " + instalador[1];
     else
       parametros = L"x -oc:\\ " + instalador[1];

     status = Application->MessageBox(parametros.c_str(), L"Confirmar", MB_OKCANCEL|MB_ICONINFORMATION);
     if(status == IDCANCEL)
     {
       sbBarraDeEstado->SimpleText = L"Operación cancelada.";
       return;
     }

     // Abre la aplicación 7za con sus parámetros y el archivo a descomprimir
     error_shell = ShellExecute(NULL, L"open", L"7za.exe", parametros.c_str(), NULL, SW_SHOWNORMAL);
     if((int)error_shell <= 32)
     {
          String condicion;

       condicion = L"Error " + String((int)error_shell) + L" con 7za.exe: " + parametros.c_str();
       ShowMessage(condicion);

       sbBarraDeEstado->SimpleText = L"Error.";
     }
     else
     {
       Sleep(997);
       sbBarraDeEstado->SimpleText = L"-1-Aplicación iniciada.";

       // Crea un archivo como acceso directo (.lnk) a jdeveloper.exe en el escritorio.
       parametros = String(L"JDev12c.lnk") + L" " +
                    dlgAbrirDir->FileName + L"\\jdeveloper\\" + L"jdeveloper.exe" + L" " +
                    dlgAbrirDir->FileName + L"\\jdeveloper\\" + L" " +
                    L"\"Oracle JDeveloper 12c\"";

       error_shell = ShellExecute(NULL, L"open", L"wCrearAtajo.vbs", parametros.c_str(), NULL, SW_SHOWNORMAL);
       if((int)error_shell <= 32)
       {
         ShowMessage(L"No se pudo crear acceso directo en el escritorio.");
         sbBarraDeEstado->SimpleText = L"Error al crear acceso directo.";
       }
       else
       {
         Sleep(750);
         sbBarraDeEstado->SimpleText = L"-2-Aplicación iniciada.";
       }
     }
   }
   else
     ShowMessage(L"ERROR: Primero debe configurar ésta aplicación.");
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::lblAplic2MouseEnter(TObject *Sender)
{
   lblAplic2->Caption = L"► " + lblAplic2->Caption;

   lblAplic2->Font->Color = clBlue;
   lblAplic2->Font->Style = TFontStyles() << fsUnderline;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::lblAplic2MouseLeave(TObject *Sender)
{
   lblAplic2->Caption = aplics[1];

   lblAplic2->Font->Color = clWindowText;
   lblAplic2->Font->Style = TFontStyles();
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::lblPathClick(TObject *Sender)
{
   // Invocar para realizar ajustes en PATH:
   // rundll32.exe sysdm.cpl,EditEnvironmentVariables --> abre la ventana 'Environment Variables'.
	HINSTANCE error_shell = 0;
	String parametros;

     sbBarraDeEstado->SimpleText = L"Iniciando ajuste de variables de entorno.";

     parametros = L"sysdm.cpl,EditEnvironmentVariables";

     // Abre la aplicación rundll32 con sus parámetros
     error_shell = ShellExecute(NULL, L"open", L"rundll32.exe", parametros.c_str(), NULL, SW_SHOWNORMAL);
     if((int)error_shell <= 32)
     {
          String condicion;

       condicion = L"Error " + String((int)error_shell) + L" en: " + parametros.c_str();
       ShowMessage(condicion);

       sbBarraDeEstado->SimpleText = L"Error.";
     }
     else
     {
       Sleep(950);
       sbBarraDeEstado->SimpleText = L"Aplicación iniciada.";
     }
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::lblPathMouseEnter(TObject *Sender)
{
   lblPath->Caption = L"► " + lblPath->Caption;

   lblPath->Font->Color = clBlue;
   lblPath->Font->Style = TFontStyles() << fsUnderline;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::lblPathMouseLeave(TObject *Sender)
{
   lblPath->Caption = aplics[2];

   lblPath->Font->Color = clWindowText;
   lblPath->Font->Style = TFontStyles();
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::FormDblClick(TObject *Sender)
{
   mmAyuda->Visible = true;
   sbBarraDeEstado->SimpleText = L"Un click cierra la ayuda.";
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::FormClick(TObject *Sender)
{
   mmAyuda->Visible = false;
   sbBarraDeEstado->SimpleText = L"Doble click abre la ayuda.";
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::lblJavaMouseEnter(TObject *Sender)
{
   lblJava->Caption = L"► " + lblJava->Caption;

   lblJava->Font->Color = clBlue;
   lblJava->Font->Style = TFontStyles() << fsUnderline;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::lblJavaMouseLeave(TObject *Sender)
{
   lblJava->Caption = aplics[3];

   lblJava->Font->Color = clWindowText;
   lblJava->Font->Style = TFontStyles();
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::lblJavaClick(TObject *Sender)
{
   // Visita el sitio www.java.com
	HINSTANCE error_shell = 0;

     sbBarraDeEstado->SimpleText = L"Ingresando a www.java.com";

     // Abre la aplicación navegador sin sus parámetros
     error_shell = ShellExecute(NULL, L"open", L"https://www.java.com/es/", NULL, NULL, SW_SHOWNORMAL);
     if((int)error_shell <= 32)
     {
          String condicion;

       condicion = L"Error " + String((int)error_shell) + L" en: navegador.";
       ShowMessage(condicion);

       sbBarraDeEstado->SimpleText = L"Error.";
     }
     else
     {
       Sleep(950);
       sbBarraDeEstado->SimpleText = L"Aplicación iniciada.";
     }
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::lblRevisarPathClick(TObject *Sender)
{
   // Hace una consulta a la variable PATH mediante comando 'set'
	HINSTANCE error_shell = 0;
	String parametros;

     sbBarraDeEstado->SimpleText = L"Revisando contenido de PATH";
     parametros = L"/c echo ::Contenido de Path::&echo.&set path&echo.&pause";

     // Abre la aplicación navegador sin sus parámetros
     error_shell = ShellExecute(NULL, L"open", L"cmd.exe", parametros.c_str(), NULL, SW_SHOWNORMAL);
     if((int)error_shell <= 32)
     {
          String condicion;

       condicion = L"Error " + String((int)error_shell) + L" en: consola.";
       ShowMessage(condicion);

       sbBarraDeEstado->SimpleText = L"Error.";
     }
     else
     {
       Sleep(950);
       sbBarraDeEstado->SimpleText = L"Aplicación iniciada.";
     }
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::lblRevisarPathMouseEnter(TObject *Sender)
{
   lblRevisarPath->Caption = L"► " + lblRevisarPath->Caption;

   lblRevisarPath->Font->Color = clBlue;
   lblRevisarPath->Font->Style = TFontStyles() << fsUnderline;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::lblRevisarPathMouseLeave(TObject *Sender)
{
   lblRevisarPath->Caption = aplics[4];

   lblRevisarPath->Font->Color = clWindowText;
   lblRevisarPath->Font->Style = TFontStyles();
}
//---------------------------------------------------------------------------
