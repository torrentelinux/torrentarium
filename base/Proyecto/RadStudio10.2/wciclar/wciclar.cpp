//---------------------------------------------------------------------------
// Programa   : wciclar.cpp
// Autor      : eugenio martínez - mayo de 2006
// Descripción: consume ciclos de cpu durante un cierto tiempo.
//              optimizado para CPU Intel Pentium, aplicación para Windows.
//              se ha agregado la característica de ventana translúcida.
//              última vez modificado en febrero de 2020.
// Licencia   : Copyright (C) 2006-2020 - Eugenio Martinez - torrentelinux@gmail.com
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//---------------------------------------------------------------------------

#define STRICT

#include <windows.h>
#include <tchar.h>
#include <mmsystem.h>

#include <cstring>
#include <strstream>
#include <sstream>
#include <fstream>
#include <iomanip>

#include <except.h>
#include <stdlib.h>
#include <mem.h>
#include <dos.h>
#include <process.h>

#pragma hdrstop

#include "cronometro.h"
#include "wciclar.h"
#include "wciclar.rh"
//---------------------------------------------------------------------------

void ejecutar(const char *prog, const char *args)
{
		char *var_temp;
		char ftemp[256];
		ofstream salida;

   var_temp = getenv("TEMP");
   if(var_temp)
   {
	 strcpy(ftemp, var_temp);
	 strcat(ftemp, "\\wciclar0.tmp");
   }
   else
     strcpy(ftemp, "\\wciclar0.tmp");

   salida.open(ftemp);
   salida << args;
   salida.close();

   execlp(prog, prog, ftemp, NULL);
}

// Muestra una breve ayuda en una ventana simple.
void mostrar_ayuda()
{
        char *msj = "wciclar reconoce los siguientes argumentos:\n"
                    "\tlicencia -- muestra en el Bloc de notas la licencia GNU/GPL.\n"
                    "\tayuda    -- muestra esta ayuda.";

   MessageBox(NULL, msj, "Ayuda", MB_OK|MB_ICONINFORMATION);
   exit(EXIT_SUCCESS);
}

// Muestra un mensaje de error en una ventana simple.
void error_opcion()
{
        char *msj ="Argumento no válido\n"
                   "Haga \"wciclar ayuda\"\n"
                   "Para conocer los argumentos reconocidos.";

   MessageBox(NULL, msj, "Aviso", MB_OK|MB_ICONERROR);
   exit(EXIT_FAILURE);
}

void LeerArgumentos()
{
   if(_argc > 1)
   {
     if(strcmp(_argv[1], "licencia") == 0)
       ejecutar(BlocDeNotas, GNU_gpl);
	 else
       if(strcmp(_argv[1], "ayuda") == 0)
         mostrar_ayuda();
       else
         error_opcion();
   }
}

template <class T> char *FormatearNumero(T nro)
{
        int estado;
        static char tmp[128];
        char nro_frmt[128] = { "" };
	ostrstream salida_frmt(nro_frmt, 128);

   salida_frmt.seekp(0, ios::beg);

   setmem(tmp, 128, '\0');

   salida_frmt << nro << ends;

   estado = GetNumberFormat(LOCALE_USER_DEFAULT, 0, salida_frmt.str(), NULL, tmp, 128);
   if(estado == 0)
     return " ";

   return tmp;
}

// Calcula la diferencia de tiempos --  resultado = Tiempo2 - Tiempo1
// Devuelve 'resultado'
LPSYSTEMTIME DifTiempo(LPSYSTEMTIME Tiempo2, LPSYSTEMTIME Tiempo1)
{
        FILETIME ficheroTiempo1 = { 0, 0 };
        FILETIME ficheroTiempo2 = { 0, 0 };
        ULARGE_INTEGER ficheroTiempo1Entero = {{ 0,0 }};
        ULARGE_INTEGER ficheroTiempo2Entero = {{ 0,0 }};
        static SYSTEMTIME resultado;

   memset(&resultado, 0, sizeof(SYSTEMTIME));

   SystemTimeToFileTime(Tiempo1, &ficheroTiempo1);
   SystemTimeToFileTime(Tiempo2, &ficheroTiempo2);

   ficheroTiempo1Entero = *(PULARGE_INTEGER) &ficheroTiempo1;
   ficheroTiempo2Entero = *(PULARGE_INTEGER) &ficheroTiempo2;

   ficheroTiempo2Entero.QuadPart -= ficheroTiempo1Entero.QuadPart;

   ficheroTiempo2 = *(PFILETIME) &ficheroTiempo2Entero;
   FileTimeToSystemTime(&ficheroTiempo2, &resultado);

   return &resultado;
}

