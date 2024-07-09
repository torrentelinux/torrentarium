/* Programa : reloj.c
   Autor    : Eugenio Martínez
   Propósito: Mostrar la fecha y hora del sistema, además permite su
              modificación por parte del usuario.
   Obs.     : Código preparado para Borland C++ 3.1 o superior (MSDOS, Windows)
              y para GNU/C (Linux).
              Se requiere del comando curl.exe para consultar el tiempo desde internet.
*/

#define __FOBSOLETE__
#include "pragma.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#if defined(__MSDOS__) || (__CONSOLE__)
#  include <dos.h>
#endif

#if defined(_Windows) && (__CONSOLE__)
#  include <windows.h>
#endif

#include "macros.h"

/* revisa los parámetros /?, ayuda, hora, fecha, ajuste */
int parametros(char *param);

/* muestra una ayuda */
int ayuda(void);

/* modifica la hora */
int hora(void);

/* modifica la fecha */
int fecha(void);

/* ajusta el tiempo mediante una conexión a internet */
int ajuste(void);

/* muestra un mensaje de error */
int error(void);

/* muestra la hora y fecha actual del reloj del sistema */
void fecha_actual(void);

/* muestra el tiempo vigente del reloj local */
void tiempo_actual(void);

/* convierte una cadena de caracteres a minúsculas */
char *euge_strlwr(char *s);

/* revisa los rangos permitidos en la hora */
int hora_rango(struct tm *t);

/* revisa los rangos permitidos en la fecha */
int fecha_rango(struct tm *t);

/* devuelve el nombre del día vigente de la semana */
char *hoy_dia(void);

/* devuelve la cantidad de días transcurridos desde el comienzo del año vigente */
int ndias(void);

#ifdef __linux__
char autor[] = "(c)Eugenio Martínez (2001-2024) - Tucumán - Arg.";

/* los nombres de los días de la semana */
char *dias[16] = { "domingo", "lunes", "martes", "miércoles",
		   "jueves", "viernes", "sábado", ""
		 };
#else
char autor[] = "(c)Eugenio Mart¡nez (2001-2024) - Tucum n - Arg.";

/* los nombres de los d¡as de la semana */
char *dias[16] = { "domingo", "lunes", "martes", "mi‚rcoles",
		   "jueves", "viernes", "s bado", ""
		 };
#endif


/* Un arreglo de punteros a funciones que no reciben parámetros y que
   devuelven un valor entero
*/
int (*ptrfunc[])(void) = { ayuda,         /* opción 0 */
                           hora,          /* opción 1 */
                           fecha,         /* opción 2 */
                           ajuste,        /* opción 3 */
                           error,         /* opción 4 */
                           0
                         };

#define Ejecute(accion)         (*ptrfunc[accion])()

int main(int argc, char **argv)
{
        int i, opcion, estado;

   puts("Reloj del sistema.");

   if(argc == 1)
     fecha_actual();
   else
   {
     for(i = 1; i < argc; i++)
     {
       opcion = parametros(argv[i]);
       estado = Ejecute(opcion);
       if(estado == -1)
         break;
     }
   }

   return 0;
}

int parametros(char *param)
{
        char *opcion;

   /* convierte a minúsculas */
   opcion = euge_strlwr(param);

   /* solicita una ayuda */
   if(strcmp("/?", opcion) == 0 || strcmp("--ayuda", opcion) == 0)
     return 0;

   /* elije modificar la hora */
   if(strcmp("hora", opcion) == 0)
     return 1;

   /* elije modificar la fecha */
   if(strcmp("fecha", opcion) == 0)
     return 2;

   /* elije ajustar el tiempo */
   if(strcmp("ajuste", opcion) == 0)
     return 3;
   /* opción no reconocida */
   else
     return 4;
}

