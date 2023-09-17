// Proyecto: eiv.cbproj
// Programa: equipoVirtual.cpp
// Autor: Octulio Bilet�n
// Prop�sito: exponer los principios b�sicos de virtualizaci�n, simulaci�n y emulaci�n para ense�ar en C++.
//            El sistema inform�tico propuesto puede estar funcionando como un todo local, remoto o h�brido.
//            La plataforma de desarrollo es en: Windows 64 bits.
// Versi�n: Setiembre de 2023.
// Obs.: El proyecto eiv.cbproj permanece abierto para su desarrollo permanente...

#include <tchar.h>
#include "eiv.h"

int _tmain(int argc, _TCHAR *argv[])
{
	Comando comando;
	Sesion sesion;
	SistemaOperativo eox;
	MaquinaVirtual metatron;

   // Enciende e inicia metatron, enciende e inicia eox, inicia sesi�n, inicia y ejecuta comando
   int salida = comando.ejecutar(
		  comando.iniciar(
                    sesion.iniciar(
                      eox.iniciar(
                        eox.encender(
                          metatron.iniciar(
			    metatron.condicion(MaquinaVirtual::encender)
                          )
                        )
                      )
                    )
   		  )
                );

   // Le comunico a la m�quina virtual la condici�n de salida
   return MaquinaVirtual().condicion(salida);
}
