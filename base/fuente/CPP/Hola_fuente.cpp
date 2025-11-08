// Programa C++ ¡Hola a todos!
// construído con macros en español

#include <iostream>
using namespace std;

#define muestre          cout<<
#define cierre           <<endl
#define siguiente_linea  "\n"
#define programa         main()
#define inicie           {
#define termine 	 }
#define mensaje(t)       #t

programa
inicie
   muestre
     mensaje(¡Hola a todos!)
     siguiente_linea
     mensaje(--------------)
   cierre;
termine