// Redibuja el area de la ventana
LRESULT Ventana(HWND idv)
{
        static unsigned int i = 0;
        PAINTSTRUCT ps;
        HDC hdc;
        RECT r;

   hdc = BeginPaint(idv, &ps);

   wmem << "vlt: " << FormatearNumero(acumulador) << endl;

   wmem << "vps: " << FormatearNumero(muestra[imuestra].vps) << separador;

   wmem << "cwh: " << FormatearNumero(muestra[imuestra].ciclos_while) << endl
        << "cme: " << muestra[imuestra].estado_memoria.dwMemoryLoad << " %" << separador;

   wmem << "est: " << FormatearNumero(estabilidad) << condicion_estabilidad << endl;

   wmem << "pri: " << wciclar_ini.escala << separador;
   wmem << "ttw: " << FormatearNumero(ttw) << " \'" << endl;

   wmem << "usr: " << usuario_y_terminal << ends;

   // Obtiene el área rectangular de la ventana cliente
   GetClientRect(idv, &r);
   r.left = r.top = 8;

   // Establece el color del texto
   SetBkColor(hdc, color_fondo);
   SetTextColor(hdc, color_texto);

   // escribe el texto en la ventana
   DrawText(hdc, wmem.str().c_str(), strlen(wmem.str().c_str()), &r, DT_EXPANDTABS);

   // Traza una línea horizontal
   MoveToEx(hdc, r.left, r.bottom - 28, NULL);
   LineTo(hdc, r.right, r.bottom - 28);

   HFONT hfnt = (HFONT)GetStockObject(ANSI_VAR_FONT);
   HFONT hOldFont = (HFONT)SelectObject(hdc, hfnt);
   if(hOldFont)
   {
     wmem.seekp(0, ios::beg);
     wmem << wciclar_ini.recurso_texto[i] << ends;

     r.top = r.bottom - 24;
     DrawText(hdc, wmem.str().c_str(), strlen(wmem.str().c_str()), &r, DT_EXPANDTABS);

     SelectObject(hdc, hOldFont);
   }

   ValidateRect(idv, NULL);
   EndPaint(idv, &ps);

   wmem.seekp(0, ios::beg);

   i++;
   if(i == max_recurso_texto)
     i = 0;

   return 0;
}

// Finaliza la aplicación
LRESULT Finalizar(void)
{
   PostQuitMessage(codigo_salida);
   return 0;
}

int Cerrando(HWND idv)
{
        LPSYSTEMTIME tiempo_dif;
        char salida1[64] = { "" };
        char salida2[64] = { "" };
        char salida3[64] = { "" };
        char salida4[64] = { "" };
        char temp[256] = { "" };
        ostrstream salida(temp, 256);

   if(wciclar_ini.salida == SALIDA_RAPIDA)
     return IDYES;

   suspendido = true;

   // Obtiene la hora actual
   GetLocalTime(&tiempo_finaliza);

   // Calcula el tiempo transcurrido desde que se inició Wciclar
   tiempo_dif = DifTiempo(&tiempo_finaliza, &tiempo_inicia);

   GetDateFormat(LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, &tiempo_inicia, NULL, salida1, 64);
   GetDateFormat(LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, &tiempo_finaliza, NULL, salida2, 64);

   GetTimeFormat(LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, &tiempo_inicia, NULL, salida3, 64);
   GetTimeFormat(LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, &tiempo_finaliza, NULL, salida4, 64);

   salida << "Tiempo inicial: " << salida1 << ' ' << salida3 << endl
          << "Tiempo final  : " << salida2 << ' ' << salida4 << endl
          << "Tiempo trans. (hh:mm:ss,mmm): " << setw(2) << setfill('0') << tiempo_dif->wHour
          << ':' << setw(2) << setfill('0') << tiempo_dif->wMinute
          << ':' << setw(2) << setfill('0') << tiempo_dif->wSecond
          << ',' << setw(3) << setfill('0') << tiempo_dif->wMilliseconds
          << endl << endl
          << "¿ Cierro la aplicación ?" << ends;

   return MessageBox(idv, salida.str(), "Tiempos", MB_YESNO|MB_ICONINFORMATION);
}

