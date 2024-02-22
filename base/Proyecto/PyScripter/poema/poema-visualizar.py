#-------------------------------------------------------------------------------
# Nombre:      poema-visualizar.py
# Propósito:   Visualizar un poema en una ventana gráfica.
#              Las opciones disponibles son nuevo, leer, guardar e imprimir.
#              El fichero "poema" es un fichero de textos con extensión .poe
#              y codificación utf-8.
#              Funciona con las bibliotecas PySide6, y PyQt6.
# Autor:       (c) Octulio Biletán 2023.
# Creado:      22/10/2023
# Origen:      Aplicación hecha en Tucumán, Argentina.
# Licencia:    Software Libre.
#-------------------------------------------------------------------------------
# -*- coding: utf-8 -*-
from __future__ import unicode_literals

import locale, sys

# Modificar para PySide6/PyQt6
from PyQt6 import QtCore, QtGui, QtWidgets, QtPrintSupport

# definición de la clase 'Poema' como la ventana principal de la aplicación
class Poema(QtWidgets.QMainWindow):
    def __init__(self):
        super(Poema, self).__init__()

        # contador de poemas guardados
        self.nro = 1

        # controla el cierre de la ventana
        self.cierraVentana = False

        self.form()

    def form(self)->QtWidgets.QMainWindow:
        self.w1 = self
        self.w1.setAutoFillBackground(True)
        self.w1.setWindowTitle("Gestión de poemas")
        self.w1.resize(450, 700)
        self.w1.setToolTip("")

        # caja de textos 'text1'
        self.text1 = QtWidgets.QTextEdit(self.w1)
        self.text1.setText("	A mis amigos\n\nA mis amigos les adeudo la ternura\ny las palabras de aliento y el abrazo;\nel compartir con todos ellos la factura\nque nos presenta la vida, paso a paso.\n\nA mis amigos les adeudo la paciencia\nde tolerarme las espinas más agudas;\nlos arrebatos de humor, la negligencia,\nlas vanidades, los temores y las dudas.\n\nUn barco frágil de papel,\nparece a veces la amistad\npero jamás puede con él\nla más violenta tempestad\nporque ese barco de papel,\ntiene aferrado a su timón\npor capitán y timonel:\nun corazón\n\nA mis amigos les adeudo algún enfado\nque perturbara sin querer nuestra armonía\nsabemos todos que no puede ser pecado\nel discutir, alguna vez, por tonterías.\n\nA mis amigos legaré cuando me muera\nmi devoción un acorde de guitarra\ny entre los versos olvidados de un poema,\nmi pobre alma incorregible de cigarra.\n\nUn barco frágil de papel,\nparece a veces la amistad\npero jamás puede con él\nla más violenta tempestad\nporque ese barco de papel,\ntiene aferrado a su timón\npor capitán y timonel:\nun corazón\n\nAmigo mío si esta copla como el viento,\nadonde quieras escucharla te reclama,\nserás plural, porque lo exige el sentimiento\ncuando se lleva a los amigos en el alma.\n\n	Autor del poema: Alberto Cortéz")
        self.text1.move(20, 40)
        self.text1.resize(310, 650)
        self.text1.setFont(QtGui.QFont("MS Shell Dlg 2", 10))
        self.text1.setToolTip("")

        # añadir botón Ajustes: en desarrollo...
        # --------------------------------------

        # botón Cerrar
        self.btnCerrar = QtWidgets.QToolButton(self.w1)

        # self.btnCerrar.setSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Fixed)
        self.btnCerrar.setSizePolicy(QtWidgets.QSizePolicy.Policy.Expanding, QtWidgets.QSizePolicy.Policy.Fixed)

        self.btnCerrar.setText("Cerrar")
        self.btnCerrar.move(350, 670)
        self.btnCerrar.resize(90, 22)

        # self.btnCerrar.setCursor(QtCore.Qt.PointingHandCursor)
        self.btnCerrar.setCursor(QtCore.Qt.CursorShape.PointingHandCursor)

        self.btnCerrar.setToolTip("Cierra la aplicación.")
        self.btnCerrar.clicked.connect(self.on_btnCerrar)

        # botón Imprimir
        self.btnImprimir = QtWidgets.QToolButton(self.w1)

        # self.btnImprimir.setSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Fixed)
        self.btnImprimir.setSizePolicy(QtWidgets.QSizePolicy.Policy.Expanding, QtWidgets.QSizePolicy.Policy.Fixed)

        self.btnImprimir.setText("Imprimir")
        self.btnImprimir.move(350, 638)
        self.btnImprimir.resize(90, 22)

        # self.btnImprimir.setCursor(QtCore.Qt.PointingHandCursor)
        self.btnImprimir.setCursor(QtCore.Qt.CursorShape.PointingHandCursor)

        self.btnImprimir.setToolTip("Imprime el poema.")
        self.btnImprimir.clicked.connect(self.on_btnImprimir)

        # botón Guardar
        self.btnGuardar = QtWidgets.QToolButton(self.w1)

        #self.btnGuardar.setSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Fixed)
        self.btnGuardar.setSizePolicy(QtWidgets.QSizePolicy.Policy.Expanding, QtWidgets.QSizePolicy.Policy.Fixed)

        self.btnGuardar.setText("Guardar")
        self.btnGuardar.move(350, 606)
        self.btnGuardar.resize(90, 22)

        #self.btnGuardar.setCursor(QtCore.Qt.PointingHandCursor)
        self.btnGuardar.setCursor(QtCore.Qt.CursorShape.PointingHandCursor)

        self.btnGuardar.setToolTip("Guarda poema en .txt")
        self.btnGuardar.clicked.connect(self.on_btnGuardar)

        # botón Leer
        self.btnLeer = QtWidgets.QToolButton(self.w1)

        #self.btnLeer.setSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Fixed)
        self.btnLeer.setSizePolicy(QtWidgets.QSizePolicy.Policy.Expanding, QtWidgets.QSizePolicy.Policy.Fixed)

        self.btnLeer.setText("Leer")
        self.btnLeer.move(350, 574)
        self.btnLeer.resize(90, 22)

        #self.btnLeer.setCursor(QtCore.Qt.PointingHandCursor)
        self.btnLeer.setCursor(QtCore.Qt.CursorShape.PointingHandCursor)

        self.btnLeer.setToolTip("Leer poema.")
        self.btnLeer.clicked.connect(self.on_btnLeer)

        # botón Nuevo
        self.btnNuevo = QtWidgets.QToolButton(self.w1)

        #self.btnNuevo.setSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Fixed)
        self.btnNuevo.setSizePolicy(QtWidgets.QSizePolicy.Policy.Expanding, QtWidgets.QSizePolicy.Policy.Fixed)

        self.btnNuevo.setText("Nuevo")
        self.btnNuevo.move(350, 542)
        self.btnNuevo.resize(90, 22)

        #self.btnNuevo.setCursor(QtCore.Qt.PointingHandCursor)
        self.btnNuevo.setCursor(QtCore.Qt.CursorShape.PointingHandCursor)

        self.btnNuevo.setToolTip("Nuevo poema.")
        self.btnNuevo.clicked.connect(self.on_btnNuevo)

        # botón etiqueta 'label1ToolButton'
        self.label1ToolButton = QtWidgets.QToolButton(self.w1)
        self.label1ToolButton.setSizePolicy(QtWidgets.QSizePolicy.Policy.Ignored, QtWidgets.QSizePolicy.Policy.Ignored)

        self.label1ToolButton.setText("* Lector de poemas *")
        self.label1ToolButton.move(20, 10)
        self.label1ToolButton.resize(170, 22)
        self.label1ToolButton.setFont(QtGui.QFont("Times New Roman", 12))

        #self.label1.setCursor(QtCore.Qt.WhatsThisCursor)
        self.label1ToolButton.setCursor(QtCore.Qt.CursorShape.WhatsThisCursor)

        self.label1ToolButton.setToolTip("Simple lector de poemas de textos.")
        self.label1ToolButton.setAutoRaise(True)
        self.label1ToolButton.clicked.connect(self.on_lblDescripcion)

        return self.w1

    def on_lblDescripcion(self):
        self.mensajeTexto = "Simple lector de poemas .poe\n" \
                            "Desarrollado para PySide6 y para PyQt6.\n" \
                            "Versión 1.2.2024\n(c)Octulio Biletán 2024."
        QtWidgets.QMessageBox.about(self, "Poema", self.mensajeTexto)

    def on_btnCerrar(self):
        print('Cierra aplicación...', flush=True)
        QtWidgets.QApplication.beep()

        # autoriza el cierre de la ventana
        self.cierraVentana = True

        self.close()

    def closeEvent(self, event):
        if self.cierraVentana == True:
            print("Finaliza aplicación.")
            event.accept()
        else:
            print("Finalización cancelada.")
            event.ignore()

    # efectúa una simple impresión de texto en el dispositivo seleccionado por el usuario.
    # los dispositivos pueden ser físicos o virtuales (PDF).
    def on_btnImprimir(self):
        print("Imprime poema...", flush=True)

        self.impresora = QtPrintSupport.QPrintDialog()
        self.impresora.setWindowTitle("Imprimir Poema")
        #if self.impresora.exec() == QtPrintSupport.QPrintDialog.Accepted:

        if self.impresora.exec() == QtPrintSupport.QPrintDialog.DialogCode.Accepted:
            self.text1.print(self.impresora.printer())
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
        nombreFichero = QtWidgets.QFileDialog.getOpenFileName(self, "Abrir fichero", "poema.poe", "Ficheros de poemas (*.poe)")

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
    # para Linux: "es_AR.UTF-8"
    locale.setlocale(locale.LC_ALL, 'spanish_argentina')

    # 'miAplicacion' es una nueva instancia de QtWidgets.QApplication()
    miAplicacion = QtWidgets.QApplication([])

    miAplicacion.setApplicationDisplayName("Lector de poemas")
    miAplicacion.setApplicationVersion("1.2")

    # 'miPoema' es una nueva instancia de Poema()
    miPoema = Poema()

    # la ventana tiene unas dimensiones fijas no ajustables
    miPoema.setFixedSize(450, 700)

    # hace que la ventana sea translúcida
    miPoema.setWindowOpacity(0.85)

    # pone la ventana en el centro de la pantalla
    miPoema.centrar()

    # muestra en pantalla la ventana principal
    miPoema.show()

    sys.exit(miAplicacion.exec())

if __name__ == '__main__':
    main()
