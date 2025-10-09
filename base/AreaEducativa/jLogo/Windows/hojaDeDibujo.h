// Proyecto: Ejemplo1.cbproj
// Encabez.: hojaDeDibujo.h
// Librería: JLogo.cpp
// Versión : 1.0
// Depende.: Embarcadero Studio ver. 22.0, VCL ver. 28.0.47991.2819, Alexandria, 64 bits.
// Autor   : Octulio Biletán * Octubre de 2025.
// Descrip.: La declaración de la clase 'hoja_de_dibujo'.
// Ambiente: Windows modo gráfico, 64 bits.
// Licencia: Software libre.

#ifndef hojadedibujo_hdd
#  define hojadedibujo_hdd

#include "frmPrincipal.h"

class hoja_de_dibujo
{
    public:
        // Entrada principal a Logo
	int visualizar(TfrmCentral *frm, Vcl::Controls::TWinControl *AOwner);
};

// La instancia 'HojaDeDibujo' está definida en hojaDeDibujo.cpp
extern hoja_de_dibujo HojaDeDibujo;

#endif
