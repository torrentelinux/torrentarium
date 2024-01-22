#-------------------------------------------------------------------------------
# Nombre   : AplicacionPrincipal.py
# Propósito: Uso de PySide6 y QMessageBox.
# Observaciones: Aplicación preparada para Windows Server 2008 R2 STD, 2016 STD.
# Autor    : Octulio Biletán.
# Creado   : 22/01/2024.
# Copyright: (c) Octulio Biletán 2024.
# Licencia : Software Libre.
#-------------------------------------------------------------------------------
import os, locale
import modulo1 as m1
from modulo1 import RegistroDeActividades

# Bloque de definiciones de variables globales.
sistema_nombre = "Modelo de Sistema Informático Comercial"
sistema_nombre_corto = "msi"
sistema_version = "1.3"
sistema_autor = "© Octulio Biletán"
sistema_fecha = "2024"
sistema_licencia = "Software Libre"
# Fin bloque

def main():
    locale.setlocale(locale.LC_ALL, "spanish_argentina")
    ra = RegistroDeActividades()

    print(sistema_nombre)
    m1.inicio()

    ra.registrar("Entrada al sistema.")

    # Limpia las variables y sale
    status = 0
    ra.registrar("Salida del sistema.")

# Aquí comienza todo...
# El punto de entrada.
if __name__ == '__main__':
    main()
