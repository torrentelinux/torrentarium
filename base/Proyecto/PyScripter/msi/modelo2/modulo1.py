#-------------------------------------------------------------------------------
# Name:        modulo1.py
# Purpose:
#
# Author:      admin
#
# Created:     18/01/2024
# Copyright:   (c) admin 2024
# Licence:     Software Libre
#-------------------------------------------------------------------------------
#import PySide6 as ps6
from PySide2.QtWidgets import QApplication

# Importa todo lo que tiene el programa AplicacionPrincipal.py
import AplicacionPrincipal as ap

def PySideVer(qa: QApplication)->str:
    return qa.instance().applicationVersion()

def PySideNombre(qa: QApplication)->str:
    return qa.instance().applicationName()

def inicio():
    aplicacion = QApplication([])
    print(ap.sistema_nombre_corto, "versión " + ap.sistema_version)
    print(PySideNombre(aplicacion), "versión " + PySideVer(aplicacion))
