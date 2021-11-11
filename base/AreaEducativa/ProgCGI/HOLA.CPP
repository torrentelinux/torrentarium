// Programa  : HOLA.CPP
// Autor     : Eugenio Martínez, setiembre de 2013.
// Propósito : Ejemplo de programa CGI. Mostrar el mensaje '¡ Hola a todos !'
//             en el navegador de páginas HTML.
// Comentario: Compilar con Embarcadero C++ Builder.
//             bcc32 hola.cpp
//             ren hola.exe hola.cgi
//             Instalar 'hola.cgi' en el directorio \cgi-bin\ del servidor HTTPD
//             Invocar así: http://127.0.0.1/cgi-bin/hola.cgi
//             Ultima actualización: 10-Nov-2021
// Refs.     : https://jkorpela.fi/forms/cgic.html

#include <iostream.h>

int main(void)
{
   // Valores aceptados en 'charset': utf-8 ; iso-8859-1
   cout << "Content-type: text/html;charset=utf-8\n\n";
   cout << "<html>";
   cout <<   "<head>";
   cout <<     "<title>Salutación</title>";
   cout <<   "</head>\n";
   cout <<   "<body>";
   cout <<     "¡ Hola a todos !<br>";
   cout <<   "</body>\n";
   cout << "</html>\n";

   return 0;
}
