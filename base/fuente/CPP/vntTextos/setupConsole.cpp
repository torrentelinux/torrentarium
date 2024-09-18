// ----------------------------------------------------------
// Propósito: 
//	Prepara la consola de textos antes de ingresar a main()
//	y antes de cerrar la consola de textos y retornar al S.O.
// Cambios: leer sig. enlace
// https://learn.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences
// ----------------------------------------------------------

#include <windows.h>
#include <wchar.h>
#include <iostream>

using namespace std;

// ********************************
// Establece info. sobre el tipo de letra que es utilizado en la consola activa
// Devuelve TRUE si OK
// Devuelve FALSE si falló
BOOL setcurrentfont(int fontY, wchar_t *fontname)
{
	CONSOLE_FONT_INFOEX tipografia = { 0 };

   // Ajusta la apariencia del tipo de letra seleccionada
   // Alternativo: tipografia.nFont = 4;
   // Alternativo: tipografia.FontFamily = FF_DONTCARE;
   tipografia.cbSize       = sizeof(CONSOLE_FONT_INFOEX);

   // Altura de la fuente de caracteres
   tipografia.dwFontSize.Y = fontY;

   tipografia.FontWeight   = FW_NORMAL;
   wcscpy(tipografia.FaceName, fontname);

   return SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &tipografia);
}

void pre_main(void)
{
	WORD color_texto;

   SetConsoleOutputCP(GetACP());

   // pone la fuente de caracteres 'Consolas' a 18 pts
   setcurrentfont(18, L"Consolas");

   // pone nuevo color blanco con brillo al texto y el fondo queda sin cambios
   color_texto = 15;
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_texto);
}

void pos_main(void)
{
	WORD color_texto;

   cin.get();

   // pone la fuente de caracteres 'Terminal' a 12 pts
   setcurrentfont(12, L"Terminal");

   // pone color blanco sin brillo al texto y el fondo queda sin cambios
   color_texto = 7;
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_texto);
}

#pragma startup pre_main
#pragma exit    pos_main
// ********************************
