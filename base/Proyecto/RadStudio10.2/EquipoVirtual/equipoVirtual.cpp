// Proyecto: eiv.cbproj
// Programa: equipoVirtual.cpp
// Autor: Octulio Biletán
// Propósito: exponer los principios básicos de virtualización, simulación y emulación para enseñar en C++.
//            El sistema informático propuesto puede estar funcionando como un todo local, remoto o híbrido.
//            La plataforma de desarrollo es en: Windows 64 bits.
// Versión: Setiembre de 2023.
// Obs.: El proyecto eiv.cbproj permanece abierto para su desarrollo permanente...

#include <tchar.h>
#include "eiv.h"

int _tmain(int argc, _TCHAR *argv[])
{
	Comando comando;
	Sesion sesion;
	SistemaOperativo eox;
	MaquinaVirtual metatron;

   // Enciende e inicia metatron, enciende e inicia eox, inicia sesión, inicia y ejecuta comando
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

   // Le comunico a la máquina virtual la condición de salida
   return MaquinaVirtual().condicion(salida);
}
