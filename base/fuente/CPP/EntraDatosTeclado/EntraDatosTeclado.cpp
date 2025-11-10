// __________________________________________________________
// Programa   : EntraDatosTeclado.cpp
// Descripcion: Dialogando con la computadora en español.
// Plataforma : Embarcadero C++ Builder, Windows.
// Licencia   : Software Libre.
// __________________________________________________________
#include <iostream>
#include <tchar.h>
#include <string>
#include <cstring>
#include <cstdlib>
#include <mem.h>

#include "macros-esp.h"

comentario Declara la tarea 'limpiar' con sus argumentos.
declare tarea limpiar(region_memoria m, tam_bytes t);

programa
inicie
	def_entero pos1 sin_datos_entero;
	def_entero pos2 sin_datos_entero;
	string buscar;
	def_caracteres entrada[96] sin_datos_caracteres;

   comando(chcp 1252>nul);

   muestre mensaje(Dialogando con la máquina.) cierre;
   muestre mensaje(¿De dónde eres?) cierre;

   muestre mensaje(Responda:) ademas " " ahora;
   espere.linea_texto(entrada, 80);

   si_es(strlen(entrada) > 0) cierto
     muestre mensaje(Tú eres) ademas " " ademas entrada cierre;
   si_no
     muestre mensaje(No has respondido.) cierre;

   muestre mensaje(¿Vives allí?) cierre;

   limpiar(entrada, 96);
   muestre mensaje(Responda:) ademas " " ahora;
   espere.linea_texto(entrada, 80);

   buscar = entrada;
   pos1 = buscar.find("no");
   pos2 = buscar.find("si");

   si_es(pos1 != string::npos) cierto
   inicie
     si_es(strcmp("no", buscar.substr(pos1, 2).c_str()) == 0) cierto
       muestre mensaje(Entiendo que quieras privacidad.) cierre;
   termine
   si_no
     inicie
       muestre mensaje(Me gustaría hacerte una visita...) cierre;
       si_es(pos2 != string::npos) cierto
	 muestre mensaje(Mañana podría visitarte.) cierre;
     termine

   limpiar(entrada, 96);
   muestre mensaje(Responda:) ademas " " ahora;
   espere.linea_texto(entrada, 80);

   buscar = entrada;
   pos1 = buscar.find("no");
   pos2 = buscar.find("si");

   si_es(pos2 != string::npos) cierto
     muestre mensaje(Ok. Nos vemos pronto.) cierre;
   si_no
     si_es(pos1 != string::npos) cierto
       muestre mensaje(En otra ocación será...) cierre;
     si_no
       inicie
	 muestre mensaje(Como tú digas. Yo respeto tu decisión.) cierre;

	 si_es(strlen(entrada) == 0) cierto
	   muestre mensaje(Estás mudo hoy...) cierre;
       termine

   muestre mensaje(Dialogo terminado.) cierre;

   comentario Efectúa una pausa hasta que se presiona la tecla 'Intro'
   espere.intro;

   comentario Retorna al S.O. y devuelve 0
   retorne 0;
termine

comentario Define la tarea 'limpiar'
tarea limpiar(region_memoria m, tam_bytes t)
inicie
   setmem(m, t, 0);
termine
