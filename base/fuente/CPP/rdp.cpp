// rdp.cpp
// diagrama de flujo: resolución de problemas.
// resolución 'inteligente' de los problemas.
// programación divertida en la consola de windows.
// codificador: edmund muslok (em).
// referencias...
// https://es.linkedin.com/posts/angelyamada_unpocodehumor-resoluciondeproblemas-activity-7097571908233158656-8707

#include <tchar.h>
#include <windows.h>

#include <iostream>
#include <cstring>
#include <conio.h>

void Entry(void);
void Exit(void);
BOOL setcurrentfont(wchar_t *nfuente, SHORT tamTipoLetra);

#pragma startup Entry
#pragma exit Exit

void Exit(void)
{
	UINT cod_pag;

   cod_pag = GetConsoleOutputCP();
   if(cod_pag != 850)
   {
     // Cambia el juego de caracteres para la entrada/salida estándar
     SetConsoleOutputCP(850);
     SetConsoleCP(850);
   }

   setcurrentfont(L"Terminal", 12);
}

void Entry(void)
{
	UINT cod_pag;

   cod_pag = GetConsoleOutputCP();
   if(cod_pag != 1252)
   {
     // Cambia el juego de caracteres para la entrada/salida estándar
     SetConsoleOutputCP(1252);
     SetConsoleCP(1252);
   }
   else
   {
     SetConsoleOutputCP(850);
     SetConsoleCP(850);
   }

   // Fuente de caracteres: Lucida Console, 14 pts.
   setcurrentfont(L"Lucida Console", 14);
}

BOOL setcurrentfont(wchar_t *nfuente, SHORT tamTipoLetra)
{
	CONSOLE_FONT_INFOEX tipografia = { 0 };

   tipografia.cbSize = sizeof(CONSOLE_FONT_INFOEX);
   tipografia.dwFontSize.Y = tamTipoLetra;
   tipografia.FontWeight = FW_NORMAL;
   tipografia.FontFamily = FF_DONTCARE;

   wcscpy(tipografia.FaceName, nfuente);

   return SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &tipografia);
}

using namespace std;

main()
{
      int funcionaLaPorqueria = 0;
      int tratasteDeArreglarlo = 0;
      int loSabeAlguienMas = 0;
      int podesCulparAOtro = 0;
      int tePuedenCagarAPedos = 0;
      const int SI = 49;
      const int NO = 48;
      const int INTRO = 13;

   cout << "Programa rdp.exe" << endl;
   cout << "Resolución de problemas." << endl << endl;

   cout << "¿Funciona la porquería? (1:sí;0:no)" << endl;
   funcionaLaPorqueria = getche();

   if(funcionaLaPorqueria == SI)
      cout << endl << "No jodas !" << endl;
   else
   {
      cout << endl;
      cout << "¿Trataste de arreglarlo? (1:sí;0:no)" << endl;

      tratasteDeArreglarlo = getche();
      if(tratasteDeArreglarlo == INTRO)
	tratasteDeArreglarlo = getche();

      if(tratasteDeArreglarlo == SI)
      {
	  cout << endl;

	  cout << "¿Lo sabe alguien más? (1:sí;0:no)" << endl;
	  loSabeAlguienMas = getche();

          // para salir del quilombo tenés que culpar a alguien...
	  if(loSabeAlguienMas == SI)
	  {
_cagaste:
	    cout << endl;
	    cout << "Cagaste ! (Cualquier tecla continúa)" << endl;
	    getch();

	    cout << "¿Podés culpar a otro? (1:sí;0:no)" << endl;
	    podesCulparAOtro = getche();

	    if(podesCulparAOtro == SI)
	      goto _problemaresuelto;
	    else
	      goto _cagaste;
	  }
	  else
	  {
	    cout << endl;

	    cout << "Hacete el Boludo..." << endl;
	    goto _problemaresuelto;
	  }
      }
      else
      {
          cout << endl;
	  cout << "¿Te pueden cagar a pedos? (1:sí;0:no)" << endl;
	  tePuedenCagarAPedos = getche();

	  if(tePuedenCagarAPedos == SI)
	    goto _cagaste;
	  else
	    cout << endl << "Tiralo a la mierda..." << endl;
      }
   }

_problemaresuelto:
   cout << endl;
   cout << "*** Problema resuelto ***" << endl;

   getch();
   return 0;
}
