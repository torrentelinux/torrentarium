// Proyecto: Ejemplo1.cbproj
// Librería: JLogo.cpp
// Versión : 1.0
// Depende.: Embarcadero Studio ver. 22.0, VCL ver. 28.0.47991.2819, Alexandria, 64 bits.
// Autor   : Octulio Biletán * Octubre de 2025.
// Descrip.: Implementar la clase JLogo.
// Ambiente: Windows, modo gráfico, 64 bits.
// Licencia: Software libre.

#include "JLogo.h"

JLogo::JLogo()
{
   error_ptr = false;
   jlogo_operable = true;

   columnas = 80;
   lineas = 42;
   col_actual = 0;
   linea_actual = 0;

   tortuga_version = "1.0";
   tortuga_fproduc = "28-09-2025";
   tortuga_copyright = "Copyright (c) 2025 Eugenio Martínez. Todos los derechos reservados.";
   tortuga_figura = L'▲';  // es la apariencia visual que tiene la tortuga
   tortuga_traza = L'*';   // es la traza que deja la tortuga cuando avanza
   piso_figura = L' ';     // es la superficie de escritura/dibujo

   frmBase = nullptr;
   apli = nullptr;
   linea = nullptr;

   direccion = "norte";    // Se desplazará hacia arriba
}

JLogo::JLogo(TfrmCentral *frm, Vcl::Controls::TWinControl *AOwner)
{
   jlogo_operable = false;
   
   if(frm == nullptr)
     error_ptr = true;

    if(AOwner == nullptr)
      error_ptr = true;

   if(error_ptr)  // Retorna si hay error en punteros, se rechazan punteros nulos
     return;

   error_ptr = false;
   jlogo_operable = true;

   frmBase = AOwner;
   apli = frm;

   columnas = 316;
   lineas = 42;
   col_actual = 0;
   linea_actual = 0;

   tortuga_version = "1.0";
   tortuga_fproduc = "28-09-2025";
   tortuga_copyright = "Copyright (c) 2025 Eugenio Martínez. Todos los derechos reservados.";
   tortuga_figura = L'▲';  // es la apariencia visual que tiene la tortuga
   tortuga_traza = L'·';   // es la traza que deja la tortuga cuando avanza
   piso_figura = L' ';     // es la superficie de escritura/dibujo

   linea = new TLabel(frmBase);
   linea->Parent = frmBase;

   direccion = "norte";    // Se desplazará hacia arriba
   limpiar();
   centropantalla();

   apli->rtfEdit->Clear();
   for(int i = 0; i < lineas; i++)
     apli->rtfEdit->Lines->Add(UnicodeString(_pantalla[i]));

   apli->rtfEdit->Left = 2;
   apli->rtfEdit->Top = 24;
   apli->rtfEdit->Width = 1280;
   apli->rtfEdit->Height = 680;
}

JLogo::~JLogo()
{
   jlogo_operable = false;
}

void JLogo::iniciar(TfrmCentral *frm, Vcl::Controls::TWinControl *AOwner)
{
   if(jlogo_operable)
   {
	if(frm == NULL)
	   error_ptr = true;

	if(AOwner == NULL)
	   error_ptr = true;

	if(error_ptr)  // Retorna si hay error en punteros
	   return;

	frmBase = AOwner;
	apli = frm;

	linea = new TLabel(frmBase);
	linea->Parent = frmBase;

	limpiar();
	centropantalla();

	apli->rtfEdit->Clear();
	for(int i = 0; i < lineas; i++)
	  apli->rtfEdit->Lines->Add(UnicodeString(_pantalla[i]));

	apli->rtfEdit->Left = 2;
	apli->rtfEdit->Top = 24;
	apli->rtfEdit->Width = 1280;
	apli->rtfEdit->Height = 680;
   }
}

// Deja limpia todas sus variables internas.
void JLogo::terminar(void)
{
   columnas = 0;
   lineas = 0;
   col_actual = 0;
   linea_actual = 0;

   direccion = "";
   tortuga_version = "";
   tortuga_fproduc = "";
   tortuga_copyright = "";
   tortuga_figura = L' ';
   tortuga_traza = L' ';
   piso_figura = L' ';
   limpiar();
}

int JLogo::producto(void)
{
    if(error_ptr)
      return 1;         // Hay error en punteros

    String texto = "Librería jLogo, versión " + tortuga_version + L", " + tortuga_fproduc +
		   ". " + tortuga_copyright;

   linea->Caption = texto;
   linea->AutoSize = true;
   linea->Left = 8;
   linea->Top = 4;
   linea->Visible = true;

   return 0;
}

// La tortuga en pantalla...
int JLogo::mostrar(void)
{
    if(error_ptr)
      return 1;         // Hay error en punteros

   apli->rtfEdit->Clear();
   for(int i = 0; i < lineas; i++)
     apli->rtfEdit->Lines->Add(UnicodeString(_pantalla[i]));

   apli->rtfEdit->ScrollPosition = TPoint(0,0);
   apli->rtfEdit->Visible = true;

   apli->rtfEdit->Refresh();
   apli->Refresh();

   return 0;
}

