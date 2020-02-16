//---------------------------------------------------------------------------
// Módulo     : config.cpp
// Autor      : eugenio martínez - agosto de 2006
// Descripción: lee el fichero de configuración wciclar.ini
//              última vez modificado en enero de 2020.
// Licencia   : Copyright (C) 2006-2020 - Eugenio Martinez - torrentelinux@gmail.com
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//---------------------------------------------------------------------------

#define STRICT

#include <windows.h>
#include <dos.h>
#include <dir.h>
#include <fstream.h>
#include <string.h>

#include "constantes.h"
#include "wciclar.rh"

// estructura para el fichero de configuración wciclar.ini
extern struct WciclarConfig
{
	// identificador del tipo de salida
        WORD salida;

        // id del recurso sonido
        WORD sonido;

        // Lapso de tiempo expresado en segundos
        // Es el intervalo de actualización de los datos a mostrar en ventana
        UINT lapso_de_tiempo;

        // estilo de la ventana
        DWORD estilo;

        // posición origen sobre el eje X
        int origenX;

        // posición origen sobre el eje Y
        int origenY;

        // el ancho de la ventana
        int ancho;

        // la altura de la ventana
        int alto;

   	// escala de prioridad: 0~200
        UINT escala;

	// el canal alfa para la ventana translúcida, valores entre 0% y 100%
        BYTE alfa;

        // la prioridad del proceso
        DWORD prioridad_proceso;

        // el tipo de prioridad
        char szTipoPrioridad[32];

        // las tres líneas de textos
        char **recurso_texto;

        // el nombre del fichero de configuración
        char *nombre;

} wciclar_ini;

extern struct PrioridadAplicacion
{
   	// escala de prioridad: 0~200
        UINT escala;

        // la prioridad del proceso
        DWORD prioridad;

        // el tipo de prioridad
        char szTipoPrioridad[32];

} proceso[];

struct EstiloVentana
{
        // estilo de la ventana
        DWORD estilo;

        // nombre del estilo de la ventana
        char nombre[32];

} estilo_ventana[] = { { WS_EX_TOPMOST,          "superior" },
                       { WS_EX_OVERLAPPEDWINDOW, "normal"   }
                     };

struct RecursoSonido
{
        // identificador del recurso sonido
        WORD sonido;

        // valor de la opción 'sonido' en wciclar.ini
        char valor[32];

} opcion_sonido[] = { { BIP_01, "normal"   },
                      { TIC_01, "tic"      },
                      { MPOP_1, "mpop"     },
                      { 0,      "silencio" }
                    };

// Comportamiento de la salida de Wciclar
struct ComportamientoSalida
{
	// identificador del tipo de salida
        WORD salida;

        // valor de la opción 'salida' en wciclar.ini
        char valor[32];

} opcion_salida[] = { { SALIDA_NORMAL, "normal" },
                      { SALIDA_RAPIDA, "rápida" },  // con acento
                      { SALIDA_RAPIDA, "rapida" }   // sin acento
                    };

extern unsigned int size_textline;
extern unsigned int max_recurso_texto;
extern HINSTANCE hinst;
char *BuscarValor(char *linea, char *campo);
void FormarNombreWciclar_ini();