void fecha_actual(void)
{
#if defined __linux__ || defined __WATCOMC__

        time_t tiempo;
        struct tm *hora;
        struct tm *fecha;

   /* obtiene la hora y la fecha actual del sistema */
    tiempo = time(NULL);
    hora = localtime(&tiempo);
    fecha = hora;

   /* muestra la hora, la fecha actual, la dif. horaria y la zona horaria */
   printf("Son las %d horas, %d minutos, %d segundos\n",
           hora->tm_hour, hora->tm_min, hora->tm_sec);

   printf("Hoy es %s %02d/%02d/%d, %05ld %s\n", dias[fecha->tm_wday],
           fecha->tm_mday, (fecha->tm_mon + 1), (fecha->tm_year + 1900),
          (fecha->tm_gmtoff/3600)*100, fecha->tm_zone);

#else
	int estado = -1;
        struct time hora;
        struct date fecha;

   /* obtiene la fecha actual del sistema */
   getdate(&fecha);

   /* muestra la fecha */
   printf("Hoy es %s %02d/%02d/%d, %d d¡as transcurridos desde el comienzo del a¤o.\n",
          hoy_dia(), fecha.da_day, fecha.da_mon, fecha.da_year, ndias());

   /* obtiene la hora actual del sistema */
   gettime(&hora);

   /* muestra la hora */
   printf("Son las %d horas, %d minutos, %d segundos\n",
           hora.ti_hour, hora.ti_min, hora.ti_sec);

   /* Windows consola, 32 bits o más */
#ifdef _Windows
   puts("Reloj de internet:");
   estado = system("curl --url https://worldtimeapi.org/api/ip.txt 2>nul|findstr /C:\"datetime\"");
   if(estado != 0)
     puts("Advertencia: No se pudo consultar el tiempo desde el sitio 'worldtimeapi.org'");
#endif

#endif
}

int hora(void)
{
#ifdef __linux__
	int status;
	time_t tiempo;
        struct tm nhora, *hora;
        char teclado = NULO;
        char mensaje[] = "\nNuevo horario (hh:mm:ss): ";
        char dato[20] = { NULO };

    tiempo = time(NULL);
    hora = localtime(&tiempo);
    memmove(&nhora, hora, sizeof(struct tm));

   /* muestra la hora actual */
   printf("Es la hora: %02d:%02d:%02d%s",
           hora->tm_hour, hora->tm_min, hora->tm_sec, mensaje);
   do
   {
     scanf("%8[0-9:]s", dato);

     /* ignora la tecla ENTER */
     scanf("%*c", &teclado);

     if(strlen(dato) != 0)
     {
       sscanf(dato, "%d:%d:%d", &nhora.tm_hour, &nhora.tm_min, &nhora.tm_sec);

       if(hora_rango(&nhora) == CIERTO)
       {
         tiempo = mktime(&nhora);
         if(tiempo != -1)
         {
           status = stime(&tiempo);
           if(status == -1)
           {
             perror("No se pudo modificar la hora.\n"
                    "Sólo el 'root' puede modificar el reloj del sistema.");
             exit(1);
           }

           break;
         }

       }

       printf("Hora incorrecta.");
       *dato = NULO;
     }

     printf("%s", mensaje);

   } loop;

#else

        int estado = 0;
        struct dostime_t actual = { 0, 0, 0, 0 };
        struct time hora;
        char teclado = NULO,
             mensaje[] = "\nNuevo horario (hh:mm:ss): ",
             dato[20] = { NULO };

   gettime(&hora);
   printf("Es la hora: %02d:%02d:%02d%s",
          hora.ti_hour, hora.ti_min, hora.ti_sec, mensaje);

   do
   {
     scanf("%8[0-9:]s", dato);

     /* ignora la tecla ENTER */
     scanf("%*c", &teclado);

     if(strlen(dato) != 0)
     {
       sscanf(dato, "%u:%u:%u", &actual.hour, &actual.minute, &actual.second);

       estado = _dos_settime(&actual);
       if(estado == 0)
         break;

       printf("Hora incorrecta.");
       *dato = NULO;
     }

     printf("%s", mensaje);

   } loop;

#endif

   return 0;
}

