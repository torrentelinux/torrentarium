// Programa  : mvars.cpp
// Autor     : Eugenio Martínez, noviembre de 2021.
// Propósito : Mostrar las variables de entorno
//             en el navegador de páginas HTML.
// Comentario: Compilar con Embarcadero C++ Builder.
//             Invocar así: http://127.0.0.1/cgi-bin/mvars.cgi

#include <iostream.h>
#include <stdlib.h>

using namespace std;

int main(void)
{
   // Valores aceptados en 'charset': utf-8 ; iso-8859-1
   cout << "Content-type: text/html;charset=utf-8\n\n";
   cout << "<html>\n";
   cout <<   "<head>\n";
   cout <<     "<title>Variables de entorno</title>\n";
   cout <<   "</head>\n";
   cout <<   "<body>\n";
   cout <<     "Las variables de entorno del proceso actual:<br>\n<br>\n";

   for(int i = 0; _environ[i] != NULL; i++)
     cout << _environ[i] << "<br>\n";

   cout <<   "</body>\n";
   cout << "</html>\n";

   return 0;
}
