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

# Modificar Librería PyQt5/PyQt6
from PyQt6.QtWidgets import *
from PyQt6.QtCore import *
from PyQt6.QtGui import *
from PyQt6.QtPrintSupport import *
from PyQt6.uic import loadUi

class Mensaje():
    # visualiza un mensaje de texto en una ventana simple
    def visualizar(self, msj:str):
        vGraf = QMessageBox()
        vGraf.setWindowTitle("Aviso")
        vGraf.setText(msj)
        vGraf.setIcon(vGraf.Icon.Information)
        vGraf.exec()

    # muestra un mensaje de texto en la consola de textos.
    def mostrar(self, msj: str):
        print(msj)

# Las aplicaciones registradas en esta clase son Google, Google Gmail, Telegram y WhatsApp
class Aplicaciones():
    def navegador(self, txt_url: str)-> None:
        webbrowser.open(txt_url)

    def BuscadorGoogle(self)-> None:
        self.navegador("https://www.google.com/")

    def CorreoGoogle(self)-> None:
        self.navegador("https://mail.google.com/mail/")

    def Telegram(self)-> None:
        self.navegador("https://www.telegram.org/dl/web")

    def WhatsApp(self)-> None:
        self.navegador("https://web.whatsapp.com")

class VentanaPrincipal(QMainWindow):
    def __init__(self):
        super(VentanaPrincipal, self).__init__()
        self.vp = loadUi("VentanaPrincipal.ui", self)

        self.dlgAcercaDe = QDialog()
        loadUi("AcercaDe.ui", self.dlgAcercaDe)

        # muestra la ventana de "Acerca de..."
        self.dlgAcercaDe.exec()

        # vincula opción de menú "Preferencias" con método 'actionPrefs'
        self.vp.actionPreferencias.triggered.connect(self.actionPrefs)

        # vincula opción de menú "Sistema/Abrir Sesión" con método 'actionAbrirS'
        self.vp.actionAbrirSesion.triggered.connect(self.actionAbrirS)

        # vincula opción de menú "Sistema/Operaciones/Generar Informes/Imprimir" con método 'actionDlgImpresora'
        self.vp.actionImpresora.triggered.connect(self.actionDlgImpresora)

        # vincula opción de menú "Sistema/Centro de Operaciones/Impresión" con método 'actionDlgImpresion'
        self.vp.actionImpresion.triggered.connect(self.actionDlgImpresion)

        # vincula opción de menú "Telegram" con método 'actionTelegramWeb'
        self.vp.actionTelegram.triggered.connect(self.actionTelegramWeb)

        # vincula opción de menú "WhatsApp" con método 'actionWhatsAppWeb'
        self.vp.actionWhatsApp.triggered.connect(self.actionWhatsAppWeb)

        # vincula opción de menú "Google Gmail" con método 'actionGmailWeb'
        self.vp.actionGoogleGmail.triggered.connect(self.actionGmailWeb)

        # vincula opción de menú "Google" con método 'actionGoogleWeb'
        self.vp.actionGoogle.triggered.connect(self.actionGoogleWeb)

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
        self.consola = Mensaje()
        self.consola.mostrar("Opción no disponible.")

    # evento respuesta para "Sistema/Operaciones/Generar Informes/Imprimir"
    def actionDlgImpresora(self):
        QPrintDialog(self).exec()

    # evento respuesta para "Sistema/Centro de Operaciones/Impresión"
    def actionDlgImpresion(self):
        QPageSetupDialog(self).exec()

    # evento respuesta para "Aplicaciones/Telegram"
    def actionTelegramWeb(self):
        print("Invocando a Telegram Web")
        Aplicaciones().Telegram()

    # evento respuesta para "Aplicaciones/WhatsApp"
    def actionWhatsAppWeb(self):
        print("Invocando a WhatsApp Web")
        Aplicaciones().WhatsApp()

    # evento respuesta para "Aplicaciones/Google"
    def actionGoogleWeb(self):
        print("Invocando a buscador Google")
        Aplicaciones().BuscadorGoogle()

    # evento respuesta para "Aplicaciones/Google Gmail"
    def actionGmailWeb(self):
        print("Invocando a correo-e de Google")
        Aplicaciones().CorreoGoogle()

    # evento respuesta para "Ayuda/Acerca de..."
    def actionAcerca_de(self):
        print("Acerca De: evento accionado.")
        self.dlgAcercaDe.exec()

    # evento respuesta para "Ayuda/Leer Manual Introductorio"
    # abre el navegador web por omisión de Windows para visualizar docu. básica
    def actionLeerManualIntroductorio(self):
        # ubicación local o remota de la docu. básica del Sistema Informático Comercial.
        # opcional: https://tu_sitio/tu_carpeta/docu.html
        self.htmlDocu = "file:///c:/base/Proyecto/PyScripter/msi/modelo4/docu.html"
        print("Leer manual introductorio: " + self.htmlDocu)
        Aplicaciones().navegador(self.htmlDocu)

# La función main()
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

# Desde aquí comienza todo...
if __name__ == '__main__':
    main()
