#-------------------------------------------------------------------------------
# Nombre:      poema-visualizar.py
# Propósito:   Visualizar un poema en una ventana gráfica.
#              Las opciones disponibles son nuevo, leer, guardar e imprimir.
#              El fichero "poema" es un fichero de textos con extensión .poe
#              y codificación utf-8.
#              Funciona con las bibliotecas PySide2, PySide6 y PyQt5.
# Autor:       Octulio Biletán.
# Creado:      22/10/2023
# Copyright:   (c) Octulio Biletán 2023.
# Licencia:    Software Libre.
#-------------------------------------------------------------------------------
# -*- coding: utf-8 -*-
from __future__ import unicode_literals

import locale, sys

# Modificar para PySide2/PySide6/PyQt5
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtPrintSupport import *

class Poema(QWidget):
    def __init__(self, parent=None):
        super(Poema, self).__init__(parent)
        self.form()

        # contador de poemas guardados
        self.nro = 1

    def form(self)->QWidget:
        self.w1 = self
        self.w1.setAutoFillBackground(True)
        self.w1.setWindowTitle("Gestión de poemas")
        self.w1.resize(450, 700)
        self.w1.setCursor(Qt.ArrowCursor)
        #self.w1.setCursor(QCursor(Qt.CursorShape.ArrowCursor))
        self.w1.setToolTip("")

        # caja de textos
        self.text1 = QTextEdit(self.w1)
        self.text1.setText("	A mis amigos\n\nA mis amigos les adeudo la ternura\ny las palabras de aliento y el abrazo;\nel compartir con todos ellos la factura\nque nos presenta la vida, paso a paso.\n\nA mis amigos les adeudo la paciencia\nde tolerarme las espinas más agudas;\nlos arrebatos de humor, la negligencia,\nlas vanidades, los temores y las dudas.\n\nUn barco frágil de papel,\nparece a veces la amistad\npero jamás puede con él\nla más violenta tempestad\nporque ese barco de papel,\ntiene aferrado a su timón\npor capitán y timonel:\nun corazón\n\nA mis amigos les adeudo algún enfado\nque perturbara sin querer nuestra armonía\nsabemos todos que no puede ser pecado\nel discutir, alguna vez, por tonterías.\n\nA mis amigos legaré cuando me muera\nmi devoción un acorde de guitarra\ny entre los versos olvidados de un poema,\nmi pobre alma incorregible de cigarra.\n\nUn barco frágil de papel,\nparece a veces la amistad\npero jamás puede con él\nla más violenta tempestad\nporque ese barco de papel,\ntiene aferrado a su timón\npor capitán y timonel:\nun corazón\n\nAmigo mío si esta copla como el viento,\nadonde quieras escucharla te reclama,\nserás plural, porque lo exige el sentimiento\ncuando se lleva a los amigos en el alma.\n\n	Autor del poema: Alberto Cortéz")
        self.text1.move(20, 40)
        self.text1.resize(310, 650)
        self.text1.setFont(QFont("MS Shell Dlg 2", 10))
        self.text1.setCursor(Qt.ArrowCursor)
        self.text1.setToolTip("")

        # botón Cerrar
        self.btnCerrar = QToolButton(self.w1)
        self.btnCerrar.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Fixed)
        self.btnCerrar.setText("Cerrar")
        self.btnCerrar.move(350, 670)
        self.btnCerrar.resize(90, 22)
        self.btnCerrar.setCursor(Qt.ArrowCursor)
        self.btnCerrar.setToolTip("Cierra la aplicación.")
        self.btnCerrar.clicked.connect(self.on_btnCerrar)

        # botón Imprimir
        self.btnImprimir = QToolButton(self.w1)
        self.btnImprimir.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Fixed)
        self.btnImprimir.setText("Imprimir")
        self.btnImprimir.move(350, 638)
        self.btnImprimir.resize(90, 22)
        self.btnImprimir.setCursor(Qt.ArrowCursor)
        self.btnImprimir.setToolTip("Imprime el poema.")
        self.btnImprimir.clicked.connect(self.on_btnImprimir)

        # botón Guardar
        self.btnGuardar = QToolButton(self.w1)
        self.btnGuardar.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Fixed)
        self.btnGuardar.setText("Guardar")
        self.btnGuardar.move(350, 606)
        self.btnGuardar.resize(90, 22)
        self.btnGuardar.setCursor(Qt.ArrowCursor)
        self.btnGuardar.setToolTip("Guarda poema en .txt")
        self.btnGuardar.clicked.connect(self.on_btnGuardar)

        # botón Leer
        self.btnLeer = QToolButton(self.w1)
        self.btnLeer.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Fixed)
        self.btnLeer.setText("Leer")
        self.btnLeer.move(350, 574)
        self.btnLeer.resize(90, 22)
        self.btnLeer.setCursor(Qt.ArrowCursor)
        self.btnLeer.setToolTip("Leer poema.")
        self.btnLeer.clicked.connect(self.on_btnLeer)

        # botón Nuevo
        self.btnNuevo = QToolButton(self.w1)
        self.btnNuevo.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Fixed)
        self.btnNuevo.setText("Nuevo")
        self.btnNuevo.move(350, 542)
        self.btnNuevo.resize(90, 22)
        self.btnNuevo.setCursor(Qt.ArrowCursor)
        self.btnNuevo.setToolTip("Nuevo poema.")
        self.btnNuevo.clicked.connect(self.on_btnNuevo)

        self.label1 = QLabel(self.w1)
        self.label1.setText("* Lector de poemas *")
        self.label1.move(20, 10)
        self.label1.resize(170, 22)
        self.label1.setFont(QFont("Times New Roman", 12))
        self.label1.setCursor(Qt.ArrowCursor)
        self.label1.setToolTip("Simple lector de poemas de textos.")

        return self.w1

    def on_btnCerrar(self):
        self.close()
        print('Cierra aplicación.', flush=True)

    # efectúa una simple impresión de texto en el dispositivo seleccionado por el usuario.
    # los dispositivos pueden ser físicos o virtuales (PDF).
    def on_btnImprimir(self):
        print("Imprime poema...", flush=True)
        self.impresora = QPrintDialog()
        if self.impresora.exec() == QPrintDialog.Accepted:
            self.text1.print_(self.impresora.printer())
            print("Se efectuó la impresión del poema.", flush=True)
        else:
            print("Impresión cancelada.", flush=True)

    def on_btnGuardar(self):
        fnombre = "poema0" + str(self.nro) + ".poe"
        ftexto = open(fnombre, "w", encoding="utf-8")
        ftexto.write(self.text1.toPlainText())
        ftexto.close()
        print("El poema ha sido guardado en el directorio vigente: ", fnombre)
        self.nro = self.nro + 1

    def on_btnLeer(self):
        print("Lee poema.", flush=True)
        nombreFichero = QFileDialog.getOpenFileName(self, "Abrir fichero", "poema.poe", "Ficheros de poemas (*.poe)")

        if nombreFichero[0]:
            idFichero = open(nombreFichero[0], "r", encoding="utf-8")
            with idFichero:
                datos = idFichero.read()
                self.text1.setText(datos)
                idFichero.close()
        else:
            print("Fichero .poe no seleccionado.")

    def on_btnNuevo(self):
        self.text1.clear()
        print('Nuevo poema.')

    """
    Pone la ventana en el centro de la pantalla.
    """
    def centrar(self):
        posX = (self.screen().size().width() / 2) - (self.width() / 2)
        self.move(round(posX), 8)

def main():
    locale.setlocale(locale.LC_ALL, 'spanish_argentina')
    miAplicacion = QApplication(sys.argv)
    miAplicacion.setApplicationDisplayName("Lector de poemas")
    miAplicacion.setApplicationVersion("1.0")

    miPoema = Poema()
    ##miPoema.setFixedSize(340, 700)
    miPoema.setWindowOpacity(0.85)
    miPoema.centrar()
    miPoema.show()

    sys.exit(miAplicacion.exec())

if __name__ == '__main__':
    main()