// Cierra la ventana
LRESULT Cerrar(HWND idv)
{
   int estado = Cerrando(idv);
   if(estado == IDYES)
   {
     // Elimina los temporizadores
     KillTimer(idv, IDT_TIMER1);
     KillTimer(idv, IDT_TIMER2);
     KillTimer(idv, IDT_TIMER3);

     codigo_salida = EXIT_SUCCESS;

     for(int i = max_recurso_texto - 1; i >= 0; i--)
       delete wciclar_ini.recurso_texto[i];

     delete wciclar_ini.recurso_texto;
     delete wciclar_ini.nombre;
     delete usuario_y_terminal;
     delete cronometro;

     wciclar_ini.recurso_texto = NULL;
     usuario_y_terminal = NULL;
     cronometro = NULL;

     DestroyWindow(idv);
   }
   else
     suspendido = false;

   return 0;
}

LRESULT ConsultarFinalSesion(HWND idv, WPARAM arg1, LPARAM arg2)
{
   UNREFERENCED_PARAMETER(arg1);
   UNREFERENCED_PARAMETER(arg2);

   Cerrando(idv);

   // Elimina los temporizadores
   KillTimer(idv, IDT_TIMER1);
   KillTimer(idv, IDT_TIMER2);
   KillTimer(idv, IDT_TIMER3);

   codigo_salida = EXIT_SUCCESS;

   for(int i = max_recurso_texto - 1; i >= 0; i--)
     delete wciclar_ini.recurso_texto[i];

   delete wciclar_ini.recurso_texto;
   delete wciclar_ini.nombre;
   delete usuario_y_terminal;
   delete cronometro;

   wciclar_ini.recurso_texto = NULL;
   usuario_y_terminal = NULL;
   cronometro = NULL;

   DestroyWindow(idv);
   return TRUE;
}

LRESULT ComandoSistema(HWND idv, UINT msj, WPARAM wParam, LPARAM lParam)
{
   // Impide que la ventana sea redimensionada y maximizada.
   if((wParam & 0xFFF0) == SC_SIZE)
     return FALSE;
   else
     if((wParam & 0xFFF0) == SC_MAXIMIZE)
       return FALSE;
     else
       return DefWindowProc(idv, msj, wParam, lParam);
}

LRESULT AjustarColorVentana(void)
{
   color_texto = GetSysColor(COLOR_WINDOWTEXT);
   color_fondo = GetSysColor(COLOR_WINDOW);

   return FALSE;
}

LRESULT CrearVentana(void)
{
        BOOL estado;
        DWORD max_cars2 = MAX_COMPUTERNAME_LENGTH + 1;
        DWORD max_cars = 80;
        char desconocido[] = "???";
        char terminal[MAX_COMPUTERNAME_LENGTH + 1];
        char usuario[80];

   // inicializa los acumuladores de ciclos
   acumulador = 0ui64;
   acumulador_parcial = 0UL;

   muestra[0].estado_memoria.dwLength = sizeof(MEMORYSTATUS);
   muestra[1].estado_memoria.dwLength = sizeof(MEMORYSTATUS);

   // Consigue nombre de usuario y terminal
   estado = GetUserName(usuario, &max_cars);
   if(estado == 0)
   {
     strcpy(usuario, desconocido);
     max_cars = strlen(desconocido);
   }

   GetComputerName(terminal, &max_cars2);
   if(estado == 0)
   {
     strcpy(terminal, desconocido);
     max_cars2 = strlen(desconocido);
   }

   try
   {
     usuario_y_terminal = new char[max_cars + max_cars2 + 4];
     cronometro = new Cronometro;

     strcpy(usuario_y_terminal, usuario);
     strcat(usuario_y_terminal, "@");
     strcat(usuario_y_terminal, terminal);
   }
   catch(...)
   {
     abortar("¡ Memoria insuficiente !");
   }

   return FALSE;
}

