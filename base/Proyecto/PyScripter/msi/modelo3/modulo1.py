#-------------------------------------------------------------------------------
# Name:        modulo1.py
# Purpose:
#
# Author:      admin
# Referencias: https://codeloop.org/python-tutorial-create-messagebox-with-pyside2/
# Created:     22/01/2024
# Copyright:   (c) admin 2024
# Licence:     Software Libre
#-------------------------------------------------------------------------------
from PySide6.QtWidgets import *
from PySide6.QtCore import *
from PySide6.QtGui import *

import time as tiempo

def tiempoLocal()->str:
    return tiempo.ctime()

class RegistroDeActividades():
    """Clase RegistroDeActividades."""

    def registrar(self, msj:str):
        """Registra con marca de tiempo la actividad mencionada en 'msj'."""

        mensaje = "%s<>%s." % (tiempoLocal(), msj)
        vGraf = QMessageBox()
        vGraf.setWindowTitle("Registrar")
        vGraf.setText(mensaje)
        vGraf.setIcon(vGraf.Icon.Information)
        vGraf.exec()

# ___________________________________________________________
def inicio():
    aplicacion = QApplication([])
