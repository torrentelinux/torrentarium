#-------------------------------------------------------------------------------
# Name:        AcercaDe.py
# Purpose:
#
# Author:      Octulio Biletán
#
# Created:     11/11/2023
# Copyright:   (c) Octulio Biletán 2023
# Licence:     Software Libre * GNU/GPL
# Referencias: https://doc.qt.io/qtforpython-5/tutorials/basictutorial/uifiles.html
#-------------------------------------------------------------------------------
# -*- coding: utf-8 -*-
from __future__ import unicode_literals

import locale
import os, sys

# Librería PySide2. Hasta Windows Server 2008 R2
from PySide2.QtCore import *
from PySide2.QtWidgets import *
from PySide2.QtGui import *
from PySide2.QtUiTools import QUiLoader

# Librería PySide6. Hasta Windows Server 2022
#from PySide6.QtCore import *
#from PySide6.QtWidgets import *
#from PySide6.QtGui import *
#from PySide6.QtUiTools import QUiLoader

def leerVntAcercaDe()->QWidget:
    ui_file_name = "AcercaDe.ui"

    ui_file = QFile(ui_file_name)
    if not ui_file.open(QIODevice.ReadOnly):
        print("No se puede abrir {}: {}".format(ui_file_name, ui_file.errorString()))
        sys.exit(-1)

    loader = QUiLoader()
    vAcercaDe = loader.load(ui_file)
    vAcercaDe.setWindowOpacity(0.85)

    ui_file.close()
    if not vAcercaDe:
        print(loader.errorString())
        sys.exit(-1)

    return vAcercaDe

# Bloque principal --
if __name__ == '__main__':
    locale.setlocale(locale.LC_ALL, 'spanish_argentina')
    miAplicacion = QApplication([])
    miAplicacion.setApplicationDisplayName("Acerca De...")
    miAplicacion.setApplicationVersion("1.0")

    vAcercaDe = leerVntAcercaDe()
    vAcercaDe.show()

    # Ejecuta la aplicación y luego regresa al S.O.
    sys.exit(miAplicacion.exec_())
