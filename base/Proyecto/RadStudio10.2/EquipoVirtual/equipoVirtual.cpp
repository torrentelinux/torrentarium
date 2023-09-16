// Programa: equipoVirtual.cpp
// Descripción: equipo virtual informático: principios básicos para enseñar virtualización en C++
// Autor: Octulio Biletán * 2023

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