int fecha(void)
{
#ifdef __linux__
        int status;
        time_t tiempo;
        struct tm nfecha, *fecha;
        char teclado = NULO,
             mensaje[] = "\nNueva fecha (dd/mm/aaaa): ",
             dato[20] = { NULO };

    tiempo = time(NULL);
    fecha = localtime(&tiempo);
    memmove(&nfecha, fecha, sizeof(struct tm));

   /* muestra la fecha actual */
   printf("Hoy es %s %02d/%02d/%d%s", dias[fecha->tm_wday],
           fecha->tm_mday, (fecha->tm_mon + 1), (fecha->tm_year + 1900),
           mensaje);

   do
   {
     scanf("%10[0-9/]s", dato);

     /* ignora la tecla ENTER */
     scanf("%*c", &teclado);

     if(strlen(dato) != 0)
     {
       sscanf(dato, "%2d/%2d/%4d", &nfecha.tm_mday, &nfecha.tm_mon,
                                   &nfecha.tm_year);

       /* hace ajustes en la fecha */
       nfecha.tm_mon--;
       nfecha.tm_year -= 1900;

       if(fecha_rango(&nfecha) == CIERTO)
       {
         tiempo = mktime(&nfecha);
         if(tiempo != -1)
         {
           status = stime(&tiempo);
           if(status == -1)
           {
             perror("No se pudo modificar la fecha.\n"
                    "Sólo el 'root' puede modificar el reloj del sistema.");
             exit(1);
           }

           break;
         }

       }

       printf("Fecha incorrecta.");
       *dato = NULO;
     }

     printf("%s", mensaje);

   } loop;

#else
        int estado = 0;
        struct dosdate_t actual = { 0, 0, 0, 0 };
        struct date fecha;
        char teclado = NULO,
             mensaje[] = "\nNueva fecha (dd/mm/aaaa): ",
             dato[20] = { NULO };

   getdate(&fecha);
   printf("Hoy es: %02d/%02d/%d%s", fecha.da_day, fecha.da_mon,
                                    fecha.da_year, mensaje);

   do
   {
     scanf("%10[0-9/]s", dato);

     /* ignora la tecla ENTER */
     scanf("%*c", &teclado);

     if(strlen(dato) != 0)
     {
       sscanf(dato, "%2u/%2u/%4u", &actual.day, &actual.month, &actual.year);

       estado = _dos_setdate(&actual);
       if(estado == 0)
         break;

       printf("Fecha incorrecta.");
       *dato = NULO;
     }

     printf("%s", mensaje);

   } loop;

#endif

   return 0;
}

int ajuste(void)
{
#ifdef __linux__
   puts("ajuste(): Función no implementada.\n");
   return 0;
#else
	int estado = -1;

   /* << Windows >>
     Puede revisar la lista de servidores con el siguiente comando:
     'control timedate.cpl', pestaña "Internet Time".
     Para Argentina: ntp1.hidro.gob.ar <> ntp2.hidro.gob.ar <> ntp.ign.gob.ar
     Para el resto del mundo: time.windows.com
   */
   puts("Ajuste del reloj del sistema desde internet: aguarde un momento...");
   puts("<Lectura inicial>");
   tiempo_actual();

   /* Invoca al comando w32tm.exe de Windows para reajustar el reloj interno */
   estado = system("w32tm.exe /resync");
   if(estado != 0)
     puts("Advertencia: No se pudo consultar el tiempo desde internet.");
   else
     puts("Ok.");

   puts("<Lectura final>");
   tiempo_actual();

   return 0;
#endif
}

char *euge_strlwr(char *s)
{
#ifdef __linux__
        char *tmp = s;

   while(*tmp != '\0')
   {
     *tmp = tolower(*tmp);
     tmp++;
   }

   return s;

#else

   return (strlwr(s));

#endif
}

int hora_rango(struct tm *t)
{
    if(t->tm_hour >= 0 && t->tm_hour <= 23)
      if(t->tm_min >= 0 && t->tm_min <= 59)
        if(t->tm_sec >= 0 && t->tm_sec <= 61)
          return CIERTO;

    return FALSO;
}

int fecha_rango(struct tm *t)
{
    if(t->tm_mday >= 1 && t->tm_mday <= 31)
      if(t->tm_mon >= 0 && t->tm_mon <= 11)
        if(t->tm_year >=0)
          return CIERTO;

    return FALSO;
}

