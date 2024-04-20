// PRUEBA DE CONCEPTO: trabajo de investigación sobre cmd.exe y windows
// *** sólo al personal autorizado ***
// https://learn.microsoft.com/es-es/windows-server/identity/ad-ds/manage/understand-security-identifiers
// https://learn.microsoft.com/es-es/windows/win32/psapi/enumerating-all-processes

#include <vcl.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ctime>
#include <process.h>

using namespace std;

char *entregarArgumentos(void)
{
	ostringstream salida;
	static char datos[1024];

   *datos = '\0';

   if(_argc == 1)
     return "<sin argumentos>";

   for(unsigned short int s = 1; s < _argc; s++)
       salida << _argv[s] << " ";

   salida << ends;

   strcpy(datos, salida.str().c_str());
   return datos;
}

void registrarEntrada(void)
{
	time_t ahora = time(NULL);
	ofstream salida;
	string fnombre;

   fnombre = getenv("TMP");
   fnombre.append("\\2491812.log");

   salida.open(fnombre.c_str(), ios::app);
   if(salida.is_open())
   {
     // pid:usr:prg:rlj:
     salida << "pid:" << getpid() << "|"
            << "usr:" << getenv("USERNAME") << "|"
            << "prg:" << _argv[0] << " " << entregarArgumentos() << "|"
            << "rlj:" << ctime(&ahora)
	    << endl;
   }

   salida.close();
}

int main(int argc, char **argv)
{
	char varUsuario[272] = { "" };
	AnsiString temp;
	string linea_comando;
	ostringstream salida;

   registrarEntrada();

   if(argc == 1)  // si no hay argumentos recibidos...
   {
//-->
    GetEnvironmentVariable("USERNAME", varUsuario, 256);

    // nombre de fantasía: microssoft (con dos eses) = micros+soft
    cout << "Microssoft Window [Version 11.0.1812.2022]" << endl
	 << "Copyright (c) 2022 Microssoft Corporation. Todo lo derecho reservado\n" << endl
	 << "A:\\Usuario\\" << varUsuario << ">" << flush;

    Application->MessageBox(L"Perdió River y Boca\nNo se encuentra la Tabla de Posiciones .afa\nen el directorio vigente", L"Prueba de concepto", MB_OK | MB_ICONERROR);
    cout << endl;
//-->
   }
   else  // si hay argumentos recibidos entonces invocar a 'cmd'
   {
     for(unsigned short int s = 1; s < argc; s++)
       salida << argv[s] << " ";

     salida << ends;

     linea_comando = salida.str().c_str();
     linea_comando.resize(linea_comando.length()-1);

     temp = linea_comando.c_str();
     temp = temp.LowerCase();

     linea_comando = temp.c_str();

     if(linea_comando.compare("/?") == 0 || linea_comando.compare("/h") == 0)
     {
         // se espera que cmd.exe esté en su lugar de residencia
	 spawnl(P_WAIT, "c:\\windows\\system32\\cmd.exe", "c:\\windows\\system32\\cmd.exe", "/?", NULL);
	 goto AFA;
     }

     // invoca al intérprete de comandos del s.o.
     system(linea_comando.c_str());
   }

AFA:
   return 0xafa;
}