LRESULT AjustarTamVentana(HWND idv, WPARAM fwSizeType)
{
   // Impide que sea maximizada la ventana.
   if(fwSizeType == SIZE_MAXIMIZED)
     ShowWindow(idv, SW_RESTORE);

   return FALSE;
}

// Reproduce un sonido
void TocarSonido(WORD id_sonido)
{
   if(id_sonido)
     PlaySound(MAKEINTRESOURCE(id_sonido), hinst, SND_ASYNC|SND_RESOURCE);
}

// Calcula vps y cwh, entre otros cálculos
LRESULT Temporizador(HWND idv, WPARAM param)
{
   if(suspendido == true)
     return 0;

   if(param == IDT_TIMER1)
     acumulador_parcial++;
   else
     if(param == IDT_TIMER2)
     {
       acumulador += acumulador_parcial;
       muestra[imuestra].vps = acumulador_parcial / wciclar_ini.lapso_de_tiempo;

       acumulador_parcial = 0UL;

       DWORD prioridad = GetPriorityClass(GetCurrentProcess());
       if(wciclar_ini.prioridad_proceso != prioridad)
       {
         string NombreVentana = szNombreAplicacion;

         // la prioridad del proceso ha cambiado
         NombreVentana += szPrioridad;
         NombreVentana += proceso[MAX_TIPO_PRIORIDAD-1].szTipoPrioridad;

         wciclar_ini.prioridad_proceso = prioridad;
         strcpy(wciclar_ini.szTipoPrioridad, proceso[MAX_TIPO_PRIORIDAD-1].szTipoPrioridad);

         for(int i = 0; i < MAX_TIPO_PRIORIDAD; i++)
           if(prioridad == proceso[i].prioridad)
           {
             NombreVentana = szNombreAplicacion;
             NombreVentana += szPrioridad;
             NombreVentana += proceso[i].szTipoPrioridad;

             strcpy(wciclar_ini.szTipoPrioridad, proceso[i].szTipoPrioridad);
             wciclar_ini.escala = proceso[i].escala;
             break;
           }

         SetWindowText(hwndMain, NombreVentana.c_str());
       }

       GlobalMemoryStatus(&muestra[imuestra].estado_memoria);
       InvalidateRect(idv, NULL, TRUE);
     }
     else
       if(param == IDT_TIMER3)
       {
         DWORD tcw = 0;

         LONGLONG i = cronometro->frecuencia();
         cronometro->iniciar();

         while(i > 0)
           i--;

         cronometro->detener();
         muestra[imuestra++].ciclos_while = cronometro->lapso_transcurrido();

         if(imuestra > 1)
         {
           // calcula 'estabilidad'
           double DifMuestras = (muestra[1].vps + muestra[1].ciclos_while + muestra[1].estado_memoria.dwMemoryLoad) / 3.0
                               - (muestra[0].vps + muestra[0].ciclos_while + muestra[0].estado_memoria.dwMemoryLoad) / 3.0;

           estabilidad = DifMuestras / 100.0;

           if(estabilidad > 0.0)
             condicion_estabilidad[1] = 'L';
           else
             if(estabilidad < 0.0)
               condicion_estabilidad[1] = 'R';
             else
               condicion_estabilidad[1] = 'E';

           imuestra = 0;
         }

         // obtiene el tiempo transcurrido desde que Windows se inició,
         // el tiempo viene expresado en milisegundos.
         tcw = GetTickCount();

         // tiempo convertido a minutos
         ttw = (tcw / 1000.0) / 60.0;

         TocarSonido(wciclar_ini.sonido);
         InvalidateRect(idv, NULL, TRUE);
       }

   return 0;
}

// Despachante de mensajes
LRESULT CALLBACK ProcVnt(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam)
{
        LRESULT estado;

   switch(messg)
   {
     case WM_TIMER  : estado = Temporizador(hWnd, wParam);
                      break;

     case WM_PAINT  : estado = Ventana(hWnd);
                      break;

     case WM_CREATE : estado = CrearVentana();
                      break;

     case WM_CLOSE  : estado = Cerrar(hWnd);
                      break;

     case WM_DESTROY: estado = Finalizar();
                      break;

     case WM_QUERYENDSESSION:
                      estado = ConsultarFinalSesion(hWnd, wParam, lParam);
                      break;
     
     /*  Respuesta a mensaje no implementado.
     case WM_QUIT:   estado = Salir();
                     break;
     */
      
     case WM_SYSCOMMAND:
                      estado = ComandoSistema(hWnd, messg, wParam, lParam);
                      break;

     case WM_SYSCOLORCHANGE:
                      estado = AjustarColorVentana();
                      break;

     case WM_SIZE:    estado = AjustarTamVentana(hWnd, wParam);
                      break;

                      // Atiende otros mensajes recibidos
     default        : estado = DefWindowProc(hWnd, messg, wParam, lParam);
   }

   return estado;
}

