#-------------------------------------------------------------------------------
# Name:        AplicacionPrincipal.py
# Purpose:     Mostrar el uso de variables globales
#              entre la aplicación principal y sus módulos.
#              Ejecutar desde la consola de textos: python AplicacionPrincipal.py
# Author:      admin
#
# Created:     18/01/2024
# Copyright:   (c) admin 2024
# Licence:     Software Libre
#-------------------------------------------------------------------------------
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
    print(sistema_nombre, '(', sistema_nombre_corto, ')')
    modulo1.inicio()
    modulo2.inicio()

# Aquí comienza todo...
# El punto de entrada.
if __name__ == '__main__':
    main()
