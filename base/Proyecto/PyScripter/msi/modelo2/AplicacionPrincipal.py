#-------------------------------------------------------------------------------
# Name:      AplicacionPrincipal.py
# Purpose:   Mostrar el uso de variables globales entre la aplicación principal
#	     y sus módulos. Ejecutar desde la consola de textos:
#	     Caso nº 1 => python AplicacionPrincipal.py
#	     Caso nº 2 => AplicacionPrincipal.py 2> nul
#	     Uso combinado de las bibliotecas PySide y PyQt entre los módulos.
# Observaciones: Aplicación preparada para Windows Server 2008 R2 STD, 2016 STD.
# Author:    Octulio Biletán.
# Created:   18/01/2024.
# Copyright: (c) Octulio Biletán 2024.
# Licence:   Software Libre.
#-------------------------------------------------------------------------------
import os
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
    print(sistema_nombre)
    modulo1.inicio()
    modulo2.inicio()

    # Ejecuta comando externo y espera
    # a que termine su ejecución
    proceso = "AcercaDe.py"
    status = os.system(proceso)
    print("status=", status)

    # Limpia las variables
    status = 0
    proceso = ""
    
# Aquí comienza todo...
# El punto de entrada.
if __name__ == '__main__':
    main()
