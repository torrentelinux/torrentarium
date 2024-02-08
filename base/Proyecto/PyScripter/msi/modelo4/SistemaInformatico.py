#-------------------------------------------------------------------------------
# Nombre:    SistemaInformatico.py
# Propósito: Servir de modelo para la construcción 'real' de
#            un sistema informático comercial.
# Autor:     Octulio Biletán
# Creado:    11/11/2023
# Copyright: (c) Octulio Biletán 2023-2024
# Licencia:  Software Libre * GNU/GPL
#-------------------------------------------------------------------------------
# -*- coding: utf-8 -*-
from __future__ import unicode_literals
import os, sys, locale, webbrowser

# Librería PyQt5/PyQt6
from PyQt6.QtWidgets import *
from PyQt6.QtCore import *
from PyQt6.QtGui import *
from PyQt6.uic import loadUi

class Mensaje():
    # visualiza un mensaje de texto en una ventana simple
    def visualizar(self, msj:str):
        vGraf = QMessageBox()
        vGraf.setWindowTitle("Aviso")
        vGraf.setText(msj)
        vGraf.setIcon(vGraf.Icon.Information)
        vGraf.exec()

class VentanaPrincipal(QMainWindow):
    # ubicación local o remota de la docu. básica del Sistema Informático Comercial.
    self.htmlDocu = "file:///C:/base/Proyecto/PyScripter/msi/modelo4/docu.html"

    def __init__(self):
        super(VentanaPrincipal, self).__init__()
        self.vp = loadUi("VentanaPrincipal.ui", self)

        self.dlgAcercaDe = QDialog()
        loadUi("AcercaDe.ui", self.dlgAcercaDe)

        # muestra la ventana de "Acerca de..."
        self.dlgAcercaDe.exec()

        # vincula opción de menú "Preferencias" con método 'actionPrefs'
        self.vp.actionPreferencias.triggered.connect(self.actionPrefs)

        # vincula opción de menú "Abrir Sesión" con método 'actionAbrirS'
        self.vp.actionAbrirSesion.triggered.connect(self.actionAbrirS)

        # vincula opción de menú "Acerca de..." con método 'actionAcerca_de'
        self.vp.actionAcercaDe.triggered.connect(self.actionAcerca_de)

        # vincula opción de menú "Leer Manual Introductorio" con método 'actionLeerManualIntroductorio'
        # esto es: emisor-señal-receptor-slot
        self.vp.actionLeerManualIntro.triggered.connect(self.actionLeerManualIntroductorio)

    # evento respuesta para "Editar/Preferencias"
    def actionPrefs(self):
        Mensaje().visualizar("Opción no disponible.")

    # evento respuesta para "Sistema/Abrir Sesión"
    def actionAbrirS(self):
        Mensaje().visualizar("Opción no disponible.")

    # evento respuesta para "Ayuda/Acerca de..."
    def actionAcerca_de(self):
        print("Acerca De: evento accionado.")
        self.dlgAcercaDe.exec()

    # evento respuesta para "Ayuda/Leer Manual Introductorio"
    # abre el navegador web por omisión de Windows para visualizar docu. básica
    def actionLeerManualIntroductorio(self):
        print("Leer manual introductorio: evento accionado.")
        webbrowser.get('windows-default').open(self.htmlDocu)

def main():
    # ajusta la localía para Español/Argentina en el S.O.
    locale.setlocale(locale.LC_ALL, 'spanish_argentina')

    # crea una instancia de QApplication.
    miAplicacion = QApplication(sys.argv)

    miAplicacion.setApplicationDisplayName("Sistema")
    miAplicacion.setApplicationVersion("1.4")

    # crea una instancia de VentanaPrincipal.
    vPrincipal = VentanaPrincipal()

    # Establece opacidad a la Ventana principal.
    vPrincipal.setWindowOpacity(0.85)

    # Muestra la Ventana principal en la pantalla.
    vPrincipal.show()

    # Ejecuta la aplicación y luego sale de la aplicación
    # devolviendo al S.O. un código de salida.
    sys.exit(miAplicacion.exec())

if __name__ == '__main__':
    main()
