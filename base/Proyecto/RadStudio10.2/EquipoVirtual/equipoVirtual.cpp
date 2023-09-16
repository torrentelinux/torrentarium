// Programa: equipoVirtual.cpp
// Descripci�n: equipo virtual inform�tico: principios b�sicos para ense�ar virtualizaci�n en C++
// Autor: Octulio Bilet�n * 2023

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
