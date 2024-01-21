#-------------------------------------------------------------------------------
# Name:        modulo2.py
# Purpose:
#
# Author:      admin
#
# Created:     18/01/2024
# Copyright:   (c) admin 2024
# Licence:     Software Libre
#-------------------------------------------------------------------------------
# from PyQt6.QtWidgets import (QApplication)
from PyQt5.QtWidgets import (QApplication)

# Importa todo lo que tiene el programa AplicacionPrincipal.py
import AplicacionPrincipal as ap

# Visualiza una ventana simple con info. sobre la biblioteca PyQt
def qtVer(qa: QApplication):
    qa.instance().aboutQt()

def inicio():
    aplicacion = QApplication([])
    print(ap.sistema_autor, ap.sistema_fecha)
    print("Licencia " + ap.sistema_licencia)
    qtVer(aplicacion)