void abortar(char *t)
{
   MessageBox(NULL, t, "Abortando...", MB_OK|MB_ICONERROR);
   exit(EXIT_FAILURE);
}

WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lptszCmdLine, int nCmdShow)
{
        HWND hWnd;
        MSG msg;
        WNDCLASS wc;

   UNREFERENCED_PARAMETER(lptszCmdLine);

   // Busca otra instancia en ejecución
   hWnd = FindWindow(szNombreClase, NULL);
   if(hWnd != NULL)
   {
	 MessageBeep(MB_ICONHAND);
	 SetForegroundWindow(hWnd);  // Se está ejecutando una instancia anterior y
	 return codigo_salida;       // se procede a activarla y ésta se cancela
   }

   // Lee los argumentos recibidos desde la línea de comandos
   LeerArgumentos();

   // Registra la clase ventana como la ventana principal
   if(!hPrevInstance)
   {
		wc.style = CS_HREDRAW | CS_VREDRAW;
		wc.lpfnWndProc = (WNDPROC) ProcVnt;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = hInstance;
		wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
		wc.hCursor = LoadCursor((HINSTANCE) NULL, IDC_ARROW);
		wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
		wc.lpszMenuName =  (LPSTR)NULL;
		wc.lpszClassName = szNombreClase;

		if(!RegisterClass(&wc))
		  return codigo_salida;
   }

   // Guarda el identificador de la instancia
   hinst = hInstance;

   // Lee el fichero de configuración wciclar.ini
   LeerWciclar_ini();

    // Crea la ventana principal
    hwndMain = CreateWindowEx(wciclar_ini.estilo, szNombreClase, szNombreAplicacion,
                              WS_OVERLAPPEDWINDOW,
                              wciclar_ini.origenX, wciclar_ini.origenY,
                              wciclar_ini.ancho, wciclar_ini.alto,
                              (HWND) NULL, (HMENU) NULL, hInstance, (LPVOID) NULL);

   // Si no puede ser creada la ventana principal,
   // termina la aplicación
   if(!hwndMain)
     return codigo_salida;

   // Intenta cambiar la prioridad del proceso
   if(!SetPriorityClass(GetCurrentProcess(), wciclar_ini.prioridad_proceso))
   {
     wciclar_ini.prioridad_proceso = NORMAL_PRIORITY_CLASS;
     wciclar_ini.escala = proceso[2].escala;
     strcpy(wciclar_ini.szTipoPrioridad, proceso[2].szTipoPrioridad);
   }

   // Cambia el estilo de la ventana a translúcida
   SetWindowLong(hwndMain, GWL_EXSTYLE, GetWindowLong(hwndMain, GWL_EXSTYLE) | WS_EX_LAYERED);

   // La ventana se pone translúcida
   SetLayeredWindowAttributes(hwndMain, 0, wciclar_ini.alfa, LWA_ALPHA);

   // Muestra la ventana y pinta su contenido
   AjustarColorVentana();
   ShowWindow(hwndMain, nCmdShow);
   UpdateWindow(hwndMain);

   // Obtiene la hora actual
   GetLocalTime(&tiempo_inicia);

   // Define 3 temporizadores
   SetTimer(hwndMain, IDT_TIMER1, USER_TIMER_MINIMUM, (TIMERPROC)NULL);
   SetTimer(hwndMain, IDT_TIMER2, (wciclar_ini.lapso_de_tiempo * 1000), (TIMERPROC)NULL);
   SetTimer(hwndMain, IDT_TIMER3, (wciclar_ini.lapso_de_tiempo * 1000) + 1750, (TIMERPROC)NULL);

    // Atiende los mensajes
    while(GetMessage(&msg, hwndMain, NULL, NULL) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // Devuelve el código de salida a Windows
    return codigo_salida;
}