void LeerWciclar_ini()
{
        char *valor = NULL;
        char *linea;
        ifstream *fichero;

   // valores predeterminados
   wciclar_ini.prioridad_proceso = proceso[2].prioridad;
   wciclar_ini.escala = proceso[2].escala;
   strcpy(wciclar_ini.szTipoPrioridad, proceso[2].szTipoPrioridad);
   wciclar_ini.lapso_de_tiempo = 3;
   wciclar_ini.estilo = WS_EX_OVERLAPPEDWINDOW;
   wciclar_ini.origenX = wciclar_ini.origenY = CW_USEDEFAULT;
   wciclar_ini.ancho = 280;
   wciclar_ini.alto = 162;
   wciclar_ini.sonido = opcion_sonido[3].sonido;
   wciclar_ini.salida = 0;
   wciclar_ini.alfa = (BYTE)((255 * 90) / 100);

   try
   {
     linea = new char[80];
     wciclar_ini.nombre = new char[MAXPATH];

     FormarNombreWciclar_ini();

     fichero = new ifstream(wciclar_ini.nombre);

     wciclar_ini.recurso_texto = new char* [max_recurso_texto];
     for(unsigned int i = 0; i < max_recurso_texto; i++)
       wciclar_ini.recurso_texto[i] = new char[size_textline];
   }
   catch(...)
   {
     // no hay memoria
     return;
   }

   // Carga recurso texto predeterminado
   for(unsigned int i = 0, j = TEXTO_AUTOR; i < max_recurso_texto; i++, j++)
     LoadString(hinst, j, wciclar_ini.recurso_texto[i], size_textline);

   *linea = '\0';
   fichero->seekg(0L, ios::end);

   if(fichero->tellg() < 0)
   {
      // no se pudo abrir el fichero de configuración
      delete fichero;
      fichero = NULL;

      delete []linea;
      linea = NULL;

      return;
   }

   fichero->seekg(0L, ios::beg);

   fichero->getline(linea, 80);
   if(strcmp(linea, "[wciclar]") != 0)
   {
      // fichero de configuración no válido
      delete fichero;
      fichero = NULL;

      delete []linea;
      linea = NULL;

      return;
   }

   unsigned int nro_linea = 0;

   while(!fichero->eof())
   {
     fichero->getline(linea, 80);

     // ignora comentarios y saltos de líneas
     if(*linea == '\0' || *linea == ';')
       continue;

     // busca el campo 'prioridad'
     valor = BuscarValor(linea, "prioridad");

     if(*valor != '\0')
     {
       for(int i = 0; i < MAX_TIPO_PRIORIDAD; i++)
         if(strcmp(valor, proceso[i].szTipoPrioridad) == 0)
         {
           wciclar_ini.prioridad_proceso = proceso[i].prioridad;
           wciclar_ini.escala = proceso[i].escala;
           strcpy(wciclar_ini.szTipoPrioridad, proceso[i].szTipoPrioridad);
           break;
         }

       continue;
     }

     // busca el campo 'intervalo'
     valor = BuscarValor(linea, "intervalo");
     if(*valor != '\0')
     {
       int resultado = atoi(valor);

       if(resultado > 0)
         wciclar_ini.lapso_de_tiempo = resultado;

       continue;
     }

     // busca el campo 'alfa'
     valor = BuscarValor(linea, "alfa");
     if(*valor != '\0')
     {
       int resultado = atoi(valor);

       if(resultado > 0 && resultado < 100)
         wciclar_ini.alfa = (BYTE)((255 * resultado) / 100);

       continue;                      
     }

     // busca el campo 'ancho'
     valor = BuscarValor(linea, "ancho");
     if(*valor != '\0')
     {
       int resultado = atoi(valor);

       if(resultado > 0 && resultado < 321)
         wciclar_ini.ancho = resultado;

       continue;
     }

     // busca el campo 'alto'
     valor = BuscarValor(linea, "alto");
     if(*valor != '\0')
     {
       int resultado = atoi(valor);

       if(resultado > 0 && resultado < 241)
         wciclar_ini.alto = resultado;

       continue;
     }

     // busca el campo 'origen_x'
     valor = BuscarValor(linea, "origen_x");
     if(*valor != '\0')
     {
       wciclar_ini.origenX = atoi(valor);
       continue;
     }

     // busca el campo 'origen_y'
     valor = BuscarValor(linea, "origen_y");
     if(*valor != '\0')
     {
       wciclar_ini.origenY = atoi(valor);
       continue;
     }

     // busca el campo 'estilo'
     valor = BuscarValor(linea, "estilo");
     if(*valor != '\0')
     {
       for(int i = 0; i < 2; i++)
         if(strcmp(valor, estilo_ventana[i].nombre) == 0)
         {
           wciclar_ini.estilo = estilo_ventana[i].estilo;
           break;
         }

       continue;
     }

     // busca el campo 'sonido'
     valor = BuscarValor(linea, "sonido");
     if(*valor != '\0')
     {
       for(int i = 0; i < sizeof(opcion_sonido)/sizeof(opcion_sonido[0]); i++)
         if(strcmp(valor, opcion_sonido[i].valor) == 0)
         {
           wciclar_ini.sonido = opcion_sonido[i].sonido;
           break;
         }

       continue;
     }

     // busca el campo 'salida'
     valor = BuscarValor(linea, "salida");
     if(*valor != '\0')
     {
       for(int i = 0; i < sizeof(opcion_salida)/sizeof(opcion_salida[0]); i++)
         if(strcmp(valor, opcion_salida[i].valor) == 0)
         {
           wciclar_ini.salida = opcion_salida[i].salida;
           break;
         }

       continue;
     }

     // busca los campos 'linea_texto'
     if(nro_linea < max_recurso_texto)
     {
       valor = BuscarValor(linea, "linea_texto");
       if(*valor != '\0')
       {
         strncpy(wciclar_ini.recurso_texto[nro_linea], valor, 65);
         if(strlen(valor) > 65)
           wciclar_ini.recurso_texto[nro_linea][65] = '\0';

         nro_linea++;
       }
     }
   }  // fin while()

   delete[] linea;
   delete fichero;
}

char *BuscarValor(char *linea, char *campo)
{
        static char resultado[80];
        char *r, *rr;

   *resultado = '\0';

   r = strstr(linea, campo);
   if(r)
   {
     rr = strchr(r, '=');
     if(rr)
       strcpy(resultado, ++rr);
   }

   return resultado;
}

void FormarNombreWciclar_ini()
{
    	char drive[MAXDRIVE];
    	char dir[MAXDIR];
    	char file[MAXFILE];
    	char ext[MAXEXT];

   fnsplit(_argv[0], drive, dir, file, ext);
   fnmerge(wciclar_ini.nombre, drive, dir, file, "ini");
}
