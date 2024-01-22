#-------------------------------------------------------------------------------
# Nombre   : AplicacionPrincipal.py
# Propósito: Mostrar el uso de variables globales entre la aplicación principal
#            y sus módulos. Ejecutar desde la consola de textos:
#            Caso nº 1 => python AplicacionPrincipal.py
#            Caso nº 2 => AplicacionPrincipal.py 2> nul
#            Uso combinado de las bibliotecas PySide y PyQt entre los módulos.
#            Se requiere de una conexión a Internet para consultar la hora actual.
# Observaciones: Aplicación preparada para Windows Server 2008 R2 STD, 2016 STD.
# Autor    : Octulio Biletán.
# Creado   : 18/01/2024.
# Copyright: (c) Octulio Biletán 2024.
# Licencia : Software Libre.
#-------------------------------------------------------------------------------
import os, locale
import modulo1, modulo2

# Bloque de definiciones de variables globales.
sistema_nombre = "Modelo de Sistema Informático Comercial"
sistema_nombre_corto = "msi"
sistema_version = "1.0"
sistema_autor = "© Octulio Biletán"
sistema_fecha = "2024"
sistema_licencia = "Software Libre"
# Fin bloque

def main():
    locale.setlocale(locale.LC_ALL, "spanish_argentina")
    fentrada = modulo2.tiempoLocal()
    tentrada = modulo2.tiempoRed()

    print(sistema_nombre)
    modulo1.inicio()
    modulo2.inicio()

    # Ejecuta comando externo y espera
    # a que termine su ejecución
    proceso = "AcercaDe.py"
    status = os.system(proceso)
    print("status=", status)

    print("____")
    print("Tiempo Internet: " + tentrada)
    print("Tiempo entrada: " + fentrada)
    print("Tiempo salida: " + modulo2.tiempoLocal())
    print("____")

    # Limpia las variables
    tentrada = ""
    fentrada = ""
    status = 0
    proceso = ""

# Aquí comienza todo...
# El punto de entrada.
if __name__ == '__main__':
    main()