void JLogo::limpiar(void)
{
   for (int x = 0; x < lineas; x++)
   {
     for (int y = 0; y < columnas; y++)
     {
	_pantalla[x][y] = piso_figura;
     }
   }
}

void JLogo::detente(int lapso)
{
	if (lapso == 0)
	{
	    return;
	}

	apli->sbBarraEstado->Panels->Items[2]->Text = "Detente=" + String(lapso) + " ";

	if (lapso > 0)
	{
            apli->sbBarraEstado->Panels->Items[2]->Text += "segundos";
	    Sleep(lapso * 1000);  // convierte a milisegundos
	}
	else
	{
	    apli->sbBarraEstado->Panels->Items[2]->Text += "milisegundos";
	    lapso = lapso * (-1);  // convierte a valor positivo el lapso de tiempo
	    Sleep(lapso);
	}
}

void JLogo::centropantalla()
{
   col_actual = (columnas / 2) - 1;
   linea_actual = (lineas / 2) - 1;
   _pantalla[linea_actual][col_actual] = tortuga_figura;  // Coloca la tortuga en el centro de la pantalla

   apli->sbBarraEstado->Panels->Items[0]->Text = "Centro x:y=" + String(linea_actual) + ":" + String(col_actual);
}

int JLogo::avance(int pasos)
{
	int status = 0;
		// Se desplaza hacia arriba
	if(direccion == "norte")
	{
		int sube = linea_actual - 1;
		int ln = 0;     // nro de línea
		_pantalla[linea_actual][col_actual] = tortuga_traza;
		while (ln < pasos)
		{
		    _pantalla[sube][col_actual] = tortuga_traza;
		    sube--;
		    ln++;
		}
		linea_actual = sube;
		_pantalla[linea_actual][col_actual] = tortuga_figura;
		return status;
	}
	    // Se desplaza hacia abajo
	if(direccion == "sur")
	{
		int baja = linea_actual + 1;
		int ln = 0;     // nro de línea
		_pantalla[linea_actual][col_actual] = tortuga_traza;
		while (ln < pasos) {
		    _pantalla[baja][col_actual] = tortuga_traza;
		    baja++;
		    ln++;
		}
		linea_actual = baja;
		_pantalla[linea_actual][col_actual] = tortuga_figura;
		return status;
	}
	    // Se desplaza hacia la derecha
	if(direccion == "este")
	{
		int desplazaX = col_actual + 1;
		int cn = 0;     // nro de columna
		_pantalla[linea_actual][col_actual] = tortuga_traza;
		while (cn < pasos) {
		    _pantalla[linea_actual][desplazaX] = tortuga_traza;
		    desplazaX++;
		    cn++;
		}
		col_actual = desplazaX;
		_pantalla[linea_actual][col_actual] = tortuga_figura;
		return status;
	}
	    // Se desplaza por el eje X hacia la izquierda
	if(direccion == "oeste")
	{
		int desplazaXizq = col_actual - 1;
		int cn = 0;     // nro de columna
		_pantalla[linea_actual][col_actual] = tortuga_traza;
		while (cn < pasos) {
		    _pantalla[linea_actual][desplazaXizq] = tortuga_traza;
		    desplazaXizq--;
		    cn++;
		}
		col_actual = desplazaXizq;
		_pantalla[linea_actual][col_actual] = tortuga_figura;
		return status;
	}
	// Error: opcion no conocida
	status = 1;
	apli->sbBarraEstado->Panels->Items[0]->Text = "Dirección: opción no conocida";
	return status;
}

void JLogo::derecha(void)
{
	direccion = "este";
	tortuga_figura = L'►';
	_pantalla[linea_actual][col_actual] = tortuga_figura;

	apli->sbBarraEstado->Panels->Items[1]->Text = "Dirección: " + direccion;
}

void JLogo::izquierda(void)
{
	direccion = "oeste";
	tortuga_figura = L'◄';
	_pantalla[linea_actual][col_actual] = tortuga_figura;

	apli->sbBarraEstado->Panels->Items[1]->Text = "Dirección: " + direccion;
}

void JLogo::subir(void)
{
	direccion = "norte";
	tortuga_figura = L'▲';
	_pantalla[linea_actual][col_actual] = tortuga_figura;

	apli->sbBarraEstado->Panels->Items[1]->Text = "Dirección: " + direccion;
}

void JLogo::bajar(void)
{
	direccion = "sur";
	tortuga_figura = L'▼';
	_pantalla[linea_actual][col_actual] = tortuga_figura;

	apli->sbBarraEstado->Panels->Items[1]->Text = "Dirección: " + direccion;
}

/*
void JLogo::borrapantalla()
{
   clrscr();
}

*/

