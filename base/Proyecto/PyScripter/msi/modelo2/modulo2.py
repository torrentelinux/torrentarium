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
import ntplib
import time as tiempo

from PyQt6.QtWidgets import (QApplication)
# from PyQt5.QtWidgets import (QApplication)

# Importa todo lo que tiene el programa AplicacionPrincipal.py
import AplicacionPrincipal as ap

def tiempoLocal()->str:
    return tiempo.ctime()

# Servidores de tiempo disponibles en Internet:
# 'time.windows.com'
# 'ar.pool.ntp.org'
# 'ntp0.fau.de'
def tiempoRed()->str:
    try:
        servidor_ntp = 'ar.pool.ntp.org'
        c = ntplib.NTPClient()
        respuesta = c.request(servidor_ntp)

        fecha_actual = tiempo.ctime(respuesta.tx_time)
        return fecha_actual
    except:
        print(f'Error de conexión a {servidor_ntp}')
        return "0"

# Visualiza una ventana simple con info. sobre la biblioteca PyQt
def qtVer(qa: QApplication):
    qa.instance().aboutQt()

def inicio():
    aplicacion = QApplication([])
    print(ap.sistema_autor, ap.sistema_fecha)
    print("Licencia " + ap.sistema_licencia)
    qtVer(aplicacion)