int ayuda(void)
{
   puts("Utilidad RELOJ v1.07.24");
   puts(autor);

#if defined(__MSDOS__) || (__CONSOLE__)
/* acentos para MS-DOS */

   puts("\nForma  I: RELOJ /? | --ayuda ==> muestra una ayuda\n"
        "Forma II: RELOJ [fecha | hora | ajuste]\n"
        "Esta utilidad muestra la hora y fecha actual del sistema.\n"
        "Es posible adem s modificar tanto la hora como la fecha, de manera individual\n"
        "o ambas al mismo tiempo.\n"
        "Para cancelar el ingreso de datos presione las teclas CTRL+C.\n"
        "El formato de la hora es: hh:mm:ss\n"
        "El formato de la fecha es: dd/mm/aaaa");

   puts("Los valores m¡nimos y m ximos para la hora y la fecha son:\n\n"
        "hora: 0-23 <> minutos: 0-59 <> segundos: 0-59\n"
        "d¡a : 1-31 <> mes    : 1-12 <> a¤o     : 1980-2099\n\n"
        "Ejemplos:\n"
        "RELOJ             ==> visualiza la hora y fecha actual (local e internet)\n"
        "RELOJ hora        ==> permite modificar la hora del computador\n"
        "RELOJ fecha       ==> permite modificar la fecha del computador\n"
        "RELOJ fecha hora  ==> permite que se modifiquen la fecha y hora del computador\n"
        "RELOJ ajuste      ==> permite sincronizar el reloj de la PC con el reloj de internet");
#else
/* acentos para LINUX */

   puts("\nForma  I: RELOJ /? | --ayuda ==> muestra una ayuda\n"
        "Forma II: RELOJ [fecha | hora]\n"
        "Esta utilidad muestra la hora y fecha actual del sistema.\n"
        "Es posible además modificar tanto la hora como la fecha, de manera individual\n"
        "o ambas al mismo tiempo.\n"
        "Para cancelar el ingreso de datos presione las teclas CTRL+C.\n"
        "El formato de la hora es: hh:mm:ss\n"
        "El formato de la fecha es: dd/mm/aaaa");

   puts("Los valores mínimos y máximos para la hora y la fecha son:\n\n"
        "hora: 0-23 <> minutos: 0-59 <> segundos: 0-61 (segundos bisiestos)\n"
        "día : 1-31 <> mes    : 1-12 <> año     : 1900-....\n\n"
        "Ejemplos:\n"
        "RELOJ             ==> visualiza la hora y fecha actual\n"
        "RELOJ hora        ==> permite modificar la hora del computador\n"
        "RELOJ fecha       ==> permite modificar la fecha del computador\n"
        "RELOJ fecha hora  ==> permite que se modifiquen la fecha y hora del computador");
#endif

   return -1;   /* regresa al shell inmediatamente */
}

int error(void)
{
#ifdef __linux__
   puts("Opción no reconocida.\n"
#else
   puts("Opci¢n no reconocida.\n"
#endif
        "Use RELOJ /? o --ayuda para una ayuda explicativa.");

   return -1;   /* regresa al shell inmediatamente */
}

void tiempo_actual(void)
{
#ifdef _Windows
        struct time hora;
        struct date fecha;
	TIME_ZONE_INFORMATION TimeZoneInfo;

   /* obtiene la hora y la fecha actual del sistema */
   gettime(&hora);
   getdate(&fecha);

   /* obtiene info. de la zona horaria vigente */
   GetTimeZoneInformation(&TimeZoneInfo);

   /* muestra el tiempo local actual */
   printf("%d hr %d mi %d,%d se [*] %02d/%02d/%d [*] ",
          hora.ti_hour, hora.ti_min, hora.ti_sec, hora.ti_hund,
          fecha.da_day, fecha.da_mon, fecha.da_year);

   /* Muestra el nombre de la zona horaria */
   _putws(TimeZoneInfo.StandardName);
#else
        struct time hora;
        struct date fecha;

   gettime(&hora);
   getdate(&fecha);

   printf("%d hr %d mi %d,%d se [*] %02d/%02d/%d\n",
          hora.ti_hour, hora.ti_min, hora.ti_sec, hora.ti_hund,
          fecha.da_day, fecha.da_mon, fecha.da_year);
#endif
}

char *hoy_dia(void)
{
        time_t tiempo = 0;
        struct tm *fecha = NULL;

   tiempo = time(NULL);
   fecha = localtime(&tiempo);

   return dias[fecha->tm_wday];
}

int ndias(void)
{
        time_t tiempo = 0;
        struct tm *fecha = NULL;

   tiempo = time(NULL);
   fecha = localtime(&tiempo);

   return fecha->tm_yday;
}
