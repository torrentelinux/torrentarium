// Proyecto: Ejemplo1.cbproj
// Módulo  : hojaDeDibujo.cpp
// Librería: JLogo.cpp
// Versión : 1.0
// Depende.: Embarcadero Studio ver. 22.0, VCL ver. 28.0.47991.2819, Alexandria, 64 bits.
// Autor   : Octulio Biletán * Octubre de 2025.
// Descrip.: Implementar la clase 'hoja_de_dibujo'.
// Ambiente: Windows, modo gráfico, 64 bits.
// Licencia: Software libre.

#include "hojaDeDibujo.h"
#include "JLogo.h"

// Definición pública y global de la instancia de la clase 'hoja_de_dibujo'.
hoja_de_dibujo HojaDeDibujo;

// Inicia la gráfica de la tortuga en la ventana principal 'frm'.
int hoja_de_dibujo::visualizar(TfrmCentral *frm, Vcl::Controls::TWinControl *AOwner)
{
	int estado = 0;
	int pasos = 10;
	JLogo *tortuga = new JLogo();

   tortuga->iniciar(frm, AOwner);	// Inicializa el entorno de trabajo para la tortuga

     estado = tortuga->producto();		// Muestra el nombre y versión del producto en uso
     estado = tortuga->avance(pasos);		// Se desplaza hacia arriba tantos pasos como indica la var. 'pasos'.
     estado = tortuga->mostrar();		// Muestra la tortuga en la pantalla
     tortuga->detente(2);			// Hace una pausa por 2 segs.

     tortuga->derecha();	// Se desplaza hacia la derecha
     tortuga->avance(pasos);
     estado = tortuga->mostrar();		// Muestra la tortuga en la pantalla
     tortuga->detente(2);			// Hace una pausa por 2 segs.

     tortuga->bajar();	// Se desplaza hacia abajo
     tortuga->avance(pasos);
     estado = tortuga->mostrar();		// Muestra la tortuga en la pantalla
     tortuga->detente(2);			// Hace una pausa por 2 segs.

     tortuga->izquierda();	// Se desplaza hacia la izquierda
     tortuga->avance(pasos);
     estado = tortuga->mostrar();		// Muestra la tortuga en la pantalla
     tortuga->detente(2);			// Hace una pausa por 2 segs.

     tortuga->subir();	// Se prepara para subir
     estado = tortuga->mostrar();		// Muestra la tortuga en la pantalla
     tortuga->detente(2);			// Hace una pausa por 2 segs.

   tortuga->terminar();			// Termina todas las tareas de la tortuga

   delete tortuga;
   return estado;	// regresa al S.O.
}
